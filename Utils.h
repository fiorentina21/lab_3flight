
#pragma once
#include <fstream>
//������ ������������
bool InputQuery();

//���� ������
bool InputNum(int32_t &num);
bool InputNum(double &num);

//���������� ������ �� ��������� �����
std::string StrFromBin(std::fstream *f);

//������ ������ � �������� ����
void StrToBin(std::fstream *f, std::string str);

void ShowHeader();

void InputStr(std::string &str);