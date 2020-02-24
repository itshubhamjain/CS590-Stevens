#include "bs_tree.h"
#include <iostream>

using namespace std;

bs_tree::bs_tree() {
	T_root = new bs_tree_node();
	T_root = NULL;
	Arr = new int[10];
}

bs_tree::~bs_tree() {
	remove_all (T_root);
	// cout<<"Inside Destructor\n";
	// delete[] Arr;
	delete_array (Arr);
}

void bs_tree::insert(int* key_array, int n) {
	for (int i = 0; i < n; i++)
		insert(key_array[i]);
	// cout << "\n\n\nDone\n\n";
	// delete[] key_array;

}

void bs_tree::insert(int key) {
	bs_tree_node* z;
	z = new bs_tree_node;
	z->key = key;
	insert(z);
}
// * binary tree type insert
// * -> search position, insert new node
// * -> fix properties after insert

void bs_tree::insert(bs_tree_node* z) {
	bs_tree_node* x;
	bs_tree_node* y;

	y = NULL;
	x = T_root;
	while (x != NULL) {
		y = x;
		if (z->key == x->key) {
			++duplicates;

			// cout<<"\nCan't insert, same key found\n";
			return;
		}
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	count++;
	// cout<<count<<"\t";
	z->p = y;
	if (y == NULL)
		T_root = z;
	else {
		if (z->key < y->key)
			y->left = z;
		else
			y->right = z;
	}

	z->left = NULL;
	z->right = NULL;
}

// void bs_tree::inorder_output(bs_tree_node* x) {
// 	if (x != NULL) {
// 		inorder_output(x->left);
// 		cout << "(" << x->key << ")" << endl;
// 		inorder_output(x->right);
// 	}
// }

void bs_tree::inorder_output(bs_tree_node* x, int level) {

	if (x != NULL) {
		inorder_output(x->left, level + 1);
		// cout << "(" << x->key << "," << level << ")" << endl;
		Arr[count] = x->key;
		++count;
		inorder_output(x->right, level + 1);
	}
}

// int* bs_tree::output(int size){

// 	delete[] Arr;
// 	Arr  = new int[size];
// 	count = 0 ;
// 	inorder_output(T_root,1);
// 	// count = 0;
// 	return Arr;
// }

int bs_tree::output(int* output_array) {

	delete_array (Arr);
	Arr = new int[count];
	count = 0;
	inorder_output(T_root, 1);
	for (int i = 0; i < count - 1; i++) {
		output_array[i] = Arr[i];
	}
	// delete[] Arr;
	// count = 0;
	return count;
}

void bs_tree::delete_array(int* array) {
	if (array) {
		delete[] array;
	}
}

void bs_tree::remove_all(bs_tree_node* x) {
	if (x != NULL) {
		if (x->left != NULL)
			remove_all(x->left);
		if (x->right != NULL)
			remove_all(x->right);
		delete x;
	}
}

