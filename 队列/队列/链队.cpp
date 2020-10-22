#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node<T> *next;
};

template<class T>
class LinkQueue
{
public:
	LinkQueue()
	{
		Node<T> *s = new Node<T>;     //创建头结点
		s->next = NULL;          
		front = rear = s; //将队头指针和队尾指针均指向头结点s
		
	}



	~LinkQueue()
	{

	}

	void EnQueue(T x)   //入队
	{
		Node<T> *s = new Node<T>;   //创建新结点
		s->data = x;            //入队数据赋给x
		s->next = NULL;
		rear->next = s;      //将结点S插到队尾
		rear = s;       //队尾指针指向s结点（向后移）
	}

	T Dequeue()
	{
		T x;
		if (rear == front)
		{
			cout << "队列为空" << endl;
		}
		
		Node<T>* p = new Node<T>;
		p = front->next;
		x = p->data;           //暂存对头元素
		front->next = p->next;    //将队头元素所在结点摘链
		if (p->next == NULL)     //判断出队前队列长度是否为1
		{
			rear = front;
		}
		delete p;
		return x;
	}

private:
	Node<T> * front,*rear;
};


int main()
{
	LinkQueue<string> LQ;
	LQ.EnQueue("李浩1");
	LQ.EnQueue("李浩2");
	LQ.EnQueue("李浩3");
	LQ.EnQueue("李浩4");

	for (int i = 0; i <4; i++)
	{
		cout << LQ.Dequeue() << endl;
	}
	system("pause");
}
