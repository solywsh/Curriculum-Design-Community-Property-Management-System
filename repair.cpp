#pragma once
#include "repair.h"
using namespace std;

void repair::repair_set(int id_p) {
	bool flag_bool = false;
	char reason[100];//ά��ԭ��
	char situation[100];//ά�����
	
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	/*int wYear, wMonth, wDay, wHour, wMinute, wSecond, wDayOfWeek;*/
	Year = sys.wYear; Month = sys.wMonth; Day = sys.wDay;
	Hour = sys.wHour; Minute = sys.wMinute; Second = sys.wSecond;
	DayOfWeek = sys.wDayOfWeek;
	//��ȡϵͳʱ��


	cout << "������ά��ԭ��: ";
	cin >> reason;

	cout << "������ά�����: ";
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
	cout << "����: " << owner_project.owner_get_name() << endl;*/
	/*int wYear, wMonth, wDay, wHour, wMinute, wSecond, wDayOfWeek;*/
	cout << "================================================================================" << endl;
	cout << "ID: " << id << endl;
	cout << "ά�޵Ǽ�ʱ��: " << Year << "��" << Month << "��" << Day << "��  "
		<< Hour << ":";
	if (Minute < 10){
		cout << "0" << Minute;//С��10ʱ��һ
	}
	else{
		cout << Minute;
	}
	cout << "  ����";
	if (DayOfWeek == 1) {cout << "һ" << endl;}
	if (DayOfWeek == 2) {cout << "��" << endl;}
	if (DayOfWeek == 3) {cout << "��" << endl;}
	if (DayOfWeek == 4) {cout << "��" << endl;}
	if (DayOfWeek == 5) {cout << "��" << endl;}
	if (DayOfWeek == 6) {cout << "��" << endl;}
	if (DayOfWeek == 7) {cout << "��" << endl;}
	cout << "ά��ԭ��: " << reason << endl;
	cout << "ά��״��: " << situation << endl;
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
