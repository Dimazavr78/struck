#pragma once
#include "iostream"
#include "string"
#include "random" // ����������� ���������� ��� ������������� ��������� �����/����
std::string programMessage() // ������� ������������� ���������� ��������� �� ���������
{
	int i = 1;
	int length = rand() % 10; // ������������� ��������� ����� ������ (������������ ����� ������ 10)
	const std::string simv = "�����Ũ��������������������������1234567890";
	// ��� ��������� �������
	
std::string message;
	srand(time(0)); // ������������� ���������� ��������� �����
	message = simv[rand() % simv.length()]; // ������ ������� ���������� �������
	for (i; i < length; ++i)
	{
		message += simv[rand() % simv.length()]; // ������ ������ �� ��������� ��������
	}
	return message;
}