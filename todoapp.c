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

void ajouter_tache()
{
    tache temp;

    int choix2;
    temp.id = ID + 1;
    printf("\t\ttitre : ");
    scanf(" %[^\n]", temp.titre);
    strupr(temp.titre);
    printf("\t\tdescription : ");
    scanf(" %[^\n]", temp.desc);
    do
    {
        printf("\t\tStatus du tache :\n \t1- A realiser | 2- En cours | 3- Finalisee  : ");
        scanf("%d", &choix2);

    } while (choix2 <= 0 || choix2 >= 4);
    switch (choix2)
    {
    case 1:
        strcpy(temp.status, "A realiser");
        break;
    case 2:
        strcpy(temp.status, "En cours");
        break;
    case 3:
        strcpy(temp.status, "Finalisee");
        break;
    default:
        printf("valeur invalide.\n");
    }
    int scan=0;
    do
    {
        
        printf("\t\tsaisir le deadline :");
        scan= scanf("%d/%d/%d", &temp.deadline.jour, &temp.deadline.mois, &temp.deadline.annee);
       // printf("%d/%d/%d", temp.deadline.jour, temp.deadline.mois, temp.deadline.annee);
    } while (scan != 3);
    
    
   // } while (temp.deadline.jour <= 0 || temp.deadline.jour >= 32 || temp.deadline.mois <= 0 || temp.deadline.mois >= 13 || t[dim].deadline.annee <= 0);
     // t[dim] = temp;
   FILE *file = fopen("taches.txt", "ab");
    if (file != NULL)
    {
        fwrite(&temp , sizeof(temp) , 1 , file);
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    fclose(file);
   //dim++ ;

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

void afficher_tache()
{
    tache temp;
    printf("\t\t+------------------------------------------------------------------------------+\n");
    printf("\t\t| Id |        Tache         |      Description     | Date limite |    Status   |\n");
    printf("\t\t+------------------------------------------------------------------------------+\n");
    // for (int i = 0; i < dim; i++)
    // {

    //     printf("\t\t| %-2d | %-20s | %-20s | %2d-%2d-%4d  | %-11s |\n", t[i].id, t[i].titre, t[i].desc, t[i].deadline.jour, t[i].deadline.mois, t[i].deadline.annee, t[i].status);
    // }
    FILE *file = fopen("taches.txt", "rb");

        if (file != NULL)
    {
        while (fread(&temp , sizeof(temp) , 1 , file))
    {
           printf("\t\t| %-2d | %-20s | %-20s | %2d-%2d-%4d  | %-11s |\n", temp.id, temp.titre, temp.desc, temp.deadline.jour, temp.deadline.mois, temp.deadline.annee, temp.status);
    
    }
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    fclose(file);

    
    
    printf("\t\t+------------------------------------------------------------------------------+\n");
}
 int main(){
   //   ajouter_tache();
   afficher_tache();
    return 0;
 }