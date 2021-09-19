#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int* score(stack* s, int* l, int n, int t) {
    int i,j;
    for (i=0; i<t*t; i+=1) {
        for (j=1; j<=n; j+=1) {
        
        /* On parcourt le tableau pour compter le nombre de jeton du joueur j */

            if ((s[i])->v==j)
                l[j-1]+=1;
        }
    }
    return l; 
}

void shown (stack* s, int t) {

    /* Affichage de la première ligne du plateau, ie des numéros de colonnes */

    printf("   |");
    int i,k;
    for (i=1;i<=t;i+=1)
        printf("%3i",i);
    printf("\n");

    printf("---+");
    for (i=1;i<=t;i+=1)
        printf("---");
    printf("\n");

    /* Afficahge du reste */

    printf("  1|");
    i=1;
    k=0;
    while (k<t*t) {

    /* t*t-k+1 est un variant de boucle, donc la boucle se termine */

        if (is_empty_stack(s[k])) printf("   ");
        else printf("%3i",(s[k])->v);
        if (k+1==t*t)
            printf("\n\n");
        else if ((k+1)%t==0) {
            i+=1;
            printf("\n   |\n%3i|",i);
        }
        k+=1;
    }
    printf("\n\n");
}

stack* active(stack* s, int i, int j, int n, int t, int* l) {

    /* active ajoute le pion à la case voulue */
    /* si la pile possède déjà un pion du joueur du tour, alors la case est activée */
    /* dans ce cas, à la place d'ajouter le pion à la case, on enlève le pion du joueur de la case */
    /* en fonction des coordonnées de la case, on ajoute des pions du joueur du tour chez les voisins de la case, pour cela on appelle récursivement active */
    
    /* ce qui garanti la terminaison est l'utilisation de la liste l: */
    /* si l[r]==1 alors la case, ayant déjà été activé à ce tour, n'est pas activée */
    /* dans le cas contraire, il suffit soit d'ajouter le pion à la case correspondante, soit de l'activer si les conditions sont remplies */

    int r=t*(i-1)+j-1;
    
    /* 1er cas: la case a déjà été activé; dans ce cas, ne rien faire */

    if (l[r]==1)
        return s;

    /* 2ème cas: la case est vide, on ajoute simplement le jeton*/

    else if (is_empty_stack(s[r]) && l[r]==0)
        push(n,&(s[r]));

    /* 3ème cas: la case est non-vide mais la couleur du dernier jeton de la pile est différente du joueur qui joue */
    /* On ajoute simplement le jeton */

    else if ((s[r])->v!=n && l[r]==0)
        push(n,&(s[r]));

    /* 4ème et dernier cas: sinon, la case est activée */
    /* Des dispositions sont prises en fonction de la case activée */

    else {

        /* On fait savoir que la case a été activée à ce tour */

        l[r]=1;
        pop(&(s[r]));
        
        /* si la case activée est de coordonnées 1 1 */

        if (i==1 && j==1) {
            s=active(s,i+1,j,n,t,l);
            s=active(s,i,j+1,n,t,l);
        }

        /* si la case activée est de coordonnées 1 t */

        else if (i==1 && j==t) {
            s=active(s,i,j-1,n,t,l);
            s=active(s,i+1,j,n,t,l);
        }

        /* si la case activée est de coordonnées t 1 */

        else if (i==t && j==1) {
            s=active(s,i-1,j,n,t,l);
            s=active(s,i,j+1,n,t,l);
        }

        /* si la case activée est de coordonnées t t */

        else if (i==t && j==t) {
            s=active(s,i,j-1,n,t,l);
            s=active(s,i-1,j,n,t,l);
        }

        /* si la case activée appartient à la première ligne mis à part les deux extrémités */

        else if (i==1) {
            s=active(s,i,j-1,n,t,l);            
            s=active(s,i+1,j,n,t,l);
            s=active(s,i,j+1,n,t,l);
        }

        /* si la case activée appartient à la dernière ligne mis à part les deux extrémités */

        else if (i==t) {
            s=active(s,i,j-1,n,t,l);            
            s=active(s,i-1,j,n,t,l);
            s=active(s,i,j+1,n,t,l);
        }

        /* si la case activée appartient à la première colonne mis à part les deux extrémités */

        else if (j==1) {
            s=active(s,i-1,j,n,t,l);            
            s=active(s,i,j+1,n,t,l);
            s=active(s,i+1,j,n,t,l);
        }

        /* si la case activée appartient à la dernière colonne mis à part les deux extrémités */

        else if (j==1) {
            s=active(s,i-1,j,n,t,l);            
            s=active(s,i,j-1,n,t,l);
            s=active(s,i+1,j,n,t,l);
        }

        /* si la case ne respecte aucun des critères précédents */

        else {
            s=active(s,i,j-1,n,t,l);            
            s=active(s,i-1,j,n,t,l);
            s=active(s,i+1,j,n,t,l);            
            s=active(s,i,j+1,n,t,l);
        }
    }
    return s;
}

int nofinish(stack* s, int t) {
    int k=0;

    /* cherche l'existence d'une pile vide */

    while (!(is_empty_stack(s[k])) && k<t*t)

    /* t*t-k+1 est un variant de boucle, donc la boucle se termine */

        k+=1;
    return (k<t*t);
}

