#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Laby
{
    int** tab;
    int taille;
} Laby;

void Preparer(Laby* l)
{
    int i,j,cpt;
    l->tab = malloc(l->taille*sizeof(int*));
    for(i=0;i<l->taille;i++)
        l->tab[i] = malloc(l->taille*sizeof(int));
    for(cpt=1,i=0;i<l->taille;i++)
        for(j=0;j<l->taille;j++)
            if (i%2==1 && j%2==1)
                l->tab[i][j] = cpt++;
            else
                l->tab[i][j] = 0;
}

void Afficher(Laby* l)
{
    int i,j;
    for(i=0;i<l->taille;i++)
    {
        for(j=0;j<l->taille;j++)
            printf("%c",(l->tab[i][j]==0)?'1':'0');
        printf("\n");
    }
}

void Liberer(Laby* l)
{
    int i;
    for(i=0;i<l->taille;i++)
        free(l->tab[i]);
    free(l->tab);
}

void Remplacer(Laby* l,int anc,int nouv)
{
    int i,j;
    for(i=0;i<l->taille;i++)
        for(j=0;j<l->taille;j++)
            if (l->tab[i][j]==anc)
                l->tab[i][j] = nouv;
}

void Generer(Laby* l)
{
    int vec[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int nbzones = ((l->taille-1)/2)*((l->taille-1)/2);
    while(nbzones>1)
    {
        int i,x,y,zone1;
        zone1 = 0;
        x = rand()%(l->taille-2)+1;
        y = rand()%(l->taille-2)+1;
        if (l->tab[x][y]!=0)
            continue; // pas un mur
        for(i=0;i<4;i++)
        {
            int valzone = l->tab[x+vec[i][0]][y+vec[i][1]];
            if (valzone>0)
            {
                if (zone1==0 || zone1 == valzone)
                    zone1 = valzone;
                else
                { // fusion
                    l->tab[x][y] = zone1;
                    Remplacer(l,valzone,zone1);
                    nbzones--;
                    break;
                }
            }        
        }
    }
}

int main()
{
    Laby l;
    srand((unsigned int)time(NULL));
    printf("taille ? Impaire et au moins 3: ");
    scanf("%d",&(l.taille));
    if (l.taille<3 || l.taille%2==0)
        return -1;  // relis la question.
    Preparer(&l);
    Generer(&l);
    Afficher(&l);
    Liberer(&l);
    return 0;
}