#include<iostream>
#include"graph.h"
using namespace std;


MGraph::MGraph(string* v, int* a, int n)
{

	this->vertexNum1 = n;
	//初始化arc存放边的矩阵
	for (int i = 0; i < Maxsize; i++)
		for (int j = 0; j < Maxsize; j++)
			arc[i][j] = 10000;
	//存储顶点信息
	for (int i = 0; i < vertexNum1; i++)
		vertex1[i] = v[i];
	//存储边的信息
	for (int i = 0; i < vertexNum1; i++)
		for (int j = 0; j < vertexNum1; j++)
			arc[i][j] = *(a + i * n + j);
}
//最小生成树算法
void MGraph::Prim(MGraph G)
{
	EgdeArry shortedge[Maxsize];//prim算法辅助数组
	//初始化辅助数组
	for (int i = 1; i < G.vertexNum1; i++)
	{		
		shortedge[i].lowcost = G.arc[0][i];
		shortedge[i].adjvex = 0;
	}
	//输出顶点v0，将顶点0加入集合U
	shortedge[0].lowcost = 0;

	for (int i = 1; i < G.vertexNum1; i++)
	{
		 //寻找最短边的邻接点k
		int k = 0, min = shortedge[1].lowcost;
		for (int i = 1; i < G.vertexNum1; i++)
		{
			if (shortedge[i].lowcost <= min&& shortedge[i].lowcost!=0)
			{
				k = i;
				min = shortedge[i].lowcost;
			}
		}
		cout << k << " " << shortedge[k].adjvex << " " << shortedge[k].lowcost << endl; //输出
		
		shortedge[k].lowcost = 0;//将顶点k加入集合U
		for (int j = 1; j < G.vertexNum1; j++)        //调整数组shortedge
		{
			if (G.arc[k][j] < shortedge[j].lowcost)
			{
				shortedge[j].lowcost = G.arc[k][j];
				shortedge[j].adjvex = k;
			}
		}
	}  
}
/*-----------------------kruskal最小生成树算法-------------------------*/
//构造函数
EdgeGraph::EdgeGraph(string * v, int n,int e)
{
	this->edgeNum = e;
	this->vertexNum2 = n;
	for (int i = 0; i < this->vertexNum2; i++)
	{
		this->vertex2[i] = v[i];
	}
	for (int i = 0; i < this->edgeNum; i++)
	{
		cout << "请输入第" << i + 1 << "条边对应的两个顶点序号" << endl;
		cin >> this->edge[i].from >> this->edge[i].to;
		cout << "请输入这条边对应的权值：" << endl;
		cin >> this->edge[i].weight;
	}
	//为了提高查找最短边的速度，先对边集数组按边上的权排序。(冒泡排序)
	int exchange =edgeNum - 1;
	int bound;
	int temp;

	while (exchange != 0)
	{
		bound = exchange; exchange = 0;
		for (int i = 0; i < bound; i++)
		{
			if (edge[i].weight > edge[i + 1].weight)
			{
				temp = edge[i].weight;
				edge[i].weight = edge[i + 1].weight;
				edge[i + 1].weight = temp;
				exchange = i;
			}
		}
	}
}

//求顶点双亲的函数
int FindRoot(int parent[], int v)
{
	int t;
	t = v;
	while (parent[t] > -1)
		t = parent[t];
	return t;
}

void EdgeGraph::Kruskal(EdgeGraph G)
{
	
	//-tset
	/*for (int i = 0; i < G.edgeNum; i++)
		cout << G.edge[i].weight << " ";*/

	//初始化辅助数组parent
	int parent[Maxsize];
	int  vex1, vex2;
	for (int i = 0; i < G.vertexNum2; i++)
		parent[i] = -1;
	for (int num = 0, i = 0; i < G.edgeNum; i++)
	{
		vex1 = FindRoot(parent, G.edge[i].from);
		vex2 = FindRoot(parent, G.edge[i].to);
		if (vex1 != vex2)
		{
			cout << "从顶点" << G.vertex2[G.edge[i].from] << "到" << G.vertex2[G.edge[i].to] << "的距离为：" << G.edge[i].weight << endl;
			parent[vex2] = vex1;  //合并生成树
			num++;
			if (num == G.edgeNum - 1) return;

		}
	}

}

int main()
{
	int cost[6][6] = { {0,34,46,10000,10000,19},
					  {34,0,10000,10000,12,10000},
					  {46,10000,0,17,10000,25},
					  {10000,10000,17,0,38,25},
					  {10000,12,10000,38,0,26},
					  {19,10000,25,25,26,0} };
	string vname[6] = { "V0","V1","V2","V3","V4","V5" };
	int* p;
	p = &cost[0][0];



	MGraph MG(vname, p, 6);
	MG.Prim(MG);
	EdgeGraph EG(vname,6, 9);
	EG.Kruskal(EG);
	system("pause");
	return 0;
}


