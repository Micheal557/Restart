
#include "TXLib.h"                 //�������� �������� ���������� ������� + ��������� ������ -->//1.1 2 3
#include <iostream>                                                                             //2.1 2 3 3 2 1
using namespace std;                                                                            //3.1 3 5 7 9...10 8 6 4 2 �� �������� + ���� ����

void Rand_Masarbitrary_numbersve (int arbitrary_numbers [], int number);   //�������� �-��
void Out_Masarbitrary_numbersve (int arbitrary_numbers [], int number);
int Rand_Masarbitrary_numbersve_test (int arbitrary_numbers [], int number);


int main()                                      //������� �-��
    {
    const int number = 10;                      //���������� ���-�� + ��������
    int arbitrary_numbers [number] = {};                       //���������� ������� (������ - �� ������ ����-��) + ���������� ������ ������ �������� 0

    Rand_Masarbitrary_numbersve (arbitrary_numbers, number);                  //����� �-�� + ������ � ������ �������
                                                //���� ���
    Out_Masarbitrary_numbersve (arbitrary_numbers, number);                   //����� �� ����� �������� �������

    $unittest (Rand_Masarbitrary_numbersve_test (arbitrary_numbers, number), -1);


    return 0;                                   //������� ������� �-�� � 0
    }

//=============================================================================

void Rand_Masarbitrary_numbersve (int arbitrary_numbers [], int number)       //�������� �-�� ������� ������ + ������ �������
    {

    for (int i = 0; i < number; i++)            //���� ���
        {
        arbitrary_numbers [i] = i % 3 + 1;                     //���������� i - ������ ������� ���������� �������� �� 1 �� 5
        }                                       //a = 2 * (rand () % 5) + 2
    }                                           //         _______
                                                //         0..32767
  //                                            //         ___________
                                                //            0..4
                                                //    ___________________
                                                //          0..8
                                                //    _____________________
                                                //          2..10
                                                //b = 2*x + 1

//=============================================================================

int Rand_Masarbitrary_numbersve_test (int arbitrary_numbers [], int number)
    {
    for (int i = 0; i < number; i++)
        {
        if (!(arbitrary_numbers [i] == i % 3 + 1 && 1 <= arbitrary_numbers [i] && arbitrary_numbers [i] <= 3)) return i;     // ���� �� ����������� ���
        }
    /*else*/return -1;
        }

//=============================================================================

void Out_Masarbitrary_numbersve (int arbitrary_numbers [], int number)
    {

    for (int j = 0; j < number; j++)
        {
        cout << j << "   " << arbitrary_numbers [j] << endl;
        }
    }




