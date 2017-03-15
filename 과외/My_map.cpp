#include <iostream>
#include <string>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

std::map<string, string> m;

template <class Key, class Vaule>
class MyMapNode
{
public:
	Key first;
	Vaule second;
	MyMapNode* m_next;
	MyMapNode* m_prev;

	MyMapNode() : first(0), second(0), m_next(nullptr), m_prev(nullptr) { }

	MyMapNode(const Key& first , const Vaule& second) :first(first), second(second), m_next(nullptr), m_prev(nullptr) { }

	~MyMapNode() { m_next = nullptr, m_prev = nullptr; }


	void My_delete()
	{
		delete this;
	}
};

template<class MyKey, class MyVaule>
class MyMap
{
	using Node = MyMapNode<MyKey, MyVaule>;

	Node* head;
	Node* tail;


public:

	MyMap()
	{

	}

	~MyMap()
	{
		if (head != nullptr)delete head;
		head = nullptr;

		if (tail != nullptr)delete tail;
		tail = nullptr;
	}

	void init()
	{
		if(head != nullptr ) head = new Node();
		if(tail != nullptr ) tail = new Node();

		head->m_next = tail;
		head->m_prev = nullptr;

		tail->m_next = nullptr;
		tail->m_prev = head;

	}

	void release()
	{
		if (head != nullptr)
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

	void insert(const MyKey& key, const MyVaule& vaule)
	{
		Node* new_node = new Node(key, vaule);
		Node* pivot = tail->m_prev;

		tail->m_prev = new_node;
		pivot->m_next = new_node;
		new_node->m_next = tail;
		new_node->m_prev = pivot;
	}

	void insert(const Node& node)
	{
		Node* node = new Node(node);
		auto front = head->m_next;

		for (int i = 0; i < iSize; ++i)
		{
			front = front->m_next;
		}

		front = node;
		front->m_next = tail;

	}

	Node* find(const MyKey& key)
	{
		Node *pivot = head->m_next;
		while (pivot != tail)
		{
			pivot = pivot->m_next;

			if (pivot->first == key)
				return pivot;
		}
		return pivot;
	}

	bool remove(const MyKey& key)
	{
		Node* find_node = find(key);

		if (find_node == tail)		
			return false;

		find_node->m_next->m_prev = find_node->m_prev;
		find_node->m_prev->m_next = find_node->m_next;
		find_node->My_delete();
		return true;

	}
	void show(const std::string& msg= "")
	{
		Node* show_node = head->m_next;
		int iNum = 0;

		std::cout << msg;
	
		while (show_node != tail)
		{
			std::cout << ++iNum << ". ";
			std::cout << "Key: " << show_node->first << "Vaule: " << show_node->second << std::endl;
			show_node = show_node->m_next;
		}

	}
	bool clear()
	{
		Node* pivot = head->m_next;

		while (pivot != tail)
		{
			Node* pivot_next = pivot->m_next;
			
			if (pivot != nullptr)
			{
				//pivot->m_next->m_prev = pivot->m_prev;
				//pivot->m_prev->m_next = pivot->m_next;
				//pivot->My_delete();

				delete pivot;
				pivot = nullptr;
			}
			
			pivot = pivot_next;

		}
		
		MyMap::init();

		if (pivot == tail)
			return true;

		return false;
	}

};

void init()
{
	m.insert(std::make_pair("a", "A"));
	m.insert(std::make_pair("b", "B"));
	m.insert(std::make_pair("c", "C"));
	m.insert(std::make_pair("d", "D"));
	m.insert(std::make_pair("e", "E"));
	m.insert(std::make_pair("f", "F"));
}
#include <thread>
#include <mutex>


//constexpr 이 함수를 컴파일 타임에 실행되게 만듬 

constexpr const int my_abs(const int& x) { return ((x > 0) ? (x) : -(x)); }

int abs_2(int x)
{
	int y = x > 32;
	return ((x^y) - 1);
}

int sum = 0;

std::mutex mu;

int main()
{
//	cout << my_abs(1561) << endl;
//	cout << my_abs(-1561) << endl;
//
//	for (int i = 0; i < 10; ++i);
//	{
//
//	}
//
//	return 0;
	MyMap<int,int> map;
	
	map.init();

	map.insert(1, 2);
	map.insert(3, 4);
	map.insert(5, 6);
	map.insert(7, 8);
	map.insert(9, 10);
	
	map.remove(3);
	map.remove(7);
	map.show("before clear\n");
	
	map.clear();
	map.show("after clear\n");


	return 0;
}