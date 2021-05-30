
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <list>
#include <cmath>
using namespace std;

struct tarifs //структура
{
    char name;
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

void Output(tarifs* tarif, int n)
{
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << tarif[i].name << "\t" << tarif[i].minutes << "\t"<< tarif[i].sms << "\t" << tarif[i].gigabytes << endl;
    }
}

int main(tarifs* tarif)
{
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

    cout << "Введите кол-во минут";
    cin >> Gig;
    cout << "Введите кол-во гиг";
    cin >> SMS;
    cout << "Введите кол-во смс";
    cin >> Minut;
    cout << "Выберите оператора: 1.МТС 2.Мегафон 3.Билайн";
    cin >> Operator;
                switch (Operator)
                {
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

                InputVtabl(N, tarifOperatorFile);
                N = 3;
                RequiredIndicators = Gig + SMS + Minut;
                for (int i = 0; i < N; i++) {
                    StrokSum = tarif[i].minutes + tarif[i].sms + tarif[i].gigabytes;
                    if (i == 0) Difference = abs(RequiredIndicators - StrokSum);
                    if (Difference > abs(RequiredIndicators - StrokSum)) {
                        Difference = abs(RequiredIndicators - StrokSum);
                        StrokNumber = i;
                    }
                }
                cout << tarif[StrokNumber].minutes << tarif[StrokNumber].sms << tarif[StrokNumber].gigabytes;
                /*list<tarifs> tarif = new list<tarifs>();
                string[] s = File.ReadAllLines(tarifOperatorFile);
                for (int i = 0; i < s.Length; i++)
                {
                    string[] rbtarif = s[i].Split(new char[] { ' ' });
                    tarifs.Add(new tarif(Convert.ToString(rbtarif[0]), Convert.ToInt32(rbtarif[1]), Convert.ToInt32(rbtarif[2]), Convert.ToInt32(rbtarif[3])));
                    StrokSum = Convert.ToInt32(rbtarif[1]) + Convert.ToInt32(rbtarif[2]) + Convert.ToInt32(rbtarif[3]);
                    if (i == 0) Difference = Math.Abs(RequiredIndicators - StrokSum);
                    if (Difference > Math.Abs(RequiredIndicators - StrokSum))
                    {
                        Difference = Math.Abs(RequiredIndicators - StrokSum);
                        StrokNumber = i;
                    }
                }

                for (int i = 0; i < s.Length; i++)
                {
                    textBoxGB.Text = Convert.ToString(tarifs[StrokNumber].name);
                }


                form2.label1.Text = Convert.ToString(tarifs[StrokNumber].name);
                form2.label2.Text = Convert.ToString(tarifs[StrokNumber].minutes);
                form2.label3.Text = Convert.ToString(tarifs[StrokNumber].sms);
                form2.label4.Text = Convert.ToString(tarifs[StrokNumber].gigabytes);

                List<String> slova = new List<string>();
                this.Hide();
                form2.Show();
            }
        }*/
}
