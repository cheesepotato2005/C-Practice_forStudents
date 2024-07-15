#include<iostream>
#include <chrono>
#include <thread>
#include<Windows.h>
                                                 /*
        -----Chapter6.���������part2-----
_________________________________________________
Read the Title.���¼�����ϰ�����������
��������������������������������������������������������������������������������������������������
              1.����/�ݼ������������
���������ࣺ
                                                 */
class Bomb {
public:
    //û�����Ǹ�ը��
    int m_count;//����ը���ĵ���ʱ
    int m_yield;//����ըҩ��TNT����
    int m_escape;//���ǰ�ȫ����ʱ��

    Bomb(int count,int yield) {
        m_count = count;
        m_yield = yield;
        m_escape = count;//��ȫ����ʱ��ĳ�ʼֵ�͵���ʱ��ͬ
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

    Bomb& operator--();//������Ҫʵ�ֵĺ���
};
                                                  /*
�������һ����ʾװ�ã���ը��ÿ��һ�����һ��״̬�����
����ʱ�Ͱ�ȫ����ʱ�䡣
*����ʱ���¹���
    ����ʱÿ�����һ�룻
*��ȫ����ʱ����¹���
    ��ȫ����ʱ��ÿ����ٵ�����;���赱��Ϊ3����ÿ�����
3�롣������10��7��4��1��0��0��0����
    ע�⣺��ȫ����ʱ�䲻��Ϊ������
��Ҫ��
  �ó�Ա�������صݼ�����������������ں�������������
  $��ע���·���ں����Լ������
                                                  */

//int main() {
//    Bomb myBomb(10, 3);
//    myBomb.motivateBomb();
//    system("pause");
//}

                                                  /*
__________________________________________________
                2.��ϵ���������
���������ࣺ
                                                  */
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
                                                  /*
���������A��B����Ƚ����ǵ�ս������С��
     ս���� = (0.6*max_Hp + 2.1*defense)*e^attack
eΪ��Ȼ������ȡ2.72
��Ҫ��
������������==�����������>��С�������<��ʹ�������
�����ܹ�������Ч��
                                                  */
void Battle(player A,player B) {
    if (A == B) {
        std::cout << "ƽ��" << std::endl;
    }
    if (A > B) {
        std::cout << A.name << "ʤ��" << std::endl;
    }
    if (A < B) {
        std::cout << B.name << "ʤ��" << std::endl;
    }
}

                                                   /*
___________________________________________________
             3.�º���������������������أ�

�Ķ�����������򣬻ش�ע���е����⣺
                                                   */
class Event {
public:
    int n;//�¼�����
    double* p;//ĳ�¼������ĸ���(p<1)
    double* w;//���¼��Ľ��
    Event(int N) {
        n = N;
        p = new double[n];
        w = new double[n];
        double p_sum = 0;
        for (int i = 0; i < n; i++) {
            p[i] = w[i] = 0;
        }
        std::cout << "����������" << n << "���¼������ĸ��ʣ�" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cin >> p[i];
            if (p[i] > 1) {
                std::cerr << "�����������󣺸���Ӧ�þ�С��1" << std::endl;
                delete[] p;
                delete[] w;
                exit(EXIT_FAILURE);
            }
            p_sum += p[i];
        }
        if (p_sum - 1.0 > 1e-6) {//��˼���������p_sum-1.0>1e-6��ʲô��˼��
            std::cerr << "�����������󣺸����ܺ�Ӧ��Ϊ1" << std::endl;
            delete[] p;
            delete[] w;
            exit(EXIT_FAILURE);
        }
        std::cout << "����������" << n << "���¼��Ľ��ֵ��" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cin >> w[i];
        }
    }
    ~Event() {
        delete[] p;
        delete[] w;
    }
};
class Expectation {//������
public:
    double operator()(Event& event) {//��˼����Ϊʲô���������ã������ʹ�����ûᵼ��ʲô�����
        double E = 0;
        for (int i = 0; i < event.n; i++) {
            E += event.p[i] * event.w[i];
        }
        return E;
    }
};
//int main() {
//    Event myEvent(5);
//    Expectation getExpect;
//    std::cout << "��ѧ����:" << getExpect(myEvent) << std::endl;
//    //��˼����getExpect��һ��������Ϊʲô��
//    system("pause");
//}