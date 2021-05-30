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

void Output(tarifs* tarif, int StrokNumber)
{
    cout << tarif[StrokNumber].name << "\t" << tarif[StrokNumber].minutes<< "\t" << tarif[StrokNumber].sms << "\t"<< tarif[StrokNumber].gigabytes << endl;
}