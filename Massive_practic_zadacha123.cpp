
#include "TXLib.h"                 //починить алгоритм заполнени€ числами + заполнить массив -->//1.1 2 3
#include <iostream>                                                                             //2.1 2 3 3 2 1
using namespace std;                                                                            //3.1 3 5 7 9...10 8 6 4 2 по половине + юнит тест

void Rand_Masarbitrary_numbersve (int arbitrary_numbers [], int number);   //прототип ф-ии
void Out_Masarbitrary_numbersve (int arbitrary_numbers [], int number);
int Rand_Masarbitrary_numbersve_test (int arbitrary_numbers [], int number);


int main()                                      //главна€ ф-и€
    {
    const int number = 10;                      //обь€вление кон-ты + значение
    int arbitrary_numbers [number] = {};                       //обь€вление массива (размер - не только конс-та) + присвоение каждой €чейке значение 0

    Rand_Masarbitrary_numbersve (arbitrary_numbers, number);                  //вызов ф-ии + массив и размер массива
                                                //цикл фор
    Out_Masarbitrary_numbersve (arbitrary_numbers, number);                   //вывод на экран элемента массива

    $unittest (Rand_Masarbitrary_numbersve_test (arbitrary_numbers, number), -1);


    return 0;                                   //возврат главной ф-ии в 0
    }

//=============================================================================

void Rand_Masarbitrary_numbersve (int arbitrary_numbers [], int number)       //описание ф-ии передаю массив + размер массива
    {

    for (int i = 0; i < number; i++)            //цикл фор
        {
        arbitrary_numbers [i] = i % 3 + 1;                     //присвоение i - €чейке массива рандомного значени€ от 1 до 5
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
        if (!(arbitrary_numbers [i] == i % 3 + 1 && 1 <= arbitrary_numbers [i] && arbitrary_numbers [i] <= 3)) return i;     // если не выполн€етс€ усл
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




