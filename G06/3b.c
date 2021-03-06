#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man system
 man date
*/

int main(int argc, char *argv[])
{
    char text[128];
    FILE *fp = fopen("command.log", "w");
    do
    {
        printf("Command: ");
        scanf("%[^\n]%*c", text);

        /* system(const char *command) executes a command specified in command
            by calling /bin/sh -c command, and returns after the command has been
            completed.
        */
        if(strcmp(text, "end")) {
           fprintf(fp,"\n * Command to be executed: %s\n", text);
           fprintf(fp,"---------------------------------\n");
           fprintf(fp, "Date: | Command: %s \n" ,text);                     //POR AQUI A DATA

           fprintf(fp, "---------------------------------\n");
        }
    } while(strcmp(text, "end"));

    fprintf(fp, "-----------The End---------------\n");
    fclose(fp);
    return EXIT_SUCCESS;
}
