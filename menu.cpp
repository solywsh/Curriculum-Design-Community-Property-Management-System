#pragma once
#include "menu.h"

void owner_menu(){
    int choice, flag = 1;
    
    while (flag)
    {
        system("cls");
        cout << "================================================================================" << endl;
        cout << "=                                  业主管理                                    =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                               1.业主信息录入                                 =" << endl;
        cout << "=                               2.业主信息修改                                 =" << endl;
        cout << "=                               3.业主信息删除                                 =" << endl;
        cout << "=                               4.查看所有业主信息                             =" << endl;
        cout << "=                               5.返回                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "请选择对应功能: ";
        cin >> choice;
        while (choice == 0 || choice > 5) {
            cout << "输入数字不正确，请重新输入1-5: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            system("cls");
            owner_meun_input();
            break;
        case 2:
            system("cls");
            owner_meun_rewrite();
            break;
        case 3:
            system("cls");
            owner_meun_delete();
            break;
        case 4:
            system("cls");
            owner_meun_find_all();
            break;
        default:
            flag = 0;
            system("cls");
            break;
        }
    }
}
void fee_menu(){
    int choice, flag = 1;
    while (flag)
    {
        system("cls");
        cout << "================================================================================" << endl;
        cout << "=                                  费用管理                                    =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                               1.费用录入                                     =" << endl;
        cout << "=                               2.费用信息修改                                 =" << endl;
        cout << "=                               3.费用信息删除                                 =" << endl;
        cout << "=                               4.查看所有信息                                 =" << endl;
        cout << "=                               5.查找缴费情况                                 =" << endl;
        cout << "=                               6.统计未缴费名单                               =" << endl;
        cout << "=                               7.返回                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "请选择对应功能: ";
        cin >> choice;
        while (choice == 0 || choice > 7) {
            cout << "输入数字不正确，请重新输入1-7: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            system("cls");
            fee_meun_input();
            break;
        case 2:
            system("cls");
            fee_meun_rewrite();
            break;
        case 3:
            system("cls");
            fee_meun_delete();
            break;
        case 4:
            system("cls");
            fee_meun_find_all();
            break;
        case 5:
            system("cls");
            fee_meun_find_one();
            break;
        case 6:
            system("cls");
            fee_meun_statistics();
            break;
        default:
            flag = 0;
            system("cls");
            break;
        }
    }

}
void repair_menu() {
    int choice, flag = 1;
    while (flag)
    {
        system("cls");
        cout << "================================================================================" << endl;
        cout << "=                                  维修管理                                    =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl; 
        cout << "=                               1.维修登记                                     =" << endl;
        cout << "=                               2.显示所有维修记录                             =" << endl;
        cout << "=                               3.维修记录删除                                 =" << endl;
        cout << "=                               4.维修记录查找                                 =" << endl;
        cout << "=                               5.返回                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "请选择对应功能: ";
        cin >> choice;
        while (choice == 0 || choice > 5) {
            cout << "输入数字不正确，请重新输入1-5: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            system("cls");
            repair_meun_input();
            break;
        case 2:
            system("cls");
            repair_meun_find_all();
            break;
        case 3:
            system("cls");
            repair_meun_delete();
            break;
        case 4:
            system("cls");
            repair_meun_find_one();
            break;
        default:
            flag = 0;
            system("cls");
            break;
        }
    }
}
void announcement_menu() {
    int choice, flag = 1;
    while (flag)
    {
        system("cls");
        cout << "================================================================================" << endl;
        cout << "=                                  公告管理                                    =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                               1.添加公告                                     =" << endl;
        cout << "=                               2.查看所有公告                                 =" << endl;
        cout << "=                               3.删除公告                                     =" << endl;
        cout << "=                               4.返回                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "请选择对应功能: ";
        cin >> choice;
        while (choice == 0 || choice > 4) {
            cout << "输入数字不正确，请重新输入1-4: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            system("cls");
            announcement_meun_input();
            break;
        case 2:
            system("cls");
            announcement_meun_find_all();
            break;
        case 3:
            system("cls");
            announcement_meun_delete();
            break;
        default:
            flag = 0;
            system("cls");
            break;
        }
    }

}

void owner_meun_input() {
    int i = 0, flag;
    bool flag_bool;
    owner owner_object;
    doc owner_doc;
    while (true){
        cout << "================================================================================" << endl;
        cout << "请输入第" <<i+1<<"位业主信息"<< endl;
        owner_object.owner_set();
        flag_bool = owner_doc.owner_write(owner_object);
        cout <<"是否继续？(1.继续 2.退出): ";
        cin >> flag;
        cout << "================================================================================" << endl;
        if (flag == 2) break;
        i++;
    }
}
void owner_meun_rewrite() {
    int choice, flag = 1;
    int id;
    bool flag_bool = false,flag_while = true;
    owner owner_object;
    doc owner_doc;

    while (flag_while)
    {
        cout << "================================================================================" << endl;
        cout << "请输入要修改业主的id(楼号+房号):";
        cin >> id;
        owner_object = owner_doc.owner_find_by_id(id);
        if (owner_object.owner_get_id() == 0)
        {
            cout << "没有查到对应业主信息！请重试！" << endl;
            cout << "================================================================================" << endl;
        }
        else
        {
            cout << "================================================================================" << endl;
            cout << "要修改的业主的信息为:" << endl;
            owner_object.owner_print();
            system("pause");
            cout << "================================================================================" << endl;
            flag_while = false;
        }
    }

    while (flag)
    {
        system("cls");
        cout << "================================================================================" << endl;
        cout << "=                                    信息修改                                  =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                                     1.姓名                                   =" << endl;
        cout << "=                                     2.性别                                   =" << endl;
        cout << "=                                     3.电话                                   =" << endl;
        cout << "=                                     4.面积                                   =" << endl;
        cout << "=                                     5.退出                                   =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "请选择修改的信息: ";
        cin >> choice;
        while (choice == 0 || choice > 5) {
            system("pause");
            cout << "输入数字不正确，请重新输入1-5: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            system("cls");//清空之前界面
            cout << "================================================================================" << endl;
            owner_object.owner_set_name();
            cout << "业主的信息更新为:" << endl;
            flag_bool = owner_doc.owner_rewrite(owner_object);
            owner_object.owner_print();
            system("pause");//停顿
            break;
        case 2:
            system("cls");
            cout << "================================================================================" << endl;
            owner_object.owner_set_sex();
            flag_bool = owner_doc.owner_rewrite(owner_object);
            cout << "业主的信息更新为:" << endl;
            owner_object.owner_print();
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "================================================================================" << endl;
            owner_object.owner_set_phone_number();
            cout << "业主的信息更新为:" << endl;
            flag_bool = owner_doc.owner_rewrite(owner_object);
            owner_object.owner_print();
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "================================================================================" << endl;
            owner_object.owner_set_area();
            cout << "业主的信息更新为:" << endl;
            flag_bool = owner_doc.owner_rewrite(owner_object);
            owner_object.owner_print();
            system("pause");
        default:
            flag = 0;
            break;
        }
    }
    
    if (flag = flag_bool)
    {
        cout << "已经成功保存至文件！" << endl;
        system("pause");
    }
}
void owner_meun_delete() {
    int id;
    char choice;
    bool flag_bool = false,flag_while = true;
    owner owner_object;
    doc owner_doc;
    while (flag_while)
    {
        system("cls");
        cout << "================================================================================" << endl;
        cout << "请输入要删除业主的id(楼号+房号):";
        cin >> id;
        owner_object = owner_doc.owner_find_by_id(id);
        if (owner_object.owner_get_id() == 0)
        {
            cout << "没有查到对应业主信息！请重试！" << endl;
            system("pause");
        }
        else
        {
            cout << "业主的信息为:" << endl;
            owner_object.owner_print();
            cout << "确认删除？(y/n): ";
            cin >> choice;
            if (choice == 'y'||choice == 'Y')
            {
                flag_bool = owner_doc.owner_delete(id);
            }
            flag_while = false;
        }
        
    }
    
    if (flag_bool)
    {
        cout << "删除成功！" << endl;
        system("pause");
    }
}
void owner_meun_find_all() {
    bool flag_bool;
    owner owner_obj;
    doc owner_doc;
    flag_bool = owner_doc.owner_read_all(owner_obj);
}

void fee_meun_input() {
    doc doc_object;
    owner owner_object;
    fee fee_object;
    fee fee_flag;
    int id_fee,flag_int;
    bool flag_bool = true;
    while (flag_bool) {
        cout << "================================================================================" << endl;
        cout << "请输入费用业主的id(楼号+房号): ";
        cin >> id_fee;
        owner_object = doc_object.owner_find_by_id(id_fee);
        if (id_fee == 0) break;

        if (owner_object.owner_get_id() == 0) {
            cout << "未找到相应用户!请重新输入!(输入0退出)" << endl;
            flag_bool = true;
        }
        else {
            cout << "找到了！\n用户信息为: " << endl;
            owner_object.owner_print();
            fee_object.fee_set(owner_object.owner_get_area(),id_fee);
            fee_flag = doc_object.fee_find_by_id_quarterly(id_fee, fee_object.fee_get_quarterly());//输入id和季度信息去查找
            if (fee_flag.fee_get_id()!= 0)
            {
                cout << "已经含有此季度信息!请重新输入!" << endl;
                system("pause");
            }
            else
            {
                doc_object.fee_write(fee_object);
                //这里可以加一个询问是否继续
                cout << "是否继续？(1.继续 2.退出): ";
                cin >> flag_int;
                cout << "================================================================================" << endl;
                if (flag_int == 2) flag_bool = false;;
                system("pause");
            }
            
        }
    }
}
void fee_meun_rewrite() {
    int choice, flag = 0, quarterly;
    int id;
    bool flag_bool = false, flag_while = true;
    owner owner_object;
    fee fee_object;
    doc fee_doc;

    while (flag_while)
    {
        cout << "================================================================================" << endl;
        cout << "请输入要修改业主的id(楼号+房号):";
        cin >> id;
        cout << "请输入要修改的季度: ";
        cin >> quarterly;
        if (id == 0) break;
        owner_object = fee_doc.owner_find_by_id(id);
        fee_object = fee_doc.fee_find_by_id_quarterly(id, quarterly);

        if (owner_object.owner_get_id()==0 || fee_object.fee_get_id()== 0)
        {
            cout << "没有查到对应业主信息！请重试！(id输入0退出)" << endl;
            system("pause");
        }
        else
        {
            cout << "业主的信息为:" << endl;
            owner_object.owner_print();
            fee_object.fee_print();
            system("pause");
            flag_while = false;
            flag = 1;
        }
        
    }

    while (flag)
    {
        system("cls");
        cout << "================================================================================" << endl;
        cout << "=                                  费用修改                                    =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                               1.物业费                                       =" << endl;
        cout << "=                               2.电梯费                                       =" << endl;
        cout << "=                               3.暖气费                                       =" << endl;
        cout << "=                               4.水费                                         =" << endl;
        cout << "=                               5.缴费情况                                     =" << endl;
        cout << "=                               6.返回                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "请选择修改的信息: ";
        cin >> choice;
        while (choice == 0 || choice > 6) {
            cout << "输入数字不正确，请重新输入1-6: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            system("cls");//清空之前界面
            fee_object.fee_set_property_costs();
            fee_object.fee_set_all();//更新收费总和
            flag_bool = fee_doc.fee_rewrite(fee_object);
            cout << "================================================================================" << endl;
            cout << "费用信息更新为:" << endl;
            fee_object.fee_print();
            system("pause");//停顿
            break;
        case 2:
            system("cls");
            fee_object.fee_set_elevator_fee();
            fee_object.fee_set_all();//更新收费总和
            flag_bool = fee_doc.fee_rewrite(fee_object);
            cout << "================================================================================" << endl;
            cout << "费用信息更新为:" << endl;
            fee_object.fee_print();
            system("pause");
            break;
        case 3:
            system("cls");
            fee_object.fee_set_heating_costs();
            fee_object.fee_set_all();//更新收费总和
            flag_bool = fee_doc.fee_rewrite(fee_object);
            cout << "================================================================================" << endl;
            cout << "费用信息更新为:" << endl;
            fee_object.fee_print();
            system("pause");
            break;
        case 4:
            system("cls");
            fee_object.fee_set_water_fee();
            fee_object.fee_set_all();//更新收费总和
            flag_bool = fee_doc.fee_rewrite(fee_object);
            cout << "================================================================================" << endl;
            cout << "费用信息更新为:" << endl;
            fee_object.fee_print();
            system("pause");
            break;
        case 5:
            system("cls");
            fee_object.fee_set_paid();
            fee_object.fee_set_all();//更新收费总和
            flag_bool = fee_doc.fee_rewrite(fee_object);
            cout << "================================================================================" << endl;
            cout << "费用信息更新为:" << endl;
            fee_object.fee_print();
            system("pause");
            break;
        default:
            flag = 0;
            break;
        }
    }

    
    if (flag_bool)
    {
        cout << "================================================================================" << endl;
        cout << "已经成功保存至文件！" << endl;
        system("pause");
    }

}
void fee_meun_delete() {
    char choice;
    int id, quarterly ,flag = 1;
    bool flag_bool = false, flag_while = true;
    owner owner_object;
    fee fee_object;
    doc fee_doc;
    while (flag_while)
    {
        cout << "================================================================================" << endl;
        cout << "请输入要删除业主的id(楼号+房号):";
        cin >> id;
        cout << "请输入要删除的季度: ";
        cin >> quarterly;
        owner_object = fee_doc.owner_find_by_id(id);
        fee_object = fee_doc.fee_find_by_id_quarterly(id, quarterly);
        if (id == 0)flag_while = false;
        if (fee_object.fee_get_id() == 0)
        {
            cout << "================================================================================" << endl;
            cout << "没有查到对应业主信息！请重试！(输入id = 0退出)" << endl;
        }
        else
        {
            cout << "================================================================================" << endl;
            cout << "业主的信息为:" << endl;
            owner_object.owner_print();
            fee_object.fee_print();
            cout << "确认删除？(y/n): ";
            //chioce = getche() 从键盘读一个字符并回显
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                flag_while = false;
                flag_bool = fee_doc.fee_delete(id,quarterly);
                
            }
        }
    }
    if (flag_bool)
    {
        cout << "删除成功！" << endl;
        system("pause");
    }
}
void fee_meun_find_all() {
    bool flag_bool;
    fee fee_object;
    doc fee_doc;
    flag_bool = fee_doc.fee_real_all(fee_object);
}
void fee_meun_find_one(){
    int flag = 1;
    int id;
    bool flag_while = true;
    owner owner_object;
    fee fee_object;
    doc fee_doc;

    while (flag_while)
    {
        cout << "================================================================================" << endl;
        cout << "请输入要查询业主的id(楼号+房号):";
        cin >> id;
        owner_object = fee_doc.owner_find_by_id(id);
        
        if (owner_object.owner_get_id() == 0 && fee_doc.fee_find_by_id(id))
        {
            cout << "================================================================================" << endl;
            cout << "没有查到对应业主信息！请重试！" << endl;
            system("pause");
        }
        else
        {
            cout << "================================================================================" << endl;
            cout << "业主"<<owner_object.owner_get_name()<<"信息为:" << endl;
            fee_doc.fee_find_one(id);
        }

        flag_while = false;
    }
}
void fee_meun_statistics(){

    char choice_char;
    bool flag_bool = true;
    doc doc_object;
    int choice, flag = 1;
    while (flag)
    {
        system("cls");
        cout << "================================================================================" << endl;
        cout << "=                                  统计                                        =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                               1.查看文件                                     =" << endl;
        cout << "=                               2.删除文件                                     =" << endl;
        cout << "=                               3.重新统计                                     =" << endl;
        cout << "=                               4.返回                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "请选择对应功能: ";
        cin >> choice;
        while (choice == 0 || choice > 4) {
            cout << "输入数字不正确，请重新输入1-4: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            system("cls");
            cout << "================================================================================" << endl;
            cout << "请选择查看的文件(1.楼号排序 2.季度排序 ): ";
            cin >> choice;
            while (choice == 0 || choice > 2) {
                cout << "输入数字不正确，请重新输入1或2: ";
                cin >> choice;
            }
            flag_bool = doc_object.fee_statistics_read(choice);
            break;
        case 2:
            system("cls");
            cout << "================================================================================" << endl;
            cout << "是否清空之前文件内容？(y/n): ";
            cin >> choice_char;
            if (choice_char == 'y' || choice_char == 'Y')
            {
                cout << "选择清空的排序文件(1.楼号 2.季度 3.全部): ";
                cin >> choice;
                while (choice == 0 || choice > 3) {
                    cout << "输入数字不正确，请重新输入1或3: ";
                    cin >> choice;
                }
                flag_bool = doc_object.fee_clean_unpaid(choice);
            }
            break;
        case 3:
            system("cls");
            cout << "================================================================================" << endl;
            cout << "请选择排序方式(1.楼号 2.季度 ): ";
            cin >> choice;
            while (choice == 0 || choice > 2) {
                cout << "输入数字不正确，请重新输入1或2: ";
                cin >> choice;
            }
            if (choice == 1)
            {
                flag_bool = doc_object.fee_statistics_by_floor();
            }
            else
            {
                flag_bool = doc_object.fee_statistics_by_quarterly();
            }
            break;
        default:
            flag = 0;
            system("cls");
            break;
        }
    }

}

void repair_meun_input(){
    int id_repair;
    bool flag_bool = true;
    doc doc_object;
    repair repair_object;
    owner owner_object;
    while (flag_bool) {
        cout << "================================================================================" << endl;
        cout << "请输入维修业主的id(楼号+房号): ";
        cin >> id_repair;
        if (id_repair == 0) break;
        owner_object = doc_object.owner_find_by_id(id_repair);
        if (owner_object.owner_get_id() == 0) {
            cout << "================================================================================" << endl;
            cout << "未找到相应用户!请重新输入!" << endl;
            flag_bool = true;
        }
        else {
            cout << "================================================================================" << endl;
            cout << "找到了！\n用户信息为: " << endl;
            owner_object.owner_print();
            system("pause");
            repair_object.repair_set(id_repair);
            doc_object.repair_write(repair_object);
            flag_bool = false;
            system("pause");
        }
    }
}
void repair_meun_find_all(){
    bool flag_bool;
    repair repair_object;
    doc repair_doc;
    flag_bool = repair_doc.repair_read_all(repair_object);

}
void repair_meun_delete(){
    int id = 0;
    char choice;
    doc doc_object;
    owner owner_object;
    repair repair_object;
    bool flag_bool = true;
    int year, month, day, hour, minute;
    while (flag_bool)
    {
        cout << "================================================================================" << endl;
        cout << "请输入想要删除的业主的id(楼号+房号): ";
        cin >> id;
        cout << "请输入维修登记时间: " << endl;
        cout << "年: ";
        cin >> year;
        cout << "月: ";
        cin >> month;
        cout << "日: ";
        cin >> day;
        cout << "时: ";
        cin >> hour;
        cout << "分: ";
        cin >> minute;
        if (id == 0) break;
        repair_object = doc_object.repair_find_by_id(id);
        if (repair_object.repair_get_id() == 0)
        {
            cout << "================================================================================" << endl;
            cout << "没有找到对应业主，请重试！(id=0时退出)" << endl;;
            flag_bool = true;
        }
        else {
            cout << "找到了! " << endl;
            repair_object.repair_print();
            owner_object = doc_object.owner_find_by_id(id);

            cout << "================================================================================" << endl;
            cout << "确认删除" << owner_object.owner_get_name() << "的信息？(y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                flag_bool = doc_object.repair_delete(id,year,month,day,hour,minute);
                if (flag_bool){
                    cout << "================================================================================" << endl;
                    cout<<"删除成功!"<<endl;
                    flag_bool = false;
                    system("pause");
                }
                else{
                    cout << "================================================================================" << endl;
                    cout << "删除失败，请重试!可能是时间错了。" << endl;
                    system("pause");
                }
                
            }
            
        }
    }
}
void repair_meun_find_one()
{
    int id;
    doc doc_object;
    bool flag_bool = false;
    cout << "================================================================================" << endl;
    cout << "请输入想要查找的业主的id(楼号+房号): ";
    cin >> id;
    flag_bool = doc_object.repair_find(id);

}

void announcement_meun_input() {
    bool flag_bool = true;
    int flag_int;
    doc doc_object;
    announcement announcement_object;
    owner owner_object;
    while (flag_bool) {
        announcement_object.announcement_set();
        flag_bool = doc_object.announcement_write(announcement_object);

        //这里可以加一个询问是否继续
        cout << "是否继续？(1.继续 2.退出): ";
        cin >> flag_int;
        cout << "================================================================================" << endl;
        if (flag_int == 2) flag_bool = false;;
    }
}
void announcement_meun_find_all() {
    bool flag_bool;
    announcement announcement_object;
    doc announcement_doc;
    flag_bool = announcement_doc.announcement_read_all(announcement_object);
}
void announcement_meun_delete() {
    int id = 0;
    char choice;
    doc doc_object;
    bool flag_bool = true;
    int year, month, day, hour, minute;
    while (flag_bool)
    {
        cout << "================================================================================" << endl;
        cout << "请输入公告登记时间: " << endl;
        cout << "年: ";
        cin >> year;
        cout << "月: ";
        cin >> month;
        cout << "日: ";
        cin >> day;
        cout << "时: ";
        cin >> hour;
        cout << "分: ";
        cin >> minute;
        if (year == 0)break;
    
        cout << "================================================================================" << endl;
        cout << "确认删除？(y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            flag_bool = doc_object.announcement_delete(year, month, day, hour, minute);
            if (flag_bool) {
                cout << "================================================================================" << endl;
                cout << "删除成功!" << endl;
                flag_bool = false;
                system("pause");
            }
            else {
                cout << "================================================================================" << endl;
                cout << "删除失败，请重试!" << endl;
                system("pause");
            }

        }
        else break;
    }

}