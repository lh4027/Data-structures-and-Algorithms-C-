//#include<iostream>
//using namespace std;
//
//enum flag {Child,Thread};  //枚举类型，枚举常量Child=0,Thread=1
//template<class T>
//class ThrNode
//{
//public:
//	T data;
//	ThrNode<T>* lchild, * rchild;
//	bool ltag=0, rtag=0;
//};
//
//template<class T>
//class InThrBiTree
//{
//public:
//	InThrBiTree();//中序线索链表构造函数
//	~InThrBiTree();
//	ThrNode<T>* Next(ThrNode<T>* p);//查找结点p的后继
//	void InOrder();  //中序遍历线索链表
//
//
//	ThrNode<T>* Create(ThrNode<T>* bt);//构造函数调用
//	void ThrBiTree(ThrNode<T>* bt, ThrNode<T>* pre);
//
//	ThrNode<T>* root;   //指向线索链表的头指针
//
//	
//};
//
//template<class T>
//ThrNode<T>* InThrBiTree<T>::Create(ThrNode<T>* bt)
//{
//	T ch;
//	cin >> ch;
//	if (ch == '#')
//	{
//		bt = NULL;
//	}
//	else
//	{
//		bt = new ThrNode<T>;  //开辟一个新结点
//		bt->data = ch;       //赋数据
//		bt->ltag = 0; bt->rtag = 0;//左右标志均置0
//		bt->lchild = Create(bt->lchild);  //递归建立左子树
//		bt->rchild = Create(bt->rchild);  //递归建立右子树
//		//这里bt是地址，bt指向左子树和右子树的地址，*Create返回bt地址
//	}
//	return bt;
//}
//
//template<class T>
//InThrBiTree<T>::InThrBiTree()
//{
//	root = Create(root); //建立带线索的二叉链表
//	ThrNode<T> *pre = NULL;//当前访问节点的前驱节点pre初始化为NULL
//	ThrBiTree(root, pre);//遍历二叉链表，建立线索
//
//}
//
//template<class T>
//void InThrBiTree<T>::ThrBiTree(ThrNode<T>* bt, ThrNode<T>* pre)
//{
//	if (bt == NULL)
//		return;
//	
//	ThrBiTree(bt->lchild, pre);//对bt的左子树建立线索
//	if (bt->lchild == NULL)   //如果当前结点的左子树为空
//	{
//		bt->ltag = 1;         //左标志置为1
//		bt->lchild = pre;     //当前结点的左子树指针指向前驱结点
//	}
//	if (bt->rchild == NULL) //如果当前结点的右子树为空
//		bt->rtag = 1;       //右标志置1，由于要指向的后继结点还未访问到，暂时不建立线索，等到下次
//	if (pre->rtag == 1)     //如果前驱结点右标志为1
//		pre->rchild = bt;    //pre结点指向后继结点，也就是当前bt结点
//
//	pre = bt;              //更新前驱结点pre
//	ThrBiTree(bt->rchild, pre);//对bt的右子树建立线索
//}
//
//
//template<class T>
//ThrNode<T>* InThrBiTree<T>::Next(ThrNode<T>* p)
//{
//	ThrNode<T>* q;
//	if (p->rtag == 1)
//	{
//		q = p->rchild;
//	}
//	else
//	{
//		q = p->rchild;
//		while (q->rtag == 0)
//		{
//			q = q->lchild;
//		}
//	}
//	return q;
//}
//
//template<class T>
//void InThrBiTree<T>::InOrder()
//{
//	ThrNode<T>* p;
//	if (root = NULL)
//	{
//		return;
//	}
//	p = root;
//	while (p->ltag == 0)
//	{
//		p = p->lchild;
//	}
//	cout << p->data << " ";
//	while (p->rchild != NULL)
//	{
//		p = Next(p);
//		cout << p->data << " ";
//	}
//}
//
//
//
//
//int main()
//{
//	InThrBiTree<string> InBitree;
//	InBitree.InOrder();
//
//	system("pause");
//
//}