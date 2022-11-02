#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <thread>

using namespace std;

vector<string> vec_reserve;
vector<int> chambres{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int choix_client;
int contador = 1;

void reserve();
void choix_chambres();
void printreserves();
void n_reserve();

int main()
{
    choix_chambres();
    printreserves();
    return 0;
}

void choix_chambres()
{

    system("cls");

    cout << "Les chambres disponibles sont: ";

    for (int i = 0; i < 10; i++)
    {
        if (chambres[i] == 1)
        {
            cout << i + 1;
        }
        cout << " ";
    }

    cout << "Choisissez lune des options ci-dessus: ";
    cin >> choix_client;

    if (chambres[choix_client - 1] == 1)
    {
        for (int i = 0; i < 10; i++)
        {
            if (choix_client == i + 1)
            {
                chambres[i] = 0;
                reserve();
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

void reserve()
{
    string nom_prenom;
    string telephone;
    string email;
    stringstream ss;
    string choix_client_string;

    ss << choix_client;
    ss >> choix_client_string;

    cin.ignore();

    system("cls");
    cout << "Ecrivez votre nom et prenom: ";
    getline(cin, nom_prenom);
    vec_reserve.push_back(nom_prenom);

    cout << "Ecrivez votre telephone: ";
    getline(cin, telephone);
    vec_reserve.push_back(telephone);

    cout << "Ecrivez votre e-mail: ";
    getline(cin, email);
    vec_reserve.push_back(email);

    vec_reserve.push_back(choix_client_string);

    n_reserve();
}

void n_reserve()
{
    stringstream c;
    string contador_s;

    c << contador;
    c >> contador_s;

    vec_reserve.push_back(contador_s);

    contador += 1;
}

/*void printreserves()
{
    for (int i = 0; i < vec_reserve.size(); i++)
    {
        cout << vec_reserve[i] << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(2000));

    main();
}*/

void printreserves()
{

    vector<string> colunas{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    vector<vector<string>> matriz;

    for (int i = 0; i < colunas.size(); i++)
    {
        vector<string> v1;
        v1.push_back(colunas[i]);

        for (int j = 0; j < vec_reserve.size(); j++)
        {
            if (choix_client == i + 1)
            {
                v1.push_back(vec_reserve[j]);
            }
            else
            {
                v1.push_back("-");
            }
        }
        matriz.push_back(v1);
    }

    for (int i = 0; i < matriz[i].size(); i++)
    {

        for (int j = 0; j < matriz.size(); j++)

            cout << matriz[j][i] << " ";
        cout << endl;
    }
}