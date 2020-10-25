#pragma once
#include<iostream>
#include<string.h>
using namespace std;
const int Maxsize = 20;
const int MaxEdge = 50;

class EgdeArry      //prim算法辅助类型
{
public:
	int lowcost;//候选最短边权值
	int adjvex;//候选最短边的邻接点
};
//prim算法使用邻接矩阵图结构
class MGraph
{
private:
	string vertex1[Maxsize];  //存放顶点数据的数组
	int arc[Maxsize][Maxsize];//存放图边的数组
	int vertexNum1;//图的顶点数

public:
	
	
	MGraph(string * v, int* a, int n);
	void Prim(MGraph G);

};

class Edgetype   //kruskal算法的辅助类型
{
public:
	int from, to;//边依附的两个顶点
	int weight;//边的权值

};
//kruskal算法使用边集数组存储结构
class EdgeGraph
{
public:
	EdgeGraph(string *v ,int n,int e);  //边集数组结构构造函数
	void Kruskal(EdgeGraph G);

private:
	string vertex2[Maxsize];//顶点数据
	Edgetype edge[MaxEdge];//边集数组
	int vertexNum2, edgeNum;//顶点数，边数
};






