#include<iostream>
#include<string>
using namespace std;
class Car {
public:
	string brand;
	int price;
	int fuel_cspt;
	int speed;
	int mobilizeTime;
	int pullUpTime;
	Car(string Brand,int Price,int Fuel_cspt) {
		brand = Brand;
		price = Price;
		fuel_cspt = Fuel_cspt;
		speed = 0;
		mobilizeTime = 0;
		pullUpTime = 0;
	}
	//��Ϊ���ⲻ��Ҫ����������ñ������ṩǳ�����������ɡ�
	void Mobilize(int MobTime, int Speed) {
		mobilizeTime = MobTime;
		speed = Speed;
		//��¼����ʱ�̺�ƽ������
	}
	void pullUp(int PullUpTime) {
		pullUpTime = PullUpTime;
	}//��¼ͣ��ʱ��
	double Fuel_consumption() {
		int time = pullUpTime - mobilizeTime;
		int distance = speed * time;
		return distance * fuel_cspt / 100.0;
	}
};
int main() {
	Car myCar("Bentley", 273, 7);
	myCar.Mobilize(3, 80);
	myCar.pullUp(9);
	cout << "Ʒ�ƣ�" << myCar.brand << endl << "�۸�" << myCar.price << "��Ԫ" << endl;
	cout << "�����г��ͺ�Ϊ��" << myCar.Fuel_consumption() << "L" << endl;
}//��Ϊ33.6L