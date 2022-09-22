#include "MenuOption.h"

void Insert() {			//삽입 함수
	BookInfo Input;
	printf("1. 등록할 도서 정보를 입력하세요. \n");		//삽입할 데이터 입력

	printf("도서명 : ");
	gets(Input.sBookName);

	printf("도서코드 : ");
	gets(Input.sBookCode);

	printf("저자명 : ");
	gets(Input.sAuthor);

	printf("출판일 : ");
	gets(Input.sYear);

	queuePointer temp = front;		//큐를 순회할 temp

	for (; temp; temp = temp->link) {
		if (strcmp(temp->data.sBookCode, "99999") == 0) {		//도서코드 "99999"는 삭제된 데이터를 의미
			strcpy(temp->data.sBookName, Input.sBookName);		//데이터가 삭제된 노드에 삽입
			strcpy(temp->data.sBookCode, Input.sBookCode);
			strcpy(temp->data.sAuthor, Input.sAuthor);
			strcpy(temp->data.sYear, Input.sYear);
			printf("등록완료!\n");
			return;
		}
	}
	AddQueue(Input);		//삭제된 노드가 없다면 큐에 새로운 노드 생성

	printf("등록완료!\n");
}

void Delete() {			//삭제 함수
	char DeleteCode[CODESIZE];
	printf("2. 삭제하고 싶은 도서코드를 입력하세요. ");

	gets(DeleteCode);

	queuePointer temp = front;

	for (; temp; temp = temp->link) {
		if (strcmp(DeleteCode, temp->data.sBookCode) == 0) {	//큐를 순회하면서 탐색
			strcpy(temp->data.sBookCode, "99999");				//삭제 시 도서코드를 "99999"로 변경
			printf("삭제완료!\n");
			return;
		}
	}
	if (temp == NULL) {
		printf("해당 도서는 존재하지 않습니다. \n");		//temp가 큐의 rear에 위치하면 도서는 존재하지 않음
	}
	return;
}

void Print() {			//전체 도서목록 출력
	queuePointer temp = front;
	int iBook_Index = 0;

	printf("\n\t도서명\t도서코드\t저자\t출판년도\n");
	printf("--------------------------------------------------\n");
	for (; temp; temp = temp->link) {
		if (strcmp(temp->data.sBookCode, "99999") == 0) {		//도서코드가 "99999"라면 삭제된 데이터를 의미
			continue;											//출력하지 않음
		}

		printf("%d : ", iBook_Index++);
		printf("%10s %10s %10s %10s\n", temp->data.sBookName, temp->data.sBookCode, temp->data.sAuthor, temp->data.sYear);
	}
	printf("\n");
}

void Search() {				//검색 함수
	queuePointer temp = front;
	char SearchCode[CODESIZE];

	printf("검색을 시작합니다.\n");
	printf("검색하고 싶은 도서코드를 입력하세요. (전체검색:0)");
	gets(SearchCode);

	if (strcmp(SearchCode, "0") == 0) {		//0 입력 시 전체목록 출력
		Print();
		return;
	}
	else if (strcmp(SearchCode, "99999") == 0) {	//99999 도서코드는 잘못된 입력
		printf("\n잘못된 입력입니다.\n");
		return;
	}

	printf("\n\t도서명\t도서코드\t저자\t출판년도\n");
	printf("--------------------------------------------------\n");
	for (; temp; temp = temp->link) {
		if (strcmp(SearchCode, temp->data.sBookCode) == 0) {		//원하는 도서코드를 찾으면 해당 도서정보 출력
			printf("1 : ");
			printf("%10s %10s %10s %10s\n\n", temp->data.sBookName, temp->data.sBookCode, temp->data.sAuthor, temp->data.sYear);
			break;
		}
	}
	if (temp == NULL) {		//temp가 큐의 rear에 위치하면 도서는 존재하지 않음
		printf("\n해당 도서코드는 존재하지 않습니다.\n");
		return;
	}
}

void Update() {			//수정 함수
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

	printf("도서명 : ");				//도서 정보를 차례로 입력받아 temp노드의 데이터에 저장
	gets(UpdateBook.sBookName);		//0 입력 시에는 수정 x
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