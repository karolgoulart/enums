#include <stdio.h>
#include <string.h>

typedef enum {
    BASE,
    CORRETIVO,
    BATOM
} TipoProduto;

typedef union {
    struct {
        int cobertura;
        char textura[20];
    } base;

    struct {
        char cor[20];
        int duracao_horas;
    } corretivo;

    struct {
        char acabamento[20];
        float brilho;
    } batom;
} DadosProduto;

typedef struct {
    char nome[50];
    char marca[50];
    float preco;
    TipoProduto tipo;
    DadosProduto dados;
} Produto;

void preenche_base(Produto* p) {
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p->nome);
    printf("Digite a marca: ");
    scanf(" %[^\n]", p->marca);
    printf("Digite o preço: ");
    scanf("%f", &p->preco);
    getchar();
    p->tipo = BASE;
    printf("Cobertura (1 a 5): ");
    scanf("%d", &p->dados.base.cobertura);
    getchar();
    printf("Textura: ");
    scanf(" %[^\n]", p->dados.base.textura);
}

void preenche_corretivo(Produto* p) {
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p->nome);
    printf("Digite a marca: ");
    scanf(" %[^\n]", p->marca);
    printf("Digite o preço: ");
    scanf("%f", &p->preco);
    getchar();
    p->tipo = CORRETIVO;
    printf("Cor: ");
    scanf(" %[^\n]", p->dados.corretivo.cor);
    printf("Duração em horas: ");
    scanf("%d", &p->dados.corretivo.duracao_horas);
    getchar();
}

void preenche_batom(Produto* p) {
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p->nome);
    printf("Digite a marca: ");
    scanf(" %[^\n]", p->marca);
    printf("Digite o preço: ");
    scanf("%f", &p->preco);
    getchar();
    p->tipo = BATOM;
    printf("Acabamento: ");
    scanf(" %[^\n]", p->dados.batom.acabamento);
    printf("Brilho (0 a 1): ");
    scanf("%f", &p->dados.batom.brilho);
    getchar();
}

void mostra_base(Produto p) {
    printf("\n=== Base ===\nNome: %s\nMarca: %s\nPreço: R$ %.2f\nCobertura: %d\nTextura: %s\n",
           p.nome, p.marca, p.preco, p.dados.base.cobertura, p.dados.base.textura);
}

void mostra_corretivo(Produto p) {
    printf("\n=== Corretivo ===\nNome: %s\nMarca: %s\nPreço: R$ %.2f\nCor: %s\nDuração: %d horas\n",
           p.nome, p.marca, p.preco, p.dados.corretivo.cor, p.dados.corretivo.duracao_horas);
}

void mostra_batom(Produto p) {
    printf("\n=== Batom ===\nNome: %s\nMarca: %s\nPreço: R$ %.2f\nAcabamento: %s\nBrilho: %.2f\n",
           p.nome, p.marca, p.preco, p.dados.batom.acabamento, p.dados.batom.brilho);
}

int main() {
    Produto p1, p2;

    preenche_base(&p1);
    mostra_base(p1);

    preenche_batom(&p2);
    mostra_batom(p2);

    return 0;
}
