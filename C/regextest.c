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
    printf("Testing: printable character:")
    printf("%d\n", matched);


    char matchDigit[] = "[[:digit:]]*";
    shouldMatch[] = "3434312351235342349";
    failed= regcomp(&compiled,rexpr,REG_EXTENDED);
    if (failed)
    {
        fprintf(stderr, "Failed to compile regular expression\n");
        return -1;
    }
    printf("Testing: Any number of digits:")
    printf("%d\n", matched);
}
