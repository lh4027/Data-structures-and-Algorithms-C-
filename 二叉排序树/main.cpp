#include<iostream>
#include"BiTree.h"
using namespace std;

//二叉排序树插入算法
void BiSortTree::InsertBST(BiNode<int> *&root, int key)  //将根节点root以引用的方式传入
{
	if (root == NULL)   
	{
		root = new BiNode<int>;
		root->data = key;
		root->lchild = NULL; root->rchild = NULL;
	}
	else
	{
		if (root->data > key)
			InsertBST(root->lchild, key);//如果插入的数据比根节点的数据小，就插到左子树上
		else if(root->data < key)
			InsertBST(root->rchild, key);//同上相反
	}
}


//二叉排序树构造函数
BiSortTree::BiSortTree(int a[], int n)
{
	this->root = NULL;
	for (int i = 0; i < n; i++)//n为插入的结点数
	{
		InsertBST(this->root,a[i]);
	}
	InOrder(this->root); //中序遍历查看是否插入正确
}

//二叉排序树查找算法
BiNode<int>* BiSortTree:: SearchBST(BiNode<int>* root, int k)//查找值为k的结点
{
	if (root == NULL||root->data == k)
		return root;
    if (root->data > k)
		return SearchBST(root->lchild, k);
	else
		return SearchBST(root->rchild, k);
}
void BiSortTree::SearchBST(int k)
{
	if (SearchBST(root, k) != NULL)
	{
		cout << "查找" << SearchBST(root, k)->data << "成功！" << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}
}

//二叉排序树删除算法
void BiSortTree::DeleteNode(BiNode<int>*& p) //p待删除结点，f为其双亲结点
{
	BiNode<int>* q;
	BiNode<int>* s;
	if (p->rchild == NULL) //只有左子树
	{
		q = p;
		p = p->lchild;
		delete q;
	}
	else if (p->lchild == NULL)//只有右子树
	{
		q = p;
		p = p->rchild;
		delete q;
	}
	else //左右子树都有，找出所需删除结点的左子树中最大的结点，将它的值赋给所需删除结点，再将它删除
	{
		//Delete_Key_Node(p, p->lchild);
		q = p;
		s = p->lchild;
		while (s->rchild)   //在p的左子树中继续查找其前驱节点，即最右下结点
		{
			q = s;
			s = s->rchild;
		}
		p->data = s->data;//s的值赋给被删除结点p，然后删除s结点
		if (q != p)
			q->rchild = s->lchild;//重接q的右子树
		else
			q->lchild = s->lchild;//重接q的左子树
		delete s;
	}
}
void BiSortTree::DeleteBFS(int key)
{
	if (root == NULL) return;
	else
	{
		if (root->data == key)
			DeleteNode(root);
		else if (root->data > key)
			DeleteNode(root->lchild);
		else
			DeleteNode(root->rchild);
	}
	cout << "删除" <<key << "成功！" << endl;
	InOrder(root); //中序遍历查看是否删除正确

}

void test1()
{
	int a[10] = { 63,55,90,42,58,70,10,45,67,83 };
	BiSortTree BST(a, 10);
	cout << endl;
	BST.SearchBST(83);
	BST.DeleteBFS(63);
}

int main()
{
	test1();
	return 0;
	system("pause");
}