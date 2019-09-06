#include <stdio.h>
#include <string.h>

void str_trim(char* dest, char* source){
    int is = 0, id = 0;     // Index (i) da string source (s) e destino (d).

    while (source[is] != '\0'){     // Verifica fim da string.
        if (source[is] != ' '){     // Se nao for espaco, copia.
            dest[id] = source[is];
            id++;
        } else if (source[is+1] != ' ' && id !=0){  // Se proximo cxaractere 
            if(source[is+1] == '\0') {              // for espaco e nao for  
                dest[id] = '\0';                    // inicio da string, copia.  
            } else {                                // Se for final da string,
                dest[id] = ' ';                     // finaliza a string destino.
                id++;
            }
        }
        is++;
    }
}

int main(){
    char* str = "    Frase   de teste   12   ";
    char new_str[100];

    printf("%s\n", str);
    printf("Size: %d\n", strlen(str));

    str_trim(new_str, str);
   
    printf("%s\n", new_str);
    printf("Size: %d\n", strlen(new_str));
    
    return 0;
}
