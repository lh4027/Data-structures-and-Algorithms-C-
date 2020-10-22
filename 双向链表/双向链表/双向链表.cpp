#include<iostream>
using namespace std;


class DaulNode
{
public:
	string data;
	DaulNode* prior;//前驱节点
	DaulNode* next;//后继节点
};

class DaulList
{
public:
	DaulList()
	{
		first = new DaulNode;
		first->next = NULL;
		first->prior = NULL;
	}

	DaulList(string a[], int n)//构造双链表,尾插法
	{
		first = new DaulNode;    //开辟头结点空间
		DaulNode* p, * s;        //创建两个结点
		first->next = NULL;
		first->prior = NULL;
		p = first;              //p指向头结点

		for (int i = 0; i < n; i++)
		{
			s = new DaulNode;     //开辟新结点空间
			s->data = a[i];       //
			s->prior = p;
			s->next = p->next;
			p->next = s;

			p = s;//p指向s，使之循环生成链表
		}
		//加上下面语句变为循环双链表
		p->next = first->next;   //链表生成后，p指向最后一位,p再让其指向first后面第一位构成大循环
		first->next->prior = p;//first后面第一结点的前驱节点指向最后一位p
	}

	void Print()
	{
		DaulNode* p=first->next;
		if (p == NULL)
		{
			cout << "empty" << endl;
		}
		while(p!=NULL)
		{
			cout << p->data << endl;
			p = p->next;
		}
	}

private:
	DaulNode* first;
};




int main()
{
	string a[3] = { "as","as","124" };
	DaulList DL(a, 3);
	DL.Print();
	system("pause");
	return 0;
}