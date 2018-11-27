#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Element_Quad {
	char * operateur;
	char * opd_1;
	char * opd_2;
	char * resultat;
	int num;
	struct Element_Quad * svt;
} Element_Quad;

Element_Quad* Tete_Q=NULL; 
int Num_Qc=0;
int Cpt_temp=0;

void Ajouter_Quad(char* operateur,char* opd_1,char* opd_2,char* resultat){

	if ( Tete_Q==NULL){

		Tete_Q=(Element_Quad*)malloc(sizeof(Element_Quad));
		Tete_Q->operateur=(char*) malloc(sizeof(char)*strlen(operateur));
		Tete_Q->opd_1=(char*) malloc(sizeof(char)*strlen(opd_1));
		Tete_Q->opd_2=(char*) malloc(sizeof(char)*strlen(opd_2));
		Tete_Q->resultat=(char*) malloc(sizeof(char)*strlen(resultat));
		strcpy(Tete_Q->operateur,operateur);
		strcpy(Tete_Q->opd_1,opd_1);
		strcpy(Tete_Q->opd_2,opd_2);
		strcpy(Tete_Q->resultat,resultat);
		Tete_Q->num=Num_Qc;
		Num_Qc++;
		Tete_Q->svt=NULL;
	}
	else{
		Element_Quad* Tmp=(Element_Quad*)malloc(sizeof(Element_Quad));
		Tmp->operateur=(char*) malloc(sizeof(char)*strlen(operateur));
		Tmp->opd_1=(char*) malloc(sizeof(char)*strlen(opd_1));
		Tmp->opd_2=(char*) malloc(sizeof(char)*strlen(opd_2));
		Tmp->resultat=(char*) malloc(sizeof(char)*strlen(resultat));
		strcpy(Tmp->operateur,operateur);
		strcpy(Tmp->opd_1,opd_1);
		strcpy(Tmp->opd_2,opd_2);
		strcpy(Tmp->resultat,resultat);
		Tmp->num=Num_Qc;
		Num_Qc++;
		Tmp->svt=Tete_Q;
		Tete_Q=Tmp;
	}
} 


void Affichage_Quad(){

	Element_Quad* cursor;
	if ( Tete_Q==NULL)
	{
		printf("\n==================== Quadruplet  ====================\n");
		printf("==================== ///// Vide ///// ====================\n");
	}
	else
	{
		cursor=Tete_Q;
		printf("\n======================= Quadruplet ==========================\n");
		printf("-------------------------------------------------------------\n");
		printf("|     Operateur    |   Opd_1   |   Opd_2   | Resultat | Qc |\n");
		printf("-------------------------------------------------------------\n");
		while(cursor!=NULL)
		{
			printf("|%18s",cursor->operateur);
			printf("|%11s",cursor->opd_1);
			printf("|%11s",cursor->opd_2);
			printf("|%10s",cursor->resultat);
			printf("|%4d|\n",cursor->num);
			cursor=cursor->svt;
		}
	}
	printf("\n\n");
}

typedef struct Pile_If {
	int numQc;
	struct Pile_If * svt;
} Pile_If;

Pile_If* Tete_Pile_If=NULL; 

void empiler_if( int numQuad){
	if ( Tete_Pile_If==NULL){
		Tete_Pile_If=(Pile_If*)malloc(sizeof(Pile_If));
		Tete_Pile_If->numQc=numQuad;
		Tete_Pile_If->svt=NULL;
	}
	else{
		Pile_If* tmp=(Pile_If*)malloc(sizeof(Pile_If));
		tmp->numQc=numQuad;
		tmp->svt=Tete_Pile_If;
		Tete_Pile_If=tmp;
	}
}

int depiler_if(){
	printf("h11\n");
	if ( Tete_Pile_If!=NULL){
		int tmp=Tete_Pile_If->numQc;
		printf("h1\n");
		if ( Tete_Pile_If->svt != NULL)
		{
			Tete_Pile_If=Tete_Pile_If->svt;
			printf("h2\n");
		}
		else{
			Tete_Pile_If=NULL;
			printf("h3\n");
		}
		printf("h4\n");
		return tmp;
	}
	return -1;
}
void MAJ_quad_if( int numQuad,int adr){
	Element_Quad* cursor=Tete_Q;
	while(cursor!=NULL){
		if( cursor->num==numQuad){
			char t[10]; sprintf(t,"%d",adr);
			cursor->opd_1=(char*) malloc(sizeof(char)*strlen(t));
			strcpy(cursor->opd_1,t);
		}
	}
}