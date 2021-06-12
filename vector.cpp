#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << &(v[i]) << " ";
	}
	cout << endl;
}

namespace vect {
	// ���캯��
	void test01() {
		vector<int> v1;
		for (int i = 0; i < 10; ++i) {
			v1.push_back(i * 2);
		}
		cout << "-------------v1-------------" << endl;
		printVector(v1);
		vector<int> v2(v1.begin(), v1.end());
		cout << "-------------v2-------------" << endl;
		printVector(v2);
		vector<int> v3(3, 5);
		cout << "-------------v3-------------" << endl;
		printVector(v3);
		vector<int> v4(v3);
		cout << "-------------v4-------------" << endl;
		printVector(v4);
	}

	// ��ֵ
	void test02() {
		vector<int> v1;
		for (int i = 0; i < 10; ++i) {
			v1.push_back(i * 2);
		}
		cout << "-------------v1-------------" << endl;
		printVector(v1);
		vector<int> v2;
		v2 = v1;
		cout << "-------------v2-------------" << endl;
		printVector(v2);
		vector<int> v3;
		v3.assign(v1.begin(), v1.end());
		cout << "-------------v3-------------" << endl;
		printVector(v3);
		vector<int> v4;
		v4.assign(2, 8);
		cout << "-------------v4-------------" << endl;
		printVector(v4);
	}

	// �����ʹ�С
	void test03() {
		vector<int> v;
		cout << "v is empty: " << v.empty() << endl;
		for (int i = 0; i < 10; ++i) {
			v.push_back(i + 1);
		}
		cout << "size of v is " << v.size() << ", capacity of v is " << v.capacity() << endl;
		cout << "after push_back, v is empty: " << v.empty() << endl;
		v.resize(15);
		printVector(v);
		cout << "after resize, size of v is " << v.size() << ", capacity of v is " << v.capacity() << endl;
		v.resize(9);
		printVector(v);
		v.resize(20, 3);
		printVector(v);
	}

	// �����ɾ��
	void test04() {
		vector<int> v;
		for (int i = 0; i < 10; ++i) {
			v.push_back(i + 1);	// β������
		}
		v.pop_back();	// ɾ��β��
		printVector(v);
		v.insert(v.begin() + 2, 10);	// ָ��λ�ò�������
		printVector(v);
		v.insert(v.begin(), 2, 5);
		printVector(v);

		v.erase(v.end() - 1);
		printVector(v);
		v.erase(v.end() - 3, v.end() - 1);
		printVector(v);
		v.clear();
		printVector(v);
	}

	// ��ȡ����
	void test05() {
		vector<int> v;
		for (int i = 0; i < 10; ++i) {
			v.push_back(i + 1);	// β������
		}
		cout << "use at, " << v.at(0) << endl;
		cout << "use [], " << v[0] << endl;
		cout << "front, " << v.front() << endl;
		cout << "back, " << v.back() << endl;
	}

	// ����
	void test06() {
		vector<int> v1;
		for (int i = 0; i < 10; ++i) {
			v1.push_back(i + 1);	// β������
		}
		vector<int> v2;
		v2.assign(3, 4);
		v1.swap(v2);
		printVector(v1);
		printVector(v2);

		// �����ڴ棬��Ҫʹ�� vector ������ø� size ���
		v1.resize(100000);
		v1.resize(3);
		cout << "capacity: " << v1.capacity() << endl;
		vector<int>(v1).swap(v1);
		cout << "after swap, capacity: " << v1.capacity() << endl;
	}

	// Ԥ���ռ�
	void test07() {
		vector<int> v;
		int num = 0;
		int* ptr = NULL;
		for (int i = 0; i < 100000; ++i) {
			v.push_back(i);
			if (&v[0] != ptr) {
				ptr = &v[0];
				++num;
			}
		}
		cout << "���ݴ�����" << num << endl;
		v.clear();
		num = 0;
		v.reserve(100000);	// ����������Ż����ٸ�Ԫ�أ���������������
		for (int i = 0; i < 100000; ++i) {
			v.push_back(i);
			if (&v[0] != ptr) {
				ptr = &v[0];
				++num;
			}
		}
		cout << "after using reserve, ���ݴ�����" << num << endl;
	}
}

//int main() {
//	vect::test01();
//	//vect::test02();
//	//vect::test03();
//	//vect::test04();
//	//vect::test05();
//	//vect::test06();
//	//vect::test07();
//	system("pause");
//	return 0;
//}