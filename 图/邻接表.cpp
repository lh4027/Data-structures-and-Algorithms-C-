#include<iostream>
using namespace std;

const int MaxSize = 100;
//定义边表结点
class ArcNode
{
public:
	int adjvex;//邻接点域
	ArcNode* next;//指针域，指向边表下一个结点
	int info;//边的权值
};

template<class T>
class VertexNode   //定义顶点表结点
{
public:

	T vertex;     //顶点数据域
	ArcNode* firstedge;  //顶点指针域，指向边表第一个结点
};

template<class T>
class ALGraph     //邻接表构造函数
{
public:
	ALGraph( int n, int e);
	~ALGraph()
	{

	}
	void DFSTraverse(int v);
	void BFSTraverse(int v);
private:
	VertexNode<T> adjlist[MaxSize];//存放顶点表的数组
	int vertexNum, arcNum;//图的顶点数，边数
	//int visited[MaxSize];
};

template<class T>
ALGraph<T>::ALGraph(int n, int e)
{
	//输入顶点信息，初始化顶点表
	vertexNum = n;
	arcNum = e;
	int b1=0, b2=0, b_flag=0;//暂存顶点编号
	
	for (int i = 0;i < n; i++)
	{
		cout << "请输入顶点的值：" << endl;
		cin>>adjlist[i].vertex ;
		adjlist[i].firstedge = NULL;
	}
	//输入每一条边，并采用头插法生成新边表，（尾插法不行）
	for (int i = 0; i < arcNum; i++)
	{
		ArcNode* s = new ArcNode;
		
		cout << "请输入有向边所依附的两个顶点编号：";
		cin >> b1 >> b2 ;
		s->adjvex = b2;
		cout << "请输入这条边所对应的权值：";
		cin >> s->info;
		s->next = adjlist[b1].firstedge;
		adjlist[b1].firstedge = s;

	}
}

template<class T>
void ALGraph<T>::DFSTraverse(int v)
{
	int visited[MaxSize];
	cout << "顶点:" << adjlist[v].vertex << " ";
	visited[v] = 1;
	ArcNode* p = adjlist[v].firstedge;
	while (p != NULL)
	{
		if (visited[p->adjvex] != 1)
			DFSTraverse(p->adjvex);
		p = p->next; 
		
	}
}
template<class T>
void ALGraph<T>::BFSTraverse(int v)
{
	//初始化队列
	int front = -1, rear = -1;
	int Q[MaxSize];
	int visited[MaxSize];
	cout << "顶点：" << adjlist[v].vertex << " ";
	 visited[v] = 1;
	Q[++rear] = v;
	
	while (front != rear)
	{
		v = Q[++front];
		ArcNode* s = adjlist[v].firstedge;
		while (s != NULL)
		{
			if (visited[s->adjvex] != 1)
			{
				cout << adjlist[s->adjvex].vertex<<" ";
				visited[s->adjvex] = 1;
				Q[++rear] = s->adjvex;
			}
			s = s->next;
		}
	}
}
int main()
{
	string a[] = { "lh","zhf","shz","cxk" };
	ALGraph<string> AL(4,4);
	AL.DFSTraverse(0);
	AL.BFSTraverse(0);
	system("pause");
}