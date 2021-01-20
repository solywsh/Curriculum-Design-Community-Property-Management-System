#pragma once
#include<iostream>
#include<string.h>
#include<windows.h>
using namespace std;
class announcement {
private:
	int Year, Month, Day, Hour, Minute, Second, DayOfWeek;
	char title[100];
	char content[100];
public:
	void announcement_set();
	void announcement_print();

	int announcement_get_year();
	int announcement_get_month();
	int announcement_get_day();
	int announcement_get_hour();
	int announcement_get_minute();
	int announcement_get_second();
	int announcement_get_week();

};

