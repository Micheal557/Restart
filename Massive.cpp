#include "TXLib.h"
using namespace std;

void OutMassive (double Result [], int nI);

int main ()
    {
    int nI = 9;
    double Result [nI];//обь€вл€ю масств *** с 0 €чейками
    Result [0] = 2;
    for (int i = 1; i < nI; i++)
        {
        Result [i] = Result [i - 1] / 10;

        }
        OutMassive (Result, nI);
    }

//=============================================================================

void OutMassive (double Result [], int nI)
    {
    for (int i = 0; i < nI; i++)
        {
        cout << Result [i] << "     " ;
        }
    }
