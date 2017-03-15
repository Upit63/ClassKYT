//#include <iostream>
//#include <algorithm>
#include "../../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/iostream"
#include "../../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/algorithm"
#include "../../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/random"
#include "../../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/list"
#include "../../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/include/vector"

using namespace std;

class GameObject
{
public:
	std::string name;
	int id;
public:
	GameObject(const int& id = 0, std::string name = "") : name(name), id(id)
	{
		//std::cout << " ID : " << id << "»ý¼ºÀÚ" << std::endl;
	}

	GameObject(const GameObject& other)
	{
		id = other.id;
		name = other.name;
		//std::cout << " ID : "<< id <<"&" << std::endl;
	}

	~GameObject() {}


	bool operator ==(const GameObject& other)
	{
		if (id == other.id)return true;
		return false;
	}
	bool operator ==(const GameObject&& other)
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
		std::cout << id << endl;
	}

};

struct TreeData { int hp; };

template <class T>
class Monster
{

protected:
	using DataType = T;
	DataType data;

public:
	virtual void input(T in_data)
	{
		data = in_data;
	}
};

template <class T>
class Tree : public Monster<T>
{
};


void show_id(void* a)
{
	auto obj = static_cast<GameObject*>(a);
	obj->show();
}

void show(void* a)
{
	auto obj = static_cast<int*>(a);
	std::cout << *obj << std::endl;
}

int main()
{
	auto pInt = new int(1);
	show(pInt);
	delete pInt;


	auto o = new GameObject(1);
	show_id(o);
	delete o;

	return 0;


	std::list<GameObject> v;

	default_random_engine dre;
	normal_distribution<> nd(50, 50);

	double arr[100];
	for (auto i = 0; i < 100; ++i)
	{
		v.push_back(nd(dre));
	}


	v.sort
	(
		[](const auto& left, const auto& right) -> int
		{
			return (left.id > right.id);
		}
	);


	//v.remove_if
	//(
	//	[&](auto& pMonster)
	//	{
	//		if (pMonster->isDie())
	//		{
	//			pPlayer->AddMoney(pMonster->SendMoney());
	//			return true;
	//		}
	//		return false;
	//	}
	//);

	//¶÷´Ù
	//sort
	//(
	//	v.begin(), 
	//	v.end(), 
	//	[](const auto& left, const auto& right) 
	//	{
	//		return left.id < right.id;
	//	}
	//);

	for (const auto &i : v )
	{
		cout << i.id << ',';
	}


	//-> c:\¼ÛÁö¿õ\³»ÄÄÇ»ÅÍ\¹ÙÅÁÈ­¸é\°ú¿Ü\±è¿µÅÂ½Ü\20170207\Resource\Image\apple.png;
	//
	//-> c:\¼ÛÁö¿õ\³»ÄÄÇ»ÅÍ\¹ÙÅÁÈ­¸é\°ú¿Ü\±è¿µÅÂ½Ü\20170207\x64/Release/½ÇÇà.exe
	//-> c:\¼ÛÁö¿õ\³»ÄÄÇ»ÅÍ\¹ÙÅÁÈ­¸é\°ú¿Ü\±è¿µÅÂ½Ü\20170207\Code/main.cpp
	//
	//-> ../../Resource/Image/apple.png

	

	return 0;
}