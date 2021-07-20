#pragma once
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left = 0;
	node* right = 0;
};

class BinaryTree
{
private:
	node* root = NULL;
	void _InOrder(node*);
	void _PreOder(node*);
	void _PostOder(node*);
	void _Add(node*&, int);
	void _Clear(node*&);
public:
	BinaryTree(node* = NULL);
	void Add(int data) { {this->_Add(this->root, data); } };
	void AddRight(int);
	void AddLeft(int);
	void InOder() { {this->_InOrder(this->root); } };
	void PreOder() { {this->_PreOder(this->root); } };
	void PostOder() { {this->_PostOder(this->root); } };
	void Clear() { {this->_Clear(this->root);} };
	
};