#include <stdio.h>

enum dia{
    domingo=0,
    segunda=1,
    terca=2,
    quarta=3,
    quinta=4,
    sexta=5,
    sabado=6
};
typedef enum dia dias;
    
const char* nome(dias d){
    static const char *nomes[]={"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
    if (d<0 || d>6){
        return "Dia inválido.";
    }
    return nomes[d];
    }
    
int main() {
    printf("%s\n", nome(2));
    

    return 0;
}
