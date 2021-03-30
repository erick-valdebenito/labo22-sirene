#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIDER_BUFFER while (getchar() != '\n')  // evite boucle infini du scanf
#define BUFFER_SIZE 64
#define POINTS 2000
#define PI 3.14

typedef struct
{
    double a;  // amplitud, seulement valeurs positives
    int f;     // frequence, seulement valeurs positives
    int b;     // indice variation freq
    int g;     // freq variation sirene, seulement valeurs positives

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

void sirene(Onde onde, char* filename, double* temps)
{
    FILE* fp = fopen(filename, "w");
    if(fp == NULL){
        printf("Error: impossible to open '%s'", filename);
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "T[s],S(t)\n");
    for (int i = 0; i < POINTS; i++)
    {
        double siren =
            abs(onde.a) * sin(2 * PI * abs(onde.f) * temps[i] + onde.b * 
            sin(2 * PI * abs(onde.g) * temps[i]));
        fprintf(fp, "%0.3lf,%0.2lf\n", temps[i],siren);
    }
    fclose(fp);
}

int main(int argc, char* argv[])
{
    Onde onde = {0};
    bool saisie_valide;
    int ret = 0;
    char out_filename[BUFFER_SIZE] = {0};
    double temps[POINTS];
    double j = 0;

    do
    {
        printf("Insérer une valeur d'amplitude :");
        ret = scanf("%lf", &onde.a);
        VIDER_BUFFER;
        saisie_valide = f_control_saisie(ret);

    } while (saisie_valide == 0);

    do
    {
        printf("Insérer une valeur de fréquence de base :");
        ret = scanf("%d", &onde.f);
        VIDER_BUFFER;
        saisie_valide = f_control_saisie(ret);

    } while (saisie_valide == 0);

    do
    {
        printf("Insérer valeur pour l’indice de la variation de fréquence :");
        ret = scanf("%d", &onde.b);
        VIDER_BUFFER;
        saisie_valide = f_control_saisie(ret);

    } while (saisie_valide == 0);

    do
    {
        printf("Insérer valeur de la fréquence des variations de la sirène :");
        ret = scanf("%d", &onde.g);
        VIDER_BUFFER;
        saisie_valide = f_control_saisie(ret);

    } while (saisie_valide == 0);

    int saisie_valide1 = 0;
    do
    {
        printf("Ecrire le nom de fichier de sortie :");

        if (fgets(out_filename, sizeof(out_filename) - 1, stdin) != NULL)
        {
            saisie_valide1 = 1;
            out_filename[strcspn(out_filename, "\n")] = 0;  // remove \n in string
        }
        else
        {
            printf("\nSaisie incorrect. ex : test.txt ou test.csv\n");
        }
    } while (saisie_valide1 == 0);

    // Creation vecteur temps
    for (int i = 0; i < POINTS; i++)
    {
        temps[i] = j / 1000;
        j++;
    }

    sirene(onde, &out_filename[0], &temps[0]);

    exit(EXIT_SUCCESS);
}