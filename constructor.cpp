#include <iostream>
#include <string>
#include "person.h"
using namespace std;

namespace constructor {
	void test01() {
		// Ĭ�Ϲ��캯��������ʹ�� Person person(); �����ᱻ��Ϊ������������
		Person person;
		//Person person2 = Person();	// ���ڶ�����캯��ʱ����֧������д��
	}

	void test02() {
		// �вι��캯��
		Person person("����", 1, 23, "13888888888", "����");
		//Person person2 = Person("����", 1, 23, "13888888888", "����");	// ���ڶ�����캯��ʱ����֧������д��
	}
}

//int main() {
//	constructor::test01();
//	//constructor::test02();
//	system("pause");
//	return 0;
//}