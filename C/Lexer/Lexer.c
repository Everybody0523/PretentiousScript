#include "token.h"
#include "token.c"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>



TokenNode * scanLine(const char * line)
{
    int l = strlen(line) + 1;
    char lineCopy[l];
    strcpy(lineCopy, line);
    char * s;
    s = strtok(lineCopy, " ");
    int isComment = strcmp(s, "Contemplation:");
    if (isComment == 0)
    {
        // Handle comments
        Token * t1 = newToken("COMMENT", line);
        TokenNode * output = newTokenNode(t1, NULL, NULL);
        return output;
    }
    else // Everything else
    {
        return NULL;
    }
    return NULL;

}


int main() {
    const char * t = "Contemplation: MEMBER_OF_Z x = 340";
    TokenNode * meep = scanLine(t);
    printf("%s\n", meep->value->value);
    return 0;
}
