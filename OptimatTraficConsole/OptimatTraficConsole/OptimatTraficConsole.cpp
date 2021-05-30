#include <cmath>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <list>
#include <windows.h>
#include "CheckTarif.h"
#include "Output.h"
using namespace std;

struct tarifs //структура
{
    string name;
    int minutes;
    int sms;
    int gigabytes;
};

tarifs* InputVtabl(int n, string tarifOperatorFile)
{
    tarifs* tarif = new tarifs[n];
    string path = tarifOperatorFile;
    ifstream fin;
    fin.open(path);
    for (int i = 0; i < n; i++) {
        fin >> tarif[i].name;
        fin >> tarif[i].minutes;
        fin >> tarif[i].sms;
        fin >> tarif[i].gigabytes;
    }
    fin.close();
    return tarif;
}

//void Output(tarifs* tarif, int StrokNumber)
//{
//  
//        cout << tarif[StrokNumber].name << "\t" << tarif[StrokNumber].minutes<< "\t" << tarif[StrokNumber].sms << "\t"<< tarif[StrokNumber].gigabytes<< endl;
//    
//}

//int CheckTarif(tarifs* tarif, int N, int RequiredIndicators)
//{
//    int Difference, StrokSum, StrokNumber;
//    for (int i = 0; i < N; i++) {
//            StrokSum = tarif[i].minutes + tarif[i].sms + tarif[i].gigabytes;
//        if (i == 0) {
//            StrokNumber = 0;
//             Difference = abs(RequiredIndicators - StrokSum);
//        }
//        if (Difference > abs(RequiredIndicators - StrokSum)) {
//            Difference = abs(RequiredIndicators - StrokSum);
//            StrokNumber = i;
//        }
//    }
//    return StrokNumber;
//}

int main()
{
    SetConsoleCP(1251); // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    setlocale(LC_ALL, "Rus"); // Подключение русского языка
    int Gig;
    int SMS;
    int Minut;
    int Operator;
    int N;
    int RequiredIndicators;
    int Difference;
    int StrokSum;
    int StrokNumber;
    string tarifOperatorFile;

    cout << "Введите кол-во минут:\n";
    cin >> Gig;
    cout << "Введите кол-во гиг:\n";
    cin >> SMS;
    cout << "Введите кол-во смс:\n";
    cin >> Minut;
    cout << "Выберите оператора: 1.МТС 2.Мегафон 3.Билайн\n";
    cin >> Operator;
    switch (Operator) {
    case 1:
        tarifOperatorFile = "TarifsMTS.txt";
        break;
    case 2:
        tarifOperatorFile = "TarifsMegafon.txt";
        break;
    case 3:
        tarifOperatorFile = "TarifsBilain.txt";
        break;
    }
    N = 2;
    tarifs* tarif = InputVtabl(N, tarifOperatorFile);
    RequiredIndicators = Gig + SMS + Minut;
    StrokNumber = CheckTarif(tarif, N, RequiredIndicators);
    Output(tarif, StrokNumber);
    /*cout << tarif[StrokNumber].name << "\t" << tarif[StrokNumber].minutes<< "\t" << tarif[StrokNumber].sms << "\t"<< tarif[StrokNumber].gigabytes;*/
}