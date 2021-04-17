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
	// ����һ��ָ��һ��ȫ�ֺ���Ϊ��Ԫ�������ڸú����п��Է��� Building ��˽�г�Ա
	friend void goodGay(const Building *building);
	// ����������Ԫ��
	friend class GoodGay;
	// ��������ָ��������ĳ�Ա����Ϊ��Ԫ����
	friend void GG::friendVisit();
public:
	void visitSettingRoom() const;
};

void Building::visitBedRoom() const {
	cout << "��������" << endl;
}

void Building::visitSettingRoom() const {
	cout << "���ʿ���" << endl;
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
//	cout << "ȫ�ֺ���Ϊ��Ԫ������" << endl;
//	goodGay(&building);
//	GoodGay gg;
//	cout << "��Ԫ�ࣺ" << endl;
//	gg.visit();
//	cout << "�������Ա����Ϊ��Ԫ������" << endl;
//	GG g;
//	g.friendVisit();
//
//	system("pause");
//	return 0;
//}