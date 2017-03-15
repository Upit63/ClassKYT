#include <iostream>

using namespace std;

//class Monster
//{
//private:
//	int id;
//
//public:
//	Monster() : id(rand() % 100)
//	{
//		double c = 0.0;
//		const int a = 10;
//		int b = 1;
//		c = (double)a;
//		
//		b = reinterpret_cast<int>(a);
//	}
//
//	//int operator()() { return id; }
//};


class Vector2
{
public:
	int xpos, ypos;
public:
	Vector2(int x = 0, int y = 0)
		:xpos(x), ypos(y)
	{

	}

	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	void show()
	{
		std::cout << "(" << xpos << "," << ypos << ")" << std::endl;
	}

	// 1
	void operator+=(const Vector2& other)
	{
		xpos += other.xpos;
		ypos += other.ypos;
	}
	Vector2 operator+(const Vector2& other)
	{
		return Vector2(other.xpos + xpos, other.ypos + ypos);
	}

	Vector2 operator-(const Vector2& other)
	{
		return Vector2(other.xpos - xpos, other.ypos - ypos);
	}
	void operator-=(const Vector2& other)
	{
		xpos -= other.xpos;
		ypos -= other.ypos;
	}
	
	Vector2 operator*(const Vector2& other)
	{
		return Vector2(other.xpos * xpos, other.ypos * ypos);
	}

	Vector2 operator*(const int& iNum)
	{
		return Vector2(iNum * xpos, iNum * ypos);
	}
	void operator*=(const Vector2& other)
	{
		xpos *= other.xpos;
		ypos *= other.ypos;
	}

	Vector2 operator/(const Vector2& other)
	{
		return Vector2(other.xpos / xpos, other.ypos / ypos);
	}
	void operator/=(const Vector2& other)
	{
		xpos /= other.xpos;
		ypos /= other.ypos;
	}
	// - * / 

};


class MyNode
{
public:
	int m_iData;
	MyNode* m_next;
	MyNode* prev;
	MyNode(const int& iData = 0) : m_iData(iData) , m_next(nullptr){}
	~MyNode(){}
};



class MyList
{
	MyNode *head;

public:
	MyList() : head(nullptr)
	{
		
	}
	~MyList()
	{
		if (head != nullptr)delete head;
		head = nullptr;
	}
	void init()
	{
		head = new MyNode();
	}
	void release()
	{
		if (head != nullptr)
		{
			delete head;
			head = nullptr;
		}
	}

	void insert(int iNum)
	{
		MyNode* node;
		node = new MyNode(iNum);
		head->m_next = node;
	}
	//전체
	void show()
	{
		
	}

	void remove(int iNum)
	{
		auto a = head->m_next;
		--iNum;
		for (int i = 0; i < iNum; ++i)
		{
			a = a->m_next;
		}

		delete a;
	}
};



//Vector2 operator+(Vector2& a,Vector2& b)
//{
//	a.xpos = a.xpos + b.xpos;
//	a.ypos = a.ypos + b.ypos;
//	return a;
//}

//template<class Type, class tem >
//Type<tem> sum(Type a, tem b)
//{
//	using type = Type<tem>;
//	return a + b;
//}

#include <map>

int main()
{
	Vector2 a, b, c;
	a = b;
	a.operator=(b);

	MyList myList;

	std::cout << "init" << std::endl;
	myList.init();

	std::cout << "insert" << std::endl;

	for (int i = 0; i < 10; ++i)myList.insert(i);
	myList.show();

	

	std::cout << "remove" << std::endl;
	myList.remove(9);	// message 나오게
	myList.remove(15);
	myList.remove(5);
	myList.remove(1);


	std::cout << "Last Show" << std::endl;
	myList.show();		//show
		

	//Vector2 a(1,1);
	//Vector2 b(2,2);
	//int iSpeed = 10;
	//
	//std::cout << "before a : "; a.show();
	//auto c = a + b;
	//c.show();
	//std::cout << "after a : "; a.show();
	//
	//auto d = a * iSpeed;
	//d.show();
	//a += b;
	//
	//int afdsadsf = 10;

	//std::cout << sum(1, 1) << std::endl;
	//std::cout << sum(1.0f, 1.0f) << std::endl;
	//std::cout << sum<int>(1, 1) << std::endl;
	//std::cout << sum<float>(1.0f, 1.0f) << std::endl;
	//auto a = sum<Monster>(Monster(), Monster());
	//auto b = sum(Monster(), Monster());


	return 0;
}

