#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(deque<int>& d) {
	for (int i = 0; i < d.size(); ++i) {
		cout << d[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < d.size(); ++i) {
		cout << &(d[i]) << " ";
	}
	cout << endl;
}

namespace deq {
	// 构造函数
	void test01() {
		deque<int> d1;
		for (int i = 0; i < 10; ++i) {
			d1.push_back(i);
		}
		cout << "-------------d1-------------" << endl;
		printDeque(d1);

		deque<int> d2(d1);
		cout << "-------------d2-------------" << endl;
		printDeque(d2);

		deque<int> d3(d1.begin() + 1, d1.end() - 1);
		cout << "-------------d3-------------" << endl;
		printDeque(d3);

		deque<int> d4(5, 3);
		cout << "-------------d4-------------" << endl;
		printDeque(d4);
	}

	// 赋值
	void test02() {
		deque<int> d1;
		for (int i = 0; i < 10; ++i) {
			d1.push_back(i * 2);
		}
		cout << "-------------d1-------------" << endl;
		printDeque(d1);
		deque<int> d2;
		d2 = d1;
		cout << "-------------d2-------------" << endl;
		printDeque(d2);
		deque<int> d3;
		d3.assign(d1.begin(), d1.end());
		cout << "-------------d3-------------" << endl;
		printDeque(d3);
		deque<int> d4;
		d4.assign(2, 8);
		cout << "-------------d4-------------" << endl;
		printDeque(d4);
	}

	// 大小
	void test03() {
		deque<int> d;
		cout << "d is empty: " << d.empty() << endl;
		for (int i = 0; i < 10; ++i) {
			d.push_back(i + 1);
		}
		cout << "size of d is " << d.size() << endl;
		cout << "after push_back, d is empty: " << d.empty() << endl;
		d.resize(15);
		printDeque(d);
		cout << "after resize, size of d is " << d.size() << endl;
		d.resize(9);
		printDeque(d);
		d.resize(20, 3);
		printDeque(d);
	}

	// 插入和删除
	void test04() {
		deque<int> d;
		for (int i = 0; i < 10; i += 2) {
			d.push_back(i);	// 尾部插入
			d.push_front(i + 1);	// 头部插入
		}
		d.pop_back();	// 删除尾部
		d.pop_front();	// 删除头部
		printDeque(d);
		d.insert(d.begin() + 2, 10);	// 指定位置插入数据
		printDeque(d);
		d.insert(d.begin(), 2, 5);
		printDeque(d);

		d.erase(d.end() - 1);
		printDeque(d);
		d.erase(d.end() - 3, d.end() - 1);
		printDeque(d);
		d.clear();
		printDeque(d);
	}

	// 读取数据
	void test05() {
		deque<int> d;
		for (int i = 0; i < 10; ++i) {
			d.push_back(i + 1);	// 尾部插入
		}
		cout << "use at, " << d.at(0) << endl;
		cout << "use [], " << d[0] << endl;
		cout << "front, " << d.front() << endl;
		cout << "back, " << d.back() << endl;
	}

	// 排序
	void test06() {
		deque<int> d;
		d.push_back(3);
		d.push_back(1);
		d.push_back(4);
		d.push_back(1);
		d.push_back(5);
		d.push_back(9);
		d.push_back(2);
		d.push_back(6);
		printDeque(d);
		sort(d.begin(), d.end());
		cout << "after sort" << endl;
		printDeque(d);
	}
}

//int main() {
//	deq::test01();
//	//deq::test02();
//	//deq::test03();
//	//deq::test04();
//	//deq::test05();
//	//deq::test06();
//	system("pause");
//	return 0;
//}