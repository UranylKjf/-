#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
#define Max 100
//��ϵ�˽ṹ��
typedef struct Person {
	string name;//����
	int sex;//��1Ů2
	int age;//����
	string phone;//�ֻ���
	string address;//��ַ
}Person;
//ͨѶ¼�ṹ��
typedef struct AddressBooks {
	Person arr[Max];
	int size;
}AddressBooks;
void Add(AddressBooks*abs) {
	//�ж�ͨѶ¼�Ƿ���
	if (abs->size == Max) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		abs->size++;
		cout << "����������" << endl;
		cin >> abs->arr[abs->size - 1].name;
		cout << "�������Ա�" << endl;
		cout << "1����������" << endl;
		cout << "2������Ů��" << endl;
		while (1) {
			cin >> abs->arr[abs->size - 1].sex;
			if (abs->arr[abs->size - 1].sex == 1 || abs->arr[abs->size - 1].sex == 2) {
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}
		cout << "���������䣬��Χ0-150" << endl;
		while (1) {
			cin >> abs->arr[abs->size - 1].age;
			if (abs->arr[abs->size - 1].age >= 0 && abs->arr[abs->size - 1].age <= 150) {
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}
		cout << "�������ֻ���" << endl;
		cin >> abs->arr[abs->size - 1].phone;
		cout << "�������ͥסַ" << endl;
		cin >> abs->arr[abs->size - 1].address;
		cout << "��ϲ����ӳɹ���" << endl;
		system("pause"); //�����������
		system("cls");   //��������
	}
}
void showPerson(AddressBooks abs) {
	if (abs.size == 0) {
		cout << "ͨѶ¼�ǿյ�" << endl;
	}
	else {
		for (int i = 0; i < abs.size; i++) {
			cout << "������" << abs.arr[i].name << "\t";
			cout << "�Ա�" << (abs.arr[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "����: " << abs.arr[i].age << "\t";
			cout << "�绰: " << abs.arr[i].phone << "\t";
			cout << "סַ: " << abs.arr[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
//�ж��Ƿ����
int isExist(AddressBooks abs,string name) {
	for (int i = 0; i < abs.size; i++) {
		if (name == abs.arr[i].name) {
			return i;
		}
	}
	return -1;
}
void Delete(AddressBooks* abs) {
	string name;
	cout << "������Ҫɾ��������" << endl;
	cin >> name;
	int ret=isExist(*abs, name);
	if (ret == -1) {
		cout << "���޴��ˣ�ɾ��ʧ��" << endl;
	}
	else {
		cout << "ɾ���ɹ�" << endl;
		for (int i = ret; i < abs->size; i++) {
			abs->arr[i] = abs->arr[i + 1];
		}
		abs->size--;
	}
	system("pause");
	system("cls");
}
void Find(AddressBooks abs) {
	string name;
	cout << "������Ҫ���ҵ�����" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "���޴��ˣ�����ʧ��" << endl;
	}
	else {
		cout << "������" << abs.arr[ret].name << "\t";
		cout << "�Ա�" << (abs.arr[ret].sex == 1 ? "��" : "Ů") << "\t";
		cout << "����: " << abs.arr[ret].age << "\t";
		cout << "�绰: " << abs.arr[ret].phone << "\t";
		cout << "סַ: " << abs.arr[ret].address << endl;
	}
	system("pause");
	system("cls");
}
void modify(AddressBooks* abs) {
	string name;
	cout << "������Ҫ�޸ĵ�����" << endl;
	cin >> name;
	int ret = isExist(*abs, name);
	if (ret == -1) {
		cout << "���޴��ˣ�����ʧ��" << endl;
	}
	else {
		cout << "�������Ա�" << endl;
		cout << "1����������" << endl;
		cout << "2������Ů��" << endl;
		while (1) {
			cin >> abs->arr[ret].sex;
			if (abs->arr[ret].sex == 1 || abs->arr[ret].sex == 2) {
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}
		cout << "���������䣬��Χ0-150" << endl;
		while (1) {
			cin >> abs->arr[ret].age;
			if (abs->arr[ret].age >= 0 && abs->arr[ret].age <= 150) {
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}
		cout << "�������ֻ���" << endl;
		cin >> abs->arr[ret].phone;
		cout << "�������ͥסַ" << endl;
		cin >> abs->arr[ret].address;
		cout << "��ϲ���޸ĳɹ���" << endl;
	}
	system("pause");
	system("cls");
}
void clearAll(AddressBooks* abs) {
	abs->size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
}
void showMenu() {
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
}
int main(){
	AddressBooks abs;
	abs.size = 0;
	int n=0;
	while (1) {
		showMenu();
		cin >> n;
		switch (n) {
		case 1: {
			Add(&abs);
			break;
		}
		case 2: {
			showPerson(abs);
			break;
		}
		case 3: {
			Delete(&abs);
			break;
		}
		case 4: {
			Find(abs);
			break;
		}
		case 5: {
			modify(&abs);
			break;
		}
		case 6: {
			clearAll(&abs);
			break;
		}
		case 0: {
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}
		default:
			break;

		}
	}
	system("pause");
	return 0;
}