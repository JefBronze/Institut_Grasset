#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

using namespace std;

string touche; // Déclaration de variable de chaîne.J'ai choisi le type de chaîne pour limiter l'entrée de l'utilisateur.Le programme n'acceptera pas qu'aucune valeur autre que 1 ou 2 ou 3 ou 4 ou Q ou M ne soit attribuée à cette variable. 

void menu(); // Il apporte la fonction de menu à la portée globale du programme.
void validation(); // Il apporte la fonction de validation à la portée globale du programme.
void choix(); // Il apporte la fonction de choix à la portée globale du programme.
void calculatrice(); // Il apporte la fonction calculatrice à la portée globale du programme.
void PpPG(); // Il apporte la fonction Plus Petit-Grand à la portée globale du programme.
void Aide(); // Il apporte la fonction de Aide à la portée globale du programme.

int main() // Introduction au programme et réception à l'utilisateur.
{
    cout << endl
         << "Bienvenue dans mes Calculatrices!!!";
    this_thread::sleep_for(chrono::milliseconds(500)); // Ligne de code pour faire en sorte que le système attende automatiquement une temp spécifique pour rendre l'interaction plus fluide.
    cout << endl
         << "Attendez 2 secondes, sil vous plait." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000)); // Ligne de code pour faire en sorte que le système attende automatiquement une temp spécifique pour rendre l'interaction plus fluide.
    menu(); // Appelez la fonction de menu qui à son tour démarrera le programme à l'utilisateur.
}

void menu() // Fonction qui apporte le menu et offre les options à l'utilisateur.
{
    system("cls"); // Nettoyez la console jusqu'à présent.Facilitant ainsi l'interaction.
    this_thread::sleep_for(chrono::milliseconds(500));// Ligne de code pour faire en sorte que le système attende automatiquement une temp spécifique pour rendre l'interaction plus fluide.
    cout << "-----------------------------------------------\n";
    cout << "    PROJET 1 - MINIALGO - MENU GENERAL\n";
    cout << "-----------------------------------------------\n";
    cout << "Presse 1 pour Calculatrice\n";
    cout << "Presse 2 pour Plus Petit-Grand\n";
    cout << "Presse 3 pour Tris4\n";
    cout << "Presse 4 pour Aide\n";
    cout << "-----------------------------------------------\n";
    cout << "Presse q pour quitter le logiciel a tout moment\n";
    cout << "Presse m pour retour a ce menu a tout moment\n";
    cout << "-----------------------------------------------\n";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << endl
         << "Entrez votre option et appuyez sur la touche ENTER sil vous plait: ";
    cin >> touche; // Ici, l'entrée de l'utilisateur est attribuée à la touche variale.
    validation(); // La fonction de validation est appelée pour vérifier que l'entrée de l'utilisateur est valide.
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
        menu();
    }
    return;
}

void choix()
{
    char c1 = '1';
    char c2 = '2';
    char c3 = '3';
    char c4 = '4';
    char c5 = 'q';
    char c6 = 'm';

    if (touche.find(c1) != string::npos)
    {
        calculatrice();
    }
    if (touche.find(c2) != string::npos)
    {
        PpPG();
    }
    if (touche.find(c3) != string::npos)
    {
        cout << "Triv4";
    }
    if (touche.find(c4) != string::npos)
    {
        Aide();
    }
    if (touche.find(c5) != string::npos)
    {
        exit(0);
    }
    if (touche.find(c6) != string::npos)
    {
        menu();
    }
}

void calculatrice() // Fonction de la Calculatrice - Option 1 du menu.
{
    system("cls");
    cout << "ARITHMETIQUE DE BASE\n"
         << endl;
    this_thread::sleep_for(chrono::milliseconds(500));

    char operation = 0;
    double premierN = 0;
    double deuxiemeN = 0;
    double solution = 0;

    cout << "Premier nombre: ";
    cin >> premierN;

    /*if (touche.size() == 1)
    {
        choix();
    }
    else
    {
        cout << endl
             << "Erreur! Vous navez insere aucune des options presentees. Reessayez en 1 seconde." << endl;
        this_thread::sleep_for(chrono::milliseconds(1500));
        menu();
    }
    return;*/

    cout << "Entrez le deuxieme nombre: ";
    cin >> deuxiemeN;

    cout << endl
         << "Entrez une operation a effectuer, choisissez-en une dans cette liste: (+) (-) (/) (*) \n";
    cout << "Entrez votre operation: ";
    cin >> operation;
    cin.ignore();

    if (operation != '+' && operation != '-' && operation != '/' && operation != '*')
    {
        cout << endl
             << "Operation invalide! Avorter!" << endl
             << "Appuyez sur Entree pour sortir.";
        cin.get();
    }

    if (operation == '+')
        solution = premierN + deuxiemeN;

    else if (operation == '-')
        solution = premierN - deuxiemeN;

    else if (operation == '*')
        solution = premierN * deuxiemeN;

    else if (operation == '/')
    {
        if (deuxiemeN == 0)
        {
            cout << endl
                 << "Vous ne pouvez pas diviser par zero! Avorter!";
            cout << endl
                 << "Appuyez sur Entree pour sortir.";
            cin.get();
        }
        solution = premierN / deuxiemeN;
    }

    cout << endl
         << "Votre reponse est: " << solution << endl
         << "Appuyez sur Entree pour sortir." << endl;
    cin.get();
    menu();
}

void PpPG() // arrumar essa função
{

    system("cls");
    cout << "PpPG\n"
         << endl;
    this_thread::sleep_for(chrono::milliseconds(500));

    int n1, n2, pp;

    cout << "\n\n\t\t\tDonner 2 nombres!\n\n"
         << endl;
    cin >> n1 >> n2;
    // cout << "\n\n\t\t\tDonner autre nombres!\n\n" << endl;
    // cin >> n2;

    cout << "\n1 nombre: " << n1 << endl;
    cout << "\n2 nombre: " << n2 << endl;

    pp = n1;
    if (n1 < n2)
    {
        cout << "\nLe plus petit des 2 nombres est: " << n1 << endl;
        cout << "\nLe plus grand des 2 nombres est: " << n2 << endl;
    }
    else
    {
        cout << "\nLe plus petit des 2 nombres est: " << n2 << endl;
        cout << "\nLe plus grand des 2 nombres est: " << n1 << endl;
    }
    cout << "\nAttendez un instant, nous vous dirigeons vers le menu principal." << n2 << endl;
    this_thread::sleep_for(chrono::milliseconds(4000));
    menu();
}

void Aide() // Fonction qui prend à l'utilisateur l'écran d'aide.
{
    system("cls");
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "-----------------------------------------------------------\n";
    cout << "-----------------------------------------------------------\n";
    cout << "              PROJET 1 - MINIALGO - AIDE\n";
    cout << "-----------------------------------------------------------\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Nom du Programmeur:.........................Jeferson Bronze\n";
    cout << "Date de creation:................................12/10/2022\n";
    cout << "Lieu de developpement:.....................Institut Grasset\n";
    cout << "-----------------------------------------------------------\n";
    cout << "EXPLICATIONS\n";
    cout << "Ce logiciel offre les fonctions de base dune calculatrice\n";
    cout << "(Addition, Soustraction, Multiplication et Division) et 2\n";
    cout << "actions, lune permettant de rechercher le plus petit et le\n";
    cout << "plus grand nombre et lautre permettant deffectuer un tri.\n";
    cout << "Dans chaque fenetre,\n";
    cout << "            - La touche m permet de revenir au menu general\n";
    cout << "            - La touche q permet de quitter le logiciel\n";
    cout << "-----------------------------------------------------------\n";
    cin >> touche;
    choix();
}