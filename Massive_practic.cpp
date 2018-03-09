
#include "TXLib.h"                 //�������� �������� ���������� ������� + ��������� ������ -->//1.1 2 3
#include <iostream>                                                                             //2.1 2 3 3 2 1
using namespace std;                                                                            //3.1 3 5 7 9...10 8 6 4 2 �� �������� + ���� ����

void Rand_Masarbitrary_ numbersve (int arbitrary_ numbers [], int number);   //�������� �-��
void Out_Masarbitrary_ numbersve (int arbitrary_ numbers [], int number);
int Rand_Masarbitrary_ numbersve_test (int arbitrary_ numbers [], int number);


int main()                                      //������� �-��
    {
    const int number = 10;                      //���������� ���-�� + ��������
    int arbitrary_ numbers [number] = {};                       //���������� ������� (������ - �� ������ ����-��) + ���������� ������ ������ �������� 0

    Rand_Masarbitrary_ numbersve (arbitrary_ numbers, number);                  //����� �-�� + ������ � ������ �������
                                                //���� ���
    Out_Masarbitrary_ numbersve (arbitrary_ numbers, number);                   //����� �� ����� �������� �������

    $unittest (Rand_Masarbitrary_ numbersve_test (arbitrary_ numbers, number), number + 13);


    return 0;                                   //������� ������� �-�� � 0
    }

//=============================================================================

void Rand_Masarbitrary_ numbersve (int arbitrary_ numbers [], int number)       //�������� �-�� ������� ������ + ������ �������
    {

    for (int i = 0; i < number; i++)            //���� ���
        {
        arbitrary_ numbers [i] = 2 * (rand () % 5) + 2;         //���������� i - ������ ������� ���������� �������� �� 1 �� 5
        }                                       //a = 2 * (rand () % 5) + 2
    }                                           //         _______
                                                //         0..32767
                                                //         ___________
                                                //            0..4
                                                //    ___________________
                                                //          0..8
                                                //    _____________________
                                                //          2..10
                                                //b = 2*x + 1

//=============================================================================

int Rand_Masarbitrary_ numbersve_test (int arbitrary_ numbers [], int number)
    {
    for (int i = 0; i < number; i++)
        {
        if (!(arbitrary_ numbers [i] % 2 == 0 && 2 <= arbitrary_ numbers [i] && arbitrary_ numbers [i] <= 10)) return i;     // ���� �� ����������� ���
        }

    /*else*/return number + 13;
    }

//-----------------------------------------------------------------------------

void Out_Masarbitrary_ numbersve (int arbitrary_ numbers [], int number)
    {

    for (int j = 0; j < number; j++)
        {
        cout << j << "   " << arbitrary_ numbers [j] << endl;
        }
    }




