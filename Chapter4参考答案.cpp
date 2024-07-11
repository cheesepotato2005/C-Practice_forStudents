#include<iostream>
#include<iomanip>
class Matrix {
public:
	double** G;//ʹ��һ������ָ����ָ��һ����ά���飬��Ҳ����ʹ�ñȽϼ򵥵�������double G[3][3]��ʹ�����ַ�������ʱ������Ҫ����ռ�
	Matrix() {
		G = new double* [3];//��G����3��double�ռ�,�����õ�����G[0],G[1],G[2]
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];//��ÿ���з���3��double�ռ�,���ɵõ�3*3����
		}
	}//Ĭ�Ϲ��캯��
	Matrix(const Matrix& other) {
		G = new double* [3];
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];//��Ĭ�Ϲ��캯����ͬ�ķ��䷽����ͬ
			for (int j = 0; j < 3; j++) {
				G[i][j] = other.G[i][j];//����ɹ�����ݱ������������һ��һ��ʼ��
			}
		}//����һ��������̣�
	}//�������캯��
	Matrix(double a11, double a21, double a31, double a12, double a22, double a32, double a13, double a23, double a33) {
		G = new double* [3];
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];
		}//���䷽������ͬ
		G[0][0] = a11; G[1][0] = a21; G[2][0] = a31;
		G[0][1] = a12; G[1][1] = a22; G[2][1] = a32;
		G[0][2] = a13; G[1][2] = a23; G[2][2] = a33;//һ��һ��ʼ��
	}//�вι���
	~Matrix() {
		for (int i = 0; i < 3; i++) {
			delete[] G[i];
		}
		delete[] G;
	}//�����ڴ�ռ�
	void PrintMx() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << std::fixed << std::setprecision(0) << G[i][j] << " ";//���������˸�ʽ��������ƾ�ȷ��
			}
			std::cout << std::endl;//ÿ��ӡһ�о��������
		}
	}
	double determinant() {
		double det = (G[0][0] * G[1][1] * G[2][2]) + (G[0][1] * G[1][2] * G[2][0]) + (G[0][2] * G[1][0] * G[2][1]) - (G[0][2] * G[1][1] * G[2][0]) - (G[0][1] * G[1][0] * G[2][2]) - (G[0][0] * G[1][2] * G[2][1]);
		//���׷���������ʽ��ֱ���öԽ��߷��򼴿�
		return det;
	}
	//������������Ǹ����������Ҫ�ĸ�ֵ��������غ�����������һ������д��
	Matrix& operator=(const Matrix& A) {//ע�⣬����ֵ����Ϊ���ã�
		if (this == &A) {
			return *this;
		}
		for (int i = 0; i < 3; i++) {
			delete[] G[i];
		}
		delete[] G;//��Ϊ���캯���Ĵ��ڣ�ֻҪ����һ�������һ�������˿ռ䣬����������Ҫ������ԭ�пռ�
		G = new double* [3];
		for (int i = 0; i < 3; i++) {
			G[i] = new double[3];
			for (int j = 0; j < 3; j++) {
				G[i][j] = A.G[i][j];
			}
		}//�����·����ڴ����һ��һ��ʼ���������������
		return *this;//�������������
	}
};
//�������⡿
class Equation {
	Matrix A;//�����Ѿ������˿ռ䣬����ڴ�����Matrix A,���������κ�һ��Equation�Ķ���
	double b[3];//����û���ڶ��������ڴ�
	//�ɼ�������ಢû����������ڴ棬����Ҫ���������������ڴ档
public:
	Equation(Matrix A, double b1, double b2, double b3) {
		this->A = A;
		b[0] = b1; b[1] = b2; b[2] = b3;
	}
	void PrintA_b() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << std::fixed << std::setprecision(0) << A.G[i][j] << " ";//���������˸�ʽ�����
			}
			std::cout << b[i] << std::endl;//ÿ��ӡA��һ�оʹ�ӡb[]��һ��Ԫ�أ��γ�������
		}
	}
	void solve() {
		double detD = A.determinant();//ϵ������ʽ
		if (detD == 0) {
			std::cout << "This equation has an infinite number of solutions" << std::endl;
			return;//���ϵ������ʽ�����棬˵���˷����������⣬�˴�������
		}
		Matrix D1 = A;
		for (int i = 0; i < 3; i++) {
			D1.G[i][0] = b[i];
		}
		Matrix D2 = A;
		for (int i = 0; i < 3; i++) {
			D2.G[i][1] = b[i];
		}
		Matrix D3 = A;
		for (int i = 0; i < 3; i++) {
			D3.G[i][2] = b[i];
		}
		double detD1 = D1.determinant();
		double detD2 = D2.determinant();
		double detD3 = D3.determinant();
		std::cout << "x1 = " << std::fixed << std::setprecision(0) << detD1 / detD << std::endl;
		std::cout << "x2 = " << std::fixed << std::setprecision(0) << detD2 / detD << std::endl;
		std::cout << "x3 = " << std::fixed << std::setprecision(0) << detD3 / detD << std::endl;
		//��������㷽����������Դ���������Ĭ����
	}
};
int main() {
	Matrix A(0, 1, -2, 1, 3, -1, 4, 7, 1);//��������
	Equation Ax_b(A, 10, 16, 3);//�вι��췽��
	Ax_b.PrintA_b();//��ӡ�������
	Ax_b.solve();//�ⷽ��and��ӡ���
	system("pause");
	return 0;
}