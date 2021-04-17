#pragma once
#include <iostream>
#include <string>
using namespace std;

// 类模板分文件编写时，一般将头文件和源文件合并成 hpp 文件
// 也可以头文件和源文件分开，其他业务类要用该类模板中的逻辑时，引入类模板 cpp 源文件
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