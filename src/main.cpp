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
// Author: 이현민
// Date: 2026-11-06

#include <iostream>
#include <string>

#include "avl_set.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int num_of_tests = 0;
  std::cin >> num_of_tests;

  while (num_of_tests--) {
    int num_of_questions = 0;
    std::cin >> num_of_questions;

    AVLSet avl_set;

    for (int i = 0; i < num_of_questions; i++) {
      std::string command;
      std::cin >> command;

      if (command == "Insert") {
        int key;
        std::cin >> key;

        std::cout << avl_set.Insert(key) << "\n";
      } else if (command == "Find") {
        int key;
        std::cin >> key;

        std::cout << avl_set.Find(key) << "\n";
      } else if (command == "Empty") {
        std::cout << ((avl_set.Empty()) ? "1" : "0") << "\n";
      } else if (command == "Size") {
        std::cout << avl_set.Size() << "\n";
      } else if (command == "Minimum") {
        int key;
        std::cin >> key;

        int min_key;
        int min_depth = avl_set.Minimum(key, &min_key);

        std::cout << min_key << " " << min_depth << "\n";
      } else if (command == "Maximum") {
        int key;
        std::cin >> key;

        int max_key;
        int max_depth = avl_set.Maximum(key, &max_key);

        std::cout << max_key << " " << max_depth << "\n";
      } else if (command == "Rank") {
        int key;
        std::cin >> key;

        int rank;
        int depth = avl_set.Rank(key, &rank);

        if (depth == -1) {
          std::cout << "-1\n";
        } else {
          std::cout << depth << " " << rank << "\n";
        }
      } else if (command == "Erase") {
        int key;
        std::cin >> key;

        std::cout << avl_set.Erase(key) << "\n";
      }
    }
  }

  return 0;
}