#include<iostream>
#include"HashList.h"
using namespace std;

void HashList::Insert(int k)
{
	int j;
	j = k % divitor;//计算散列地址
	Node* p = ht[j].first;
	//头插法
	Node* q = new Node;
	q->m_data = k;
	q->next = ht[j].first;
	ht[j].first = q;
}

void HashList::CreatHT(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		Insert(a[i]);
	}
	for (int i = 0; i < Maxsize; i++)
	{
		Node* p = ht[i].first;
		while (p != NULL) 
		{
			cout << p->m_data << " ";
			p = p->next;
		}
	}
}

void HashList::Delete(int k)
{
	Node* p = HashSearch(k);
	if (p)
	{
		p->m_data = NULL;
		//delete p;
		cout << "删除成功！" << endl;
	}
	else
		cout << "不存在，删除失败！" << endl;

	//test
	for (int i = 0; i < Maxsize; i++)
	{
		Node* p = ht[i].first;
		while (p != NULL)
		{
			cout << p->m_data << " ";
			p = p->next;
		}
	}
}

//开散列表查找算法
Node *HashList::HashSearch(int value)
{
	int j;
	
	j = value % divitor;
	
	last = ht[j].first;
	Node* p = last;
	while (p != NULL)
	{
		if (p->m_data == value)
		{
			cout << "查到" << p->m_data << endl;
			return p; 
			break;
		}
		else
		{
			last = p;
			p = p->next;
			
		}
	}
	cout << "查找失败！" << endl;
	return 0;
}


void test()
{
	HashList HL(Maxsize,11);
	int a[9] = { 47,7,29,11,16,92,22,8,3 };
	HL.CreatHT(a, 9);
	HL.HashSearch(92);
	HL.Delete(92);
	
}

int main()
{
	test();
	system("pause");
	return 0;
}