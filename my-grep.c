#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    char *c;
    char n[2500];
    char *line = NULL;
    size_t len = 0;
    ssize_t k;

    // Checks in if  conditions are met
    if (argc == 1)
    {
        printf("my-grep: searchterm [file...]\n");
        exit(1);
    }
   // Reads from standard input if file  with no file
    else if (argc < 3)

    {

       if(strstr(fgets(n , 2500, stdin),argv[1]))
	{printf("%s",n);}
    }

    // Loop through the various files
    else{

	for (int i = 2; i <= argc-1 ; i++)
    {
        fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("my-grep:cannot open file\n");
            exit(1);
        }
        //Compares and prints out the line that matches with the item being searched
        while ((k = getline(&line, &len, fp)) != -1)
        {
            c = strstr(line, argv[1]);
            if (c != NULL)
            {
                printf("%s", line);
            }
	}
            fclose(fp);
        }
    }
}
