#include<iostream>
#include <chrono>
#include <thread>
#include<Windows.h>
#include<cmath>
//1
class Bomb {
    int m_count;
    int m_yield;
    int m_escape;
    Bomb(int count, int yield) {
        m_count = count;
        m_yield = yield;
        m_escape = count;
    }
    void motivateBomb() {
        while (m_count != 0) {
            std::cout << "ʣ��ʱ��: " << m_count << " ��\n";
            std::cout << "��ȫ����ʱ�䣺" << m_escape << " ��\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            //������Ĺ��������߳�����һ��,ʵ�ּ�ʱ����
            --*this;//ע��������ǰ�õݼ�
            system("cls");//����̨����
        }
        std::cout << "ը����ը��" << std::endl;
    }//ը����������
    Bomb& operator--();
};

//����ǰ�õݼ�
Bomb& Bomb::operator--() {
    m_count--;
    m_escape -= m_yield;
    if (m_escape < 0) {
        m_escape = 0;
    }
    return *this;
}

//2
class player {
public:
    std::string name;//��ɫ��
    double max_Hp;//�������ֵ
    double attack;//������
    double defense;//������

    bool operator==(player B);
    bool operator>(player B);
    bool operator<(player B);
    //������Ҫ�����ص���������
};
bool player::operator==(player B) {
    double A_power = pow((0.6 * max_Hp + 2.1 * defense) * 2.72, attack);
    double B_power = pow((0.6 * B.max_Hp + 2.1 * B.defense) * 2.72, B.attack);
    if (fabs(A_power - B_power) < 1e-6)
        return 1;
    else
        return 0;
}
bool player::operator>(player B) {
    double A_power = pow((0.6 * max_Hp + 2.1 * defense) * 2.72, attack);
    double B_power = pow((0.6 * B.max_Hp + 2.1 * B.defense) * 2.72, B.attack);
    if (fabs(A_power - B_power) > 1e-6)
        return 1;
    else
        return 0;
}
bool player::operator<(player B) {
    double A_power = pow((0.6 * max_Hp + 2.1 * defense) * 2.72, attack);
    double B_power = pow((0.6 * B.max_Hp + 2.1 * B.defense) * 2.72, B.attack);
    if (fabs(B_power - A_power) > 1e-6)
        return 1;
    else
        return 0;
}