#include "File.h"


int LoadFile(FILE* fd) {		//���� �ε� �Լ�
	BookInfo TempData;
	char Buffer[BUFFER_SIZE];

	while (true) {
		memset(Buffer, 0, sizeof(Buffer));		//�ݺ����� ���� �ʱ�ȭ
		fgets(Buffer, sizeof(Buffer), fd);

		if (Buffer[0] == NULL) {		//gets���� NULL�� ���Դٸ�
			return 1;					//�� �̻� �����Ͱ� �����Ƿ� �ε� ��
		}

		char* ptr = strtok(Buffer, ",");		//strtok : ���ڿ��� ��ū �������� ����
		strcpy(TempData.sBookName, ptr);		//','�� �������� ���ڿ��� ������ ����
		ptr = strtok(NULL, ",");
		strcpy(TempData.sBookCode, ptr);
		ptr = strtok(NULL, ",");
		strcpy(TempData.sAuthor, ptr);
		ptr = strtok(NULL, ",");
		strcpy(TempData.sYear, strtok(ptr, "\n"));

		AddQueue(TempData);				//�ӽ� �����͸� ť�� �߰�
	}
	return -1;		//���� �� -1 ��ȯ
}

int SaveFile(char* FileName) {		//���� ���� �Լ�
	queuePointer temp = front;		//ť�� ��ȸ�� �ӽó�� temp

	printf("������ �����մϴ�.\n");

	FILE* fd;
	if ((fd = fopen(FileName, "w")) == NULL) {		//���� ����, ���� �� -1 ��ȯ
		fclose(fd);
		return -1;
	}

	for (; temp; temp = temp->link) {		//��带 ��ȸ�ϸ鼭 �����͸� ���Ͽ� ����
		fprintf(fd, "%s,%s,%s,%s\n", temp->data.sBookName, temp->data.sBookCode,
			temp->data.sAuthor, temp->data.sYear);
	}
	fclose(fd);
	return 1;		//���� �� 1 ��ȯ
}