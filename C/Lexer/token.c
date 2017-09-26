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

int main()
{
    Token * t = newToken("Member_of_Z", "44");
    printf("%s\n", t->type);
    printf("%s\n", t->value);
    return 0;
}
