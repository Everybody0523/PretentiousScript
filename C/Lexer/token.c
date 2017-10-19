#include "token.h"
#include <string.h>
#include <stdlib.h>

struct _Token
{
    char * type;
    char * value;
};

/*
* Constructor for a token.
*/
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

/*
* Constructor for a TokenNode.
*/
TokenNode * newTokenNode(Token * value, Token * next, Token * prev)
{
    TokenNode * output = malloc(sizeof(TokenNode));
    output->value = value;
    output->next = next;
    output->prev = prev;
    return output;
}

/*
Given the head of a linked list of TokenNodes, free the entire linked list.
WARNING: Don't use it to free just the head. Not that someone should be
doing that, because it would cause a leak! :O
*/
void freeTokenNodes(TokenNode * head)
{
    TokenNode * temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->value->type);
        free(temp->value->value);
        free(temp->value);
        // No need to free prev, it's already been freed. next is...well, next.
        // (To be freed, not in the tautological sense).
        free(temp);
    }
}
