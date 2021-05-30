#include <cmath>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <list>
#include <windows.h>
using namespace std;

struct tarifs //структура
{
    string name;
    int minutes;
    int sms;
    int gigabytes;
};

int CheckTarif(tarifs* tarif, int N, int RequiredIndicators)
{
    int Difference, StrokSum, StrokNumber;
    for (int i = 0; i < N; i++) {
        StrokSum = tarif[i].minutes + tarif[i].sms + tarif[i].gigabytes;
        if (i == 0) {
            StrokNumber = 0;
            Difference = abs(RequiredIndicators - StrokSum);
        }
        if (Difference > abs(RequiredIndicators - StrokSum)) {
            Difference = abs(RequiredIndicators - StrokSum);
            StrokNumber = i;
        }
    }
    return StrokNumber;
}