#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <string>

using namespace std;

string touche; // Déclaration de variable de chaîne.J'ai choisi le type de chaîne pour limiter l'entrée de l'utilisateur.Le programme n'acceptera pas qu'aucune valeur autre que 1 ou 2 ou 3 ou 4 ou Q ou M ne soit attribuée à cette variable.
string toucheC; // ...
double N1; // ...

void menu();         // Il apporte la fonction de menu à la portée globale du programme.
void validation();   // Il apporte la fonction de validation à la portée globale du programme.
void choix();        // Il apporte la fonction de choix à la portée globale du programme.
void choixC(); //...
void calculatrice(); // Il apporte la fonction calculatrice à la portée globale du programme.
void PpPG();         // Il apporte la fonction Plus Petit-Grand à la portée globale du programme.
void Aide();         // Il apporte la fonction de Aide à la portée globale du programme.

int main() // Introduction au programme et réception à l'utilisateur.
{
    cout << endl
         << "Bienvenue dans mes Calculatrices!!!";
    this_thread::sleep_for(chrono::milliseconds(500)); // Ligne de code pour faire en sorte que le système attende automatiquement une temp spécifique pour rendre l'interaction plus fluide.
    cout << endl
         << "Attendez 2 secondes, sil vous plait." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000)); // Ligne de code pour faire en sorte que le système attende automatiquement une temp spécifique pour rendre l'interaction plus fluide.
    menu();                                             // Appelez la fonction de menu qui à son tour démarrera le programme à l'utilisateur.
}

void menu() // Fonction qui apporte le menu et offre les options à l'utilisateur.
{
    system("cls");                                     // Nettoyez la console jusqu'à présent.Facilitant ainsi l'interaction.
    this_thread::sleep_for(chrono::milliseconds(500)); // Ligne de code pour faire en sorte que le système attende automatiquement une temp spécifique pour rendre l'interaction plus fluide.
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
    validation();  // La fonction de validation est appelée pour vérifier que l'entrée de l'utilisateur est valide.
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

void choixC()
{
    char c1 = 'q';
    char c2 = 'm';
    char c3 = 'n';

    if (toucheC.find(c1) != string::npos)
    {
        exit(0);
    }
    if (toucheC.find(c2) != string::npos)
    {
        menu();
    }
    if (toucheC.find(c3) != string::npos)
    {
        calculatrice();
    }
    else
    {
        N1 = stod(toucheC);
    }
}

void calculatrice() // Fonction de la Calculatrice - Option 1 du menu.
{
    char operation = 0;
    double N2 = 0;
    double solution = 0;

    system("cls");
    this_thread::sleep_for(chrono::milliseconds(500));

    cout << "-----------------------------------------------------------\n";
    cout << "        PROJET 1 - MINIALGO - CALCULATRICE (+ - x /)       \n";
    cout << "-----------------------------------------------------------\n";
    cout << "Nombre 1: \n";
    cout << "Nombre 2: \n";
    cout << "Operation:\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Resultat:\n";
    cout << " \n";
    cout << "-----------------------------------------------------------\n";
    cout << "Presse 'q' pour quitter le programme\n";
    cout << "Presse 'm' pour retour au menu initial\n";
    cout << "Appuyez sur 'n' pour faire un nouveau calcul\n";
    cout << "-----------------------------------------------------------\n";

    cout << "Entrez le premier nombre ou quelque autre des commandes affichees: ";
    cin >> toucheC;
    choixC();

    cout << "Entrez le deuxieme nombre: ";
    cin >> N2;

    cout << endl
         << "Entrez une operation a effectuer, choisissez-en une dans cette liste: (+) (-) (/) (*) \n";
    cin >> operation;

    if (operation != '+' && operation != '-' && operation != '/' && operation != '*')
    {
        cout << endl
             << "Operation invalide! Entrez lun des quatre operateurs arithmetiques!" << endl;
        cin >> operation;
        if (operation != '+' && operation != '-' && operation != '/' && operation != '*')
        {
            cout << "Ok, tu ne veux pas calculer quoi que ce soit ? Au revoir!";
            exit(0);
        }
    }

    if (operation == '+')
        solution = N1 + N2;

    else if (operation == '-')
        solution = N1 - N2;

    else if (operation == '*')
        solution = N1 * N2;

    else if (operation == '/')
    {
        if (N2 == 0)
        {
            cout << endl
                 << "Vous ne pouvez pas diviser par zero!" << endl;
            cout << "Entrez un nombre plus ou moins de zero." << endl;
            cin >> N2;
            if (N2 == 0)
            {
                cout << endl
                     << "Ok, il semble que vous ne vouliez rien partager vraiment. Au revoir!";
                exit(0);
            }
        }
        solution = N1 / N2;
    }

    system("cls");
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "-----------------------------------------------------------\n";
    cout << "        PROJET 1 - MINIALGO - CALCULATRICE (+ - x /)       \n";
    cout << "-----------------------------------------------------------\n";
    cout << "Nombre 1: " << N1 << "\n";
    cout << "Nombre 2: " << N2 << "\n";
    cout << "Operation: " << operation << "\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Resultat: " << solution << "\n";
    cout << " \n";
    cout << "-----------------------------------------------------------\n";
    cout << "Presse 'q' pour quitter le programme\n";
    cout << "Presse 'm' pour retour au menu initial\n";
    cout << "Presse 'n' pour recommencer a calculer!\n";
    cout << "-----------------------------------------------------------\n";
    cin >> toucheC;
    choixC();
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