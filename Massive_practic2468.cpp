
#include "TXLib.h"
#include <iostream>
using namespace std;                                                                            // �������� + �������� �-�, ������� ���������� 2 ������� (�� ���������� ��������) ��� ������ �� ��������� ������������ ��

void Rand_Massive_numbers (int arbitrary_numbers [], int number);   //�������� �-��
void Out_Massive_numbers (int arbitrary_numbers [], int number);
int Rand_Massive_numbers_test (int arbitrary_numbers [], int number);
int Rand_Massive_numbers_test2 (int arbitrary_numbers [], int number);


int main()                                      //������� �-��
    {
    const int number = 10;
    int arbitrary_numbers [number] = {};

    Rand_Massive_numbers (arbitrary_numbers, number);

    Out_Massive_numbers (arbitrary_numbers, number);

    //UnitTest_All ();
    $unittest (Rand_Massive_numbers_test (arbitrary_numbers, number), -1);
    //$unittest (Rand_Massive_numbers_test2 (arbitrary_numbers, number), -1);
    return 0;
    }

//=============================================================================

void Rand_Massive_numbers (int arbitrary_numbers [], int number)//-       //�������� �-�� ������� ������ + ������ �������
    {

    for (int i = 0; i < number; i++)            //���� ���
        {
        arbitrary_numbers [i] = 2 * (rand () % 5) + 2;
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

int Rand_Massive_numbers_test (int arbitrary_numbers [], int number)//-
    {
    for (int i = 0; i < number; i++)
        {
        if (!(arbitrary_numbers [i] % 2 == 0 && 2 <= arbitrary_numbers [i] && arbitrary_numbers [i] <= 10))
            {
            Out_Massive_numbers (arbitrary_numbers, number);
            return i;
            }                                       // ���� �� ����������� ���
        }

/*else*/return -1;
    }

//-----------------------------------------------------------------------------

void Out_Massive_numbers (int arbitrary_numbers [], int number)//-
    {

    for (int j = 0; j < number; j++)
        {
        cout << j << "   " << arbitrary_numbers [j] << endl;
        }
    }

//=============================================================================

int Rand_Massive_numbers_test2 (int arbitrary_numbers [], int number)
        {
        int right_massive [] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1};

        for (int i = 0; i < number; i++)
            {
            if (right_massive [i] != arbitrary_numbers [i])
                {
                cout << i << endl;
                return i;
                }
            }
    /*else*/return -1;
    }




