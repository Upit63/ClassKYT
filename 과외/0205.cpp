#include <iostream>
#include <vector>
using namespace std;

static int gInstanceID = 0;
class Coffee
{
private:
	int m_iID;
	size_t m_iSize;
	char* m_pName;

public:

	inline int strlen_my(char *pString)
	{
		int iNum = 0;
		while (pString[iNum] != NULL)
		{
			++iNum;
		}
		return iNum;
	}
		
	void release()
	{
		if (m_pName != nullptr)
		{
			delete m_pName;
		}
			m_pName = nullptr;
	}

	Coffee(char *pName = nullptr)
		:m_pName(pName)
	{
		if (pName == nullptr)
			return;

		m_iSize= strlen(m_pName);
		m_pName = new char[m_iSize+1];
		memcpy(m_pName, pName, m_iSize+1);

		m_iID = gInstanceID;
		std::cout<<"ID: "<< m_iID << "\t ������, �ּҰ� : " << (void*)m_pName << std::endl;
		++gInstanceID;
	}

	Coffee(const Coffee& other)
	{
		m_iSize = other.m_iSize;
		m_pName = new char[m_iSize+1];

		memcpy(m_pName, other.m_pName, m_iSize+1);
		m_iID = gInstanceID;
		std::cout << "ID: " << m_iID << "\t\t �������, �ּҰ� : " << (void*)m_pName << std::endl;
		++gInstanceID;

	}

	//�̵������� �������� ���
	Coffee(Coffee&& other)
	{
		m_iSize = other.m_iSize;
		m_pName = other.m_pName;
		
		other.m_pName = nullptr;
		m_iID = gInstanceID;
		std::cout << "ID: " << m_iID << "\t\t �̵�����, �ּҰ� : " << (void*)m_pName << std::endl;
		++gInstanceID;
	}

	~Coffee()
	{
		std::cout  << "ID: " << m_iID << "\t �Ҹ���, �ּҰ� : " << (void*)m_pName << std::endl;
	
		if (m_pName != nullptr)
		{
			delete m_pName;
		}
		m_pName = nullptr;
	}

	void show()
	{
		if (m_pName != nullptr)
			std::cout << "ID: " << m_iID << " Name: " << m_pName << std::endl;
		else
			return;
	}

	void operator=(const Coffee& other)
	{
		m_iSize = other.m_iSize;
		m_pName = new char[m_iSize + 1];
		m_iID = other.m_iID;

		memcpy(m_pName, other.m_pName, m_iSize + 1);
		std::cout << "ID: " << m_iID << "\t\t �������, �ּҰ� : " << (void*)m_pName << std::endl;
	}

	void operator=(Coffee&& other)
	{
		m_iSize = other.m_iSize;
		m_pName = other.m_pName;
		m_iID = other.m_iID;

		other.m_pName = nullptr;
		std::cout << "ID: " << m_iID << "\t\t �̵�����,  �ּҰ� : " << (void*)m_pName << std::endl;
	}
};

int main()
{
	std::cout << "----------------------------- ������ --------------------------" << std::endl;
	Coffee Americano("�Ƹ޸�ī��");
	Coffee Cofelatte("ī���");
	Coffee Caramel("ī���");

	Coffee coffee;
	coffee = move(Americano);
	std::cout << "----------------------------- show --------------------------" << std::endl;
	//--
	Americano.show();
	coffee.show();
	
	std::cout << "----------------------------- �Ҹ��� --------------------------" << std::endl;
	//coffee.release();
	//Americano.release();
	//Cofelatte.release();
	//Caramel.release();

	return 0;
}