#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <Windows.h>

using namespace std;

int sum = 0;
int arr_sum[1000];

int t_a;
int t_b;
int t_c;

std::mutex my_mutex;

#define MAX 25000000

static time_t tStart = 0;
static std::chrono::high_resolution_clock::time_point cStart;

enum TIME_UNIT
{
	UINT_nanoseconds
	, UNIT_microseconds
	, UINT_milliseconds
	, UINT_seconds
	, UINT_minutes
	, UINT_hours
};

static void ChornoTime(bool start = true, const int& time_unit = UINT_nanoseconds)
{
	if (start) cStart = std::chrono::high_resolution_clock::now();

	else
	{
		auto total_time = std::chrono::high_resolution_clock::now() - cStart;

		std::cout << "time : ";
		switch (time_unit)
		{
		case UINT_nanoseconds:  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(total_time).count() << "nanoseconds \n";  break;
		case UNIT_microseconds: std::cout << std::chrono::duration_cast<std::chrono::microseconds>(total_time).count() << "microseconds \n"; break;
		case UINT_milliseconds: std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(total_time).count() << "msec \n"; break;
		case UINT_seconds:      std::cout << std::chrono::duration_cast<std::chrono::seconds>(total_time).count() << "seconds \n"; break;
		case UINT_minutes:      std::cout << std::chrono::duration_cast<std::chrono::minutes>(total_time).count() << "minutes \n"; break;
		case UINT_hours:        std::cout << std::chrono::duration_cast<std::chrono::hours>(total_time).count() << "hours \n"; break;
		};

	}


}

static void gotoxy(const short& x, const short& y)
{
	COORD pos{ x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void func(const int& nThread)
{
	int local_sum = 0;
	for (int i = 0; i < (MAX / nThread); ++i)
	{
		local_sum += 2;
	}
	my_mutex.lock();
	sum += local_sum;
	my_mutex.unlock();
}
void arr_func(const int& nThread, const int& nID)
{
	int id = nID * 8;
	for (int i = 0; i < (MAX / nThread); ++i)
	{
		arr_sum[id] += 2;
	}
}

void arr_func_02(const int& nThread, const int& nID)
{
	int id = nID * 8;
	for (int i = 0; i < (MAX / nThread); ++i)
	{
		if (id == 1) t_a += 2;
		else if (id == 2) t_b += 2;
		else if (id == 3) t_c += 2;
		//arr_sum[id] += 2;
	}
}

class MyFrame
{
public:
	MyFrame() : x(0), y(0) {}
	~MyFrame() {}

	int x, y;

	void run()
	{
		std::thread t_clear{ [&]() { update(); } };

		while (1)
		{
			//clear();
			render();
		}

		t_clear.join();
	}
	void update()
	{
		while (1)
		{
			if (GetAsyncKeyState(VK_LEFT)) x--;
			if (GetAsyncKeyState(VK_RIGHT)) x++;
			if (GetAsyncKeyState(VK_UP)) y--;
			if (GetAsyncKeyState(VK_DOWN)) y++;
			cout << "(" << x << "," << y << ")" << endl;
		}
	}
	void render()
	{
		gotoxy(x, y);
		std::cout << "hellow" << std::endl;
		Sleep(17);
		system("cls");
	}
	void clear()
	{
		while (1)
		{
			Sleep(17);
			system("cls");
		}
	}
};

int** iarr;
void init(const int& nThread)
{
	iarr = new int*[nThread];

	for (int i = 0; i < nThread; ++i)
	{
		iarr[i] = new int;
	}
}

void Delete(const int& nThread)
{
	for (int i = 0; i < nThread; ++i)
	{
		delete iarr[i];
	}
}

void Pointer_arr_func(const int& nThread, const int& iD)
{

	for (int i = 0; i < (MAX / nThread); ++i)
	{
		*iarr[iD] += 2;
	}

}


int main()
{
	int nThread = 2;
	std::thread input
	{
		[&]()
	{
		while (nThread)
		{
			init(nThread);
			std::cin >> nThread;
		}
	}
	};

	std::vector<std::thread> vThread;


	for (auto i = 0; i < 10; ++i)
	{
		arr_sum[i] = 0;
	}

	while (nThread)
	{
		int local_nThread = nThread;

		t_a = 0;
		t_b = 0;
		t_c = 0;
		sum = 0;
		ChornoTime();
		for (auto i = 0; i < local_nThread; ++i)
		{
			//vThread.push_back(std::thread{ func, local_nThread });
			vThread.push_back(std::thread{ Pointer_arr_func, local_nThread, i });
		}

		for (auto &thread : vThread)
		{
			thread.join();
		}

		for (auto i = 0; i < local_nThread; ++i)
		{
			sum += *iarr[i];
			*iarr[i] = 0;
		}

		ChornoTime(false, TIME_UNIT::UINT_milliseconds);
		//   std::cout << "sum : " << sum << std::endl;

		for (auto i = 0; i < local_nThread; ++i)
		{
			arr_sum[i] = 0;
		}


		vThread.clear();
	}
	input.join();
	Delete(nThread);


}