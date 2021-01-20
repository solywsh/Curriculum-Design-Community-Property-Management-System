#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "owner.h"
#include "fee.h"
#include "repair.h"
#include "admin.h"
#include "announcement.h"
using namespace std;

class doc {
private:
	char owner_file_name[100] = "owner_infor.dat";
	char fee_file_name[100] = "fee_infor.dat";
	char unpaid_by_floor_name[100] = "unpaid_by_floor.dat";
	char unpaid_by_quarterly_name[100] = "unpaid_by_quarterly.dat";
	char repair_file_name[100] = "repair_infor.dat";
	char admin_file_name[100] = "admin_infor.dat";
	char announcement_file_name[100] = "announcement_infor.dat";
public:
	bool owner_write(owner &owner_p);
	bool owner_read_all(owner &owner_p);
	bool owner_rewrite(owner &owner_p);
	bool owner_delete(int id);
	owner owner_find_by_id(int id);

	
	bool fee_write(fee &fee_p);
	bool fee_real_all(fee &fee_p);
	bool fee_rewrite(fee& fee_p);
	bool fee_delete(int id, int quarterly);
	fee fee_find_by_id_quarterly(int id,int quarterly);
	bool fee_find_by_id(int id);
	bool fee_find_one(int id);
	bool fee_statistics_read(int flag_int);
	bool fee_statistics_by_floor();//ע��ͳ�Ƶ���δ�ɷѵ�
	bool fee_statistics_by_quarterly();
	bool fee_unpaid_write(fee& fee_pp,int flag);//δ�ɷ�д��flag = 0ʱ����¥�ţ� flag = 1ʱ���ռ���
	bool fee_clean_unpaid(int flag);//���֮ǰ���ļ�


	bool repair_write(class repair &repair_p);//�⼸����class����Ϊ������������ʾ�ض��壬��ѯ���ϵó����޸ķ���
	bool repair_read_all(class repair& repair_p);
	bool repair_delete(int id_p,int year_p,int month_p,int day_p,int hour_p,int min_p);
	class repair repair_find_by_id(int id_p);//��������ҵ�һ��ʱ�ͻ�ֹͣ����
	bool repair_find(int id_p);//��������ҵ����к�������ʾ

	bool admin_write(admin& admin_p);
	char* admin_find(char* username_p);//�����û���������һ������
	bool admin_rewrite(admin& admin_p);

	bool announcement_write(announcement& announcement_p);
	bool announcement_read_all(announcement& announcement_p);
	bool announcement_delete(int year_p, int month_p, int day_p, int hour_p, int min_p);


};
