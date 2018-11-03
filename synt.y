%{
#include <stdio.h>
int nbligne=1;
int yylex();
int yyerror(char *s);
%}

%token mc_pgm mc_integer mc_real mc_const
       bib_calcul bib_tab bib_boucle
       op_aff sp_var
       id val_entiere val_reelle
       '{' '}' ',' ';' '+' '*' '/' '-' '[' ']'

%%

//////////////////////////////////// Structure general ////////////////////////////////////
S : BIBL mc_pgm id '{' NDEC INST '}' {printf("\nLe programme marche correctement\n");}
;

BIBL : bib_calcul BIBL {printf("\nbib calcul");}
     | bib_tab BIBL {printf("\nbib tab");}
     | bib_boucle BIBL {printf("\nbib tab");}
     | {printf("\nbib calcul");}
;

//////////////////////////////////// Declaration part ////////////////////////////////////
NDEC : DEC MOREDEC {printf("\nBLOCK DECLARATION END");}
;

MOREDEC : NDEC {printf("\nMORE DECLARATIONS");}
	|  {printf("\nEND OF DECLARATIONS");}
;

DEC : TYPE NVAR ';' {printf("\nDECLARATION LINE");}
;

NVAR : VAR MOREVAR {printf("\nLIST OF VARS");}
;

MOREVAR : sp_var NVAR {printf("\nMORE VARIABLES");}
	|  {printf("\nEND OF LIST VAR DEC");}
;

VAR : id INDEX  {printf("\n VARIABLE");}
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
     | INST_BCL MOREINST {printf("\nINST BOUCLE");}
;

MOREINST : INST {printf("\nTHERE IS MORE INST");}
	 | {printf("\nNO MORE INST");}
;

INST_AFF: VAR op_aff EXP1 ';' {printf("\nAFFECTATION");}
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

INST_BCL : '{' '{' {printf("\nINST BOUCLE");}
;
      
%%
int main()
{yyparse();}

int yywrap()
{return 1;}

int yyerror(char *msg) 
{printf("\nERREUR SYNTAXIQUE : a la ligne %d\n",nbligne);	return 1;}
