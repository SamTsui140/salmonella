// #include <cassert>
// #include <cstdio>
// #include <cstring>
// #include <functional>
// #include <iostream>
// #include <memory>
// #include <string>
// #include <unistd.h>
// #include <utility>
// #include <vector>

// #include "../common/constants.h"
// #include "../common/contextmanager.h"
// #include "../common/err.h"

// #include "authtableentry.h"
// #include "map.h"
// #include "map_factories.h"
// #include "storage.h"

// using namespace std;

// /// MyStorage is the student implementation of the Storage class
// class MyStorage : public Storage {
//   /// The map of authentication information, indexed by username
//   Map<string, AuthTableEntry> *auth_table;

//   /// The name of the file from which the Storage object was loaded, and to
//   /// which we persist the Storage object when save() is invoked
//   const string filename;

// public:
//   /// Construct an empty object and specify the file from which it should be
//   /// loaded.  To avoid exceptions and errors in the constructor, the act of
//   /// loading data is separate from construction.
//   ///
//   /// @param fname   The name of the file to use for persistence
//   /// @param buckets The number of buckets in the hash table
//   MyStorage(const std::string &fname, size_t buckets)
//       : auth_table(authtable_factory(buckets)), filename(fname) {}

//   /// Destructor for the storage object.
//   virtual ~MyStorage() { 
//     cout << "my_storage.cc::~MyStorage() is not implemented\n";
//   }

//   /// Authenticate a user
//   ///
//   /// @param user The name of the user who made the request
//   /// @param pass The password for the user, used to authenticate
//   ///
//   /// @return A result tuple, as described in storage.h
//   result_t auth(const string &user, const string &pass) {
//     cout << "my_storage.cc::auth() is not implemented\n";
//     // NB: These asserts are to prevent compiler warnings
//     assert(user.length() > 0);
//     assert(pass.length() > 0);
//     return {false, RES_ERR_UNIMPLEMENTED, {}};
//   }

//   /// Create a new entry in the Auth table.  If the user already exists, return
//   /// an error.  Otherwise, save an entry with the username, password, and a zero-byte content.
//   ///
//   /// @param user The user name to register
//   /// @param pass The password to associate with that user name
//   ///
//   /// @return A result tuple, as described in storage.h
//   virtual result_t add_user(const string &user, const string &pass) {
//     cout << "my_storage.cc::add_user() is not implemented\n";
//     // NB: These asserts are to prevent compiler warnings
//     assert(user.length() > 0);
//     assert(pass.length() > 0);
//     return {false, RES_ERR_UNIMPLEMENTED, {}};
//   }

//   /// Set the data bytes for a user, but do so if and only if the password
//   /// matches
//   ///
//   /// @param user    The name of the user whose content is being set
//   /// @param pass    The password for the user, used to authenticate
//   /// @param content The data to set for this user
//   ///
//   /// @return A result tuple, as described in storage.h
//   virtual result_t set_user_data(const string &user, const string &pass,
//                                  const vector<uint8_t> &content) {
//     cout << "my_storage.cc::set_user_data() is not implemented\n";
//     // NB: These asserts are to prevent compiler warnings
//     assert(user.length() > 0);
//     assert(pass.length() > 0);
//     assert(content.size() > 0);
//     return {false, RES_ERR_UNIMPLEMENTED, {}};
//   }

//   /// Return a copy of the user data for a user, but do so only if the password
//   /// matches
//   ///
//   /// @param user The name of the user who made the request
//   /// @param pass The password for the user, used to authenticate
//   /// @param who  The name of the user whose content is being fetched
//   ///
//   /// @return A result tuple, as described in storage.h.  Note that "no data" is
//   ///         an error
//   virtual result_t get_user_data(const string &user, const string &pass,
//                                  const string &who) {
//     cout << "my_storage.cc::get_user_data() is not implemented\n";
//     // NB: These asserts are to prevent compiler warnings
//     assert(user.length() > 0);
//     assert(pass.length() > 0);
//     assert(who.length() > 0);
//     return {false, RES_ERR_UNIMPLEMENTED, {}};
//   }

//   /// Return a newline-delimited string containing all of the usernames in the
//   /// auth table
//   ///
//   /// @param user The name of the user who made the request
//   /// @param pass The password for the user, used to authenticate
//   ///
//   /// @return A result tuple, as described in storage.h
//   virtual result_t get_all_users(const string &user, const string &pass) {
//     cout << "my_storage.cc::get_all_users() is not implemented\n";
//     // NB: These asserts are to prevent compiler warnings
//     assert(user.length() > 0);
//     assert(pass.length() > 0);
//     return {false, RES_ERR_UNIMPLEMENTED, {}};
//   }

  

//   /// Write the entire Storage object to the file specified by this.filename. To
//   /// ensure durability, Storage must be persisted in two steps.  First, it must
//   /// be written to a temporary file (this.filename.tmp).  Then the temporary
//   /// file can be renamed to replace the older version of the Storage object.
//   ///
//   /// @return A result tuple, as described in storage.h
//   virtual result_t save_file() {
//     cout << "my_storage.cc::save_file() is not implemented\n";
//     return {false, RES_ERR_UNIMPLEMENTED, {}};
//   }

//   /// Populate the Storage object by loading this.filename.  Note that load()
//   /// begins by clearing the maps, so that when the call is complete, exactly
//   /// and only the contents of the file are in the Storage object.
//   ///
//   /// @return A result tuple, as described in storage.h.  Note that a
//   ///         non-existent file is not an error.
//   virtual result_t load_file() {
//     FILE *storage_file = fopen(filename.c_str(), "r");
//     if (storage_file == nullptr) {
//       return {true, "File not found: " + filename, {}};
//     }
//     cout << "my_storage.cc::load_file() is not implemented\n";
//     return {false, RES_ERR_UNIMPLEMENTED, {}};
//   }
// };

// /// Create an empty Storage object and specify the file from which it should be
// /// loaded.  To avoid exceptions and errors in the constructor, the act of
// /// loading data is separate from construction.
// ///
// /// @param fname   The name of the file to use for persistence
// /// @param buckets The number of buckets in the hash table
// Storage *storage_factory(const std::string &fname, size_t buckets) {
//   return new MyStorage(fname, buckets);
// }


#include <cassert>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unistd.h>
#include <utility>
#include <vector>

#include "../common/constants.h"
#include "../common/contextmanager.h"
#include "../common/err.h"

#include "authtableentry.h"
#include "map.h"
#include "map_factories.h"
#include "storage.h"

using namespace std;

/// MyStorage is the student implementation of the Storage class
class MyStorage : public Storage {
  /// The map of authentication information, indexed by username
  Map<string, AuthTableEntry> *auth_table;

  /// The name of the file from which the Storage object was loaded, and to
  /// which we persist the Storage object when save() is invoked
  const string filename;

public:
  /// Construct an empty object and specify the file from which it should be
  /// loaded.
  MyStorage(const std::string &fname, size_t buckets)
      : auth_table(authtable_factory(buckets)), filename(fname) {}

  /// Destructor for the storage object.
  virtual ~MyStorage() {
    delete auth_table;
  }

  /// Authenticate a user
  virtual result_t auth(const string &user, const string &pass) {
    bool authenticated = false;
    bool found = auth_table->do_with_readonly(user, [&](const AuthTableEntry &entry) {
      if (entry.password == pass) {
        authenticated = true;
      }
    });

    if (!found || !authenticated) {
      return {false, RES_ERR_LOGIN, {}};
    }
    return {true, RES_OK, {}};
  }

  /// Create a new entry in the Auth table.
  virtual result_t add_user(const string &user, const string &pass) {
    AuthTableEntry entry{user, pass, {}};
    bool inserted = auth_table->insert(user, entry);
    if (!inserted) {
      return {false, RES_ERR_USER_EXISTS, {}};
    }
    return {true, RES_OK, {}};
  }

  /// Set the data bytes for a user, but do so if and only if the password matches
  virtual result_t set_user_data(const string &user, const string &pass,
                                 const vector<uint8_t> &content) {
    auto auth_res = auth(user, pass);
    if (!auth_res.succeeded) {
      return auth_res;
    }

    bool updated = auth_table->do_with(user, [&](AuthTableEntry &entry) {
      entry.content = content;
    });

    if (!updated) {
      return {false, RES_ERR_LOGIN, {}};
    }
    return {true, RES_OK, {}};
  }

  /// Return a copy of the user data for a user, but do so only if the password matches
  virtual result_t get_user_data(const string &user, const string &pass,
                                 const string &who) {
    auto auth_res = auth(user, pass);
    if (!auth_res.succeeded) {
      return auth_res;
    }

    vector<uint8_t> out_data;
    bool user_found = false;
    bool has_data = false;

    user_found = auth_table->do_with_readonly(who, [&](const AuthTableEntry &entry) {
      if (!entry.content.empty()) {
        has_data = true;
        out_data = entry.content;
      }
    });

    if (!user_found) {
      return {false, RES_ERR_NO_USER, {}};
    }
    if (!has_data) {
      return {false, RES_ERR_NO_DATA, {}};
    }

    return {true, RES_OK, out_data};
  }

  /// Return a newline-delimited string containing all of the usernames in the auth table
  /// Return a newline-delimited string containing all of the usernames in the auth table
  virtual result_t get_all_users(const string &user, const string &pass) {
    auto auth_res = auth(user, pass);
    if (!auth_res.succeeded) {
      return auth_res;
    }

    string users_list = "";
    auth_table->do_all_readonly([&](const string &key, const AuthTableEntry &) {
      users_list += key + "\n";
    });

    vector<uint8_t> data(users_list.begin(), users_list.end());
    return {true, RES_OK, data};
  }

  /// Write the entire Storage object to the file specified by this.filename.
  virtual result_t save_file() {
    string temp_filename = filename + ".tmp";
    FILE *fp = fopen(temp_filename.c_str(), "wb");
    if (fp == nullptr) {
      return {false, RES_ERR_SERVER, {}};
    }

    bool write_error = false;
    auth_table->do_all_readonly([&](const string &, const AuthTableEntry &entry) {
      if (write_error) return;

      if (fwrite(AUTHENTRY.c_str(), 1, 4, fp) != 4) {
        write_error = true;
        return;
      }

      uint32_t u_len = static_cast<uint32_t>(entry.username.size());
      uint32_t p_len = static_cast<uint32_t>(entry.password.size());
      uint32_t c_len = static_cast<uint32_t>(entry.content.size());

      if (fwrite(&u_len, 4, 1, fp) != 1 ||
          fwrite(&p_len, 4, 1, fp) != 1 ||
          fwrite(&c_len, 4, 1, fp) != 1) {
        write_error = true;
        return;
      }

      if (u_len > 0 && fwrite(entry.username.data(), 1, u_len, fp) != u_len) {
        write_error = true;
        return;
      }
      if (p_len > 0 && fwrite(entry.password.data(), 1, p_len, fp) != p_len) {
        write_error = true;
        return;
      }
      if (c_len > 0 && fwrite(entry.content.data(), 1, c_len, fp) != c_len) {
        write_error = true;
        return;
      }

      // Compute padding so entry is divisible by 4
      size_t total_bytes = 4 + 12 + u_len + p_len + c_len;
      size_t rem = total_bytes % 4;
      if (rem != 0) {
        size_t pad_len = 4 - rem;
        char pad[3] = {0, 0, 0};
        if (fwrite(pad, 1, pad_len, fp) != pad_len) {
          write_error = true;
          return;
        }
      }
    });

    fclose(fp);

    if (write_error) {
      unlink(temp_filename.c_str());
      return {false, RES_ERR_SERVER, {}};
    }

    if (rename(temp_filename.c_str(), filename.c_str()) != 0) {
      return {false, RES_ERR_SERVER, {}};
    }

    return {true, RES_OK, {}};
  }

  /// Populate the Storage object by loading this.filename.
  virtual result_t load_file() {
    FILE *fp = fopen(filename.c_str(), "rb");
    if (fp == nullptr) {
      return {true, "File not found: " + filename, {}};
    }

    auth_table->clear();

    while (true) {
      char header[4];
      size_t read_bytes = fread(header, 1, 4, fp);
      if (read_bytes == 0) {
        break; // Clean EOF
      }
      if (read_bytes < 4 || string(header, 4) != AUTHENTRY) {
        fclose(fp);
        return {false, RES_ERR_SERVER, {}};
      }

      uint32_t u_len = 0;
      uint32_t p_len = 0;
      uint32_t c_len = 0;

      if (fread(&u_len, 4, 1, fp) != 1 ||
          fread(&p_len, 4, 1, fp) != 1 ||
          fread(&c_len, 4, 1, fp) != 1) {
        fclose(fp);
        return {false, RES_ERR_SERVER, {}};
      }

      if (u_len > (uint32_t)LEN_UNAME || p_len > (uint32_t)LEN_PASSWORD || c_len > (uint32_t)LEN_PROFILE_FILE) {
        fclose(fp);
        return {false, RES_ERR_SERVER, {}};
      }

      string user(u_len, '\0');
      if (u_len > 0 && fread(&user[0], 1, u_len, fp) != u_len) {
        fclose(fp);
        return {false, RES_ERR_SERVER, {}};
      }

      string pass(p_len, '\0');
      if (p_len > 0 && fread(&pass[0], 1, p_len, fp) != p_len) {
        fclose(fp);
        return {false, RES_ERR_SERVER, {}};
      }

      vector<uint8_t> content(c_len);
      if (c_len > 0 && fread(content.data(), 1, c_len, fp) != c_len) {
        fclose(fp);
        return {false, RES_ERR_SERVER, {}};
      }

      size_t total_bytes = 4 + 12 + u_len + p_len + c_len;
      size_t rem = total_bytes % 4;
      if (rem != 0) {
        size_t pad_len = 4 - rem;
        char pad[3];
        if (fread(pad, 1, pad_len, fp) != pad_len) {
          fclose(fp);
          return {false, RES_ERR_SERVER, {}};
        }
      }

      auth_table->insert(user, AuthTableEntry{user, pass, content});
    }

    fclose(fp);
    return {true, "Loaded: " + filename, {}};
  }
};

/// Create an empty Storage object
Storage *storage_factory(const std::string &fname, size_t buckets) {
  return new MyStorage(fname, buckets);
}