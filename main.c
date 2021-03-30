#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define VIDER_BUFFER while(getchar() != '\n') // evite boucle infini du scanf


typedef struct
{
    double a;  // amplitud
    int f;  // frequence
    int t;  // temps
    int b;  // indice variation freq
    int g;  // freq variation sirene
} Onde;

bool f_control_saisie(int ret)
{
    bool validation;

    if (ret != 1)
    {
        printf("ERREUR DE SAISIE! Recommencer svp.\n\n");
        validation = 0;
    }
    else
    {
        validation = 1;
    }
    return validation;
}

int main(int argc, char* argv[])
{
    Onde onde = {0};
    bool saisie_valide;
    int ret = 0;
    char *out_filename = NULL;

    FILE* fp = stdin;
    do
    {
        printf("Insérer une valeur d'amplitude :");
        ret = fscanf(fp, "%lf", &onde.a);
        VIDER_BUFFER;
        saisie_valide = f_control_saisie(ret);

    } while (saisie_valide == 0);

    do
    {
        printf("Insérer une valeur de fréquence de base :");
        ret = fscanf(fp, "%d", &onde.f);
        saisie_valide = f_control_saisie(ret);

    } while (saisie_valide == 0);

    do
    {
        printf("Insérer valeur pour l’indice de la variation de fréquence :");
        ret = fscanf(fp, "%d", &onde.b);
        saisie_valide = f_control_saisie(ret);

    } while (saisie_valide == 0);

    do
    {
        printf("Insérer valeur de la fréquence des variations de la sirène :");
        ret = scanf("%d", &onde.g);
        saisie_valide = f_control_saisie(ret);

    } while (saisie_valide == 0);

    do
    {
        printf("Ecrire le nom de fichier de sortie :");
        ret = scanf("%s", out_filename);
        VIDER_BUFFER;
        saisie_valide = 0; //f_control_saisie(ret);

    } while (saisie_valide == 0);

    printf("Insert 'Amplitud' value :");

    exit(EXIT_SUCCESS);
}