//Chapter2.��������
#include<iostream>
int factorial(int a) {
	if (a == 0)return 1;// ע��0!=1
	for (int i = a - 1; i > 0; i--) {
		a *= i;
	}//ʵ�ֽ׳�
	return a;
}
int factorial(int a, int b) {
	return factorial(a) / factorial(b);
}
//��Ȼ����������ڲ�Ҳ����д����һ����ʽ��
int factorial_new(int a, int b) {
	if (a == b) {
		return 1;
	}
	else if (a > b&&a*b!=0) {//������뱣֤a��b����Ϊ��
		for (int i = a - 1; i != b; i--) {
			a *= i;
		}
		return a;
	}
	else if (b == 0) {
		return factorial(a);
	}//��Ϊ����a>b>=0�����Բ�����aΪ0�������
}//����ֻ����һ�֣����кܶ����������������гɹ����ɡ�