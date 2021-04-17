#include <iostream>
#include <string>
#include "person.h"
using namespace std;

namespace constructor {
	void test01() {
		// 默认构造函数，不能使用 Person person(); 这样会被认为是在声明函数
		Person person;
		//Person person2 = Person();	// 存在多个构造函数时，不支持这种写法
	}

	void test02() {
		// 有参构造函数
		Person person("张三", 1, 23, "13888888888", "北京");
		//Person person2 = Person("张三", 1, 23, "13888888888", "北京");	// 存在多个构造函数时，不支持这种写法
	}
}

//int main() {
//	constructor::test01();
//	//constructor::test02();
//	system("pause");
//	return 0;
//}