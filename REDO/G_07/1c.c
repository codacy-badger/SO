#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    Person p;

    /* Validate number of arguments */
    if (argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        perror("Error opening file!");
        return EXIT_FAILURE;
    }

    /* read all the itens of the file */
    while (fread(&p, sizeof(Person), 1, fp) == 1)
    {
        printPersonInfo(&p);
    }
    
    int num_pessoas;
    printf("Num pessoas? ");
    scanf("%d", &num_pessoas);
    int age;
    float height;
    char name[64];
    /* Write 10 itens on a file */
    for (int i = 0; i < num_pessoas; i++)
    {
        printf("Name? ");
        scanf(" %[^\n]", p.name);
        printf("Age? ");
        scanf("%d", &p.age);
        printf("Height? ");
        scanf("%le", &p.height);
        printf("\n---------\n");
        fwrite(&p, sizeof(Person), 1, fp);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
