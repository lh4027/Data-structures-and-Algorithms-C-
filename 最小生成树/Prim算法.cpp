#include<iostream>
#include"graph.h"
using namespace std;

//
MGraph::MGraph(string* v, int* a, int n)
{
	
	this->vertexNum= n;
	//初始化arc存放边的矩阵
	for (int i = 0; i < Maxsize; i++)
		for (int j = 0; j < Maxsize; j++)
			arc[i][j] = 10000;
	//存储顶点信息
	for (int i = 0; i < vertexNum; i++)
		vertex[i] = v[i];
	//存储边的信息
	for (int i = 0; i < vertexNum; i++)
		for (int j = 0; j < vertexNum; j++)
			arc[i][j] = *(a + i * n + j);
}

int MinEdge(EgdeArry *shortedge, int n)
{
	int k = 0,min=shortedge[1].lowcost;
	for (int i = 1; i < n; i++)
	{
		if (shortedge[i].lowcost <= min)
		{
			k = i;
			min = shortedge[i].lowcost;
		}
	}
	return k;
}
//最小生成树算法

void MGraph::Prim(MGraph G)
{
	EgdeArry shortedge[Maxsize];//prim算法辅助数组
	int k;//边的权值最小的辅助数组下标
	//初始化辅助数组
	for (int i = 1; i < G.vertexNum; i++)
	{
		shortedge[i].lowcost = G.arc[0][i];
		shortedge[i].adjvex = 0;
	}
	//输出顶点v0，将顶点0加入集合U
	shortedge[0].lowcost = 0;
	
	for (int i = 1; i < G.vertexNum; i++)
	{
		k = MinEdge(shortedge, G.vertexNum);  //寻找最短边的邻接点k
		cout << k << " " << shortedge[k].adjvex << " " << shortedge[k].lowcost << endl; //输出
		shortedge[k].lowcost = 0;//将顶点k加入集合U
		for (int j = 1; j < G.vertexNum; j++)        //调整数组shortedge
		{
			if (G.arc[k][j] < shortedge[j].lowcost)
			{
				shortedge[j].lowcost = G.arc[k][j];
				shortedge[j].adjvex = k;
			}
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
		p=&cost[0][0];

	
	MGraph MG(vname, p, 6);
	//cout << MG.arc[0][1];
	//Prim(MG);

	system("pause");
	return 0;
}

