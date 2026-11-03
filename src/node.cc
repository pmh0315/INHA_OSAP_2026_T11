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
// Author: 박민혁
// Date: 2026-11-03

#include "include/node.h"

using namespace std;

explicit Node::Node(int key)
    : key_(key),
      height_(1),
      subtree_size_(1),
      parent_node_(nullptr),
      left_node_(nullptr),
      right_node_(nullptr) {}

int Node::get_key() const {
  return key_;
}

int Node::get_height() const {
  return height_;
}

int Node::get_subtree_size() const {
  return subtree_size_;
}

Node* Node::get_parent_node() const {
  return parent_node_;
}

Node* Node::get_left_node() const {
  return left_node_;
}

Node* Node::get_right_node() const {
  return right_node_;
}

void Node::set_key(int key) {
  key_ = key;
}

void Node::set_height(int height) {
  height_ = height;
}

void Node::set_subtree_size(int subtree_size) {
  subtree_size_ = subtree_size;
}

void Node::set_parent_node(Node* parent_node) {
  parent_node_ = parent_node;
}

void Node::set_left_node(Node* left_node) {
  left_node_ = left_node;
}

void Node::set_right_node(Node* right_node) {
  right_node_ = right_node;
}