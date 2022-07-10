#include <iostream>
#include <string>
using namespace std;

// ���е� #����������Ǳ�����# �����ƴ�ӵõ����ǲ���������������ǳ�����# �����ƴ�ӵõ��ı�ʾ�ò������ַ���
#define P(A) printf("%s: %d\n", #A, A);		// �ú�Ĳ����ʺϴ�����
#define SQUARE(x) printf("The square of "#x"is %d\n", ((x)*(x)));	// �ú�Ĳ����ʺϴ�����
// ���е� ##: ��ǰ���ַ���������µġ���ʶ����
#define XNAME(n) x##n
// ���е� __VA_ARGS__: ������е� ... ԭ�����
#define LOGD(...) printf(__VA_ARGS__);
// ���е� ##__VA_ARGS__: ������е� ... ԭ����������䵱�ɱ����ǰ�й̶�����ʱ����ʵ��û���ɱ������##__VA_ARGS__ �ܼ��������������ǰ��Ķ���ȥ��
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