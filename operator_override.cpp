#include <iostream>
#include <string>
#include "person.h"
using namespace std;

Person operator+(Person& p1, Person& p2) {
	Person temp;
	temp.setAge(p1.getAge() + p2.getAge());
	return temp;
}

// 重载左移操作符只能通过全局函数重载，因为成员函数重载时在 << 左边的只能是成员函数所属类的实例
ostream& operator<<(ostream& cout, Person person) {
	cout << person.getName() << "\t" << (person.getGender() == 1 ? "男" : "女") << "\t" << person.getAge()<< "\t" << person.getPhone() << "\t" << person.getAddress() ;
	return cout;
}

namespace operator_override {
	void test01() {
		Person p1;
		p1.setAge(23);
		Person p2;
		p2.setAge(24);
		Person p = p1 + p2;		// 如果是通过成员函数重载，本质是 Person p = p1.operator+(p2);
		cout << "age of p: " << p.getAge() << endl;
	}

	void test02() {
		Person p1;
		p1.setAge(13);
		Person p2;
		p2.setAge(14);
		Person p = p1 + p2;		// 如果是通过全局函数重载，本质是 Person p = operator+(p1, p2);
		cout << "age of p: " << p.getAge() << endl;
	}

	void test03() {
		Person p("张三", 1, 23, "13999999999", "北京");
		cout << p << endl;
	}

	void test04() {
		Person p("张三", 1, 23, "13999999999", "北京");
		cout << ++p << endl;
	}

	void test05() {
		Person p("张三", 1, 23, "13999999999", "北京");
		cout << p++ << endl;
		cout << p << endl;
	}

	void test06() {
		Person p1("张三", 1, 23, "13999999999", "北京");
		Person p2("李四", 1, 24, "13888888888", "上海");
		Person p3("王五", 1, 25, "13666666666", "天津");
		p1 = p2 = p3;
		cout << p1 << endl;
	}

	void test07() {
		Person p1("张三", 1, 23, "13999999999", "北京");
		Person p2("张三", 1, 23, "13999999999", "上海");
		cout << "p1 == p2: " << (p1 == p2) << endl;
	}

	void test08() {
		Person p1("张三", 1, 23, "13999999999", "北京");
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