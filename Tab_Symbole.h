#include<stdio.h>
#include<stdlib.h>
typedef struct Element_TS
{
	char *nom;
	char *code;
	char* type;
	int cst;
	int position;
	struct Element_TS * svt;

}Element_TS;

Element_TS* TS=NULL;
int positionEntite=1;

void AfficherTS(Element_TS* TS)
{
	Element_TS* cursor;
	if ( TS==NULL)
	{
		printf("\n========== Table de symbole vide ==========\n");
	}
	else
	{
		cursor=TS;
		printf("\n==================== Table de Symbole ====================\n");
		printf("|Nom Entitée  | Code Entitée | Type Entitée | CST | POSITION |\n");
		while(TS!NULL)
		{
			printf("|%s",cursor->nom);
			printf("|%s",cursor->code);
			if ( ->type !=NULL) { printf("|%s",cursor->type);}
			printf("|%d\n",cursor->cst);
			printf("|%d\n",cursor->position);
			cursor=cursor->svt;
		}
	}
}




Element_TS* Rechercher(char* nom)
{
	Element_TS* curseur=TS;
	while(curseur !=NULL)
	{
		if ( strcmp(curseur->nom,nom)==0) return curseur;
	}
	return NULL;
} 

int Inserer(char* nom,char* code)
{
	if  (Rechercher(nom)!=NULL)
	{
		if (strcmp(code,"idf")==0){
			printf("\nDouble déclaration de la variable %s\n",nom );
			//Erreur Double declared IDF
			return -1;	
		}
	}
	else
	{
		if ( TS==NULL)
		{
			TS=(Element_TS*)malloc(sizeof(Element_TS));
			strcpy(nom,TS->nom);
			strcpy(code,TS->code);
			TS->position=positionEntite;
			positionEntite++;
			TS->svt=NULL;
		}
		else
		{
			Element_TS* tmp = (Element_TS*)malloc(sizeof(Element_TS));
			strcpy(nom,tmp->nom);
			strcpy(code,tmp->code);
			TS->position=positionEntite;
			positionEntite++;
			tmp->svt=TS;
			TS=tmp;
		}
		//Insertion réussie
		return 0

	}
}

int idf_Declarer(char* nom)
{
	Element_TS* current_idf=Rechercher(nom);
	if ( current_idf !=NULL)
	{
		if ( current_idf->type!=NULL) return 1;
		//non Déclaré false == 0
		return 0;
	}
	else {  //idf non inserer dans la TS 
		return -1; }
}

int nb_sauts_ligne(char * s) {
	return strcpt(s,'\n');
}