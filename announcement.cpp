#pragma once
#include "announcement.h"
void announcement::announcement_set(){
	char title[100];
	char content[100];
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	/*int wYear, wMonth, wDay, wHour, wMinute, wSecond, wDayOfWeek;*/
	Year = sys.wYear; Month = sys.wMonth; Day = sys.wDay;
	Hour = sys.wHour; Minute = sys.wMinute; Second = sys.wSecond;
	DayOfWeek = sys.wDayOfWeek;
	//读取系统时间
	cout << "================================================================================" << endl;
	cout << "请输入公告标题:";
	cin >> title;
	cout << "请输入公告内容: ";
	cin >> content;

	strcpy(this->title, title);
	strcpy(this->content, content);

	announcement_print();
}
void announcement::announcement_print()
{
	cout << "================================================================================" << endl;
	cout <<"标题: "<<title << endl;
	cout << "内容: "<<content << endl;
	cout << "时间: " << Year << "年" << Month << "月" << Day << "日  "
		<< Hour << ":";
	if (Minute < 10) {
		cout << "0" << Minute;//小于10时加一
	}
	else
	{
		cout << Minute;
	}
	cout << "  星期";
	if (DayOfWeek == 1) { cout << "一" << endl; }
	if (DayOfWeek == 2) { cout << "二" << endl; }
	if (DayOfWeek == 3) { cout << "三" << endl; }
	if (DayOfWeek == 4) { cout << "四" << endl; }
	if (DayOfWeek == 5) { cout << "五" << endl; }
	if (DayOfWeek == 6) { cout << "六" << endl; }
	if (DayOfWeek == 7) { cout << "日" << endl; }
	cout << "================================================================================" << endl;
	system("pause");
}

int announcement::announcement_get_year()
{
	return this->Year;
}
int announcement::announcement_get_month()
{
	return this->Month;
}
int announcement::announcement_get_day()
{
	return this->Day;
}
int announcement::announcement_get_hour()
{
	return this->Hour;
}
int announcement::announcement_get_minute()
{
	return this->Minute;
}
int announcement::announcement_get_second()
{
	return this->Minute;
}
int announcement::announcement_get_week()
{
	return this->DayOfWeek;
}