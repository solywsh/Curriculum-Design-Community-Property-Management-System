#pragma once
#include"fee.h"
#include<iostream>
using namespace std;

void fee::fee_set(double area,int id) {
	int quarterly;//季度
	bool paid;//是否缴费
	double cube;//水的用量，立方
	char choice;

	cout << "================================================================================" << endl;
	cout << "是否更改各费用收费系数？(y/n): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		cout << "请输入物业费收费系数(元/m2): ";
		cin >> property_costs_k;
		cout << "请输入电梯费收费系数(元/m2): ";
		cin >> elevator_fee_k;
		cout << "请输入暖气费收费系数(元/m2): ";
		cin >> heating_costs_k;
		cout << "请输入水费收费系数(元/m3): ";
		cin >> water_fee_k;

		cout << "现在的收费标准是:" << endl;
		cout << "物业费: " << property_costs_k << "元/m2" << endl;
		cout << "电梯费: " << elevator_fee_k << "元/m2" << endl;
		cout << "暖气费: " << heating_costs_k << "元/m2" << endl;
		cout << "水费: " << water_fee_k << "元/m3" << endl;
	}

	this->property_costs_k = property_costs_k;
	this->elevator_fee_k = elevator_fee_k;
	this->heating_costs_k = heating_costs_k;
	this->water_fee_k = water_fee_k;
	while (true)
	{
		cout << "请输入季度: ";
		cin >> quarterly;
		if (quarterly < 5)
		{
			break;
		}
		else
		{
			cout<<"请输入季度1-4！"<<endl;
		}
	}

	

	cout << "请输入业主本季度用水(m3): ";
	cin >> cube;
	cout << "业主是否缴费(y/n): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
		paid = true;
	else paid = false;
	double all = 0;//收费总和
	double property_costs= this->property_costs_k * area;//物业费=k*面积
	double elevator_fee = this->elevator_fee_k * area;//电梯费=k*面积
	double heating_costs = this->heating_costs_k * area;//暖气费=k*面积
	double water_fee = this->water_fee_k * cube;//水费=k*立方

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
	
	cout << "业主第" << quarterly << "季度的收费信息:" << endl;
	cout << "ID: " << id << endl;
	cout << "是否缴费: ";
	if (paid)
		cout << "已缴费" << endl;
	else cout << "未缴费" << endl;

	cout << "本季度物业费: " << property_costs << endl;;
	cout << "本季度电梯费: " << elevator_fee << endl;
	cout << "本季度暖气费: " << heating_costs << endl;
	cout << "本季度水费: " << water_fee << endl;
	cout << "总计: " << all << endl;
	cout << "================================================================================" << endl;
}
void fee::fee_set_id(int id) {
	this->id = id;
}

void fee::fee_set_quarterly() {
	int quarterly;
	cout << "================================================================================" << endl;
	cout << "请输更改后的季度: ";
	cin >> quarterly;
	this->quarterly = quarterly;
}
void fee::fee_set_property_costs() {
	double property_costs;
	cout << "================================================================================" << endl;
	cout << "请输入更改后的物业费: ";
	cin >> property_costs;
	this->property_costs = property_costs;
}
void fee::fee_set_elevator_fee() {
	double elevator_fee;
	cout << "================================================================================" << endl;
	cout << "请输入更改后的电梯费: ";
	cin >> elevator_fee;
	this->elevator_fee = elevator_fee;
}
void fee::fee_set_heating_costs(){
	double heating_costs;
	cout << "================================================================================" << endl;
	cout << "请输入更改后的暖气费: ";
	cin >> heating_costs;
	this->heating_costs = heating_costs;
}
void fee::fee_set_water_fee() {
	double water_fee;
	cout << "================================================================================" << endl;
	cout << "请输入更改后的水费: ";
	cin >> water_fee;
	this->water_fee = water_fee;
}
void fee::fee_set_paid() {
	int choice;
	cout << "================================================================================" << endl;
	cout << "将缴费信息修改为(1.已缴费 2.未缴费): ";
	cin >> choice;
	while (choice == 0 || choice > 2) {
		cout << "输入数字不正确，请重新输入1-2: ";
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