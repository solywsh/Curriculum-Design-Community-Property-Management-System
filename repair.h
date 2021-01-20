#pragma once
#include<windows.h>
#include<iostream>
#include<string.h>
using namespace std;

class repair {
private:
	int id;
	int Year, Month, Day, Hour, Minute, Second, DayOfWeek;//调用时间
	/*
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wDayOfWeek 返回一个整型数字
	*/
	char reason[100];//维修原因
	char situation[100];//维修情况
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
