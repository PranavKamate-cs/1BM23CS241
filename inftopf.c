#include<stdio.h>
#include<string.h>
int index1=0, pos=0, top=-1,length;
char symbol, temp, infix[20], postfix[20], stack[20];
void push(char symbol);
char pop();
int pred(char symbol);
void infixtopostfix();
int main(){
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    infixtopostfix();
    printf("\nIntfix expression: %s\n", infix);
    printf("\nPostfix expression: %s\n", postfix);
    return 0;
}

void infixtopostfix(){
    length = strlen(infix);
    while(index1<length){
        symbol = infix[index1];
        switch(symbol){
            case '(': {push(symbol);
                break;
            }
            case ')':{ temp = pop();
                while(temp!='('){
                    postfix[pos++] = temp;
                    temp = pop();
                }
                break;
            }
            case '+':
            case '-':
            case '*':
            case '/':{while(pred(stack[top])>=pred(symbol)){
                    temp=pop();
                    postfix[pos++]=temp;
                }
                push(symbol);
                break;
            }
            default : postfix[pos++]=symbol;
        }
        index1++;
    }
    while(top>0){
        temp = pop();
        postfix[pos++]=temp;
    }
}

void push(char symbol){
    top++;
    stack[top] = symbol;
}

char pop(){
    char symb = stack[top];
    top--;
    return symb;
}

int pred(char symbol){
    switch(symbol){
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '(':return 3;
    }
    return 0;
}
