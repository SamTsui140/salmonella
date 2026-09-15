// #include <cstring>
// #include <cassert>
// #include <iostream>
// #include <string>
// #include <vector>

// #include "../common/constants.h"
// #include "../common/contextmanager.h"
// #include "../common/err.h"
// #include "../common/net.h"

// #include "parsing.h"
// #include "responses.h"

// using namespace std;

// /// Extract a string from a vector
// ///
// /// @param it     An iterator to the extraction point
// /// @param count  The number of characters to extract
// /// @return The string
// string extract_string(vector<uint8_t>::iterator &it, size_t count) {
//   cout << "parsing.cc::extract_string() is not implemented\n";
//   // NB: These assertions are only here to prevent compiler warnings
//   assert(count != 0);
//   return "";
// }


// /// Extract a size (uint32_t) from a vector
// /// @param it An iterator to the extraction point
// /// @return The uint32_t extracted
// uint32_t extract_size(vector<uint8_t>::iterator &it) {
//   cout << "parsing.cc::extract_size() is not implemented\n";
//   return 0;
// }

// /// When a new client connection is accepted, this code will run to figure out
// /// what the client is requesting, and to dispatch to the right function for
// /// satisfying the request.
// ///
// /// @param sd      The socket on which communication with the client takes place
// /// @param storage The Storage object with which clients interact
// ///
// /// @return true if the server should halt immediately, false otherwise
// bool parse_request(int sd, Storage *storage) {
//   cout << "parsing.cc::parse_request() is not implemented\n";
//   // NB: These assertions are only here to prevent compiler warnings
//   assert(sd);
//   assert(storage);
//   return false;
// }

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "../common/constants.h"
#include "../common/contextmanager.h"
#include "../common/err.h"
#include "../common/net.h"

#include "parsing.h"
#include "responses.h"

using namespace std;

/// Helper to send format error response
static bool send_format_error(int sd) {
  send_reliably(sd, RES_ERR_REQ_FMT);
  return false;
}

/// Extract a string from a vector
string extract_string(vector<uint8_t>::iterator &it, size_t count) {
  string s(it, it + count);
  it += count;
  return s;
}

/// Extract a size (uint32_t) from a vector
uint32_t extract_size(vector<uint8_t>::iterator &it) {
  uint32_t val = 0;
  memcpy(&val, &(*it), sizeof(uint32_t));
  it += sizeof(uint32_t);
  return val;
}

/// When a new client connection is accepted, this code runs to parse the request
/// and dispatch to the correct handler.
bool parse_request(int sd, Storage *storage) {
  // Read the full request from the socket
  vector<uint8_t> req = reliable_get_to_eof(sd);

  // A valid request header must at least contain:
  // 4 bytes (cmd) + 4 bytes (u_len) + 4 bytes (p_len) + 4 bytes (b_len) = 16 bytes
  if (req.size() < 16) {
    return send_format_error(sd);
  }

  auto it = req.begin();
  string cmd = extract_string(it, 4);
  uint32_t u_len = extract_size(it);
  uint32_t p_len = extract_size(it);
  uint32_t b_len = extract_size(it);

  // Validate lengths against protocol limits
  if (u_len > (uint32_t)LEN_UNAME || p_len > (uint32_t)LEN_PASSWORD) {
    return send_format_error(sd);
  }

  // Ensure buffer matches the expected message length
  if (req.size() != 16 + u_len + p_len + b_len) {
    return send_format_error(sd);
  }

  string u = extract_string(it, u_len);
  string p = extract_string(it, p_len);
  vector<uint8_t> rem(it, req.end());

  // Command routing table
  vector<string> cmds = {REQ_REG, REQ_BYE, REQ_SAV, REQ_SET, REQ_GET, REQ_ALL};
  decltype(handle_reg) *handlers[] = {handle_reg, handle_bye, handle_sav,
                                      handle_set, handle_get, handle_all};

  for (size_t i = 0; i < cmds.size(); ++i) {
    if (cmd == cmds[i]) {
      return handlers[i](sd, storage, u, p, rem);
    }
  }

  // Invalid command code
  return send_format_error(sd);
}