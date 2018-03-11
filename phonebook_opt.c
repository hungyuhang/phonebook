#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry **pHead)
{
    unsigned int index = BKDRHash(lastName);
    entry *pEntry = *(pHead + index);
    while (pEntry != NULL) {
        if (strcasecmp(lastName, pEntry->lastName) == 0)
            return pEntry;
        pEntry = pEntry->pNext;
    }

    return NULL;
}

entry **append(char lastName[], entry **e)
{
    entry **pHead = e;
    unsigned int index = BKDRHash(lastName);
    entry **ppEntry = (e + index);
    entry *pEntry = *ppEntry;

    if (*ppEntry == NULL) {
        *ppEntry = (entry *) malloc(sizeof(entry));
        pEntry = *ppEntry;
    } else {
        while (pEntry != NULL) {
            if (pEntry->pNext == NULL) {
                break;
            } else {
                pEntry = pEntry->pNext;
            }
        }
        pEntry->pNext = (entry *) malloc(sizeof(entry));
        pEntry = pEntry->pNext;
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