#pragma once
#include <iostream>
#include<stdio.h>
#include"doc.h"
using namespace std;

void owner_menu();//����ҵ���Ĳ˵�չʾ
void fee_menu();//���ò˵�
void repair_menu();//ά�޲˵�
void announcement_menu();//����˵�

//ҵ�� �Ӳ˵�����
void owner_meun_input();
void owner_meun_rewrite();
void owner_meun_delete();
void owner_meun_find_all();

//�����Ӳ˵�����
void fee_meun_input();
void fee_meun_rewrite();
void fee_meun_delete();
void fee_meun_find_all();
void fee_meun_find_one();
void fee_meun_statistics();//ͳ��

void repair_meun_input();
void repair_meun_find_all();
void repair_meun_delete();
void repair_meun_find_one();

void announcement_meun_input();
void announcement_meun_find_all();
void announcement_meun_delete();