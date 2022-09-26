#include "stdheaders.h"			//std������� ����
#include "HashTable.h"			//�ؽ����̺� ���
#include "MenuOption.h"			//�޴��ɼ� ���
#include "File.h"				//���Ͽɼ� ���

#define BUFFER_SIZE 100
#define FILE_SIZE 128

enum FileOption {		//���� �ɼ�
	NO_FILE_OPTION, NEW_FILE, LOAD_FILE
};

enum MenuOption {		//�޴� �ɼ�
	NO_MENU_OPTION, INSERT, DEL, UPDATE, SEARCH, EXIT
};

void Init(char FileName[]) {
	int iFileOption;
	FILE* fd;

	printf("������� ���Ͻý��� ���α׷��Դϴ�.\n");
	printf("1. ���� �����, 2. �ҷ�����, 3. ���� => ");
	scanf_s("%d", &iFileOption);
	getchar();

	if (iFileOption == NEW_FILE) {			//�� ���� ����
		printf("���� ���� ���ϸ��� �Է����ּ���. : ");
		gets(FileName);
		if ((fd = fopen(FileName, "w")) == NULL) {
			printf("���� : ������ �� �� �����ϴ�. \n");
			return;
		}
	}
	else if (iFileOption == LOAD_FILE) {	//���� ���� �ε�
		while (true) {
			printf("�ҷ��� ���ϸ��� �Է����ּ���.(Q �Է� �� ����) : ");
			gets(FileName);

			if (FileName[0] == 'Q' || FileName[0] == 'q') {
				printf("�����մϴ�. \n");
				return 0;
			}

			if ((fd = fopen(FileName, "r")) == NULL) {
				printf("���� : �ش� ������ �������� �ʽ��ϴ�. �ٽ� �Է����ּ���. \n");
			}
			else {
				if (LoadFile(fd) == 0) {			//���Ϸε� ����, ���� �� 0 ��ȯ
					printf("\n�ҷ����� ����\n");
					continue;
				}
				else {
					printf("\n�ҷ����� ����! \n");
					break;
				}
			}
		}
	}

	else {
		printf("\n�����մϴ�.\n");
		return;
	}

	fclose(fd);
	return;
}

void Run(char FileName[]) {		//���� ����
	int iMenuOption;		//�޴� �ɼ� ����

	while (true) {
		printf("1: ����, 2: ����, 3: ����, 4: �˻�, 5: ���� => ");
		scanf_s("%d", &iMenuOption);
		getchar();

		switch (iMenuOption) {
		case INSERT:	//����
			Insert();
			break;
		case DEL:		//����
			Delete();
			break;
		case UPDATE:	//����
			Update();
			break;
		case SEARCH:	//�˻�
			Search();
			break;
		default:		//���� �� ����
			if (SaveFile(FileName) == 1) {
				printf("\n���强��!\n");
			}
			else {
				printf("\n�������!\n");
			}
			printf("\n�����մϴ�.\n");
			system("pause");
			return;
		}
		system("pause");
		system("cls");
	}
	return;
}

int main() {
	HashTable = (Bucket*)malloc(BUCKET_SIZE * sizeof(Bucket));		//HashTable.h�� ����� �ؽ����̺� �޸��Ҵ�

	for (int i = 0; i < BUCKET_SIZE; i++) {			//�ؽ����̺� �ʱ�ȭ
		HashTable[i].count = 0;
		HashTable[i].head = NULL;
	}

	char FileName[FILE_SIZE];
	Init(FileName);				//���� �ɼ�

	system("pause");
	system("cls");

	Run(FileName);				//���� ����

	return 0;
}