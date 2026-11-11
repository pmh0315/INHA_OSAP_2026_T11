// MIT License

// Copyright (c) 2026

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Author: 채은재
// Date: 2026-11-06

#include "avl_set.h"

#include "node.h"

int AVLSet::Find(int key) const {
  Node* node = tree_.FindNode(key);
  if (node == nullptr) {
    return -1;
  }
  return tree_.GetDepth(node);
}

int AVLSet::Insert(int key) {
  Node* node = tree_.InsertNode(key);
  if (node == nullptr) {
    return -1;
  }
  return tree_.GetDepth(node);
}

bool AVLSet::Empty() const { return tree_.Empty(); }

int AVLSet::Size() const { return tree_.Size(); }

int AVLSet::Minimum(int key, int* depth) const {
  Node* node = tree_.FindNode(key);
  if (node == nullptr) {
    return -1;
  }
  while (node->get_left_node() != nullptr) {
    node = node->get_left_node();
  }
  *depth = tree_.GetDepth(node);
  return node->get_key();
}

int AVLSet::Maximum(int key, int* depth) const {
  Node* node = tree_.FindNode(key);
  if (node == nullptr) {
    return -1;
  }
  while (node->get_right_node() != nullptr) {
    node = node->get_right_node();
  }
  *depth = tree_.GetDepth(node);
  return node->get_key();
}

int AVLSet::Rank(int key, int* depth) const {
  Node* node = tree_.FindNode(key);
  if (node == nullptr) {
    return -1;
  }
  Node* left = node->get_left_node();
  int num_smaller = (left == nullptr) ? 0 : left->get_subtree_size();
  Node* child = node;
  Node* parent = node->get_parent_node();
  while (parent != nullptr) {
    if (parent->get_right_node() == child) {
      num_smaller += parent->get_subtree_size() - child->get_subtree_size();
    }
    child = parent;
    parent = parent->get_parent_node();
  }
  *depth = tree_.GetDepth(node);
  return num_smaller + 1;
}

int AVLSet::Erase(int key) {
  Node* node = tree_.FindNode(key);
  if (node == nullptr) {
    return -1;
  }
  int depth = tree_.GetDepth(node);
  tree_.RemoveNode(node);
  return depth;
}
