#pragma once
#include<windows.h>
#include<iostream>
#include<string.h>
using namespace std;

class repair {
private:
	int id;
	int Year, Month, Day, Hour, Minute, Second, DayOfWeek;//����ʱ��
	/*
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wDayOfWeek ����һ����������
	*/
	char reason[100];//ά��ԭ��
	char situation[100];//ά�����
public:
	void repair_set(int id_p);
	void repair_print();
	int repair_get_id();
	void repair_set_id(int id_p);
	int repair_get_year();
	int repair_get_month();
	int repair_get_day();
	int repair_get_hour();
	int repair_get_minute();
	int repair_get_second();
	int repair_get_week();
};
