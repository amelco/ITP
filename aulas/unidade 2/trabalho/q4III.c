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
            printf("x: %c, item: %c\t%d && %d\n", x, item, eh_operador(x), prioridade(x) >= prioridade(item));
            /* verifica se é operador [1 ou 0] */
			while(eh_operador(x) && prioridade(x)>= prioridade(item))
			{
                printf("TRUE\n");
				postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = pop();                       /* add them to postfix expresion */
			}
			push(x);
			/* because just above while loop will terminate we have
			oppped one extra item
			for which condition fails and loop terminates, so that one*/

			push(item);                 /* push current oprerator symbol onto stack */
		}
        else if(item == ')')         /* if current symbol is ')' then */
		{
			x = pop();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			printf("\nExpressão infix inválida.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; /* go to next symbol of infix expression */
	} /* while loop ends here */
	if(topo > 0)
	{
		printf("\nExpressão infix inválida.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}
	if(topo > 0)
	{
		printf("\nExpressão infix inválida.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */

}

int main() {
    char infix[TAM], postfix[TAM];         /* declare infix string and postfix string */

	/* why we asked the user to enter infix expression
	* in parentheses ( )
	* What changes are required in porgram to
	* get rid of this restriction since it is not
	* in algorithm
	* */
	printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
	printf("\nEnter Infix expression : ");
	// gets(infix);
    scanf("%s", infix);

	InfixToPostfix(infix,postfix);                   /* call to convert */
	printf("Postfix Expression: %s\n", postfix);
	// puts(postfix);                     /* print postfix expression */
    // printf("%s\n", postfix);

	return 0;
}
