#include<iostream>
#include<string>
using namespace std;
class Account {
	int balance;
	int debt;
	bool status;
public:
	string name;
	string number;
	Account() {
		name = "С��";
		number = "19223110";
		balance = 8000;
		debt = 2000;
		status = 0;//����Ĭ�ϲ������˻���Ҳ����Ĭ�����ã����ݾ������������
	}
	Account(string name,string number,int balance,int debt) {
		this->name = name;
		this->number = number;
		this->balance = balance;
		this->debt = debt;
		status = 0;
	}
	void enable() {
		this->status = 1;
	}
	void disable() {
		this->status = 0;
	}
	int getBalance() {
		return balance;
	}
	int getDebt() {
		return debt;
	}
	Account operator+(const Account& other) {
		Account tempSum;
		tempSum.name = this->name;
		tempSum.number = this->number;
		tempSum.balance = this->balance + other.balance;//this����ָ�򱾶��󣬼����غ�"+"ǰ��Ķ���
		tempSum.debt = this->debt + other.debt;
		return tempSum;
	}
};

Account MergeAccout(Account A, Account B) {
	Account C = A + B;
	A.disable();
	B.disable();
	C.enable();
	return C;
}
//˼����Ϊʲô����ϲ��������ܷ���һ�����ã�
/*
�����ǲ��ܷ���һ���ֲ����������ã���Ϊ�ֲ����������������֮��ͻᱻ���٣��������������ڷǷ�������
������ֵ������У�����ʵ�����Ƿ���һ�����������ǺϷ��ġ�
*/
ostream& operator<<(ostream &cout,Account &C) {
	cout << "������" << C.name << "\n�˺ţ�" << C.number << "\n��" << C.getBalance() << "\nǷ�" << C.getDebt();
	return cout;
}//���������һ����ȫ�ֺ������أ���Ϊ���������ڵ��ú���ʱ��ʹ��cout�����档

void getInfo(Account C) {
	cout << C << endl;
}

int main() {
	Account A; A.enable();
	Account B("С��", "19223108", 964, 952); B.enable();
	Account C = MergeAccout(A, B);
	getInfo(C);
	system("pause");
}


