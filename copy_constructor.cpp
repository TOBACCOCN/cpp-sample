#include <iostream>
#include <string>
#include "person.h"
using namespace std;

namespace copy_constructor {
	// 注意：参数类型为 Person& 时不会调用拷贝构造函数
	void showPerson(Person person) {
		cout << "姓名：" << person.getName() << "\t";
		cout << "性别：" << (person.getGender() == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << person.getAge() << "\t";
		cout << "手机号：" << person.getPhone() << "\t";
		cout << "地址：" << person.getAddress() << endl;
	}

	// 直接调用拷贝构造函数
	void test01() {
		Person person;
		person.setName("张三");
		person.setGender(1);
		person.setAge(23);
		person.setAddress("北京");
		Person person2(person);
		showPerson(person2);
	}

	// 对象作参数传递时会调用拷贝构造函数
	void test02() {
		Person person;
		person.setName("张三");
		person.setGender(1);
		person.setAge(23);
		person.setAddress("北京");
		showPerson(person);
	}

	// 对象作参数返回时会调用拷贝构造函数
	Person test03() {
		Person person;
		person.setName("张三");
		person.setGender(1);
		person.setAge(23);
		person.setAddress("北京");
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