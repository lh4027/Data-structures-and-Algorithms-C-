//#include<iostream>
//using namespace std;
//
//template <class T>
//class BiNode
//{
//public:
//	T data;
//	BiNode <T>* lchild=NULL, * rchild=NULL;
//};
//
//
//template <class T>
//class BiTree
//{
//public:
//	BiTree()
//	{
//		root = NULL;
//		root = Create(root);
//	}
//
//	~BiTree()
//	{
//		Release(root);
//	}
//	
//	void PreOrder()
//	{
//		PreOrder(root);
//	}
//
//	void InOrder()
//	{
//		InOrder(root);
//	}
//
//	void PostOrder()
//	{
//		PostOrder(root);
//	}
//	层序遍历
//	void LeverOrder();
//	
//	
//
//private:
//	BiNode<T> * root;
//	
//	
//
//	二叉树构造函数
//	BiNode<T>* Create(BiNode<T>* bt);
//	二叉树析构函数
//	void Release(BiNode<T>* bt);
//
//	void PreOrder(BiNode<T>* bt);
//	二叉树中序遍历
//	void InOrder(BiNode<T>* bt);
//	二叉树后序遍历
//	void PostOrder(BiNode<T>* bt);
//	
//};
//
//template <class T>
//BiNode<T>* BiTree<T>::Create(BiNode<T>* bt)  //约定用户按照前序遍历方式输入数据，若无数据则输入#代替
//{
//	T ch;
//	cin >> ch;
//	if (ch == '#')
//	{
//		bt = NULL;	
//	}
//	else
//	{ 
//		bt = new BiNode<T>;  //开辟一个新结点
//		bt->data = ch;       //赋数据
//		bt->lchild = Create(bt->lchild);  //递归建立左子树
//		bt->rchild = Create(bt->rchild);  //递归建立右子树
//		这里bt是地址，bt指向左子树和右子树的地址，*Create返回bt地址
//	}
//	return bt;
//}
//
//采用后序遍历释放结点
//template <class T>
//void BiTree<T>::Release(BiNode<T>* bt)
//{
//	if (bt != NULL)
//	{
//		Release(bt->lchild);
//		Release(bt->rchild);
//		delete bt;
//	}
//}
//
//二叉树前序遍历
//template <class T>
//void BiTree<T>::PreOrder(BiNode<T>* bt)
//{
//	if (bt != NULL)
//	{
//		cout << bt->data << " ";
//		PreOrder(bt->lchild);
//		PreOrder(bt->rchild);
//	}
//	else
//	{
//		return;
//	}
//}
//
//
//二叉树中序遍历
//template <class T>
//void BiTree<T>::InOrder(BiNode<T>* bt)
//{
//	if (bt != NULL)
//	{
//		InOrder(bt->lchild);
//		cout << bt->data << " ";
//		InOrder(bt->rchild);
//	}
//	else
//	{
//		return;
//	}
//}
//
//二叉树后序遍历
//template <class T>
//void BiTree<T>::PostOrder(BiNode<T>* bt)
//{
//	if (bt != NULL)
//	{
//		PostOrder(bt->lchild);
//		PostOrder(bt->rchild);
//		cout << bt->data << " ";
//	}
//	else
//	{
//		return;
//	}
//}
//
//二叉树层序遍历:先将根节点入队，再出队访问其左右子树，若左右子树不为空则将其入队，
//再顺序出队在访问其左右子树，以此循环
//template <class T>
//void BiTree<T>::LeverOrder()
//{
//	int front = -1;
//	int rear = -1;  //队列头尾指针
//	 创建一个队列	
//	BiNode<T>* Q[100]; 
//	BiNode<T>* q;     //创建一个q指针用于接收结点指针
//
//	         
//	if (root != NULL)
//	{
//		Q[++rear] = root;    //头结点先入队
//	}
//	else return;
//	while (front != rear)
//	{
//		q = Q[++front];     //结点出队
//		cout << q->data<<" ";    
//		if (q->lchild != NULL)
//		{
//			Q[++rear] = q->lchild;      //左子树结点入队
//		}
//		if (q->rchild != NULL)
//		{
//			Q[++rear] = q->rchild; //右子树结点入队
//		}
//	}
//}
//
//
//void test01()
//{
//	BiTree<char> BT;
//	cout << "前序遍历：";
//	BT.PreOrder();
//	cout << endl;
//	cout << "中序遍历：";
//	BT.InOrder();
//	cout << endl;
//	cout << "后序遍历：";
//	BT.PostOrder();
//	cout << endl;
//	cout << "层序遍历：";
//	BT.LeverOrder();
//	cout << endl;
//	
//}
//
//int main()
//{
//	test01();
//	system("pause");
//}