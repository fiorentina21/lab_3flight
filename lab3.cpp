/* �10. ����������� ������� ���������� �������. */
#include <iostream>
#include <string>
#include "DateTime.h"
#include "Luggage.h"
#include "MyContainer.h"
#include <Windows.h>


/* ����� ������ */
void DropOff(MyContainer<Luggage> &storage) {
	Luggage luggage;

	cout << "����� ������" << endl;
	if (ReadLuggage(luggage) == true) {
		storage.Add(luggage);
		cout << "����� ������� ����." << endl;
	}
	else cout << "����� �� ��� ����." << endl;
}

/* �������� ����� */

void Claim(MyContainer<Luggage> &storage) {
	auto check = [](const Luggage &l1, const Luggage& l2) {
		return l1.owner.compare(l2.owner) == 0 && l1.flight == l2.flight;
	};

	Luggage luggage;
	int index;

	cout << "��������� ������" << endl << "������� ��� ���������: ";
	InputStr(luggage.owner);
	cout << "������� ����� �����: ";
	cin >> luggage.flight;
	cout << endl;

	index = storage.LinearSearch(check, luggage);

	if (index == -1) cout << "����� �� ������." << endl;
	else {
		cout << "����� �����: " << endl;

		ShowHeader();
		cout << endl;

		while (index != -1) {
			ShowLuggage(storage.GetElem(index));
			storage.RemoveInd(index);
			index = storage.LinearSearch(check, luggage);
		}

		cout << endl;
	}
}

/* �������� �������� � ������ (�����) */

void ViewAll(MyContainer<Luggage> &storage) {
	int ans;

	do {
		cout << "�������� � ������" << endl
			<< "1> �� ����� ���������" << endl
			<< "2> �� ������ �����" << endl
			<< "3> �� ������� �����������" << endl
			<< "0> �����" << endl
			<< ">";
	} while (!InputNum(ans) || ans < 0 || ans > 3);
	cout << endl;

	switch (ans)
	{
	case 0: return;
	case 1: storage.Sort([](const Luggage &l1, const Luggage &l2) { return l1.owner.compare(l2.owner) == -1; }); break;
	case 2: storage.Sort([](const Luggage &l1, const Luggage &l2) { return l1.flight < l2.flight; }); break;
	case 3: storage.Sort([](const Luggage &l1, const Luggage &l2) { return CompareDateTime(l1.departure, l2.departure) == -1; }); break;
	}

	ShowHeader();
	cout << endl;

	auto count = storage.Count();
	if (count == 0) cout << "��������� �����." << endl;
	else for (int i = 0; i < count; i++) ShowLuggage(storage.GetElem(i));
	cout << endl;
}


/* ������ ����� (��������) */
void Confiscate(MyContainer<Luggage> &storage) {
	auto check = [](const Luggage &l1, const Luggage& l2) {
		return l1.owner.compare(l2.owner) == 0 && l1.flight == l2.flight;
	};

	Luggage luggage;
	int index;

	cout << "������� ������" << endl << "������� ��� ���������: ";
	InputStr(luggage.owner);
	cout << "������� ����� �����: ";
	cin >> luggage.flight;
	cout << endl;

	index = storage.LinearSearch(check, luggage);

	if (index == -1) cout << "����� �� ������." << endl;
	else {
		cout << "����� �����: " << endl;

		ShowHeader();
		cout << endl;
		while (index != -1) {
			ShowLuggage(storage.GetElem(index));
			storage.RemoveInd(index);
			index = storage.LinearSearch(check, luggage);
		}

		cout << endl;
	}
}

void Menu(MyContainer<Luggage> &storage) {
	int ans;

	while (true) {
		do {
			cout << "������� ���������� �������" << endl;
			cout << "�������� ����� �������:" << endl;
			cout << "1> ��������" << endl
				<< "2> ��������� ����������" << endl
				<< "0> �����" << endl
				<< ">";
		} while (!InputNum(ans) || ans < 0 || ans > 2);
		cout << endl;

		switch (ans) {
		case 0: return;
		case 1:
			do {
				cout << "1> ����� �����" << endl
					<< "2> �������� �����" << endl
					<< "0> �����" << endl
					<< ">";
			} while (!InputNum(ans) || ans < 0 || ans > 2);
			cout << endl;

			switch (ans) {
			case 1: DropOff(storage); break;
			case 2: Claim(storage); break;
			}

			break;
		case 2:
			do {
				cout << "1> ���������� � �������" << endl
					<< "2> ������ �����" << endl
					<< "0> �����" << endl
					<< ">";
			} while (!InputNum(ans) || ans < 0 || ans > 2);
			cout << endl;

			switch (ans) {
			case 1: ViewAll(storage); break;
			case 2: Confiscate(storage); break;
			}

			break;
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);

	MyContainer<Luggage> bank("Source.dat", LuggageFromFile, LuggageToFile);
	Menu(bank);


	return 0;
}