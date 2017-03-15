#include <iostream>
#include <time.h>
#include <list>
#include <vector>
#include <map>
#include <string>


using namespace std;
//>
//==
//!=
class GameObject
{
public:
	std::string name;
	int id;
public:
	GameObject(const int& id=0, std::string name = "") : name(name), id(id) {}
	~GameObject(){}

	bool operator >(const GameObject& other) const
	{
		if (id > other.id) return true;
		return false;
	}

	bool operator ==(const GameObject& other)
	{
		if (id == other.id)return true;
		return false;
	}

	bool operator !=(const GameObject& other)
	{
		if (id != other.id)return true;
		return false;
	}

	void show()
	{
		std::cout << id;
	}
	
};

template<class T>
class MyNode
{
public:
	T m_iData;

	MyNode* next;
	MyNode* before;
	MyNode(const T& iData = 0) : m_iData(iData), next(nullptr) , before(nullptr)
	{
	}
	~MyNode() 
	{
		next = nullptr;
		before = nullptr;
	}

	void show()
	{
		m_iData.show();
	}

};

template<class T>
class MyList
{
	using Node = MyNode<T>;

	Node *head;
	Node *tail;

	int m_iNum;

public:

	MyList(const int& iNum = 0) : m_iNum(iNum), head(nullptr), tail(nullptr)
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


		//---------------------------------------------------------------------------
		//Node* pivot2 = nullptr;
		//for(pivot2 = head; pivot2 != nullptr; pivot2 = pivot2->next)
		//{
		//}
		//Node* node = new Node(iNum);
		////head = node;
		//if (m_iNum == 1)
		//{
		//	head->next = node;
		//}
		//else if(m_iNum > 1)
		//{
		//	for (int i = 0; i < m_iNum; ++i)
		//	{
		//		//head->next->operator%=(head->next);
		//	}
		//}
		//++m_iNum;
	//---------------------------------------------------------------------------

	}

	//전체
	void show()
	{
		int iNum = 1;
		Node* pivot = head;
		cout << typeid(T).name() << endl;
		while (pivot->next != tail)
		{
			std::cout << iNum << ". ";
			pivot->next->show();
			std::cout << "\n";
			pivot = pivot->next;
			++iNum;
		}

		//std::cout << "num : " << iNum << std::endl;
	}

	void swap(Node* L, Node* R)
	{
		if ( (L->next == R) && (R->before == L) )
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
		
		
		/*while (current->next != nullptr)
		{
			if ((left != nullptr) && (right != nullptr))
			{
				left->before->before->next = left->before;
				left->next = right->next;
				left->before->next = right;
				right->next = left;		

			}

			else if (current->next->m_iData == iNumleft)
			{
				left = current->next;
				current = current->next;
			}

			else if (current->next->m_iData == iNumright)
			{
				right = current->next;
				current = current->next;
			}

			else
			current = current->next;
		}
*/

	}

	void remove(const T& tNum)
	{
		Node* current = head;
		Node* before = nullptr;

		//Node* current = head;
		//Node* before = nullptr;

		while (current->next != nullptr)
		{
			
			if (current->next->m_iData == tNum)
			{
				if (current->next->next == nullptr)
				{
					delete current->next;
					current->next = nullptr;

					break;
				}
				else
				{
					before = current;
					current = current->next;
					auto pNode = current->next;
					delete before->next;
					before->next = nullptr;
					before->next = pNode;
					current = pNode;
					//current->next = nullptr;
				}
			}
			
			else
			{
				before = current;
				current = current->next;
				
			}
		}
	
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
};

template<class Ty>
void QQswap(Ty& iLeft, Ty& iRight)
{
	Ty swap = iLeft;
	iLeft = iRight;
	iRight = swap;
}

int main()
{
	/* 
		범위기반 for문
		for (int d : arr){}
	*/

	MyList<GameObject> myList;


	std::cout << "init" << std::endl;
	myList.init();

	std::cout << "insert" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		myList.insert(GameObject(rand()%100));
		//myList.insert((10-i));
	}
	myList.show();


	std::cout << "remove" << std::endl;

	std::cout << "swap" << std::endl;


	//myList.change(2, 6);

	//myList.remove(2);	// message 나오게
	//myList.remove(15);
	//myList.remove(5);
	//myList.remove(9);


	std::cout << "Last Show" << std::endl;
	myList.show();		//show

	//while (1)
	//{
	//	std::cout << "----------" << std::endl;

	//	int left, right;
	//	std::cout << "left : "; cin >> left;
	//	std::cout << "right : "; cin >> right;

	//	mylist.change(left, right);
	//	mylist.show();		//show

	//}
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		myList.sort();
		myList.show();


	return 0;
}
