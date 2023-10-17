#include <stdio.h>

int main()
{
    int i, n;

    printf("Main Menu\n");
    printf("1.New Game:\n");
    printf("2.Resume Game:\n");
    printf("3.Leader board:\n");
    printf("4.Edit Username:\n");
    printf("5.About:\n");
    printf("6.Exit:\n");

    do
    {
        printf("\nChose an option: ");
        scanf("%d", &n);
    } while (n < 1 || n > 6);
    return n;
}
int newgame()
{
    char str[20], i;
    printf("Username:");
    scanf("%s", str);
    char Names[4][20] = {"Messi", "Neymar", "Suarez"};
    for (i = 0; i < 4; i++)
    {
        int d = strcmp(str, Names[i]);
        if (d == 0)
        {
            printf("Valid Username");
        }
        else
        {
            printf("Invalid Username:");
        }
    }
}
