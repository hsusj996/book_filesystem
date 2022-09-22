#include "stdheaders.h"
#include "LinkedList.h"
#include "MenuOption.h"
#include "File.h"

void Init(char FileName[]) {
	int iFileOption;
	FILE* fd;

	printf("������� ���Ͻý��� ���α׷��Դϴ�.\n");
	printf("1. ���� �����, 2. �ҷ�����, 3. ���� => ");
	scanf_s("%d", &iFileOption);
	getchar();

	if (iFileOption == NEW_FILE) {
		printf("���� ���� ���ϸ��� �Է����ּ���. : ");
		gets(FileName);
		if ((fd = fopen(FileName, "w")) == NULL) {
			printf("���� : ������ �� �� �����ϴ�. \n");
			return;
		}
	}

	else if (iFileOption == LOAD_FILE) {
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
				if (LoadFile(fd) == -1) {
					printf("�ҷ����� ����\n");
					continue;
				}
				else {
					printf("�ҷ����� ����! \n");
					break;
				}
			}
		}
	}

	else {
		printf("�����մϴ�. \n");
		return;
	}

	fclose(fd);
	return;
}

void Run(char FileName[]) {
	int iMenuOption;

	while (true) {
		printf("1: ����, 2: ����, 3: ����, 4: �˻�, 5: ���� => ");
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
				printf("���强��!\n");
			}
			else {
				printf("�������!\n");
			}
			printf("�����մϴ�.\n");
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
