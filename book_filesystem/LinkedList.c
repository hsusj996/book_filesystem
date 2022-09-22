#include "LinkedList.h"

void AddQueue(BookInfo Data) {		//링크드리스트 큐에 노드 삽입
	queuePointer temp;
	temp = malloc(sizeof(*temp));		//메모리 할당

	temp->data = Data;
	temp->link = NULL;
	if (front) {			//최초 삽입 x
		rear->link = temp;
	}
	else {					//최초 삽입
		front = temp;
	}
	rear = temp;
}