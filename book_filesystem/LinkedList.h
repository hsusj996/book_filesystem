#pragma once
#include "stdheaders.h"

#define NAMESIZE 30
#define CODESIZE 20
#define AUTHORSIZE 20
#define YEARSIZE 20

typedef struct  {		//å ���� ����ü
	char sBookName[NAMESIZE];
	char sBookCode[CODESIZE];
	char sAuthor[AUTHORSIZE];
	char sYear[YEARSIZE];
}BookInfo;

typedef struct queue* queuePointer;		//��ũ�帮��Ʈ ť ����ü
typedef struct queue {
	BookInfo data;
	queuePointer link;
};
queuePointer front, rear;		//������ rear���� ����

void AddQueue(BookInfo Data);
