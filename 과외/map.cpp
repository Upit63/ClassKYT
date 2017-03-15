#include <map>
#include <iostream>
#include <string>

using namespace std;

template<class Key, class Vaule>
class CMymap
{
	CMymap(Key Key, Vaule Vaule) {};

};

using MyKey = int;
using Myvaule = int;

/*
	tempalte<class Key, class vaule>
	class map
	{

	}
	
			<> <- template
	std::map<key, vaule>;

*/


int main()
{
	std::map<int, int> m;
	std::pair<MyKey, Myvaule> mypair(1, 10);

	mypair = { 50,500 };

	mypair.first; //key
	mypair.second; //vaule

	m.empty(); (m.size() == 0);

	m.insert(mypair);
	m.insert(std::make_pair(2, 11));
	m.emplace(std::pair<MyKey, Myvaule>(3, 15));
	m.emplace(std::move(std::make_pair(5, 11)));

	std::cout << "---------------------" << std::endl;
	for (const auto& iter : m)
		std::cout << "key : " << iter.first << " | vaule: " << iter.second << std::endl;

	std::cout<<"---------------------" << std::endl;

	auto rebegin = m.rbegin();
	cout<<"key: "<<rebegin->first<<" | vaule: " << rebegin->second<<endl;
	++rebegin;
	cout<<"key: "<<rebegin->first<<" | vaule: " << rebegin->second<<endl;
	++rebegin;
	cout<<"key: "<<rebegin->first<<" | vaule: " << rebegin->second<<endl;

	std::cout << "---------------------" << std::endl;
	

	//try
	//{
	//	m.at(0);
	//}
	//catch (exception exception)
	//{
	//	std::cout << "catch" << std::endl;
	//}

	std::cout<< "1 : " << m[1] << std::endl;
	std::cout<< "2 : " << m[2] << std::endl;
	std::cout<< "3 : " << m[3] << std::endl;

	int remove_vaule = 5;

	auto era = m.erase(remove_vaule);
	cout << "succ erase" << era << endl;

	era = m.erase(remove_vaule);
	cout << "fail erase: " << era << endl;

	auto find = m.find(2);
	if (find != m.end())
	{
		cout << "find : " << find->second << endl;
	}

	return 0;
}