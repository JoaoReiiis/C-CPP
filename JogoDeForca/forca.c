#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

char palavra[TAMANHO_PALAVRA];
int chutesdados = 1;
char chutes[26];

void adicionapalavra()
{
    char quer;

    printf("Voce deseja adicionar uma palavra? (S/N)");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char novapalavra[20];
        printf("Qual a nova palavra?");
        scanf("%s", novapalavra);

        FILE *f;
        f = fopen("palavras.txt", "r+");
        if (f == 0)
        {
            printf("Desculpe, banco de dados nao disponivel\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

void escolherpalavra()
{
    FILE *f;
    f = fopen("palavras.txt", "r");
    if (f == 0)
    {
        printf("Sem palavras\n");
        exit(1);
    }

    srand(time(0));

    int nmrpalavras;
    fscanf(f, "%d", &nmrpalavras);

    int randon = rand() % nmrpalavras;

    for (int i = 0; i <= randon; i++)
    {
        fscanf(f, "%s", palavra);
    }

    fclose(f);
}

void abertura()
{
    printf("=====================================\n");
    printf("=========={Jodo de Forca}============\n");
    printf("=====================================\n\n");
}

void chuta()
{
    char chute;
    printf("\nQual a letra?");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca()
{
    int erros = chuteserrados();
    
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    printf("Você já deu %d chutes:", chutesdados);

    for (int i = 0; i < strlen(chutes); i++)
    {
        printf(" %c", chutes[i]);
    }

    printf("\n");

    for (int i = 0; i < strlen(palavra); i++)
    {

        int certo = jachutou(palavra[i]);

        if (jachutou(palavra[i]))
        {
            printf(" %c ", palavra[i]);
        }
        else
        {
            printf(" _ ");
        }
    }

    printf("\n");
}

int chuteserrados(){
    int erros = 0;

    for (int i = 0; i < chutesdados; i++)
    {
        int existe = 0;

        for (int j = 0; j < strlen(palavra); j++)
        {
            if (chutes[i] == palavra[j])
            {
                existe = 1;
                break;
            }
        }

        if (!existe)
            erros++;
    }
}

int enforcou()
{
    
    return chuteserrados() >= 5;
}

int acertou()
{
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (!jachutou(palavra[i]))
        {
            return 0;
        }
    }

    return 1;
}

int jachutou(char letra)
{
    int certo = 0;

    for (int j = 0; j < chutesdados; j++)
    {
        if (chutes[j] == letra)
        {
            certo = 1;
            break;
        }
    }
    return certo;
}

int main()
{
    abertura();
    escolherpalavra();
    do
    {
        desenhaforca();
        chuta();
    } while (!acertou() && !enforcou());

    if (acertou())
    {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    }
    else
    {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavra);

        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adicionapalavra();

    return 0;
}
