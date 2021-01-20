#pragma once
#include "owner.h"

void owner::owner_set() {
	char name[100];
	char phone_number[100];
	int floor;
	int room_number;
	double area = 0;
	int id;
	int sex_int;
	cout << "������ҵ��������: ";
	cin >> name; strcpy(this->name, name);
	cout << "��ѡ��ҵ���Ա��Ӧ����(1.��/2.Ů): ";
	while (true) {
		cin >> sex_int;
		try {
			if (sex_int == 1) {
				strcpy(this->sex, "��");
				break;
			}
			else {
				if (sex_int == 2) {
					strcpy(this->sex, "Ů");
					break;
				}
				else throw sex_error();
			}
		}
		catch (sex_error) {
			cout << "����������1��2��" << endl;
		}
	}
	cout << "������ҵ���ֻ���: ";
	cin >> phone_number; strcpy(this->phone_number, phone_number);
	cout << "������ҵ��¥��: ";
	cin >> floor; this->floor = floor;
	cout << "������ҵ������: ";
	cin >> room_number; this->room_number = room_number;
	cout << "������ҵ��סլ���(ƽ��): ";
	cin >> area; this->area = area;
	id = owner_create_id(floor, room_number);
	this->id = id;
	this->owner_print();
}
int owner::owner_create_id(int x, int y) {
	int ans;
	x *= 10;
	for (ans = y / 10; ans != 0; ans /= 10) {
		x *= 10;
	}
	return x + y;
}
int owner::owner_get_id() { 
	return this->id; 
}
void owner::owner_set_id(int id) {
	this->id = id;
}
void owner::owner_print() {
	cout << "================================================================================" << endl;
	cout << "����: " << name << endl;
	cout << "�Ա�: " << sex << endl;
	cout << "�绰: " << phone_number << endl;
	cout << "¥��#����: " << floor << "#" << room_number << endl;
	cout << "���: " << area << endl;
	cout << "ID: " << id << endl;
	cout << "================================================================================" << endl;
}
char* owner::owner_get_name() {
	return this->name;
}
void owner::owner_set_name() {
	char name[100];
	cout << "������ҵ��������: ";
	cin >> name; strcpy(this->name, name);
}
void owner::owner_set_sex() {
	int sex_int;
	cout << "================================================================================" << endl;
	cout << "��ѡ��ҵ���Ա��Ӧ����(1.��/2.Ů): ";
	while (true) {
		cin >> sex_int;
		try {
			if (sex_int == 1) {
				strcpy(this->sex, "��");
				break;
			}
			else {
				if (sex_int == 2) {
					strcpy(this->sex, "Ů");
					break;
				}
				else throw sex_error();
			}
		}
		catch (sex_error) {
			cout << "����������1��2��" << endl;
		}
	}
}
void owner::owner_set_phone_number() {
	char phone_number[100];
	cout << "������ҵ���ֻ���: ";
	cin >> phone_number; strcpy(this->phone_number, phone_number);
}
void owner::owner_set_area() {
	double area = 0;
	cout << "�����޸ĺ����ҵ��סլ���(ƽ��): ";
	cin >> area; this->area = area;
}
double owner::owner_get_area() {
	return this->area;
}
int owner::owner_get_floor() {
	return this->floor;
}