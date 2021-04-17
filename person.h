#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int gender;	// 1���У�2��Ů
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
	Person();	// �޲ι��캯�����������Աû��ʵ�ָú�����������Զ����Ĭ�ϵ��޲ι��캯��
	Person(string name, int gender, int age, string phone, string address);	// �вι��췽����Ҳ������Ϊ���޲ι��캯�������غ�����1.��������ͬ��2.�β����������ͻ�˳��ͬ�������ز���û�й�ϵ��
	//Person(Person& person);		// �������캯�����������Աû��ʵ�ָú�����������Զ���ӿ������캯��(������������)
	// �����������������Աû��ʵ�ָú�����������Զ����Ĭ�ϵ����������������ٸ����ʵ��ʱ����ø÷���
	~Person(){
		//cout << "�������� starting" << endl;
	}
	// ͨ����Ա�������� + �������ע�ⲻҪ��д�������캯��
	//Person operator+(Person& person) {
	//	Person temp;
	//	temp.setAge(this->getAge() + person.getAge());
	//	return temp;
	//}
	// ����ǰ�� ++ �������ע�ⷵ�ص������� 
	Person& operator++() {
		age++;
		return *this;
	}
	// ���غ��� ++�������ע�ⷵ�صĲ������ã��β�Ҫ�� int ռλ 
	Person operator++(int) {
		Person temp = *this;
		age++;
		return temp;
	}
	// ���� = �����
	Person& operator=(Person& person) {
		name = person.getName();
		gender = person.getGender();
		age = person.getAge();
		phone = person.getPhone();
		address = person.getAddress();
		return *this;
	}
	// ���� == ��ϵ�����
	bool operator==(Person& person) {
		return this->getName() == person.getName() && this->getGender() == person.getGender() && this->getAge() == person.getAge()
			&& this->getPhone() == person.getPhone() && this->getAddress() == person.getAddress();
	}
	// ���غ����������������ʽ���̶�����γ������⣬Ҳ��Ϊ�º���������ʱ���������ø�ʽ����
	void operator()(int age) {
		this->setAge(this->getAge() + age);
	}

};