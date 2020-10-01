#ifndef __MYDB_H
#define __MYDB_H
#include <string>

struct DEBUGGER {
  bool debug;
  bool error;

  explicit DEBUGGER(bool isDb) : debug(false), error(false) {}

  void operator=(bool isDb) {
    if (isDb == true) {
      debug = true;
      error = false;
    } else {
      debug = false;
      error = false;
    }
  }

  DEBUGGER& operator=(bool isDb) {
    debug = isDb;
    error = false;
    return *this;
  }
};

#endif