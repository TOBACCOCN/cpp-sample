#include <iostream>
#include <string>
#include "person.hpp"
using namespace std;

void swap(int& a, int& b) {
	int temp = a * 2;
	a = b;
	b = temp;
}

// ����ģ��
template <typename T>
void swapTemp(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//	�� swap(T& a, T& b) ��������
template <typename T>
void swapTemp(T& a, T& b, T& c) {
	//template<T> swapTemp(T& a, T& b, T& c) {
	T temp = a;
	a = b;
	b = c;
	c = temp;
}

// ���Ķ��庯��ģ��ʱ��Ҫ�������� Person ��ģ��
template <class T1, class T2>
class Person;

// �ú���ģ����Ϊ Person ����Ԫ����ʱ�ĺ���ģ�嶨��
template <class T1, class T2>
void friendOutShow(Person<T1, T2>& person) {
	cout << "name: " << person.name << ", age: " << person.age << endl;
}

// ��ģ�壬������Ĭ��ģ�����
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
	// ��ģ���ж���ȫ�ֺ�����Ϊ��Ԫ����
	friend void friendShow(Person<T1, T2>& person) {
		cout << "name: " << person.name << ", age: " << person.age << endl;
	}
	// ��ģ���������������ⶨ��ȫ�ֺ�����Ϊ��Ԫ��������Ҫ�ȶ����ģ�庯��������������Ԫ����ʱ����Ҫ����ģ������б�
	friend void friendOutShow<>(Person<T1, T2>& person);
};

// ��ģ���Ա�����������������ⶨ��ʱ������Ҫ�������򣬻��м�ģ������б�
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

// ����̳���ģ��ʱ������ָ��ģ���������
class Student : Person<string, int> {

};

// ����̳���ģ��ʱ�����߽������ģ��������Ϳ��ų������õ����ߴ���ģ���������
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

// ��ģ�������������ģ�����ֱ��ָ����һ���ô˷���
void show(Person<string, int>& person) {
	cout << "name: " << person.name << ", age: " << person.age << endl;
}

// ��ģ�������������ģ�������ģ�廯
template <typename T1, typename T2>
void show1(Person<T1, T2>& person) {
	cout << "T1: " << typeid(T1).name() << ", T2: " << typeid(T2).name() << endl;
	cout << "name: " << person.name << ", age: " << person.age << endl;
}

// ��ģ���������������������ģ�廯
template <typename T>
void show2(T& person) {
	cout << "T: " << typeid(T).name() << endl;
	cout << "name: " << person.name << ", age: " << person.age << endl;
}

namespace temp {
	void test01() {
		int a = 10;
		int b = 100;
		// ����ͨ������ģ�庯�������ϵ���ʱ������ʹ����ͨ����
		swap(a, b);
		// �������ͨ��[��]ģ���������ģ�庯��
		swap<>(a, b);	// ��׼���Դ���ģ�庯��
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
		// ��ͨ������ģ�庯�� swap �ƺ������ϣ�������ͨ������Ҫ����ת�������Ե��õ���ģ�庯��
		swap(a, b);
		cout << "a is " << a << ", b is " << b << endl;
	}

	void test05() {
		//Person<> p("tom", 24);	// �޷��Զ������Ƶ�
		Person<string, int> p("tom", 24);
		Person<string, int> p1("����", 23);
		p.show();
		p1.show();
	}

	void test06() {
		MyClass<Person1> myClass;
		myClass.fun1();
		//myClass.fun2();	// ����ʱ����fun2 �� obj.show2 ʵ�ʵ��� Person1 �� show2���� Person1 û�и÷���
	}

	void test07() {
		Person<string, int> p("�����", 500);
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