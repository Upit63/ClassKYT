#include <iostream>
#include <list>
#include <vector>

#include <memory>
#include <fstream>

/*
	 - container : list, vector, map, set (make_pair)
	 - smart_pointer
	 - 가변인자 teamplate

*/


#define Container list

using namespace std;


class GameObject
{
public:
	std::string name;
	int id;
public:
	GameObject(const int& id = 0, std::string name = "") : name(name), id(id) 
	{
		//std::cout << " ID : " << id << "생성자" << std::endl;
	}

	GameObject(const GameObject& other)
	{
		id = other.id;
		name = other.name;
		//std::cout << " ID : "<< id <<"&" << std::endl;
	}
	GameObject(const GameObject&& other)
	{
		id = other.id;
		name = other.name;
		//std::cout << " ID : " << id << "&&" << std::endl;
	}
	~GameObject() {}

	bool operator >(const GameObject& other) const
	{
		if (id > other.id) return true;
		return false;
	}

	bool operator ==(const GameObject& other)
	{
		//std::cout << "operator ==(const GameObject& other)" << std::endl;
		if (id == other.id)return true;
		return false;
	}
	bool operator ==(const GameObject&& other)
	{
		//std::cout << "operator ==(const GameObject&& other)" << std::endl;
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


ostream& operator<<(ostream& os, GameObject object)
{ 
	os << object.id;
	return os;
}

template<class Ta, class Tb = int>
Tb sum(Ta a, Tb b, bool return_type = true)
{
	if (return_type)
		return a;
	else
		return b;
}

//template<class T,class Args...>

void show()
{
}

template<class T, class... Args>
void show(T a, Args... rest)
{
	std::cout << a << std::endl;
	show(rest...);

}




int main(int argc, char *argv)
{



	//ifstream ifs;
	//ofstream ofs;


	GameObject object;
	object.id = 10;

	return 0;
	std::cout << object.id << std::endl;
	std::cout.operator<<(object.id);


	std::cout << object << std::endl;
	//std::cout.operator<<(object);


	std::vector<GameObject> v;
	std::list<GameObject> l;

	for (int i = 0; i < 4; ++i)
	{
		auto a = GameObject(i);
		v.push_back(std::move(a));
	}

	for (auto d : v)
	{
		d.id *= 100;
	}

	for (auto &d : v)
	{
		d.id *= 100;
	}

	for (const auto &d : v)
	{
		std::cout << d.id << std::endl;
	}

	//v.begin();
	//l.begin();
	//
	//v.end();
	//l.end();
	//
	//v.reserve(5);
	//l.reserve(5);
	//
	//v.erase();
	//l.erase();
	//
	//v.remove();
	//l.remove();
	//l.remove_if();

	//범위기반 for문 auto는 vector의 Tempelate
	//for (auto obj : v)
	//{
	//	obj.show();
	//}

	return 0;
}



