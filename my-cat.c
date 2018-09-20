#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

//Checks whether the argument are enough 
    if (argc < 2)
    {
        printf(" There is not enough argument\n");
        exit(0);
    }
//Loops through the files and read its content
    for (int i = 1; i <= argc - 1; i++)
	{
        FILE *fp;
	fp = fopen(argv[i], "r");

        if (fp == NULL)
        {
            printf("cannot open file\n");
            exit(0);
        }
//Gets the content read and prints it
	int c;
	do {

	c =  fgetc(fp);
	putchar(c);
	}
        while (c != EOF);
	fclose(fp);
    }

}


