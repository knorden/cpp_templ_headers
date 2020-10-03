#include "testMyTemplate.h"

void testMyTemplate() {
  BinST<int> tTree{1, 2, 3, 4, 5, 6};
  // Turn on debugging mode:
  tTree.debug_on();
  std::cout << "tTree: ";
  tTree.print();

  std::cout << "\n\nTest #1: deep copy constructor:\n";
  BinST<int> deepCopiedTree(tTree);
  std::cout << "BinST<int> deepCopiedTree(tTree): ";
  deepCopiedTree.print();

  std::cout << "\n\nTest #2: deep copy assignment operator:\n";
  BinST<int>* tAsm = nullptr;
  tAsm = new BinST<int>;
  std::cout << "tAsm before copy assigment: ";
  tAsm->print();
  std::cout << std::endl;
  *tAsm = deepCopiedTree;
  std::cout << "tAsm after copy assignment: ";
  tAsm->print();

  std::cout << "\n\nTest #3: tTree destructed:\n";
  std::cout << "tTree before destructor is called: ";
  tTree.print();
  std::cout << "\ntTree.~BinST() is invoked.\n";
  tTree.~BinST();
  std::cout << "call tTree.printInOrder() to check values of tTree after "
               "destruction: ";
  tTree.print();
  std::cout << "\ntTree destructed successfully.\n";

  std::cout << "\n\nTest #4: move constructor:\n";
  std::cout << "Tree A before moving: ";
  deepCopiedTree.print();
  std::cout << "\nTree A's height before moving: "
            << deepCopiedTree.getHeight();
  BinST<int> tTree_new = std::move(deepCopiedTree);
  std::cout << "\nTree A after moving: ";
  deepCopiedTree.print();
  std::cout << "\nTree A's height after moving: " << deepCopiedTree.getHeight();
  std::cout << "\nNewly constructed tree B after moving: ";
  tTree_new.print();
  std::cout << "\nNewly constructor tree B's height after moving: "
            << tTree_new.getHeight();

  std::cout << "\n\nTest #5: move assignment constructor:\n";
  BinST<int> tA{1, 3, 5, 6}, tB{2, 5, 4, 8, 10};
  std::cout << "Before moving:\n";
  std::cout << "Tree A: ";
  tA.print();
  std::cout << std::endl;
  std::cout << "Tree B: ";
  tB.print();
  tA = std::move(tB);
  std::cout << std::endl;
  std::cout << "After moving:\n";
  std::cout << "Tree A: ";
  tA.print();
  std::cout << std::endl;
  std::cout << "Tree B: ";
  tB.print();
  std::cout << std::endl;

  std::cout << "\n\nTest #6: BST::printLevelOrderHelper():\n";
  BinST<int> tC{3, 5, 4, 1, 6, 8, 13, 25};
  tC.print_LevelOrder();

  std::cout << "\n\n\nEnd of Test.\nAll trees destroyed." << std::endl;
}

void anotherTest() {
  std::cout << "ANOTHER TEST" << std::endl;

  BinST<int> pretr{65, 67, 66, 73, 70, 71, 74, 68, 72, 75};
  BinST<int> intr{73, 66, 67, 70, 74, 71, 65, 68, 75, 72};

  pretr.debug_on();
  intr.debug_on();

  pretr.printLongestPath();
  std::cout << std::endl;
  intr.printLongestPath();
}