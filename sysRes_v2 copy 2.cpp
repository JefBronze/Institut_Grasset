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
void menuAdm();
void filtre_choix_user_1();
void filtre_choix_adm_1();
void routage1();
void routage_adm1();
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
void verifiezReserve();
void annulerReserve();
void tableReserves();
void changerReserve();
void checkout();
//----------------------------------Finale: Appel des fonctions-------------------

//----------------------------------Accueil: Variables globales-------------------
string choix_user_1;
string choix_adm_1;
string choix_chambre;
int num_res = 1;
//----------------------------------Finale: Variables globales--------------------

//----------------------------------Accueil: Vecteurs-----------------------------
vector<int> chambres{1, 1, 1, 1, 1, 1};
vector<string> chambre1;
vector<string> chambre2;
vector<string> chambre3;
vector<string> chambre4;
vector<string> chambre5;
vector<string> chambre6;
vector<int> num_res_global;
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
    cout << "Presse 3 pour Verifier une reserve\n";
    cout << "Presse 4 pour Annuler une reservation\n";
    cout << "Presse 5 pour Faire Check-out\n";
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

void menuAdm()
{
    system("cls");

    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "-----------------------------------------------\n";
    cout << "          MENU D ADMINISTRATION\n";
    cout << "-----------------------------------------------\n";
    cout << "Presse 1 pour Voir toutes les reserves\n";
    cout << "Presse 2 pour Changer les reservations\n";
    cout << "Presse 3 pour Chercher une reservation\n";
    cout << "Presse 4 pour Annuler une reserves\n";
    cout << "-----------------------------------------------\n";
    cout << "Presse q pour quitter le logiciel a tout moment\n";
    cout << "Presse m pour retour ao menu du client a tout moment\n";
    cout << "-----------------------------------------------\n";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << endl
         << "Entrez votre option et appuyez sur ENTER sil vous plait: ";
    cin >> choix_adm_1;
    filtre_choix_adm_1();
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

void filtre_choix_adm_1()
{
    if (choix_adm_1.size() == 1)
    {
        routage_adm1();
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
        verifiezReserve();
    }
    if (choix_user_1.find(c4) != string::npos)
    {
        cin.ignore();
        annulerReserve();
    }
    if (choix_user_1.find(c5) != string::npos)
    {
        cin.ignore();
        checkout();
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
        menuAdm();
    }
    else
    {
        cout << endl
             << "** ERREUR **!!\n\n Vous navez insere aucune des options presentees. Reessayez en 1 seconde." << endl;
        this_thread::sleep_for(chrono::milliseconds(1500));
        menuclient();
    }
}

void routage_adm1()
{
    system("cls");

    char c1 = '1';
    char c2 = '2';
    char c3 = '3';
    char c4 = '4';
    char cq = 'q';
    char cm = 'm';

    if (choix_adm_1.find(c1) != string::npos)
    {
        cin.ignore();
        tableReserves();
    }
    if (choix_adm_1.find(c2) != string::npos)
    {
        cin.ignore();
        changerReserve();
    }
    if (choix_adm_1.find(c3) != string::npos)
    {
        cin.ignore();
        verifiezReserve();
    }
    if (choix_adm_1.find(c4) != string::npos)
    {
        cin.ignore();
        annulerReserve();
    }
    if (choix_adm_1.find(cq) != string::npos)
    {
        cin.ignore();
        exit(0);
    }
    if (choix_adm_1.find(cm) != string::npos)
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

    num_res_global.push_back(num_res);

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
    this_thread::sleep_for(chrono::milliseconds(1000));
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
    this_thread::sleep_for(chrono::milliseconds(1000));
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
    this_thread::sleep_for(chrono::milliseconds(1000));
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
    this_thread::sleep_for(chrono::milliseconds(1000));
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
    this_thread::sleep_for(chrono::milliseconds(1000));
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
    this_thread::sleep_for(chrono::milliseconds(1000));
    //---------------Finale: Impression de réserve pour le client---------------------

    menuclient();
}

void checkin()
{
    system("cls");
    // cin.ignore();

    cout << "Quelle est votre numero de reserve ou nom (inserer exactement comme vous avez insere dans la reserve, en respectant le nom de famille, les espaces et les lettres MAUSCULS le cas echeant)?" << endl;

    string checkin_info;

    getline(cin, checkin_info);
    cout << "\n";

    vector<string>::iterator it;

    //----------------------Search - Chambre 1
    it = find(chambre1.begin(), chambre1.end(), checkin_info);
    if (it != chambre1.end())
    {
        chambre1.push_back("Confirme");
        cout << chambre1[0] << " votre enregistrement a te effectue avec succes. Merci!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 1

    //----------------------Search - Chambre 2
    it = find(chambre2.begin(), chambre2.end(), checkin_info);
    if (it != chambre2.end())
    {
        chambre2.push_back("Confirme");
        cout << chambre2[0] << " votre enregistrement a te effectue avec succes. Merci!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 2

    //----------------------Search - Chambre 3
    it = find(chambre3.begin(), chambre3.end(), checkin_info);
    if (it != chambre3.end())
    {
        chambre3.push_back("Confirme");
        cout << chambre3[0] << " votre enregistrement a te effectue avec succes. Merci!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 3

    //----------------------Search - Chambre 4
    it = find(chambre4.begin(), chambre4.end(), checkin_info);
    if (it != chambre4.end())
    {
        chambre4.push_back("Confirme");
        cout << chambre4[0] << " votre enregistrement a te effectue avec succes. Merci!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 4

    //----------------------Search - Chambre 5
    it = find(chambre5.begin(), chambre5.end(), checkin_info);
    if (it != chambre5.end())
    {
        chambre5.push_back("Confirme");
        cout << chambre5[0] << " votre enregistrement a te effectue avec succes. Merci!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 5

    //----------------------Search - Chambre 6
    it = find(chambre6.begin(), chambre6.end(), checkin_info);
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

void verifiezReserve()
{
    system("cls");
    // cin.ignore();

    cout << "Pour confirmer votre reserve insert votre numero de reserve ou nom (inserer exactement comme vous avez insere dans la reserve, en respectant le nom de famille, les espaces et les lettres MAUSCULS le cas echeant)?" << endl;

    string checkin_info;

    getline(cin, checkin_info);
    cout << "\n";

    vector<string>::iterator it;

    //----------------------Search - Chambre 1
    it = find(chambre1.begin(), chambre1.end(), checkin_info);
    if (it != chambre1.end())
    {
        for (int i = 0; i < chambre1.size(); i++)
        {
            cout << chambre1[i];
            cout << " ";
        }
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 1

    //----------------------Search - Chambre 2
    it = find(chambre2.begin(), chambre2.end(), checkin_info);
    if (it != chambre2.end())
    {
        for (int i = 0; i < chambre2.size(); i++)
        {
            cout << chambre2[i];
            cout << " ";
        }
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 2

    //----------------------Search - Chambre 3
    it = find(chambre3.begin(), chambre3.end(), checkin_info);
    if (it != chambre3.end())
    {
        for (int i = 0; i < chambre3.size(); i++)
        {
            cout << chambre3[i];
            cout << " ";
        }
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 3

    //----------------------Search - Chambre 4
    it = find(chambre4.begin(), chambre4.end(), checkin_info);
    if (it != chambre4.end())
    {
        for (int i = 0; i < chambre4.size(); i++)
        {
            cout << chambre4[i];
            cout << " ";
        }
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 4

    //----------------------Search - Chambre 5
    it = find(chambre5.begin(), chambre5.end(), checkin_info);
    if (it != chambre5.end())
    {
        for (int i = 0; i < chambre5.size(); i++)
        {
            cout << chambre5[i];
            cout << " ";
        }
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 5

    //----------------------Search - Chambre 6
    it = find(chambre6.begin(), chambre6.end(), checkin_info);
    if (it != chambre6.end())
    {
        for (int i = 0; i < chambre6.size(); i++)
        {
            cout << chambre6[i];
            cout << " ";
        }
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

void annulerReserve()
{
    system("cls");

    cout << "Pour annuler votre reservation, entrez votre nom exactement comme vous avez insere dans la reserve: ";

    string checkin_info;

    getline(cin, checkin_info);
    cout << "\n";

    vector<string>::iterator it;

    //----------------------Search - Chambre 1
    it = find(chambre1.begin(), chambre1.end(), checkin_info);
    if (it != chambre1.end())
    {
        chambre1.clear();
        cout << "Votre reserve a ete annulee avec succes!";
        this_thread::sleep_for(chrono::milliseconds(2000));
        menuclient();
    }
    //----------------------Search - Chambre 1

    //----------------------Search - Chambre 2
    it = find(chambre2.begin(), chambre2.end(), checkin_info);
    if (it != chambre2.end())
    {
        chambre2.clear();
        cout << "Votre reserve a ete annulee avec succes!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 2

    //----------------------Search - Chambre 3
    it = find(chambre3.begin(), chambre3.end(), checkin_info);
    if (it != chambre3.end())
    {
        chambre3.clear();
        cout << "Votre reserve a ete annulee avec succes!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 3

    //----------------------Search - Chambre 4
    it = find(chambre4.begin(), chambre4.end(), checkin_info);
    if (it != chambre4.end())
    {
        chambre4.clear();
        cout << "Votre reserve a ete annulee avec succes!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 4

    //----------------------Search - Chambre 5
    it = find(chambre5.begin(), chambre5.end(), checkin_info);
    if (it != chambre5.end())
    {
        chambre5.clear();
        cout << "Votre reserve a ete annulee avec succes!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 5

    //----------------------Search - Chambre 6
    it = find(chambre6.begin(), chambre6.end(), checkin_info);
    if (it != chambre6.end())
    {
        chambre6.clear();
        cout << "Votre reserve a ete annulee avec succes!";
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

void tableReserves()
{
    string linhas[6]{"Chambre 1: ", "Chambre 2: ", "Chambre 3: ", "Chambre 4: ", "Chambre 5: ", "Chambre 6: "};
    // string colunas[6]{"   ", "NOM", "TELEPHONE", "EMAIL", "CHAMBRE N", "RESERVE N"};

    string *chambres_array1 = &chambre1[0];
    string *chambres_array2 = &chambre2[0];
    string *chambres_array3 = &chambre3[0];
    string *chambres_array4 = &chambre4[0];
    string *chambres_array5 = &chambre5[0];
    string *chambres_array6 = &chambre6[0];

    /*for (int i = 0; i < 6; i++)
    {
        cout << "        " << colunas[i] << "  ";
    }*/

    // cout << " " << endl;

    for (int i = 0; i < chambres.size(); i++)
    {
        cout << linhas[i] << "  ";
        if (i == 0)
        {
            for (int j = 0; j < chambre1.size(); j++)
            {
                cout << chambres_array1[j] << "  ";
            }
            cout << endl;
        }
        if (i == 1)
        {
            for (int j = 0; j < chambre2.size(); j++)
            {
                cout << chambres_array2[j] << "  ";
            }
            cout << endl;
        }
        if (i == 2)
        {
            for (int j = 0; j < chambre3.size(); j++)
            {
                cout << chambres_array3[j] << "  ";
            }
            cout << endl;
        }
        if (i == 3)
        {
            for (int j = 0; j < chambre4.size(); j++)
            {
                cout << chambres_array4[j] << "  ";
            }
            cout << endl;
        }
        if (i == 4)
        {
            for (int j = 0; j < chambre5.size(); j++)
            {
                cout << chambres_array5[j] << "  ";
            }
            cout << endl;
        }
        if (i == 5)
        {
            for (int j = 0; j < chambre6.size(); j++)
            {
                cout << chambres_array6[j] << "  ";
            }
            cout << endl;
        }
    }
    this_thread::sleep_for(chrono::milliseconds(3000));
    menuclient();
}

void changerReserve()
{
    int chambre_dep;
    int chambre_des;
    vector<string> temp;

    system("cls");

    string linhas[6]{"Chambre 1: ", "Chambre 2: ", "Chambre 3: ", "Chambre 4: ", "Chambre 5: ", "Chambre 6: "};
    // string colunas[6]{"   ", "NOM", "TELEPHONE", "EMAIL", "CHAMBRE N", "RESERVE N"};

    string *chambres_array1 = &chambre1[0];
    string *chambres_array2 = &chambre2[0];
    string *chambres_array3 = &chambre3[0];
    string *chambres_array4 = &chambre4[0];
    string *chambres_array5 = &chambre5[0];
    string *chambres_array6 = &chambre6[0];

    /*for (int i = 0; i < 6; i++)
    {
        cout << "        " << colunas[i] << "  ";
    }*/

    // cout << " " << endl;

    for (int i = 0; i < chambres.size(); i++)
    {
        cout << linhas[i] << "  ";
        if (i == 0)
        {
            for (int j = 0; j < chambre1.size(); j++)
            {
                cout << chambres_array1[j] << "  ";
            }
            cout << endl;
        }
        if (i == 1)
        {
            for (int j = 0; j < chambre2.size(); j++)
            {
                cout << chambres_array2[j] << "  ";
            }
            cout << endl;
        }
        if (i == 2)
        {
            for (int j = 0; j < chambre3.size(); j++)
            {
                cout << chambres_array3[j] << "  ";
            }
            cout << endl;
        }
        if (i == 3)
        {
            for (int j = 0; j < chambre4.size(); j++)
            {
                cout << chambres_array4[j] << "  ";
            }
            cout << endl;
        }
        if (i == 4)
        {
            for (int j = 0; j < chambre5.size(); j++)
            {
                cout << chambres_array5[j] << "  ";
            }
            cout << endl;
        }
        if (i == 5)
        {
            for (int j = 0; j < chambre6.size(); j++)
            {
                cout << chambres_array6[j] << "  ";
            }
            cout << endl;
        }
    }

    cout << "Selectionnez les 2 chambres a alter: " << endl;
    cin >> chambre_dep >> chambre_des;

    //----------------------------------Accueil: Chambre 1-----------------------------
    if (chambre_dep == 1 && chambre_des == 2)
    {
        for (int i = 0; i < chambre2.size(); i++)
        {
            temp.push_back(chambre2[i]);
        }
        chambre2.clear();
        for (int i = 0; i < chambre1.size(); i++)
        {
            chambre2.push_back(chambre1[i]);
        }
        chambre1.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre1.push_back(temp[i]);
        }
        temp.clear();
    }

    if (chambre_dep == 1 && chambre_des == 3)
    {
        for (int i = 0; i < chambre3.size(); i++)
        {
            temp.push_back(chambre3[i]);
        }
        chambre3.clear();
        for (int i = 0; i < chambre1.size(); i++)
        {
            chambre3.push_back(chambre1[i]);
        }
        chambre1.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre1.push_back(temp[i]);
        }
    }

    if (chambre_dep == 1 && chambre_des == 4)
    {
        for (int i = 0; i < chambre4.size(); i++)
        {
            temp.push_back(chambre4[i]);
        }
        chambre4.clear();
        for (int i = 0; i < chambre1.size(); i++)
        {
            chambre4.push_back(chambre1[i]);
        }
        chambre1.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre1.push_back(temp[i]);
        }
    }

    if (chambre_dep == 1 && chambre_des == 5)
    {
        for (int i = 0; i < chambre5.size(); i++)
        {
            temp.push_back(chambre5[i]);
        }
        chambre5.clear();
        for (int i = 0; i < chambre1.size(); i++)
        {
            chambre5.push_back(chambre1[i]);
        }
        chambre1.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre1.push_back(temp[i]);
        }
    }

    if (chambre_dep == 1 && chambre_des == 6)
    {
        for (int i = 0; i < chambre6.size(); i++)
        {
            temp.push_back(chambre6[i]);
        }
        chambre6.clear();
        for (int i = 0; i < chambre1.size(); i++)
        {
            chambre6.push_back(chambre1[i]);
        }
        chambre1.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre1.push_back(temp[i]);
        }
    }
    //----------------------------------Finale: Chambre 1-----------------------------

    //----------------------------------Accueil: Chambre 2-----------------------------
    if (chambre_dep == 2 && chambre_des == 3)
    {
        for (int i = 0; i < chambre3.size(); i++)
        {
            temp.push_back(chambre3[i]);
        }
        chambre3.clear();
        for (int i = 0; i < chambre2.size(); i++)
        {
            chambre3.push_back(chambre2[i]);
        }
        chambre2.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre2.push_back(temp[i]);
        }
    }

    if (chambre_dep == 2 && chambre_des == 4)
    {
        for (int i = 0; i < chambre4.size(); i++)
        {
            temp.push_back(chambre4[i]);
        }
        chambre4.clear();
        for (int i = 0; i < chambre2.size(); i++)
        {
            chambre4.push_back(chambre2[i]);
        }
        chambre2.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre2.push_back(temp[i]);
        }
    }

    if (chambre_dep == 2 && chambre_des == 5)
    {
        for (int i = 0; i < chambre5.size(); i++)
        {
            temp.push_back(chambre5[i]);
        }
        chambre5.clear();
        for (int i = 0; i < chambre2.size(); i++)
        {
            chambre5.push_back(chambre2[i]);
        }
        chambre2.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre2.push_back(temp[i]);
        }
    }

    if (chambre_dep == 2 && chambre_des == 6)
    {
        for (int i = 0; i < chambre6.size(); i++)
        {
            temp.push_back(chambre6[i]);
        }
        chambre6.clear();
        for (int i = 0; i < chambre2.size(); i++)
        {
            chambre6.push_back(chambre2[i]);
        }
        chambre2.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre2.push_back(temp[i]);
        }
    }
    //----------------------------------Finale: Chambre 2-----------------------------

    //----------------------------------Accueil: Chambre 3-----------------------------
    if (chambre_dep == 3 && chambre_des == 4)
    {
        for (int i = 0; i < chambre4.size(); i++)
        {
            temp.push_back(chambre4[i]);
        }
        chambre4.clear();
        for (int i = 0; i < chambre3.size(); i++)
        {
            chambre4.push_back(chambre3[i]);
        }
        chambre3.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre3.push_back(temp[i]);
        }
    }

    if (chambre_dep == 3 && chambre_des == 5)
    {
        for (int i = 0; i < chambre5.size(); i++)
        {
            temp.push_back(chambre5[i]);
        }
        chambre5.clear();
        for (int i = 0; i < chambre3.size(); i++)
        {
            chambre5.push_back(chambre3[i]);
        }
        chambre3.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre3.push_back(temp[i]);
        }
    }

    if (chambre_dep == 3 && chambre_des == 6)
    {
        for (int i = 0; i < chambre6.size(); i++)
        {
            temp.push_back(chambre6[i]);
        }
        chambre6.clear();
        for (int i = 0; i < chambre3.size(); i++)
        {
            chambre6.push_back(chambre3[i]);
        }
        chambre3.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre3.push_back(temp[i]);
        }
    }
    //----------------------------------Finale: Chambre 3-----------------------------

    //----------------------------------Accueil: Chambre 4-----------------------------
    if (chambre_dep == 4 && chambre_des == 5)
    {
        for (int i = 0; i < chambre5.size(); i++)
        {
            temp.push_back(chambre5[i]);
        }
        chambre5.clear();
        for (int i = 0; i < chambre4.size(); i++)
        {
            chambre5.push_back(chambre4[i]);
        }
        chambre4.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre4.push_back(temp[i]);
        }
    }

    if (chambre_dep == 4 && chambre_des == 6)
    {
        for (int i = 0; i < chambre6.size(); i++)
        {
            temp.push_back(chambre6[i]);
        }
        chambre6.clear();
        for (int i = 0; i < chambre4.size(); i++)
        {
            chambre6.push_back(chambre4[i]);
        }
        chambre4.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre4.push_back(temp[i]);
        }
    }
    //----------------------------------Finale: Chambre 4-----------------------------

    //----------------------------------Accueil: Chambre 5-----------------------------
    if (chambre_dep == 5 && chambre_des == 6)
    {
        for (int i = 0; i < chambre6.size(); i++)
        {
            temp.push_back(chambre6[i]);
        }
        chambre6.clear();
        for (int i = 0; i < chambre5.size(); i++)
        {
            chambre6.push_back(chambre5[i]);
        }
        chambre5.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            chambre5.push_back(temp[i]);
        }
    }
    //----------------------------------Finale: Chambre 5-----------------------------

    tableReserves();
    this_thread::sleep_for(chrono::milliseconds(3000));
    menuclient();
}

void checkout()
{
    system("cls");

    cout << "Pour effectuer le check-out, entrez votre nom exactement comme vous avez insere dans la reserve: ";

    string checkin_info;

    getline(cin, checkin_info);
    cout << "\n";

    vector<string>::iterator it;

    //----------------------Search - Chambre 1
    it = find(chambre1.begin(), chambre1.end(), checkin_info);
    if (it != chambre1.end())
    {
        chambre1.clear();
        cout << "Votre check-out etait fait avec succes!";
        this_thread::sleep_for(chrono::milliseconds(2000));
        menuclient();
    }
    //----------------------Search - Chambre 1

    //----------------------Search - Chambre 2
    it = find(chambre2.begin(), chambre2.end(), checkin_info);
    if (it != chambre2.end())
    {
        chambre2.clear();
        cout << "Votre check-out etait fait avec succes!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 2

    //----------------------Search - Chambre 3
    it = find(chambre3.begin(), chambre3.end(), checkin_info);
    if (it != chambre3.end())
    {
        chambre3.clear();
        cout << "Votre check-out etait fait avec succes!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 3

    //----------------------Search - Chambre 4
    it = find(chambre4.begin(), chambre4.end(), checkin_info);
    if (it != chambre4.end())
    {
        chambre4.clear();
        cout << "Votre check-out etait fait avec succes!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 4

    //----------------------Search - Chambre 5
    it = find(chambre5.begin(), chambre5.end(), checkin_info);
    if (it != chambre5.end())
    {
        chambre5.clear();
        cout << "Votre check-out etait fait avec succes!";
        this_thread::sleep_for(chrono::milliseconds(3000));
        menuclient();
    }
    //----------------------Search - Chambre 5

    //----------------------Search - Chambre 6
    it = find(chambre6.begin(), chambre6.end(), checkin_info);
    if (it != chambre6.end())
    {
        chambre6.clear();
        cout << "Votre check-out etait fait avec succes!";
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