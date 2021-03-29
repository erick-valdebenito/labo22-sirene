# Labo 22 - Fichier son

## Objectifs pédagogiques
- Utiliser les fonctions de base de gestion des fichiers "texte" du langage C.
- Coder un programme robuste aux erreurs des utilisateurs.

## Saisie
- Tant que l'utilisateur n'a pas entré une valeur correcte, le programme doit demander de recommencer la saisie.

## Visualisation de l’onde d’une sirène
La forme caractéristique de l’onde d’une sirène est une sinusoïde d’amplitude constante et de fréquence variant sinusoïdalement, d’équation :

```math
s(t) = A * sin(2 * π * f * t + B * sin(2 * π * g * t))
```

où `s(t)` désigne la forme d’onde, `A` son amplitude, `f` sa fréquence de base, `B` l’indice de la variation de fréquence, et `g` la fréquence des variations de la sirène.

Ecrire un programme qui demande à l’utilisateur les paramètres `A`, `f`, `B` et `g`, ainsi que le nom du fichier de résultat (ex. "onde.txt" ou "onde.csv"), et qui génère un fichier texte formaté (ou csv) contenant 2000 valeurs consécutives de la fonction s(t) séparées de 0.001 seconde. 

Le fichier devra contenir une ligne pour chaque point, comportant le temps `t` et la valeur de s(t) séparées par une virgule.

Utilisez ce programme pour générer les valeurs de l’onde d’une sirène de fréquence f=20 Hz (valeur volontairement basse pour permettre une bonne visualisation), d’amplitude A=20000, indice de variation (modulation) de fréquence B = 5, et de fréquence de variation de g = 2 Hz.

Vérifier que le fichier contient bien les valeurs du temps et de s(t) en colonne.

Pour mieux se représenter les paramètres d'un son, voici un descriptif des différents paramètres :

**Description:**

A 
: amplitude du son (fort ou doux) (les musiciens disent forte ou piano)

f
: fréquence de base (son aigu ou bas)

B
: indice de la variation de fréquence (change la mélodie)

g
: fréquence des variations de la sirène (rapide ou lent)

## Visualisation

Importez le fichier texte généré (.csv) dans un logiciel tableur (Excel ou autre) et tracez l’onde calculée (contrôle visuel).

Enregistrer votre graphique comme image.

## A pousser sur Github
- Code source
- Graphique en image
