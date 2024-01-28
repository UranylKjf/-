#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
#define Max 100
//联系人结构体
typedef struct Person {
	string name;//姓名
	int sex;//男1女2
	int age;//年龄
	string phone;//手机号
	string address;//地址
}Person;
//通讯录结构体
typedef struct AddressBooks {
	Person arr[Max];
	int size;
}AddressBooks;
void Add(AddressBooks*abs) {
	//判断通讯录是否满
	if (abs->size == Max) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		abs->size++;
		cout << "请输入姓名" << endl;
		cin >> abs->arr[abs->size - 1].name;
		cout << "请输入性别" << endl;
		cout << "1、代表男生" << endl;
		cout << "2、代表女生" << endl;
		while (1) {
			cin >> abs->arr[abs->size - 1].sex;
			if (abs->arr[abs->size - 1].sex == 1 || abs->arr[abs->size - 1].sex == 2) {
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}
		cout << "请输入年龄，范围0-150" << endl;
		while (1) {
			cin >> abs->arr[abs->size - 1].age;
			if (abs->arr[abs->size - 1].age >= 0 && abs->arr[abs->size - 1].age <= 150) {
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}
		cout << "请输入手机号" << endl;
		cin >> abs->arr[abs->size - 1].phone;
		cout << "请输入家庭住址" << endl;
		cin >> abs->arr[abs->size - 1].address;
		cout << "恭喜您添加成功！" << endl;
		system("pause"); //按任意键继续
		system("cls");   //清屏操作
	}
}
void showPerson(AddressBooks abs) {
	if (abs.size == 0) {
		cout << "通讯录是空的" << endl;
	}
	else {
		for (int i = 0; i < abs.size; i++) {
			cout << "姓名：" << abs.arr[i].name << "\t";
			cout << "性别：" << (abs.arr[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄: " << abs.arr[i].age << "\t";
			cout << "电话: " << abs.arr[i].phone << "\t";
			cout << "住址: " << abs.arr[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
//判断是否存在
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
	cout << "请输入要删除的姓名" << endl;
	cin >> name;
	int ret=isExist(*abs, name);
	if (ret == -1) {
		cout << "查无此人，删除失败" << endl;
	}
	else {
		cout << "删除成功" << endl;
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
	cout << "请输入要查找的姓名" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人，查找失败" << endl;
	}
	else {
		cout << "姓名：" << abs.arr[ret].name << "\t";
		cout << "性别：" << (abs.arr[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄: " << abs.arr[ret].age << "\t";
		cout << "电话: " << abs.arr[ret].phone << "\t";
		cout << "住址: " << abs.arr[ret].address << endl;
	}
	system("pause");
	system("cls");
}
void modify(AddressBooks* abs) {
	string name;
	cout << "请输入要修改的姓名" << endl;
	cin >> name;
	int ret = isExist(*abs, name);
	if (ret == -1) {
		cout << "查无此人，查找失败" << endl;
	}
	else {
		cout << "请输入性别" << endl;
		cout << "1、代表男生" << endl;
		cout << "2、代表女生" << endl;
		while (1) {
			cin >> abs->arr[ret].sex;
			if (abs->arr[ret].sex == 1 || abs->arr[ret].sex == 2) {
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}
		cout << "请输入年龄，范围0-150" << endl;
		while (1) {
			cin >> abs->arr[ret].age;
			if (abs->arr[ret].age >= 0 && abs->arr[ret].age <= 150) {
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}
		cout << "请输入手机号" << endl;
		cin >> abs->arr[ret].phone;
		cout << "请输入家庭住址" << endl;
		cin >> abs->arr[ret].address;
		cout << "恭喜您修改成功！" << endl;
	}
	system("pause");
	system("cls");
}
void clearAll(AddressBooks* abs) {
	abs->size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}
void showMenu() {
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
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
			cout << "欢迎下次使用！" << endl;
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