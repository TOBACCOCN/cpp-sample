#include "person.h"

void Person::setName(string name) {
	this->name = name;
}

void Person::setGender(int gender) {
	this->gender = gender;
}

void Person::setAge(int age) {
	this->age = age;
}

void Person::setPhone(string phone) {
	this->phone = phone;
}
void Person::setAddress(string age) {
	this->address = address;
}

string Person::getName() {
	return name;
}

int Person::getAge() {
	return age;
}

int Person::getGender() {
	return gender;
}

string Person::getPhone() {
	return phone;
}
string Person::getAddress() {
	return address;
}

Person::Person() {
	//cout << "默认构造函数 starting" << endl;
}

Person::Person(string name, int gender, int age, string phone, string address) {
	//cout << "有参构造函数 starting" << endl;
	this->name = name;
	this->gender = gender;
	this->age = age;
	this->phone = phone;
	this->address = address;
}

//Person::Person(Person& person) {
//	cout << "拷贝构造函数 starting" << endl;
//	name = person.getName();
//	gender = person.getGender();
//	age = person.getAge();
//	phone = person.getPhone();
//	address = person.getAddress();
//}

// 目前似乎不能写在这里，只能写在头文件中
//Person::~Person() {
//	cout << "析构函数 starting" << endl;
//}

//Person Person::operator+(Person person) {
//	Person temp;
//	temp.setAge(this->getAge() + person.getAge());
//	return temp;
//}