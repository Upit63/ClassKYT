#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;


int main()
{
	std::vector<char> v;

	ifstream fin;
	fin.open("the.txt",ios::binary);

	if (true == fin.fail())
	{
		std::cout << "not ifstream find" << std::endl;
		return 0;
	}

	char c = NULL;
	char msg[20] = { NULL };
	int iCount = 0;
	int i = 0;
	char enter[4] = { NULL };

	char arrThat[3] = { 't','h','a' };
	char *arrpThat[3] = { nullptr };

	//getline '/r' ���ö����� �д´�.
	//get charũ�⸸ŭ ��ĭ�� ����
	// .operator>>(char c) get(char)�̶� ����ϰ� �д´�.
	

	while (fin.get(c))
	{
		if (c == ' ')
		{
			fin.get(c);
			v.push_back(c);

			if (c == 't' || c == 'T')
			{
				//enter[0] = c;
				fin.get(c);
				v.push_back(c);

				if (c == 'h' || c == 'H')
				{
					//enter[1] = c;
					fin.get(c);
					v.push_back(c);

					if (c == 'e' || c == 'E')
					{
						//enter[2] = c;
						fin.get(c);
						v.push_back(c);

						if (c == ' ')
						{
							//++iCount;	
						}

						//v.push_back(c);
					}
				}
			
			}
		}
		//v.push_back(c);
		//else
		//{
		//	while (fin.get(c))
		//	{
		//		if (c == ' ')
		//		{
		//			break;
		//		}
		//
		//	}
		//}
	}	

	

	fin.close();

	std::cout << "the: " << iCount << std::endl;
	
	return 0;

	ofstream out("�ȷ�Ȩ���Ǹ���.txt", ios::binary);
	if (out.fail()==true)
	{
		std::cout << "not ofstream find" << std::endl;
		return 0;
	}

	/*for (auto d : v)
	{
		out << d <<",";
	}*/

	out.close();

}

///<summary>
///����
///<summary>
//�ּ� ó���� �Լ�

