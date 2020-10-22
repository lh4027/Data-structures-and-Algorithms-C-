#include<iostream>
using namespace std;

//中缀表达式转化为后缀表达式（未成功）
class Node
{
public:
	int data;
	Node* next;
};

class LinkStack
{
public:
	LinkStack()
	{
		top = NULL;
		base = NULL;
	}
	void Push(char x)
	{
		/*if ((top - base) > StackSpace)
		{
			cout << "栈已满！" << endl;
		}*/
		Node* s = new Node;
		s->data = x;
		s->next = top;
		top = s;
	}
	
	char Pop()
	{
		Node* p;
		char x;
		if (top == NULL)
		{
			cout << "栈为空！" << endl;
		}
		p = top;
		x = p->data;
		top = top->next;
		delete p;
		return x;
	}
	int IsEmpty()
	{
		if (top == NULL)
			return 1;
		else return 0;
	}

	const int StackSpace = 100;
private:
	Node * top = new Node;
	Node * base = new Node;
};

void test01()
{
	LinkStack LS;
	char c,e;

	cout << "请输入后缀表达式，以#作为结束标志" << endl;
	cin >> c;
	while (c != '#')
	{
		if (c >= '0' && c <= '9')
		{
			cout << c << " ";
		}
		else if (')' == c)  //遇到右括号开始弹栈
		{
			e = LS.Pop();
			while ('(' != e)//弹栈知道遇到左括号
			{
				cout << LS.Pop() << " "; 
			}
		}
		else if ('+' == c || '-' == c)
		{
			if (LS.IsEmpty())
			{
				LS.Push(c);
			}
			else
			{
				do
				{
					e = LS.Pop();
					if ('(' == e)
					{
						LS.Push(e);
					}
					else
					{
						cout << e << " ";
					}
				} while (!LS.IsEmpty() && '(' == e);
				LS.Push(c);

			}
		}
		else if ('*' == c || '/' == c || '(' == c)
		{
			LS.Push(c);
		}
		else
		{
			cout << "输入格式错误！" << endl;

		}
	
		cin >> c;
	}
}

int main()
{
	
	test01();
	
}