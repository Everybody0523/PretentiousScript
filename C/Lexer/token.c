#include "token.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct _Token
{
    char * type;
    char * value;
};

Token * newToken(const char * type, const char * value)
{
    Token * output = malloc(sizeof(Token));
    output->type = malloc(strlen(type) + 1);
    output->value = malloc(strlen(value) + 1);
    strcpy(output->type, type);
    strcpy(output->value, value);
    return output;
}

struct _TokenNode
{
    Token * value;
    TokenNode * next;
    TokenNode * prev;
}

Token * newTokenNode(Token * value, Token * next, Token * prev)
{
    TokenNode * output = malloc(sizeof(TokenNode));
    output->value = value;
    output->next = next;
    output->prev = prev;
    return output;
}
