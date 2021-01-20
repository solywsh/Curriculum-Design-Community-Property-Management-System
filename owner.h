#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class sex_error {};

class owner {
private:
	char name[100];
	char sex[100];
	char phone_number[100];
	int floor;//楼号
	int room_number;//房号
	double area = 0;//面积，由于后面涉及计算，这里采用浮点数
	int id;
	/*由于业主类，费用类，维修类都需要建立一个文件，为了统一，设置了一个id的变量
		id需要唯一性，于是采用了楼号+房号作为id的数字，也方便后面的操作*/

	//为后面方便计算，规定,楼号为1 - 99之间两位数字, 房号为1 - 9999之间4位数字
public:
	void owner_set();
	void owner_print();//仅仅测试用
	int owner_get_id();
	int owner_get_floor();
	char* owner_get_name();
	int owner_create_id(int x,int y);//楼号和房号相连
	void owner_set_id(int id);
	double owner_get_area();
	void owner_set_name();
	void owner_set_sex();
	void owner_set_phone_number();
	void owner_set_area();
};

