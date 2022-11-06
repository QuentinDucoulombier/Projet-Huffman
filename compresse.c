/*!
    \file compresse.c
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \brief fichier avec les fonctions pour compresser le texte et l'ecrire
    \remarks Aucune
    Description détaillée des fonctions et des procédures
*/

/* Inclusion des librairies */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compresse.h"
#include "fonctions.h"
#define nomFichier "lorem.txt" //emplacement où changer le nom du fichier à compresser

void AjouterTeteCode(listeCode* l, char c, char* cd)
{
  maillonC* m;

  m = malloc(sizeof(maillonC));
  m -> caract = c;
  m -> code = cd;
  m -> suivant = (*l);
  (*l) = m;
}

void AffichageListeCode(listeCode l_c)
{
  listeCode temp;
  temp = l_c;

  if (temp == NULL)
  {
    printf("La liste est vide ! \n");
  }
  else
  {
    printf("-------------------------\n");
    while (temp != NULL)
    {
      printf("%c > code : %s\n", temp -> caract, temp ->code);
      temp = temp -> suivant;
    }
  }
}

arbre creeArbreCompr(liste l) 
{
  arbre a = creeArbre(0, NULL, NULL);
  listeArbre l_a = NULL;

  while(l -> suivant != NULL)
  {
    liste templ = NULL;
    templ = copieListe(copieListe(l));
    int temp = 0; 

    for (int i = 0; i < 2; i++) //
    {
      temp= temp + l -> valeur;
      l = l -> suivant;
    }
    AjouterTete(&l, temp, NULL);

    if ((templ -> caract == NULL) && (templ -> suivant -> caract != NULL)) //cas ou la premiere valeur de la liste est un arbre
    {
      if (templ -> valeur == templ -> suivant -> valeur)
      {
        a = creeArbre(l, creeArbre(templ -> suivant, NULL, NULL), suppDebutLstArbre(&l_a));
        AjouterTeteLArbre(&l_a, a);
      }
      else
      {
        a = creeArbre(l, suppDebutLstArbre(&l_a), creeArbre(templ -> suivant, NULL, NULL));
        AjouterTeteLArbre(&l_a, a);
      }
    }
    if ((templ -> caract != NULL) && (templ -> suivant -> caract == NULL)) // cas ou la deuxieme valeur de la liste est un arbre
    {
      a = creeArbre(l, creeArbre(templ, NULL, NULL), suppDebutLstArbre(&l_a));
      AjouterTeteLArbre(&l_a, a);
    }
    if((templ -> caract != NULL) && (templ -> suivant -> caract != NULL)) // cas ou les deux valeurs ne sont pas des arbres
    {
      a = creeArbre(l, creeArbre(templ, NULL, NULL), creeArbre(templ -> suivant, NULL, NULL));
      AjouterTeteLArbre(&l_a, a);
    }
    if((templ -> caract == NULL) && (templ -> suivant -> caract == NULL)) // cas ou les deux sont des arbres
    {
      a = creeArbre(l, suppDebutLstArbre(&l_a), suppDebutLstArbre(&l_a -> suivant));
      AjouterTeteLArbre(&l_a, a);
    }
    TriFusionArbre(&l_a);
    TriFusion(&l); 
  }
  return a;
}

void compression(arbre a, listeCode* lc)
{
  char* code = "";
  compressionAux(a, code, lc);
}

void compressionAux(arbre a, char* code, listeCode* lc)
{
  if ((a -> fDroite == NULL) && (a -> fGauche == NULL)) 
  {
    AjouterTeteCode(lc, a -> valeur -> caract, code);

  }
  else
  {
    compressionAux(a -> fDroite, rajoutChaine(code, "1"), lc);
    compressionAux(a -> fGauche, rajoutChaine(code, "0"), lc);
  }  
}

char* rajoutChaine(char* elt1, char* elt2)
{
  int taille1 = strlen(elt1);
  int taille2 = strlen(elt2);
  int taille = taille1 + taille2;
  char* temp =  malloc(taille *sizeof(char));

  if(elt1 == "")
  {
    free(temp);
    return elt2;
  }
  
  for (int i = 0; i < taille1; i++)
  {
    temp[i] = elt1[i];
  }
  for (int j = 0; j < taille2; j++)
  {
   temp[taille1 + j] = elt2[j];
  }
  return temp;
}

void en_tete(liste l)
{
  FILE* fichier = NULL;
  fichier = fopen("compressé.txt", "w");

  liste temp = NULL;
  temp = l;

  fprintf(fichier, "%d \n", tailleListe(l));

  if (temp == NULL)
  {
    printf("La liste est vide ! \n");
  }
  else
  {
    while (temp != NULL)
    {
      fprintf(fichier, "%d->%c\n", temp -> valeur, temp -> caract);
      temp = temp -> suivant;
    }
  }

  fclose(fichier);
}

char* caractCode(listeCode lc, int lettreEnCours)
{
  while(lc != NULL)
  {
    if(lc -> caract == lettreEnCours)
    {
      return lc -> code;
    }
    lc = lc -> suivant;
  }
}

void ouvrirFich(listeCode lc)
{
  FILE* fichier = fopen(nomFichier, "r");
  FILE* fichier1 = fopen("compressé.txt", "a");
  char alphabet[77] = "abcdefghijklmnopqrstuwxyz (.)[,]/-?!:;'\"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n"; // reste les "" et certainement d'autres truc
  int compteur[77] = {0}, y;
  int lettreEnCours = 0;
  if(fichier != NULL)
  {
    while (lettreEnCours != EOF)
    {
      lettreEnCours = fgetc(fichier);
      y = 0;
      while(alphabet[y] != '\0')
      {
        if (alphabet[y] == lettreEnCours)
        {
          fputs(caractCode(lc, lettreEnCours), fichier1);
        }

      y++;
      }
      
    }
  }
  fclose(fichier);
  fclose(fichier1);
}