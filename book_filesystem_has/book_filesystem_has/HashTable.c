#include "HashTable.h"

int Hash_func(int key) {		//�ؽ� �Լ�, Ű ���� ����ũ���� ������ ����
	return key % BUCKET_SIZE;	//(1 ~~ BUCKET_SIZE -1)
}

NodePointer createNode(BookInfo data, int key) {		//�ؽ����̺� ��� ����
	NodePointer newNode;
	newNode = (NodePointer)malloc(sizeof(struct node));
	newNode->key = key;
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

int Hash_Add(BookInfo data, int key) {		//�ؽ����̺� ����

	int iHash_Index = Hash_func(key);

	NodePointer newNode = createNode(data, key);

	if (HashTable[iHash_Index].count == 0) {		//���Ͽ� ���� ����
		HashTable[iHash_Index].count = 1;
		HashTable[iHash_Index].head = newNode;
		return 1;
	}
	else {												//���� ������ �ƴ� ���
		newNode->next = HashTable[iHash_Index].head;	//���� head�� ����
		HashTable[iHash_Index].head = newNode;			//���� ���� �� ����� next��
		HashTable[iHash_Index].count++;	
		return 1;
	}
	return 0;			//���� �� 0��ȯ
}
	
int Hash_Del(int key) {		//�ؽ����̺� ����
	int iHash_Index = Hash_func(key);
	NodePointer Before_Node = NULL;			//������ ����� ���� ���
	NodePointer temp = NULL;
	temp = HashTable[iHash_Index].head;		//head���� Ž��

	for (; temp; temp = temp->next) {
		if (temp->key == key) {
			if (HashTable[iHash_Index].head == temp) {			//temp�� ������ ù��° ����� ���
				HashTable[iHash_Index].head = temp->next;
			}
			else {			//temp �ι�° �̻� ����� ���
				Before_Node->next = temp->next;
			}
			HashTable[iHash_Index].count--;
			free(temp);
			return 1;
		}
		Before_Node = temp;			//���� ��� Ž���� ���� �����带 before�� ����
	}
	return 0;
}

int Hash_Search(int key) {		//�ؽ����̺� Ž��
	int iHash_Index = Hash_func(key);
	NodePointer temp = NULL;
	temp = HashTable[iHash_Index].head;


	for (; temp; temp = temp->next) {
		if (temp->key == key) {		//Ű ���� �����ϴٸ� ���
			printf("\n   %-20s %-10s %-15s %-10s\n", "������", "�����ڵ�", "����", "���ǳ⵵");
			printf("-----------------------------------------------------------------\n");
			printf("1 : ");
			printf("%-20s %-10s %-15s %-10s\n\n", 
					temp->data.sBookName, temp->data.sBookCode, temp->data.sAuthor, temp->data.sYear);
			return 1;
		}
	}
	return 0;		//Ž�� ���� �� 0 ��ȯ
}


int Hash_Update(BookInfo data, int key) {		//�ؽ����̺�  ������Ʈ
	if (Hash_Del(key) == 0) {		//Ű ���� �ش�Ǵ� ��� ����
		return 0;
	}
	if (Hash_Add(data, atoi(data.sBookCode)) == 0) {		//���ο� Ű ��, �����ͷ� ���Ӱ� ��� ���� �� ����
		return 0;
	}
	return 1;
}

