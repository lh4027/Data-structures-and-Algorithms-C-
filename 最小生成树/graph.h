#pragma once
#include<iostream>
#include<string>

const int Maxsize = 20;

//声明邻接矩阵图结构
class MGraph
{
private:
	string vertex[Maxsize];  //存放顶点数据的数组
	int arc[Maxsize][Maxsize];//存放图边的数组
	int vertexNum;//图的顶点数

public:
	
	MGraph()
	{
		
	}
	MGraph(string *v, int* a, int n);
	void Prim(MGraph G);

};

class EgdeArry
{
public:
	int lowcost;//候选最短边权值
	int adjvex;//候选最短边的邻接点
};




