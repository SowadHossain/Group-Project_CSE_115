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
    int scores;
    int isGameSaved;
    int rank;
    //struct Game saved_game;
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
void displayLeaderboard(User leaderboard[], int size);
void updateLeaderboard(User leaderboard[], int size, const char *name, int score);
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

///////////////////////////////////////////////ARRAYS//////////////////////////////

//array of users
struct User userArray[MAX_USERS];
//array of words
struct Word wordList[MAX_WORD];
//Leaderboard array
struct User Leaderboard[MAX_USERS];

///////////////////////////////////////////////MAIN FUNCTION////////////////////////
int main(){
    printf("Envery thing seems ok\n");
    loadUsers();
    loadWords();
    printf("After the funcion");


}

//data loading function definations
//function written by SOWAD
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
//function written by SOWAD
void loadUsers(){
    FILE *file;
    file = fopen(".\\data_files\\users_data.dat", "r");
    int fread_result = fread(userArray, sizeof(struct User),MAX_USERS,file);
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
//function written by AHNAF 
void displayLeaderboard(User leaderboard[], int size)
{
    printf("===== LEADERBOARD =====\n");
    for (int i = 0; i < size; i++)
    {
        printf("Number %d. %s: %d\n", i + 1, leaderboard[i].name, leaderboard[i].score);
    }
}
//function written by AHNAF
void updateLeaderboard(User leaderboard[], int size, const char *name, int score)
{
    for (int i = 0; i < size; i++)
    {
        if (score > leaderboard[i].score)
        {

            for (int j = size - 1; j > i; j--)
            {
                strcpy(leaderboard[j].name, leaderboard[j - 1].name);
                leaderboard[j].score = leaderboard[j - 1].score;
            }

            strcpy(leaderboard[i].name, name);
            leaderboard[i].score = score;
            break;
        }
    }
}
//function written by FARHAN
int mainMenu(){
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
//function written by FARHAN
int newgame()
{
    char str[20], i;
    printf("Username:");
    scanf("%s", str);
    for (i = 0; i < 4; i++)
    {
        int d = strcmp(str, userArray[i].name);
        if (d == 0)
        {
            printf("\nValid Username");
            return 0;
        }
    }
    printf("\nInvalid Username:");
    return 1;
}

//data saving functions

void saveUsers();
void saveLeaderboard();
