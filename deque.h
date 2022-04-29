#pragma once
#include "iostream"
#include "windows.h"
// ���������� ����������� ������
template <class T>
struct node
{
	T DATA; // ��������� �� ������������
	node* next, * prev; // ��������� �� ��������� � ���������� �������
};
// ������� ��������� �����, ���������� � ���� ��� ������ � ���� ����
template <class T>
class base_deque
{
protected:
	node<T>* begin, * end; // ���������� ������ � ����� ����
	int _SIZE, _MAXSIZE; // _SIZE - ������� ���������� �������, _MAXSIZE - ������������ ���������� ������� � ����
		T* data;
public:
	// ����� ���������� �������� � ����� ����, ��������� ������ ������������� ������
	virtual void push_front(T dat)
	{
		std::cout << "\n������� �����!";
	}
	// ����� ���������� �������� � ������ ����, ��������� ������ ������������� ������
	virtual void push_back(T dat)
	{
		std::cout << "\n������� �����!";
	}
	// ����� �������� �������� � ����� ����, ��������� ������ ������������� ������
	virtual void pop_front()
	{
		std::cout << "\n������� �����!";
	}
	// ����� �������� ���� ������ ����, ��������� ������ ������������� ������
	virtual void clear()
	{
		std::cout << "\n������� �����!";
	}
	// ����� �������� �� ������� ����, ��������� ������������� � �������� �������
	bool empty()
	{
		return (this->_SIZE == 0) ? 1 : 0;
	}
	// ����� �������� �� ������������ ����, ��������� ������������� � �������� �������
	bool full()
	{
		return (_SIZE == _MAXSIZE) ? 1 : 0;
	}
	// ����� ������ ���������� ������� � ����, ��������� ������������� � �������� �������
	int size()
	{
		return _SIZE;
	}

		int maxsize()
	{
		return _MAXSIZE;
	}
	// ����� ������ ���������� �������� ����, ��������� ������ ������������� ������
	virtual T front()
	{
		T dat;
		std::cout << "\n������� �����!";
		return dat;
	}
	// ������� ������ (������ �����������)
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
		std::cout << "\n�������� ����������...\n";
	}
};
template <class T>
class deque_list : public base_deque<T> // �������� ��������������� ������ �� base_deque
{
public:
	// ����������� ��� ����������
	explicit deque_list()
	{
		this->begin = NULL;
		this->end = NULL;
		this->_SIZE = 0;
		this->_MAXSIZE = 5;
	}
	// ����������� � 1 ����������
	explicit deque_list(const int SIZE)
	{
		int i = 0;
		this->begin = NULL;
		this->end = NULL;
		while (i < SIZE)
		{
			node<T>* temp = new node<T>;
			std::cout << "������� " << i + 1 << " ������� ����: ";
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
	// ����� ���������� �������� � ����� ����
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
	// ����� ���������� �������� � ������ ����
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
	// ����� �������� ���������� �������� � ����
	virtual void pop_front()
	{
		this->end = this->end->prev;
		delete this->end->next;
		this->end->next = new node<T>;
		this->end->next = this->begin;
		this->begin->prev = this->end;
		this->_SIZE--;
	}
	// �������� ���� ������ �� ����
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
	// ����� ������ ���������� �������� ����
	T front()
	{
		T data;
		if (this->empty())
		{
			std::cout << "��� ����...\n";
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
	// ����������� ��� ����������
	explicit deque_arr()
	{
		this->_MAXSIZE = 5;
		this->data = new T[this->_MAXSIZE];
		this->_SIZE = 0;
	}
	// ����������� � 1 ����������
	explicit deque_arr(const int SIZE)
	{
			size_t i = 0;
		this->_MAXSIZE = SIZE;
		this->data = new T[SIZE];
		this->_SIZE = 0;
	}
	// ����� ���������� �������� � ����� ����
	virtual void push_front(T dat)
	{
		size_t i = 0;
		if (this->full())
			std::cout << "���������� ���������� ����� ������ (��� ��������)...\n";
		else
		{
			this->data[++this->_SIZE - 1] = dat;
		}
	}
	// ����� ���������� �������� � ������ ����
	virtual void push_back(T dat)
	{
		size_t i;
		T temp;
		if (this->full())
		{
			std::cout << "���������� ���������� ����� ������ (��� ��������)...\n";
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
	// ����� �������� ���������� �������� � ����
	virtual void pop_front()
	{
		int i = 0;
		std::string null = "0";
		for (i; i < this->_SIZE - 1; ++i)
			this->data[i] = this->data[i + 1];
		this->_SIZE--;
	}
	// �������� ���� ������ �� ����
	virtual void clear()
	{
			delete[] this->data;
		this->data = new T[this->_MAXSIZE];
		this->_SIZE = 0;
	}
	// ����� ������ ���������� �������� ����
	T front()
	{
		if (this->empty())
		{
			std::cout << "��� ����...\n";
			return 0;
		}
		return this->data[this->_SIZE - 1];
	}
};
