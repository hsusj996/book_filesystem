#include "HashTable.h"

int Hash_func(int key) {		//해시 함수, 키 값을 버켓크기의 나머지 연산
	return key % BUCKET_SIZE;	//(1 ~~ BUCKET_SIZE -1)
}

NodePointer createNode(BookInfo data, int key) {		//해시테이블 노드 생성
	NodePointer newNode;
	newNode = (NodePointer)malloc(sizeof(struct node));
	newNode->key = key;
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

int Hash_Add(BookInfo data, int key) {		//해시테이블 삽입

	int iHash_Index = Hash_func(key);

	NodePointer newNode = createNode(data, key);

	if (HashTable[iHash_Index].count == 0) {		//버켓에 최초 삽입
		HashTable[iHash_Index].count = 1;
		HashTable[iHash_Index].head = newNode;
		return 1;
	}
	else {												//최초 삽입이 아닌 경우
		newNode->next = HashTable[iHash_Index].head;	//버켓 head에 삽입
		HashTable[iHash_Index].head = newNode;			//기존 노드는 새 노드의 next로
		HashTable[iHash_Index].count++;	
		return 1;
	}
	return 0;			//실패 시 0반환
}
	
int Hash_Del(int key) {		//해시테이블 삭제
	int iHash_Index = Hash_func(key);
	NodePointer Before_Node = NULL;			//삭제할 노드의 이전 노드
	NodePointer temp = NULL;
	temp = HashTable[iHash_Index].head;		//head부터 탐색

	for (; temp; temp = temp->next) {
		if (temp->key == key) {
			if (HashTable[iHash_Index].head == temp) {			//temp가 버켓의 첫번째 노드인 경우
				HashTable[iHash_Index].head = temp->next;
			}
			else {			//temp 두번째 이상 노드인 경우
				Before_Node->next = temp->next;
			}
			HashTable[iHash_Index].count--;
			free(temp);
			return 1;
		}
		Before_Node = temp;			//다음 노드 탐색을 위해 현재노드를 before에 저장
	}
	return 0;
}

int Hash_Search(int key) {		//해시테이블 탐색
	int iHash_Index = Hash_func(key);
	NodePointer temp = NULL;
	temp = HashTable[iHash_Index].head;


	for (; temp; temp = temp->next) {
		if (temp->key == key) {		//키 값이 동일하다면 출력
			printf("\n   %-20s %-10s %-15s %-10s\n", "도서명", "도서코드", "저자", "출판년도");
			printf("-----------------------------------------------------------------\n");
			printf("1 : ");
			printf("%-20s %-10s %-15s %-10s\n\n", 
					temp->data.sBookName, temp->data.sBookCode, temp->data.sAuthor, temp->data.sYear);
			return 1;
		}
	}
	return 0;		//탐색 실패 시 0 반환
}


int Hash_Update(BookInfo data, int key) {		//해시테이블  업데이트
	if (Hash_Del(key) == 0) {		//키 값에 해당되는 노드 삭제
		return 0;
	}
	if (Hash_Add(data, atoi(data.sBookCode)) == 0) {		//새로운 키 값, 데이터로 새롭게 노드 생성 후 저장
		return 0;
	}
	return 1;
}

