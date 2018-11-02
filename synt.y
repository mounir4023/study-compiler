%{
#include <stdio.h>
int nbligne=1;
int yylex();
int yyerror(char *s);
%}

%token mc_pgm id '{' '}' bib_calcul bib_tab bib_boucle
mc_integer mc_real ',' ';' aff '+' '*' '/' '-' '[' ']' taille_tab
%%

S:  BIBL mc_pgm id '{' NDEC INST '}' {printf("Programme marche correctement\n");}
;

INST: INST_AFF
      |
;
INST_AFF: id aff EXP ';'
;
EXP: id OP EXP
    |id
;

OP: '+'
   |'-'
   |'*'
   |'/'
; 

BIBL : bib_calcul BIBL
      |bib_tab BIBL
      |bib_boucle BIBL
      |
;
NDEC : DEC NDEC
	  | DEC	
;
DEC : TYPE LISTE_VARIABLES ';'
	 | TYPE  TAB ';'
;
TYPE: mc_integer
	 | mc_real	
;
LISTE_VARIABLES: id ',' LISTE_VARIABLES
                |id
;
TAB :id '[' taille_tab ']'
;
      
%%
int main()
{yyparse();}

int yywrap()
{return 1;}

int yyerror(char *msg)
{
printf("Erreur syntaxique : a la ligne %d\n",nbligne);
return 1;
}