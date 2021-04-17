#pragma once
#include <iostream>
#include <string>
using namespace std;

// ��ģ����ļ���дʱ��һ�㽫ͷ�ļ���Դ�ļ��ϲ��� hpp �ļ�
// Ҳ����ͷ�ļ���Դ�ļ��ֿ�������ҵ����Ҫ�ø���ģ���е��߼�ʱ��������ģ�� cpp Դ�ļ�
template <class T1, class T2>
class HppPerson {
public:
	T1 name;
	T2 age;
	HppPerson(T1 name, T2 age);
	void show();
};

template <class T1, class T2>
HppPerson<T1, T2>::HppPerson(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

template <class T1, class T2>
void HppPerson<T1, T2>::show() {
	cout << "name: " << this->name << ", age: " << this->age << endl;
}