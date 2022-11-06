#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "trisRapide.h"
#include "compresse.h"
#include "decompresse.h"

int main()
{
  int reponse;
  liste l = NULL;
  listeCode lc = NULL;
  arbre test = NULL;
  liste temp = NULL;

  do
  {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Que voulez vous  faire? \n");
    printf("1: compréssion d'un fichier \n");
    printf("2: décompréssion d'un fichier \n");
    scanf("%d", &reponse);
  } while ((reponse < 1) || (reponse > 2));
  

  switch (reponse)
  {
  case 1:
    l = occurence();
    TriFusion(&l);
    temp = copieListe(copieListe(l));
    test = creeArbreCompr(l);
    compression(test, &lc);
    en_tete(temp);
    ouvrirFich(lc);
    break;

  case 2:
    decompression();
    break;

  default:
    break;
  }











  /*
  //AffichageListe(occurence());
  //printf("Le nombre d'occurence est de : %d\n", nombreOccurence('a'));
  liste l = NULL;
  listeCode lc = NULL;
  l = occurence();
  arbre test = NULL;
  TriFusion(&l);
  AffichageListe(l);
  liste temp = copieListe(copieListe(l));
  test = caVaEtreDur(l, creeArbre(0, NULL, NULL));
  //AffichageListe(l);
  //parcoursPrefixe(test);
  compression(test, &lc);
  AffichageListeCode(lc);
  en_tete(temp, test);
  ouvrirFich(lc);
  //tabComp(temp, test);

  decompression();
  */
  return 0;
}
