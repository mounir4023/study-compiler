%{
#include <stdio.h>
#include "Tab_Symbole.h"
int nbligne=1;
int yylex();
int yyerror(char *s);
int Bib_Calcule=0,Bib_Boucle=0,Bib_tab=0;
%}

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
			/*Inserer("ihab","mc_cle");*/
			Bib_Calcule=1; 
		} else {
			 printf("\nBibliotheque deja déclarée");
		} 
	 }
;

TAB : bib_tab { 
    	if (Bib_tab==0) {
		Bib_tab=1;
		/*Inserer("ihab","mc_cle");*/
	} else { 
		printf("\nBibliotheque deja déclarée"
	}
      }
;

BOUCLE : bib_boucle { 
       		if (Bib_Boucle==0) { 
			Bib_Boucle=1;
		} else {
		printf("\nBibliotheque deja déclarée"
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

NVAR : VAR MOREVAR {printf("\nLIST OF VARS");}
;

MOREVAR : sp_var NVAR {printf("\nMORE VARIABLES");}
	|  {printf("\nEND OF LIST VAR DEC");}
;

VAR : id INDEX  {printf("\nVARIABLE");}
;

INDEX : '[' val_entiere ']' {printf("\nINDEX");}
      | {printf("\nNO INDEX");}
;

TYPE : mc_integer {printf("\nINTEGER DECLARE");}
     | mc_real	 {printf("\nREEL DECLARE");}
;

CST : val_entiere {printf("\nVAL ENTIERE");}
    | val_reelle {printf("\nVAL REELLE");}
;

//////////////////////////////////// Instruction part ////////////////////////////////////

INST : INST_AFF MOREINST {printf("\nINST AFFECTATION");}
     | INST_IF MOREINST {printf("\nINST BOUCLE");}
     | INST_WHL MOREINST {printf("\nINST WHILE");}
;

MOREINST : INST {printf("\nTHERE IS MORE INST");}
	 | {printf("\nNO MORE INST");}
;

INST_AFF: VAR sb_aff EXP1 ';' {printf("\nAFFECTATION");}
;

EXP1 : EXP2 '+' EXP1 {printf("\nTERM D AFFECTATION");}
     | EXP2 '-' EXP1 {printf("\nTERM D AFFECTATION");}
     | EXP2 {printf("\nTERM D AFFECTATION");}
;

EXP2 : EXP3 '*' EXP2 {printf("\nTERM D ADDITION");}
     | EXP3 '/' EXP2 {printf("\nTERM D ADDITION");}
     | EXP3 {printf("\nTERM D ADDITION");}
;

EXP3 : VAR  {printf("\nVAR IN AFFECTATION");}
     | CST {printf("\nCST IN AFFECTATION");}
;

INST_IF : mc_exec INST mc_if '(' COND ')' {printf("\n\n\n === IF STATEMENT ====\n");}
;

INST_WHL : mc_while '(' COND ')' '{' INST '}' {printf("\n\n\n === WHILE LOOP ====\n");}
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
 Inserer("ihab","idf"); 
 AfficherTS(TS);
}

int yywrap()
{return 1;}

int yyerror(char *msg) 
{printf("\nERREUR SYNTAXIQUE : a la ligne %d\n",nbligne);	return 1;}
