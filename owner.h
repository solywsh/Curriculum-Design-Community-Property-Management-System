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
	int floor;//¥��
	int room_number;//����
	double area = 0;//��������ں����漰���㣬������ø�����
	int id;
	/*����ҵ���࣬�����࣬ά���඼��Ҫ����һ���ļ���Ϊ��ͳһ��������һ��id�ı���
		id��ҪΨһ�ԣ����ǲ�����¥��+������Ϊid�����֣�Ҳ�������Ĳ���*/

	//Ϊ���淽����㣬�涨,¥��Ϊ1 - 99֮����λ����, ����Ϊ1 - 9999֮��4λ����
public:
	void owner_set();
	void owner_print();//����������
	int owner_get_id();
	int owner_get_floor();
	char* owner_get_name();
	int owner_create_id(int x,int y);//¥�źͷ�������
	void owner_set_id(int id);
	double owner_get_area();
	void owner_set_name();
	void owner_set_sex();
	void owner_set_phone_number();
	void owner_set_area();
};

