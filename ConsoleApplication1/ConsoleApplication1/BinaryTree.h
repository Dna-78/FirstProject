#pragma once
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left = NULL;
	node* right = NULL;
};

class BinaryTree
{
private:
	node* root;
public:
	BinaryTree(node* = NULL);
	void AddRight(int);
	void AddLeft(int);

	void PreoOder(node* root)
	{
		if (root == NULL)
		{
			return;

			cout << root->data << "\t";
			PreoOder(root->left);
			PreoOder(root->right);
		}
	}
};