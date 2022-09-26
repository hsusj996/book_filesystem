#pragma once

#include "stdheaders.h"

#define BUCKET_SIZE 20
#define NAME_SIZE 30
#define CODE_SIZE 20
#define AUTHOR_SIZE 20
#define YEAR_SIZE 20

typedef struct {		//å ���� ����ü
	char sBookName[NAME_SIZE];
	char sBookCode[CODE_SIZE];
	char sAuthor[AUTHOR_SIZE];
	char sYear[YEAR_SIZE];
}BookInfo;

typedef struct node* NodePointer;		//���Ḯ��Ʈ
typedef struct node {
	int key;
	BookInfo data;
	NodePointer next;
};

typedef struct {			//�ؽ����̺� ����
	NodePointer head;
	int count;
}Bucket;
Bucket* HashTable;

int Hash_func(int key);

NodePointer createNode(BookInfo data, int key);

int Hash_Add(BookInfo data, int key);

int Hash_Del(int key);

int Hash_Search(int key);

int Hash_Update(BookInfo data, int key);