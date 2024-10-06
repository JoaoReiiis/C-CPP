#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int segundos = time(0);
    srand(segundos);

    int numero = rand() % 100;
    int chute = 0;
    int tentativas = 0;
    int ganhou = 0;
    double pontos = 1000;
    int nivel = 0;

    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        tentativas = 20;
        break;
    case 2:
        tentativas = 10;
        break;
    case 3:
        tentativas = 5;
        break;
    }

    for (int i = 1; i <= tentativas; i++)
   
    {
        printf("tentativa %d\n", i);
        printf("Insira o chute:");

        scanf("%d", &chute);

        if (chute < 0)
        {
            printf("Voce nao pode chutar numeros negativos.\n");
            tentativas--;
            continue;
        }

        if (chute == numero)
        {
            printf("O Numero chutado foi %d. Voce acertou!\n", chute);
            ganhou = 1;
        }
        else
        {
            printf("O Numero chutado foi %d. Voce errou!\n", chute);
            pontos -= abs((int)((chute - numero) / 2.0));

            if (chute < numero)
            {
                printf("Dica: o numero é maior.\n");
            }
            else
            {
                printf("Dica: o numero é menor.\n");
            }
        }
    }
    printf("fim de jogo. tentativas: %d \n Pontos: %.1f\n", tentativas, pontos);

    return 0;

}