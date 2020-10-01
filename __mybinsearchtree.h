#ifndef __MYBINSEARCHTREE_H
#define __MYBINSEARCHTREE_H
#include <initializer_list>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

template <typename T>
class Node {
 public:
  T value;
  Node* l;
  Node* r;
  static unsigned int totalNodes;

  Node(T val) {
    this->value = val;
    this->l = nullptr;
    this->r = nullptr;
    ++totalNodes;
  }

  Node(T val, Node<T>* nleft, Node<T>* nright) {
    this->value = val;
    this->l = nleft;
    this->r = nright;
  }

  ~Node() {
    this->value = 0;
    this->l = nullptr;
    this->r = nullptr;
    --totalNodes;
  }

  void operator=(const Node<T>& rNode) {
    this->value = rNode.value;
    this->l = rNode.l;
    this->r = rNode.r;
  }
};

template <typename T>
int Node<T>::totalNodes = 0;

template <typename T>
class BinST {
 protected:
  Node<T>* _root;
  bool _debug = false;

  Node<T>* _cloneTree(Node<T>* node) {
    if (!node)
      return nullptr;
    else
      return new Node<T>(node->value, _cloneTree(node->l), _cloneTree(node->r));
  }

  void _hidden_destroyBranch(Node<T>* b) {
    if (b) {
      _hidden_destroyBranch(b->l);
      _hidden_destroyBranch(b->r);
      delete b;
    }
  }

  void _hidden_addNode(Node<T>* root, T val) {
    if (root->value > val) {
      if (!root->l)
        root->l = new Node<T>(val);
      else
        _hidden_addNode(root->l, val);
    }

    else {
      if (!root->r)
        root->r = new Node<T>(val);
      else
        _hidden_addNode(root->r, val);
    }
  }

  void _hidden_printOrder_IN(Node<T>* root, std::ostream& output) {
    if (!root)
      return;
    _hidden_printOrder_IN(root->l, output);
    output << root->value << '--> ';
    _hidden_printOrder_IN(root->r, output);
  }

  void _hidden_printOrder_POST(Node<T>* root, std::ostream& output) {
    if (!root)
      return;
    _hidden_printOrder_POST(root->l, output);
    _hidden_printOrder_POST(root->r, output);
    output << root->val << '--> ';
  }

  void _hidden_printOrder_PRE(Node<T>* root, std::ostream& output) {
    if (!root)
      return;
    output << root->val << '--> ';
    _hidden_printOrder_PRE(root->l, output);
    _hidden_printOrder_PRE(root->r, output);
  }

  void _hidden_printOrder_LEVEL(Node<T>* root, std::ostream& output) {
    if (!root)
      return;
    std::queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
      int num_nodes = static_cast<int>(q.size());
      while (num_nodes > 0) {
        Node<T>* nPtr = q.front();
        output << nPtr->value << '--> ';
        q.pop();
        if (nPtr->l) {
          q.push(nPtr->l);
        }
        if (nPtr->r) {
          q.push(nPtr->r);
        }
        --num_nodes;
      }
      output << std::endl;
    }
  }

  int _hidden_countNodes(Node<T>* root) {
    if (!root)
      return 0;
    else
      return 1 + _hidden_countNodes(root->l) + _hidden_countNodes(root->r);
  }

  int _hidden_getHeight(Node<T>* root) {
    if (!root)
      return -1;
    else
      return 1 + max(_hidden_getHeight(root->l), _hidden_getHeight(root->r));
  }

  void _hidden_getLongestPath(Node<T>* root, std::ostream& output) {
    if (!root)
      return;
    output << root->val << '--> ';
    if (__hidden_getHeight(root->l) > _hidden_getHeight(root->r))
      _hidden_getLongestPath(root->l);
    else
      _hidden_getLongestPath(root->r);
  }

  bool _hidden_deleteValue(Node<T>* predecessor, Node<T>* current, T val) {
    if (!current)
      return false;
    if (current->value == val) {
      if (!current->l || !current->r) {
        Node<T>* temp = current->l;

        if (current->r)
          temp = current->r;

        if (predecessor) {
          if (predecessor->l == current)
            predecessor->l = temp;
          else
            predecessor->r = temp;
        }

        else
          this->_root = temp;
      }

      else {
        Node<T>* valid = current->r;
        while (valid->l)
          valid = valid->l;

        T tempVal = current->value;
        current->value = valid->value;
        valid->value = tempVal;
        return _hidden_deleteValue(current, current->r, tempVal);
      }
      delete current;
      return true;
    }
    return _hidden_deleteValue(current, current->l, val) ||
           _hidden_deleteValue(current, current->r, val);
  }

  bool _hidden_checkIf_val_exists(Node<T>* root, T val) {
      if (!root)
        return false;
      else if (root->value == val)
        return true;
      else if(root->value > val)
        return (_hidden_checkIf_val_exists(root->l, val));
      else
        return (_hidden_checkIf_val_exists(root->r, val));
  }

 public:
 BinST() : _root(nullptr) {}
 
};

#endif