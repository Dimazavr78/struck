#pragma once
#include "iostream"
#include "string"
#include "random" // Подключение библиотеки для генерирования случайных чисел/стро
std::string programMessage() // Функция моделирования случайного сообщения от программы
{
	int i = 1;
	int length = rand() % 10; // Генерирование случайной длины строки (максимальная длина строки 10)
	const std::string simv = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ1234567890";
	// Все случайные символы
	
std::string message;
	srand(time(0)); // Инициализация генератора случайных чисел
	message = simv[rand() % simv.length()]; // Запись первого случайного символа
	for (i; i < length; ++i)
	{
		message += simv[rand() % simv.length()]; // Запись строки из случайных символов
	}
	return message;
}