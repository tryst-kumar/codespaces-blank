#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack
{
    int* word;
    int size;
    int top;
} Stack;

void initStack(Stack *s, int size)
{
    s->word = (int*)malloc(sizeof(int) * size);
    if (s->word == NULL)
    {
        printf("Failed Allocation\n");
        return;
    }
    s->top = -1;
    s->size = size;
}

bool isEmpty(Stack* s)
{
    return s->top == -1;
}

bool isFull(Stack* s)
{
    return s->top == s->size - 1;
}

void push(Stack* s, int element)
{
    if (isFull(s))
    {
        return;
    }
    s->top++;
    s->word[s->top] = element;
}

int pop(Stack* s)
{
    if (isEmpty(s))
    {
        return -1; // Changed to return an invalid value
    }
    int temp = s->word[s->top];
    s->top--;
    return temp;
}

void freeStack(Stack* s)
{
    free(s->word);
}

int evaluation(const char* postfix)
{
    Stack s;
    initStack(&s, strlen(postfix));
    int i = 0;

    char c;
    while ((c = postfix[i++]) != '\0')
    {
        if (c == ' ')
        {
            continue;
        }
        if (isdigit(c))
        {
            push(&s, c - '0');
        }
        else
        {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (c)
            {
            case '+':
                push(&s, operand1 + operand2);
                break;
            case '-':
                push(&s, operand1 - operand2);
                break;
            case '*':
                push(&s, operand1 * operand2);
                break;
            case '/':
                push(&s, operand1 / operand2);
                break;
            default:
                break;
            }
        }
    }
    int result = pop(&s);
    freeStack(&s);
    return result;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <postfix expression>\n", argv[0]);
        return 1;
    }

    const char* postfix = argv[1];
    printf("%d\n", evaluation(postfix));
    return 0;
}
