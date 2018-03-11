#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    /* as same as the original */
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* as same as the original */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pDetails = (entryDetails *) malloc(sizeof(entryDetails));
    e->pNext = NULL;

    return e;
}
