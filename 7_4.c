#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'
#define SLEN 81

int main()
{
	char file[SLEN];
	char ch;
	FILE* fp;
	long count, last;

	puts("Enter the name of the file to be processed:");
	scanf("%80s", file);
	if((fp = fopen(file, "r")) == NULL)
	{
		printf("reverse can't open %s\n", file);
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0L, SEEK_END);//定位至文件结尾
	last = ftell(fp);
	for(count = 1L; count <= last; count++)
	{
		fseek(fp, -count, SEEK_END);//从文件结尾处回退10个字节
		ch = getc(fp);
		if(ch != CNTL_Z && ch != '\r')
			putchar(ch);
	}
	putchar('\n');
	fclose(fp);

	return 0;
}