#ifndef IO_H_
#define IO_H_

#define CHUNK_SIZE 4096

char *ReadFileToBuffer(const char *filename, bool isStdin, long *size);

#endif // IO_H_
