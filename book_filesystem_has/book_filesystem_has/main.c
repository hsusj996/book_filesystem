#include "stdheaders.h"			//std헤더파일 묶음
#include "HashTable.h"			//해시테이블 헤더
#include "MenuOption.h"			//메뉴옵션 헤더
#include "File.h"				//파일옵션 헤더

#define BUFFER_SIZE 100
#define FILE_SIZE 128

enum FileOption {		//파일 옵션
	NO_FILE_OPTION, NEW_FILE, LOAD_FILE
};

enum MenuOption {		//메뉴 옵션
	NO_MENU_OPTION, INSERT, DEL, UPDATE, SEARCH, EXIT
};

void Init(char FileName[]) {
	int iFileOption;
	FILE* fd;

	printf("도서목록 파일시스템 프로그램입니다.\n");
	printf("1. 새로 만들기, 2. 불러오기, 3. 종료 => ");
	scanf_s("%d", &iFileOption);
	getchar();

	if (iFileOption == NEW_FILE) {			//새 파일 생성
		printf("새로 만들 파일명을 입력해주세요. : ");
		gets(FileName);
		if ((fd = fopen(FileName, "w")) == NULL) {
			printf("에러 : 파일을 열 수 없습니다. \n");
			return;
		}
	}
	else if (iFileOption == LOAD_FILE) {	//기존 파일 로드
		while (true) {
			printf("불러올 파일명을 입력해주세요.(Q 입력 시 종료) : ");
			gets(FileName);

			if (FileName[0] == 'Q' || FileName[0] == 'q') {
				printf("종료합니다. \n");
				return 0;
			}

			if ((fd = fopen(FileName, "r")) == NULL) {
				printf("에러 : 해당 파일은 존재하지 않습니다. 다시 입력해주세요. \n");
			}
			else {
				if (LoadFile(fd) == 0) {			//파일로드 실행, 실패 시 0 반환
					printf("\n불러오기 실패\n");
					continue;
				}
				else {
					printf("\n불러오기 성공! \n");
					break;
				}
			}
		}
	}

	else {
		printf("\n종료합니다.\n");
		return;
	}

	fclose(fd);
	return;
}

void Run(char FileName[]) {		//실행 동작
	int iMenuOption;		//메뉴 옵션 변수

	while (true) {
		printf("1: 삽입, 2: 삭제, 3: 수정, 4: 검색, 5: 종료 => ");
		scanf_s("%d", &iMenuOption);
		getchar();

		switch (iMenuOption) {
		case INSERT:	//삽입
			Insert();
			break;
		case DEL:		//삭제
			Delete();
			break;
		case UPDATE:	//수정
			Update();
			break;
		case SEARCH:	//검색
			Search();
			break;
		default:		//저장 및 종료
			if (SaveFile(FileName) == 1) {
				printf("\n저장성공!\n");
			}
			else {
				printf("\n저장실패!\n");
			}
			printf("\n종료합니다.\n");
			system("pause");
			return;
		}
		system("pause");
		system("cls");
	}
	return;
}

int main() {
	HashTable = (Bucket*)malloc(BUCKET_SIZE * sizeof(Bucket));		//HashTable.h에 선언된 해시테이블에 메모리할당

	for (int i = 0; i < BUCKET_SIZE; i++) {			//해시테이블 초기화
		HashTable[i].count = 0;
		HashTable[i].head = NULL;
	}

	char FileName[FILE_SIZE];
	Init(FileName);				//파일 옵션

	system("pause");
	system("cls");

	Run(FileName);				//동작 실행

	return 0;
}