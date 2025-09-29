#include <stdio.h>

typedef enum {
    REAIS = 1,
    DOLAR,
    EURO
} Moeda;

typedef union {
    float real;
    float dolar;
    float euro;
} valor;

typedef struct {
    valor val;
    Moeda tipo; 
} preco;

void exibe(preco p) {
    if (p.tipo == REAIS) 
        printf("Preço: R$ %.2f\n", p.val.real);
    else if (p.tipo == DOLAR) 
        printf("Preço: $ %.2f\n", p.val.dolar);
    else if (p.tipo == EURO)
        printf("Preço: € %.2f\n", p.val.euro);
    else
        printf("Inválido!\n");
}

preco altera(preco p, Moeda novo_tipo) {
    preco novo;
    if (p.tipo == REAIS) { 
        if (novo_tipo == DOLAR)
            novo.val.dolar = p.val.real / 5.3;
        else if (novo_tipo == EURO)
            novo.val.euro = p.val.real / 6.2;
        else
            novo.val.real = p.val.real;
    } 
    else if (p.tipo == DOLAR) { 
        if (novo_tipo == REAIS)
            novo.val.real = p.val.dolar * 5.3;
        else if (novo_tipo == EURO)
            novo.val.euro = (p.val.dolar * 5.3) / 6.2;
        else
            novo.val.dolar = p.val.dolar;    
    } 
    else if (p.tipo == EURO) { 
        if (novo_tipo == REAIS)
            novo.val.real = p.val.euro * 6.2;
        else if (novo_tipo == DOLAR)
            novo.val.dolar = (p.val.euro * 6.2) / 5.3;
        else
            novo.val.euro = p.val.euro;
    }
    novo.tipo = novo_tipo;
    return novo;
}

int main() {
    preco p;
    int origem, destino;

    printf("Escolha a moeda:\n1 - Reais\n2 - Dolares\n3 - Euros\nOpção: ");
    scanf("%d", &origem);
    p.tipo = (Moeda)origem;

    printf("Digite o valor: ");
    if (p.tipo == REAIS) scanf("%f", &p.val.real);
    else if (p.tipo == DOLAR) scanf("%f", &p.val.dolar);
    else if (p.tipo == EURO) scanf("%f", &p.val.euro);

    exibe(p);

    printf("\nEscolha a moeda para conversão:\n1 - Reais\n2 - Dolares\n3 - Euros\nOpção: ");
    scanf("%d", &destino);
    
    preco p2 = altera(p, (Moeda)destino);
    exibe(p2);

    return 0;
