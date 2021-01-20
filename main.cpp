#pragma once
#include <iostream>
#include <stdlib.h>
#include <iomanip>//设置cout时的空格setw()
#include "menu.h"
using namespace std;
/***
 *                    _ooOoo_
 *                   o8888888o
 *                   88" . "88
 *                   (| -_- |)
 *                    O\ = /O
 *                ____/`---'\____
 *              .   ' \\| |// `.
 *               / \\||| : |||// \
 *             / _||||| -:- |||||- \
 *               | | \\\ - /// | |
 *             | \_| ''\---/'' | |
 *              \ .-\__ `-` ___/-. /
 *           ___`. .' /--.--\ `. . __
 *        ."" '< `.___\_<|>_/___.' >'"".
 *       | | : `- \`.;`\ _ /`;.`/ - ` : | |
 *         \ \ `-. \_ __\ /__ _/ .-` / /
 * ======`-.____`-.___\_____/___.-`____.-'======
 *                    `=---='
 *
 * .............................................
 *          佛祖保佑             永无BUG
*/
int main(){
    int choice;
    char usr[100], pw[100];
    bool flag_menu = false;//当管理员登陆之后为true，才能进入管理界面
    bool flag_admin = true;//控制管理员菜单的循环

    //bool flag_menu = true;//跳过登陆直接进入菜单，调试用
    //bool flag_admin = false;

    bool flag = false;
    admin admin_object;
    doc doc_main;

    /*admin_object.admin_set();
    flag = doc_main.admin_write(admin_object);
    此处是用于第一次登陆,在数据文件里没有管理员信息的情况*/

    SYSTEMTIME sys_main;
    GetLocalTime(&sys_main);

    while (flag_admin)
    {
        
        system("cls");
        cout << "================================================================================" << endl;
        cout << "=                                小区物业管理系统                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                                1.管理员登陆                                  =" << endl;
        cout << "=                                2.修改密码                                    =" << endl;
        cout << "=                                3.退出                                        =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        
        cout << "=" << setw(30) << "时间: " << sys_main.wYear << "年" << sys_main.wMonth << "月" << sys_main.wDay << "日  "
            << sys_main.wHour << ":";
        if (sys_main.wMinute < 10) {
            cout << "0" << sys_main.wMinute;//小于10时加一
        }
        else
        {
            cout << sys_main.wMinute;
        }
        cout << "  星期";
        if (sys_main.wDayOfWeek == 1) { cout << "一"; }
        if (sys_main.wDayOfWeek == 2) { cout << "二"; }
        if (sys_main.wDayOfWeek == 3) { cout << "三"; }
        if (sys_main.wDayOfWeek == 4) { cout << "四"; }
        if (sys_main.wDayOfWeek == 5) { cout << "五"; }
        if (sys_main.wDayOfWeek == 6) { cout << "六"; }
        if (sys_main.wDayOfWeek == 7) { cout << "日"; }
        cout << setw(21) << "=" << endl;
        cout << "================================================================================" << endl;

        cout << "请选择对应功能: ";
        cin >> choice;
        while (choice == 0 || choice > 3) {
            system("pause");
            cout << "输入数字不正确，请重新输入1-3: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            while (true)
            {
                cout << "请输入管理员用户名: ";
                cin >> usr;
                cout << "请输入管理员密码: ";
                cin >> pw;
                if (strcmp(doc_main.admin_find(usr), pw) == 0) {
                    system("cls");
                    cout << "================================================================================" << endl;
                    cout << "=                                                                              =" << endl;
                    cout << "=                                                                              =" << endl;
                    cout << "=                                                                              =" << endl;
                    cout << "=                                     欢迎!                                    =" << endl;
                    cout << "=                                                                              =" << endl;
                    cout << "=                                                                              =" << endl;
                    cout << "=                                                                              =" << endl;
                    cout << "=                                                                              =" << endl;
                    cout << "================================================================================" << endl;
                    system("pause");
                    flag_admin = false;
                    flag_menu = true;
                    break;//此break跳出while循环
                }
                else {
                    cout << "密码不正确，请重新输入!" << endl;
                    system("pause");
                }
            }
            break;//此break结束switch
        case 2:
            while (true){
                cout << "请输入管理员用户名: ";
                cin >> usr;
                cout << "请输入旧的管理员密码: ";
                cin >> pw;
                if (strcmp(doc_main.admin_find(usr), pw) == 0) {
                    cout << "请输入新的密码: " ;
                    cin >> pw;
                    admin_object.admin_set_password(pw);
                    admin_object.admin_set_username(usr);
                    if (doc_main.admin_rewrite(admin_object)) {
                        cout << "修改成功!新的密码: ";
                        cout << admin_object.admin_get_password()<< endl;
                    }
                    else cout << "修改失败!" << endl;
                    /*flag_admin = false;
                    flag_menu = true;*/
                    system("pause");
                    break;//此break跳出while循环
                }
                else {
                    cout << "用户名或密码不正确，请重新输入!" << endl;
                }
            }
            break;//此break结束switch
        default:
            return 0;
        }
    }
    while (flag_menu)
    {
        system("cls");
        cout << "================================================================================" << endl;
        cout << "=                            小区物业管理系统菜单                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                               1.业主管理                                     =" << endl;
        cout << "=                               2.费用管理                                     =" << endl;
        cout << "=                               3.维修管理                                     =" << endl;
        cout << "=                               4.公告管理                                     =" << endl;
        cout << "=                               5.退出                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "=" << setw(30) << "时间: " << sys_main.wYear << "年" << sys_main.wMonth << "月" << sys_main.wDay << "日  "
            << sys_main.wHour << ":";
        if (sys_main.wMinute < 10) {
            cout << "0" << sys_main.wMinute;//小于10时加一
        }
        else
        {
            cout << sys_main.wMinute;
        }
        cout << "  星期";
        if (sys_main.wDayOfWeek == 1) { cout << "一"; }
        if (sys_main.wDayOfWeek == 2) { cout << "二"; }
        if (sys_main.wDayOfWeek == 3) { cout << "三"; }
        if (sys_main.wDayOfWeek == 4) { cout << "四"; }
        if (sys_main.wDayOfWeek == 5) { cout << "五"; }
        if (sys_main.wDayOfWeek == 6) { cout << "六"; }
        if (sys_main.wDayOfWeek == 7) { cout << "日"; }
        cout << setw(21) << "=" << endl;
        cout << "================================================================================" << endl;
        cout << "请选择对应功能: ";
        cin >> choice;
        while (choice == 0 || choice > 5){
            system("pause");
            cout << "输入数字不正确，请重新输入1-5: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            system("cls");//清空之前界面
            owner_menu();
            //system("pause");//停顿
            break;
        case 2:
            system("cls");
            fee_menu();
            break;
        case 3:
            system("cls");
            repair_menu();
            break;
        case 4:
            system("cls");
            announcement_menu();
            break;
        default:
            return 0;
        }
    }

}

