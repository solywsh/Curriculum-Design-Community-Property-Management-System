#pragma once
#include<iostream>
using namespace std;
class fee {
private:
	int id;
	int quarterly;//����
	double cube;//ˮ������������
	bool paid;//�ж��Ƿ�ɷ�
	double property_costs_k = 0.75;//��ҵ��k=0.75
	double elevator_fee_k = 0.3;//���ݷ�k=0.3
	double heating_costs_k = 20;//ů����k=20
	double water_fee_k = 0.28;//ˮ��k=0.28
	//����kΪ2020�����շѱ�׼2��ˮƽ
	double property_costs;//��ҵ��=k*���
	double elevator_fee;//���ݷ�=k*���
	double heating_costs;//ů����=k*���
	double water_fee;//ˮ��=k*����
	double all;//�շ��ܺ�

public:
	void fee_set(double area, int id);
	void fee_print();
	void fee_set_id(int id);
	void fee_set_property_costs();
	void fee_set_elevator_fee();
	void fee_set_heating_costs();
	void fee_set_water_fee();
	void fee_set_quarterly();
	void fee_set_all();
	void fee_set_paid();
	bool fee_get_paid();
	int fee_get_id();
	int fee_get_quarterly();
};
