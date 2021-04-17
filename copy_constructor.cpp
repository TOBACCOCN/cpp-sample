#include <iostream>
#include <string>
#include "person.h"
using namespace std;

namespace copy_constructor {
	// ע�⣺��������Ϊ Person& ʱ������ÿ������캯��
	void showPerson(Person person) {
		cout << "������" << person.getName() << "\t";
		cout << "�Ա�" << (person.getGender() == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << person.getAge() << "\t";
		cout << "�ֻ��ţ�" << person.getPhone() << "\t";
		cout << "��ַ��" << person.getAddress() << endl;
	}

	// ֱ�ӵ��ÿ������캯��
	void test01() {
		Person person;
		person.setName("����");
		person.setGender(1);
		person.setAge(23);
		person.setAddress("����");
		Person person2(person);
		showPerson(person2);
	}

	// ��������������ʱ����ÿ������캯��
	void test02() {
		Person person;
		person.setName("����");
		person.setGender(1);
		person.setAge(23);
		person.setAddress("����");
		showPerson(person);
	}

	// ��������������ʱ����ÿ������캯��
	Person test03() {
		Person person;
		person.setName("����");
		person.setGender(1);
		person.setAge(23);
		person.setAddress("����");
		return person;
	}
}


//int main() {
//	copy_constructor::test01();
//	//copy_constructor::test02();
//	//copy_constructor::test03();
//	system("pause");
//	return 0;
//}