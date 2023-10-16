typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void displayLeaderboard(Player leaderboard[], int size)
{
    printf("===== LEADERBOARD =====\n");
    for (int i = 0; i < size; i++)
    {
        printf("Number %d. %s: %d\n", i + 1, leaderboard[i].name, leaderboard[i].score);
    }
}

void updateLeaderboard(Player leaderboard[], int size, const char *name, int score)
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
