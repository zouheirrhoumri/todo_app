#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct date
{
    int jour, mois, annee;
} date;

typedef struct tache
{
    int id;
    char titre[20];
    char desc[255];
    char status[11];
    date deadline;
} tache;
tache t[100];
int ID = 0;
int dim = 0;


void ajouter_tache(tache t[])
{
    int choix2;
    t[dim].id = ID + 1;
    printf("\t\ttitre : ");
    scanf(" %[^\n]", t[dim].titre);
    strupr(t[dim].titre);
    printf("\t\tdescription : ");
    scanf(" %[^\n]", t[dim].desc);
    do
    {
        printf("\t\tStatus du tache :\n \t1- A realiser | 2- En cours | 3- Finalisee  : ");
        scanf("%d", &choix2);

    } while (choix2 <= 0 || choix2 >= 4);
    switch (choix2)
    {
    case 1:
        strcpy(t[dim].status, "A realiser");
        break;
    case 2:
        strcpy(t[dim].status, "En cours");
        break;
    case 3:
        strcpy(t[dim].status, "Finalisee");
        break;
    default:
        printf("valeur invalide.\n");
    }
    do
    {
        printf("\t\tsaisir le deadline :");
        scanf("%d/%d/%d", &t[dim].deadline.jour, &t[dim].deadline.mois, &t[dim].deadline.annee);
    } while (t[dim].deadline.jour <= 0 || t[dim].deadline.jour >= 32 || t[dim].deadline.mois <= 0 || t[dim].deadline.mois >= 13 || t[dim].deadline.annee <= 0);
    dim++;
    ID++;
}

void ajouter_plus(tache t[])
{
    int nbr, p;
    printf("\t\tcombien vous voulez ajouter :");
    scanf("%d", &nbr);
    p = nbr + dim;
    for (int i = dim; i < p; i++)
    {
        ajouter_tache(t);
    }
}