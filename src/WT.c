/******************************************************************************/
/* WT.C                                                                       */
/******************************************************************************/

#include "WT.h"



/******************************************************************************/
/* nouveauNoeud                                                               */
/******************************************************************************/
Noeud *nouveauNoeud()
{
    Noeud * n = (Noeud *) malloc(sizeof(Noeud));
    int i;

    for(i=0;i!=26;i++)
        n->fils[i] = NULL;
    n->term = 0;

    return n;
}




/******************************************************************************/
/* ajouteMotArbre                                                             */
/******************************************************************************/
void ajouteMotArbre(Noeud *racine, char *str)
{
  if (str[0] == '\0'){
    racine->term = 1;
    //printf("fini");
  }
  else{
    if (racine->fils[str[0]-'a'] == NULL){
      racine->fils[str[0]-'a'] = nouveauNoeud();
    }
    ajouteMotArbre(racine->fils[str[0]-'a'], str+1);
  }
  return ;
}



/******************************************************************************/
/* chercheMotArbre                                                            */
/******************************************************************************/
int chercheMotArbre(Noeud *racine,char *str)
{
  if (str[0] == '\0'){
    //printf("fini");
    return racine->term ? 1:0;
  }
  else{
    if (racine->fils[str[0]-'a'] != NULL)
      return chercheMotArbre(racine->fils[str[0]-'a'], str+1);
    else
      return 0;
  }
}

int chercheMotJokerArbre(Noeud *racine, char *str){
  int somme = 0;
  if (str[0] == '\0'){
    return racine->term ? 1:0;
  }
  else if (str[0] == '#'){
    for(int i = 0;i<26;i++){
      if (racine->fils[i] != NULL){
        somme += chercheMotJokerArbre(racine->fils[i], str+1);
      }
    }
    return somme;
  }
  else{
    if (racine->fils[str[0]-'a'] != NULL)
      return chercheMotJokerArbre(racine->fils[str[0]-'a'], str+1);
    else
      return 0;
  }
}

int chercheMotSubstArbre(Noeud *racine, char *str, int nbs, char *chemin, int prof){
  int somme = 0;
  if (str[0] == '\0'){
    return racine->term ? 1:0;
  }
  else{
    if (racine->fils[str[0]-'a'] != NULL){
      *chemin = str[0]
      return chercheMotSubstArbre(racine->fils[str[0]-'a'], str+1, nbs, chemin+1, prof+1);
    }
    else{
      if (nbs > 0) {
        for(int i = 0;i<26;i++){
          if (racine->fils[i] != NULL){
            *chemin = i+'a';
            somme += chercheMotSubstArbre(racine->fils[i], str+1, nbs-1, chemin+1, prof+1);
          }
        }
      }
    }
    return somme;
  }
}
