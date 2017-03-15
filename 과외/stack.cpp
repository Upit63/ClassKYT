#include <iostream>

/*
	Statck = 마트에서 카트뺴기
	 Queue = 줄 서기
*/
using namespace std;


template <class T>
class MyNode
{
public:
	std::string name;
	MyNode* m_next;
	MyNode* m_prev;
	T m_tData;
	MyNode(const T& tData = 0) : m_tData(tData), m_next(nullptr) , m_prev(nullptr)
	{
		//std::cout << "MyNode T: " << typeid(T).name <<std::endl;
	}
	~MyNode() { m_next = nullptr, m_prev = nullptr; }
};

template<class T>
class MyList
{
	using Node = MyNode<T>;

	Node *head;
	Node *tail;

	T m_tData;

public:

	MyList(const T& tData = 0,const int & iSize=0)
		: m_tData(tData), head(nullptr), tail(nullptr)
	{

	}

	~MyList()
	{
		if (head != nullptr)delete head;
		head = nullptr;

		if (tail != nullptr)delete tail;
		tail = nullptr;
	}

	void init()
	{
		head = new Node();
		tail = new Node();

		head->name = "head";
		tail->name = "tail";


		head->m_next = tail;
		head->m_prev = tail;

		tail->m_next = head;;
		tail->m_prev = head;

	}

	void release()
	{
		if (head)
		{
			delete head;
			head = nullptr;
		}

		if (tail != nullptr)
		{
			delete tail;
			tail = nullptr;
		}
	}

	void insert(const T& tData)
	{
		Node* new_node = new Node(tData);
		auto pivot = tail->m_prev;

		pivot->m_next = new_node;

		new_node->m_next = tail;
		tail->m_prev = new_node;

		new_node->m_prev = pivot;


	}

	void insert(const T& tData,const int & iSize)
	{
		Node* node = new Node(tData);
		auto front = head->m_next;

		for (int i = 0; i < iSize; ++i)
		{
			front = front->m_next;
		}

		front = node;
		front->m_next = tail;

	}

	//전체
	//void show()
	//{
	//	int iNum = 1;
	//	Node* pivot = head;
	//	cout << typeid(T).name() << endl;
	//	while (pivot->m_next != tail)
	//	{
	//		std::cout << iNum << ". ";
	//		pivot->m_next->show();
	//		std::cout << "\n";
	//		pivot = pivot->m_next;
	//		++iNum;
	//	}

	//std::cout << "num : " << iNum << std::endl;
	//}

	//void swap(Node* L, Node* R)
	//{
	//	if ((L->m_next == R) && (R->before == L))
	//	{
	//		L->before->m_next = R;
	//		R->m_next->before = L;
	//		R->before = L->before;
	//		R->m_next->before = L;
	//		L->before = R;
	//		L->m_next = R->m_next;
	//		R->m_next = L;
	//
	//		return;
	//	}
	//
	//	if ((R->m_next == L) && (L->before == R))
	//	{
	//		R->before->m_next = L;
	//		L->m_next->before = R;
	//		L->before = R->before;
	//		L->m_next->before = R;
	//		R->before = L;
	//		R->m_next = L->m_next;
	//		L->m_next = R;
	//
	//		return;
	//	}
	//
	//	Node* L_m_next = L->m_next;
	//	Node* L_before = L->before;
	//
	//	R->m_next->before = L;
	//	L->before->m_next = R;
	//
	//	L->m_next->before = R;
	//	R->before->m_next = L;
	//
	//	L->m_next = R->m_next;
	//	R->m_next = L_m_next;
	//
	//	L->before = R->before;
	//	R->before = L_before;
	//
	//
	//	/*while (current->m_next != nullptr)
	//	{
	//	if ((left != nullptr) && (right != nullptr))
	//	{
	//	left->before->before->m_next = left->before;
	//	left->m_next = right->m_next;
	//	left->before->m_next = right;
	//	right->m_next = left;
	//
	//	}
	//
	//	else if (current->m_next->m_iData == iNumleft)
	//	{
	//	left = current->m_next;
	//	current = current->m_next;
	//	}
	//
	//	else if (current->m_next->m_iData == iNumright)
	//	{
	//	right = current->m_next;
	//	current = current->m_next;
	//	}
	//
	//	else
	//	current = current->m_next;
	//	}
	//	*/
	//
	//}

	//void remove(const T& tNum)
	//{
	//	Node* current = head;
	//	Node* before = nullptr;
	//
	//	//Node* current = head;
	//	//Node* before = nullptr;
	//
	//	while (current->m_next != nullptr)
	//	{
	//
	//		if (current->m_next->m_iData == tNum)
	//		{
	//			if (current->m_next->m_next == nullptr)
	//			{
	//				delete current->m_next;
	//				current->m_next = nullptr;
	//
	//				break;
	//			}
	//			else
	//			{
	//				before = current;
	//				current = current->m_next;
	//				auto pNode = current->m_next;
	//				delete before->m_next;
	//				before->m_next = nullptr;
	//				before->m_next = pNode;
	//				current = pNode;
	//				//current->m_next = nullptr;
	//			}
	//		}
	//
	//		else
	//		{
	//			before = current;
	//			current = current->m_next;
	//
	//		}
	//	}
	//
	//}

	T& front()
	{
		return head->m_next->m_tData;
	}

	void remove()
	{
		auto front = head->m_next;
		head->m_next = head->m_next->m_next;
		delete front;
	}

};

template <class T>
class CMyStack
{
public:
	size_t m_uSize;
	T arr[10000];
	size_t m_uTop;
	

	CMyStack()
	{
		
	}
	~CMyStack()
	{

	}
	void push(const T& tEnter)
	{
		arr[m_uTop] = tEnter;
		++m_uSize;
		++m_uTop;
	}
	T pop()
	{
		return arr[--m_uTop];
	}
};

template<class T>
class CMyQueue
{
public:
	CMyQueue() : m_iSize(0)
	{

	}
	~CMyQueue()
	{

	}

	void push(T input)
	{
		++m_iSize;
		m_List.insert(input);
	}
	void pop()
	{		
		--m_iSize;
		m_List.remove();
	}

	T& front() { return m_List.front(); }

	void init()
	{
		m_List.init();
	}

	void release()
	{
		m_List.release();
	}

	using Type = T;
	int m_iSize;
	MyList <T> m_List;
};

template<class T>
class YTStack
{
	using Type = int;

public:
	Type data[100000];
	int top;

	YTStack()
	{
		top = -1;
		memset(data, 0, sizeof(data));
	}

	bool insert(const Type& n)
	{
		if (top >= 100000)
			return false;

		data[++top] = n;
		return true;
	}

	Type pop()
	{
		if (empty())
			return -1;

		return data[top--];
	}

	
	bool empty()
	{
		return (top == -1);
	}

};

template<class T>
class YTQueue
{
	using Type = int;

public:
	Type data[100000];
	int front;
	int rear;

	YTQueue() : front(0), rear(0)
	{
		memset(data, 0, sizeof(data));
	}

	bool insert(const Type& n)
	{
		if (front >= 100000) front = 0;
		data[front++] = n;
		return true;
	}

	Type pop()
	{
		if (rear >= 100000) rear = 0;
		return data[rear++];
	}


	bool empty()
	{
		return (top == rear);
	}

};

int main()
{

	CMyQueue<int> q;

	q.init();

	for (int i = 1; i < 10; ++i)
	{
		q.push(i);
	}


	for (int i = 0; i < 5; ++i)
	{
		std::cout << q.front() << std::endl;;
		q.pop();
	}

	cout << "Size : " << q.m_iSize << endl;
	
	q.release();

	return 0;
}
