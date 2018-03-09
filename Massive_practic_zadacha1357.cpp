
#include "TXLib.h"                 //�������� �������� ���������� ������� + ��������� ������ -->//1.1 2 3
#include <iostream>                                                                             //2.1 2 3 3 2 1
using namespace std;                                                                            //3.1 3 5 7 9...10 8 6 4 2 �� �������� + ���� ����

void Rand_Massive_numbers (int arbitrary_numbers [], int number);   //�������� �-��
void Out_Massive_numbers (int arbitrary_numbers [], int number);
int Rand_Massive_numbers_test (int arbitrary_numbers [], int number);


int main()                                      //������� �-��
    {
    const int number = 12;                      //���������� ���-�� + ��������
    int arbitrary_numbers [number] = {};                       //���������� ������� (������ - �� ������ ����-��) + ���������� ������ ������ �������� 0

    Rand_Massive_numbers (arbitrary_numbers, number);                  //����� �-�� + ������ � ������ �������
                                                //���� ���
    Out_Massive_numbers (arbitrary_numbers, number);                   //����� �� ����� �������� �������

    $unittest (Rand_Massive_numbers_test (arbitrary_numbers, number), -1);


    return 0;                                   //������� ������� �-�� � 0
    }

//=============================================================================

void Rand_Massive_numbers (int arbitrary_numbers [], int number)       //�������� �-�� ������� ������ + ������ �������
    {
    int needed_number = 1;
    int changing_number = 2;
    for (int i = 0; i < number; i++)            //���� ���
        {
        arbitrary_numbers [i] = needed_number;
        needed_number = needed_number + changing_number;
        //if (needed_number >= 4) needed_number = 3, changing_number = - changing_number;
        //if (needed_number <= 0) needed_number = 1, changing_number = - changing_number;
        if (i + 1 == number / 2 && number % 2 == 0) needed_number-=1, changing_number = - changing_number;        // ��� ������� � ������ ����������� ���������
        if (i == number / 2 && number % 2 == 1) needed_number-=3, changing_number = - changing_number;        // ��� ������� � �������� ����������� ���������
         //���������� i - ������ ������� ���������� �������� �� 1 �� 5
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

int Rand_Massive_numbers_test (int arbitrary_numbers [], int number)
    {
    int good_massive [] = {1, 3, 5, 7, 9, 11, 12, 10, 8, 6, 4, 2};

    for (int i = 0; i < number; i++)
        {
        if (arbitrary_numbers [i] != good_massive [i]) return i;     // ���� �� ����������� ���
        }
    /*else*/return -1;
        }

//=============================================================================

void Out_Massive_numbers (int arbitrary_numbers [], int number)
    {

    for (int j = 0; j < number; j++)
        {
        cout << j << "   " << arbitrary_numbers [j] << endl;
        }
    }




