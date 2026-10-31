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
// Date: 2026-10-30

#ifndef AVLSET_INCLUDE_AVL_SET_H_
#define AVLSET_INCLUDE_AVL_SET_H_

#include "avl_tree.h"

class AVLSet {
 public:
  int Find(int key) const;

  int Insert(int key);

  bool Empty() const;

  int Size() const;

  int Minimum(int key, int* min_key) const;

  int Maximum(int key, int* max_key) const;

  int Rank(int key, int* rank) const;

  int Erase(int key);

 private:
  AVLTree tree_;
};

#endif  // AVLSET_INCLUDE_AVL_SET_H_
