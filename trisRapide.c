/*!
    \file trisRapides.c
    \author Lucas Thu Ping One
    \author Quentin Ducoulombier
    \brief fichier avec tout les tris
    \remarks Aucune
    Description détaillée des fonctions et des procédures
*/

/* Inclusion des librairies */
#include "trisRapide.h"
#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

void TriFusion(liste* l)
{

    liste tete = *l;
    liste a;
    liste b;

    if((tete == NULL) || (tete -> suivant == NULL))
    {
        return;
    }
    Fusionner(tete, &a, &b);
    TriFusion(&a);
    TriFusion(&b);
    *l = listeTrie(a, b);

}

liste listeTrie(liste a, liste b)
{
	liste listeTemp = NULL;

	if (a == NULL)
	{
		return(b);
	}
	else if(b == NULL)
	{
		return(a);
	}

	if(a -> valeur <= b -> valeur)
	{
		listeTemp = a;
		listeTemp -> suivant = listeTrie(a -> suivant, b);
	}
	else
	{
		listeTemp = b;
		listeTemp -> suivant = listeTrie(a, b -> suivant);
	}
	return listeTemp;
}

void Fusionner(liste l,	liste* premiereMoitie, liste* deuxiemeMoitie)
{
	liste curseur2 = NULL;
	liste curseur1 = NULL;
	curseur1 = l;
	curseur2 = l -> suivant;

	while (curseur2 != NULL)
	{
		curseur2 = curseur2 -> suivant;
		if (curseur2 != NULL)
		{
			curseur1 = curseur1 -> suivant;
			curseur2 = curseur2 -> suivant;
		}
	}

	*premiereMoitie = l;
	*deuxiemeMoitie = curseur1 -> suivant;
	curseur1 -> suivant = NULL;
}



/* Meme fonctions mais pour triées des arbres */

void TriFusionArbre(listeArbre* l)
{

    listeArbre tete = *l;
    listeArbre a;
    listeArbre b;

    if((tete == NULL) || (tete -> suivant == NULL))
    {
        return;
    }
    FusionnerArbre(tete, &a, &b);
    TriFusionArbre(&a);
    TriFusionArbre(&b);
    *l = listeTrieArbre(a, b);

}

listeArbre listeTrieArbre(listeArbre a, listeArbre b)
{
	listeArbre listeTemp = NULL;

	if (a == NULL)
	{
		return(b);
	}
	else if(b == NULL)
	{
		return(a);
	}

	if(a -> arbre -> valeur -> valeur  <= b -> arbre -> valeur -> valeur)
	{
		listeTemp = a;
		listeTemp -> suivant = listeTrieArbre(a -> suivant, b);
	}
	else
	{
		listeTemp = b;
		listeTemp -> suivant = listeTrieArbre(a, b -> suivant);
	}
	return listeTemp;
}

void FusionnerArbre(listeArbre l,	listeArbre* premiereMoitie, listeArbre* deuxiemeMoitie)
{
	listeArbre curseur2 = NULL;
	listeArbre curseur1 = NULL;
	curseur1 = l;
	curseur2 = l -> suivant;

	while (curseur2 != NULL)
	{
		curseur2 = curseur2 -> suivant;
		if (curseur2 != NULL)
		{
			curseur1 = curseur1 -> suivant;
			curseur2 = curseur2 -> suivant;
		}
	}

	*premiereMoitie = l;
	*deuxiemeMoitie = curseur1 -> suivant;
	curseur1 -> suivant = NULL;
}

