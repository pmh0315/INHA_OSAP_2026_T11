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
// Author: 마승우, 박민혁
// Date: 2026-11-06

#include "include/avl_tree.h"

AVLTree::AVLTree() : root_(nullptr), size_(0) {}

// Clear함수 호출로 모든 노드의 동적 할당 해제
AVLTree::~AVLTree() {
  Clear(root_);
}

Node* AVLTree::FindNode(Node* node, int key) const {
  Node* cur_node = node;
  while (cur_node != nullptr) {
    if (key == cur_node->get_key()) {
      // 키를 찾으면 리턴
      return cur_node;
    } else if (key < cur_node->get_key()) {
      // 찾는 키 값이 현재 노드의 키 값보다 작으면 현재 노드를 left 노드로 변경
      cur_node = cur_node->get_left_node();
    } else {
      // 찾는 키 값이 현재 노드의 키 값보다 크면 현재 노드를 right 노드로 변경
      cur_node = cur_node->get_right_node();
    }
  }
  return nullptr;
}
// 루트를 고정으로 FindNode함수를 실행하는 함수
Node* AVLTree::FindNode(int key) const {
  return FindNode(root_, key);
}

Node* AVLTree::InsertNode(int key) {
  // 루트가 비어있으면(트리가 존재하지 않으면) 새로운 노드로 생성후 루트 설정
  if (root_ == nullptr) {
    root_ = new Node(key);
    size_++;
    return root_;
  }

  Node* cur_node = root_;
  Node* par_node = nullptr;
  while (cur_node != nullptr) {
    par_node = cur_node;
    if (key < cur_node->get_key()) {
      // 삽입 할 키 값이 현재 노드의 키 값보다 작으면 현재 노드를 left 노드로
      // 변경
      cur_node = cur_node->get_left_node();
    } else if (key > cur_node->get_key()) {
      // 삽입 할 키 값이 현재 노드의 키 값보다 크면 현재 노드를 right 노드로
      // 변경
      cur_node = cur_node->get_right_node();
    } else {
      // 키가 중복된 경우는 삽입 안 함
      return nullptr;
    }
  }

  Node* new_node = new Node(key);
  new_node->set_parent_node(par_node);
  if (key < par_node->get_key()) {
    // 새로운 노드 키 값이 부모 노드의 키 값보다 작으면 새로운 노드를 왼쪽
    // 자식으로 설정
    par_node->set_left_node(new_node);
  } else {
    // 새로운 노드 키 값이 부모 노드의 키 값보다 크면 새로운 노드를 오른쪽
    // 자식으로 설정
    par_node->set_right_node(new_node);
  }

  size_++;
  // Rebalance();  리밸런싱 함수 구현한 뒤 수정 필요함
  return new_node;
}

bool AVLTree::Empty() const {
  return size_ == 0;
}

int AVLTree::Size() const {
  return size_;
}

void AVLTree::Clear(Node* node) {
  if (node == nullptr) {
    return;
  }

  Clear(node->get_left_node());
  Clear(node->get_right_node());

  delete node;
}