#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "rules.h"

int main() {
    int nbre,taille; /* Nombre de joueurs, Taille du plateau */
    int n=1; /* correspond au numéro du joueur */
    char c; /* permet de créer une condition si un joueur change d'avis après saisie d'une case */
    int i,j; /* permet de parcourir la matrice de piles */
    int r; /* correspond à l'indice d'un élément dans représentation 1D  du tableau 2D */

    char buf[256]; /* permet de récupérer la ligne entrée en entier */

    /* Initialisation */

    /* Demande du nmbre de joueurs lors de la partie */
    
    printf("Entrez le nombre de joueurs:\n");
    fgets(buf, 256, stdin);    
    sscanf(buf,"%i",&nbre);
    
    /* Demande de la taille du plateau */

    printf("Entrez la taille du plateau:\n");
    fgets(buf, 256, stdin);
    sscanf(buf,"%i",&taille);
    printf("\n");
    
    /* Création du plateau */

    stack* s = (stack*) malloc(taille*taille*sizeof(stack));

    /* Début du jeu */
    
    while (nofinish(s,taille)) {

        /* Tant que le plateau n'est pas rempli, le jeu continue */
        /* Le facteur "terminason" dépend entièrement des joueurs lors de la partie */
        
        printf("Tour du joueur %i\n\n", n);
        shown(s,taille);
        
        c='n';
        while (c!='o') {

        /* Tant que le joueur n'aura pas entrer une commande commencant par la lettre o lors de la confirmation, alors les questions seront redemandées */
        /* Le facteur "terminaison" dépend entièrement du joueur en tour */

            /* Demande la case choisie par le joueur numéro n */

            printf("Quelle case choisissez vous ?\n");
            fgets(buf, 256, stdin);
            sscanf(buf,"%i %i",&i,&j);
            printf("\n");

            /* Affiche le contenu de la case */

            printf("Contenu de la case:\n\n");
            r=taille*(i-1)+j-1;
            show(s[r]);

            /* Demande la confirmation du joueur numéro n pour placer le jeton dans la case insérée */

            printf("Voules vous mettre les jeton ici ?\n");
            fgets(buf, 256, stdin);
            sscanf(buf, "%1c",&c);
            printf("\n");
        }
        
        /* Le jeton est placé comme souhaité dans le plateau et celui-ci sera modifié si nécessaire en fonction des règles du jeu */

        int *l = (int*) calloc(taille*taille,sizeof(int));
        active(s,i,j,n,taille,l);
        free(l);
        if (n!=nbre) n+=1;
        else n=1;
    }
    
    printf("La partie est terminée\n\n");
    
    /* Affichage du score */

    printf("Joueur :");
    for (n=1;n<=nbre;n+=1)
        printf("%3i", n);
    printf("\n");
    
    int *t = (int*) calloc(nbre,sizeof(int));
    t=score(s,t,nbre,taille);
    printf("Score  :");
    for (n=0;n<nbre;n+=1)
        printf("%3i", t[n]);
    printf("\n");
    
    /* La mémoire est libérée */

    free(s);
    free(t);
    
    return 0;
}

