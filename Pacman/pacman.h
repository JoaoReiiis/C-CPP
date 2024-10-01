void liberamapa();
void lemapa();
void alocamapa();

void move(char direcao);
int acabou();
void imprimemamapa();

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;