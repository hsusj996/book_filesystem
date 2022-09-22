#include "File.h"


int LoadFile(FILE* fd) {
	BookInfo TempData;
	char Buffer[BUFFER_SIZE];
	int i = 0;

	while (true) {
		memset(Buffer, 0, sizeof(Buffer));
		fgets(Buffer, sizeof(Buffer), fd);

		if (Buffer[0] == NULL) {
			return 1;
		}

		char* ptr = strtok(Buffer, ",");
		strcpy(TempData.sBookName, ptr);
		ptr = strtok(NULL, ",");
		strcpy(TempData.sBookCode, ptr);
		ptr = strtok(NULL, ",");
		strcpy(TempData.sAuthor, ptr);
		ptr = strtok(NULL, ",");
		strcpy(TempData.sYear, strtok(ptr, "\n"));

		AddQueue(TempData);
	}
	return -1;
}

int SaveFile(char* FileName) {
	queuePointer temp = front;

	printf("저장을 시작합니다.\n");

	FILE* fd;
	if ((fd = fopen(FileName, "w")) == NULL) {
		fclose(fd);
		return -1;
	}

	for (; temp; temp = temp->link) {
		fprintf(fd, "%s,%s,%s,%s\n", temp->data.sBookName, temp->data.sBookCode,
			temp->data.sAuthor, temp->data.sYear);
	}
	fclose(fd);
	return 1;
}