#include <iostream>
#include <string>
#include "person.h"
using namespace std;

Person operator+(Person& p1, Person& p2) {
	Person temp;
	temp.setAge(p1.getAge() + p2.getAge());
	return temp;
}

// �������Ʋ�����ֻ��ͨ��ȫ�ֺ������أ���Ϊ��Ա��������ʱ�� << ��ߵ�ֻ���ǳ�Ա�����������ʵ��
ostream& operator<<(ostream& cout, Person person) {
	cout << person.getName() << "\t" << (person.getGender() == 1 ? "��" : "Ů") << "\t" << person.getAge()<< "\t" << person.getPhone() << "\t" << person.getAddress() ;
	return cout;
}

namespace operator_override {
	void test01() {
		Person p1;
		p1.setAge(23);
		Person p2;
		p2.setAge(24);
		Person p = p1 + p2;		// �����ͨ����Ա�������أ������� Person p = p1.operator+(p2);
		cout << "age of p: " << p.getAge() << endl;
	}

	void test02() {
		Person p1;
		p1.setAge(13);
		Person p2;
		p2.setAge(14);
		Person p = p1 + p2;		// �����ͨ��ȫ�ֺ������أ������� Person p = operator+(p1, p2);
		cout << "age of p: " << p.getAge() << endl;
	}

	void test03() {
		Person p("����", 1, 23, "13999999999", "����");
		cout << p << endl;
	}

	void test04() {
		Person p("����", 1, 23, "13999999999", "����");
		cout << ++p << endl;
	}

	void test05() {
		Person p("����", 1, 23, "13999999999", "����");
		cout << p++ << endl;
		cout << p << endl;
	}

	void test06() {
		Person p1("����", 1, 23, "13999999999", "����");
		Person p2("����", 1, 24, "13888888888", "�Ϻ�");
		Person p3("����", 1, 25, "13666666666", "���");
		p1 = p2 = p3;
		cout << p1 << endl;
	}

	void test07() {
		Person p1("����", 1, 23, "13999999999", "����");
		Person p2("����", 1, 23, "13999999999", "�Ϻ�");
		cout << "p1 == p2: " << (p1 == p2) << endl;
	}

	void test08() {
		Person p1("����", 1, 23, "13999999999", "����");
		p1(2);
		cout << p1 << endl;
	}
}


//int main() {
//	//operator_override::test01();
//	//operator_override::test02();
//	//operator_override::test03();
//	//operator_override::test04();
//	//operator_override::test05();
//	//operator_override::test06();
//	//operator_override::test07();
//	operator_override::test08();
//	system("pause");
//	return 0;
//}