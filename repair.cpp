#pragma once
#include "repair.h"
using namespace std;

void repair::repair_set(int id_p) {
	bool flag_bool = false;
	char reason[100];//维修原因
	char situation[100];//维修情况
	
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	/*int wYear, wMonth, wDay, wHour, wMinute, wSecond, wDayOfWeek;*/
	Year = sys.wYear; Month = sys.wMonth; Day = sys.wDay;
	Hour = sys.wHour; Minute = sys.wMinute; Second = sys.wSecond;
	DayOfWeek = sys.wDayOfWeek;
	//读取系统时间


	cout << "请输入维修原因: ";
	cin >> reason;

	cout << "请输入维修情况: ";
	cin >> situation;

	this->id = id_p;
	strcpy(this->reason, reason);
	strcpy(this->situation, situation);

	repair_print();
}
void repair::repair_print() {
	bool flag_bool = false;
	/*owner owner_project;
	doc doc_repair;

	owner_project = doc_repair.owner_find_by_id(id);
	cout << "姓名: " << owner_project.owner_get_name() << endl;*/
	/*int wYear, wMonth, wDay, wHour, wMinute, wSecond, wDayOfWeek;*/
	cout << "================================================================================" << endl;
	cout << "ID: " << id << endl;
	cout << "维修登记时间: " << Year << "年" << Month << "月" << Day << "日  "
		<< Hour << ":";
	if (Minute < 10){
		cout << "0" << Minute;//小于10时加一
	}
	else{
		cout << Minute;
	}
	cout << "  星期";
	if (DayOfWeek == 1) {cout << "一" << endl;}
	if (DayOfWeek == 2) {cout << "二" << endl;}
	if (DayOfWeek == 3) {cout << "三" << endl;}
	if (DayOfWeek == 4) {cout << "四" << endl;}
	if (DayOfWeek == 5) {cout << "五" << endl;}
	if (DayOfWeek == 6) {cout << "六" << endl;}
	if (DayOfWeek == 7) {cout << "日" << endl;}
	cout << "维修原因: " << reason << endl;
	cout << "维修状况: " << situation << endl;
	cout << "================================================================================" << endl;
	
}
int repair::repair_get_id()
{
	return this->id;
}
void repair::repair_set_id(int id_p) {
	this->id = id_p;
}
int repair::repair_get_year()
{
	return this->Year;
}
int repair::repair_get_month()
{
	return this->Month;
}
int repair::repair_get_day()
{
	return this->Day;
}
int repair::repair_get_hour()
{
	return this->Hour;
}
int repair::repair_get_minute()
{
	return this->Minute;
}
int repair::repair_get_second()
{
	return this->Minute;
}
int repair::repair_get_week()
{
	return this->DayOfWeek;
}
