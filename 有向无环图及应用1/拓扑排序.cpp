#include<iostream>
#include<vector>
#include"ALGraph.h"
using namespace std;

ALGraph::ALGraph(string a[],int b[], int n, int e)
{
	this->vertexNum = n;
	this->arcNum = e;
	for (int i = 0; i < this->vertexNum; i++)
	{
		this->adjlist[i].vertex = a[i];
		this->adjlist[i].firstedge = NULL;
		this->adjlist[i].in = b[i];
	}
	//依次输入边
	
	int i1, i2,w;
	for (int i = 0; i < this->arcNum; i++)
	{
		cout << "输入一条边所依附的两个顶点编号：" << endl;
		cin >> i1 >> i2;
		cout << "请输入边的权值：" << endl;
		cin >> w;
		ArcNode* s = new ArcNode;
		s->weight = w;
		s->adjvex = i2;
		s->next = this->adjlist[i1].firstedge;
		this->adjlist[i1].firstedge = s;
	}

}
//拓扑排序算法，时间复杂度为O(n+e)
vector<int> ALGraph::TopSort(ALGraph G)
{
	vector<int> vec;
	//栈s初始化，累加器初始化
	int top = -1, count = 0;
	int S[Maxsize];
	int j,k;
	//扫描顶点表，将入度为0的顶点入栈
	for (int i = 0; i < G.vertexNum; i++)
	{ 
		if (G.adjlist[i].in == 0)
		{
			S[++top]=i;
		}
	}
	//当栈非空时循环
	while (top != -1)
	{
		//栈顶元素出栈，输出顶点，count自加
		j = S[top--];
		cout << G.adjlist[j].vertex;
		vec.push_back(j);
		count++;
		
		//对顶点j的每一个邻接点k执行下面操作
		ArcNode* p = G.adjlist[j].firstedge;
		while (p != NULL)//扫描顶点表，找出顶点j 的所有出边
		{
			k = p->adjvex;
			G.adjlist[k].in--; //入度减一
			if (G.adjlist[k].in == 0) //如果入度为0
			{
				S[++top] = k;   //顶点入栈
			}
			p = p->next;
		}
	}
	if (count < G.vertexNum)
	{
		cout << "有回路！" << endl;
		return ;
	}
		
	return vec;

}


//int main()
//{
//	string v[6] = { "A","B","C","D","E","F" };
//	int b[6] = { 3,0,1,3,0,2 };
//	ALGraph AL(v, b, 6, 9);
//	AL.TopSort(AL);
//	system("pause");
//	return 0;
//}