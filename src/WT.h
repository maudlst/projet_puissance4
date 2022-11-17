/******************************************************************************/
/* WT.H                                                                       */
/******************************************************************************/

#ifndef WT_H
#define WT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define DEBUG_WT 0



/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/
typedef struct noeud {
    struct noeud *fils[26];
    char          term;
    } Noeud;



/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/
/* Crée un nouveau noeud                                                      */
Noeud *nouveauNoeud();
/* Ajoute un mot dans l'arbre                                                 */
void ajouteMotArbre(Noeud *racine,char *str);
/* Cherche un mot dans l'arbre                                                */
int chercheMotArbre(Noeud *racine,char *str);
/* Cherche un mot dans l'arbre qui peut contenir un joker                     */
int chercheMotJokerArbre(Noeud *racine, char *str);
/* Cherche un mot dans l'arbre qui peut contenir une substitution             */
int chercheMotSubstArbre(Noeud *racine, char *str, int nbs, char *chemin, int prof);




#endif
