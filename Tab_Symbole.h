#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	printf("\nRechercher: %s",nom);
	Element_TS* curseur=TS;
	while(curseur !=NULL)
	{
		if ( strcmp(curseur->nom,nom)==0) return curseur;
		curseur=curseur->svt;
	}
	return NULL;
} 

int Inserer(char* nom, char* code)
{
	//printf("\nDebut insertion: nom= %s code= %s\n",nom,code);
	printf("\nInserrer TS: %s %s",nom,code);
	Element_TS* found=Rechercher(nom);
	if  (found!=NULL)
	{
		//printf("\nSearch results: %s\n",found->nom);
		if (strcmp(found->type,"idf")==0){
			//Erreur Double declared IDF
			printf("\nDouble déclaration de la variable s\n",nom);
			return -1;	
		}
	}
	else
	{
		//printf("\nSearch results: NULL\n");
		if ( TS==NULL)
		{
			//printf("\nTS is empty: have to malloc\n");
			TS=(Element_TS*)malloc(sizeof(Element_TS));
			//printf("malloc %d\n",TS);
			TS->nom=(char*) malloc(sizeof(char)*strlen(nom));
			strcpy(TS->nom,nom);
			//printf("name copied: %s\n",TS->nom);
			TS->code=(char*) malloc(sizeof(char)*strlen(code));
			strcpy(TS->code,code);
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
			tmp->position=positionEntite;
			positionEntite++;
			tmp->svt=TS;
			TS=tmp;
			//printf("%p %p\n",tmp,TS );
		}
		//Insertion réussie
		return 0;
	}
}

void Inserer_LD( char * nom ) {
	printf("\nLD: %s",nom);
	if ( LD == NULL ) {
		LD = (Element_List_Dec *) malloc(sizeof(Element_List_Dec));
		LD->nom=strdup(nom);
	} else {
		Element_List_Dec* tmp = (Element_List_Dec*)malloc(sizeof(Element_List_Dec));
		tmp->nom=strdup(nom);
		tmp->svt=LD;
		LD=tmp;
	}
}

void Vider_LD() {
	while (LD!=NULL) {
		printf("\nVider: %s %s",LD->nom,type_courant);
		Inserer(LD->nom,type_courant);
		LD=LD->svt;
	}
	LD=NULL;
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
