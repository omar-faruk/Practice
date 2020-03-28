#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
/* calculate filesize */
int calc_bufsize(char *filename)
{
struct stat st;
stat(filename, &st);
return ((int)st.st_size);
}

int main(int argc, char *argv[])
{
if(argc < 3)
{
printf("Usage:\n\t%s <word> <files> ...\n", argv[0]);
return -1;
}
FILE *fp;
char *filename;
int x = 2;
/* process each file */
for(x; x != argc; x++)
{
filename = argv[x];
if( (fp = fopen(filename, "r")) == NULL)
{
printf("Failed to open file: %s\n", argv[2]);
return -2;
}int BUFSIZE = calc_bufsize(filename);
/* read ENTIRE file into buf[] */
char buf[BUFSIZE];
fread(&buf, sizeof(char), BUFSIZE, fp);
/* search buf for word (case sensitive) */
char *ans = strstr(buf, argv[1]);
/* word found, print filename */
if(ans != NULL)
printf("Found the pattern in the file :%s\n", filename);
else 
	printf("Not Found!!\n");
/* word not found, do nothing */
fclose(fp);
}
return 0;
}
