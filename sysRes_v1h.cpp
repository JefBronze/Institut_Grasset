#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <string>

using namespace std;

void reserve();
void printreserve();
void menuclient();
void validation();
void choix();

vector<string> rv(5);
string touche;

int main()
{
    system("cls");
    menuclient();
    reserve();
}

void menuclient()
{
    system("cls");
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "-----------------------------------------------\n";
    cout << "          BIENVENUE A MON HOTEL\n";
    cout << "-----------------------------------------------\n";
    cout << "Presse 1 pour Faire une reservation\n";
    cout << "Presse 2 pour Faire Check-in\n";
    cout << "Presse 3 pour Confirmer une reserve\n";
    cout << "Presse 4 pour Annuler une reservation\n";
    cout << "Presse 5 pour Verifiez vos donnees denregistrement\n";
    cout << "Presse 6 pour Faire Check-out\n";
    cout << "Presse 9 pour Parler a un employe\n";
    cout << "-----------------------------------------------\n";
    cout << "Presse q pour quitter le logiciel a tout moment\n";
    cout << "Presse m pour retour a ce menu a tout moment\n";
    cout << "-----------------------------------------------\n";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << endl
         << "Entrez votre option et appuyez sur la touche ENTER sil vous plait: ";
    cin >> touche;
    validation();
}

void validation()
{
    if (touche.size() == 1)
    {
        choix();
    }
    else
    {
        cout << endl
             << "Erreur! Vous navez insere aucune des options presentees. Reessayez en 1 seconde." << endl;
        this_thread::sleep_for(chrono::milliseconds(1500));
        menuclient();
    }
}

void choix()
{
    char c1 = '1';
    char c2 = '2';
    char c3 = '3';
    char c4 = '4';
    char c5 = '5';
    char c6 = '6';
    char c9 = '9';
    char cq = 'q';
    char cm = 'm';

    if (touche.find(c1) != string::npos)
    {
        cin.ignore();
        reserve();
    }
    if (touche.find(c2) != string::npos)
    {
        cout << "2";
    }
    if (touche.find(c3) != string::npos)
    {
        cout << "3";
    }
    if (touche.find(c4) != string::npos)
    {
        cout << "4";
    }
    if (touche.find(c5) != string::npos)
    {
        cout << "5";
    }
    if (touche.find(c6) != string::npos)
    {
        cout << "6";
    }
    if (touche.find(c9) != string::npos)
    {
        cout << "9";
    }
    if (touche.find(cq) != string::npos)
    {
        exit(0);
    }
    if (touche.find(cm) != string::npos)
    {
        menuclient();
    }
}

void reserve()
{
    string A;
    string B;
    string C;

    cout << "Ecrivez votre nom et prenom: ";
    getline(cin, A);
    rv.push_back(A);

    cout << "Ecrivez votre telephone: ";
    getline(cin, B);
    rv.push_back(B);

    cout << "Ecrivez votre e-mail: ";
    getline(cin, C);
    rv.push_back(C);

    rv.push_back("0");
    rv.push_back("0");

    printreserve();
    exit(0);
}

void printreserve()
{
    for (int i = 0; i < rv.size(); i++)
    {
        cout << rv[i] << endl;
    }
}
