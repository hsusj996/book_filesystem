#include "LinkedList.h"

void AddQueue(BookInfo Data) {		//��ũ�帮��Ʈ ť�� ��� ����
	queuePointer temp;
	temp = malloc(sizeof(*temp));		//�޸� �Ҵ�

	temp->data = Data;
	temp->link = NULL;
	if (front) {			//���� ���� x
		rear->link = temp;
	}
	else {					//���� ����
		front = temp;
	}
	rear = temp;
}