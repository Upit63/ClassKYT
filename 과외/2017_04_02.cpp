#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

void CountWords(std::map<std::string,int>& m, string* msg)
{
	int i = 0;

	while (msg[i] != NULL)
	{
		m[msg[i++]]++;
	}

}

int main()
{
	std::map<std::string, int> m;

	string msg[1000];

	std::cin >> msg;
	CountWords(m, msg);

	for (auto &c : m)
	{
		std::cout << "word : " << c.first << " - " << "count : " << c.second << std::endl;
	}


	return 0;
}