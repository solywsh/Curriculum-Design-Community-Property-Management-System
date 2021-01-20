#pragma once
#include<iostream>
using namespace std;
class fee {
private:
	int id;
	int quarterly;//季度
	double cube;//水的用量，立方
	bool paid;//判断是否缴费
	double property_costs_k = 0.75;//物业费k=0.75
	double elevator_fee_k = 0.3;//电梯费k=0.3
	double heating_costs_k = 20;//暖气费k=20
	double water_fee_k = 0.28;//水费k=0.28
	//以上k为2020国家收费标准2等水平
	double property_costs;//物业费=k*面积
	double elevator_fee;//电梯费=k*面积
	double heating_costs;//暖气费=k*面积
	double water_fee;//水费=k*立方
	double all;//收费总和

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
