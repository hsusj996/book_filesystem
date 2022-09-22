#include "MenuOption.h"

void Insert() {
	BookInfo Input;
	printf("1. 등록할 도서 정보를 입력하세요. \n");

	printf("도서명 : ");
	gets(Input.sBookName);

	printf("도서코드 : ");
	gets(Input.sBookCode);

	printf("저자명 : ");
	gets(Input.sAuthor);

	printf("출판일 : ");
	gets(Input.sYear);

	queuePointer temp = front;

	for (; temp; temp = temp->link) {
		if (strcmp(temp->data.sBookCode, "99999") == 0) {
			strcpy(temp->data.sBookName, Input.sBookName);
			strcpy(temp->data.sBookCode, Input.sBookCode);
			strcpy(temp->data.sAuthor, Input.sAuthor);
			strcpy(temp->data.sYear, Input.sYear);
			printf("등록완료!\n");
			return;
		}
	}
	AddQueue(Input);

	printf("등록완료!\n");
}

void Delete() {
	char DeleteCode[CODESIZE];
	printf("2. 삭제하고 싶은 도서코드를 입력하세요. ");

	gets(DeleteCode);

	queuePointer temp = front;

	for (; temp; temp = temp->link) {
		if (strcmp(DeleteCode, temp->data.sBookCode) == 0) {
			strcpy(temp->data.sBookCode, "99999");
			printf("삭제완료!\n");
			return;
		}
	}
	printf("해당 도서는 존재하지 않습니다. \n");
}

void Print() {
	queuePointer temp = front;
	int iBook_Index = 0;

	printf("\n\t도서명\t도서코드\t저자\t출판년도\n");
	printf("--------------------------------------------------\n");
	for (; temp; temp = temp->link) {
		if (strcmp(temp->data.sBookCode, "99999") == 0) {
			continue;
		}

		printf("%d : ", iBook_Index++);
		printf("%10s %10s %10s %10s\n", temp->data.sBookName, temp->data.sBookCode, temp->data.sAuthor, temp->data.sYear);
	}
	printf("\n");
}

void Search() {
	queuePointer temp = front;
	char SearchCode[CODESIZE];

	printf("검색을 시작합니다.\n");
	printf("검색하고 싶은 도서코드를 입력하세요. (전체검색:0)");
	gets(SearchCode);

	if (strcmp(SearchCode, "0") == 0) {
		Print();
		return;
	}
	else if (strcmp(SearchCode, "99999") == 0) {
		printf("\n잘못된 입력입니다.\n");
		return;
	}

	printf("\n\t도서명\t도서코드\t저자\t출판년도\n");
	printf("--------------------------------------------------\n");
	for (; temp; temp = temp->link) {
		if (strcmp(SearchCode, temp->data.sBookCode) == 0) {
			printf("1 : ");
			printf("%10s %10s %10s %10s\n\n", temp->data.sBookName, temp->data.sBookCode, temp->data.sAuthor, temp->data.sYear);
			break;
		}
	}
	if (temp == NULL) {
		printf("\n해당 도서코드는 존재하지 않습니다.\n");
		return;
	}
}

void Update() {
	queuePointer temp = front;
	char UpdateCode[CODESIZE];
	BookInfo UpdateBook;

	printf("수정을 시작합니다.\n");
	printf("수정하고 싶은 도서코드를 입력하세요. ");
	gets(UpdateCode);

	if (strcmp(UpdateCode, "99999") == 0) {
		printf("\n잘못된 입력입니다.\n");
		return;
	}

	printf("\n\t도서명\t도서코드\t저자\t출판년도\n");
	printf("--------------------------------------------------\n");
	for (; temp; temp = temp->link) {
		if (strcmp(UpdateCode, temp->data.sBookCode) == 0) {
			printf("1 : ");
			printf("%10s %10s %10s %10s\n\n", temp->data.sBookName, temp->data.sBookCode, temp->data.sAuthor, temp->data.sYear);
			break;
		}
	}

	if (temp == NULL) {
		printf("\n해당 도서코드는 존재하지 않습니다.\n");
		return;
	}

	printf("수정할 정보를 입력받습니다. (수정사항이 없다면 0을 입력)\n\n");

	printf("도서명 : ");
	gets(UpdateBook.sBookName);
	if (strcmp(UpdateBook.sBookName, "0") == 1) {
		strcpy(temp->data.sBookName, UpdateBook.sBookName);
	}

	printf("도서코드 : ");
	gets(UpdateBook.sBookCode);
	if (strcmp(UpdateBook.sBookCode, "0") == 1) {
		strcpy(temp->data.sBookCode, UpdateBook.sBookCode);
	}

	printf("저자명 : ");
	gets(UpdateBook.sAuthor);
	if (strcmp(UpdateBook.sAuthor, "0") == 1) {
		strcpy(temp->data.sAuthor, UpdateBook.sAuthor);
	}

	printf("출판일 : ");
	gets(UpdateBook.sYear);
	if (strcmp(UpdateBook.sYear, "0") == 1) {
		strcpy(temp->data.sYear, UpdateBook.sYear);
	}

	printf("수정완료!\n");
}