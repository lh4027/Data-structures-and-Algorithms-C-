#pragma once
#define Maxsize 20
//定义边表结点类
class Node
{
public:
	int m_data;//数据域
	Node* next;//指针域
};
//定义单链表类作为开散列表
class hashlist
{
public:
	Node *first;
};

class HashList
{
public:
	void CreatHT(int a[], int n);  //创建一个哈希表
	void Insert(int k);   //哈希表插入算法
	void Delete(int k);//哈希表删除算法
	Node * HashSearch(int value);  //哈希表查找算法
	HashList(int size, int d)
	{
		ht = new hashlist [size];
		divitor = d;
		for (int i = 0; i < size; i++)
		{
			ht[i].first= NULL;
		}
	}
private:
	hashlist *ht;
	int divitor;
	Node* last;//用于记录需要删除结点的上一个结点位置
};
