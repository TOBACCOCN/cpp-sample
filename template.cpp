#include <iostream>
#include <string>
#include "person.hpp"
using namespace std;

void swap(int& a, int& b) {
	int temp = a * 2;
	a = b;
	b = temp;
}

// 函数模板
template <typename T>
void swapTemp(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//	与 swap(T& a, T& b) 发生重载
template <typename T>
void swapTemp(T& a, T& b, T& c) {
	//template<T> swapTemp(T& a, T& b, T& c) {
	T temp = a;
	a = b;
	b = c;
	c = temp;
}

// 下文定义函数模板时需要先声明该 Person 类模板
template <class T1, class T2>
class Person;

// 该函数模板作为 Person 的友元函数时的函数模板定义
template <class T1, class T2>
void friendOutShow(Person<T1, T2>& person) {
	cout << "name: " << person.name << ", age: " << person.age << endl;
}

// 类模板，可以有默认模板参数
template <class T1, class T2>
class Person {
//private:
public:
	T1 name;
	T2 age;
	Person() {
	}
	Person(T1 name, T2 age);
	void show() {
		cout << "name: " << name << ", age: " << age << endl;
	}
	// 类模板中定义全局函数作为友元函数
	friend void friendShow(Person<T1, T2>& person) {
		cout << "name: " << person.name << ", age: " << person.age << endl;
	}
	// 类模板类内声明，类外定义全局函数作为友元函数，需要先定义该模板函数，类内声明友元函数时，需要传空模板参数列表
	friend void friendOutShow<>(Person<T1, T2>& person);
};

// 类模板成员函数类内声明，类外定义时，不光要加作用域，还有加模板参数列表
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

// 子类继承类模板时，必须指定模板参数类型
class Student : Person<string, int> {

};

// 子类继承类模板时，或者将父类的模板参数类型开放出来，让调用者传入模板参数类型
template <class T1, class T2>
class Student1 : public Person<T1, T2> {

};

class Person1 {
public:
	string name;
	int age;
	void show1() {
	}
};

class Person2 {
public:
	string name;
	int age;
	void show2() {
	}
};

template <class T>
class MyClass {
public:
	T obj;
	void fun1() {
		obj.show1();
	}
	void fun2() {
		obj.show2();
	}
};

// 类模板对象作参数，模板参数直接指定，一般用此方法
void show(Person<string, int>& person) {
	cout << "name: " << person.name << ", age: " << person.age << endl;
}

// 类模板对象作参数，模板参数再模板化
template <typename T1, typename T2>
void show1(Person<T1, T2>& person) {
	cout << "T1: " << typeid(T1).name() << ", T2: " << typeid(T2).name() << endl;
	cout << "name: " << person.name << ", age: " << person.age << endl;
}

// 类模板对象作参数，将参数类模板化
template <typename T>
void show2(T& person) {
	cout << "T: " << typeid(T).name() << endl;
	cout << "name: " << person.name << ", age: " << person.age << endl;
}

namespace temp {
	void test01() {
		int a = 10;
		int b = 100;
		// 当普通函数和模板函数都符合调用时，优先使用普通函数
		swap(a, b);
		// 可以添加通过[空]模板参数调用模板函数
		swap<>(a, b);	// 标准库自带该模板函数
		swap<int>(a, b);
		cout << "a is " << a << ", b is " << b << endl;
	}

	void test02() {
		int a = 10;
		int b = 100;
		//swapTemp<>(a, b);
		cout << "a is " << a << ", b is " << b << endl;
	}

	void test03() {
		int a = 10;
		int b = 100;
		int c = 1000;
		swapTemp(a, b, c);
		cout << "a is " << a << ", b is " << b << ", c is " << c << endl;
	}

	void test04() {
		char a = 'a';
		char b = 'b';
		// 普通函数与模板函数 swap 似乎都符合，但是普通函数需要类型转换，所以调用的是模板函数
		swap(a, b);
		cout << "a is " << a << ", b is " << b << endl;
	}

	void test05() {
		//Person<> p("tom", 24);	// 无法自动类型推导
		Person<string, int> p("tom", 24);
		Person<string, int> p1("张三", 23);
		p.show();
		p1.show();
	}

	void test06() {
		MyClass<Person1> myClass;
		myClass.fun1();
		//myClass.fun2();	// 运行时报错，fun2 中 obj.show2 实际调用 Person1 的 show2，而 Person1 没有该方法
	}

	void test07() {
		Person<string, int> p("孙悟空", 500);
		show(p);
		show1(p);
		show2(p);
	}

	void test08() {
		Student stu;
	}
	void test09() {
		Student1<string, int> stu;
	}

	void test10() {
		HppPerson<string, int> p("hpp-person", 23);
		p.show();
	}

	void test11() {
		Person<string, int> p("friend-person", 24);
		friendShow(p);
	}

	void test12() {
		Person<string, int> p("friend-out-person", 24);
		friendOutShow(p);
	}
}

//int main() {
//	//temp::test01();
//	//temp::test02();
//	//temp::test03();
//	//temp::test04();
//	//temp::test05();
//	//temp::test06();
//	//temp::test07();
//	//temp::test08();
//	//temp::test09();
//	//temp::test10();
//	//temp::test11();
//	temp::test12();
//	system("pause");
//	return 0;
//}