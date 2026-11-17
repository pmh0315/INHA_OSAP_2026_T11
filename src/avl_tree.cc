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

#include <algorithm>

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

  // 상향식 Rebalancing
  while (par_node != nullptr) {
    Node* new_par_node = par_node->get_parent_node();
    Rebalance(par_node);
    par_node = new_par_node;
  }

  return new_node;
}

bool AVLTree::Empty() const {
  return size_ == 0;
}

int AVLTree::Size() const {
  return size_;
}

int AVLTree::GetDepth(Node* node) const {
  if (node == nullptr) {
    return -1;
  }

  int depth = 0;
  Node* cur_node = node;
  
  // 루트 노드(부모가 nullptr인 노드)에 도달할 때까지 반복
  while (cur_node->get_parent_node() != nullptr) {
    depth++;
    cur_node = cur_node->get_parent_node();
  }
  
  return depth;
}

void AVLTree::RemoveNode(Node* node) {
  if (node == nullptr) {
    return;
  }

  Node* left_node = node->get_left_node();
  Node* right_node = node->get_right_node();
  
  //자식이 둘 다 존재할 경우 후임자(successor) 사용
  if (left_node != nullptr && right_node != nullptr) {
    Node* successor = GetSuccessor(node);
    node->set_key(successor->get_key());

    //실제 삭제와 리밸런싱은 후임자 위치에서 수행하도록 재귀적 호출
    RemeveNode(successor);
    return;
  }

  Node* par_node = node->get_parent_node();
  Node* child = (left_node != nullptr) ? left_node : right_node;

  if (child != nullptr) {
    child->set_parent_node(par_node);
  }

  if (par_node == nullptr) {
    // 삭제하는 노드가 트리의 루트였던 경우 루트 변경
    root_ = child;
  } else if (par_node->get_left_node() == node) {
    par_node->set_left_node(child);
  } else {
    par_node->set_right_node(child);
  }

  delete node;
  size_--;

   // 상향식 Rebalancing
  while (par_node != nullptr) {
    Node* new_par_node = par_node->get_parent_node();
    Rebalance(par_node);
    par_node = new_par_node;
  }
}

void AVLTree::UpdateNode(Node* node) {
  if (node == nullptr) {
    return;
  }

  Node* left_node = node->get_left_node();
  int left_node_height = GetNodeHeight(left_node);
  int left_node_subtree_size = GetNodeSubtreeSize(left_node);

  Node* right_node = node->get_right_node();
  int right_node_height = GetNodeHeight(right_node);
  int right_node_subtree_size = GetNodeSubtreeSize(right_node);

  int child_max_height = std::max(left_node_height, right_node_height);
  node->set_height(child_max_height + 1);
  node->set_subtree_size(left_node_subtree_size + right_node_subtree_size + 1);
}

int AVLTree::GetBalanceFactor(Node* node) const {
  if (node == nullptr) {
    return 0;
  }

  Node* left_node = node->get_left_node();
  int left_node_height = GetNodeHeight(left_node);

  Node* right_node = node->get_right_node();
  int right_node_height = GetNodeHeight(right_node);

  return left_node_height - right_node_height;
}

Node* AVLTree::RotateLeft(Node* z) {
  if (z == nullptr) {
    return nullptr;
  }

  Node* y = z->get_right_node();
  if (y == nullptr) {
    return nullptr;
  }

  Node* parent_node = z->get_parent_node();
  if (parent_node == nullptr) {
    root_ = y;
  } else if (parent_node->get_left_node() == z) {
    parent_node->set_left_node(y);
  } else {  // parent_node->get_right_node() == z
    parent_node->set_right_node(y);
  }

  Node* y_left_node = y->get_left_node();
  if (y_left_node != nullptr) {
    y_left_node->set_parent_node(z);
  }
  z->set_parent_node(y);
  z->set_right_node(y_left_node);
  y->set_parent_node(parent_node);
  y->set_left_node(z);

  // 아래 노드부터 Update
  UpdateNode(z);
  UpdateNode(y);

  return y;
}

Node* AVLTree::RotateRight(Node* z) {
  if (z == nullptr) {
    return nullptr;
  }

  Node* y = z->get_left_node();
  if (y == nullptr) {
    return nullptr;
  }

  Node* parent_node = z->get_parent_node();
  if (parent_node == nullptr) {
    root_ = y;
  } else if (parent_node->get_left_node() == z) {
    parent_node->set_left_node(y);
  } else {  // parent_node->get_right_node() == z
    parent_node->set_right_node(y);
  }

  Node* y_right_node = y->get_right_node();
  if (y_right_node != nullptr) {
    y_right_node->set_parent_node(z);
  }
  z->set_parent_node(y);
  z->set_left_node(y_right_node);
  y->set_parent_node(parent_node);
  y->set_right_node(z);

  // 아래 노드부터 Update
  UpdateNode(z);
  UpdateNode(y);

  return y;
}

void AVLTree::Rebalance(Node* z) {
  if (z == nullptr) {
    return;
  }

  UpdateNode(z);

  int balance_factor = GetBalanceFactor(z);
  if (balance_factor >= 2) {
    Node* y = z->get_left_node();
    if (y == nullptr) {
      return;
    }

    if (GetBalanceFactor(y) >= 0) {
      RotateRight(z);
    } else {
      RotateLeft(y);
      RotateRight(z);
    }
  } else if (balance_factor <= -2) {
    Node* y = z->get_right_node();
    if (y == nullptr) {
      return;
    }

    if (GetBalanceFactor(y) <= 0) {
      RotateLeft(z);
    } else {
      RotateRight(y);
      RotateLeft(z);
    }
  }
}

Node* AVLTree::GetSuccessor(Node* node) const {
  if (node == nullptr) {
    return nullptr;
  }

  // 오른쪽 자식이 있는 경우 오른쪽 서브트리에서 가장 왼쪽 아래로 내려간 노드
  if (node->get_right_node() != nullptr) {
    Node* cur_node = node->get_right_node();
    while (cur_node->get_left_node() != nullptr) {
      cur_node = cur_node->get_left_node();
    }
    return cur_node;
  }

  // 오른쪽 자식이 없는 경우 부모를 타고 올라가며 자신이 왼쪽 자식인 첫 번째 부모
  Node* cur_node = node;
  Node* par_node = cur_node->get_parent_node();
  
  while (par_node != nullptr && cur_node == par_node->get_right_node()) {
    cur_node = par_node;
    par_node = par_node->get_parent_node();
  }
  
  return par_node;
}

int AVLTree::GetNodeHeight(Node* node) const {
  return (node != nullptr) ? node->get_height() : 0;
}

int AVLTree::GetNodeSubtreeSize(Node* node) const {
  return (node != nullptr) ? node->get_subtree_size() : 0;
}

void AVLTree::Clear(Node* node) {
  if (node == nullptr) {
    return;
  }

  Clear(node->get_left_node());
  Clear(node->get_right_node());

  delete node;
}