#include <stdio.h>
#include<string.h>

#define MAX_WORD 5
#define MAX_USERS 10
int NUMBER_OF_USERS = 0;
struct Users{
    char name[50];
    int id;
    int matches_played;
    int isGameSaved;
    int rank;
    //struct Game saved_game;
};
struct Users userArray[MAX_USERS];
struct Users userArray2[MAX_USERS];

/*
void setWord(int i,char word_i[10],char clue_i[100]){
    strcpy(words[i].word , word_i);
    strcpy(words[i].clue ,clue_i);
}*/

void setUser(int i,
    char name[50],
    int id,
    int matches_played,
    int isGameSaved,
    int rank){
        --i;
        strcpy(userArray[i].name,name);
        userArray[i].id = ++NUMBER_OF_USERS;
        userArray[i].matches_played = matches_played;
        userArray[i].isGameSaved = isGameSaved;
        userArray[i].rank = rank;

    }

void printUser(int i,struct Users usrArr[]){
    printf("\nName: %s",usrArr[i-1].name);
    printf("\nID: %i",usrArr[i-1].id);
}

int main()
{
    FILE *file;
    file = fopen(".\\data_files\\users.dat", "w");

    setUser(1,"sowad",NUMBER_OF_USERS,0,0,0);
    setUser(2,"abcd",NUMBER_OF_USERS,0,0,0);
    setUser(3,"ahad",NUMBER_OF_USERS,0,0,0);
    setUser(4,"p3",NUMBER_OF_USERS,0,0,0);
    setUser(5,"p4",NUMBER_OF_USERS,0,0,0);

    fwrite(userArray, sizeof(struct Users),MAX_USERS+1,file);

    fclose(file);

    file = fopen(".\\data_files\\users.dat", "r");
    fread(userArray2, sizeof(struct Users),MAX_USERS+1,file);
    printUser(1,userArray2);
    printUser(2,userArray2);
    printUser(3,userArray2);
    printUser(4,userArray2);
    printUser(5,userArray2);
    fclose(file);
}
