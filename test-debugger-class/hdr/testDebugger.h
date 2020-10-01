#ifndef TESTDEBUGGER_H
#define TESTDEBUGGER_H
#include <iostream>
#include <string>

class DEBUGGER {
 protected:
  bool debug;
  bool error;

  void _typecastConstr(int val) {
    static_cast<int>(val) == 1 ? debug = 1 : debug = 0;
  }
  void _debug_SWITCH(const int val) { _typecastConstr(val); }
  void _debug_ON() {
    if (!debug)
      debug = true;
    error = false;
  }
  void _debug_OFF() {
    if (debug)
      error = debug = false;
  }

 public:
  // constructor default to OFF.
  explicit DEBUGGER() : debug(false), error(false) {}
  DEBUGGER(int val) {
    _typecastConstr(val);
    error = false;
  }

  void operator=(int val) { _debug_SWITCH(val); }

  //   void operator=(bool isDb) {
  //     if (isDb == true) {
  //       debug = true;
  //       error = false;
  //     } else {
  //       debug = false;
  //       error = false;
  //     }
  //   }

  //   DEBUGGER& operator=(bool isDb) {
  //     debug = isDb;
  //     error = false;
  //     return *this;
  //   }

  void printDBG() {
    std::cout << "-------------------------------------------\n";
    std::cout << ">>>>>>> \"THIS DEBUGGER INSTANCE\":  debug= " << debug
              << std::endl;
    std::cout << "\t\t\t\t   error= " << error << std::endl;
    std::cout << "-------------------------------------------\n\n";
  }
};

void testDB();

#endif
