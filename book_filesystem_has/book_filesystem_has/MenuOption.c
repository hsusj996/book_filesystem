#include "MenuOption.h"

int Insert() {			//삽입 함수
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

	if (Hash_Add(Input, atoi(Input.sBookCode)) == 0) {
		printf("\n오류 : 등록 실패!\n");
		return 0;
	}
	printf("\n등록완료!\n");
	return 1;
}

int Delete() {			//삭제 함수
	char DeleteCode[CODE_SIZE];
	printf("2. 삭제하고 싶은 도서코드를 입력하세요. ");

	gets(DeleteCode);

	if (Hash_Del(atoi(DeleteCode)) == 0) {
		printf("\n오류 : 삭제 실패!\n");
		return 0;
	}
	printf("\n삭제 성공!\n");
	return 1;
}

void Print() {			//전체 도서목록 출력
	NodePointer temp;
	int iBook_Index = 0;

	printf("\n   %-20s %-10s %-15s %-10s\n", "도서명", "도서코드", "저자", "출판년도");
	printf("-----------------------------------------------------------------\n");

	for (int i = 0; i < BUCKET_SIZE; i++) {
		if (HashTable[i].count == 0) {		//버켓에 노드가 없다면 다음으로
			continue;
		}
		temp = HashTable[i].head;
		for (; temp; temp = temp->next) {
			printf("%d : ", iBook_Index++);
			printf("%-20s %-10s %-15s %-10s\n",
					temp->data.sBookName, temp->data.sBookCode, temp->data.sAuthor, temp->data.sYear);
		}
	}
	printf("\n");
}

int Search() {				//검색 함수
	char SearchCode[CODE_SIZE];

	printf("검색을 시작합니다.\n");
	printf("검색하고 싶은 도서코드를 입력하세요. (전체검색:0)");
	gets(SearchCode);

	if (strcmp(SearchCode, "0") == 0) {		//0 입력 시 전체목록 출력
		Print();
		return 1;
	}

	if (Hash_Search(atoi(SearchCode)) == 0) {
		printf("\n오류 : 해당 도서는 존재하지 않습니다!\n");
		return 0;
	}
	return 1;
}

int Update() {			//수정 함수
	char UpdateCode[CODE_SIZE];
	BookInfo UpdateBook;
	char Buffer[BUFFER_SIZE];
	int iBefore_Code;

	printf("수정을 시작합니다.\n");
	printf("수정하고 싶은 도서코드를 입력하세요. ");
	gets(UpdateCode);

	iBefore_Code = atoi(UpdateCode);		//업데이트할 도서코드를 정수로 변환 후 저장

	if (Hash_Search(iBefore_Code) == 0) {
		printf("\n오류 : 해당 도서는 존재하지 않습니다!\n");
		return 0;
	}

	printf("수정할 정보를 입력받습니다. (수정사항이 없다면 0을 입력)\n\n");

	printf("도서명 : ");		//도서 정보를 차례로 입력받아 temp노드의 데이터에 저장
	gets(Buffer);		//0 입력 시에는 수정 x
	strcpy(UpdateBook.sBookName, Buffer);

	printf("도서코드 : ");
	gets(Buffer);		//0 입력 시에는 수정 x
	strcpy(UpdateBook.sBookCode, Buffer);

	printf("저자명 : ");
	gets(Buffer);		//0 입력 시에는 수정 x
	strcpy(UpdateBook.sAuthor, Buffer);

	printf("출판일 : ");
	gets(Buffer);
	strcpy(UpdateBook.sYear, Buffer);

	if (Hash_Update(UpdateBook, iBefore_Code) == 0) {
		printf("\n오류 : 업데이트 실패!\n");
		return 0;
	}
	printf("\n수정완료!\n");
	return 1;
}