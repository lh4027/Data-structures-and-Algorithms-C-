//#pragma once
//enum kind{Active,Empty,Deleted};
//
//#define Maxsize (int)20 
//class HashTable
//{
//public:
//
//	void CreatHT(int a[],int n);  //创建一个哈希表
//	void Insert(int k);   //哈希表插入算法
//	void Delete(int k);//哈希表删除算法
//	int HashSearch(int value);  //哈希表查找算法
//
//	
//	HashTable(int size,int d,int m)
//	{
//		info = new kind[size];  
//		ht = new int[size];
//		Compare_Num = new int[size];
//		divitor = d;
//		this->m = m;
//
//		for (int i = 0; i < Maxsize; i++)
//		{
//			info[i] = Empty;
//			ht[i] = 0;
//			Compare_Num[i] = 0;
//		}
//	}
//	~HashTable()
//	{
//		delete[] info;
//		delete[] ht;
//		delete[] Compare_Num;
//	}
//
//private:
//	kind *info;      //记录哈希表每个位置状态的数组
//	int *ht;         //哈希表
//	int *Compare_Num; //记录比较次数的数组
//	int divitor;//k%divitor,除数留余法取余系数
//	int m;//探测的起始下标，一般为哈希表长度
//};
