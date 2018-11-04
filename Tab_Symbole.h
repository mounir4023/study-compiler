#include<stdio.h>
#include<stdlib.h>
typedef struct Element_TS
{
	char *nom;
	char *code;
	char* type;
	int cst;
	struct Element_TS * svt;

}Element_TS;

Element_TS* TS=NULL;

Element_TS* Rechercher(char* nom)
{
	Element_TS* curseur=TS;
	while(curseur !=NULL)
	{
		if ( strcmp(curseur->nom,nom)==1) return curseur;
	}
	return NULL;
} 

int Inserer(char* nom,char* code)
{
	if  (Rechercher(nom)!=NULL)
	{
		if (strcmp(code,"idf")==1){
			printf("\nDouble déclaration de la variable %s\n",nom );	
		}
	}
	else
	{
		if ( TS==NULL)
		{
			TS=(Element_TS*)malloc(sizeof(Element_TS));
			strcpy(nom,TS->nom);
			strcpy(code,TS->code);
			TS->svt=NULL;
		}
		else
		{
			Element_TS* tmp = (Element_TS*)malloc(sizeof(Element_TS));
			strcpy(nom,tmp->nom);
			strcpy(code,tmp->code);
			tmp->svt=TS;
			TS=tmp;
		}

	}
}

int nb_sauts_ligne(char * s) {
	return strcpt(s,'\n');
}