#pragma once
#include "iostream"
#include "windows.h"
// Объявление двусвязного списка
template <class T>
struct node
{
	T DATA; // Сообщение от пользователя
	node* next, * prev; // Указатель на следующий и предыдущий элемент
};
// Базовый шаблонный класс, содержащий в себе все методы и поля дека
template <class T>
class base_deque
{
protected:
	node<T>* begin, * end; // Объявление начало и конца дека
	int _SIZE, _MAXSIZE; // _SIZE - текущее количество записей, _MAXSIZE - максимальное количество записей в деке
		T* data;
public:
	// Метод добавления элемента в конец дека, доступный только родительскому классу
	virtual void push_front(T dat)
	{
		std::cout << "\nБазовый класс!";
	}
	// Метод добавления элемента в начало дека, доступный только родительскому классу
	virtual void push_back(T dat)
	{
		std::cout << "\nБазовый класс!";
	}
	// Метод удаления элемента с конца дека, доступный только родительскому классу
	virtual void pop_front()
	{
		std::cout << "\nБазовый класс!";
	}
	// Метод удаления всех данных дека, доступный только родительскому классу
	virtual void clear()
	{
		std::cout << "\nБазовый класс!";
	}
	// Метод проверки на пустоту дека, доступный родительскому и дочерним классам
	bool empty()
	{
		return (this->_SIZE == 0) ? 1 : 0;
	}
	// Метод проверки на заполненость дека, доступный родительскому и дочерним классам
	bool full()
	{
		return (_SIZE == _MAXSIZE) ? 1 : 0;
	}
	// Метод вывода количества записей в деке, доступный родительскому и дочерним классам
	int size()
	{
		return _SIZE;
	}

		int maxsize()
	{
		return _MAXSIZE;
	}
	// Метод вывода последнего элемента дека, доступный только родительскому классу
	virtual T front()
	{
		T dat;
		std::cout << "\nБазовый класс!";
		return dat;
	}
	// Очистка памяти (работа деструктора)
	~base_deque()
	{
		node<T>* temp;
		while (begin && --_SIZE)
		{
			temp = begin;
			begin = begin->next;
			delete temp;
		}
		delete[] data;
		std::cout << "\nСработал деструктор...\n";
	}
};
template <class T>
class deque_list : public base_deque<T> // Создание наследственного класса от base_deque
{
public:
	// Конструктор без параметров
	explicit deque_list()
	{
		this->begin = NULL;
		this->end = NULL;
		this->_SIZE = 0;
		this->_MAXSIZE = 5;
	}
	// Конструктор с 1 параметром
	explicit deque_list(const int SIZE)
	{
		int i = 0;
		this->begin = NULL;
		this->end = NULL;
		while (i < SIZE)
		{
			node<T>* temp = new node<T>;
			std::cout << "Введите " << i + 1 << " элемент дека: ";
			std::cin >> temp->DATA;
			std::cout << "\n";
			temp->next = this->begin;
			temp->prev = this->end;
			if (this->end)
			{
				this->end->next = temp;
			}
			else
			{
				this->begin = temp;
			}
			this->end = temp;
			i++;
		}
		this->_SIZE = 0;
		this->_MAXSIZE = 10;
	}
	// Метод добавления элемента в конец дека
	virtual void push_front(T dat)
	{
		node<T>* temp = new node<T>;
		this->_SIZE++;
		temp->DATA = dat;
		temp->prev = this->begin;
		temp->next = this->end;
		if (this->begin)
		{
			this->begin->prev = temp;
		}
		else
		{
			this->end = temp;
		}
		this->begin = temp;
	}
	// Метод добавления элемента в начало дека
	virtual void push_back(T dat)
	{
		node<T>* temp = new node<T>;
		this->_SIZE++;
		temp->DATA = dat;
		temp->prev = this->end;
		temp->next = this->begin;
		if (this->end)
		{
			this->end->next = temp;
		}
		else
		{
				this->begin = temp;
		}
		this->end = temp;
	}
	// Метод удаления последнего элемента в деке
	virtual void pop_front()
	{
		this->end = this->end->prev;
		delete this->end->next;
		this->end->next = new node<T>;
		this->end->next = this->begin;
		this->begin->prev = this->end;
		this->_SIZE--;
	}
	// Удаление всех данных из дека
	virtual void clear()
	{
		node<T>* temp;
		while (this->begin && --this->_SIZE)
		{
			temp = this->begin;
			this->begin = this->begin->next;
			delete temp;
		}
	}
	// Метод вывода последнего элемента дека
	T front()
	{
		T data;
		if (this->empty())
		{
			std::cout << "Дек пуст...\n";
			return data;
		}
		else
		{
			return this->begin->DATA;
		}
	}
};
template<class T>
class deque_arr : public base_deque<T>
{
public:
	// Конструктор без параметров
	explicit deque_arr()
	{
		this->_MAXSIZE = 5;
		this->data = new T[this->_MAXSIZE];
		this->_SIZE = 0;
	}
	// Конструктор с 1 параметром
	explicit deque_arr(const int SIZE)
	{
			size_t i = 0;
		this->_MAXSIZE = SIZE;
		this->data = new T[SIZE];
		this->_SIZE = 0;
	}
	// Метод добавления элемента в конец дека
	virtual void push_front(T dat)
	{
		size_t i = 0;
		if (this->full())
			std::cout << "Невозможно добавление новых данных (дек заполнен)...\n";
		else
		{
			this->data[++this->_SIZE - 1] = dat;
		}
	}
	// Метод добавления элемента в начало дека
	virtual void push_back(T dat)
	{
		size_t i;
		T temp;
		if (this->full())
		{
			std::cout << "Невозможно добавление новых данных (дек заполнен)...\n";
				return;
		}
		else
		{
			this->_SIZE++;
			i = this->_SIZE - 1;
			for (i; i > 0; --i)
			{
				this->data[i] = this->data[i - 1];
			}
			this->data[0] = dat;
		}
	}
	// Метод удаления последнего элемента в деке
	virtual void pop_front()
	{
		int i = 0;
		std::string null = "0";
		for (i; i < this->_SIZE - 1; ++i)
			this->data[i] = this->data[i + 1];
		this->_SIZE--;
	}
	// Удаление всех данных из дека
	virtual void clear()
	{
			delete[] this->data;
		this->data = new T[this->_MAXSIZE];
		this->_SIZE = 0;
	}
	// Метод вывода последнего элемента дека
	T front()
	{
		if (this->empty())
		{
			std::cout << "Дек пуст...\n";
			return 0;
		}
		return this->data[this->_SIZE - 1];
	}
};
