#include <iostream>
#include <string>
using namespace std;

class Building;
class GG {
	Building* building;
public:
	GG();
	void friendVisit();
};

class Building {
private:
	string settingRoom;
	string bedRoom;
	void visitBedRoom() const;
	// 方法一：指定一个全局函数为友元函数，在该函数中可以访问 Building 的私有成员
	friend void goodGay(const Building *building);
	// 方法二：友元类
	friend class GoodGay;
	// 方法三：指定其他类的成员函数为友元函数
	friend void GG::friendVisit();
public:
	void visitSettingRoom() const;
};

void Building::visitBedRoom() const {
	cout << "访问卧室" << endl;
}

void Building::visitSettingRoom() const {
	cout << "访问客厅" << endl;
}

void goodGay(const Building *building) {
	building->visitBedRoom();
}

class GoodGay {
	Building* building;
public:
	GoodGay();
	void visit();
};

GoodGay::GoodGay() {
	building = new Building;
}

void GoodGay::visit() {
	building->visitBedRoom();
}

GG::GG() {
	building = new Building;
}

void GG::friendVisit() {
	building->visitBedRoom();
}

//int main() {
//	Building building;
//	building.visitSettingRoom();
//	cout << "全局函数为友元函数：" << endl;
//	goodGay(&building);
//	GoodGay gg;
//	cout << "友元类：" << endl;
//	gg.visit();
//	cout << "其他类成员函数为友元函数：" << endl;
//	GG g;
//	g.friendVisit();
//
//	system("pause");
//	return 0;
//}