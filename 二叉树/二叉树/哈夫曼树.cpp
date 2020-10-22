#include<iostream>
using namespace std;


class element
{
public:
	int weight;
	int lchild, rchild, parent;
};

//选取权值最小的两个结点
void  Select(element a[],int n,int &s1,int &s2 )
{
	for (int i = 0; i < n; i++) //初始化s1，s1的双亲为-1
	{
		if (a[i].parent == -1)
		{
			s1 = i; break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i].parent == -1 && a[s1].weight > a[i].weight)
		{
			s1 = i;
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (a[j].parent == -1 && j != s1)
		{
			s2 = j; break;
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (a[j].parent == -1 && a[s2].weight > a[j].weight&& j != s1)
		{
			s2 = j;
		}
	}
}

void HuffmanTree(element huffmanTree[], int w[], int n)
{
	for (int i = 0; i < 2 * n - 1; i++)  //初始化，所有结点均没有双亲和孩子
	{
		huffmanTree[i].parent = -1;
		huffmanTree[i].lchild = -1;
		huffmanTree[i].rchild = -1;
	}

	for (int i = 0; i < n; i++)  //构造只有根节点的n棵二叉树
	{
		huffmanTree[i].weight = w[i];
	}
	for (int k = n; k < 2 * n - 1; k++)
	{
		int i1, i2;
		Select(huffmanTree, k, i1, i2);
		huffmanTree[i1].parent = k;
		huffmanTree[i2].parent = k;
		huffmanTree[k].weight = huffmanTree[i1].weight + huffmanTree[i2].weight;
		huffmanTree[k].lchild = i1;
		huffmanTree[k].rchild = i2;
	}
}

void print(element hT[], int n)
{
	cout << "index " << "weight " << "parent " << "lchild " << "rchild " << endl;
	cout << left;
	for (int i = 0; i < n; i++)
	{
		cout << i ;
		cout << "        " << hT[i].weight ;
		cout << "        " << hT[i].parent ;
		cout << "       " << hT[i].lchild;
		cout << "       " << hT[i].rchild << endl;
	}
}
int main()
{
	int x[] = { 2,3,4,5 };
	element* huffmantree = new element[2 * size(x) - 1];
	HuffmanTree(huffmantree, x, 4);
	print(huffmantree, 7);
	system("pause");
	return 0;
}