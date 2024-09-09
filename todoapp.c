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
    FILE *file = fopen("taches.txt", "a");
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

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

void afficher_tache(tache t[])
{
    printf("\t\t+------------------------------------------------------------------------------+\n");
    printf("\t\t| Id |        Tache         |      Description     | Date limite |    Status   |\n");
    printf("\t\t+------------------------------------------------------------------------------+\n");
    for (int i = 0; i < dim; i++)
    {

        printf("\t\t| %-2d | %-20s | %-20s | %2d-%2d-%4d  | %-11s |\n", t[i].id, t[i].titre, t[i].desc, t[i].deadline.jour, t[i].deadline.mois, t[i].deadline.annee, t[i].status);
    }
    printf("\t\t+------------------------------------------------------------------------------+\n");
}

void tri_alpha()
{

    tache r[100], temp;
    for (int i = 0; i < dim; i++)
    {
        r[i] = t[i];
    }
    for (int i = 0; i < dim; i++)
    {
        for (int j = i + 1; i < dim; i++)
        {
            if (strcmp(r[i].titre, r[j].titre) > 0)
            {
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;
            }
        }
    }
    printf("\t\tLes taches triees alphabitique : \n");
    afficher_tache(r);
}
