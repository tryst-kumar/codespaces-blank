#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stack
{
    char* word;
    int size;
    int top;
}Stack;

void initStack(Stack *s, int size)
{
    s->word = (char*)malloc(sizeof(char) * size);
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

void push(Stack* s, char element)
{
    if (isFull(s))
    {
        return;
    }
    s->top++;
    s->word[s->top] = element;
}

char pop(Stack* s)
{
    if (isEmpty(s))
    {
        return ' ';
    }
    char temp = s->word[s->top];
    s->top--;
    return temp;
}

void freeStack(Stack* s)
{
    free(s->word);
}


int reverse(int n)
{
    char str[12];;
    sprintf(str, "%d", n);
    Stack s;
    initStack(&s, 12);
    int l = strlen(str);
    for (int i = 0; i < l; i++)
    {
        push(&s, str[i]);
    }

    char sr[12];
    for (int i = 0; i < l; i++)
    {
        sr[i] = pop(&s);
    }
    sr[l] = '\0';
    
    int temp = atoi(sr);
    freeStack(&s);
    return temp;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    printf("Enter Nummber: %s\n", argv[1]);
    printf("Result: %i\n", reverse(atoi(argv[1])));

    return 0;
}