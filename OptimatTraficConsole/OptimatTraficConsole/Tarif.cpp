#include "CheckTarif.h"
#include "Output.h"
#include <cmath>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <list>
#include <windows.h>
using namespace std;

struct tarifs 
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