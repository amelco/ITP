/* 
  REFERENCIAS
    infix to postifx:
    1. https://csis.pace.edu/~wolf/CS122/infix-postfix.htm
    2. https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/

    evaluate postfix:
    3. https://www.tutorialspoint.com/Evaluate-Postfix-Expression
    4. https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // para usar exit()
#include <ctype.h>      // para usar isdigit()

#define TAM 100         // define uma constante TAM (tamanho) de valor igual a 100

typedef enum boll_t {false=0, true} bool;     // define tipo booleano [false=0, true=1]

char pilha[TAM];        // variável global pilha [0-99]. Global porque é utilizada em várias funções
int topo = -1;          // variável "topo" da pilha. [-1: sem elementos, 0: 1 elemento, ... 99: 100 elementos]

// define a operação 'push' da pilha [colocar elemento na pilha]
void push (char item) {
    if (topo >= TAM) {
        printf("\nPilha Sobrecarregada (Stack Overflow).\n");
    } else {
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
    if(simbolo == '*' || simbolo == '/' || simbolo == '+' || simbolo =='-')
	{
		return true;
	}
	else
	{
	return false;
	}
}

// define função para retornar a prioridade de um operador
//  => retorna um inteiro. Quanto maior o inteiro, maior a prioridade
int prioridade (char simbolo) {
    if(simbolo == '*' || simbolo == '/')
	{
		return 2;
	}
	else if(simbolo == '+' || simbolo == '-')          // menor prioridade
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// define função que tranforma infix para postfix
// os números só podem ter um algarismo
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

	while(item != '\0')                     // executa loop até fim da string 
	{
		if(item == '(')
		{
			push(item);
		}
		else if(isdigit(item))
		{
			postfix_exp[j] = item;              // adiciona o numero à expressão postfix
			j++;
		}
		else if(eh_operador(item))              // item é um operador [+, -, *, /]
		{
			x=pop();                            // retira elemento da pilha e armazena em x
            // printf("x: %c, item: %c\t%d && %d\n", x, item, eh_operador(x), prioridade(x) >= prioridade(item));
            
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
			while(eh_operador(x) && prioridade(x)>= prioridade(item))
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
			push(x);            // coloca de volta o item que foi retirado ao fim do loop
			push(item);         // coloca o item atual na pilha
		}
        // se o item é ')' então retira os elementos da pilha e escreve no postfix até encontrar um '('
        else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
        // se o item não é '(' ou ')' e nem um operador, então é um símbolo não permitido
		{
			printf("\nExpressão infix inválida.\n");
			getchar();
			exit(1);
		}

		i++;
		item = infix_exp[i];        // armazena o próximo símbolo da expressão infix
	}                               // fim do while

    // Ao fim do while loop, a pilha deve estar vazia
	if(topo > 0)
	{
		printf("\nExpressão infix inválida.\n");
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0';          // finaliza a string da expressao postfix

}

int calc(char x,int op1,int op2)
{
	if(x == '+')
		return(op1+op2);
	if(x == '-')
		return(op1-op2);
	if(x == '*')
		return(op1*op2);
	if(x == '/')
		return(op1/op2);
	if(x == '%')
		return(op1%op2);
}

int resolve(char postfix[]) {
    int i;
    char item;
    int op1, op2, val;

    topo = -1;
    i = 0;
    item = postfix[i];
    
    while (item != '\0'){
        // printf("%d %c\n", i, item);
        if (isdigit(item))
            push(item);
        else {
            op1 = pop()-48;         // item-48 para retornar o número inteiro ao inves do codigo ASCII
            op2 = pop()-48;
            val = calc(item, op1, op2);
            push(val+48);
        }

        i++;
        item = postfix[i];
    }
    
    // val = pop()-48;
    printf("Resultado: %d\n", val);

}

int main() {
     int n = 4;  // número de equações
    // cria vetor de strings que pode armazenar até 30 equações com 100 caracteres
    char equacoes[30][100] = {"1+2*3",
                         "1-2*3/4", 
                         "1+1/2", 
                         "2/3+3*4"};
    // strings para serem usadas na função InfixToPostfix()
    char infix[TAM], postfix[TAM];

    for (int i=0; i<n; i++) {
        // scanf("%s", infix);
        strcpy(infix, equacoes[i]);
        InfixToPostfix(infix,postfix);
        printf("Postfix Expression: %s\n", postfix);
        resolve(postfix);
        
    }
	

	return 0;
}
