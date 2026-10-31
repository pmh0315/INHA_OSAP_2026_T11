# INHA_OSAP_2026_T11
## Node ADT
Member Variable
```cpp
int key_
int height_
int subtree_size_
Node* parent_node_
Node* left_node_
Node* right_node_
```
Member Function
```cpp
explicit Node(int key)
int get_key()
int get_height()
int get_subtree_size()
Node* get_parent_node()
Node* get_left_node()
Node* get_right_node()
void set_key(int key)
void set_height(int height)
void set_subtree_size(int subtree_size)
void set_parent_node(Node* parent_node)
void set_left_node(Node* left_node)
void set_right_node(Node* right_node) 
```
---
## AVLTree ADT
Member Variable
```cpp
Node* root_;
int size_;
```
Member Function
```cpp
AVLTree()
~AVLTree()
Node* FindNode(Node* node, int key) const
Node* FindNode(int key) const
Node* InsertNode(int key)
bool Empty() const
int Size() const
int GetDepth(Node* node) const
void RemoveNode(Node* node)
Node* GetSuccessor(Node* node) const
void Clear(Node* node)
```
---
## AVLSet ADT
Member Variable
```cpp
AVLTree tree_;
```
Member Function
```cpp
int Find(int key) const
int Insert(int key)
bool Empty() const
int Size() const
int Minimum(int key, int* min_key) const
int Maximum(int key, int* max_key) const
int Rank(int key, int* rank) const
int Erase(int key)
```
---
