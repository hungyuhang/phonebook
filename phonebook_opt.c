#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], tableElement *pHead)
{
    unsigned int index = BKDRHash(lastName);
    entry *pEntry = (pHead + index)->pHead;

    while (pEntry != NULL) {
        if (strcasecmp(lastName, pEntry->lastName) == 0)
            return pEntry;
        pEntry = pEntry->pNext;
    }

    return NULL;
}

tableElement *append(char lastName[], tableElement *e)
{
    tableElement *pHead = e;
    unsigned int index = BKDRHash(lastName);
    entry *pEntry = NULL;
    e += index;

    if (e->pHead == NULL) {
        e->pHead = (entry *) malloc(sizeof(entry));
        pEntry = e->pHead;
        e->pBottom = pEntry;
    } else {
        e->pBottom->pNext = (entry *) malloc(sizeof(entry));
        pEntry = e->pBottom->pNext;
        e->pBottom = pEntry;
    }
    strcpy(pEntry->lastName, lastName);
    pEntry->pDetails = NULL;
    pEntry->pNext = NULL;

    return pHead;
}

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str) {
        hash = hash * seed + (*str++);
    }

    return (hash & (MAX_HASH_SIZE - 1)); // hash & 0x000001FF
}
