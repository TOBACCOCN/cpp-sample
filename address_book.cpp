#include <iostream>
#include <string>
#include "person.h"
#define MAX 10
using namespace std;

void showMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.������ϵ��  *****" << endl;
	cout << "*****  4.ɾ����ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}

struct AddressBook {
	Person persons[MAX];
	int mSize;
};

void addPerson(struct AddressBook* addressBook) {
	if (addressBook->mSize >= MAX) {
		cout << "��ϵ������" << endl;
	} else {
		string name;
		cout << "����������" << endl;
		cin >> name;
		int gender;
		cout << "�������Ա�1���У�2��Ů��" << endl;
		cin >> gender;
		while (gender != 1 && gender != 2) {
			cout << "�������Ա�1���У�2��Ů��" << endl;
			cin >> gender;
		}
		int age;
		cout << "����������" << endl;
		cin >> age;
		string phone;
		cout << "��������ϵ�绰" << endl;
		cin >> phone;
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		Person person(name, gender, age, phone, address);
		addressBook->persons[addressBook->mSize++] = person;
		cout << "������" << endl;
	}
}

void showPerson(Person* person) {
	cout << "������" << person->getName() << "\t";
	cout << "�Ա�" << (person->getGender() == 1 ? "��" : "Ů") << "\t";
	cout << "���䣺" << person->getAge() << "\t";
	cout << "��ϵ�绰��" << person->getPhone() << "\t";
	cout << "��ַ��" << person->getAddress() << endl;
}

void showPerson(struct AddressBook* addressBook) {
	if (addressBook->mSize == 0) {
		cout << "û����ϵ��" << endl;
	} else {
		for (int i = 0; i < addressBook->mSize; ++i) {
			showPerson(&(addressBook->persons[i]));
		}
	}
}

void searchPerson(struct AddressBook* addressBook) {
	if (addressBook->mSize == 0) {
		cout << "��ϵ��Ϊ��" << endl;
	}
	else {
		string name;
		cout << "��������Ҫ���ҵ��˵�����" << endl;
		cin >> name;
		bool found = false;
		for (int i = 0; i < addressBook->mSize; ++i) {
			if (addressBook->persons[i].getName() == name) {
				found = true;
				showPerson(&(addressBook->persons[i]));
			}
		}
		if (!found) {
			cout << "���޴���" << endl;
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
		cout << "��ϵ��Ϊ��" << endl;
	}
	else {
		string name;
		cout << "��������Ҫɾ�����˵�����" << endl;
		cin >> name;
		bool found = false;
		for (int i = 0; i < addressBook->mSize; ++i) {
			if (addressBook->persons[i].getName() == name) {
				showPerson(&(addressBook->persons[i]));
				deletePerson(addressBook, i);
				--i;
				cout << "ɾ���ɹ�" << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "���޴���" << endl;
		}
	}
}

void updatePerson(struct AddressBook* addressBook) {
	if (addressBook->mSize == 0) {
		cout << "��ϵ��Ϊ��" << endl;
	}
	else {
		string name;
		cout << "��������Ҫ���µ��˵�����" << endl;
		cin >> name;
		bool found = false;
		for (int i = 0; i < addressBook->mSize; ++i) {
			if (addressBook->persons[i].getName() == name) {
				cout << "�鵽һ��" << endl;
				showPerson(&(addressBook->persons[i]));
				int gender;
				cout << "�������Ա�1���У�2��Ů��" << endl;
				cin >> gender;
				while (gender != 1 && gender != 2) {
					cout << "�������Ա�1���У�2��Ů��" << endl;
					cin >> gender;
				}
				int age;
				cout << "����������" << endl;
				cin >> age;
				string phone;
				cout << "��������ϵ�绰" << endl;
				cin >> phone;
				string address;
				cout << "�������ַ" << endl;
				cin >> address;
				Person person(name, gender, age, phone, address);
				addressBook->persons[i] = person;
				showPerson(&person);
				cout << "�޸ĳɹ�" << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "���޴���" << endl;
		}
	}
}

void cleanPerson(struct AddressBook* addressBook) {
	if (addressBook->mSize == 0) {
		cout << "û����ϵ��" << endl;
	}else {
		addressBook->mSize = 0;
		cout << "��ϵ�������" << endl;
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
//			cout << "��ӭ�´�ʹ��" << endl;
//			system("pause");
//			return 0;
//		default:
//			break;
//		}
//		system("pause");
//		system("cls");
//	}
//}