#pragma once
#include<iostream>
using namespace std;
const int Maxsize = 20;

class ArcNode //边表节点
{
public:
	int adjvex;// 邻接点域
	ArcNode* next;//指针域
	int weight;//权值

};

class VertexNode // 顶点表结点
{
public:
	string vertex;
	int in;//入度
	ArcNode* firstedge;//顶点邻接点域
	

};

class ALGraph
{
public:
	ALGraph(string a[],int b[], int n, int e);
	vector<int> TopSort(ALGraph G);
	void FindKeyPath(ALGraph G);

	

	
private:
	int vertexNum, arcNum;
	VertexNode adjlist[Maxsize];
};
