#pragma once
#include"fee.h"
#include<iostream>
using namespace std;

void fee::fee_set(double area,int id) {
	int quarterly;//����
	bool paid;//�Ƿ�ɷ�
	double cube;//ˮ������������
	char choice;

	cout << "================================================================================" << endl;
	cout << "�Ƿ���ĸ������շ�ϵ����(y/n): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		cout << "��������ҵ���շ�ϵ��(Ԫ/m2): ";
		cin >> property_costs_k;
		cout << "��������ݷ��շ�ϵ��(Ԫ/m2): ";
		cin >> elevator_fee_k;
		cout << "������ů�����շ�ϵ��(Ԫ/m2): ";
		cin >> heating_costs_k;
		cout << "������ˮ���շ�ϵ��(Ԫ/m3): ";
		cin >> water_fee_k;

		cout << "���ڵ��շѱ�׼��:" << endl;
		cout << "��ҵ��: " << property_costs_k << "Ԫ/m2" << endl;
		cout << "���ݷ�: " << elevator_fee_k << "Ԫ/m2" << endl;
		cout << "ů����: " << heating_costs_k << "Ԫ/m2" << endl;
		cout << "ˮ��: " << water_fee_k << "Ԫ/m3" << endl;
	}

	this->property_costs_k = property_costs_k;
	this->elevator_fee_k = elevator_fee_k;
	this->heating_costs_k = heating_costs_k;
	this->water_fee_k = water_fee_k;
	while (true)
	{
		cout << "�����뼾��: ";
		cin >> quarterly;
		if (quarterly < 5)
		{
			break;
		}
		else
		{
			cout<<"�����뼾��1-4��"<<endl;
		}
	}

	

	cout << "������ҵ����������ˮ(m3): ";
	cin >> cube;
	cout << "ҵ���Ƿ�ɷ�(y/n): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
		paid = true;
	else paid = false;
	double all = 0;//�շ��ܺ�
	double property_costs= this->property_costs_k * area;//��ҵ��=k*���
	double elevator_fee = this->elevator_fee_k * area;//���ݷ�=k*���
	double heating_costs = this->heating_costs_k * area;//ů����=k*���
	double water_fee = this->water_fee_k * cube;//ˮ��=k*����

	all = property_costs + elevator_fee + heating_costs  + water_fee;

	this->quarterly = quarterly;
	this->property_costs = property_costs;
	this->elevator_fee = elevator_fee;
	this->heating_costs = heating_costs;
	this->water_fee = water_fee;
	this->cube = cube;
	this->paid = paid;
	this->all = all;
	this->id = id;

	fee_print();
}
void fee::fee_print() {
	cout << "================================================================================" << endl;
	
	cout << "ҵ����" << quarterly << "���ȵ��շ���Ϣ:" << endl;
	cout << "ID: " << id << endl;
	cout << "�Ƿ�ɷ�: ";
	if (paid)
		cout << "�ѽɷ�" << endl;
	else cout << "δ�ɷ�" << endl;

	cout << "��������ҵ��: " << property_costs << endl;;
	cout << "�����ȵ��ݷ�: " << elevator_fee << endl;
	cout << "������ů����: " << heating_costs << endl;
	cout << "������ˮ��: " << water_fee << endl;
	cout << "�ܼ�: " << all << endl;
	cout << "================================================================================" << endl;
}
void fee::fee_set_id(int id) {
	this->id = id;
}

void fee::fee_set_quarterly() {
	int quarterly;
	cout << "================================================================================" << endl;
	cout << "������ĺ�ļ���: ";
	cin >> quarterly;
	this->quarterly = quarterly;
}
void fee::fee_set_property_costs() {
	double property_costs;
	cout << "================================================================================" << endl;
	cout << "��������ĺ����ҵ��: ";
	cin >> property_costs;
	this->property_costs = property_costs;
}
void fee::fee_set_elevator_fee() {
	double elevator_fee;
	cout << "================================================================================" << endl;
	cout << "��������ĺ�ĵ��ݷ�: ";
	cin >> elevator_fee;
	this->elevator_fee = elevator_fee;
}
void fee::fee_set_heating_costs(){
	double heating_costs;
	cout << "================================================================================" << endl;
	cout << "��������ĺ��ů����: ";
	cin >> heating_costs;
	this->heating_costs = heating_costs;
}
void fee::fee_set_water_fee() {
	double water_fee;
	cout << "================================================================================" << endl;
	cout << "��������ĺ��ˮ��: ";
	cin >> water_fee;
	this->water_fee = water_fee;
}
void fee::fee_set_paid() {
	int choice;
	cout << "================================================================================" << endl;
	cout << "���ɷ���Ϣ�޸�Ϊ(1.�ѽɷ� 2.δ�ɷ�): ";
	cin >> choice;
	while (choice == 0 || choice > 2) {
		cout << "�������ֲ���ȷ������������1-2: ";
		cin >> choice;
	}
	if (choice == 1)this->paid = true;
	else this->paid = false;
}
void fee::fee_set_all() {
	this->all = this->property_costs + this->elevator_fee + 
		this->heating_costs  + this->water_fee;
}
int fee::fee_get_id() {
	return this->id;
}
int fee::fee_get_quarterly() {
	return this->quarterly;
}
bool fee::fee_get_paid() {
	return this->paid;
}