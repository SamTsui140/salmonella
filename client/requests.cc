// #include <cassert>
// #include <cstring>
// #include <iostream>
// #include <openssl/rand.h>
// #include <vector>

// #include "../common/constants.h"
// #include "../common/contextmanager.h"
// #include "../common/file.h"
// #include "../common/net.h"

// #include "requests.h"

// using namespace std;

// /// Use this instead of constructing empty vector args to send_cmd
// vector<uint8_t> empty_vec;

// /// Add the size of a value to a vector as a little-endian 4-byte value 
// ///
// /// @param res  The vector to add to
// /// @param t    The thing whose size should be added
// ///
// /// @tparam T   The type of t
// template <class T> void add_size(vector<uint8_t> &res, T t) {
  
// }

// /// Add the contents of an iterable to a vector
// ///
// /// @param res  The vector to add to
// /// @param t    The thing to add
// ///
// /// @tparam T   The type of t
// template <class T> void add_it(vector<uint8_t> &res, T t) {

// }

// /// If a buffer consists of RES_OK.bbbb.d+, where `.` means concatenation, bbbb
// /// is an 4-byte binary integer and d+ is a string of characters, write the
// /// bytes (d+) to a file
// ///
// /// @param buf      The buffer holding a response
// /// @param filename The name of the file to write
// void send_result_to_file(const vector<uint8_t> &buf, const string &filename) {
  
// }

// /// Send a message to the server, using the common format for messages,
// /// then take the response from the server and return it.
// ///
// /// @param sd       The open socket descriptor for communicating with the server
// /// @param cmd      The command that is being sent
// /// @param user     The username for the request
// /// @param password The password for the request
// /// @param msg      The contents
// ///
// /// @return a vector with the result, or an empty vector on error
// vector<uint8_t> send_cmd(int sd, const string &cmd,
//                          const string &user, const string &password,
//                          const vector<uint8_t> &msg) {
//   cout << "requests.cc::send_cmd() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(cmd.length() > 0);
//   assert(user.length() > 0);
//   assert(password.length() > 0);
//   assert(msg.size() > 0);
//   return {};
// }

// /// req_reg() sends the REG command to register a new user
// ///
// /// @param sd      The open socket descriptor for communicating with the server
// /// @param user    The name of the user doing the request
// /// @param pass    The password of the user doing the request
// void req_reg(int sd, const string &user, const string &pass,
//              const string &) {
//   cout << "requests.cc::req_reg() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(user.length() > 0);
//   assert(pass.length() > 0);
// }

// /// req_bye() writes a request for the server to exit.
// ///
// /// @param sd      The open socket descriptor for communicating with the server
// /// @param user    The name of the user doing the request
// /// @param pass    The password of the user doing the request
// void req_bye(int sd, const string &user, const string &pass,
//              const string &) {
//   cout << "requests.cc::req_bye() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(user.length() > 0);
//   assert(pass.length() > 0);
// }

// /// req_sav() writes a request for the server to save its contents
// ///
// /// @param sd      The open socket descriptor for communicating with the server
// /// @param user    The name of the user doing the request
// /// @param pass    The password of the user doing the request
// void req_sav(int sd, const string &user, const string &pass,
//              const string &) {
//   cout << "requests.cc::req_sav() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(user.length() > 0);
//   assert(pass.length() > 0);
// }

// /// req_set() sends the SET command to set the content for a user
// ///
// /// @param sd      The open socket descriptor for communicating with the server
// /// @param user    The name of the user doing the request
// /// @param pass    The password of the user doing the request
// /// @param setfile The file whose contents should be sent
// void req_set(int sd, const string &user, const string &pass, const string &setfile) {
//   cout << "requests.cc::req_set() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(user.length() > 0);
//   assert(pass.length() > 0);
//   assert(setfile.length() > 0);
// }

// /// req_get() requests the content associated with a user, and saves it to a
// /// file called <user>.file.dat.
// ///
// /// @param sd      The open socket descriptor for communicating with the server
// /// @param user    The name of the user doing the request
// /// @param pass    The password of the user doing the request
// /// @param getname The name of the user whose content should be fetched
// void req_get(int sd, const string &user, const string &pass,
//              const string &getname) {
//   cout << "requests.cc::req_get() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(user.length() > 0);
//   assert(pass.length() > 0);
//   assert(getname.length() > 0);
// }

// /// req_all() sends the ALL command to get a listing of all users, formatted
// /// as text with one entry per line.
// ///
// /// @param sd      The open socket descriptor for communicating with the server
// /// @param user    The name of the user doing the request
// /// @param pass    The password of the user doing the request
// /// @param allfile The file where the result should go
// void req_all(int sd, const string &user, const string &pass,
//              const string &allfile) {
//   cout << "requests.cc::req_all() is not implemented\n";
//   // NB: These asserts are to prevent compiler warnings
//   assert(sd);
//   assert(user.length() > 0);
//   assert(pass.length() > 0);
//   assert(allfile.length() > 0);
// }



#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <openssl/rand.h>
#include <vector>

#include "../common/constants.h"
#include "../common/contextmanager.h"
#include "../common/file.h"
#include "../common/net.h"

#include "requests.h"

using namespace std;

/// Use this instead of constructing empty vector args to send_cmd
vector<uint8_t> empty_vec;

/// Add the size of a value to a vector as a little-endian 4-byte value 
template <class T> void add_size(vector<uint8_t> &res, T t) {
  uint32_t sz = static_cast<uint32_t>(t.size());
  const uint8_t *ptr = reinterpret_cast<const uint8_t *>(&sz);
  res.insert(res.end(), ptr, ptr + sizeof(uint32_t));
}

/// Add the contents of an iterable to a vector
template <class T> void add_it(vector<uint8_t> &res, T t) {
  res.insert(res.end(), t.begin(), t.end());
}

/// If a buffer consists of RES_OK.bbbb.d+, where `.` means concatenation, bbbb
/// is a 4-byte binary integer and d+ is a string of characters, write the
/// bytes (d+) to a file
void send_result_to_file(const vector<uint8_t> &buf, const string &filename) {
  if (buf.size() < 8) {
    return;
  }

  string msg(buf.begin(), buf.begin() + 4);
  if (msg != RES_OK) {
    return;
  }

  uint32_t len = 0;
  memcpy(&len, &buf[4], sizeof(uint32_t));

  FILE *fp = fopen(filename.c_str(), "wb");
  if (fp == nullptr) {
    return;
  }

  if (len > 0 && buf.size() >= 8 + len) {
    fwrite(&buf[8], 1, len, fp);
  }
  fclose(fp);
}

/// Send a message to the server, using the common format for messages,
/// then take the response from the server and return it.
vector<uint8_t> send_cmd(int sd, const string &cmd,
                         const string &user, const string &password,
                         const vector<uint8_t> &msg) {
  vector<uint8_t> req;
  add_it(req, cmd);
  add_size(req, user);
  add_size(req, password);
  add_size(req, msg);
  add_it(req, user);
  add_it(req, password);
  add_it(req, msg);

  if (!send_reliably(sd, req)) {
    return {};
  }

  vector<uint8_t> res = reliable_get_to_eof(sd);
  if (res.empty()) {
    return {};
  }

  if (res.size() >= 4 && string(res.begin(), res.begin() + 4) == RES_OK) {
    cout << RES_OK << endl;
  } else {
    cout << string(res.begin(), res.end()) << endl;
  }

  return res;
}

/// req_reg() sends the REG command to register a new user
void req_reg(int sd, const string &user, const string &pass,
             const string &) {
  send_cmd(sd, REQ_REG, user, pass, empty_vec);
}

/// req_bye() writes a request for the server to exit.
void req_bye(int sd, const string &user, const string &pass,
             const string &) {
  send_cmd(sd, REQ_BYE, user, pass, empty_vec);
}

/// req_sav() writes a request for the server to save its contents
void req_sav(int sd, const string &user, const string &pass,
             const string &) {
  send_cmd(sd, REQ_SAV, user, pass, empty_vec);
}

/// req_set() sends the SET command to set the content for a user
void req_set(int sd, const string &user, const string &pass, const string &setfile) {
  vector<uint8_t> file_data = load_entire_file(setfile);
  vector<uint8_t> block;
  add_size(block, file_data);
  add_it(block, file_data);
  send_cmd(sd, REQ_SET, user, pass, block);
}

/// req_get() requests the content associated with a user, and saves it to a
/// file called <user>.file.dat.
void req_get(int sd, const string &user, const string &pass,
             const string &getname) {
  vector<uint8_t> block;
  add_size(block, getname);
  add_it(block, getname);
  auto res = send_cmd(sd, REQ_GET, user, pass, block);
  send_result_to_file(res, getname + ".file.dat");
}

/// req_all() sends the ALL command to get a listing of all users, formatted
/// as text with one entry per line.
void req_all(int sd, const string &user, const string &pass,
             const string &allfile) {
  auto res = send_cmd(sd, REQ_ALL, user, pass, empty_vec);
  send_result_to_file(res, allfile);
}