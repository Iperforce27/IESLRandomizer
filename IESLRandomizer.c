#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void randomPlayer(char* player, FILE* archive, int archDim)
{
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
    FILE* gks;
    gks = fopen("GKs.txt", "r");

    char gk[100];

    randomPlayer(gk, gks, 37);

    printf("%s\n\n", gk);
    printf("Press NEWLINE to close");
    scanf("%c");

    return 0;
}