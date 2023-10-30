#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>


#define MAX_WORD 5
#define MAX_USERS 10
#define GUESSES 7
#define CURRENT_USER

int NUMBER_OF_USERS=0;
char DASHES[10];
int Strike=0;
int CorrectGusses=0;
//game status structure
typedef struct {
    char word[10];
    char guessed_letters[10];
    int wrong_attempts;
    int attempts;
} Game;
//user structure
typedef struct {
    char name[50];
    int id;
    int matches_played;
    int scores;
    int isGameSaved;
    int rank;
    //struct Game saved_game;
} User;
//word structure
typedef struct{
    char word[10];
    char clue[100];

}Word;
//data loading functions
void loadWords();
void loadUsers();
void loadLeaderboard();
//data saving functions

void saveUsers();
void saveLeaderboard();

//functions
void clearscr()				//A function to clear the terminal/cmd window.
{
    system("@cls||clear");
}
void AddUsers();
void EditUser();
void displayLeaderboard(User leaderboard[], int size);
void updateLeaderboard(User leaderboard[], int size, const char *name, int score);
void About();
void exit();
int MainMenu();
void getUser();
void setUser();
void drawHangman(int strike);
void drawTitle();
void drawgameOver();
void drawYouWon();
void game();

//////////////////////////////////
void printWord(int i,Word wd){
    printf("%iWORD: %s\n",i,wd.word);
    printf("%iCLUE=%s\n",i,wd.clue);
    }

void printUser(int i,User usrArr[]){
    printf("\nName: %s",usrArr[i-1].name);
    printf("\nID: %i",usrArr[i-1].id);
}

///////////////////////////////////////////////ARRAYS//////////////////////////////

//array of users
User userArray[MAX_USERS];
//array of words
Word wordList[MAX_WORD];
//Leaderboard array
User Leaderboard[MAX_USERS];

///////////////////////////////////////////////MAIN FUNCTION////////////////////////
int main(){
    printf("Envery thing seems ok\n");
    loadUsers();
    loadWords();
    game();
    printf("After the funcion");
}

//data loading function definations
//function written by SOWAD
void loadWords(){
    FILE *file;
    file = fopen(".\\data_files\\words.dat", "r");
    int fread_result = fread(wordList,sizeof(Word),MAX_WORD,file);

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
    int fread_result = fread(userArray, sizeof(User),MAX_USERS,file);
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
        printf("Number %d. %s: %d\n", i + 1, leaderboard[i].name, leaderboard[i].scores);
    }
}
//function written by AHNAF
void updateLeaderboard(User leaderboard[], int size, const char *name, int score)
{
    for (int i = 0; i < size; i++)
    {
        if (score > leaderboard[i].scores)
        {

            for (int j = size - 1; j > i; j--)
            {
                strcpy(leaderboard[j].name, leaderboard[j - 1].name);
                leaderboard[j].scores = leaderboard[j - 1].scores;
            }

            strcpy(leaderboard[i].name, name);
            leaderboard[i].scores = score;
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

//game
void game(){
    int tempchar;
    int letter_exist=0;
    Word chosen;
    char chosen_word[20],chosen_wordHint[100];
    srand(time(NULL));
    int word_index = (rand() % (MAX_WORD - 1));
    chosen = wordList[word_index];
    strcpy(chosen_word,chosen.word);
    strcpy(chosen_wordHint,chosen.clue);
    int word_lenth = strlen(chosen_word);

    for(int i =0;i<word_lenth;i++)
        DASHES[i]='*';

    DASHES[word_lenth]='\0';

    while(1){
        //clearscr();//un-comment this line 
        drawTitle();
        printf("\n gussed letter\nletter Exist= %i,\ncorrect gusse = %i\n",letter_exist,CorrectGusses);//for testing

        if(CorrectGusses==word_lenth){
            printf("\nTHE WORD WAS:%s\n\n",chosen_word);
            void drawYouWon();
            break;
        }

        drawHangman(Strike);

        if(Strike == GUESSES){
            printf("\nTHE WORD WAS:%s\n\n",chosen_word);
            drawgameOver();
            break;
        }

        printf("\n\nGUESS THE WORD:%s",DASHES);
        printf("\n\nHINT:%s",chosen_wordHint);
        printf("\n~Enter '*' to save and return to main menu\n");
    //taking input form the user
        printf("\n\nGuess a letter: ");
        scanf("%c",&tempchar);

        if(tempchar=='*'){

            break;
        }

    for(int i =0;i<word_lenth;i++){
        if(chosen_word[i]==tempchar){
            DASHES[i]=tempchar;
            letter_exist+=1;
            CorrectGusses+=1;
            printf("\n ????????\n\\\ngussed letter\nletter Exist= %i,\ncorrect gusse = %i\n",letter_exist,CorrectGusses);//for testing
        }
    }
    if(letter_exist==0){
        Strike++;
        printf("\n strike %i",Strike);//for testing

    }
    letter_exist =0;
    }
}

//draw function
void drawHangman(int strike){
    //clearscr();//un-comment this line 
    switch (strike)
    {
    case 1:
        printf("  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========");
        break;
    case 2:
        printf("  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========");
        break;
    case 3:
        printf( "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========");
        break;
    case 4:
        printf("  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n========="    );
        break;
    case 5:
        printf("  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========");
        break;
    case 6:
        printf("  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========");
        break;
    case 7:
        printf("  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========");
        break;
    }
}

void drawTitle(){
    printf(" _                                             \n");
    printf("| |                                            \n");
    printf("| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
    printf("| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
    printf("| | | | (_| | | | | (_| | | | | | | (_| | | | | \n");
    printf("|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
    printf("                    __/ |                      \n");
    printf("                   |___/  \n");
}


void drawgameOver(){
printf(" _______  _______  _______  _______    _______           _______  _______ \n");
printf("(  ____ \\(  ___  )(       )(  ____ \\  (  ___  )|\\     /|(  ____ \\(  ____ )\n");
printf("| (    \\/| (   ) || () () || (    \\/  | (   ) || )   ( || (    \\/| (    )|\n");
printf("| |      | (___) || || || || (__      | |   | || |   | || (__    | (____)|\n");
printf("| | ____ |  ___  || |(_)| ||  __)     | |   | |( (   ) )|  __)   |     __)\n");
printf("| | \\_  )| (   ) || |   | || (        | |   | | \\ \\_/ / | (      | (\\ (\n");
printf("| (___) || )   ( || )   ( || (____/\\  | (___) |  \\   /  | (____/\\| ) \\ \\__\n");
printf("(_______)|/     \\||/     \\|(_______/  (_______)   \\_/   (_______/|/   \\__/\n");
}

void drawYouWon(){
printf("");
printf("                                                                       __  __\n");
printf("                                                                      /  |/  |\n");
printf(" __    __   ______   __    __        __   __   __   ______   _______  $$ |$$ |\n");
printf("/  |  /  | /      \\ /  |  /  |      /  | /  | /  | /      \\ /       \\ $$ |$$ |\n");
printf("$$ |  $$ |/$$$$$$  |$$ |  $$ |      $$ | $$ | $$ |/$$$$$$  |$$$$$$$  |$$ |$$ |\n");
printf("$$ |  $$ |$$ |  $$ |$$ |  $$ |      $$ | $$ | $$ |$$ |  $$ |$$ |  $$ |$$/ $$/\n");
printf("$$ \\__$$ |$$ \\__$$ |$$ \\__$$ |      $$ \\_$$ \\_$$ |$$ \\__$$ |$$ |  $$ | __  __\n");
printf("$$    $$ |$$    $$/ $$    $$/       $$   $$   $$/ $$    $$/ $$ |  $$ |/  |/  |\n");
printf(" $$$$$$$ | $$$$$$/   $$$$$$/         $$$$$/$$$$/   $$$$$$/  $$/   $$/ $$/ $$/\n");
printf("/  \\__$$ |\n");
printf("$$    $$/\n");
printf(" $$$$$$/\n");
}
//data saving functions

void saveUsers(){}
void saveLeaderboard(){
//    printf("afsd");
}
