// #include <string>
// #include <iostream>
// #include <cassert>
// #include "../common/constants.h"
// #include "../common/net.h"
// #include "responses.h"

// using namespace std;
// /// Add the size of a value to a vector as a 4-byte value
// ///
// /// @param res  The vector to add to
// /// @param t    The thing whose size should be added
// ///
// /// @tparam T   The type of t
// template <class T> void add_size(vector<uint8_t> &res, T t) {
//   cout << "responses.cc::add_size() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(res.size() > 0);
//   assert(t.size() > 0);
// }

// /// Add the contents of an iterable to a vector
// ///
// /// @param res  The vector to add to
// /// @param t    The thing to add
// ///
// /// @tparam T   The type of t
// template <class T> void add_it(vector<uint8_t> &res, T t) {
//   cout << "responses.cc::add_it() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(res.size() > 0);
//   assert(t.size() > 0);
// }

// /// Concatenate a string and a vector of content, in a format that can be sent
// /// to the client as a single message.  Most often, this involves a message of
// /// RES_OK and content that was returned from a hash table.
// ///
// /// @param msg     A string message to send to the client
// /// @param content A vector of content to send to the client
// ///
// /// @return a vector with the correct concatenation of msg and content
// vector<uint8_t> build_res(const string &msg, const vector<uint8_t> &content) {
//   cout << "responses.cc::build_res() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(msg.length() > 0);
//   assert(content.size() > 0);
//   return {};
// }

// /// Send a message format error
// ///
// /// @param sd  The socket onto which the result should be written
// ///
// /// @return false, to indicate that the server shouldn't stop
// bool send_err_msg_format(int sd) {
//   send_reliably(sd, RES_ERR_REQ_FMT);
//   return false;
// }

// /// Extract a string from a vector
// ///
// /// @param it     An iterator to the extraction point
// /// @param count  The number of characters to extract
// /// @return The extracted string
// string extract_string(vector<uint8_t>::const_iterator &it,
//                              size_t count) {
//   cout << "responses.cc::extract_string() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(count != 0);
//   return "";
// }

// /// Extract a size (uint32_t) from a vector
// /// @param it An iterator to the extraction point
// /// @return The extracted uint32_t
// uint32_t extract_size(vector<uint8_t>::const_iterator &it) {
//   cout << "responses.cc::extract_size() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   return 0;
// }

// /// Extract a vector from a vector
// /// @param it     An iterator to the extraction point
// /// @param count  The number of bytes to extract
// /// @return The extracted vector
// vector<uint8_t> extract_vec(vector<uint8_t>::const_iterator &it,
//                                    size_t count) {
//   cout << "responses.cc::extract_vector() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(count != 0);
//   return {};
// }

// /// Respond to an ALL command by generating a list of all the usernames in the
// /// Auth table and returning them, one per line.
// ///
// /// @param sd      The socket onto which the result should be written
// /// @param storage The Storage object, which contains the auth table
// /// @param u       The user name associated with the request
// /// @param p       The password associated with the request
// /// @param req     The contents of the request
// ///
// /// @return false, to indicate that the server shouldn't stop
// bool handle_all(int sd, Storage *storage,
//                 const std::string &u, const std::string &p,
//                 const vector<uint8_t> &req) {
//   cout << "responses.cc::handle_all() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(storage);
//   assert(u.length() > 0);
//   assert(p.length() > 0);
//   assert(req.size() > 0);
//   return false;
// }

// /// Respond to a SET command by putting the provided data into the Auth table
// ///
// /// @param sd      The socket onto which the result should be written
// /// @param storage The Storage object, which contains the auth table
// /// @param u       The user name associated with the request
// /// @param p       The password associated with the request
// /// @param req     The contents of the request
// ///
// /// @return false, to indicate that the server shouldn't stop
// bool handle_set(int sd, Storage *storage,
//                 const std::string &u, const std::string &p,
//                 const vector<uint8_t> &req) {
//   cout << "responses.cc::handle_set() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(storage);
//   assert(u.length() > 0);
//   assert(p.length() > 0);
//   assert(req.size() > 0);
//   return false;
// }

// /// Respond to a GET command by getting the data for a user
// ///
// /// @param sd      The socket onto which the result should be written
// /// @param storage The Storage object, which contains the auth table
// /// @param u       The user name associated with the request
// /// @param p       The password associated with the request
// /// @param req     The contents of the request
// ///
// /// @return false, to indicate that the server shouldn't stop
// bool handle_get(int sd, Storage *storage,
//                 const std::string &u, const std::string &p,
//                 const vector<uint8_t> &req) {
//   cout << "responses.cc::handle_get() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(storage);
//   assert(u.length() > 0);
//   assert(p.length() > 0);
//   assert(req.size() > 0);
//   return false;
// }

// /// Respond to a REG command by trying to add a new user
// ///
// /// @param sd      The socket onto which the result should be written
// /// @param storage The Storage object, which contains the auth table
// /// @param u       The user name associated with the request
// /// @param p       The password associated with the request
// /// @param req     The contents of the request
// ///
// /// @return false, to indicate that the server shouldn't stop
// bool handle_reg(int sd, Storage *storage,
//                 const std::string &u, const std::string &p,
//                 const vector<uint8_t> &req) {
//   cout << "responses.cc::handle_reg() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(storage);
//   assert(u.length() > 0);
//   assert(p.length() > 0);
//   assert(req.size() > 0);
//   return false;
// }

// /// Respond to a BYE command by returning false, but only if the user
// /// authenticates
// ///
// /// @param sd      The socket onto which the result should be written
// /// @param storage The Storage object, which contains the auth table
// /// @param u       The user name associated with the request
// /// @param p       The password associated with the request
// /// @param req     The contents of the request
// ///
// /// @return true, to indicate that the server should stop, or false on an error
// bool handle_bye(int sd, Storage *storage,
//                 const std::string &u, const std::string &p,
//                 const vector<uint8_t> &req) {
//   cout << "responses.cc::handle_bye() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(storage);
//   assert(u.length() > 0);
//   assert(p.length() > 0);
//   assert(req.size() > 0);
//   return false;
// }

// /// Respond to a SAV command by persisting the file, but only if the user
// /// authenticates
// ///
// /// @param sd      The socket onto which the result should be written
// /// @param storage The Storage object, which contains the auth table
// /// @param u       The user name associated with the request
// /// @param p       The password associated with the request
// /// @param req     The contents of the request
// ///
// /// @return false, to indicate that the server shouldn't stop
// bool handle_sav(int sd, Storage *storage,
//                 const std::string &u, const std::string &p,
//                 const vector<uint8_t> &req) {
//   cout << "responses.cc::handle_sav() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(storage);
//   assert(u.length() > 0);
//   assert(p.length() > 0);
//   assert(req.size() > 0);
//   return false;
// }



#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "../common/constants.h"
#include "../common/net.h"
#include "responses.h"

using namespace std;

/// Add the size of a value to a vector as a 4-byte value
template <class T> void add_size(vector<uint8_t> &res, T t) {
  uint32_t sz = static_cast<uint32_t>(t.size());
  const uint8_t *ptr = reinterpret_cast<const uint8_t *>(&sz);
  res.insert(res.end(), ptr, ptr + sizeof(uint32_t));
}

/// Add the contents of an iterable to a vector
template <class T> void add_it(vector<uint8_t> &res, T t) {
  res.insert(res.end(), t.begin(), t.end());
}

/// Concatenate a string and a vector of content
vector<uint8_t> build_res(const string &msg, const vector<uint8_t> &content) {
  vector<uint8_t> res;
  add_it(res, msg);
  add_size(res, content);
  add_it(res, content);
  return res;
}

/// Send a message format error
bool send_err_msg_format(int sd) {
  send_reliably(sd, RES_ERR_REQ_FMT);
  return false;
}

/// Extract a string from a vector
string extract_string(vector<uint8_t>::const_iterator &it, size_t count) {
  string s(it, it + count);
  it += count;
  return s;
}

/// Extract a size (uint32_t) from a vector
uint32_t extract_size(vector<uint8_t>::const_iterator &it) {
  uint32_t val = 0;
  memcpy(&val, &(*it), sizeof(uint32_t));
  it += sizeof(uint32_t);
  return val;
}

/// Extract a vector from a vector
vector<uint8_t> extract_vec(vector<uint8_t>::const_iterator &it, size_t count) {
  vector<uint8_t> v(it, it + count);
  it += count;
  return v;
}

/// Respond to an ALL command
bool handle_all(int sd, Storage *storage, const std::string &u,
                const std::string &p, const vector<uint8_t> &req) {
  if (req.size() != 0) {
    return send_err_msg_format(sd);
  }
  auto res = storage->get_all_users(u, p);
  if (!res.succeeded) {
    send_reliably(sd, res.msg);
    return false;
  }
  auto resp = build_res(res.msg, res.data);
  send_reliably(sd, resp);
  return false;
}

/// Respond to a SET command
bool handle_set(int sd, Storage *storage, const std::string &u,
                const std::string &p, const vector<uint8_t> &req) {
  // SET expects @b: len(@f).@f
  if (req.size() < 4) {
    return send_err_msg_format(sd);
  }
  auto it = req.cbegin();
  uint32_t f_len = extract_size(it);
  if (f_len > (uint32_t)LEN_PROFILE_FILE || req.size() != 4 + f_len) {
    return send_err_msg_format(sd);
  }
  vector<uint8_t> content = extract_vec(it, f_len);

  auto res = storage->set_user_data(u, p, content);
  send_reliably(sd, res.msg);
  return false;
}

/// Respond to a GET command
bool handle_get(int sd, Storage *storage, const std::string &u,
                const std::string &p, const vector<uint8_t> &req) {
  // GET expects @b: len(@w).@w
  if (req.size() < 4) {
    return send_err_msg_format(sd);
  }
  auto it = req.cbegin();
  uint32_t w_len = extract_size(it);
  if (w_len > (uint32_t)LEN_UNAME || req.size() != 4 + w_len) {
    return send_err_msg_format(sd);
  }
  string who = extract_string(it, w_len);

  auto res = storage->get_user_data(u, p, who);
  if (!res.succeeded) {
    send_reliably(sd, res.msg);
    return false;
  }
  auto resp = build_res(res.msg, res.data);
  send_reliably(sd, resp);
  return false;
}

/// Respond to a REG command
bool handle_reg(int sd, Storage *storage, const std::string &u,
                const std::string &p, const vector<uint8_t> &req) {
  if (req.size() != 0) {
    return send_err_msg_format(sd);
  }
  auto res = storage->add_user(u, p);
  send_reliably(sd, res.msg);
  return false;
}

/// Respond to a BYE (EXIT) command
bool handle_bye(int sd, Storage *storage, const std::string &u,
                const std::string &p, const vector<uint8_t> &req) {
  if (req.size() != 0) {
    return send_err_msg_format(sd);
  }
  auto res = storage->auth(u, p);
  send_reliably(sd, res.msg);
  return res.succeeded; // If auth succeeded, true terminates the server
}

/// Respond to a SAV command
bool handle_sav(int sd, Storage *storage, const std::string &u,
                const std::string &p, const vector<uint8_t> &req) {
  if (req.size() != 0) {
    return send_err_msg_format(sd);
  }
  auto auth_res = storage->auth(u, p);
  if (!auth_res.succeeded) {
    send_reliably(sd, auth_res.msg);
    return false;
  }
  auto res = storage->save_file();
  send_reliably(sd, res.msg);
  return false;
}