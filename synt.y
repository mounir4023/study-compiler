%{
#include <stdio.h>
#include "Tab_Symbole.h"
//int nbligne=1;
//extern int nbcolonne;
//int fin_dec=0;
//int type_changes=0;
//int type_const=0;
int Bib_Calcule=0,Bib_Boucle=0,Bib_Tab=0;
int yylex();
int yyerror(char *s);
%}

%union{
char*  chaine;
int entier;
float real;
}

%token mc_pgm mc_integer mc_real mc_const mc_if mc_while mc_exec
       bib_calcul bib_tab bib_boucle
       sb_eg sb_diff sb_inf sb_infeg sb_sup sb_supeg
       sb_aff sp_var
       <chaine>id <entier>val_entiere <real>val_reelle
       '{' '}' ',' ';' '+' '*' '/' '-' '[' ']' '(' ')'

%%

//////////////////////////////////// Structure general ////////////////////////////////////
S : BIBL mc_pgm id '{' DEC INST '}' { printf("\n\nLe programme est syntaxiquement correct !\n"); }
;

BIBL : CALCUL BIBL     
     | TAB BIBL        
     | BOUCLE BIBL 
     | 
;

//////////////////////////////// Règles bibliothèques  ///////////////////////////////////////

CALCUL : bib_calcul { 
       		                   if (Bib_Calcule==0) { 
                                                			Inserer("CALCUL","mc","/",0);
                                                			Bib_Calcule=1; 
                                              		} else {
									printf("\nBibliotheque CALCUL deja déclarée");
                                              		} 
	                   }
;

TAB : bib_tab { 
    	                 if (Bib_Tab==0) {
		                                        	Bib_Tab=1;
			                                        Inserer("TAB","mc","/",0);
	                 } else { 
		                                                printf("\nBibliotheque TAB deja déclaée");
	                 }
               }
;

BOUCLE : bib_boucle { 
       		             if (Bib_Boucle==0) { 
								Bib_Boucle=1;
                                             			Inserer("BOUCLE","mc","/",0);
		              } else {
			                                        printf("\nBibliotheque BOUCLE deja declare");
	 	                                             }
      	            }
;

//////////////////////////////////// Declaration part ////////////////////////////////////
DEC : TYPE CONST NVAR ';' MOREDEC 
;

CONST: mc_const { type_const=1;  }
     | { type_const=0; }
;

MOREDEC : DEC 
	|  
	{
		fin_dec=1;
		//printf("\n\n\n =================== Fin de la partie declarations ==================");
	}
;

NVAR : VAR MOREVAR 
;

MOREVAR : sp_var NVAR 
	|  
	{
		//printf("\n==== Fin de la liste de declarations [type: %s , is const %d, vars: %d]", type_courant,type_const,nb_LD());
		Vider_LD();
		//printf("\n==== Fin deplacement LD= %d , elements= %d\n",LD,nb_LD()); 
	}
;

VAR : id INDEX  
    	{ 
		if( fin_dec == 0 ) {
			Inserer_LD($1,index_val);
			//printf("\nVar declaree: %s/%s taille: %d/%d",$1,LD->nom,index_val,LD->taille);
		} else {
			if ( Rechercher($1) == NULL ) {
				printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Variable %s non declaree !",nbligne,nbcolonne,$1);	
			}
			if (index_val ==-1 && get_taille($1) > 1) {
				printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Acces a un tableau sans preciser d indice !",nbligne,nbcolonne);
			} else if (index_val>get_taille($1)) {
				printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Depassement de la taille de tableau !",nbligne,nbcolonne);
			} else if (get_taille($1)==1 && index_val != -1 ) {
				printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Variable simple utilisee comme un tableau !",nbligne,nbcolonne);
			}
		}
	}
;

INDEX : '[' val_entiere ']' 
	{ 
		if(!Bib_Tab) printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Utilisation de tableau sans import de la biblioteque !",nbligne,nbcolonne);
		if (!fin_dec) {
			if($2==0) printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Declaration de tableau de taille egale a zero  !",nbligne,nbcolonne);
			if($2==1) printf("\nL%2d C%2d | AVERTISSEMENT: Le tableau de taille 1 a ete transforme en variable simple  !",nbligne,nbcolonne);
		}
		index_val = $2;
	}
      | 
	{
		index_val = -1;
	}
;

TYPE : mc_integer   { type_courant = strdup("INTEGER"); } 
     | mc_real	    { type_courant = strdup("REAL"); } 
;

CST : val_entiere 
    | val_reelle 
;

//////////////////////////////////// Instruction part ////////////////////////////////////

INST : INST_AFF MOREINST 
     | INST_IF MOREINST 
     | INST_WHL MOREINST 
;

MOREINST : INST 
	 | 
;

INST_AFF: VAR sb_aff EXP1 ';' 
	{
			if ( ! Bib_Calcule ) {
				printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Utilisation d'operations arithmetiques sans import de biblioteque !",nbligne,nbcolonne); 
			}
	}
;

EXP1 : EXP2 '+' EXP1 
     | EXP2 '-' EXP1 
     | EXP2 
;

EXP2 : EXP3 '*' EXP2 
     | EXP3 '/' EXP2 
     | EXP3 
;

EXP3 : VAR  
     | CST 
;

INST_IF : mc_exec INST mc_if '(' COND ')' 
;

INST_WHL : mc_while '(' COND ')' '{' INST '}'
	{
		if(!Bib_Boucle)  printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Utilisation de boucle sans import de la biblioteque !",nbligne,nbcolonne);
	}
;

COND : EXP1 COMPARATEUR EXP1
;

COMPARATEUR : sb_eg
	    | sb_diff
	    | sb_inf
	    | sb_infeg
	    | sb_sup
	    | sb_supeg
;
      
%%
int main()
{yyparse(); 
 AfficherTS(TS);
}

int yywrap()
{return 1;}

int yyerror(char *msg) 
{printf("\nL%2d C%2d | ERREUR SYNTAXIQUE",nbligne,nbcolonne);	return 1;}
