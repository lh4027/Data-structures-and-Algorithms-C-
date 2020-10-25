//#include<iostream>
//
//using namespace std;
//
//const int MaxSize = 10;//顶点最大值
//const int StackSize = 100;//栈最大容量
//
//
//
//template<class T>
//class MGraph
//{
//public:
//	MGraph(T a[], int n, int e)  //无向图的邻接矩阵
//	{
//		vertexNum = n;
//		this->arcNum = e;
//		int x,y;
//		for ( int i = 0; i < this->vertexNum; i++) //初始化邻接矩阵
//		{
//			vertex[i] = a[i];
//			for (int j = 0; j < this->vertexNum; j++)
//				arc[i][j] = 0;
//		}	
//		for (int k = 0; k < arcNum; k++)      //输入每一条边
//		{
//			cout << "请输入无向图两个连接顶点编号：";
//			cin >> x >> y;
//			arc[x][y] = 1;                      //置边标志
//			arc[y][x] = 1;
//		}
//	}
//
//	~MGraph()
//	{
//
//	}
//	//深度优先遍历算法
//	void DFSTraverse(int v)
//	{
//		
//		cout << vertex[v];
//		//visited[v] = 1;
//		for (int j = 0; j < this->vertexNum; j++)
//		{
//			if (arc[v][j] == 1 && visited[j] != 1)
//				DFSTraverse(j);
//		}
//		
//	}
//
//	void BFSTraverse(int v)
//	{
//		int front = -1;
//		int rear = -1;  //初始化队列
//		int Q[MaxSize];
//		int* visited = new int;
//
//		cout << vertex[v];   //打印顶点v
//
//		visited[v] = 1;    //
//		Q[++rear] = v;    //顶点v入队
//		while (front != rear)  //队列非空时
//		{
//			v = Q[++front];     //将队队头元素出队并送到v
//			for (int i = 0; i < this->vertexNum; i++)
//			{
//				if (this->arc[v][i] == 1 && visited[i] != 1)
//				{
//					cout << this->vertex[i]<<" ";
//					visited[i] = 1;
//					Q[++rear] = i;
//				}
//			}
//		}
//		
//	}
//
//private:
//	T vertex[MaxSize];//存放图中顶点信息的数组
//	int arc[MaxSize][MaxSize];//存放边的数组
//	int vertexNum, arcNum;//图的顶点数和边数
//	int visited[MaxSize];//
//	
//};
//
//
//
//int main()
//{
//	string a[] = { "lh","zhf","shz","cxk"};
//	MGraph<string> MG(a,4,4);
//	MG.BFSTraverse(0);
//	MG.DFSTraverse(0);
//	
//
//}
