#include <stdio.h>
#include<string.h>

#define MAX_WORD 5
#define MAX_USERS 10
int NUMBER_OF_USERS = 0;
typedef struct{
    char word[10];
    char clue[100];

}Word;
typedef struct {
    Word word;
    char guessed_letters[10];
    int wrong_attempts;
} Game;

struct Users{
    char name[50];
    int id;
    int matches_played;
    int scores;
    int isGameSaved;
    int rank;
    Game saved_game;
};



struct Users userArray2[MAX_USERS];
struct Users userArray[MAX_USERS];


void setUser(int i,
    char name[50],
    int matches_played,
    int isGameSaved,
    int rank){
        --i;
        strcpy(userArray2[i].name,name);
        userArray2[i].id = ++NUMBER_OF_USERS;
        userArray2[i].matches_played = matches_played;
        userArray2[i].isGameSaved = isGameSaved;
        userArray2[i].rank = rank;
    }

void printUser(int i,struct Users usrArr[]){
    printf("\nName: %s",usrArr[i-1].name);
    printf("\nID: %i",usrArr[i-1].id);
}

int main()
{
   FILE *file;
     file = fopen(".\\data_files\\users_data.dat", "w");

    setUser(1,"dihan",NUMBER_OF_USERS,0,0);
    setUser(2,"abcd",NUMBER_OF_USERS,0,0);
    setUser(3,"ahad",NUMBER_OF_USERS,0,0);
    setUser(4,"p3",NUMBER_OF_USERS,0,0);
    setUser(5,"p4",NUMBER_OF_USERS,0,0);

    fwrite(userArray2, sizeof(struct Users),MAX_USERS,file);

    fclose(file);

    file = fopen(".\\data_files\\users_data.dat", "r");
    int fread_result = fread(userArray, sizeof(struct Users),MAX_USERS,file);
    if(fread_result==MAX_USERS)
        printf("\nUSERS copied succesfully\n");
    else
        printf("\nerror copying users file\n");
    printUser(1,userArray);
    printUser(2,userArray);
    printUser(3,userArray);
    printUser(4,userArray);
    printUser(5,userArray);
    fclose(file);
}
