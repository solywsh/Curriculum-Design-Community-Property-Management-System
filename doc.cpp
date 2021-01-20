#pragma once
#include "doc.h"

bool doc::owner_write(owner& owner_p) {
	fstream datafile;
	//���ļ�
	datafile.open(owner_file_name, ios::in | ios::out);
	//���ļ�ָ���ƶ���ĩβ
	datafile.seekp(0, ios::end);
	//д������
	datafile.write((char*)&owner_p, sizeof(class owner));
	//�ر�
	datafile.close();
	return true;
}
bool doc::owner_read_all(owner& owner_p) {
	fstream datafile;
	datafile.open(owner_file_name, ios::in | ios::out);
	datafile.seekg(0, ios::end);//��¼ĩβλ��
	long poEnd = datafile.tellg();//ĩβλ�ø�ֵ
	datafile.seekg(0, ios::beg);//��ת����ʼ
	if (datafile.tellg() == poEnd)
	{
		cout << "================================================================================" << endl;
		cout << "=                                �ļ���û����Ϣ��                              ="<<endl;
		cout << "================================================================================" << endl;
		
	}
	while (datafile.tellg() != poEnd) {
		datafile.read((char*)&owner_p, sizeof(class owner));
		owner_p.owner_print();
	}
	datafile.close();
	system("pause");
	return true;
}
bool doc::owner_rewrite(owner& owner_p) {
	int id;
	id = owner_p.owner_get_id();
	owner owner_pw[40];
	int i = 0, j = 0;
	fstream datafile;
	datafile.open(owner_file_name, ios::in | ios::out);
	datafile.seekg(0, ios::end);
	long poEnd = datafile.tellg();
	datafile.seekg(0, ios::beg);
	while (datafile.tellg() != poEnd) {
		datafile.read((char*)&owner_pw[i], sizeof(owner));
		i++;
	}
	datafile.close();//���������ݶ�ȡ

	datafile.open(owner_file_name, ios::in | ios::out | ios::trunc);//���ļ������ԭ��������
	datafile.seekg(0, ios::beg);
	while (j != i) {
		if (owner_pw[j].owner_get_id() != id) {
			datafile.write((char*)&owner_pw[j], sizeof(class owner));//��������ھ�д��	
		}
		else datafile.write((char*)&owner_p, sizeof(class owner));
		j++;
	}
	datafile.close();//���������ݶ�ȡ
	return true;

} 
bool doc::owner_delete(int id) {
	owner owner_p[40];
	int i = 0,j =0;
	fstream datafile;
	datafile.open(owner_file_name, ios::in | ios::out);
	datafile.seekg(0, ios::end);
	long poEnd = datafile.tellg();
	datafile.seekg(0, ios::beg);
	while (datafile.tellg() != poEnd) {
		datafile.read((char*)&owner_p[i], sizeof(owner));
		i++;
	}
	datafile.close();//���������ݶ�ȡ

	datafile.open(owner_file_name, ios::in | ios::out |ios::trunc);//���ļ������ԭ��������
	datafile.seekg(0, ios::beg);
	while (j != i){
		if (owner_p[j].owner_get_id() != id) {
			datafile.write((char*)&owner_p[j], sizeof(class owner));//��������ھ�д��	
		}
		j++;
	}
	datafile.close();//���������ݶ�ȡ
	return true;

}
owner doc::owner_find_by_id(int id) {
	owner owner_p;
	int flag = 0;//�û�������
	fstream iof;
	iof.open(owner_file_name, ios::in | ios::out);
	iof.seekg(0, ios::end);
	long poEnd = iof.tellg();
	iof.seekg(0, ios::beg);
	while (iof.tellg() != poEnd) {
		iof.read((char*)&owner_p, sizeof(owner));
		if (owner_p.owner_get_id() == id) {//�ҵ���,����
			flag = 1;//����
			break;
		}
	}
	//������û�ҵ�
	if (flag == 0) {
		owner_p.owner_set_id(0);
	}
	iof.close();
	return owner_p;
}

bool doc::fee_write(fee& fee_p){
	fstream datafile;
	datafile.open(fee_file_name, ios::in | ios::out);
	datafile.seekp(0, ios::end);
	datafile.write((char*)&fee_p, sizeof(class fee));
	datafile.close();
	return true;
}
bool doc::fee_real_all(fee& fee_p) {
	int id;
	fstream datafile;
	datafile.open(fee_file_name, ios::in | ios::out);
	datafile.seekg(0, ios::end);//��¼ĩβλ��
	long poEnd = datafile.tellg();//ĩβλ�ø�ֵ
	datafile.seekg(0, ios::beg);//��ת����ʼ
	if (datafile.tellg() == poEnd)
	{
		cout << "================================================================================" << endl;
		cout << "�ļ���û����Ϣ��" << endl;
	}

	while (datafile.tellg() != poEnd) {
		datafile.read((char*)&fee_p, sizeof(class fee));
		id = fee_p.fee_get_id();
		cout << "================================================================================" << endl;
		cout << owner_find_by_id(id).owner_get_name() << "�ķ�����Ϣ:" << endl;
		fee_p.fee_print();
	}
	datafile.close();
	system("pause");
	return true;
}
bool doc::fee_rewrite(fee& fee_p) {
	bool tag = false;
	fee old;
	fstream datafile;
	datafile.open(fee_file_name, ios::in | ios::out);
	datafile.seekp(0, ios::end);
	long poEnd = datafile.tellp();
	datafile.seekp(0, ios::beg);
	while (datafile.tellp() != poEnd) {
		datafile.read((char*)&old, sizeof(class fee));
		if (old.fee_get_id() == fee_p.fee_get_id() && old.fee_get_quarterly()== fee_p.fee_get_quarterly()) {
			datafile.seekp(-sizeof(class fee), ios::cur);
			datafile.write((char*)&fee_p, sizeof(fee));
			tag = true;
			break;
		}
	}
	datafile.close();
	return tag;
}
bool doc::fee_delete(int id_p, int quarterly_p){
	fee fee_p[40];
	int i = 0, j = 0;
	fstream datafile;
	datafile.open(fee_file_name, ios::in | ios::out);
	datafile.seekg(0, ios::end);
	long poEnd = datafile.tellg();
	datafile.seekg(0, ios::beg);
	while (datafile.tellg() != poEnd) {
		datafile.read((char*)&fee_p[i], sizeof(class fee));
		i++;
	}
	datafile.close();

	datafile.open(fee_file_name, ios::in | ios::out | ios::trunc);//���ļ������ԭ��������
	datafile.seekg(0, ios::beg);
	while (j != i) {
		if (fee_p[j].fee_get_id() != id_p || fee_p[j].fee_get_quarterly() != quarterly_p) {
			datafile.write((char*)&fee_p[j], sizeof(class fee));//��������ھ�д��	
		}
		j++;
	}
	datafile.close();
	return true;
}
bool doc::fee_find_by_id(int id) {
	fee fee_p;
	bool flag = false;
	fstream iof;
	iof.open(fee_file_name, ios::in | ios::out);
	iof.seekg(0, ios::end);
	long poEnd = iof.tellg();
	iof.seekg(0, ios::beg);
	while (iof.tellg() != poEnd) {
		iof.read((char*)&fee_p, sizeof(fee));
		if (fee_p.fee_get_id() == id) {
			flag = true;
			break;
		}
	}
	iof.close();
	
	return flag;
}
bool doc::fee_find_one(int id) {//��β���ͬһid��ҵ���ɷ���Ϣ
	fee fee_p;
	bool flag = false;
	fstream dataflie;
	dataflie.open(fee_file_name, ios::in | ios::out);
	dataflie.seekg(0, ios::end);
	long poEnd = dataflie.tellg();
	dataflie.seekg(0, ios::beg);

	while (dataflie.tellg() != poEnd) {
		dataflie.read((char*)&fee_p, sizeof(class fee));
		if (fee_p.fee_get_id() == id) {
			fee_p.fee_print();
			system("pause");
			flag = true;
		}
	}
	dataflie.close();
	return flag;
}

bool doc::fee_statistics_read(int flag_int)
{
	int id;
	fee fee_p;
	fstream datafile;
	if (flag_int==1)
	{
		datafile.open(unpaid_by_floor_name, ios::in | ios::out);
	}
	else datafile.open(unpaid_by_quarterly_name, ios::in | ios::out);
	datafile.seekg(0, ios::end);//
	long poEnd = datafile.tellg();//ĩβλ�ø�ֵ��¼ĩβλ��
	datafile.seekg(0, ios::beg);//��ת����ʼ
	if (datafile.tellg() == poEnd)
	{
		cout << "================================================================================" << endl;
		cout << "�ļ���û����Ϣ��" << endl;
	}

	while (datafile.tellg() != poEnd) {
		datafile.read((char*)&fee_p, sizeof(class fee));
		id = fee_p.fee_get_id();
		cout << "================================================================================" << endl;
		cout << owner_find_by_id(id).owner_get_name() << "�ķ�����Ϣ:" << endl;
		fee_p.fee_print();
	}
	datafile.close();
	system("pause");
	return true;
}
bool doc::fee_statistics_by_floor() {
	int id, floor, i = 1;
	int write_type = 0;//����д������
	fee fee_p;
	owner owner_object;
	bool flag = false, flag_while = true;
	fstream iof;
	iof.open(fee_file_name, ios::in | ios::out);
	iof.seekg(0, ios::end);
	long poEnd = iof.tellg();
	iof.seekg(0, ios::beg);
	while (flag_while) {
		iof.read((char*)&fee_p, sizeof(fee));//��ͷ��ʼ��ȡ
		id = fee_p.fee_get_id();//ȡ�������id
		owner_object = owner_find_by_id(id);//�÷������idȥ�ҵ�ҵ������Ӧ�Ķ���
		floor = owner_object.owner_get_floor();//�ҵ�ҵ�����¥��
		if (fee_p.fee_get_paid());
		else{
			if (floor == i) {
				cout << floor << "��¥" << owner_object.owner_get_name() << "�ķ�����Ϣ: " << endl;
				fee_p.fee_print();
				system("pause");
				flag = fee_unpaid_write(fee_p, write_type);
			}
		}
		
		if (iof.tellg() == poEnd)//��һ���ֻص�����
		{
			i++;
			iof.seekg(0, ios::beg);//�ص���ʼ
		}
		if (i == 99)//�涨¥�����Ϊ99
		{
			flag_while = false;//��99����
			flag = true;
		}
	}
	iof.close();

	return flag;
}
bool doc::fee_statistics_by_quarterly() {
	int id, i = 1, quarterly;
	int write_type = 1;
	fee fee_p;
	owner owner_object;
	bool flag = false, flag_while = true;
	fstream iof;
	iof.open(fee_file_name, ios::in | ios::out);
	iof.seekg(0, ios::end);
	long poEnd = iof.tellg();
	iof.seekg(0, ios::beg);
	while (flag_while) {
		iof.read((char*)&fee_p, sizeof(fee));//��ͷ��ʼ��ȡ
		id = fee_p.fee_get_id();//ȡ�������id
		quarterly = fee_p.fee_get_quarterly();//ȡ������Ϣ
		owner_object = owner_find_by_id(id);//�÷������idȥ�ҵ�ҵ������Ӧ�Ķ���
		//floor = owner_object.owner_get_floor();�ҵ�ҵ�����¥��
		if (fee_p.fee_get_paid());//�����Ƿ�ɷѵ���Ϣ��δ�ɷѷ���false������ɷ�����
		else
		{
			if (quarterly == i) {
				cout << "��" << quarterly << "����" <<
					owner_object.owner_get_name() << "�ķ�����Ϣ: " << endl;
				fee_p.fee_print();
				system("pause");
				flag = fee_unpaid_write(fee_p, write_type);
			}
		}
		if (iof.tellg() == poEnd)//��һ���ֻص�����
		{
			i++;
			iof.seekg(0, ios::beg);//�ص���ʼ
		}
		if (i == 4)//һ��4������
		{
			flag_while = false;//��4����ѭ��
			flag = true;
		}
	}
	iof.close();

	return flag;


}
bool doc::fee_unpaid_write(fee& fee_pp, int flag) {
	fstream datafile;
	if (flag == 0 )
	{
		datafile.open(unpaid_by_floor_name, ios::in | ios::out);
	}
	else
	{
		datafile.open(unpaid_by_quarterly_name, ios::in | ios::out);
	}
	datafile.seekp(0, ios::end);
	datafile.write((char*)&fee_pp, sizeof(class fee));
	datafile.close();
	return true;
}
bool doc::fee_clean_unpaid(int flag)
{
	fstream datafile;
	if (flag == 1){
		datafile.open(unpaid_by_floor_name, ios::in | ios::out | ios::trunc);//����հ�¥����������
		datafile.close();
	}
	if (flag == 2 ){
		datafile.open(unpaid_by_quarterly_name, ios::in | ios::out | ios::trunc);//����հ�������������
		datafile.close();
	}
	if (flag == 3)
	{
		datafile.open(unpaid_by_floor_name, ios::in | ios::out | ios::trunc);
		datafile.close();

		datafile.open(unpaid_by_quarterly_name, ios::in | ios::out | ios::trunc);
		datafile.close();

	}
	return true;
}
fee doc::fee_find_by_id_quarterly(int id, int quarterly_p) {
	fee fee_p;
	int flag = 0;
	fstream iof;
	iof.open(fee_file_name, ios::in | ios::out);
	iof.seekg(0, ios::end);
	long poEnd = iof.tellg();
	iof.seekg(0, ios::beg);
	while (iof.tellg() != poEnd) {
		iof.read((char*)&fee_p, sizeof(class fee));
		if (fee_p.fee_get_id() == id && fee_p.fee_get_quarterly() == quarterly_p) {
			cout<<"���ļ��ҵ���"<<endl;
			system("pause");
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		fee_p.fee_set_id(0);
	}
	iof.close();
	return fee_p;
}

bool doc::repair_write(repair& repair_p) {
	fstream datafile;
	datafile.open(repair_file_name, ios::in | ios::out);
	datafile.seekp(0, ios::end);
	datafile.write((char*)&repair_p, sizeof(repair));
	datafile.close();
	return true;
}
bool doc::repair_read_all(repair& repair_p) {
	fstream datafile;
	datafile.open(repair_file_name, ios::in | ios::out);
	datafile.seekg(0, ios::end);//��¼ĩβλ��
	long poEnd = datafile.tellg();//ĩβλ�ø�ֵ
	datafile.seekg(0, ios::beg);//��ת����ʼ
	if (datafile.tellg() == poEnd)
	{
		cout << "================================================================================" << endl;
		cout << "�ļ���û����Ϣ��" << endl;
	}
	while (datafile.tellg() != poEnd) {
		datafile.read((char*)&repair_p, sizeof(class repair));
		repair_p.repair_print();
	}
	datafile.close();
	system("pause");
	return true;
}
bool doc::repair_delete(int id_p, int year_p, int month_p, int day_p, int hour_p, int min_p)
{
	bool flag_bool = false;
	repair repair_p[40];
	int i = 0, j = 0;
	fstream datafile;
	datafile.open(repair_file_name, ios::in | ios::out);
	datafile.seekg(0, ios::end);
	long poEnd = datafile.tellg();
	datafile.seekg(0, ios::beg);
	while (datafile.tellg() != poEnd) {
		datafile.read((char*)&repair_p[i], sizeof(repair));
		i++;
	}
	datafile.close();//���������ݶ�ȡ

	datafile.open(repair_file_name, ios::in | ios::out | ios::trunc);//���ļ������ԭ��������
	datafile.seekg(0, ios::beg);
	while (j != i) {
		if (repair_p[j].repair_get_id() != id_p|| repair_p[j].repair_get_year()!=year_p||
			repair_p[j].repair_get_month()!=month_p||repair_p[j].repair_get_day()!=day_p|| 
			repair_p[j].repair_get_hour() != hour_p || repair_p[j].repair_get_minute()!= min_p) {
			datafile.write((char*)&repair_p[j], sizeof(class repair));//��������ھ�д��
		}
		else flag_bool = true;//ֻ�г����������������ϵ�ʱ��˵���ҵ���Ӧ���ݣ���д���� 
		j++;
	}

	datafile.close();//���������ݶ�ȡ
	return flag_bool;
}
repair doc::repair_find_by_id(int id_p)
{
	repair repair_p;
	int flag = 0;//�û�������
	fstream iof;
	iof.open(repair_file_name, ios::in | ios::out);
	iof.seekg(0, ios::end);
	long poEnd = iof.tellg();
	iof.seekg(0, ios::beg);
	while (iof.tellg() != poEnd) {
		iof.read((char*)&repair_p, sizeof(class repair));
		if (repair_p.repair_get_id() == id_p) {//�ҵ���,����
			flag = 1;//����
			break;
		}
	}
	//������û�ҵ�
	if (flag == 0) {
		repair_p.repair_set_id(0);
	}
	iof.close();
	return repair_p;
}
bool doc::repair_find(int id_p) {
	int i = 0;
	repair repair_p;
	bool flag_bool = false;//�û�������
	fstream iof;
	iof.open(repair_file_name, ios::in | ios::out);
	iof.seekg(0, ios::end);
	long poEnd = iof.tellg();
	iof.seekg(0, ios::beg);
	while (true) {
		if (iof.eof())break;
		iof.read((char*)&repair_p, sizeof(class owner));
		if (repair_p.repair_get_id() == id_p) {//�ҵ���,����
			flag_bool = true;//����
			repair_p.repair_print();
			i++;
		}
	}
	if (flag_bool)
	{
		cout << "================================================================================" << endl;
		cout << "���ҵ�����" << i << "����Ϣ��" << endl;
	}
	else cout << "δ�ҵ���Ϣ��" << endl;
	system("pause");
	iof.close();
	return flag_bool;
}

bool doc::admin_write(admin& admin_p) {
	fstream datafile;
	datafile.open(admin_file_name, ios::in | ios::out );
	datafile.seekp(0, ios::end);
	datafile.write((char*)&admin_p, sizeof(admin));
	datafile.close();
	return true;

}
char* doc::admin_find(char* username_p) {
	admin admin_p;
	fstream iof;
	char passoword_p[100];
	iof.open(admin_file_name, ios::in | ios::out);
	iof.seekg(0, ios::end);
	long poEnd = iof.tellg();
	iof.seekg(0, ios::beg);

	while (iof.tellg() != poEnd) {
		iof.read((char*)&admin_p, sizeof(admin));
		//strcmp()�����ַ����Ƚϣ������ͬ���򷵻�0
		if (strcmp(admin_p.admin_get_name(),username_p) == 0 ) {//�ҵ���,����
			strcpy(passoword_p, admin_p.admin_get_password());
			break;
		}
	}
	iof.close();
	return passoword_p;
}
bool doc::admin_rewrite(admin& admin_p)
{
	fstream datafile;
	datafile.open(admin_file_name, ios::in | ios::out );
	datafile.seekp(0, ios::beg);
	datafile.write((char*)&admin_p, sizeof(admin));
	datafile.close();
	return true;
}

bool doc::announcement_write(announcement& announcement_p){
	fstream datafile;
	datafile.open(announcement_file_name, ios::in | ios::out);
	datafile.seekp(0, ios::end);
	datafile.write((char*)&announcement_p, sizeof(announcement));
	datafile.close();
	return true;
}
bool doc::announcement_read_all(announcement& announcement_p){
	fstream datafile;
	datafile.open(announcement_file_name, ios::in | ios::out);
	datafile.seekg(0, ios::end);//��¼ĩβλ��
	long poEnd = datafile.tellg();//ĩβλ�ø�ֵ
	datafile.seekg(0, ios::beg);//��ת����ʼ
	if (datafile.tellg() == poEnd)
	{
		cout << "================================================================================" << endl;
		cout << "�ļ���û����Ϣ��" << endl;
		system("pause");
		
	}
	while (datafile.tellg() != poEnd) {
		datafile.read((char*)&announcement_p, sizeof(class announcement));
		announcement_p.announcement_print();

	}
	datafile.close();
	
	return true;
}
bool doc::announcement_delete(int year_p, int month_p, int day_p, int hour_p, int min_p)
{
	bool flag_bool = true;
	announcement announcement_p[40];
	int i = 0, j = 0;
	fstream datafile;

	datafile.open(announcement_file_name, ios::in | ios::out);
	datafile.seekg(0, ios::end);
	long poEnd = datafile.tellg();
	datafile.seekg(0, ios::beg);
	while (datafile.tellg() != poEnd) {
		datafile.read((char*)&announcement_p[i], sizeof(announcement));
		i++;
	}
	datafile.close();//���������ݶ�ȡ

	datafile.open(announcement_file_name, ios::in | ios::out | ios::trunc);//���ļ������ԭ��������
	datafile.seekg(0, ios::beg);
	while (j != i) {
		if (announcement_p[j].announcement_get_year() != year_p ||
			announcement_p[j].announcement_get_month() != month_p || announcement_p[j].announcement_get_day() != day_p ||
			announcement_p[j].announcement_get_hour() != hour_p || announcement_p[j].announcement_get_minute() != min_p) {
			
			datafile.write((char*)&announcement_p[j], sizeof(class announcement));//��������ھ�д��
			flag_bool = false;
		}
		j++;
	}
	datafile.close();//���������ݶ�ȡ
	return flag_bool;
}
