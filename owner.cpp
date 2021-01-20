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
	cout << "请输入业主的姓名: ";
	cin >> name; strcpy(this->name, name);
	cout << "请选择业主性别对应数字(1.男/2.女): ";
	while (true) {
		cin >> sex_int;
		try {
			if (sex_int == 1) {
				strcpy(this->sex, "男");
				break;
			}
			else {
				if (sex_int == 2) {
					strcpy(this->sex, "女");
					break;
				}
				else throw sex_error();
			}
		}
		catch (sex_error) {
			cout << "请输入数字1或2！" << endl;
		}
	}
	cout << "请输入业主手机号: ";
	cin >> phone_number; strcpy(this->phone_number, phone_number);
	cout << "请输入业主楼号: ";
	cin >> floor; this->floor = floor;
	cout << "请输入业主房号: ";
	cin >> room_number; this->room_number = room_number;
	cout << "请输入业主住宅面积(平方): ";
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
	cout << "姓名: " << name << endl;
	cout << "性别: " << sex << endl;
	cout << "电话: " << phone_number << endl;
	cout << "楼号#房号: " << floor << "#" << room_number << endl;
	cout << "面积: " << area << endl;
	cout << "ID: " << id << endl;
	cout << "================================================================================" << endl;
}
char* owner::owner_get_name() {
	return this->name;
}
void owner::owner_set_name() {
	char name[100];
	cout << "请输入业主的姓名: ";
	cin >> name; strcpy(this->name, name);
}
void owner::owner_set_sex() {
	int sex_int;
	cout << "================================================================================" << endl;
	cout << "请选择业主性别对应数字(1.男/2.女): ";
	while (true) {
		cin >> sex_int;
		try {
			if (sex_int == 1) {
				strcpy(this->sex, "男");
				break;
			}
			else {
				if (sex_int == 2) {
					strcpy(this->sex, "女");
					break;
				}
				else throw sex_error();
			}
		}
		catch (sex_error) {
			cout << "请输入数字1或2！" << endl;
		}
	}
}
void owner::owner_set_phone_number() {
	char phone_number[100];
	cout << "请输入业主手机号: ";
	cin >> phone_number; strcpy(this->phone_number, phone_number);
}
void owner::owner_set_area() {
	double area = 0;
	cout << "请输修改后的入业主住宅面积(平方): ";
	cin >> area; this->area = area;
}
double owner::owner_get_area() {
	return this->area;
}
int owner::owner_get_floor() {
	return this->floor;
}