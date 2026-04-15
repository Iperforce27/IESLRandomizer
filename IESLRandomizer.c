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
    if (strcmp(*player, *(player-1)))
    {
        randomPlayer(player, archive, archDim);
    }
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
    
    int dfN, mfN, fwN;  //Number of players per role

    /* Ask for formation */
    printf("IESL Randomizer (v2)\n");
    printf("Give me the formation as 3 positive integers separated by a space: ");
    scanf_s("%d%d%d", &dfN, &mfN, &fwN);

    int teamsize = dfN + mfN + fwN + 1;
    char team[teamsize + 2][100];

    /* Randomize team */
    randomPlayer(team[0], gks, 36);
    for (int i = 1; i <= dfN; i++)
    {
        randomPlayer(team[i], dfs, 91);
    }
    for (int i = dfN + 1; i <= dfN + mfN; i++)
    {
        randomPlayer(team[i], mfs, 97);
    }
    for (int i = dfN + mfN + 1; i <= dfN + mfN + fwN; i++)
    {
        randomPlayer(team[i], fws, 69);
    }
    randomPlayer(team[teamsize], cos, 14);
    randomPlayer(team[teamsize + 1], mgs, 14);

    /* Close the txt files */
    fclose(gks);
    fclose(dfs);
    fclose(mfs);
    fclose(fws);
    fclose(cos);
    fclose(mgs);

    /* Print team */
    printf("Lineup\n\n");
    for (int i = 0; i<teamsize; i++)
    {
        printf("%s", team[i]);
    }
    printf("\nCoach and manager\n\n%s%s", team[teamsize], team[teamsize+1]);


    printf("\nPress NEWLINE to close");
    scanf_s("%c%c");

    return 0;
}