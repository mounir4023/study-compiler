#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
		int tmp = 1;
		cursor=TS;
		printf("\n==================== Table de Symbole ====================\n");
		printf("|Nom Entitée  | Code Entitée | Type Entitée | CST | POSITION |\n");
		while(cursor!=NULL)
		{
			printf("\n Iteration N° %d\n",tmp);
			printf("|%s",cursor->nom);
			printf("|%s",cursor->code);
			if (cursor->type !=NULL) { printf("|%s",cursor->type);}
			else { printf("|        "); }
			printf("|%d",cursor->cst);
			printf("|%d\n",cursor->position);
			cursor=cursor->svt;
			tmp++;
		}
	}
}


Element_TS* Rechercher(char* nom)
{
	Element_TS* curseur=TS;
	while(curseur !=NULL)
	{
		if ( strcmp(curseur->nom,nom)==0) return curseur;
		curseur=curseur->svt;
	}
	return NULL;
} 

int Inserer(char* nom,char* code)
{
	printf("\nDebut insertion: nom= %s code= %s\n",nom,code);
	Element_TS* found=Rechercher(nom);
	if  (found!=NULL)
	{
		printf("\nSearch results: %s\n",found->nom);
		if (strcmp(found->code,"idf")==0){
			printf("\nDouble déclaration de la variable %s\n",nom );
			//Erreur Double declared IDF
			return -1;	
		}
	}
	else
	{
		printf("\nSearch results: NULL\n");
		if ( TS==NULL)
		{
			printf("\nTS is empty: have to malloc\n");
			TS=(Element_TS*)malloc(sizeof(Element_TS));
			//printf("malloc %d\n",TS);
			TS->nom=(char*) malloc(sizeof(char)*strlen(nom));
			strcpy(TS->nom,nom);
			printf("name copied: %s\n",TS->nom);
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
			printf("%p %p\n",tmp,TS );
		}
		//Insertion réussie
		return 0;

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

/*int nb_sauts_ligne(char * s) {
	return strcpt(s,'\n');
}*/
