#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/* Pick a random player */
void randomPlayer(char* player, FILE* archive, int archDim)
{
    fseek(archive, 0, 0);
    int index = rand() % archDim;
    for(int i = 0; i<index; i++)
    {
        fgets(player, 100, archive);
    }
    fgets(player, 100, archive);
}

int main()
{
    srand(time(NULL));
    /* Open txt files */
    FILE *gks, *dfs, *mfs, *fws, *cos, *mgs;
    gks = fopen("GKs.txt", "r");
    dfs = fopen("DFs.txt", "r");
    mfs = fopen("MFs.txt", "r");
    fws = fopen("FWs.txt", "r");
    cos = fopen("COs.txt", "r");
    mgs = fopen("MGs.txt", "r");

    char team[13][100];

    /* Randomize team */
    randomPlayer(team[0], gks, 37);
    for (int i = 1; i<=4; i++)
    {
        randomPlayer(team[i], dfs, 91);
    }
    for (int i = 5; i<=7; i++)
    {
        randomPlayer(team[i], mfs, 97);
    }
    for (int i = 8; i<=10; i++)
    {
        randomPlayer(team[i], fws, 69);
    }
    randomPlayer(team[11], cos, 14);
    randomPlayer(team[12], mgs, 14);

    /* Print team */
    printf("Lineup\n\n");
    for (int i = 0; i<11; i++)
    {
        printf("%s", team[i]);
    }
    printf("\nCoach and manager\n\n%s%s", team[11], team[12]);


    printf("\nPress NEWLINE to close");
    scanf_s("%c");

    return 0;
}