#include <iostream>
#include <random>
#include "deque.h"
#include <string>
#include <windows.h>
#define cls system("CLS")
#define pause system("PAUSE")
using namespace std;
// Прототип функции обработки алгоритма
template <class T>
void menu(base_deque<T>*);
string programMessage(); 
string userMessage(); // Прототип функции для моделирования сообщения от пользователя
int main()
{
	SetConsoleCP(1251); 
		SetConsoleOutputCP(1251); 
		char charMenu = 0; // Переменная меню
	base_deque<string>* arr; // Создание указателя дека на родительский класс
	do
	{
		cls;
		cout << "Введите тип дека:\n1 - векторная реализация\n2 - реализация списком\nВвод: ";
			cin >> charMenu;
		cls;
	} while (charMenu != '1' && charMenu != '2'); // Цикл выбора в меню
	switch (charMenu)
	{
	case '1':arr = new deque_arr<string>; menu(arr); delete arr; break; 
	case '2':arr = new deque_list<string>; menu(arr); delete arr; break;
	}
	
		return 0;
}
template <class T>
void menu(base_deque<T>* arr)
{
	bool menu; 
		char charMenu, exitProgramm = 0; 
		int chanceUser, chanceProgramm, chance; 
		string message, temp; 
		while (exitProgramm != 'e')
		{
			charMenu = 0;
			srand(time(0)); // Инициализация генератора случайных чисел
			chanceUser = rand() % 101; 
				chanceProgramm = 100 - chanceUser; 
				chance = rand() % 101; // Переменной будет присвоено случайно число от 0 до 100
			if (chanceUser >= chanceProgramm)
			{
				menu = (chanceProgramm >= chance) ? 0 : 1;
			}
			else
			{
				menu = (chanceUser >= chance) ? 1 : 0;
			}
			switch (menu)
			{
			case 0:
			{
				message = programMessage(); 
					cout << "От программы было передано сообщение \"" << message <<
					"\"\n";
				pause;
				if (!arr->full()) 
				{
					cls;
					cout << "В дек будет помещено сообщение от программы \"" <<	message << "\"\n";
					pause;
					arr->push_front(message); // Запись нового сообщения в дек
				}
				else
				{
						cls;
					temp = arr->front(); // Запоминание последнего сообщения из дека
					cout << "Дек заполнен...\nПоследнее сообщение из дека \"" <<
						temp << "\"\nВ дек будет помещено новое сообщение от программы \"" << message
						<< "\"\n";
					pause;
					do
					{
						cout << "\nУдалить все данные для очистка дека или удалить один элемент ? \n'a' - всё\n'o' - один\nВвод: ";
							cin >> charMenu;
						cls;
					} while (charMenu != 'a' && charMenu != 'o');
					switch (charMenu)
					{
					case 'a': arr->clear(); cout << "Дек очищен...\nБыло добавлено новое сообщение от программы \"" << message << "\"\n"; arr -> push_front(message); break; // Очищение дека + запись нового сообщения от программы
					case 'o': arr->pop_front(); cout << "Сообщение \"" << temp <<
						"\" удалено из дека\nВместо него помещено новое\"" << message << "\"\n"; arr -> push_front(message); break; 
					}
				}
			}break;
			case 1:
			{
				message = userMessage(); 
					cout << "Было передано сообщение от пользователя \"" << message
					<< "\"\n";
				pause;
				if (!arr->full())
				{
					cls;
					cout << "В дек будет помещено сообщение от пользователя \""
						<< message << "\"\n";
					pause;
					arr->push_back(message); 
				}
				else
				{
					cls;
					temp = arr->front(); // Запоминание последнего сообщения из дека
					cout << "Дек заполнен...\nПоследнее сообщение из дека \"" <<
						temp << "\"\nВ дек будет помещено новое сообщение от пользователя \"" <<
						message << "\"\n";
					pause;
					do
					{
						cout << "\n\nУдалить все данные для очистка дека или удалить один элемент ? \n'a' - всё\n'o' - один\nВвод: ";
							cin >> charMenu;
						cls;
					} while (charMenu != 'a' && charMenu != 'o');
						switch (charMenu)
						{
						case 'a': arr->clear(); cout << "Дек очищен...\nБыло добавлено новое сообщение от программы \"" << message << "\"\n"; arr -> push_back(message); break; // Очистка дека и добавление нового сообщения от пользователя
						case 'o': arr->pop_front(); cout << "Сообщение \"" << temp <<
							"\" удалено из дека\nВместо него помещено новое\"" << message << "\"\n"; arr -> push_back(message); break; 
						}
				}
			}break;
			}
			cout << "\nВыйти из цикла?\nВведите \"e\", чтобы выйти...\n";
			cin >> exitProgramm;
		}
}
string userMessage() // Объявление функции генерации сообщения от пользователя
{
	int i = 1;
	int length = rand() % 10; 
	const std::string simv = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ1234567890"; 
		std::string message;
	srand(time(0)); // Инициализация генератора случайных чисел
	message = simv[rand() % simv.length()]; // Запись первого случайного символа
	for (i; i < length; ++i)
	{
		message += simv[rand() % simv.length()]; // Запись строки из случайных символов
	}
	return message;
}
