#include<iostream>

/*
 * Konrad Filek
 * Implementacja stosu na raw pointerach
 * Licencja: Public Domain 
 *
 * Jest to przyklad jedynie edukacyjny wykonany w celach przecwiczenia dzialania 
 * raw pointerow, templatek na klasach i obslugi bledow try catchem.
 * Nie jest to w zadnym wypadku kod produkcyjny!
 * Chcialem sprawdzic stan mojej personalnej jakosci pisania kodu
 *
 */

template <class T>
class Stack
{
private:
	struct A
	{
		T value;
		A *back;
	};
	A *t;
	std::size_t size;
public:
	Stack()
	{
		size = 0;
	}

	~Stack()
	{
		while(!empty())
		{
			pop();
		}
	}

	T top()
	{
		if(size == 0)
		{
			throw std::string{"Stack jest pusty!"};
		}
		return t->value;
	}

	void push(T x) 
	{
		A *tmp = t;
		t = new A;
		if(size == 0)
		{
			t->back = nullptr;
		}
		else
		{
			t->back = tmp;
		}
		t->value = x;
		size++;
	}

	T pop()
	{
		if(size != 0)
		{
			T result = t->value;
			A *tmp = t->back;
			delete t;
			if(size != 1)
			{
				t = tmp;
			}
			size--;
			return result;
		}
		else
		{
			throw std::string{"Nie mozna usunac elementu, kiedy stos jest pusty!"};
		}
	}

	bool empty()
	{
		return size == 0;
	}
};


int main()
{
	std::cout
	<< "Operacje:\n"
	<< "1 - dodanie liczby do stosu(uzytkownik podaje na wejsciu)\n"
	<< "2 - usuniecie wierzcholka ze stosu\n"
	<< "[kazda inna wartosc] - wyjscie z programu\n";

	Stack<int> a;
	while(1)
	{
		try
		{
			std::cout << "Wierzcholek: " << a.top() << std::endl;
		}
		catch(std::string errorMsg)
		{
			std::cout << errorMsg << std::endl;
		}

		int choice = 0;
		std::cin >> choice;

		switch(choice)
		{
			default: // zakonczenie programu 
			{
				return 0;
			} break;
			case 1: // dodanie liczby na stos 
			{
				int x;
				std::cin >> x;
				a.push(x);
			} break;
			case 2: // usuniecie wierzcholka stosu
			{
				try
				{
					std::cout << "Usunieto: " << a.pop() << std::endl;
				}
				catch(std::string errorMsg)
				{
					std::cout << errorMsg << std::endl;
				}
			} break;
		}
	}
}
