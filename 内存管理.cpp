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
//	// ���뵥��Test���͵Ŀռ�
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	
//	// ����10��Test���͵Ŀռ�
//	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
//	free(p2);
//}
//void Test3()
//{
//	// ���뵥��Test���͵Ķ���
//	Test* p1 = new Test;
//	// ����10��Test���͵Ķ���
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
//		cout << "ListNode ����" << endl;
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
//		cout << "ListNode ����" << endl;
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
//	//����ר��������
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
//		cout << "ListNode ����" << endl;
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
//	    // pt����ָ���ֻ��������Test������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
//    Test *pt = (Test*)malloc(sizeof(Test));
//	new(pt)Test; // ע�⣺���Test��Ĺ��캯���в���ʱ���˴���Ҫ����
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
//		cout << "~A:����"  << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A*p = (A*)malloc(sizeof(A));
//	new(p)A;//��ʾ���ù��캯��
//	cout << endl;
//	new(p)A(3);//��ʾ���ù��캯���������ʼ����ֵ
//	return 0;
//}