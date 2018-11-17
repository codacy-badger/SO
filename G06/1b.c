#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 80 /* or other suitable maximum line size */


int main(int argc, char *argv[])
{
    int i;
    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 

    /* Validate number of arguments */
    if(argc < 2)
    {
        printf("USAGE: %s fileName\n", argv[i]);
        return EXIT_FAILURE;
    }
    
    /* Open the file provided as argument */
    
    for (i=1; i<argc ; i++){
        errno = 0;
        fp = fopen(argv[i], "r");
        if(fp == NULL)
        {
            perror ("Error opening file!");
            return EXIT_FAILURE;
        }
        int linhas = 1;
        /* read all the lines of the file */
        while(fgets(line, sizeof(line), fp) != NULL )
            {
            printf("%d-> %s",linhas, line);
            linhas ++;
            }
        //printf("Numero de linhas: %d\n",linhas);    
        printf("\n------------------------------------\n");
    }       
    fclose (fp);

    return EXIT_SUCCESS;
}