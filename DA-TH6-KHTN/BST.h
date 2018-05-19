#pragma once
#include <iostream>
using namespace std;

struct Node
{
public:
	unsigned info;
	Node *left, *right;
	Node()
	{
		info = 0;
		left = right = NULL;
	}
	Node(int x)
	{
		info = x;
		left = right = NULL;
	}
};

typedef Node* Tree;
void treeInit(Tree &);
Tree &ArrayToBST(int[], int);
void addNode(Tree &, unsigned);
Node* &findNode(Tree &, unsigned);
void deleteNode(Tree &, unsigned);
void deleteNode(Tree &);
Node *searchStandFor(Tree &, Tree&);
Node* findMinimum(Tree);
unsigned countNode(Tree);
unsigned countSubTree(Tree);
unsigned countLeaf(Tree);
unsigned treeHeight(Tree);
void LRN(Tree);
void LNR(Tree);
void RNL(Tree);
void RLN(Tree);
void NRL(Tree);
void NLR(Tree);

inline void treeInit(Tree &tr)
{
	tr = NULL;
}

inline Tree &ArrayToBST(int a[], int n)
{
	Tree * tree = new Tree;
	Tree &tr = *tree;
	treeInit(tr);
	for (int i = 0; i < n; i++)
		addNode(tr, a[i]);
	return tr;
}

inline void addNode(Tree &tr, unsigned x)
{
	if (tr != NULL)
	{
		if (x <= tr->info)
			addNode(tr->left, x);
		else
			addNode(tr->right, x);
	}
	else 
		tr = new Node(x);
}

inline Node*& findNode(Tree &tr, unsigned x)
{
	if (tr != NULL)
	{
		if (tr->info == x)
			return tr;
		if (x <= tr->info)
		{
			return findNode(tr->left, x);
		}
		else
		{
			return findNode(tr->right, x);
		}
	}
	else
	{

		Node** ptr = new Node*;
		Node *&p = *ptr;
		return p;
	}
}

inline void deleteNode(Tree & tr, unsigned x)
{
	// tim node chua x de xoa
	if (tr == NULL)
		return;
	else if (x < tr->info)
		deleteNode(tr->left, x);
	else if (x > tr->info)
		deleteNode(tr->right, x);
	// tim duoc
	else // x == tr->info
		deleteNode(tr);
}

inline void deleteNode(Tree & tr)
{
	Node *temp = tr;
	// if leaf
	if (!tr->left && !tr->right)
	{
		tr = NULL;
		delete temp;
	}
	// if has only right child
	else if (!tr->left && tr->right)
	{
		tr = tr->right;
		delete temp;
	}
	// if has only left child
	else if (tr->left && !tr->right)
	{
		tr = tr->left;
		delete temp;
	}
	// if both children
	else
	{
		temp = searchStandFor(tr->left, tr);
		delete temp;
	}
}

inline Node * searchStandFor(Tree &subtree, Tree &root)
{
	// tim rightmost ele
	if (subtree->right)
		return searchStandFor(subtree->right, root);
	// found it
	Node * temp = subtree;
	root->info = subtree->info;
	subtree = subtree->left;
	return temp;
}

inline Node* findMinimum(Tree tr)
{
	if (!tr->left)
		return tr;
	return findMinimum(tr->left);
}

inline unsigned countNode(Tree tr)
{
	// dung dem khi gap node NULL
	if (tr == NULL)
		return 0;
	// neu khong, tang mot don vi dem, dem ben phai va ben trai
	else
		return 1 + countNode(tr->left) + countNode(tr->right);
}

inline unsigned countSubTree(Tree tr)
{
	// dung dem khi gap node NULL
	if (tr == NULL)
		return 0;
	// neu khong, tang mot don vi dem neu node co hai con, dem trai, dem phai
	else if (tr->left && tr->right)
		return 1 + countSubTree(tr->left) + countSubTree(tr->right);
	// neu khong, dem trai, dem phai
	else
		return 0 + countSubTree(tr->left) + countSubTree(tr->right);
}

inline unsigned countLeaf(Tree tr)
{
	// dung dem khi gap node NULL
	if (tr == NULL)
		return 0;
	// tang mot don vi khi gap node la
	if (!tr->left && !tr->right)
		return 1;
	// neu khong, dem trai, dem phai
	else
		return countLeaf(tr->left) + countLeaf(tr->right);
}

inline unsigned treeHeight(Tree tr)
{
	if (tr == NULL)
		return 0;
	unsigned a = treeHeight(tr->left), b = treeHeight(tr->right);
	return 1 + (a > b ? a : b);
}

void LRN(Tree tr)
{
	if (tr == NULL)
		return;
	LRN(tr->left);
	LRN(tr->right);
	cout << tr->info;
}
void LNR(Tree tr)
{
	if (tr == NULL)
		return;
	LNR(tr->left);
	cout << tr->info << "  ";
	LNR(tr->right);
}
void RNL(Tree tr)
{
	if (tr = NULL)
		return;
	LNR(tr->right);
	cout << tr->info << "  ";
	LNR(tr->left);
}
void RLN(Tree tr)
{
	if (tr = NULL)
		return;
	LNR(tr->right);
	LNR(tr->left);
	cout << tr->info << "  ";
}
void NRL(Tree tr)
{
	if (tr == NULL)
		return;
	cout << tr->info << "  ";
	NRL(tr->right);
	NRL(tr->left);
}
void NLR(Tree tr)
{
	if (tr == NULL)
		return;
	cout << tr->info << "  ";
	NLR(tr->left);
	NLR(tr->right);
}