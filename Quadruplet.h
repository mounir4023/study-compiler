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