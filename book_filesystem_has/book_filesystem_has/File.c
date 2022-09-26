#include "File.h"

int LoadFile(FILE* fd) {		//파일 로드
	BookInfo TempData;
	char Buffer[BUFFER_SIZE];

	while (true) {
		memset(Buffer, 0, sizeof(Buffer));		//반복마다 버퍼 초기화
		fgets(Buffer, sizeof(Buffer), fd);

		if (Buffer[0] == NULL) {		//gets에서 NULL이 나왔다면
			return 1;					//더 이상 데이터가 없으므로 로드 끝
		}

		char* ptr = strtok(Buffer, ",");		//strtok : 문자열을 토큰 기준으로 나눔
		strcpy(TempData.sBookName, ptr);		//','를 기준으로 문자열을 나누고 저장
		ptr = strtok(NULL, ",");
		strcpy(TempData.sBookCode, ptr);
		ptr = strtok(NULL, ",");
		strcpy(TempData.sAuthor, ptr);
		ptr = strtok(NULL, ",");
		strcpy(TempData.sYear, strtok(ptr, "\n"));

		if (Hash_Add(TempData, atoi(TempData.sBookCode)) == 0) {		//해시테이블에 데이터 삽입
			printf("오류 : 테이블에 데이터 추가 불가\n");
			break;
		}
	}
	return 0;		//실패 시 0 반환
}

int SaveFile(char* FileName) {		//파일 저장 함수
	NodePointer temp;

	printf("저장을 시작합니다.\n");

	FILE* fd;
	if ((fd = fopen(FileName, "w")) == NULL) {		//파일 오픈, 실패 시 0 반환
		fclose(fd);
		return 0;
	}

	for (int i = 0; i < BUCKET_SIZE; i++) {			//각 버켓의 노드들을 탐색하여 저장
		temp = HashTable[i].head;
		for (; temp; temp = temp->next) {
			fprintf(fd, "%s,%s,%s,%s\n", temp->data.sBookName, temp->data.sBookCode,
				temp->data.sAuthor, temp->data.sYear);
		}
	}
	fclose(fd);
	return 1;		//성공 시 1 반환
}
