#pragma once
#include "admin.h"

void admin::admin_set()
{
	char user_name[100];
	char password[100];
	cout << "��������������Ա���û���: ";
	cin >> user_name;
	cout << "����һ���µ�����: ";
	cin >> password;

	strcpy(this->user_name, user_name);
	strcpy(this->password, password);
	
	cout << "���óɹ�!�û���������Ϊ: " << endl;
	admin_print();

}

void admin::admin_print()
{
	cout << "user name: "<<user_name << endl;
	cout << "password: " << password << endl;
}

char* admin::admin_get_name(){
	return this->user_name;
}

char* admin::admin_get_password(){
	return this->password;
}

void admin::admin_set_password(char *pw){
	strcpy(this->password, pw);
}

void admin::admin_set_username(char* user)
{
	strcpy(this->user_name,user);
}
