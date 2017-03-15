#include <iostream>
#include <map>
#include <set>
#include <random>
#include <functional>

using namespace std;

/*	
	set, map은 정렬 컨테이너
	insert 하는 순간에 정렬이 됩니다. (정렬 알고리즘은 Red-Black Tree)

	set = insert data가 (key = value)
	map = insert data key, value

*/

void empty(const std::set<int>& sSet)
{
	if (sSet.empty() == true)
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "not empty" << endl;
	}
}

void empty2(const std::set<int>& sSet)
{
	if (sSet.empty() == true)
	{
		cout << "```empty" << endl;
	}
	else
	{
		cout << "```not empty" << endl;
	}
}

int main()
{
	set<int> sSet;
	 
	//sort(시작주소, 끝주소) C++
	//find(시작주소, 끝주소) C++ 
	default_random_engine dre;
	normal_distribution<double> nd(500, 50);

	function<void(const std::set<int>&)>set_empty;

	if (0)
		set_empty = empty;
	else
		set_empty = empty2;

	function<void(const std::set<int>&)>lamda_empty =
		[](std::set<int> sSet)
	{
		if (sSet.empty() == true)
		{
			cout << "empty" << endl;
		}
		else
		{
			cout << "not empty" << endl;
		}
	};

	for (int i = 0; i < 100; ++i)
	{
		sSet.insert(nd(dre));
	}

	cout << "-------set--------" << endl;

	for (const auto& i : sSet)
	{
		cout << i << "\t";
	}

	cout << endl;
}