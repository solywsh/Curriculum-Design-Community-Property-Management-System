#pragma once
#include "menu.h"

void owner_menu(){
    int choice, flag = 1;
    
    while (flag)
    {
        system("cls");
        cout << "================================================================================" << endl;
        cout << "=                                  ҵ������                                    =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                               1.ҵ����Ϣ¼��                                 =" << endl;
        cout << "=                               2.ҵ����Ϣ�޸�                                 =" << endl;
        cout << "=                               3.ҵ����Ϣɾ��                                 =" << endl;
        cout << "=                               4.�鿴����ҵ����Ϣ                             =" << endl;
        cout << "=                               5.����                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "��ѡ���Ӧ����: ";
        cin >> choice;
        while (choice == 0 || choice > 5) {
            cout << "�������ֲ���ȷ������������1-5: ";
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
        cout << "=                                  ���ù���                                    =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                               1.����¼��                                     =" << endl;
        cout << "=                               2.������Ϣ�޸�                                 =" << endl;
        cout << "=                               3.������Ϣɾ��                                 =" << endl;
        cout << "=                               4.�鿴������Ϣ                                 =" << endl;
        cout << "=                               5.���ҽɷ����                                 =" << endl;
        cout << "=                               6.ͳ��δ�ɷ�����                               =" << endl;
        cout << "=                               7.����                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "��ѡ���Ӧ����: ";
        cin >> choice;
        while (choice == 0 || choice > 7) {
            cout << "�������ֲ���ȷ������������1-7: ";
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
        cout << "=                                  ά�޹���                                    =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl; 
        cout << "=                               1.ά�޵Ǽ�                                     =" << endl;
        cout << "=                               2.��ʾ����ά�޼�¼                             =" << endl;
        cout << "=                               3.ά�޼�¼ɾ��                                 =" << endl;
        cout << "=                               4.ά�޼�¼����                                 =" << endl;
        cout << "=                               5.����                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "��ѡ���Ӧ����: ";
        cin >> choice;
        while (choice == 0 || choice > 5) {
            cout << "�������ֲ���ȷ������������1-5: ";
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
        cout << "=                                  �������                                    =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                               1.��ӹ���                                     =" << endl;
        cout << "=                               2.�鿴���й���                                 =" << endl;
        cout << "=                               3.ɾ������                                     =" << endl;
        cout << "=                               4.����                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "��ѡ���Ӧ����: ";
        cin >> choice;
        while (choice == 0 || choice > 4) {
            cout << "�������ֲ���ȷ������������1-4: ";
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
        cout << "�������" <<i+1<<"λҵ����Ϣ"<< endl;
        owner_object.owner_set();
        flag_bool = owner_doc.owner_write(owner_object);
        cout <<"�Ƿ������(1.���� 2.�˳�): ";
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
        cout << "������Ҫ�޸�ҵ����id(¥��+����):";
        cin >> id;
        owner_object = owner_doc.owner_find_by_id(id);
        if (owner_object.owner_get_id() == 0)
        {
            cout << "û�в鵽��Ӧҵ����Ϣ�������ԣ�" << endl;
            cout << "================================================================================" << endl;
        }
        else
        {
            cout << "================================================================================" << endl;
            cout << "Ҫ�޸ĵ�ҵ������ϢΪ:" << endl;
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
        cout << "=                                    ��Ϣ�޸�                                  =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                                     1.����                                   =" << endl;
        cout << "=                                     2.�Ա�                                   =" << endl;
        cout << "=                                     3.�绰                                   =" << endl;
        cout << "=                                     4.���                                   =" << endl;
        cout << "=                                     5.�˳�                                   =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "��ѡ���޸ĵ���Ϣ: ";
        cin >> choice;
        while (choice == 0 || choice > 5) {
            system("pause");
            cout << "�������ֲ���ȷ������������1-5: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            system("cls");//���֮ǰ����
            cout << "================================================================================" << endl;
            owner_object.owner_set_name();
            cout << "ҵ������Ϣ����Ϊ:" << endl;
            flag_bool = owner_doc.owner_rewrite(owner_object);
            owner_object.owner_print();
            system("pause");//ͣ��
            break;
        case 2:
            system("cls");
            cout << "================================================================================" << endl;
            owner_object.owner_set_sex();
            flag_bool = owner_doc.owner_rewrite(owner_object);
            cout << "ҵ������Ϣ����Ϊ:" << endl;
            owner_object.owner_print();
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "================================================================================" << endl;
            owner_object.owner_set_phone_number();
            cout << "ҵ������Ϣ����Ϊ:" << endl;
            flag_bool = owner_doc.owner_rewrite(owner_object);
            owner_object.owner_print();
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "================================================================================" << endl;
            owner_object.owner_set_area();
            cout << "ҵ������Ϣ����Ϊ:" << endl;
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
        cout << "�Ѿ��ɹ��������ļ���" << endl;
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
        cout << "������Ҫɾ��ҵ����id(¥��+����):";
        cin >> id;
        owner_object = owner_doc.owner_find_by_id(id);
        if (owner_object.owner_get_id() == 0)
        {
            cout << "û�в鵽��Ӧҵ����Ϣ�������ԣ�" << endl;
            system("pause");
        }
        else
        {
            cout << "ҵ������ϢΪ:" << endl;
            owner_object.owner_print();
            cout << "ȷ��ɾ����(y/n): ";
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
        cout << "ɾ���ɹ���" << endl;
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
        cout << "���������ҵ����id(¥��+����): ";
        cin >> id_fee;
        owner_object = doc_object.owner_find_by_id(id_fee);
        if (id_fee == 0) break;

        if (owner_object.owner_get_id() == 0) {
            cout << "δ�ҵ���Ӧ�û�!����������!(����0�˳�)" << endl;
            flag_bool = true;
        }
        else {
            cout << "�ҵ��ˣ�\n�û���ϢΪ: " << endl;
            owner_object.owner_print();
            fee_object.fee_set(owner_object.owner_get_area(),id_fee);
            fee_flag = doc_object.fee_find_by_id_quarterly(id_fee, fee_object.fee_get_quarterly());//����id�ͼ�����Ϣȥ����
            if (fee_flag.fee_get_id()!= 0)
            {
                cout << "�Ѿ����д˼�����Ϣ!����������!" << endl;
                system("pause");
            }
            else
            {
                doc_object.fee_write(fee_object);
                //������Լ�һ��ѯ���Ƿ����
                cout << "�Ƿ������(1.���� 2.�˳�): ";
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
        cout << "������Ҫ�޸�ҵ����id(¥��+����):";
        cin >> id;
        cout << "������Ҫ�޸ĵļ���: ";
        cin >> quarterly;
        if (id == 0) break;
        owner_object = fee_doc.owner_find_by_id(id);
        fee_object = fee_doc.fee_find_by_id_quarterly(id, quarterly);

        if (owner_object.owner_get_id()==0 || fee_object.fee_get_id()== 0)
        {
            cout << "û�в鵽��Ӧҵ����Ϣ�������ԣ�(id����0�˳�)" << endl;
            system("pause");
        }
        else
        {
            cout << "ҵ������ϢΪ:" << endl;
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
        cout << "=                                  �����޸�                                    =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                               1.��ҵ��                                       =" << endl;
        cout << "=                               2.���ݷ�                                       =" << endl;
        cout << "=                               3.ů����                                       =" << endl;
        cout << "=                               4.ˮ��                                         =" << endl;
        cout << "=                               5.�ɷ����                                     =" << endl;
        cout << "=                               6.����                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "��ѡ���޸ĵ���Ϣ: ";
        cin >> choice;
        while (choice == 0 || choice > 6) {
            cout << "�������ֲ���ȷ������������1-6: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            system("cls");//���֮ǰ����
            fee_object.fee_set_property_costs();
            fee_object.fee_set_all();//�����շ��ܺ�
            flag_bool = fee_doc.fee_rewrite(fee_object);
            cout << "================================================================================" << endl;
            cout << "������Ϣ����Ϊ:" << endl;
            fee_object.fee_print();
            system("pause");//ͣ��
            break;
        case 2:
            system("cls");
            fee_object.fee_set_elevator_fee();
            fee_object.fee_set_all();//�����շ��ܺ�
            flag_bool = fee_doc.fee_rewrite(fee_object);
            cout << "================================================================================" << endl;
            cout << "������Ϣ����Ϊ:" << endl;
            fee_object.fee_print();
            system("pause");
            break;
        case 3:
            system("cls");
            fee_object.fee_set_heating_costs();
            fee_object.fee_set_all();//�����շ��ܺ�
            flag_bool = fee_doc.fee_rewrite(fee_object);
            cout << "================================================================================" << endl;
            cout << "������Ϣ����Ϊ:" << endl;
            fee_object.fee_print();
            system("pause");
            break;
        case 4:
            system("cls");
            fee_object.fee_set_water_fee();
            fee_object.fee_set_all();//�����շ��ܺ�
            flag_bool = fee_doc.fee_rewrite(fee_object);
            cout << "================================================================================" << endl;
            cout << "������Ϣ����Ϊ:" << endl;
            fee_object.fee_print();
            system("pause");
            break;
        case 5:
            system("cls");
            fee_object.fee_set_paid();
            fee_object.fee_set_all();//�����շ��ܺ�
            flag_bool = fee_doc.fee_rewrite(fee_object);
            cout << "================================================================================" << endl;
            cout << "������Ϣ����Ϊ:" << endl;
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
        cout << "�Ѿ��ɹ��������ļ���" << endl;
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
        cout << "������Ҫɾ��ҵ����id(¥��+����):";
        cin >> id;
        cout << "������Ҫɾ���ļ���: ";
        cin >> quarterly;
        owner_object = fee_doc.owner_find_by_id(id);
        fee_object = fee_doc.fee_find_by_id_quarterly(id, quarterly);
        if (id == 0)flag_while = false;
        if (fee_object.fee_get_id() == 0)
        {
            cout << "================================================================================" << endl;
            cout << "û�в鵽��Ӧҵ����Ϣ�������ԣ�(����id = 0�˳�)" << endl;
        }
        else
        {
            cout << "================================================================================" << endl;
            cout << "ҵ������ϢΪ:" << endl;
            owner_object.owner_print();
            fee_object.fee_print();
            cout << "ȷ��ɾ����(y/n): ";
            //chioce = getche() �Ӽ��̶�һ���ַ�������
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
        cout << "ɾ���ɹ���" << endl;
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
        cout << "������Ҫ��ѯҵ����id(¥��+����):";
        cin >> id;
        owner_object = fee_doc.owner_find_by_id(id);
        
        if (owner_object.owner_get_id() == 0 && fee_doc.fee_find_by_id(id))
        {
            cout << "================================================================================" << endl;
            cout << "û�в鵽��Ӧҵ����Ϣ�������ԣ�" << endl;
            system("pause");
        }
        else
        {
            cout << "================================================================================" << endl;
            cout << "ҵ��"<<owner_object.owner_get_name()<<"��ϢΪ:" << endl;
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
        cout << "=                                  ͳ��                                        =" << endl;
        cout << "================================================================================" << endl;
        cout << "=                                                                              =" << endl;
        cout << "=                               1.�鿴�ļ�                                     =" << endl;
        cout << "=                               2.ɾ���ļ�                                     =" << endl;
        cout << "=                               3.����ͳ��                                     =" << endl;
        cout << "=                               4.����                                         =" << endl;
        cout << "=                                                                              =" << endl;
        cout << "================================================================================" << endl;
        cout << "��ѡ���Ӧ����: ";
        cin >> choice;
        while (choice == 0 || choice > 4) {
            cout << "�������ֲ���ȷ������������1-4: ";
            cin >> choice;
        }
        switch (choice) {
        case 1:
            system("cls");
            cout << "================================================================================" << endl;
            cout << "��ѡ��鿴���ļ�(1.¥������ 2.�������� ): ";
            cin >> choice;
            while (choice == 0 || choice > 2) {
                cout << "�������ֲ���ȷ������������1��2: ";
                cin >> choice;
            }
            flag_bool = doc_object.fee_statistics_read(choice);
            break;
        case 2:
            system("cls");
            cout << "================================================================================" << endl;
            cout << "�Ƿ����֮ǰ�ļ����ݣ�(y/n): ";
            cin >> choice_char;
            if (choice_char == 'y' || choice_char == 'Y')
            {
                cout << "ѡ����յ������ļ�(1.¥�� 2.���� 3.ȫ��): ";
                cin >> choice;
                while (choice == 0 || choice > 3) {
                    cout << "�������ֲ���ȷ������������1��3: ";
                    cin >> choice;
                }
                flag_bool = doc_object.fee_clean_unpaid(choice);
            }
            break;
        case 3:
            system("cls");
            cout << "================================================================================" << endl;
            cout << "��ѡ������ʽ(1.¥�� 2.���� ): ";
            cin >> choice;
            while (choice == 0 || choice > 2) {
                cout << "�������ֲ���ȷ������������1��2: ";
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
        cout << "������ά��ҵ����id(¥��+����): ";
        cin >> id_repair;
        if (id_repair == 0) break;
        owner_object = doc_object.owner_find_by_id(id_repair);
        if (owner_object.owner_get_id() == 0) {
            cout << "================================================================================" << endl;
            cout << "δ�ҵ���Ӧ�û�!����������!" << endl;
            flag_bool = true;
        }
        else {
            cout << "================================================================================" << endl;
            cout << "�ҵ��ˣ�\n�û���ϢΪ: " << endl;
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
        cout << "��������Ҫɾ����ҵ����id(¥��+����): ";
        cin >> id;
        cout << "������ά�޵Ǽ�ʱ��: " << endl;
        cout << "��: ";
        cin >> year;
        cout << "��: ";
        cin >> month;
        cout << "��: ";
        cin >> day;
        cout << "ʱ: ";
        cin >> hour;
        cout << "��: ";
        cin >> minute;
        if (id == 0) break;
        repair_object = doc_object.repair_find_by_id(id);
        if (repair_object.repair_get_id() == 0)
        {
            cout << "================================================================================" << endl;
            cout << "û���ҵ���Ӧҵ���������ԣ�(id=0ʱ�˳�)" << endl;;
            flag_bool = true;
        }
        else {
            cout << "�ҵ���! " << endl;
            repair_object.repair_print();
            owner_object = doc_object.owner_find_by_id(id);

            cout << "================================================================================" << endl;
            cout << "ȷ��ɾ��" << owner_object.owner_get_name() << "����Ϣ��(y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                flag_bool = doc_object.repair_delete(id,year,month,day,hour,minute);
                if (flag_bool){
                    cout << "================================================================================" << endl;
                    cout<<"ɾ���ɹ�!"<<endl;
                    flag_bool = false;
                    system("pause");
                }
                else{
                    cout << "================================================================================" << endl;
                    cout << "ɾ��ʧ�ܣ�������!������ʱ����ˡ�" << endl;
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
    cout << "��������Ҫ���ҵ�ҵ����id(¥��+����): ";
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

        //������Լ�һ��ѯ���Ƿ����
        cout << "�Ƿ������(1.���� 2.�˳�): ";
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
        cout << "�����빫��Ǽ�ʱ��: " << endl;
        cout << "��: ";
        cin >> year;
        cout << "��: ";
        cin >> month;
        cout << "��: ";
        cin >> day;
        cout << "ʱ: ";
        cin >> hour;
        cout << "��: ";
        cin >> minute;
        if (year == 0)break;
    
        cout << "================================================================================" << endl;
        cout << "ȷ��ɾ����(y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            flag_bool = doc_object.announcement_delete(year, month, day, hour, minute);
            if (flag_bool) {
                cout << "================================================================================" << endl;
                cout << "ɾ���ɹ�!" << endl;
                flag_bool = false;
                system("pause");
            }
            else {
                cout << "================================================================================" << endl;
                cout << "ɾ��ʧ�ܣ�������!" << endl;
                system("pause");
            }

        }
        else break;
    }

}