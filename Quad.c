#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Quad
{
	char* champ1;
	char* champ2;
	char* champ3;
	char* champ4;
	int position;
	struct Quad * svt;

}Quad;

Quad* Tete_quad=NULL;
int position_Qc=0;

Quad* Rechercher_Quad(Quad* Tete_quad,Quad* Qc)
{
	if ( Tete_quad ==NULL)
	{
		printf("\nListe quadruplets vide\n");
		return NULL;
	}
	else
	{
		Quad* Cursor=Tete_quad;
		while( Cursor!=NULL)
		{
			if ( Cursor == Qc)
			{
				return 
			}
		}

	}


}

/* NOTE: si necessaire ndirha treturni Quad* Tete_quad */
void InsererQuad(Quad* Tete_quad,char* Ch1,char* Ch2, char* Ch3,char* Ch4)
{
		Quad* Cursor=Tete_quad;
		Quad* tmp_Qc=(Quad*)malloc(sizeof(Quad));
		tmp_Qc->champ1=(char*) malloc(sizeof(char)*strlen(Ch1));
		tmp_Qc->champ2=(char*) malloc(sizeof(char)*strlen(Ch2));
		tmp_Qc->champ3=(char*) malloc(sizeof(char)*strlen(Ch3));
		tmp_Qc->champ4=(char*) malloc(sizeof(char)*strlen(Ch4));
		strcpy(tmp_Qc->champ1,Ch1);
		strcpy(tmp_Qc->champ2,Ch2);
		strcpy(tmp_Qc->champ3,Ch3);
		strcpy(tmp_Qc->champ4,Ch4);
		tmp_Qc->position=position_Qc;
		position_Qc++;

	if ( Cursor==NULL)
	{
		Cursor=tmp_Qc;
		Cursor->svt=NULL;
		Tete_quad=Cursor;
	}
	else
	{
		Cursor=tmp_Qc;
		Cursor->svt=Tete_quad;
		Tete_quad=Cursor;
	}
}