#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int gender;	// 1：男；2：女
	int age;
	string phone;
	string address;
public:
	void setName(string name);
	void setGender(int gender);
	void setAge(int age);
	void setPhone(string phone);
	void setAddress(string address);
	string getName();
	int getGender();
	int getAge();
	string getPhone();
	string getAddress();
	Person();	// 无参构造函数，如果程序员没有实现该函数，程序会自动添加默认的无参构造函数
	Person(string name, int gender, int age, string phone, string address);	// 有参构造方法，也可以认为是无参构造函数的重载函数（1.函数名相同，2.形参数量或类型或顺序不同，跟返回参数没有关系）
	//Person(Person& person);		// 拷贝构造函数，如果程序员没有实现该函数，程序会自动添加拷贝构造函数(复制所有属性)
	// 析构函数，如果程序员没有实现该函数，程序会自动添加默认的析构函数，在销毁该类的实例时会调用该方法
	~Person(){
		//cout << "析构函数 starting" << endl;
	}
	// 通过成员函数重载 + 运算符，注意不要重写拷贝构造函数
	//Person operator+(Person& person) {
	//	Person temp;
	//	temp.setAge(this->getAge() + person.getAge());
	//	return temp;
	//}
	// 重载前置 ++ 运算符，注意返回的是引用 
	Person& operator++() {
		age++;
		return *this;
	}
	// 重载后置 ++运算符，注意返回的不是引用，形参要加 int 占位 
	Person operator++(int) {
		Person temp = *this;
		age++;
		return temp;
	}
	// 重载 = 运算符
	Person& operator=(Person& person) {
		name = person.getName();
		gender = person.getGender();
		age = person.getAge();
		phone = person.getPhone();
		address = person.getAddress();
		return *this;
	}
	// 重载 == 关系运算符
	bool operator==(Person& person) {
		return this->getName() == person.getName() && this->getGender() == person.getGender() && this->getAge() == person.getAge()
			&& this->getPhone() == person.getPhone() && this->getAddress() == person.getAddress();
	}
	// 重载函数调用运算符，格式不固定，入参出参任意，也成为仿函数（调用时跟函数调用格式很像）
	void operator()(int age) {
		this->setAge(this->getAge() + age);
	}

};