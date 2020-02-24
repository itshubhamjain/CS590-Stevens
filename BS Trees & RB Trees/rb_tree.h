#ifndef __RB_TREE_H__
#define __RB_TREE_H__

enum rb_tree_color {
  RB_RED, RB_BLACK
};

struct rb_tree_node {
  int key;
  int color;
  rb_tree_node* left;
  rb_tree_node* right;
  rb_tree_node* p;
};

class rb_tree {
protected:
  rb_tree_node* T_nil;
  rb_tree_node* T_root;

public:
  rb_tree();
  ~rb_tree();
  int* A = new int[1];
  int duplicates = 0;
  int case1 = 0;
  int case2 = 0;
  int case3 = 0;
  int countLeft = 0;
  int countRight = 0;
  void insert(int*, int);
  void insert(int);
  int count = 0;
  int output(int*);

  int getCount() {
    return count;
  };
  int count_Duplicates() {
    return duplicates;
  };
  int count_Left() {
    return countLeft;
  };
  int count_Right() {
    return countRight;
  };

  int count_Case1() {
    return case1;
  };
  int count_Case2() {
    return case2;
  };
  int count_Case3() {
    return case3;
  };

  int heightTree() {
    int height;
    height = blackheight(T_root);
    return height;
  };

  // void inorder_output() {
  //   inorder_output(T_root, 1);
  // }
  // void output() {
  //   output(T_root, 1);
  // }
  // int output(int) {
  // output(T_root, 1, int);}

protected:
  int blackheight(rb_tree_node*);
// void blackheight(rb_tree_node* x);
  void insert(rb_tree_node*);
  void insert_fixup(rb_tree_node*&);

  void remove_all(rb_tree_node*);

  void left_rotate(rb_tree_node*);
  void right_rotate(rb_tree_node*);

  void inorder_output(rb_tree_node*, int);
  void output(rb_tree_node*, int);
  int maximum(int, int);
// void output(rb_tree_node*, int);
};

#endif
