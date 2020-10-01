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

  Node<T>* _hidden_cloneTree(Node<T>* node) {
    (!node) ? return nullptr
            : return new Node<T>(node->value, _hidden_cloneTree(node->l),
                                 _hidden_cloneTree(node->r));
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
      (!root->l) ? root->l = new Node<T>(val) : _hidden_addNode(root->l, val);
    }

    else {
      (!root->r) ? root->r = new Node<T>(val) : _hidden_addNode(root->r, val);
    }
  }

  void _hidden_printOrder_IN(Node<T>* root, std::ostream& output) {
    (!root) ? return;
    _hidden_printOrder_IN(root->l, output);
    output << root->value << '--> ';
    _hidden_printOrder_IN(root->r, output);
  }

  void _hidden_printOrder_POST(Node<T>* root, std::ostream& output) {
    (!root) ? return;
    _hidden_printOrder_POST(root->l, output);
    _hidden_printOrder_POST(root->r, output);
    output << root->val << '--> ';
  }

  void _hidden_printOrder_PRE(Node<T>* root, std::ostream& output) {
    (!root) ? return;
    output << root->val << '--> ';
    _hidden_printOrder_PRE(root->l, output);
    _hidden_printOrder_PRE(root->r, output);
  }

  void _hidden_printOrder_LEVEL(Node<T>* root, std::ostream& output) {
    (!root) ? return;
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
    (!root)
        ? return 0
        : return 1 + _hidden_countNodes(root->l) + _hidden_countNodes(root->r);
  }

  int _hidden_getHeight(Node<T>* root) {
    (!root) ? return -1
            : return 1 + max(_hidden_getHeight(root->l),
                             _hidden_getHeight(root->r));
  }

  void _hidden_printLongestPath(Node<T>* root, std::ostream& output) {
    (!root) ? return;
    output << root->val << '--> ';
    (__hidden_getHeight(root->l) > _hidden_getHeight(root->r))
        ? _hidden_printLongestPath(root->l)
        : _hidden_printLongestPath(root->r);
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
          (predecessor->l == current) ? predecessor->l = temp
                                      : predecessor->r = temp;
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
    (!root) ? return false
            : (root->value == val)
                  ? return true
                  : (root->value > val)
                        ? return (_hidden_checkIf_val_exists(root->l, val))
                        : return (_hidden_checkIf_val_exists(root->r, val));
  }

 public:
  BinST() : _root(nullptr) {}

  BinST(intializer_list<T> vals) : _root(nullptr) {
    for (auto val : vals) {
      this->add(val);
    }
  }

  ~BinST() { (this->_debug) ? _hidden_destroyBranch(this->_root); }

  BinST(const BinST& another) : _root(nullptr) {
    (this->_debug) ? std::cout << "[_debug] Invoked:\"Copy Constructor\""
                               << std::endl;
    this->_root = _hidden_cloneTree(another._root);
  }

  BinST(BinST&& another) : _root(nullptr) {
    (this->_debug) ? std::cout << "[_debug] Invoked:\"Move Constructor\""
                               << std::endl;
    this->_root = another._root;
    another._root = nullptr;
  }

  BinST& operator=(BinST& another) {
    (this->_debug) ? std::cout << "[_debug] Invoked:\"Copy Assignment\""
                               << std::endl;
    this->_root = _hidden_cloneTree(another._root);
    return *this;
  }

  BinST& operator=(BinST&& another) {
    (this->_debug) ? std::cout << "[_debug] Invoked:\"Move Assignment\""
                               << std::endl;
    this->_root = another._root;
    another._root = nullptr;
    return *this;
  }

  void destroyBranch() {
    (this->_root) ? this->_hidden_destroyBranch(this->_root);
    this->_root = nullptr;
  }

  void add(T val) {
    (this->_root) ? this->_hidden_addNode(this->_root, val)
                  : this->_root = new Node<T>(val);
  }

  bool empty() { return (this->root == nullptr); }

  void print(std::ostream& output = std::cout) {
    _hidden_printOrder_IN(this->_root, output);
  }

  void print_PostOrder(std::ostream& output = std::cout) {
    _hidden_printOrder_POST(this->_root, output);
  }

  void print_PreOrder(std::ostream& output = std::cout) {
    _hidden_printOrder_PRE(this->_root, output);
  }

  void print_LevelOrder(std::ostream& output = std::cout) {
    _hidden_printOrder_LEVEL(this->_root, output);
  }

  int size() { return totalNodes; }

  int count_Nodes() { return _hidden_countNodes(this->_root); }

  int getHeight() { return _hidden_getHeight(this->_root); }

  void printLongestPath() { _hidden_printLongestPath(this->_root); }

  bool deleteValue(T val) {
    return this->_hidden_deleteValue(nullptr, this->_root, val);
  }

  bool foundInTree(T val) {
    return _hidden_checkIf_val_exists(this->_root, val);
  }

  void debug_on() { this->_debug = true; }

  void debug_off() { this->_debug = false; }
};

#endif