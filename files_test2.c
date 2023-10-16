
//saves the word list

#include <stdio.h>
#include<string.h>

#define MAX_WORD 5

struct Word
{
    char word[10];
    char clue[100];

} ;/////words[MAX_WORD];

struct Word words2[MAX_WORD];
/*
void setWord(int i,char word_i[10],char clue_i[100]){
    strcpy(words[i].word , word_i);
    strcpy(words[i].clue ,clue_i);
}*/
void printWord(int i,struct Word wd){
    printf("%iWORD: %s\n",i,wd.word);
    printf("%iCLUE=%s\n",i,wd.clue);
    }

int main()
{
    FILE *file;
   /* file = fopen(".\\data_files\\words.dat", "w");

    setWord(1,"Mango","A sweet fruit");
    setWord(2,"MESsi","The goat");
    setWord(3,"Facebook","Social networking site");
    setWord(4,"Youtube","Largesh video streaming platform");

    printf("all ok");

    fwrite(words, sizeof(struct Word),MAX_WORD+1,file);
    fclose(file);
*/
    file = fopen(".\\data_files\\words.dat", "r");
    fread(words2,sizeof(struct Word),MAX_WORD+1,file);

    printWord(1,words2[1]);
    printWord(2,words2[2]);
    printWord(3,words2[3]);
    printWord(4,words2[4]);


    fclose(file);
}
