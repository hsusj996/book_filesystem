#include "stdheaders.h"
#include "LinkedList.h"

#define BUFFER_SIZE 100
#define FILE_SIZE 128

enum FileOption {
	NO_FILE_OPTION, NEW_FILE, LOAD_FILE
};
enum MenuOption {
	NO_MENU_OPTION, INSERT, DEL, UPDATE, SEARCH, EXIT
};

int LoadFile(FILE* fd);

int SaveFile(char* FileName);


