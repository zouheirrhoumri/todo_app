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