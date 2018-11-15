#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int nb_LD();
int fin_dec=0;

typedef struct Element_TS
{
	char * nom;
	char * code;
	char * type;
	int cst;
	int position;
	struct Element_TS * svt;

}Element_TS;

typedef struct Element_List_Dec {
	char* nom;
	struct Element_List_Dec * svt;
}Element_List_Dec;

Element_TS* TS=NULL;
int positionEntite=1;
Element_List_Dec* LD=NULL;
char * type_courant;

void AfficherTS(Element_TS* TS)
{
	Element_TS* cursor;
	if ( TS==NULL)
	{
		printf("\n==================== Table de Symbole ====================\n");
		printf("==================== ///// Vide ///// ====================\n");
	}
	else
	{
		int tmp = 1;
		cursor=TS;
		printf("\n==================== Table de Symbole ====================\n");
		printf("| Nom Entité | Code Entitée | Type Entitée | CST | POSITION |\n");
		while(cursor!=NULL)
		{
			printf("|%12s",cursor->nom);
			printf("|%14s",cursor->code);
			if (cursor->type !=NULL) { printf("|%14s",cursor->type);}
			else { printf("|%14s"," "); }
			printf("|%5d",cursor->cst);
			printf("|%10d|\n",cursor->position);
			cursor=cursor->svt;
			tmp++;
		}
	}
}


Element_TS* Rechercher(char* nom)
{
	Element_TS* curseur = TS;
	while(curseur != NULL)
	{
		if ( strcmp(curseur->nom,nom) == 0) return curseur;
		curseur=curseur->svt;
	}
	return NULL;
} 

int Inserer(char* nom, char* code, char* type)
{
	if ( fin_dec ) return 0;
	Element_TS* found = Rechercher(nom);
	if  (found!=NULL)
	{
		printf("\nERREUR SEMANTIQUE: Variable %s doublement declaree!",nom);
	}
	else
	{
		if ( TS == NULL)
		{
			TS=(Element_TS*)malloc(sizeof(Element_TS));
			TS->nom=(char*) malloc(sizeof(char)*strlen(nom));
			strcpy(TS->nom,nom);
			TS->code=(char*) malloc(sizeof(char)*strlen(code));
			strcpy(TS->code,code);
			TS->type=(char*) malloc(sizeof(char)*strlen(type));
			strcpy(TS->type,type);
			TS->position=positionEntite;
			positionEntite++;
			TS->svt=NULL;
		}
		else
		{
			Element_TS* tmp = (Element_TS*)malloc(sizeof(Element_TS));
			tmp->nom=(char*) malloc(sizeof(char)*strlen(nom));
			strcpy(tmp->nom,nom);
			tmp->code=(char*) malloc(sizeof(char)*strlen(code));
			strcpy(tmp->code,code);
			tmp->type=(char*) malloc(sizeof(char)*strlen(type));
			strcpy(tmp->type,type);
			tmp->position=positionEntite;
			positionEntite++;
			tmp->svt=TS;
			TS=tmp;
		}
	}
	return 0;
}

void Inserer_LD( char * nom ) {
	printf("\nvar: %s ",nom);
	if ( LD == NULL ) {
		LD = (Element_List_Dec *) malloc(sizeof(Element_List_Dec));
		LD->nom=strdup(nom);
		LD->svt=NULL;
	} else {
		Element_List_Dec* tmp = (Element_List_Dec*)malloc(sizeof(Element_List_Dec));
		tmp->nom=strdup(nom);
		tmp->svt=LD;
		LD=tmp;
	}
}

void Vider_LD() {
	while (LD!=NULL) {
		printf("\nDeplacer de LD(%d) vers TS: %s %s",LD,LD->nom,type_courant);
		Inserer(LD->nom,"idf",type_courant);
		LD=LD->svt;
	}
}

int nb_LD() {
	Element_List_Dec * tmp = LD;
	int nb=0;
	while (tmp!=NULL) {
		nb++;
		tmp=tmp->svt;
	}
	return nb;
}

void afficher_LD() {
	printf("( ");
	Element_List_Dec * tmp = LD;
	while (tmp!=NULL) {
		printf("\t%s",tmp->nom);
		tmp=tmp->svt;
	}
	printf(" )");
}

/*
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
}*/
