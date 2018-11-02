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
S : BIBL mc_pgm id '{' NDEC NINST '}' {printf("\nLe programme marche correctement\n");}
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

TYPE: mc_integer
    | mc_real	
;

//////////////////////////////////// Instruction part ////////////////////////////////////
NINST: INST MOREINST
;

MOREINST : NINST
	 |
;

INST : INST_AFF
     |
;

INST_AFF: id op_aff EXP ';'
;

EXP: id OP EXP
   | id
;

OP: '+'
   |'-'
   |'*'
   |'/'
; 

      
%%
int main()
{yyparse();}

int yywrap()
{return 1;}

int yyerror(char *msg) 
{printf("Erreur syntaxique : a la ligne %d\n",nbligne);	return 1;}
