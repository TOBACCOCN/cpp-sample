#include <iostream>
#include <string>
#include "person.h"
#define MAX 10
using namespace std;

void showMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.查找联系人  *****" << endl;
	cout << "*****  4.删除联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}

struct AddressBook {
	Person persons[MAX];
	int mSize;
};

void addPerson(struct AddressBook* addressBook) {
	if (addressBook->mSize >= MAX) {
		cout << "联系人已满" << endl;
	} else {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		int gender;
		cout << "请输入性别（1：男，2：女）" << endl;
		cin >> gender;
		while (gender != 1 && gender != 2) {
			cout << "请输入性别（1：男，2：女）" << endl;
			cin >> gender;
		}
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		string phone;
		cout << "请输入联系电话" << endl;
		cin >> phone;
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		Person person(name, gender, age, phone, address);
		addressBook->persons[addressBook->mSize++] = person;
		cout << "添加完成" << endl;
	}
}

void showPerson(Person* person) {
	cout << "姓名：" << person->getName() << "\t";
	cout << "性别：" << (person->getGender() == 1 ? "男" : "女") << "\t";
	cout << "年龄：" << person->getAge() << "\t";
	cout << "联系电话：" << person->getPhone() << "\t";
	cout << "地址：" << person->getAddress() << endl;
}

void showPerson(struct AddressBook* addressBook) {
	if (addressBook->mSize == 0) {
		cout << "没有联系人" << endl;
	} else {
		for (int i = 0; i < addressBook->mSize; ++i) {
			showPerson(&(addressBook->persons[i]));
		}
	}
}

void searchPerson(struct AddressBook* addressBook) {
	if (addressBook->mSize == 0) {
		cout << "联系人为空" << endl;
	}
	else {
		string name;
		cout << "请输入需要查找的人的姓名" << endl;
		cin >> name;
		bool found = false;
		for (int i = 0; i < addressBook->mSize; ++i) {
			if (addressBook->persons[i].getName() == name) {
				found = true;
				showPerson(&(addressBook->persons[i]));
			}
		}
		if (!found) {
			cout << "查无此人" << endl;
		}
	}
}

void deletePerson(struct AddressBook* addressBook, int index) {
	for (int i = index; i < addressBook->mSize; ++i) {
		addressBook->persons[i] = addressBook->persons[i + 1];
	}
	addressBook->mSize--;
}

void deletePerson(struct AddressBook* addressBook) {
	if (addressBook->mSize == 0) {
		cout << "联系人为空" << endl;
	}
	else {
		string name;
		cout << "请输入需要删除的人的姓名" << endl;
		cin >> name;
		bool found = false;
		for (int i = 0; i < addressBook->mSize; ++i) {
			if (addressBook->persons[i].getName() == name) {
				showPerson(&(addressBook->persons[i]));
				deletePerson(addressBook, i);
				--i;
				cout << "删除成功" << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "查无此人" << endl;
		}
	}
}

void updatePerson(struct AddressBook* addressBook) {
	if (addressBook->mSize == 0) {
		cout << "联系人为空" << endl;
	}
	else {
		string name;
		cout << "请输入需要更新的人的姓名" << endl;
		cin >> name;
		bool found = false;
		for (int i = 0; i < addressBook->mSize; ++i) {
			if (addressBook->persons[i].getName() == name) {
				cout << "查到一人" << endl;
				showPerson(&(addressBook->persons[i]));
				int gender;
				cout << "请输入性别（1：男，2：女）" << endl;
				cin >> gender;
				while (gender != 1 && gender != 2) {
					cout << "请输入性别（1：男，2：女）" << endl;
					cin >> gender;
				}
				int age;
				cout << "请输入年龄" << endl;
				cin >> age;
				string phone;
				cout << "请输入联系电话" << endl;
				cin >> phone;
				string address;
				cout << "请输入地址" << endl;
				cin >> address;
				Person person(name, gender, age, phone, address);
				addressBook->persons[i] = person;
				showPerson(&person);
				cout << "修改成功" << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "查无此人" << endl;
		}
	}
}

void cleanPerson(struct AddressBook* addressBook) {
	if (addressBook->mSize == 0) {
		cout << "没有联系人" << endl;
	}else {
		addressBook->mSize = 0;
		cout << "联系人已清空" << endl;
	}
}

//int main() {
//	struct AddressBook addressBook;
//	addressBook.mSize = 0;
//	int select = 0;
//	while (true) {	
//		showMenu();
//		cin >> select;
//		switch (select) {
//		case 1:
//			addPerson(&addressBook);
//			break;
//		case 2:
//			showPerson(&addressBook);
//			break;
//		case 3:
//			searchPerson(&addressBook);
//			break;
//		case 4:
//			deletePerson(&addressBook);
//			break;
//		case 5:
//			updatePerson(&addressBook);
//			break;
//		case 6:
//			cleanPerson(&addressBook);
//			break;
//		case 0:
//			cout << "欢迎下次使用" << endl;
//			system("pause");
//			return 0;
//		default:
//			break;
//		}
//		system("pause");
//		system("cls");
//	}
//}