#include <iostream>
#include <string>
using namespace std;

namespace str {
	// 构造
	void test01() {
		string s1;
		cout << "s1 is " << s1 << endl;
		const char* c = "hello world";
		string s2(c);
		cout << "s2 is " << s2 << endl;
		string s3(s2);
		cout << "s3 is " << s3 << endl;
		string s4(10, 'a');
		cout << "s4 is" << s4 << endl;
	}

	// 赋值
	void test02() {
		string s1;
		s1 = "hello world";
		cout << "s1 is " << s1 << endl;
		string s2 = s1;
		cout << "s2 is " << s2 << endl;
		string s3;
		char c = 'C';
		s3 = c;
		cout << "s3 is " << s3 << endl;
		string s4;
		s4.assign("hello c++");
		cout << "s4 is " << s4 << endl;
		string s5;
		s5.assign("hello c++", 5);
		cout << "s5 is " << s5 << endl;
		string s6;
		s6.assign(s5);
		cout << "s6 is " << s6 << endl;;
		string s7;
		s7.assign(10, 'c');
		cout << "s7 is " << s7 << endl;
	}

	// 拼接
	void test03() {
		string s1;
		cout << "s1 is " << s1 << endl;
		s1 += "hello";
		cout << "s1 is " << s1 << endl;
		s1 += 'C';
		cout << "s1 is " << s1 << endl;
		string s2;
		s2.append("hello");
		cout << "s2 is " << s2 << endl;
		string s = "world";
		s2.append(s);
		cout << "s2 is " << s2 << endl;
		s2.append("CCCCCccccc", 5);
		cout << "s2 is " << s2 << endl;
		s2.append("sssssSSSSS", 5, 5);
		cout << "s2 is " << s2 << endl;
	}

	// 查找替换
	void test04() {
		string s = "hello world";
		//find(const char* s, int pos = 0);
		int index = s.find("ll", 0);
		cout << "index is " << index << endl;
		//find(const string& s, int pos = 0);
		string he = "he";
		index = s.find(he);
		cout << "index is " << index << endl;
		//find(const char c, int pos = 0);
		index = s.find('o', 0);
		cout << "index is " << index << endl;
		//find(const char* s, int pos, int n)
		//index = s.find("lloo", 0, 3);	// 从 s 中索引为 1 位置开始找 lloo 的前 3 个字符所在索引，结果为 2
		index = s.find("lloo", 0, 4);	// 从 s 中索引为 0 位置开始找 lloo 的前 4 个字符所在索引，结果为  -1
		cout << "index is " << index << endl;
		index = s.rfind("ll");
		cout << "index is " << index << endl;
		index = s.rfind(he);
		cout << "index is " << index << endl;
		index = s.rfind('o');
		cout << "index is " << index << endl;
		index = s.rfind("lloo", 0, 4);
		cout << "index is " << index << endl;

		// replace(int pos, int n, const char* s)
		//s = s.replace(6, 5, "c++");
		// replace(int pos, int n, const string& s)
		string cpp = "c++";
		s.replace(6, 5, cpp);
		cout << "s is " << s << endl;
	}

	// 比较
	void test05() {
		string s1 = "hello";
		string s2 = "HELLO";
		int ret = s1.compare("HELLO");
		//string s2 = "HELLO";
		//int ret = s1.compare(s2);
		if (ret == 0) {
			cout << "s1: " << s1 << ", s2: " << s2 << ", s1 == s2" << endl;
		}
		else if (ret > 0) {
			cout << "s1: " << s1 << ", s2: " << s2 << ", s1 > s2" << endl;
		}
		else {
			cout << "s1: " << s1 << ", s2: " << s2 << ", s1 < s2" << endl;
		}
	}

	// 读取
	void test06() {
		string s = "hello";
		char c = s.at(0);
		cout << "c is " << c << endl;
		c = s[1];
		cout << "c is " << c << endl;
	}

	// 插入和删除
	void test07() {
		string s = "hello world";
		s.insert(0,"hi ");
		cout << "s is " << s << endl;
		string cpp = " c++";
		s.insert(s.size(), cpp);
		cout << "s is " << s << endl;
		s.insert(s.size(), 5, 'C');
		cout << "s is " << s << endl;
		s.erase(0, 3);
		cout << "s is " << s << endl;
		s.clear();
		cout << "s is " << s << endl;
	}

	// 截取
	void test08() {
		string s = "hello world";
		string sub = s.substr(1, 3);
		cout << "s is " << s << endl;
		cout << "sub is " << sub << endl;
	}

	// example
	void test09() {
		string s = "zhangsan@sina.com";
		int index = s.find('@');
		string name = s.substr(0, index);
		cout << "name is " << name << endl;
	}
}

//int main() {
//	//str::test01();
//	//str::test02();
//	//str::test03();
//	//str::test04();
//	//str::test05();
//	//str::test06();
//	//str::test07();
//	//str::test08();
//	str::test09();
//	system("pause");
//	return 0;
//}