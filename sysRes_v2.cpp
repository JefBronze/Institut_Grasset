#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

//----------------------------------Accueil: Appel des fonctions-----------------
void menuclient();
void filtre_choix_user_1();
void routage1();
void choix_chambres();
void reserve();
void filtre_choix_user_2();
void filtre_choix_user_3();
void routage2();
void reserve_chambre1();
void reserve_chambre2();
void reserve_chambre3();
void reserve_chambre4();
void reserve_chambre5();
void reserve_chambre6();
void checkin();
void print_chambres();
//----------------------------------Finale: Appel des fonctions-------------------

//----------------------------------Accueil: Variables globales-------------------
string choix_user_1;
string choix_chambre;
int num_res = 1;
//----------------------------------Finale: Variables globales--------------------

//----------------------------------Accueil: Vecteurs-----------------------------
vector<int> chambres{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
vector<string> chambre1;
vector<string> chambre2;
vector<string> chambre3;
vector<string> chambre4;
vector<string> chambre5;
vector<string> chambre6;
//----------------------------------Finale: Vecteurs------------------------------

int main()
{
    menuclient();
    return 0;
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
    cout << "Presse a pour acceder au menu administratif\n";
    cout << "-----------------------------------------------\n";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << endl
         << "Entrez votre option et appuyez sur ENTER sil vous plait: ";
    cin >> choix_user_1;
    filtre_choix_user_1();
}

void filtre_choix_user_1()
{
    if (choix_user_1.size() == 1)
    {
        routage1();
    }
    else
    {
        cout << endl
             << "** ERREUR **!!\n\n Vous navez insere aucune des options presentees. Reessayez en 1 seconde." << endl;
        this_thread::sleep_for(chrono::milliseconds(1500));
        menuclient();
    }
}

void routage1()
{
    system("cls");

    char c1 = '1';
    char c2 = '2';
    char c3 = '3';
    char c4 = '4';
    char c5 = '5';
    char c6 = '6';
    char c9 = '9';
    char cq = 'q';
    char cm = 'm';
    char ca = 'a';

    if (choix_user_1.find(c1) != string::npos)
    {
        cin.ignore();
        choix_chambres();
    }
    if (choix_user_1.find(c2) != string::npos)
    {
        cin.ignore();
        checkin();
    }
    if (choix_user_1.find(c3) != string::npos)
    {
        cin.ignore();
        cout << "3";
        exit(0);
    }
    if (choix_user_1.find(c4) != string::npos)
    {
        cin.ignore();
        cout << "4";
        exit(0);
    }
    if (choix_user_1.find(c5) != string::npos)
    {
        cin.ignore();
        cout << "5";
        exit(0);
    }
    if (choix_user_1.find(c6) != string::npos)
    {
        cin.ignore();
        cout << "6";
        exit(0);
    }
    if (choix_user_1.find(c9) != string::npos)
    {
        cin.ignore();
        cout << "Attendre eternellement!\n";
        cout << "Tchau!!!!\n";
        exit(0);
    }
    if (choix_user_1.find(cq) != string::npos)
    {
        cin.ignore();
        exit(0);
    }
    if (choix_user_1.find(cm) != string::npos)
    {
        cin.ignore();
        menuclient();
    }
    if (choix_user_1.find(ca) != string::npos)
    {
        cin.ignore();
        print_chambres();
    }
    else
    {
        cout << endl
             << "** ERREUR **!!\n\n Vous navez insere aucune des options presentees. Reessayez en 1 seconde." << endl;
        this_thread::sleep_for(chrono::milliseconds(1500));
        menuclient();
    }
}

void choix_chambres()
{
    system("cls");

    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "-----------------------------------------------\n";
    cout << "        BIENVENUE AU MENU DE RESERVE\n";
    cout << "-----------------------------------------------\n";
    cout << "Les chambres disponibles sont: \n";

    for (int i = 0; i < 6; i++)
    {
        if (chambres[i] == 1)
        {
            cout << i + 1;
        }
        cout << " ";
    }

    cout << endl
         << "\nChoisissez lune des options ci-dessus: \n"
         << endl;
    cin >> choix_chambre;

    filtre_choix_user_2();
}

void filtre_choix_user_2()
{
    if (choix_chambre == "1" || choix_chambre == "2" || choix_chambre == "3" || choix_chambre == "4" || choix_chambre == "5" || choix_chambre == "6")
    {
        filtre_choix_user_3();
    }
    else
    {
        cout << endl
             << "** ERREUR **!!\n\n Vous serez redirige vers le menu." << endl;
        this_thread::sleep_for(chrono::milliseconds(1500));
        menuclient();
    }
}

void filtre_choix_user_3()
{
    int choix_chambre_int = stoi(choix_chambre);

    if (chambres[choix_chambre_int - 1] == 1)
    {
        for (int i = 0; i < 10; i++)
        {
            if (choix_chambre_int == i + 1)
            {
                chambres[i] = 0;
                routage2();
            }
        }
    }
    else
    {
        cout << "Chambre occupee! Reessayer!";
        this_thread::sleep_for(chrono::milliseconds(2000));
        choix_chambres();
    }
}

void routage2()
{
    system("cls");

    char c1 = '1';
    char c2 = '2';
    char c3 = '3';
    char c4 = '4';
    char c5 = '5';
    char c6 = '6';
    char cq = 'q';
    char cm = 'm';

    if (choix_chambre.find(c1) != string::npos)
    {
        reserve_chambre1();
    }
    if (choix_chambre.find(c2) != string::npos)
    {
        reserve_chambre2();
    }
    if (choix_chambre.find(c3) != string::npos)
    {
        reserve_chambre3();
    }
    if (choix_chambre.find(c4) != string::npos)
    {
        reserve_chambre4();
    }
    if (choix_chambre.find(c5) != string::npos)
    {
        reserve_chambre5();
    }
    if (choix_chambre.find(c6) != string::npos)
    {
        reserve_chambre6();
    }
    if (choix_chambre.find(cq) != string::npos)
    {
        exit(0);
    }
    if (choix_chambre.find(cm) != string::npos)
    {
        cin.ignore();
        menuclient();
    }
    else
    {
        cout << endl
             << "** ERREUR **!!\n\n Vous navez insere aucune des options presentees. Reessayez en 1 seconde." << endl;
        this_thread::sleep_for(chrono::milliseconds(1500));
        menuclient();
    }
}

void reserve_chambre1()
{
    string nom_prenom;
    string telephone;
    string email;
    stringstream ss;
    string choix_chambre_string;

    ss << choix_chambre;
    ss >> choix_chambre_string;

    stringstream c;
    string num_res_string;

    c << num_res;
    c >> num_res_string;

    num_res += 1;

    cin.ignore();

    system("cls");
    cout << "Ecrivez votre nom et prenom: ";
    getline(cin, nom_prenom);
    chambre1.push_back(nom_prenom);

    cout << "Ecrivez votre telephone: ";
    getline(cin, telephone);
    chambre1.push_back(telephone);

    cout << "Ecrivez votre e-mail: ";
    getline(cin, email);
    chambre1.push_back(email);

    chambre1.push_back(choix_chambre_string);
    chambre1.push_back(num_res_string);

    system("cls");
    cout << "Verifiez vos donnees de reservation: \n"
         << endl;

    //---------------Accueil: Impression de réserve pour le client---------------------
    vector<string> lignes{"Nom :", "Telephone :", "Email :", "Chambre :", "N Reserve :"};
    vector<vector<string>> matriz;
    for (int i = 0; i <= 1; i++)
    {
        vector<string> v1;
        for (int j = 0; j < chambre1.size(); j++)
        {
            if (i == 0)
            {
                v1.push_back(lignes[j]);
            }
            else
            {
                v1.push_back(chambre1[j]);
            }
        }
        matriz.push_back(v1);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)

            cout << matriz[j][i] << " ";
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "\n";
    cout << "Cet ecran avait ete detruit en 3 secondes\n";
    cout << "3\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "2\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "1\n";
    this_thread::sleep_for(chrono::milliseconds(2000));
    //---------------Finale: Impression de réserve pour le client---------------------

    menuclient();
}

void reserve_chambre2()
{
    string nom_prenom;
    string telephone;
    string email;
    stringstream ss;
    string choix_chambre_string;

    ss << choix_chambre;
    ss >> choix_chambre_string;

    stringstream c;
    string num_res_string;

    c << num_res;
    c >> num_res_string;

    num_res += 1;

    cin.ignore();

    system("cls");
    cout << "Ecrivez votre nom et prenom: ";
    getline(cin, nom_prenom);
    chambre2.push_back(nom_prenom);

    cout << "Ecrivez votre telephone: ";
    getline(cin, telephone);
    chambre2.push_back(telephone);

    cout << "Ecrivez votre e-mail: ";
    getline(cin, email);
    chambre2.push_back(email);

    chambre2.push_back(choix_chambre_string);
    chambre2.push_back(num_res_string);

    system("cls");
    cout << "Verifiez vos donnees de reservation: \n"
         << endl;

    //---------------Accueil: Impression de réserve pour le client---------------------
    vector<string> lignes{"Nom :", "Telephone :", "Email :", "Chambre :", "N Reserve :"};
    vector<vector<string>> matriz;
    for (int i = 0; i <= 1; i++)
    {
        vector<string> v1;
        for (int j = 0; j < chambre2.size(); j++)
        {
            if (i == 0)
            {
                v1.push_back(lignes[j]);
            }
            else
            {
                v1.push_back(chambre2[j]);
            }
        }
        matriz.push_back(v1);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)

            cout << matriz[j][i] << " ";
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "\n";
    cout << "Cet ecran avait ete detruit en 3 secondes\n";
    cout << "3\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "2\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "1\n";
    this_thread::sleep_for(chrono::milliseconds(2000));
    //---------------Finale: Impression de réserve pour le client---------------------

    menuclient();
}

void reserve_chambre3()
{
    string nom_prenom;
    string telephone;
    string email;
    stringstream ss;
    string choix_chambre_string;

    ss << choix_chambre;
    ss >> choix_chambre_string;

    stringstream c;
    string num_res_string;

    c << num_res;
    c >> num_res_string;

    num_res += 1;

    cin.ignore();

    system("cls");
    cout << "Ecrivez votre nom et prenom: ";
    getline(cin, nom_prenom);
    chambre3.push_back(nom_prenom);

    cout << "Ecrivez votre telephone: ";
    getline(cin, telephone);
    chambre3.push_back(telephone);

    cout << "Ecrivez votre e-mail: ";
    getline(cin, email);
    chambre3.push_back(email);

    chambre3.push_back(choix_chambre_string);
    chambre3.push_back(num_res_string);

    system("cls");
    cout << "Verifiez vos donnees de reservation: \n"
         << endl;

    //---------------Accueil: Impression de réserve pour le client---------------------
    vector<string> lignes{"Nom :", "Telephone :", "Email :", "Chambre :", "N Reserve :"};
    vector<vector<string>> matriz;
    for (int i = 0; i <= 1; i++)
    {
        vector<string> v1;
        for (int j = 0; j < chambre3.size(); j++)
        {
            if (i == 0)
            {
                v1.push_back(lignes[j]);
            }
            else
            {
                v1.push_back(chambre3[j]);
            }
        }
        matriz.push_back(v1);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)

            cout << matriz[j][i] << " ";
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "\n";
    cout << "Cet ecran avait ete detruit en 3 secondes\n";
    cout << "3\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "2\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "1\n";
    this_thread::sleep_for(chrono::milliseconds(2000));
    //---------------Finale: Impression de réserve pour le client---------------------

    menuclient();
}

void reserve_chambre4()
{
    string nom_prenom;
    string telephone;
    string email;
    stringstream ss;
    string choix_chambre_string;

    ss << choix_chambre;
    ss >> choix_chambre_string;

    stringstream c;
    string num_res_string;

    c << num_res;
    c >> num_res_string;

    num_res += 1;

    cin.ignore();

    system("cls");
    cout << "Ecrivez votre nom et prenom: ";
    getline(cin, nom_prenom);
    chambre4.push_back(nom_prenom);

    cout << "Ecrivez votre telephone: ";
    getline(cin, telephone);
    chambre4.push_back(telephone);

    cout << "Ecrivez votre e-mail: ";
    getline(cin, email);
    chambre4.push_back(email);

    chambre4.push_back(choix_chambre_string);
    chambre4.push_back(num_res_string);

    system("cls");
    cout << "Verifiez vos donnees de reservation: \n"
         << endl;

    //---------------Accueil: Impression de réserve pour le client---------------------
    vector<string> lignes{"Nom :", "Telephone :", "Email :", "Chambre :", "N Reserve :"};
    vector<vector<string>> matriz;
    for (int i = 0; i <= 1; i++)
    {
        vector<string> v1;
        for (int j = 0; j < chambre4.size(); j++)
        {
            if (i == 0)
            {
                v1.push_back(lignes[j]);
            }
            else
            {
                v1.push_back(chambre4[j]);
            }
        }
        matriz.push_back(v1);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)

            cout << matriz[j][i] << " ";
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "\n";
    cout << "Cet ecran avait ete detruit en 3 secondes\n";
    cout << "3\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "2\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "1\n";
    this_thread::sleep_for(chrono::milliseconds(2000));
    //---------------Finale: Impression de réserve pour le client---------------------

    menuclient();
}

void reserve_chambre5()
{
    string nom_prenom;
    string telephone;
    string email;
    stringstream ss;
    string choix_chambre_string;

    ss << choix_chambre;
    ss >> choix_chambre_string;

    stringstream c;
    string num_res_string;

    c << num_res;
    c >> num_res_string;

    num_res += 1;

    cin.ignore();

    system("cls");
    cout << "Ecrivez votre nom et prenom: ";
    getline(cin, nom_prenom);
    chambre5.push_back(nom_prenom);

    cout << "Ecrivez votre telephone: ";
    getline(cin, telephone);
    chambre5.push_back(telephone);

    cout << "Ecrivez votre e-mail: ";
    getline(cin, email);
    chambre5.push_back(email);

    chambre5.push_back(choix_chambre_string);
    chambre5.push_back(num_res_string);

    system("cls");
    cout << "Verifiez vos donnees de reservation: \n"
         << endl;

    //---------------Accueil: Impression de réserve pour le client---------------------
    vector<string> lignes{"Nom :", "Telephone :", "Email :", "Chambre :", "N Reserve :"};
    vector<vector<string>> matriz;
    for (int i = 0; i <= 1; i++)
    {
        vector<string> v1;
        for (int j = 0; j < chambre5.size(); j++)
        {
            if (i == 0)
            {
                v1.push_back(lignes[j]);
            }
            else
            {
                v1.push_back(chambre5[j]);
            }
        }
        matriz.push_back(v1);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)

            cout << matriz[j][i] << " ";
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "\n";
    cout << "Cet ecran avait ete detruit en 3 secondes\n";
    cout << "3\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "2\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "1\n";
    this_thread::sleep_for(chrono::milliseconds(2000));
    //---------------Finale: Impression de réserve pour le client---------------------

    menuclient();
}

void reserve_chambre6()
{
    string nom_prenom;
    string telephone;
    string email;
    stringstream ss;
    string choix_chambre_string;

    ss << choix_chambre;
    ss >> choix_chambre_string;

    stringstream c;
    string num_res_string;

    c << num_res;
    c >> num_res_string;

    num_res += 1;

    cin.ignore();

    system("cls");
    cout << "Ecrivez votre nom et prenom: ";
    getline(cin, nom_prenom);
    chambre6.push_back(nom_prenom);

    cout << "Ecrivez votre telephone: ";
    getline(cin, telephone);
    chambre6.push_back(telephone);

    cout << "Ecrivez votre e-mail: ";
    getline(cin, email);
    chambre6.push_back(email);

    chambre6.push_back(choix_chambre_string);
    chambre6.push_back(num_res_string);

    system("cls");
    cout << "Verifiez vos donnees de reservation: \n"
         << endl;

    //---------------Accueil: Impression de réserve pour le client---------------------
    vector<string> lignes{"Nom :", "Telephone :", "Email :", "Chambre :", "N Reserve :"};
    vector<vector<string>> matriz;
    for (int i = 0; i <= 1; i++)
    {
        vector<string> v1;
        for (int j = 0; j < chambre6.size(); j++)
        {
            if (i == 0)
            {
                v1.push_back(lignes[j]);
            }
            else
            {
                v1.push_back(chambre6[j]);
            }
        }
        matriz.push_back(v1);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)

            cout << matriz[j][i] << " ";
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "\n";
    cout << "Cet ecran avait ete detruit en 3 secondes\n";
    cout << "3\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "2\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "1\n";
    this_thread::sleep_for(chrono::milliseconds(2000));
    //---------------Finale: Impression de réserve pour le client---------------------

    menuclient();
}

void checkin()
{
    system("cls");
    cout << "Quelle est votre reservation ou votre nom?" << endl;

    string checkin_info;
    cin >> checkin_info;

    string search_element = checkin_info;

    vector<string>::iterator it;

    //----------------------Search - Chambre 1
    it = find(chambre1.begin(), chambre1.end(), search_element);
    if (it != chambre1.end())
    {
        chambre1.push_back("Confirme");
        cout << chambre1[0] << " votre enregistrement a te effectue avec succes. Merci!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 1

    //----------------------Search - Chambre 2
    it = find(chambre2.begin(), chambre2.end(), search_element);
    if (it != chambre2.end())
    {
        chambre2.push_back("Confirme");
        cout << chambre2[0] << " votre enregistrement a te effectue avec succes. Merci!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 2

    //----------------------Search - Chambre 3
    it = find(chambre3.begin(), chambre3.end(), search_element);
    if (it != chambre3.end())
    {
        chambre3.push_back("Confirme");
        cout << chambre3[0] << " votre enregistrement a te effectue avec succes. Merci!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 3

    //----------------------Search - Chambre 4
    it = find(chambre4.begin(), chambre4.end(), search_element);
    if (it != chambre4.end())
    {
        chambre4.push_back("Confirme");
        cout << chambre4[0] << " votre enregistrement a te effectue avec succes. Merci!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 4

    //----------------------Search - Chambre 5
    it = find(chambre5.begin(), chambre5.end(), search_element);
    if (it != chambre5.end())
    {
        chambre5.push_back("Confirme");
        cout << chambre5[0] << " votre enregistrement a te effectue avec succes. Merci!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 5

    //----------------------Search - Chambre 6
    it = find(chambre6.begin(), chambre6.end(), search_element);
    if (it != chambre6.end())
    {
        chambre6.push_back("Confirme");
        cout << chambre6[0] << " votre enregistrement a te effectue avec succes. Merci!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 6
    else
    {
        cout << "Il ny a pas de reservation avec ces donnees.";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
}

void print_chambres()
{
    for (int i = 0; i < chambre1.size(); i++)
    {
        cout << chambre1[i];
        cout << " ";
    }
    cout << "\n";
    for (int i = 0; i < chambre2.size(); i++)
    {
        cout << chambre2[i];
        cout << " ";
    }
    cout << "\n";
    for (int i = 0; i < chambre3.size(); i++)
    {
        cout << chambre3[i];
        cout << " ";
    }
    cout << "\n";
    for (int i = 0; i < chambre4.size(); i++)
    {
        cout << chambre4[i];
        cout << " ";
    }
    cout << "\n";
    for (int i = 0; i < chambre5.size(); i++)
    {
        cout << chambre5[i];
        cout << " ";
    }
    cout << "\n";
    for (int i = 0; i < chambre6.size(); i++)
    {
        cout << chambre6[i];
        cout << " ";
    }

    exit(0);
}