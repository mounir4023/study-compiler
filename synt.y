%{
#include <stdio.h>
#include "Tab_Symbole.h"
int nbligne=1;
extern int nbcolonne;
int typeIdf;
int Bib_Calcule=0,Bib_Boucle=0,Bib_tab=0;
int yylex();
int yyerror(char *s);
%}

%union{
char*  chaine;
}

%token mc_pgm mc_integer mc_real mc_const mc_if mc_while mc_exec
       bib_calcul bib_tab bib_boucle
       sb_eg sb_diff sb_inf sb_infeg sb_sup sb_supeg
       sb_aff sp_var
       id val_entiere val_reelle
       '{' '}' ',' ';' '+' '*' '/' '-' '[' ']' '(' ')'

%%

//////////////////////////////////// Structure general ////////////////////////////////////
S : BIBL mc_pgm id '{' DEC INST '}' { printf("\nLe programme marche correctement\n"); }
;

BIBL : CALCUL BIBL     
     | TAB BIBL        
     | BOUCLE BIBL 
     | 
;

//////////////////////////////// Règles bibliothèques  ///////////////////////////////////////

CALCUL : bib_calcul { 
       		                   if (Bib_Calcule==0) { 
                                                			Inserer("bib_calcul","mc_cle");
                                                			Bib_Calcule=1; 
                                              		} else {
                                              			 printf("\nBibliotheque deja déclarée");
                                              		} 
	                   }
;

TAB : bib_tab { 
    	                 if (Bib_tab==0) {
		                                        Bib_tab=1;
		                                        Inserer("bib_tab","mc_cle");
	                                     } else { 
		                                                printf("\nBibliotheque deja déclaée");
	                                     }
               }
;

BOUCLE : bib_boucle { 
       		             if (Bib_Boucle==0) { 
			                                       Bib_Boucle=1;
                                             Inserer("bib_boulce","mc_cle");
		                                      } else {
			                                               printf("\nBibliotheque deja declare");
	 	                                             }
      	            }
;

//////////////////////////////////// Declaration part ////////////////////////////////////
DEC : TYPE NVAR ';' MOREDEC 
     | TYPE mc_const NVAR ';' MOREDEC 
;

MOREDEC : DEC 
	|  
;

NVAR : VAR MOREVAR 
;

MOREVAR : sp_var NVAR 
	|  
;

VAR : id INDEX  { Inserer(TS,$1);}
;

INDEX : '[' val_entiere ']' 
      | 
;

TYPE : mc_integer   { typeIdf=0; /* 0 for integer */ }
     | mc_real	    { typeIdf=1; /*0 for real*/ }
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
{printf("\nERREUR SYNTAXIQUE : a la ligne %d\n",nbligne);	return 1;}
