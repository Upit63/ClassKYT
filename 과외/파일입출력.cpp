#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
class Obj
{
public:
	Obj():key(rand() % 100) {}

private:
	int key;

public:
	void operator=(const Obj& other)
	{
		(key = other.key);
	}

	bool operator<(const Obj& other) const
	{
		return (key < other.key);
	}

	int operator*() const
	{
		std::cout << "key: ";
		return key;
	}
};

#define READ

int size(char* cWord)
{
	int i = 0;

	while (cWord[i]!=NULL)
	{
		++i;
	}
	return i;
}

bool Compare(char* left, char* right,const int & iNum)
{

	for (int i = 0; i < iNum; ++i)
	{
		if (left[i] != right[i])
		{
			return false;
		}
	}

	return true;
}


using namespace std;
#include <set>

int main()
{
	//	명
	// goto 명

	//string 변수명.append(뒤에 덧붙일 문자(열) " ");
	vector<char> write_data;

#ifdef READ
	vector<char> vInput;
	ifstream ifs;

	char c = NULL;
	int iCount = 0;
	bool TorF = true;

	int iCount_Input = 0;
	int iCount_Output = 0;

	char* Input_Word = nullptr;
	Input_Word = new char[20];

	char* Output_Word = nullptr;
	Output_Word = new char[20];

	memset(Output_Word, 20, sizeof(Output_Word));
	memset(Input_Word, 20, sizeof(Input_Word));


	while (true)
	{
		string file_name = " ";
		std::cout << "무슨 파일을 읽으시겠습니까? : ";
		std::cin >> file_name;

		if (file_name.size() < file_name.find(".txt"))
		{
			file_name.append(".txt");
		}

		ifs.open(file_name, ios::binary);

		if (false == ifs.is_open())
		{
			std::cout << "Not found" << endl;
			continue;
		}
		std::cout << "found" << endl;

		break;
	}

	std::cout << "바꿀 단어를 입력해주세요 (20자 이내)" << endl;
	std::cin >> Input_Word;

	std::cout << "어떤 단어로 바뀔지 입력해주세요 (20자 이내)" << endl;
	std::cin >> Output_Word;

	iCount_Input = size(Input_Word);
	iCount_Output = size(Output_Word);



	std::vector<int> v;
	std::set<int> s;
	
	s.size();
	v.size();

	std::string msg;
	msg.size();
	msg.length();

	for(auto i =0; i < msg.size(); ++i) msg[i];

	for (const auto& c : msg) c;
	std::vector<char> k;
	while (ifs.get(c))
	{
		k.push_back(c);
		if ('z' == c)
		{
			int a = 10;
		}
		if (' ' == c || '\r' == c || k.size() == 1)
		{
			int start = 0;

			if (k.size() == 1)
			{
				if (k[0] == Input_Word[0])
				{
					start++;
				}
			}
		
			else if ('\r' == c)
			{
				ifs.get(c); 
				ifs.get(c);	 
				if (c == Input_Word[0])
				{
					start++;
				}
			}
			for (int i = start; i < iCount_Input; ++i)
			{
				ifs.get(c);
				k.push_back(c);

				if (c != Input_Word[i])
				{
					TorF = false;
					break;
				}

				else
				{
					TorF = true;
					//ifs.get(c);
				}
			
			}

		//	if (TorF == false)
		//	{
		//		while (' ' == c)
		//		{
		//			ifs.get(c);
		//		}
		//	}

			ifs.get(c);
			k.push_back(c);

			if (' ' == c && true == TorF)
			{
				for (int a = 0; a < iCount_Output; ++a)
				{
					write_data.push_back(Output_Word[a]);
				}

				write_data.push_back(' ');
				++iCount;
				TorF = false;
			}

		}


		write_data.push_back(c);
	}

	for (const auto& d : k)
		std::cout << d;
	
	std::cout << Input_Word << "가 " << Output_Word << "로 바뀌었습니다" << endl;
	std::cout <<"총 "<< iCount << "개가 바뀌었습니다" << endl;
	ifs.close();

	ofstream ofs("output.txt", ios::binary);

	for (const auto & c : write_data)
	{
		ofs << c;
	}
	

	ofs.close();

///-------------------------------------------------------------------------------

#else
	//#pragma region [이름]
	string output_name = " ";

	cout << "만들 파일 이름은?" << endl;
	cin >> output_name;

	ofstream ofs(output_name,ios::binary | ios_base::app);

	while (true)
	{
		string msg = " ";
		cin >> msg;

		if ("exit" == msg)
			break;
	
		if ("@e" == msg)
		{
			ofs << endl;
			continue;
		}

		ofs << msg;

	}

	ofs.close();

	//#pragma endregion
	#endif // READ
	return 0;



	//std::make_pair(key, vaule);
}