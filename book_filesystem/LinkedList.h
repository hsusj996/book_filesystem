#pragma once
#include "stdheaders.h"

#define NAMESIZE 30
#define CODESIZE 20
#define AUTHORSIZE 20
#define YEARSIZE 20

typedef struct  {		//책 정보 구조체
	char sBookName[NAMESIZE];
	char sBookCode[CODESIZE];
	char sAuthor[AUTHORSIZE];
	char sYear[YEARSIZE];
}BookInfo;

typedef struct queue* queuePointer;		//링크드리스트 큐 구조체
typedef struct queue {
	BookInfo data;
	queuePointer link;
};
queuePointer front, rear;		//삽입은 rear에서 동작

void AddQueue(BookInfo Data);
