#include <iostream>
#include "BST.h"
using namespace std;


int main(void)
{
	Tree tr;
	int a[] = {5, 2, 7, 4, 6, 8, 1, 3, 9};
	tr = ArrayToBST(a, 9);
	LNR(tr);
	cout << endl;
	deleteNode(tr, 2);
	deleteNode(tr, 7);
	deleteNode(tr, 5);
	deleteNode(tr, 1);
	LNR(tr);
	cout << endl;
	cout << "So node la: " << countNode(tr) << endl;
	cout << "So cay con la: " << countSubTree(tr) << endl;
	cout << "So nut la la: " << countLeaf(tr) << endl;
	system("pause");
	return 0;
}