#include<stdio.h>
#include<math.h>
#include<string.h>


#define MAX_WORD 5
#define MAX_USERS 10
int NUMBER_OF_USERS=0;
#define GUESSES 6
#define CURRENT_USER
//game status structure
struct Game{
    char word[10];
    char guessed_letters[10];
    int wrong_attempts;
    int attempts;
};
//user structure
struct User{
    char name[50];
    int id;
    int matches_played;
    int isGameSaved;
    int rank;
    struct Game saved_game;
};
//word structure
struct Word
{
    char word[10];
    char clue[100];

};
//data loading functions
void loadWords();
void loadUsers();
void loadLeaderboard();
//data saving functions

void saveUsers();
void saveLeaderboard();

//functions
void AddUsers();
void EditUser();
void ShowLeaderboard();
void About();
void exit();
int MainMenu();
void getUser();
void setUser();


//////////////////////////////////
void printWord(int i,struct Word wd){
    printf("%iWORD: %s\n",i,wd.word);
    printf("%iCLUE=%s\n",i,wd.clue);
    }

void printUser(int i,struct User usrArr[]){
    printf("\nName: %s",usrArr[i-1].name);
    printf("\nID: %i",usrArr[i-1].id);
}

/////////////////////////////////

//array of users
struct User userArray[MAX_USERS];
struct Word wordList[MAX_WORD];

int main(){
    printf("Envery thing seems ok\n");
    loadUsers();
    loadWords();
    printf("After the funcion");


}

//data loading function definations
void loadWords(){
    FILE *file;
    file = fopen(".\\data_files\\words.dat", "r");
    int fread_result = fread(wordList,sizeof(struct Word),MAX_WORD,file);

    if(fread_result==MAX_WORD)
        printf("\nWords copied succesfully\n");
    else
        printf("\nerror copying word file\n");
    printWord(1,wordList[1]);
    printWord(2,wordList[2]);
    printWord(3,wordList[3]);
    fclose(file);
}

void loadUsers(){
    FILE *file1;
    file1 = fopen(".\\data_files\\users_data.dat", "r");
                            //wordList,sizeof(struct Word),MAX_WORD,file
    int fread_result = fread(userArray,sizeof(struct User),MAX_USERS,file1);
    printf("\n/////////////////////////////////////////////");
    if(fread_result==MAX_USERS)
        printf("\nUSERS copied succesfully\nfread returns %d\n",fread_result);
    else
        printf("\nerror copying users file\nfread returns %d\n",fread_result);

    printUser(1,userArray);
    printUser(2,userArray);
    printUser(2,userArray);
    printUser(1,userArray);
    fclose(file1);
}
void loadLeaderboard();

//data saving functions

void saveUsers();
void saveLeaderboard();
