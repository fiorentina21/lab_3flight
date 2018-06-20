#pragma once

#include <string>
#include <fstream>
#include "DateTime.h"

using namespace std;

// ��������� "�����"
struct Luggage {
	string owner; // passenger
	int32_t flight;
	DateTime departure;
	string destination;
	int32_t countOfPlaces;
	double_t totalWeight;
};

// ��������� �������� � ������ �� �������
bool ReadLuggage(Luggage&);

// ����� �� �������
void ShowLuggage(const Luggage&);

// ���������� �������� � ������ �� �����
bool LuggageFromFile(Luggage&, fstream*);

// ����� � ����
void LuggageToFile(const Luggage&, fstream*);