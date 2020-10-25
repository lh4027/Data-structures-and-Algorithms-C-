#include<iostream>
#include<vector>
#include"ALGraph.h"
using namespace std;

void ALGraph::FindKeyPath(ALGraph G)
{
	vector<int> topo;
	int ve[Maxsize];//事件最早发生时间（从源点开始，根据入边计算取最大值，正向）
	int vl[Maxsize];//事件最晚发生时间（从终点开始，按照逆拓扑排序，
	int ee;//活动最早开始时间
	int el;//活动最晚开始时间
	topo = G.TopSort(G);//首先将拓扑排序结果保存在容器中
	//test
	/*for (vector<int>::iterator it = topo.begin(); it != topo.end(); it++)
	{
		cout << (*it) << " ";
	}*/
	//初始化事件的最早发生时间
	for (int i = 0; i < G.vertexNum; i++)
	{
		ve[i] = 0;
	}
	int j,k;
	//计算事件最早发生时间
	for (vector<int>::iterator it = topo.begin(); it != topo.end(); it++) 
	{
		k = (*it);         //取出拓扑序列的顶点
		ArcNode* p = G.adjlist[k].firstedge;
		while (p != NULL)
		{
			j = p->adjvex;  
			if (ve[k] + p->weight > ve[j])      
			{
				ve[j] = ve[k] + p->weight;     //更新顶点j的最早发生时间
			}
			p = p->next;
		}
	}
	//test
	/*for (int i = 0; i < G.vertexNum; i++)
	{
		cout << ve[i] << " ";
	}*/
	//计算事件的最迟发生时间  
	for (int i = 0; i < G.vertexNum; i++)
	{
		vl[i] = ve[G.vertexNum-1];        //将每个事件的最迟发生时间初始化为汇点的最早发生时间
	}
	for (vector<int>::reverse_iterator it = topo.rbegin(); it != topo.rend(); it++)
	{
		k = (*it);         //取出拓扑序列的顶点k
		ArcNode* p = G.adjlist[k].firstedge;
		//汇点的最迟发生时间就是其最早发生时间
		while (p != NULL)
		{
			j = p->adjvex;
			if (vl[k]>vl[j]-p->weight)
			{
				vl[k] = vl[j] - p->weight;     //更新顶点j的最迟发生时间
			}
			p = p->next;
		}
	}
	//test
	/*for (int i = 0; i < G.vertexNum; i++)
	{
		cout << vl[i] << " ";
	}*/

	//判断每一次活动是否为关键活动
	cout << "关键活动路径为：";
	for (int i = 0; i < G.vertexNum; i++)
	{
		ArcNode* p = G.adjlist[i].firstedge;
		while (p != NULL)
		{
			j = p->adjvex;
			ee = ve[i];
			el = vl[j] - p->weight;
			if (ee == el)
				cout << G.adjlist[i].vertex << "->" << G.adjlist[j].vertex << " ";
			p = p->next;
		}
	}
	cout << endl;
	cout << "最长路径长度为：" << ve[G.vertexNum - 1];
}

void test()
{
	string v[9] = { "V0","V1","V2","V3","V4","V5","V6","V7","V8" };
	int b[11] = { 0,1,1,1,2,1,1,1,2 };
	ALGraph AL(v, b, 9, 11);
	AL.FindKeyPath(AL);
}

int main()
{
	test();
	system("pause");
	return 0;
}