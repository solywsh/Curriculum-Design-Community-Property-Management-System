#pragma once
#include "admin.h"

void admin::admin_set()
{
	char user_name[100];
	char password[100];
	cout << "请输入新增管理员的用户名: ";
	cin >> user_name;
	cout << "设置一个新的密码: ";
	cin >> password;

	strcpy(this->user_name, user_name);
	strcpy(this->password, password);
	
	cout << "设置成功!用户名和密码为: " << endl;
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
