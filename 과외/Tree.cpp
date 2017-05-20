#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
class MyNode
{
	using Type = int;

public:
	T m_iData;

	MyNode* next;
	MyNode* before;
	MyNode(const T& iData = 0) : m_iData(iData), next(nullptr), before(nullptr)
	{
	}
	~MyNode()
	{
		next = nullptr;
		before = nullptr;
	}

};

template<class T>
class MyList
{
	using Node = MyNode<T>;

	Node *head;
	Node *tail;

	int m_iSize;

public:

	MyList(const int& iSize = 0) : m_iSize(iSize), head(nullptr), tail(nullptr)
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
		head->next = tail;
		tail->next = nullptr;
		head->before = nullptr;
		tail->before = head;
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

	void insert(const T& tNum)
	{
		//1단계 - 마지막 노드를 찾는다.
		Node* pivot = tail->before;

		//2단계 - 새로 연결할 노드를 만든다.
		Node* node = new Node(tNum);

		//3단계 - 1단계에서 찾은 pivot 뒤에 넣어줘야 된다.
		tail->before = node;
		node->next = tail;
		node->before = pivot;
		pivot->next = node;
		++m_iSize;

	}

	void swap(Node* L, Node* R)
	{
		if ((L->next == R) && (R->before == L))
		{
			L->before->next = R;
			R->next->before = L;
			R->before = L->before;
			R->next->before = L;
			L->before = R;
			L->next = R->next;
			R->next = L;

			return;
		}

		if ((R->next == L) && (L->before == R))
		{
			R->before->next = L;
			L->next->before = R;
			L->before = R->before;
			L->next->before = R;
			R->before = L;
			R->next = L->next;
			L->next = R;

			return;
		}

		Node* L_next = L->next;
		Node* L_before = L->before;

		R->next->before = L;
		L->before->next = R;

		L->next->before = R;
		R->before->next = L;

		L->next = R->next;
		R->next = L_next;

		L->before = R->before;
		R->before = L_before;

	}

	void change(const T& left_vaule, const T& right_vaule)
	{
		auto left = find(left_vaule);
		auto right = find(right_vaule);

		if (left == nullptr) return;
		if (right == nullptr)return;

		MyList::swap(left, right);

	}

	Node* find(const T& find_vaule)
	{
		Node* curr = head->next;
		while (curr->next != nullptr)
		{
			if (curr->m_iData == find_vaule)
				return curr;
			curr = curr->next;
		}
		return nullptr;
	}

	void sort()
	{
		bool swapped;
		Node* pivot = head;
		Node* leftElement = pivot->next;
		Node* rightElement = leftElement->next;

		do
		{
			swapped = false;
			if (rightElement == tail)
			{
				leftElement = pivot->next;
				rightElement = leftElement->next;
			}

			while (rightElement != tail)
			{

				if (leftElement->m_iData > rightElement->m_iData)
				{
					swap(leftElement, rightElement);
					swapped = true;
				}

				rightElement = rightElement->next;
				leftElement = leftElement->next;
			}


		} while (swapped);

	}

	const int size()const
	{
		return m_iSize;
	}

	Node* find_index(const int& index)
	{
		Node* new_Node = head;
		
		for (int i = 0; i < index; ++i)
		{
			new_Node = new_Node->next;
		}
		return new_Node;
	}
};

constexpr int my_pow(const int& n, const int& d)
{
	return d >= 0 ? n * pow(n, d - 1) : 1;
}
constexpr int my_factorial(const int& n)
{
	//return d >= 0 ? n * pow(n, d - 1) : 1;
	return 0;
}
int factorial(const int& n)
{
	int vaule = 1;
	for (int i = 1; i <= n; ++i) vaule *= i;
	return vaule;
}

constexpr int sum(const int& n){ return n >= 0 ? n + sum(n - 1) : 0; }

//template<typename T>
class Node
{
	using T = int;

public:
	T m_tData;
	Node* m_nRight;
	Node* m_nLeft;
	int m_iChildCount;
	bool m_bEmtpy;

	Node(const T& tData = 0, Node* nRight = nullptr, Node* nLeft = nullptr, const bool& Emtpy = true)
		:m_tData(tData), m_nRight(nRight), m_nLeft(nLeft), m_iChildCount(0), m_bEmtpy(Emtpy)
	{
			
	}

	~Node() //: m_tData(0), m_nRight(nullptr), m_nLeft(nullptr)
	{
		m_tData = 0;
		m_nRight = nullptr;
		m_nLeft = nullptr;
	}
};

class My_Tree 
{
	using MyNode = Node;

	using T = int;
	int iNum;
	Node* nRoot;
	MyList<int> m_Input;

public:
	Node* m_nBranch;

	My_Tree(Node* nBranch = nullptr)
		:m_nBranch(nBranch)
	{
		nRoot = nullptr;
	}
	
	~My_Tree()
	{
		
	}

	void init()
	{
		if (nRoot == nullptr)
		{
			nRoot = new Node;
			iNum = 1;
		}
		//my_insert(nRoot, 1);
		m_Input.init();
	}

	void my_insert(const T& tData)
	{
		m_Input.insert(tData);
	}

	void insert(Node* parent, const T& tData)
	{
		m_nBranch = parent;
		m_nBranch->m_iChildCount++;

		while (true)
		{
			if (m_nBranch->m_nLeft == nullptr)
			{
				m_nBranch->m_nLeft = new Node;
				m_nBranch->m_nLeft->m_tData = tData; 
			}

			else if (m_nBranch->m_nRight == nullptr)
			{
				m_nBranch->m_nRight = new Node;
				m_nBranch->m_nRight->m_tData = tData;
			}

			else if ((m_nBranch->m_nLeft != nullptr) && (m_nBranch->m_nRight == nullptr))
			{
				insert(m_nBranch->m_nLeft, tData);
			}
		}
	}
	
	bool my_remove(MyNode* parent, const T& tData)
	{
		if (parent->m_nLeft->m_tData == tData)
		{
			parent->m_tData = -1;
			parent->m_bEmtpy = false;				
			return true;

		}

		if (parent->m_nRight->m_tData == tData)
		{
			parent->m_tData = -1;
			parent->m_bEmtpy = false;
			return true;
		}

		if (parent->m_nLeft->m_iChildCount > parent->m_nRight->m_iChildCount)
			return my_remove(parent->m_nRight, tData);
		else
			return my_remove(parent->m_nLeft, tData);
	}
	
	bool my_remove(const T& tData)
	{
		return my_remove(nRoot, tData);
	}
	
	void clear()
	{
		nRoot;
	}

	void my_sort()
	{
		m_Input.sort();	//bubble
		my_sort(0, m_Input.size(), 0, m_Input.size());
	}

	void my_sort(const int& start_index, const int& end_index, int level, const int& all_size)
	{
		auto start_node = m_Input.find_index(start_index);
		auto end_node = m_Input.find_index(end_index);
		auto center_node = static_cast<int>((start_index + end_index) / 2);
		auto satrt_node_distance= end_index - start_index;
		my_sort(1, 2, ++level, all_size);
	}

	void sort()
	{
		m_Input.sort();

		int size = m_Input.size() / 2;
		int left = m_Input.size() / 2;
		int right = m_Input.size() / 2;

		//Node* smaller = m_Input.find_index(size);
		//Node* bigger = m_Input.find_index(size);
		//nRoot = smaller;
		//left = left / 2;
		//smaller = m_Input.find_index(left);
		//
		//right = left + size;
		//bigger = m_Input.find_index(right);

	}

private:

	bool my_insert(MyNode* parent, const T& tData)
	{
		parent->m_iChildCount++;

		if (parent->m_nLeft == nullptr)
		{
			MyNode* new_node = new MyNode(tData);
			parent->m_nLeft = new_node;
			return true;
		}

		if (parent->m_nRight == nullptr)
		{
			MyNode* new_node = new MyNode(tData);
			parent->m_nRight = new_node;
			return true;
		}

		if (parent->m_nLeft->m_iChildCount > parent->m_nRight->m_iChildCount)
			return my_insert(parent->m_nRight, tData);
		else
			return my_insert(parent->m_nLeft, tData);

		return false;
	}

};

#include <fstream>
int main()
{
	//cout << sum(5) << endl;
	std::ifstream ifs("read.csv", std::ios::binary);

	std::vector<char> v;
	char c;
	while (!ifs.eof())
	{
		ifs >> c;
		//cout << c;
		if (c == ',' || c== ' ')
		{
			continue;
		}
		v.push_back(c);
	}

	ifs.close();
	
	std::ofstream ofs("save_csv.txt", std::ios::binary);
	for (auto& d : v)
		ofs << d;
	ofs.close();

	return 0;
}																		