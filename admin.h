#pragma once
#include <iostream>
#include<string.h>
using namespace std;
class admin {
private:
	char user_name[100];
	char password[100];
public:
	void admin_set();//ֻ�����ڵ�һ������
	void admin_print();
	char* admin_get_name();
	char* admin_get_password();
	void admin_set_password(char *pw);
	void admin_set_username(char* user);
};