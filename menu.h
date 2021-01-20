#pragma once
#include <iostream>
#include<stdio.h>
#include"doc.h"
using namespace std;

void owner_menu();//用于业主的菜单展示
void fee_menu();//费用菜单
void repair_menu();//维修菜单
void announcement_menu();//公告菜单

//业主 子菜单函数
void owner_meun_input();
void owner_meun_rewrite();
void owner_meun_delete();
void owner_meun_find_all();

//费用子菜单函数
void fee_meun_input();
void fee_meun_rewrite();
void fee_meun_delete();
void fee_meun_find_all();
void fee_meun_find_one();
void fee_meun_statistics();//统计

void repair_meun_input();
void repair_meun_find_all();
void repair_meun_delete();
void repair_meun_find_one();

void announcement_meun_input();
void announcement_meun_find_all();
void announcement_meun_delete();