#ifndef __BS_TREE_H__
#define __BS_TREE_H__
struct bs_tree_node {
  int key;
  bs_tree_node* left;
  bs_tree_node* right;
  bs_tree_node* p;
};

class bs_tree {
protected:
  bs_tree_node* T_root;

public:
  // int* A  = new int[size];
  bs_tree();
  ~bs_tree();
  int count = 0;
  int* Arr;
  void insert(int*, int);
  // int* inorder_output(int);

  // void inorder_output() {
  //   inorder_output(T_root, 1);
  // }
  void insert(int);
  // int* output(int );
  int output(int*);
  int duplicates = 0;
  int getCount() {
    // delete[] A;
    return count;
  }
  ;
  int duplicates_count() {
    return duplicates;
  };
  // int* inorder_output(int);

  // void inorder_output() {
  //   inorder_output(T_root, 1);
  // }

protected:
  void insert(bs_tree_node*);
  
  void remove_all(bs_tree_node*);

  void inorder_output(bs_tree_node*, int);
  void delete_array(int*);
};

#endif

