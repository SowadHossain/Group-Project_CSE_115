#include<stdio.h>
int main()
{
    FILE *file;
    char c;

    file = fopen("about.txt","r");


    if(file == NULL)
    {
        printf("Error in opening file");
        return(-1);
    }
    while(1)
    {
        c = fgetc(file);
        if( feof(file) )
            break;
        printf("%c", c);
    }
    fclose(file);
}



