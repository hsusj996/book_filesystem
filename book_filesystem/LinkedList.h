#pragma once
#include "stdheaders.h"

#define NAMESIZE 30
#define CODESIZE 20
#define AUTHORSIZE 20
#define YEARSIZE 20

typedef struct  {
	char sBookName[NAMESIZE];
	char sBookCode[CODESIZE];
	char sAuthor[AUTHORSIZE];
	char sYear[YEARSIZE];
}BookInfo;

typedef struct queue* queuePointer;
typedef struct queue {
	BookInfo data;
	queuePointer link;
};
queuePointer front, rear;

void AddQueue(BookInfo Data);
