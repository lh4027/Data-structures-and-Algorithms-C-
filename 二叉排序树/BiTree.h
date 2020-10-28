#pragma once
#include<iostream>
using namespace std;

template<class T>
class BiNode
{
public:
	T data;
	BiNode<T>* lchild, * rchild;
};

//构建二叉排序树类
class BiSortTree
{
public:
	BiSortTree( int a[], int n);
	void InsertBST(BiNode<int> * &root, int key); //插入一个结点
	void DeleteBFS(int key);//删除结点f的左孩子p

	BiNode<int>* SearchBST(BiNode<int>* root, int k);//查找值为k的结点
	void SearchBST(int k);

private:
	BiNode<int>* root;  //二叉树根结点
	void InOrder(BiNode<int>* bt);
	void DeleteNode(BiNode<int>*& p);
	
};

void BiSortTree::InOrder(BiNode<int>* bt)  //二叉树中序遍历
{
	if (bt == NULL)return;
	else
	{
		InOrder(bt->lchild);
		cout << bt->data << " ";
		InOrder(bt->rchild);
	}
}