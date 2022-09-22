#include "File.h"


int LoadFile(FILE* fd) {		//파일 로드 함수
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

		AddQueue(TempData);				//임시 데이터를 큐에 추가
	}
	return -1;		//실패 시 -1 반환
}

int SaveFile(char* FileName) {		//파일 저장 함수
	queuePointer temp = front;		//큐를 순회할 임시노드 temp

	printf("저장을 시작합니다.\n");

	FILE* fd;
	if ((fd = fopen(FileName, "w")) == NULL) {		//파일 오픈, 실패 시 -1 반환
		fclose(fd);
		return -1;
	}

	for (; temp; temp = temp->link) {		//노드를 순회하면서 데이터를 파일에 삽입
		fprintf(fd, "%s,%s,%s,%s\n", temp->data.sBookName, temp->data.sBookCode,
			temp->data.sAuthor, temp->data.sYear);
	}
	fclose(fd);
	return 1;		//성공 시 1 반환
}