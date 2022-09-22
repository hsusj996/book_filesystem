#include "LinkedList.h"

void AddQueue(BookInfo Data) {
	queuePointer temp;
	temp = malloc(sizeof(*temp));

	temp->data = Data;
	temp->link = NULL;
	if (front) {
		rear->link = temp;
	}
	else {
		front = temp;
	}
	rear = temp;
}