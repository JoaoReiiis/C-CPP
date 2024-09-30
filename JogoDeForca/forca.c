#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[10];
    sprintf(palavra, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    do
    {
        for (int i = 0; i < strlen(palavra); i++)
        {
            int certo = 0;

            for (int j = 0; j < tentativas; j++)
            {
                if (chutes[j] == palavra[i])
                {
                    certo = 1;
                    break;
                }
            }
            if (certo)
            {
                printf("%c", palavra[i]);
            }
            else
            {
                printf(" _ ");
            }
        }

        printf("\n");
        char chute;
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas++;

    } while (!acertou && !enforcou);
    return 0;

}