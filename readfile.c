#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fileptr;
	char *buffer;
	long filelen;

	fileptr = fopen("Resource/ref.jpg", "rb");
	fseek(fileptr, 0, SEEK_END);
	filelen = ftell(fileptr);
	rewind(fileptr);

	buffer = (char *)malloc((filelen+1)*sizeof(char));
	int file_size = fread(buffer, 1, filelen, fileptr);
	fclose(fileptr);

	char result[file_size];
	memset(result, '\0', file_size);
	printf("%d\n", file_size);
	for (int i = 0; i < file_size; i++)
	{
		// printf( "%hd", buffer[i]);
		result[i] = buffer[i];
	}
	printf("%lu", sizeof(buffer));
}
