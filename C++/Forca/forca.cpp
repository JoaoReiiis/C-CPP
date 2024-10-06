#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool contem_letra(char chute, string PALAVRA)
{
    for (char letra : PALAVRA)
    {
        if (chute == letra)
        {
            return true;
        }
    }
    return false;
}

bool acertou(string PALAVRA, map<char, bool> chutes)
{
    for (char letra : PALAVRA)
    {
        if (!chutes[letra])
        {
            return false;
        }
    }
    return true;
}

bool enforcou(vector<char> chutes)
{
    return chutes.size() >= 5;
}

vector<string> le_arquivo()
{
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open())
    {
        int numero_palavras;
        arquivo >> numero_palavras;

        vector<string> palavras_arquivo;

        for (int i = 0; i < numero_palavras; i++)
        {
            string palavra;
            arquivo >> palavra;
            palavras_arquivo.push_back(palavra);
        }

        arquivo.close();
        return palavras_arquivo;
    }else{
        cout << "Não foi possivel abrir o arquivo de palavras.";
        exit(0);
    }
}

string sorteia_palavra()
{
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    string palavra = palavras[indice_sorteado];
    return palavra;
}

void salva_arquivo(vector<string> nova_lista){
    ofstream arquivo;
    arquivo.open("palavras.txt");
    if(arquivo.is_open()){
        arquivo << nova_lista.size() << endl;

        for(string palavra : nova_lista){
            arquivo << palavra << endl;
        }
        arquivo.close();
    }else{
        cout <<  "Nao foi possivel acessar o banco de palavras." << endl;
        exit(0);
    }
}

void adiciona_palavra(){
    cout << "Digite a nova palavra: " << endl;
    string nova_palavra;
    cin >> nova_palavra;
    for (auto &letra: nova_palavra) letra = toupper(letra);

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);
    salva_arquivo(lista_palavras);
}

int main()
{
    const string PALAVRA = sorteia_palavra();
    map<char, bool> chutes;
    vector<char> erros;

    cout << ">>> JOGO DE FORCA <<<" << endl;

    while (!acertou(PALAVRA, chutes) && !enforcou(erros))
    {
        cout << "Chutes errados: ";
        for (char letra : erros)
        {
            cout << letra << " ";
        }
        cout << endl;

        for (char letra : PALAVRA)
        {
            if (chutes[letra])
            {
                cout << letra;
            }
            else
            {
                cout << "_";
            }
        }
        cout << endl;

        cout << "Seu chute: ";
        char chute;
        cin >> chute;
        chute = toupper(chute);

        chutes[chute] = true;

        if (contem_letra(chute, PALAVRA))
        {
            cout << "O chute esta na palavra." << endl;
        }
        else
        {
            cout << "seu chute nao esta na palavra" << endl;
            erros.push_back(chute);
        }
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra era: " << PALAVRA << endl;

    if (acertou(PALAVRA, chutes))
    {
        cout << "Parabens, voce acertou a palavra!" << endl;

        cout << "Deseja adicionar um nova palavra? (S/n)" << endl;
        char resposta;
        cin >> resposta;

        if(resposta == 'S' || resposta == 's'){
            adiciona_palavra();
        }
    }
    else
    {
        cout << "Voce perdeu!" << endl;
    }
}
