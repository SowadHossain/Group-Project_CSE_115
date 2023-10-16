#include<stdio.h>
#include<math.h>


#define MAX_USERS 10
#define NUMBER_OF_USERS
#
//game status structure
struct Game;
//use structure
struct Users;

//array of users
struct Users userArray[MAX_USERS];

int main(){
    printf("Envery thing seems ok");
}

struct Game{
    char word[10];
    char guessed_letters[10];
    int wrong_attempts;
    int attempts;
};

struct Users{
    char name[50];
    int id;
    int matches_played;
    int isGameSaved;
    int rank;
    struct Game saved_game;
};
