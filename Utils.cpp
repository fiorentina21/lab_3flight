#include <iostream>
#include <iomanip>
#include <string>
#include "Utils.h"

//������ ������������
bool InputQuery() {
	char c;
	do {
		std::cout << "Y/N? ";
		std::cin >> c;
	} while (c != 'n' && c != 'N' && c != 'y' && c != 'Y');
	return c == 'Y' || c == 'y';
}

//���� ������
bool InputNum(double & num) {
	std::cin >> num;
	bool OK = std::cin.good();
	std::cin.clear();
	/*������� ������������� ������������ ��� ��������
	(������������/�������) �������� �� ������� ������.
	� ������ ����� ���� ����� ������, � ������� �� ������ �������.
	�� ���������� � ����, ������� ������� rdbuf().
	� ����� ��������� ���� ����� �����, ������� �������� � ��� ����������.
	��������� � �� ����� ��� ������, �� �������� ������� in_avail()
	����� ������. ��� ���������� �������� ��� � ����� ���������������*/
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return OK;
}

bool InputNum(int32_t &num) {
	std::cin >> num;
	bool OK = std::cin.good();
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return OK;
}

//���������� ������ �� ��������� �����
std::string StrFromBin(std::fstream *f) {
	std::string result;
	int32_t len;
	if (!f->read(reinterpret_cast<char*>(&len), sizeof(len))) {
		return "";
	}
	char *buf = new char[len];
	if (!f->read(buf, len)) {
		return "";
	}
	result = buf;
	delete[] buf;
	return result;
}

//������ ������ � �������� ����
void StrToBin(std::fstream *f, std::string str) {
	int32_t len = str.length() + 1;
	f->write(reinterpret_cast<char*>(&len), sizeof(len));
	f->write(str.c_str(), len);
}

void ShowHeader() {
	std::cout << std::setw(25) << std::left << "��������:"
		<< std::setw(8) << std::left << "����:"
		<< std::setw(20) << std::left << "�����������:"
		<< std::setw(15) << std::left << "����������:"
		<< std::setw(15) << std::left << "���-�� ����:"
		<< std::setw(5) << std::left << "��� ������:";
}


void InputStr(std::string &str) {
	std::getline(std::cin, str);
}