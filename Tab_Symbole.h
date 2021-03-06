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

void maj_nb_ligne(char * com ) {
    for ( int i; i < strlen(com) ; i ++ ) if (com[i]=='\n') nbligne++;
}

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
		printf("\n================ Table de Symbole =================\n");
		printf("---------------------------------------------------\n");
		printf("|     Nom    |   Code   |   Type   | CST | TAILLE |\n");
		printf("---------------------------------------------------\n");
		while(cursor!=NULL)
		{
			printf("|%12s",cursor->nom);
			printf("|%10s",cursor->code);
			if (cursor->type !=NULL) { printf("|%10s",cursor->type);}
			else { printf("|%12s"," "); }
			printf("|%5d",cursor->cst);
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

int get_taille(char* nom) {
	Element_TS * var = Rechercher(nom);
	if ( var == NULL ) return 0;
	return var->taille;
}

void Inserer_LD(char * nom , int taille) {
	if ( LD == NULL ) {
		LD = (Element_List_Dec *) malloc(sizeof(Element_List_Dec));
		LD->nom=strdup(nom);
		LD->taille=taille;
		LD->svt=NULL;
	} else {
		Element_List_Dec* tmp = (Element_List_Dec*)malloc(sizeof(Element_List_Dec));
		tmp->nom=strdup(nom);
		tmp->taille=taille;
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
		printf("\t%s[%d]",tmp->nom,tmp->taille);
		tmp=tmp->svt;
	}
	printf(" )");
}

int getNature(char* nom){
	//Si l'IDF est une var ou CST
	Element_TS* cursor = Rechercher(nom);
	int nature;
	if ( cursor != NULL)
	{
		nature=cursor->cst;
		return nature;
	}
	return -1;
}

char* getType(char* nom){
	Element_TS* cursor = Rechercher(nom);
	char* type;
	if ( cursor != NULL){
		type=cursor->type;
		return type;
	}
	return NULL;
}
