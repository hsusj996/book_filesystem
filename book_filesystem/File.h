#include "stdheaders.h"
#include "LinkedList.h"

#define BUFFER_SIZE 100
#define FILE_SIZE 128

enum FileOption {		//���� �ɼ�
	NO_FILE_OPTION, NEW_FILE, LOAD_FILE
};

int LoadFile(FILE* fd);

int SaveFile(char* FileName);


