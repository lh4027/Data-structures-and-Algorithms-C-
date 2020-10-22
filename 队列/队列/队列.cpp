//#include<iostream>
//
//using namespace std;
//
////队列的顺序存储结构
//const int QueueSize = 5;
//template<class T>
//class CirQueue
//{
//public:
//	CirQueue()
//	{
//		front = rear = QueueSize - 1;
//	}
//
//	void EnQueue(T x)//入队
//	{
//		if ((rear + 1) % QueueSize == front)
//		{
//			cout << "队列已满,入队失败！" << endl;
//			IsFull = true;
//			
//		}
//		else
//		{	
//			rear = (rear + 1) % QueueSize;//队尾指针再循环条件下加1
//			data[rear] = x;	
//			IsFull = false;
//		}
//	}
//	T DeQueue()//出队
//	{
//		if (front  == rear)
//		{
//			cout << "队列已空！" << endl;
//			
//			IsEmpty = true;
//			
//		}
//		front = (front + 1) % QueueSize;
//		return data[front];
//		
//		
//		IsEmpty = false;
//		
//	}
//
//
//	~CirQueue()
//	{
//
//	}
//
//	bool IsEmpty = 0;
//	bool IsFull = 0;
//private:
//	string data[QueueSize];//存放队列元素数组
//	int front, rear;    //队头和队尾指针
//
//};
//
//
//void Test01()
//{
//
//	CirQueue<string> CQ;
//	string str;
//	cout << "请输入入队的元素：" << endl;
//	while (cin >> str)
//	{
//		CQ.EnQueue(str);
//		if (CQ.IsFull)break;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		cout << CQ.DeQueue() << endl;
//
//	}
//	//cout << CQ.DeQueue() << endl;
//
//
//}
//
//int main()
//{
//	Test01();
//	system("pause");
//}