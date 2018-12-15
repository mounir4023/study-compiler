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
int Cpt_ttemp=0;
int I;

void Traiter_Elmt(Element_Quad* cursor,Element_Quad* child,Element_Quad* parent);
void MAJ_Qc(int i);

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
			break;
		}
		cursor=cursor->svt;
	}
}
void make_condWhile_quad( char * str,char * t){
						if ( strcmp(str,"==")==0){
                            Ajouter_Quad("BNE","","",t);
                        }
                        if ( strcmp(str,"!=")==0){
                            Ajouter_Quad("BE","","",t);
                        }
                        if ( strcmp(str,"<")==0){
                            Ajouter_Quad("BGE","","",t);
                        }
                        if ( strcmp(str,"<=")==0){
                            Ajouter_Quad("BG","","",t);
                        }
                        if ( strcmp(str,">")==0){
                            Ajouter_Quad("BLE","","",t);
                        }
                        if ( strcmp(str,">=")==0){
                            Ajouter_Quad("BL","","",t);
                        }
}

typedef struct Pile_While {
    int numQc;
    struct Pile_While * svt;
} Pile_While;

Pile_While* Tete_Pile_While=NULL; 

void empiler_while( int numQuad){
    if ( Tete_Pile_While==NULL){
        Tete_Pile_While=(Pile_While*)malloc(sizeof(Pile_While));
        Tete_Pile_While->numQc=numQuad;
        Tete_Pile_While->svt=NULL;
    }
    else{
        Pile_While* tmp=(Pile_While*)malloc(sizeof(Pile_While));
        tmp->numQc=numQuad;
        tmp->svt=Tete_Pile_While;
        Tete_Pile_While=tmp;
    }
}

int depiler_while(){
    //printf("h11\n");
    if ( Tete_Pile_While!=NULL){
        Pile_While* current=Tete_Pile_While;
        int tmp=current->numQc;
        if ( current->svt != NULL)
        {

            Tete_Pile_While=current->svt;
        }
        else{

            Tete_Pile_While=NULL;
        }
        free(current);
        return tmp;
    }
    return -1;
}
void MAJ_quad_while( int numQuad,int adr){
    Element_Quad* cursor=Tete_Q;
    while(cursor!=NULL){
        if( cursor->num==numQuad){
            char t[10]; sprintf(t,"%d",adr);
            cursor->opd_1=(char*) malloc(sizeof(char)*strlen(t));
            strcpy(cursor->opd_1,t);
            break;
        }
        cursor=cursor->svt;
    }
}


///////////////// Optimisation //////////////////////

void Chercher_Elmt(){

	Element_Quad * cursor;
	Element_Quad * parent;
	Element_Quad * child;
	if ( Tete_Q==NULL)
	{
		printf("\n==================== Quadruplet Optimiser  ====================\n");
		printf("==================== ///// Vide ///// ====================\n");
	}
	else
	{
		int x;
		cursor=Tete_Q;
		parent=cursor; 
		child=NULL;
		while(cursor!=NULL){

			child=cursor->svt;
			if ( strcmp(cursor->operateur,"*") == 0 ){
				Traiter_Elmt(cursor,child,parent);
				if ( x>2){
					MAJ_Qc(I);
				}
				
			}
			
			parent=cursor;
			cursor=child;
		}
		

	}
}

void Traiter_Elmt(Element_Quad* cursor,Element_Quad* child,Element_Quad* parent){
	
	char * opd;
	int x,y;
	if ( atoi(cursor->opd_1)<atoi(cursor->opd_2)){
		x=atoi(cursor->opd_1);
		y=1;
		opd=cursor->opd_2;
	}
	else{
		x=atoi(cursor->opd_2);
		y=2;
		opd=cursor->opd_1;
	}

	// Dans le cas où a*2 ou bien a*1
	if ( x<=2 ){
		if ( x == 2){
			cursor->operateur="+";
			if ( y == 1){
				cursor->opd_1=cursor->opd_2;
			}
			else
			{
				cursor->opd_2=cursor->opd_1;
			}
		}
		else{
			cursor->operateur="+";
			if ( y == 1){
				cursor->opd_1="0";
			}
			else
			{
				cursor->opd_2="0";
			}
		}
	}
	else{
			
			Element_Quad* tmp;
			Element_Quad * sauvTmp;
			char m[10];
			sprintf(m,"Tt%d",Cpt_ttemp);
			//printf("7\n");
			tmp=(Element_Quad*)malloc(sizeof(Element_Quad));
			tmp->svt=child;
			sauvTmp=tmp;
			tmp->operateur=(char*) malloc(sizeof(char)*strlen("+"));
			tmp->opd_1=(char*) malloc(sizeof(char)*strlen(opd));
			tmp->opd_2=(char*) malloc(sizeof(char)*strlen(opd));
			tmp->resultat=(char*) malloc(sizeof(char)*strlen(m));
			//printf("8\n");
			strcpy(tmp->operateur,"+");
			strcpy(tmp->opd_1,opd);
			strcpy(tmp->opd_2,opd);
			strcpy(tmp->resultat,m);
			//printf("9\n");
			Cpt_ttemp++;
			for (int i=2;i<x;i++){
				tmp=(Element_Quad*)malloc(sizeof(Element_Quad));
				tmp->svt=sauvTmp;
				sauvTmp=tmp;
				tmp->operateur=(char*) malloc(sizeof(char)*strlen("+"));
				tmp->opd_1=(char*) malloc(sizeof(char)*strlen(opd));
				tmp->opd_2=(char*) malloc(sizeof(char)*strlen(m));
				strcpy(tmp->opd_2,m);
				Cpt_ttemp++;
				sprintf(m,"Tt%d",Cpt_ttemp);
				tmp->resultat=(char*) malloc(sizeof(char)*strlen(m));
				strcpy(tmp->operateur,"+");
				strcpy(tmp->opd_1,opd);
				if ( i == (x-1)){
					strcpy(tmp->resultat,cursor->resultat);
					//tmp->svt=NULL;
				}else{
					strcpy(tmp->resultat,m);
				}
			}
			Cpt_ttemp++;
			parent->svt=tmp;
			I=x-1;
			
	}
}
void MAJ_Qc(int x){
	Element_Quad* cursor;
	Element_Quad* parent;
	cursor=Tete_Q;
	int Qc_prec;
	while(cursor!=NULL){
		
			if ( cursor->num!=0){
				cursor->num=cursor->num+x-1;
				Qc_prec=cursor->num;
			}else{
				while(cursor!=NULL && cursor->num==0){
					cursor->num=(Qc_prec-1);
					Qc_prec=cursor->num;
					cursor=cursor->svt;
				}
				break;
			}

		cursor=cursor->svt;
			
		}
		cursor=Tete_Q;
		while(cursor!=NULL){
			if ( strcmp(cursor->operateur,"BNE")==0 || strcmp(cursor->operateur,"BE")==0 || strcmp(cursor->operateur,"BGE")==0 || strcmp(cursor->operateur,"BG")==0 || strcmp(cursor->operateur,"BLE")==0 || strcmp(cursor->operateur,"BL")==0)
		{
			int y=atoi(cursor->opd_1);
			y=y+x-1;
			char t[10];
			sprintf(t,"%d",y);
			strcpy(cursor->opd_1,t);
		}
		cursor=cursor->svt;
		}
		
	

}