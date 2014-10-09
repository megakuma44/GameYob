#pragma once
#include <dirent.h>

#define MAX_FILENAME_LEN 256

struct FileHandle;

#ifdef C_IO_FUNCTIONS
#define DirStruct DIR
#else
struct DirStruct;
#endif

void        fs_init();
FileHandle* file_open(const char*, const char*);    // Returns NULL if error occurs
void        file_close(FileHandle*);
void        file_read(void*, int, int, FileHandle*);
void        file_write(const void*, int, int, FileHandle*);
void        file_gets(char*, int, FileHandle*);
void        file_putc(char, FileHandle*);

int         file_tell(FileHandle*);
void        file_seek(FileHandle*, int, int);
int         file_getSize(FileHandle*);

void        file_printf(FileHandle*, const char*, ...);

bool        file_exists(const char* filename);


DirStruct*  fs_opendir(const char*);
void        fs_closedir(DirStruct*);
struct dirent* fs_readdir(DirStruct*);

void        fs_getcwd(char*, size_t);
void        fs_chdir(const char*);
