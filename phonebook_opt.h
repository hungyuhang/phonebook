#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define MAX_HASH_SIZE 8192

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1

typedef struct __PHONE_BOOK_ENTRY_DETAILS {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} entryDetails;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY_DETAILS *pDetails;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __TABLE_ELEMENT {
    struct __PHONE_BOOK_ENTRY *pBottom;
    struct __PHONE_BOOK_ENTRY *pHead;
} tableElement;

entry *findName(char lastName[], tableElement *pHead);
tableElement *append(char lastName[], tableElement *e);
unsigned int BKDRHash(char *str);

#endif
