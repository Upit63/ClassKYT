#include <iostream>
#include <memory>
#include <string>

//#define used_shared_pointer


class GameObject
{
public:
	std::string name;
	int id;
public:
	GameObject(const int& id = 0, std::string name = "") : name(name), id(id)
	{
		//std::cout << " ID : " << id << "持失切" << std::endl;
	}
	~GameObject()
	{
		std::cout << "さけじ" << std::endl;
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

	void show() = delete;


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

};

#ifdef used_shared_pointer 
	class SharePointer
{
	unsigned int* reference_count = nullptr;
	using Ty = GameObject;
	Ty* Ptr;

public:
	
	SharePointer()
	{
		Ptr = new Ty();
		reference_count = new unsigned int;
		*reference_count = 1;
	}

	SharePointer(SharePointer& other)
	{
		(*other.reference_count)++;
		Ptr = other.Ptr;
		reference_count = other.reference_count;
		///*reference_count++;
		///auto i = 102;
	}

	~SharePointer()
	{
		if (reference_count == nullptr)
		{
			return;
		}

			(*reference_count)--;

		if (*reference_count == 1)
		{
			delete reference_count;
			reference_count = nullptr;
		}

		else if (*reference_count > 0)
			return;

		delete Ptr;
		Ptr = nullptr;
	}

	void reset()
	{
		(*reference_count)--;
		
		if (*reference_count == 0)
		{
			reference_count = nullptr;
			return;
		}

		Ptr = nullptr;
		reference_count = nullptr;
			
	}

	int use_count() const
	{
		return *reference_count;
	}

	void operator=(SharePointer& other)
	{
		*this = other;
	}
};
#else
	class UniquePointer
{
	typedef GameObject Ty;
	//using Ty = GameObject;
	using pointer = Ty*;
	Ty* Ptr;

public:

	UniquePointer()
	{
		Ptr = new Ty();
	}

	UniquePointer(UniquePointer& other) = delete;

	UniquePointer(UniquePointer&& other)
	{
		Ptr = other.Ptr;
		other.Ptr = nullptr;
	}

	~UniquePointer() {}

	void reset()
	{
		delete Ptr;
	}

	void operator=(UniquePointer& other) = delete;

	void operator=(UniquePointer&& other)
	{
		Ptr = other.Ptr;
		other.Ptr = nullptr;
	}

	bool operator==(UniquePointer* other)
	{
		if (other == nullptr)
		{
			return true;
		}

		return false;
	}
	bool operator!=(UniquePointer* other)
	{
		if (other != nullptr)
		{
			return true;
		}

		return false;
	}
};
#endif
void pointer_show(int* p, int vaule)
{
	std::cout << "point : " << *p << " | " << "vaule : " << vaule << std::endl;
}

int main()
{
	#ifdef used_shared_pointer 
		std::shared_ptr<GameObject> pShared = std::make_shared<GameObject>();
		//SharePointer pShared;

		auto next(pShared);

		std::cout << "use count : " << pShared.use_count() << std::endl;
		pShared.reset();

		std::cout << "use count : " << next.use_count() << std::endl;

		auto prev(next);
		std::cout << "use count : " << prev.use_count() << std::endl;

		GameObject* pGame = new GameObject;
		if (pGame != nullptr)
		{
			delete pGame;
			pGame = nullptr;
		}

		std::cout << "-----------SharedPointer-------------" << std::endl;
	#else
		//std::unique_ptr<GameObject> pUnique = std::make_unique<GameObject>();
		UniquePointer pUnique;


		auto next = std::move(pUnique);
		pUnique.reset();


		if (pUnique == nullptr)
		{
			std::cout << " pUnique nullptr" << std::endl;
		}

		

		UniquePointer next_next;
		//next_next.operator=(std::move(next));
		next_next = std::move(next);

		if (next_next == nullptr)
		{
			std::cout << " next_next nullptr" << std::endl;
		}



		GameObject* pGame = new GameObject;
		pGame->name;
		if (pGame != nullptr)
		{
			delete pGame;
			pGame = nullptr;
		}
		std::cout << "-----------Uniuqe Pointer-------------" << std::endl;

	#endif  


}