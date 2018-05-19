//Tạo một cây nhị phân tìm kiếm bằng cách đọc dữ liệu từ file.
//File được tổ chức như sau : 
//N //số nút trong cây  
//8 //giá trị của các nút  
//3
//7
#include <iostream>
#include <fstream>
#include "../DA-TH6-KHTN/BST.h"
using namespace std;

int main()
{
	Tree tree;
	treeInit(tree);
	ifstream fileIn("data.txt");
	int n; fileIn >> n;
	for (int i = 0, j; i < n; i++)
	{
		fileIn >> j;
		addNode(tree, j);
	}

	LNR(tree);
	cout << endl;
	system("pause");
	fileIn.close();
	return 0;
}