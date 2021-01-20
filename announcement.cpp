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
	//��ȡϵͳʱ��
	cout << "================================================================================" << endl;
	cout << "�����빫�����:";
	cin >> title;
	cout << "�����빫������: ";
	cin >> content;

	strcpy(this->title, title);
	strcpy(this->content, content);

	announcement_print();
}
void announcement::announcement_print()
{
	cout << "================================================================================" << endl;
	cout <<"����: "<<title << endl;
	cout << "����: "<<content << endl;
	cout << "ʱ��: " << Year << "��" << Month << "��" << Day << "��  "
		<< Hour << ":";
	if (Minute < 10) {
		cout << "0" << Minute;//С��10ʱ��һ
	}
	else
	{
		cout << Minute;
	}
	cout << "  ����";
	if (DayOfWeek == 1) { cout << "һ" << endl; }
	if (DayOfWeek == 2) { cout << "��" << endl; }
	if (DayOfWeek == 3) { cout << "��" << endl; }
	if (DayOfWeek == 4) { cout << "��" << endl; }
	if (DayOfWeek == 5) { cout << "��" << endl; }
	if (DayOfWeek == 6) { cout << "��" << endl; }
	if (DayOfWeek == 7) { cout << "��" << endl; }
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