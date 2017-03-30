#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

int iSum = 0;
std::mutex My_Mutex;
int arr_sum[10];

void func(const int &iThread)
{
	int a = 0;
	for(int i = 0; i < (2500000 / iThread); ++i)
	{
		a += 2;
	}
		My_Mutex.lock();
		iSum += a;
		My_Mutex.unlock();
}

void arr_func(const int &iThread,const int& nID)
{
	for (int i = 0; i < (2500000 / iThread); ++i)
	{
		arr_sum[nID] += 2;
	}     
}
int main()
{
	std::vector<std::thread> vThread;
	int iThread = 2;

	for (int i = 0; i < iThread; ++i)
	{
		vThread.push_back(std::thread{ arr_func, iThread, i });
	}

	for (auto &thead : vThread)
	{
		thead.join();
	}

	for (int i = 0; i < 10; ++i)
	{
		iSum += arr_sum[i];
	}

	cout << "sum: " << iSum << endl;

	return 0;
}