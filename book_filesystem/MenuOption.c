#include "MenuOption.h"

void Insert() {
	BookInfo Input;
	printf("1. ����� ���� ������ �Է��ϼ���. \n");

	printf("������ : ");
	gets(Input.sBookName);

	printf("�����ڵ� : ");
	gets(Input.sBookCode);

	printf("���ڸ� : ");
	gets(Input.sAuthor);

	printf("������ : ");
	gets(Input.sYear);

	queuePointer temp = front;

	for (; temp; temp = temp->link) {
		if (strcmp(temp->data.sBookCode, "99999") == 0) {
			strcpy(temp->data.sBookName, Input.sBookName);
			strcpy(temp->data.sBookCode, Input.sBookCode);
			strcpy(temp->data.sAuthor, Input.sAuthor);
			strcpy(temp->data.sYear, Input.sYear);
			printf("��ϿϷ�!\n");
			return;
		}
	}
	AddQueue(Input);

	printf("��ϿϷ�!\n");
}

void Delete() {
	char DeleteCode[CODESIZE];
	printf("2. �����ϰ� ���� �����ڵ带 �Է��ϼ���. ");

	gets(DeleteCode);

	queuePointer temp = front;

	for (; temp; temp = temp->link) {
		if (strcmp(DeleteCode, temp->data.sBookCode) == 0) {
			strcpy(temp->data.sBookCode, "99999");
			printf("�����Ϸ�!\n");
			return;
		}
	}
	printf("�ش� ������ �������� �ʽ��ϴ�. \n");
}

void Print() {
	queuePointer temp = front;
	int iBook_Index = 0;

	printf("\n\t������\t�����ڵ�\t����\t���ǳ⵵\n");
	printf("--------------------------------------------------\n");
	for (; temp; temp = temp->link) {
		if (strcmp(temp->data.sBookCode, "99999") == 0) {
			continue;
		}

		printf("%d : ", iBook_Index++);
		printf("%10s %10s %10s %10s\n", temp->data.sBookName, temp->data.sBookCode, temp->data.sAuthor, temp->data.sYear);
	}
	printf("\n");
}

void Search() {
	queuePointer temp = front;
	char SearchCode[CODESIZE];

	printf("�˻��� �����մϴ�.\n");
	printf("�˻��ϰ� ���� �����ڵ带 �Է��ϼ���. (��ü�˻�:0)");
	gets(SearchCode);

	if (strcmp(SearchCode, "0") == 0) {
		Print();
		return;
	}
	else if (strcmp(SearchCode, "99999") == 0) {
		printf("\n�߸��� �Է��Դϴ�.\n");
		return;
	}

	printf("\n\t������\t�����ڵ�\t����\t���ǳ⵵\n");
	printf("--------------------------------------------------\n");
	for (; temp; temp = temp->link) {
		if (strcmp(SearchCode, temp->data.sBookCode) == 0) {
			printf("1 : ");
			printf("%10s %10s %10s %10s\n\n", temp->data.sBookName, temp->data.sBookCode, temp->data.sAuthor, temp->data.sYear);
			break;
		}
	}
	if (temp == NULL) {
		printf("\n�ش� �����ڵ�� �������� �ʽ��ϴ�.\n");
		return;
	}
}

void Update() {
	queuePointer temp = front;
	char UpdateCode[CODESIZE];
	BookInfo UpdateBook;

	printf("������ �����մϴ�.\n");
	printf("�����ϰ� ���� �����ڵ带 �Է��ϼ���. ");
	gets(UpdateCode);

	if (strcmp(UpdateCode, "99999") == 0) {
		printf("\n�߸��� �Է��Դϴ�.\n");
		return;
	}

	printf("\n\t������\t�����ڵ�\t����\t���ǳ⵵\n");
	printf("--------------------------------------------------\n");
	for (; temp; temp = temp->link) {
		if (strcmp(UpdateCode, temp->data.sBookCode) == 0) {
			printf("1 : ");
			printf("%10s %10s %10s %10s\n\n", temp->data.sBookName, temp->data.sBookCode, temp->data.sAuthor, temp->data.sYear);
			break;
		}
	}

	if (temp == NULL) {
		printf("\n�ش� �����ڵ�� �������� �ʽ��ϴ�.\n");
		return;
	}

	printf("������ ������ �Է¹޽��ϴ�. (���������� ���ٸ� 0�� �Է�)\n\n");

	printf("������ : ");
	gets(UpdateBook.sBookName);
	if (strcmp(UpdateBook.sBookName, "0") == 1) {
		strcpy(temp->data.sBookName, UpdateBook.sBookName);
	}

	printf("�����ڵ� : ");
	gets(UpdateBook.sBookCode);
	if (strcmp(UpdateBook.sBookCode, "0") == 1) {
		strcpy(temp->data.sBookCode, UpdateBook.sBookCode);
	}

	printf("���ڸ� : ");
	gets(UpdateBook.sAuthor);
	if (strcmp(UpdateBook.sAuthor, "0") == 1) {
		strcpy(temp->data.sAuthor, UpdateBook.sAuthor);
	}

	printf("������ : ");
	gets(UpdateBook.sYear);
	if (strcmp(UpdateBook.sYear, "0") == 1) {
		strcpy(temp->data.sYear, UpdateBook.sYear);
	}

	printf("�����Ϸ�!\n");
}