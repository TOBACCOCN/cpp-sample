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
	//cout << "Ĭ�Ϲ��캯�� starting" << endl;
}

Person::Person(string name, int gender, int age, string phone, string address) {
	//cout << "�вι��캯�� starting" << endl;
	this->name = name;
	this->gender = gender;
	this->age = age;
	this->phone = phone;
	this->address = address;
}

//Person::Person(Person& person) {
//	cout << "�������캯�� starting" << endl;
//	name = person.getName();
//	gender = person.getGender();
//	age = person.getAge();
//	phone = person.getPhone();
//	address = person.getAddress();
//}

// Ŀǰ�ƺ�����д�����ֻ��д��ͷ�ļ���
//Person::~Person() {
//	cout << "�������� starting" << endl;
//}

//Person Person::operator+(Person person) {
//	Person temp;
//	temp.setAge(this->getAge() + person.getAge());
//	return temp;
//}