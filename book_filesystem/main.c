#include "stdheaders.h"			//라이브러리 모음
#include "LinkedList.h"
#include "MenuOption.h"
#include "File.h"

void Init(char FileName[]) {	//최초 실행 함수
	int iFileOption;	//파일로드 옵션
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
				if (LoadFile(fd) == -1) {
					printf("불러오기 실패\n");
					continue;
				}
				else {
					printf("불러오기 성공! \n");
					break;
				}
			}
		}
	}

	else {
		printf("종료합니다. \n");
		return;
	}

	fclose(fd);
	return;
}

void Run(char FileName[]) {		//실행 동작 함수
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
				printf("저장성공!\n");
			}
			else {
				printf("저장실패!\n");
			}
			printf("종료합니다.\n");
			return 0;
		}
		system("pause");
		system("cls");
	}
}

int main() {

	char FileName[FILE_SIZE];
	
	Init(FileName);

	system("pause");
	system("cls");

	Run(FileName);

	return 0;
}
