#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

int main()
{
    regex_t compiled;
    char rexpr[] = "\"[[:print:]]\"";
    char shouldMatch[] = "\"d\"";
    int failed= regcomp(&compiled,rexpr,REG_EXTENDED);

    if (failed)
    {
        fprintf(stderr, "Failed to compile regular expression\n");
        return -1;
    }

    int matched = regexec(&compiled, shouldMatch, 0, 0, 0);

    printf("%d\n", matched); //0 if matches. It's currently printing 1??
}
