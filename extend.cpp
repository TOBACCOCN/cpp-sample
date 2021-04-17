#include <iostream>
#include <string>
using namespace std;

class Parent {
public:
	//string name;
	//int age;
	Parent() {
		cout << "Parent constructor" << endl;
	}
	~Parent() {
		cout << "Parent desstructor" << endl;
	}
};

class Child : Parent {
public:
	//string name;
	//int age;
	Child() {
		cout << "Child constructor" << endl;
	}
	~Child() {
		cout << "Child desstructor" << endl;
	}
};

namespace extend {
	void test01() {
		Child child;
	}
}

//int main() {
//	extend::test01();
//	system("pause");
//	return 0;
//}