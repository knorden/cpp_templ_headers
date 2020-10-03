/****************************************************************************
 **	NAME: CHALRES NORDEN, CLASS: CptS-223
 ** ASSIGNMENT: MA2, Binary Search Tree and C++11+
 ****************************************************************************/
/****************************************************************************
 * MOVE CONSTRUCTOR:
 * A Move Constructor constructs a new data unit by assigning the resource
 * of a passed-in data to it, while also releasing the old unit from the
 * system.
 *
 * MOVE ASSIGNMENT OPERATOR:
 * A Move Assignment Operator transfer resource from a right-value data unit
 * to an existing left-value data unit.
 *
 ****************************************************************************/
/****************************************************************************
 * BST::empty(): worst case: O(1).
 * It's a single operation returning the root node.
 * BST::add(): worst case: O(N).
 * This is when we have to append a leaf to continuous tree with one trunk
 * and no leaves.
 * BST::makeEmpty(): worst case: O(N).
 * We must traverse through all nodes to delete the tree.
 * BST::printLevelOrder(): worst case: O(N).
 * We must traverse through all nodes to print their values.
 * BST::cloneTree(): worst case: O(N).
 * We must traverse through all node to clone the tree.
 */
// #include "testBST.h"
#include "testMyTemplate.h"

int main() {
  std::string tSTRING = "THIS IS A TEST STRING\n";
  std::cout << tSTRING;

  // testBST();

  // testMyTemplate();

  anotherTest();

  return 0;
}