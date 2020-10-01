#include "testDebugger.h"

void testDB() {
  std::string s1 = "HELLO FROM testDebugger.\n";
  std::cout << s1;

  std::cout << "TEST 01: explicit constructor: d(0), e(0)\n";
  DEBUGGER dBg_01;
  dBg_01.printDBG();

  std::cout << "TEST 02: copy constructor:\n";
  DEBUGGER dBg_02(true);
  dBg_02.printDBG();

  int input;
  std::cin >> input;
  dBg_02 = input;
  dBg_02.printDBG();
}