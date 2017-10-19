#include "token.h"
#include "token.c"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>


/*
* Search the string array (ie. array of array of characters) for a string,
* value. Return 0 if found, and 1 if not found.
*/
int searchArrayForString(const char * value, const char ** arr, size_t n)
{
    size_t i = 0;
    int found=0;
    for(i=0;i<length;i++){
        if (strcmp(*(arr + i),value) == 0){
            found = 1;
        }
    }
    return found == 1 ? 0 : 1;
}

/*
* Generate a (linked) List of TokenNodes from a line of PretentiousScript
* code.
*/
TokenNode * scanLine(const char * line)
{
    int l = strlen(line) + 1;
    char lineCopy[l];
    strcpy(lineCopy, line);
    char * s;
    s = strtok(lineCopy, " ");
    int isComment = strcmp(s, "Contemplation:");
    int mayAlsoBeComment = strcmp(s, "contemplation");
    if (isComment == 0 || mayAlsoBeComment == 0)
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




/*
* Main method for testing purposes.
*/
int main()
{
    const char * t = "MEMBER_OF_Z x = 340";
    TokenNode * meep = scanLine(t);
    printf("%s\n", meep->value->value);
    return 0;
}
