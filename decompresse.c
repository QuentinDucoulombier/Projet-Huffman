/*!
    \file decompresse.c
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \brief fichier avec les fonctions pour decompresser
    \remarks Aucune
    Prototypage des fonctions et procédures.
*/

/* Inclusion des librairies */
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "compresse.h"
#include "decompresse.h"
#define fichierCompresse "compressé.txt" //A changer si le fichier est deja compressé


void decompression()
{
  FILE* fichier = NULL;
  fichier = fopen(fichierCompresse, "r");

  FILE* fichier1 = NULL;
  fichier1 = fopen("décompressé.txt", "w");

  int nbCarac = 0;
  liste l = NULL;
  char caracTemp = 0;
  int occuTemp;
  arbre a;
  char temp;

  if (fichier != NULL)
  {
    fscanf(fichier, "%d", &nbCarac);
  }

  for (int i = 0; i < nbCarac; i++)
  {
    fscanf(fichier, "%d->%c", &occuTemp, &caracTemp);
    AjouterTete(&l, occuTemp, caracTemp);
  }

  TriFusion(&l);
  a = creeArbreCompr(l);

  do
  {
    printf("%c", lectCode(a, temp, fichier));
    temp = fgetc(fichier);
  } while (temp != EOF);
  
  fclose(fichier);
  fclose(fichier1);
}

char lectCode(arbre a, char temp, FILE* fichier)
{
  if ((a -> fDroite == NULL) && (a -> fGauche == NULL))
  {
    return a->valeur->caract;
  }
  else
  {
    if (temp != NULL)
    {
      if (temp == '0')
      {
        return lectCode(a->fGauche, NULL,fichier);
      }
      else
      {
        return lectCode(a->fDroite, NULL,fichier);
      }
    }
    else
    {
      if (fgetc(fichier) == '0')
      {
        return lectCode(a->fGauche, NULL,fichier);
      }
      else
      {
        return lectCode(a->fDroite, NULL,fichier);
      }
    }
  }
}