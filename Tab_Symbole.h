#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int nb_LD();
int fin_dec=0;
int type_changes;
int type_const;
int index_val=-1;
int nbligne=1;
int nbcolonne;

typedef struct Element_TS {
	char * nom;
	char * code;
	char * type;
	int cst;
	int taille;
	struct Element_TS * svt;
} Element_TS;

typedef struct Element_List_Dec {
	char* nom;
	int taille;
	struct Element_List_Dec * svt;
} Element_List_Dec;

Element_TS* TS = NULL;
Element_List_Dec* LD = NULL;
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
		printf("\n ===================== Table de Symbole =====================\n\n");
		printf("| Nom Entité | Code Entitée | Type Eitee | EST CST | TAILLE |\n");
		printf("-------------------------------------------------------------\n");
		while(cursor!=NULL)
		{
			printf("|%12s",cursor->nom);
			printf("|%14s",cursor->code);
			if (cursor->type !=NULL) { printf("|%12s",cursor->type);}
			else { printf("|%14s"," "); }
			printf("|%9d",cursor->cst);
			printf("|%8d|\n",cursor->taille);
			cursor=cursor->svt;
			tmp++;
		}
	}
	printf("\n\n");
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

int Inserer(char* nom, char* code, char* type, int taille)
{
	if ( fin_dec ) return 0;
	Element_TS* found = Rechercher(nom);
	if  (found!=NULL)
	{
		printf("\nL%2d C2%d | ERREUR SEMANTIQUE: Variable %s doublement declaree!",nbligne,nbcolonne,nom);
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
			TS->cst=type_const;
			TS->taille=taille;
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
			tmp->cst=type_const;
			tmp->taille=taille;
			tmp->svt=TS;
			TS=tmp;
		}
	}
	return 0;
}

void Inserer_LD( char * nom , int taille) {
	//printf("\nvar: %s ",nom);
	if ( LD == NULL ) {
		LD = (Element_List_Dec *) malloc(sizeof(Element_List_Dec));
		LD->nom=strdup(nom);
		LD->taille=taille;
		LD->svt=NULL;
	} else {
		Element_List_Dec* tmp = (Element_List_Dec*)malloc(sizeof(Element_List_Dec));
		tmp->nom=strdup(nom);
		LD->taille=taille;
		tmp->svt=LD;
		LD=tmp;
	}
}

void Vider_LD() {
	while (LD!=NULL) {
		int taille=1;
		if (LD->taille!=-1) taille=LD->taille;
		Inserer(LD->nom,"idf",type_courant,taille);
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
