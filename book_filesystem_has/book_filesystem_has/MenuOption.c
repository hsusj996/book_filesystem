#include "MenuOption.h"

int Insert() {			//���� �Լ�
	BookInfo Input;
	printf("1. ����� ���� ������ �Է��ϼ���. \n");		//������ ������ �Է�

	printf("������ : ");
	gets(Input.sBookName);

	printf("�����ڵ� : ");
	gets(Input.sBookCode);

	printf("���ڸ� : ");
	gets(Input.sAuthor);

	printf("������ : ");
	gets(Input.sYear);

	if (Hash_Add(Input, atoi(Input.sBookCode)) == 0) {
		printf("\n���� : ��� ����!\n");
		return 0;
	}
	printf("\n��ϿϷ�!\n");
	return 1;
}

int Delete() {			//���� �Լ�
	char DeleteCode[CODE_SIZE];
	printf("2. �����ϰ� ���� �����ڵ带 �Է��ϼ���. ");

	gets(DeleteCode);

	if (Hash_Del(atoi(DeleteCode)) == 0) {
		printf("\n���� : ���� ����!\n");
		return 0;
	}
	printf("\n���� ����!\n");
	return 1;
}

void Print() {			//��ü ������� ���
	NodePointer temp;
	int iBook_Index = 0;

	printf("\n   %-20s %-10s %-15s %-10s\n", "������", "�����ڵ�", "����", "���ǳ⵵");
	printf("-----------------------------------------------------------------\n");

	for (int i = 0; i < BUCKET_SIZE; i++) {
		if (HashTable[i].count == 0) {		//���Ͽ� ��尡 ���ٸ� ��������
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

int Search() {				//�˻� �Լ�
	char SearchCode[CODE_SIZE];

	printf("�˻��� �����մϴ�.\n");
	printf("�˻��ϰ� ���� �����ڵ带 �Է��ϼ���. (��ü�˻�:0)");
	gets(SearchCode);

	if (strcmp(SearchCode, "0") == 0) {		//0 �Է� �� ��ü��� ���
		Print();
		return 1;
	}

	if (Hash_Search(atoi(SearchCode)) == 0) {
		printf("\n���� : �ش� ������ �������� �ʽ��ϴ�!\n");
		return 0;
	}
	return 1;
}

int Update() {			//���� �Լ�
	char UpdateCode[CODE_SIZE];
	BookInfo UpdateBook;
	char Buffer[BUFFER_SIZE];
	int iBefore_Code;

	printf("������ �����մϴ�.\n");
	printf("�����ϰ� ���� �����ڵ带 �Է��ϼ���. ");
	gets(UpdateCode);

	iBefore_Code = atoi(UpdateCode);		//������Ʈ�� �����ڵ带 ������ ��ȯ �� ����

	if (Hash_Search(iBefore_Code) == 0) {
		printf("\n���� : �ش� ������ �������� �ʽ��ϴ�!\n");
		return 0;
	}

	printf("������ ������ �Է¹޽��ϴ�. (���������� ���ٸ� 0�� �Է�)\n\n");

	printf("������ : ");		//���� ������ ���ʷ� �Է¹޾� temp����� �����Ϳ� ����
	gets(Buffer);		//0 �Է� �ÿ��� ���� x
	strcpy(UpdateBook.sBookName, Buffer);

	printf("�����ڵ� : ");
	gets(Buffer);		//0 �Է� �ÿ��� ���� x
	strcpy(UpdateBook.sBookCode, Buffer);

	printf("���ڸ� : ");
	gets(Buffer);		//0 �Է� �ÿ��� ���� x
	strcpy(UpdateBook.sAuthor, Buffer);

	printf("������ : ");
	gets(Buffer);
	strcpy(UpdateBook.sYear, Buffer);

	if (Hash_Update(UpdateBook, iBefore_Code) == 0) {
		printf("\n���� : ������Ʈ ����!\n");
		return 0;
	}
	printf("\n�����Ϸ�!\n");
	return 1;
}