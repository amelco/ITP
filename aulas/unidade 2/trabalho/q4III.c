/**
 REFERÊNCIAS
    infix to postifx:
    1. https://csis.pace.edu/~wolf/CS122/infix-postfix.htm
    2. https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
    3. http://community.bartdesmet.net/blogs/bart/archive/2006/10/11/4513.aspx

    evaluate postfix:
    4. https://www.tutorialspoint.com/Evaluate-Postfix-Expression
    5. https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/

 > Recebe até 30 strings de 100 caracteres contendo equações que podem conter os operadores: 
     +, -, /, *
     e retorna o resultado da equação, levando em conta as prioridades do operadores.
 > Os operandos só podem ter um algarismo.
 > Considera parentêses para alterar prioridade de operações.
 
 Disponível em: https://github.com/amelco/ITP/blob/master/aulas/unidade%202/trabalho/q4III.c
 Desenvolvido por: Andre Herman (amelco.herman@gmail.com)
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // para usar exit()
#include <ctype.h>      // para usar isdigit()

#define TAM 100         // define uma constante TAM (tamanho) de valor igual a 100

typedef enum boll_t {
    false=0, 
    true
} bool;                 // define tipo booleano [false=0, true=1]

char pilha[TAM];        // variável global pilha [0-99]. Global porque é utilizada em várias funções
int topo = -1;          // variável "topo" da pilha. [-1: sem elementos, 0: 1 elemento, ... 99: 100 elementos]

// define a operação 'push' da pilha [colocar elemento na pilha]
void push (char item) {
    if (topo >= TAM)
        printf("\nPilha Sobrecarregada (Stack Overflow).\n");
    else {
        topo++;
        pilha[topo] = item;
    }
}

// define a operação 'pop' da pilha [retirar último elemento da pilha]
//   => retorna elemento que foi retirado
char pop () {
    char item;

    if (topo < 0) {
        printf("\nPilha não contém elemento a ser retirado (Stack Underflow)\n");
        exit(1);
    } else {
        item = pilha[topo];
        topo--;
        return item;
    }
}

// define função para checar se o simbolo é um operador
//   => retorna true ou false
bool eh_operador (char simbolo) {
    if(simbolo == '*' || simbolo == '/' || simbolo == '+' || simbolo =='-') return true;
	else return false;
}

// define função para retornar a prioridade de um operador
//  => retorna um inteiro. Quanto maior o inteiro, maior a prioridade
int prioridade (char simbolo) {
    if(simbolo == '*' || simbolo == '/') return 2;
	else if(simbolo == '+' || simbolo == '-') return 1;
	else return 0;
}

// define função que tranforma infix para postfix
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');                              // coloca '(' na pilha 
	strcat(infix_exp,")");                  // adiciona ')' na expressao infix

	i = 0;
	j = 0;
	item = infix_exp[i];                    // inicializa antes do loop

	while(item != '\0') {                   // executa loop até fim da string 
		if(item == '(') {
			push(item);
		}
		else if(isdigit(item)) {
			postfix_exp[j] = item;              // adiciona o numero à expressão postfix
			j++;
		}
		else if(eh_operador(item)) {            // item é um operador [+, -, *, /]
			x = pop();                          // retira elemento da pilha e armazena em x
            
            /* 
                retira todos os elementos de maior prioridade que o item e
                os adiciona na expressao postfix
                
                funcionamento:
                    verifica se x é operador [1 ou 0] E se a prioridade de x é maior que a do item
                    ex.
                    x='+'     => prioridade(x) = 1   => é operador? [verdadeiro = 1]
                    item='*'  => prioridade(item) = 2
                    1 >= 2? [falso = 0]
                    1 && 0 [1 AND 0] = 0 [falso]
             */
			while(eh_operador(x) && prioridade(x)>= prioridade(item)) {
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
			push(x);            // coloca de volta o item que foi retirado ao fim do loop
			push(item);         // coloca o item atual na pilha
		}
        // se o item é ')' então retira os elementos da pilha e escreve no postfix até encontrar um '('
        else if(item == ')') {
			x = pop();
			while(x != '(') {
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
        // se o item não é '(' ou ')' e nem um operador, então é um símbolo não permitido
		else {
			printf("\nExpressão infix inválida.\n");
			getchar();
			exit(1);
		}

		i++;
		item = infix_exp[i];        // armazena o próximo símbolo da expressão infix
	}                               // fim do while
    infix_exp[i-1] = '\0';          // retira o ')' inserido na expressao infix

    // Ao fim do while loop, a pilha deve estar vazia
	if(topo > 0) {
		printf("\nExpressão infix inválida.\n");
		getchar();
		exit(1);
	}

	postfix_exp[j] = '\0';          // finaliza a string da expressao postfix
}

// define funcao para calcular a operação entre 2 operandos
//   => retorna um float com o resultado
float calc(char x, float op1, float op2) {
	if(x == '+') return (op1+op2);
	if(x == '-') return (op1-op2);
	if(x == '*') return (op1*op2);
	if(x == '/') return (op1/op2);
}

// define função para resolver a expressão postfix
float resolve(char postfix[]) {
    float pilha[TAM];       // vetor de float que servirá como pilha
    int i;
    char item;              // item atual da expressão postfix
    float op1, op2, val;    // 2 operandos (números) e o valor do resultado

    // inicializa variáveis
    topo = -1;
    i = 0;
    item = postfix[i];
    
    while (item != '\0'){
        if (isdigit(item)) {              // verifica se um algarismo e adiciona à pilha
            topo++;
            pilha[topo] = item;
        }
        else {                            // se for um operador, retira 2 operandos da pilha e realiza operação
            op1 = pilha[topo]-48;         // item-48 para retornar o número ao inves do codigo ASCII
            topo--;
            op2 = pilha[topo]-48;
            topo--;
            val = calc(item, op2, op1);
            topo++;
            pilha[topo] = val+48;         // coloca o resultado na pilha
        }

        i++;
        item = postfix[i]; 
    }
    
    val = pilha[topo]-48;               // retira o resultado (final) da pilha
    topo--;
    return val;                         // retorna o resultado

}

/* inicio PARTE 2*/
// função para encontrar uma substring dentro de outra string (em teste)
int substr(char str[100], char sub[100]) {
    int i, j=0, k;
      for(i=0; str[i]; i++) {
        if(str[i] == sub[j]) {
            for(k=i, j=0; str[k] && sub[j]; j++, k++)
                if(str[k]!=sub[j]) break;
            if(!sub[j]) return i;
        }
      }
}

// função para substituir as variáveis por seus valores (em teste)
void substituir(int nv, char vars[10][50], char eq[100]) {
    char new_eq[100];
    char aux[100];
    int ia = 0;
    
    for (int i=0; i<nv*2; i+=2) {
        printf("%s %s => ", vars[i], eq);
        printf("%d\n", substr(eq, vars[i]));
    }
}

/* fim PARTE 2*/

int main() {
     
    int n = 4;  // número de equações
    // cria vetor de strings que pode armazenar até 30 equações com 100 caracteres
    char equacoes[30][100] = {"1+2*3",
                              "1-2*3/4", 
                              "1+1/2", 
                              "2/3+3*4"};
    // strings para serem usadas na função InfixToPostfix()
    char infix[100], postfix[100];
    
    /* PARTE 1 e 3 */
    for (int i=0; i<n; i++) {
        strcpy(infix, equacoes[i]);
        InfixToPostfix(infix,postfix);
        printf("%20s = %7.2f\n", infix, resolve(postfix));
        // printf("%s = %s = %.2f\n", infix, postfix, resolve(postfix));
    }

    /* PARTE 2 (em teste) */
    int nv = 2;
    char variaveis [10][50] = {"va","1",
                               "vb","2"};
    int ne = 4;
    char equacoes2[30][100] = {"va+2*3",
                               "va-vb*3/4",
                               "1+1/vb",
                               "2/3+3*4"};
    
    for (int i=0; i<ne; i++) {
        substituir(2, variaveis, equacoes2[i]);
    }


	return 0;
}
