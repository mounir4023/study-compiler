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

BIBL : bib_calcul BIBL
     | bib_tab BIBL
     | bib_boucle BIBL
     |
;

//////////////////////////////////// Declaration part ////////////////////////////////////
NDEC : DEC MOREDEC
;

MOREDEC : NDEC
	| 
;

DEC : TYPE NVAR ';'
;

NVAR : VAR MOREVAR
;

MOREVAR : sp_var NVAR
	| 
;

VAR : id INDEX 
;

INDEX : '[' val_entiere ']'
      |
;

TYPE : mc_integer
     | mc_real	
;

CST : val_entiere
    | val_reelle
;

//////////////////////////////////// Instruction part ////////////////////////////////////

INST : INST_AFF MOREINST
     | INST_BCL MOREINST
;

MOREINST : INST
	 |
;

INST_AFF: VAR op_aff EXP1 ';'
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

INST_BCL : '{' '{'
;
      
%%
int main()
{yyparse();}

int yywrap()
{return 1;}

int yyerror(char *msg) 
{printf("ERREUR SYNTAXIQUE : a la ligne %d\n",nbligne);	return 1;}
