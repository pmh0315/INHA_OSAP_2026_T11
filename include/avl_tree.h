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
// GitHubId: Zutomaro1411, choco103-dev
// Date: 2026-10-30

#ifndef AVLSET_INCLUDE_AVL_TREE_H_
#define AVLSET_INCLUDE_AVL_TREE_H_

#include "node.h"

class AVLTree {
 public:
  AVLTree();
  ~AVLTree();

  Node* FindNode(Node* node, int key) const;
  Node* FindNode(int key) const;
  Node* InsertNode(int key);
  bool Empty() const;
  int Size() const;
  int GetDepth(Node* node) const;
  void RemoveNode(Node* node);

  // node의 height, subtree_size 값 업데이트
  void UpdateNode(Node* node);
  // node의 left_node와 right_node의 height 차이 리턴
  int GetBalanceFactor(Node* node) const;
  Node* RotateLeft(Node* z);
  Node* RotateRight(Node* z);
  // 리밸런싱이 필요 시 상황에 맞게 수행
  void Rebalance(Node* z);

 private:
  Node* GetSuccessor(Node* node) const;
  void Clear(Node* node);

  Node* root_;
  int size_;
};

#endif  // AVLSET_INCLUDE_AVL_TREE_H_