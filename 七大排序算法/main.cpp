#include<iostream>
using namespace std;


//直接插入排序算法(时间复杂度为O(n^2)稳定的排序)
void StraightInsertSort(int r[], int n)
{
	int i, j;
	for ( i = 2; i <= n; i++)
	{
		r[0] = r[i];                        //0号单元用作暂存单元和监视岗
		for ( j = i - 1; r[0] < r[j]; j--)  //寻找插入位置
			r[j + 1] = r[j];                //记录后移
		r[j+1] = r[0];
	}
}

//希尔排序(对直接插入排序的改进，时间复杂度在O(n^2)和O(log2(n))之间，是不稳定的排序
void ShellSort(int r[], int n)
{
	int i, j, d;
	for (d = n / 2; d >= 1; d = d / 2)  //以增量为d进行区间的插入排序
	{
		for (i = d + 1; i <= n; i++)
		{
			r[0] = r[i];
			for (j = i - d; j > 0 && r[0] < r[j]; j = j - d)
				r[j + d] = r[j];
			r[j + d] = r[0];
		}
	}
}

//冒泡法排序(时间复杂度为O(n^2)稳定的排序)
void BubbleSort(int r[], int n)
{
	int i, j,temp;
	bool flag = true;
	i = n-1;
	while (i > 0 && flag)
	{
		flag = false;
		for (j = 0; j < i; j++)
		{
			if (r[j] > r[j + 1])
			{
				flag = true;
				temp = r[j + 1];
				r[j + 1] = r[j];
				r[j] = temp;
			}
		}
		i--;
	}
}

/*    快速排序算法(对冒泡算法的改进)  
/*    时间复杂度O(nlog2(n))
/*    不稳定的排序                      
*/
//快速排序一次划分算法
int Partition(int r[], int first,int end)  
{
	int temp;
	int i = first,j = end,pivot=r[first];
	while (i < j)
	{
		while (i < j && r[j]>=pivot)  //左侧扫描
			j--;
		if (i < j)
		{
			swap(r[i], r[j]);    //将较小记录交换到前面
			i++;
		}

		while (i < j && r[i] <= pivot)
			i++;
		if (i < j)
		{
			swap(r[i], r[j]);//将较大记录交换到后面
			j--;
		}
	}
	return i;  //i为轴值记录的最终位置
}
void QuickSort(int r[], int first, int end)
{
	int pivot;
	if (first < end)
	{
		pivot = Partition(r, first, end);
		QuickSort(r, first, pivot-1);
		QuickSort(r, pivot + 1, end);
	}
}


/*     简单选择排序
/*     时间复杂度O(n^2)
/*     不稳定
*/ 
void SelectSort(int r[], int n)  
{
	int i, j, index;
	for (i = 0; i < n; i++)
	{
		index = i;
		for (j = i + 1; j < n; j++)
			if (r[j] < r[index])
				index = j;
		if (index != i)
			swap(r[i], r[index]);
	}
}

/*     堆排序算法
/*    时间复杂度O(nlog2(n))
/*    不稳定的排序  
*/
//筛选法调整堆
void Sift(int r[], int k, int n)//k为结点所在位置，n为序列大小
{
	int i = k, j = 2 * k;//i为根节点位置，j=2*k是i结点左孩子位置
	while (j <= n)   //如果有左孩子，k的左孩子为2*k,右孩子为2*k+1
	{
		if (j < n && r[j] < r[j + 1]) //如果有右孩子，且左孩子比右孩子小
			j++;//j指向右孩子
		if (r[i] > r[j]) //如果根节点大于左右孩子，以满足堆，跳出
			break;
		else
			swap(r[i], r[j]);//与较大的孩子交换
		i = j;  //i指向交换后新的位置，继续向下比较，一直下沉到叶子结点
		j = 2 * i;//更新j
	}
}
//堆排序
void HeapSort(int r[], int n)  //0号单元用作交换操作的暂存单元
{
	//初始建堆，从最后一个分支结点n/2到根节点
	for (int i = n / 2; i >= 1; i--)
		Sift(r, i, n);

	//排序，重复执行移走堆顶，再重建堆
	for (int i = 1; i < n; i++)
	{
		swap(r[1], r[n - i + 1]);
		Sift(r, 1, n - i);
	}
}

/*     归并排序递归算法
/*
/*
*/

void Merge(int r[], int low, int mid, int high)
{
	int* s = new int[high - low + 1];//申请一个辅助数组
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high)
	{
		if (r[i] <= r[j])   //按照从小到大顺序存放到辅助数组中
			s[k++] = r[i++];
		else
			s[k++] = r[j++];
	}
	while (i <= mid)
		s[k++] = r[i++];   //对子序列r[low:middle]剩余的依次处理
	while (j <= high)
		s[k++] = r[j++];   //对子序列r[middle+1:high]剩余的依次处理
	for (i = low, k = 0; i <= high; i++, k++)
		r[i] = s[k];      //将辅助数组转移到原始数组中
	delete[]s;//释放辅助数组
}
void MergeSort(int r[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(r, low, mid);
		MergeSort(r, mid + 1, high);
		Merge(r, low, mid, high);
	}
}

void test01()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	StraightInsertSort(a, 20);
	cout << "直接插入法排序结果：" << endl;
	for (int i = 1; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
void test02()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	ShellSort(a, 20);
	cout << "希尔排序结果：" << endl;
	for (int i = 1; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}

void test03()  
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	BubbleSort(a, 21);
	cout << "冒泡排序结果：" << endl;
	for (int i = 0; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
void test04()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	QuickSort(a, 0,20);
	cout << "快速排序结果：" << endl;
	for (int i = 0; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
void test05()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	SelectSort(a, 21);
	cout << "简单选择排序结果：" << endl;
	for (int i = 0; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
void test06()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	HeapSort(a,20);
	cout << "堆排序结果：" << endl;
	for (int i = 0; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
void test07()
{
	int a[21] = { 0,12,23,4,7,33,5,67,45,21,22,1,2,4,3,7,5,9,6,10,19 };
	MergeSort(a, 0, 20);
	cout << "归并递归排序结果：" << endl;
	for (int i = 0; i < 21; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	system("pause");
	return 0;

}