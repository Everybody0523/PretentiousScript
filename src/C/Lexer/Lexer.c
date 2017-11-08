#include "token.h"
#include "token.c"
#include "constants.h"
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

        while(token != NULL){

        }
        return NULL;
    }
    return NULL;

}


TokenNode * analyzeString(const char * s)
{
    int a = strcmp(s, PRIMITIVES[0])
    int b = strcmp(s, PRIMITIVES[1])
    if (a == 0 || b == 0)
    {
        const char * v = (a == 0) ? PRIMITIVES[0] : PRIMITIVES[1]);
        Token * t1 = newToken("PRIMITIVE", v)
        TokenNode * output = newTokenNode(t1, NULL, NULL);
        return output;
    }
    else
    {
    }
}

/*
Returns 0 if it DOESN'T match (because seriously, POSIX's built-in returning
0 ON match when 0 usually means false makes no sense). Returns 1 on failure
to match, and returns -1 when it fails to compile.
*/
int regexComp(const char * str, const char * pattern)
{
    regex_t compiled;
    int failed = regcomp(&compiled,pattern,REG_EXTENDED);
    if (failed)
    {
        return -1;
    }
    int matched = regexec(&compiled, str, 0, 0, 0);
    return (matched == 0) ? 1 : 0
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
