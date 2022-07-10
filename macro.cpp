#include <iostream>
#include <string>
using namespace std;

// 宏中的 #：如果参数是变量，# 与参数拼接得到的是参数名；如果参数是常量，# 与参数拼接得到的表示该参数的字符串
#define P(A) printf("%s: %d\n", #A, A);		// 该宏的参数适合传变量
#define SQUARE(x) printf("The square of "#x"is %d\n", ((x)*(x)));	// 该宏的参数适合传常量
// 宏中的 ##: 将前后字符相连组成新的【标识符】
#define XNAME(n) x##n
// 宏中的 __VA_ARGS__: 将入参中的 ... 原样输出
#define LOGD(...) printf(__VA_ARGS__);
// 宏中的 ##__VA_ARGS__: 将入参中的 ... 原样输出，尤其当可变参数前有固定参数时，若实际没传可变参数，##__VA_ARGS__ 能兼容这种情况，将前面的逗号去除
#define LOGF(format, ...) printf(format, ##__VA_ARGS__);

namespace macro {
	void test01() {
		int a = 1;
		P(a);
	}

	void test02() {
		SQUARE(8);
	}

	void test03() {
		int XNAME(1), XNAME(2);
		XNAME(1) = 0;
		XNAME(2) = 3;
		printf("XNAME(%d): %d\n", 1, XNAME(1));
		printf("XNAME(%d): %d\n", 2, XNAME(2));
	}

	void test04() {
		printf("__FILE__: %s, __func__: %s, __FUNCTION__: %s, __LINE__: %d, __DATE__: %s, __TIME__: %s, __TIMESTAMP__: %s, __STDCPP_THREADS__: %d\n",
			__FILE__, __func__, __FUNCTION__, __LINE__, __DATE__, __TIME__, __TIMESTAMP__, __STDCPP_THREADS__);
	}

	void test05() {
		LOGD("hello %s\n", "wolrd");
	}

	void test06() {
		LOGF("hello\n");
	}
}

//int main() {
//	//macro::test01();
//	//macro::test02();
//	//macro::test03();
//	//macro::test04();
//	//macro::test05();
//	//macro::test06();
//
//	short a[2][4];
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
//		cout << a[i] << endl;
//		for (int j = 0; j < sizeof(a[0]) / sizeof(short); ++j) {
//			cout << &a[i][j] << endl;
//		}
//	}
//
//	system("pause");
//	return 0;
//}