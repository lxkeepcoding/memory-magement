//#include<iostream>
//using namespace std;
//
//void f2()
//{
//	int b = 0;
//	cout <<"b:"<< &b << endl;
//	cout << endl;
//	cout << endl;
//}
//
//void f1()
//{
//	int a = 0;
//	cout<<"a:" << &a << endl;
//	cout << endl;
//	cout << endl;
//	f2();
//}
//
//int main()
//{
//	f1();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	for (int i = 0; i < 3; i++)
//	{
//		int *p1 = (int *)malloc(4);
//		int *p2 = (int *)malloc(4);
//		cout << "p1:" << p1 << endl << endl << endl;
//		cout << "p2:" << p2 << endl << endl << endl;
//		free(p1);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//private:
//	int _data;
//};
//void Test2()
//{
//	// 申请单个Test类型的空间
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	
//	// 申请10个Test类型的空间
//	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
//	free(p2);
//}
//void Test3()
//{
//	// 申请单个Test类型的对象
//	Test* p1 = new Test;
//	// 申请10个Test类型的对象
//	Test* p2 = new Test[10];
//	delete p1;
//	delete[] p2;
//}
//
//int main()
//{
//	Test2();
//	Test3();
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//
//struct ListNode
//{
//	ListNode *_next;
//	ListNode *_prev;
//	int _val;
//	ListNode(int val = 0)
//		:_next(nullptr), _prev(nullptr), _val(val)
//	{}
//	~ListNode()
//	{
//		cout << "ListNode 析构" << endl;
//	}
//};
//int main()
//{
//	//C
//	struct ListNode *n1 = (struct ListNode *)malloc(sizeof(struct ListNode));
//	free(n1);
//	//C++
//	ListNode *n2 = new ListNode;
//	delete n2;
//	return 0;
//}
//


//
//#include<iostream>
//using namespace std;
//
//struct ListNode
//{
//	ListNode *_next;
//	ListNode *_prev;
//	int _val;
//	ListNode(int val = 0)
//		:_next(nullptr), _prev(nullptr), _val(val)
//	{}
//	~ListNode()
//	{
//		cout << "ListNode 析构" << endl;
//	}
//};
//int main()
//{
//	struct ListNode *n1 = (struct ListNode *)malloc(sizeof(struct ListNode));
//	free(n1);
//	struct ListNode *n2 = (struct ListNode *)operator new(sizeof(struct ListNode));
//	operator delete (n2);
//	void *p3 = malloc(0x7fffffff);
//	if (p3 == NULL)
//	{
//		cout << "malloc fail" << endl;
//	}
//	try
//	{
//		void *p4 = operator new(0x7fffffff);
//	}
//	catch (exception &e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}
//



//#include<iostream>
//using namespace std;
//
//struct ListNode
//{
//	ListNode *_next;
//	ListNode *_prev;
//	int _val;
//	//类中专属的重载
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1);
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//	ListNode(int val = 0)
//		:_next(nullptr), _prev(nullptr), _val(val)
//	{}
//	~ListNode()
//	{
//		cout << "ListNode 析构" << endl;
//	}
//};
//
//int main()
//{
//	ListNode* p = new ListNode(1);
//	delete p;
//
//}

//#include<iostream>
//using namespace std;
//
//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//private:
//	int _data;
//};
//void test()
//{
//	    // pt现在指向的只不过是与Test对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//    Test *pt = (Test*)malloc(sizeof(Test));
//	new(pt)Test; // 注意：如果Test类的构造函数有参数时，此处需要传参
//}

//
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A:" << _a<< endl;
//	}
//	~A()
//	{
//		cout << "~A:析构"  << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A*p = (A*)malloc(sizeof(A));
//	new(p)A;//显示调用构造函数
//	cout << endl;
//	new(p)A(3);//显示调用构造函数并赋予初始化的值
//	return 0;
//}