//#include<iostream>
//#include"Hash.h"
//using namespace std;
//
//
///**************************************************/
///*名称：开散列表*/
//
//void HashTable::CreatHT(int a[],int n)
//{
//
//	for (int i = 0; i < n; i++)
//	{
//		Insert(a[i]);
//	}
//	//test
//	for (int i = 0; i < Maxsize; i++)
//		cout << ht[i] << " ";
//	cout << endl;
//	for (int i = 0; i < Maxsize; i++)
//		cout << info[i] << " ";
//	cout << endl;
//}
//
//void HashTable::Insert(int k)
//{
//	int i, j;
//	j = k % divitor;
//
//	if (info[j] !=Active)
//	{
//		ht[j] = k; info[j] = Active;
//	}	
//	else
//	{
//		i = (j + 1) % m;
//		do
//		{
//			if (info[i] != Active)
//			{
//				ht[i] = k; info[i] = Active; break;
//			}
//			else
//				i = (i + 1) % m;
//		} while (i != j);
//	}
//	for (int i = 0; i < Maxsize; i++)
//		cout << ht[i] << " ";
//	cout << endl;
//	for (int i = 0; i < Maxsize; i++)
//		cout << info[i] << " ";
//	cout << endl;
//}
//void HashTable::Delete(int k)
//{
//	int i;
//	i = HashSearch(k);
//	if ( i!= false)
//	{
//		info[i] = Deleted;
//		ht[i] = 0;
//		cout << "删除成功！" << endl;
//	}
//	else
//		cout << "未找到，删除失败！" << endl;
//	//test
//	for (int i = 0; i < Maxsize; i++)
//		cout << ht[i] << " ";
//	cout << endl;
//	for (int i = 0; i < Maxsize; i++)
//		cout << info[i] << " ";
//	cout << endl;
//}
//
////散列表查找算法
///*           线性探测法               */
//int HashTable::HashSearch(int value)
//{
//	int i,j;
//	j = value % divitor;
//	if (ht[j] == value && info[j] == Active)
//	{
//		return j;
//	}	
//	else if (info[j] == Empty)
//	{
//		return false;
//	}
//	i = (j + 1) % m;
//	do
//	{
//		if (info[i] == Active && ht[i] == value)
//		{
//			return i;
//			break;
//		}
//		i = (i + 1) % m;
//		if (i == j)
//			return false;
//	} while (i != j);
//	
//}
//
////void test()
////{
////	HashTable HT(Maxsize, 11, Maxsize);
////	int a[9] = { 47,7,29,11,16,92,22,8,3 };
////	HT.CreatHT(a,9);
////	if (HT.HashSearch(92)!=false)
////	{
////		cout << "查找成功！" << " 位置：" << HT.HashSearch(92) << endl;
////	}
////	else
////		cout << "查找失败！" << endl;
////	cout << endl;
////	HT.Delete(92);
////	cout << endl;
////}
////
////int main()
////{
////	test();
////	system("pause");
////	return 0;
////}