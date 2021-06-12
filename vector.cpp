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
	// 构造函数
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

	// 赋值
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

	// 容量和大小
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

	// 插入和删除
	void test04() {
		vector<int> v;
		for (int i = 0; i < 10; ++i) {
			v.push_back(i + 1);	// 尾部插入
		}
		v.pop_back();	// 删除尾部
		printVector(v);
		v.insert(v.begin() + 2, 10);	// 指定位置插入数据
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

	// 读取数据
	void test05() {
		vector<int> v;
		for (int i = 0; i < 10; ++i) {
			v.push_back(i + 1);	// 尾部插入
		}
		cout << "use at, " << v.at(0) << endl;
		cout << "use [], " << v[0] << endl;
		cout << "front, " << v.front() << endl;
		cout << "back, " << v.back() << endl;
	}

	// 互换
	void test06() {
		vector<int> v1;
		for (int i = 0; i < 10; ++i) {
			v1.push_back(i + 1);	// 尾部插入
		}
		vector<int> v2;
		v2.assign(3, 4);
		v1.swap(v2);
		printVector(v1);
		printVector(v2);

		// 收缩内存，主要使得 vector 容量变得跟 size 差不多
		v1.resize(100000);
		v1.resize(3);
		cout << "capacity: " << v1.capacity() << endl;
		vector<int>(v1).swap(v1);
		cout << "after swap, capacity: " << v1.capacity() << endl;
	}

	// 预留空间
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
		cout << "扩容次数：" << num << endl;
		v.clear();
		num = 0;
		v.reserve(100000);	// 告诉容器大概会存多少个元素，避免后续多次扩容
		for (int i = 0; i < 100000; ++i) {
			v.push_back(i);
			if (&v[0] != ptr) {
				ptr = &v[0];
				++num;
			}
		}
		cout << "after using reserve, 扩容次数：" << num << endl;
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