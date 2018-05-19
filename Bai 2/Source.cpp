//Dùng cây nhị phân tìm kiếm để thống kê số lần xuất hiện của
//từng ký tự trong một chuỗi nhập từ bàn phím.

#include <iostream>
#include <string>
using namespace std;

struct Node
{
public:
	char info;
	unsigned count;
	Node *left, *right;
	Node()
	{
		info = '/0';
		count = 0;
		left = right = NULL;
	}
	Node(char x)
	{
		info = x;
		count = 1;
		left = right = NULL;
	}
};

typedef Node * Tree;

void treeInit(Tree &);
void addNode(Tree &, char);
Tree stringToCharCountTree();
void LNR(Tree);

int main(void)
{
	Tree tree = stringToCharCountTree();
	LNR(tree);
	cout << endl;
	system("pause");
	return 0;
}

void treeInit(Tree &tree)
{
	tree = NULL;
}

void addNode(Tree &tree, char c)
{
	if (tree == NULL)
		tree = new Node(c);
	else if (tree->info == c)
		tree->count++;
	else if (c > tree->info)
		addNode(tree->right, c);
	else
		addNode(tree->left, c);
}

Tree stringToCharCountTree()
{
	string str;
	cout << "Nhap chuoi de dem so luong ki tu trong chuoi: ";
	getline(cin, str);
	int length = str.length();
	Tree tree;
	treeInit(tree);
	for (int i = 0; i < length; i++)
	{
		addNode(tree, str[i]);
	}
	return tree;
}

void LNR(Tree tree)
{
	if (tree == NULL)
		return;
	LNR(tree->left);
	cout << "'" << tree->info << "'" << ":" << tree->count << "   ";
	LNR(tree->right);
}