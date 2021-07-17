#include <iostream>
#include <string.h>
#include "call_c.h"			// function1

using namespace std;

// function2
//extern "C" {
//    int add(int a, int b);
//}

void testCallC() {
	cout << "--------" << __func__ << "--------" << endl;
	cout << add(9, 3) << endl;
	cout << endl;
}

int main() {
	testCallC();
	system("pause");
	return 0;
}