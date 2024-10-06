#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout << "Jogo de adivinhação!" << endl;

    srand(time(NULL));

    const int NUMERO = rand() % 100;
    int chute;
    int tentativas = 0;
    char dificuldade;
    float pontos = 1000;

    cout << "Escolha a dificuldade (F)ácil (M)édio (D)ificíl -> ";
    cin >> dificuldade;

    if(dificuldade == 'F'){
        tentativas = 10;
    }else if(dificuldade == 'M'){
        tentativas = 5;
    }else if(dificuldade == 'D'){
        tentativas = 3;
    }

    while (tentativas > 0){
        cout << "Tentativas: " << tentativas << endl;
        cout << "Insira um chute: ";
        cin >> chute;

        if (chute == NUMERO)
        {
            cout << "Vocẽ acertou o numero!" << endl;
            break;
        }
        else if (chute > NUMERO)
        {
            cout << "Vocẽ errou o numero! Seu chute foi maior que o numero." << endl;
        }
        else if (chute < NUMERO)
        {
            cout << "Vocẽ errou o numero! Seu chute foi menor que o numero." << endl;
        }

        pontos -= abs(chute - NUMERO)/2;
        tentativas --;
    }

    cout << "Fim de jogo!" << endl;
    
    cout.precision(2);
    cout << fixed;
    cout << "Pontos: "<< pontos << endl;


    return 0;
}