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
// Author: 마승우
// GitHubId: Zutomaro1411
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

 private:
  Node* GetSuccessor(Node* node) const;       
  void Clear(Node* node);

  Node* root_;
  int size_;
};

#endif