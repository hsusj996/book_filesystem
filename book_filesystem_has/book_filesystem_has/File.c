#include "File.h"

int LoadFile(FILE* fd) {		//���� �ε�
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

		if (Hash_Add(TempData, atoi(TempData.sBookCode)) == 0) {		//�ؽ����̺� ������ ����
			printf("���� : ���̺� ������ �߰� �Ұ�\n");
			break;
		}
	}
	return 0;		//���� �� 0 ��ȯ
}

int SaveFile(char* FileName) {		//���� ���� �Լ�
	NodePointer temp;

	printf("������ �����մϴ�.\n");

	FILE* fd;
	if ((fd = fopen(FileName, "w")) == NULL) {		//���� ����, ���� �� 0 ��ȯ
		fclose(fd);
		return 0;
	}

	for (int i = 0; i < BUCKET_SIZE; i++) {			//�� ������ ������ Ž���Ͽ� ����
		temp = HashTable[i].head;
		for (; temp; temp = temp->next) {
			fprintf(fd, "%s,%s,%s,%s\n", temp->data.sBookName, temp->data.sBookCode,
				temp->data.sAuthor, temp->data.sYear);
		}
	}
	fclose(fd);
	return 1;		//���� �� 1 ��ȯ
}
