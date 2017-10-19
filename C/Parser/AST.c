#include "AST.h"
#include <string.h>
#include <stdlib.h>

/*
* Struct for an Abstract Syntax Tree Node.
*/
struct _AST
{
    char * type;
    char * value;

    AST * firstborn;
    // Because the amount of children of each AST Node may vary, we need to
    // use something dynamic, hence we store the children of each AST as a
    // linked list. firstborn denotes the head of the linked list of children.

    AST * nextSibling;
    AST * previousSibling;
    // In case this "instance" (to borrow a term from OOP) of a AST is not a
    // root, and it has siblings. These point to the next and previous values
    //in its parent's linked list of siblings.
};

/*
* AST Constructor.
*/
AST * newAST(char * type, char * value, AST * child, AST * next, AST * prev)
{
    AST * output = malloc(sizeof(AST));
    output->type = type;
    output->value = value;
    output->firstborn = child;
    output->nextSibling = next;
    output->previousSibling = prev;
    return output;
}


/*
* Free an entire tree of AST nodes. My choice of naming presents some
* issues with grammar.
*/
void freeEntireAST(AST * root)
{
    if (root->firstborn == NULL)
    {
        // Free siblings.
        AST * temp;
        while (root != NULL)
        {
            temp = root;
            root = root->nextSibling;
            free(temp->type);
            free(temp->value);
            if (temp->firstborn != NULL)
            {
                freeEntireAST(temp);
            }
            free(temp);
        }
    }
    else
    {
        // Free all children, then free itself. Base case covers all
        // children too. :)
        freeEntireAST(root->firstborn);
         
        // Free siblings.
        AST * temp;
        while (root != NULL)
        {
            temp = root;
            root = root->nextSibling;
            free(temp->type);
            free(temp->value);
            if (temp->firstborn != NULL)
            {
                freeEntireAST(temp);
            }
            free(temp);
        }
    }
}
