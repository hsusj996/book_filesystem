#include "stdheaders.h"
#include "LinkedList.h"
#include "MenuOption.h"
#include "File.h"

void Init(char FileName[]) {
	int iFileOption;
	FILE* fd;

	printf("도서목록 파일시스템 프로그램입니다.\n");
	printf("1. 새로 만들기, 2. 불러오기, 3. 종료 => ");
	scanf_s("%d", &iFileOption);
	getchar();

	if (iFileOption == NEW_FILE) {
		printf("새로 만들 파일명을 입력해주세요. : ");
		gets(FileName);
		if ((fd = fopen(FileName, "w")) == NULL) {
			printf("에러 : 파일을 열 수 없습니다. \n");
			return;
		}
	}

	else if (iFileOption == LOAD_FILE) {
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

void Run(char FileName[]) {
	int iMenuOption;

	while (true) {
		printf("1: 삽입, 2: 삭제, 3: 수정, 4: 검색, 5: 종료 => ");
		scanf_s("%d", &iMenuOption);
		getchar();

		switch (iMenuOption) {
		case INSERT:
			Insert();
			break;
		case DEL:
			Delete();
			break;
		case UPDATE:
			Update();
			break;
		case SEARCH:
			Search();
			break;
		default:
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
