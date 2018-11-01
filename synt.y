%{
#include <stdio.h>
int nbligne=1;	
%}
%token mc_pgm id '{' '}' bib_calcul bib_tab bib_boucle mc_integer ',' ';' aff '+' '*' '/' '-' 

%%

S: BIBL mc_pgm id '{' DEC INST '}' {printf("pgm correcte \n");}
;
INST : INST_AFF
;
INST_AFF : id aff EXP ';'
;
EXP: id OP EXP 
	| id
	;
OP: '+'
	| '*' 
	| '/' 
	| '-'
;	
BIBL :bib_calcul BIBL 
	|	 bib_tab BIBL 
	| bib_boucle BIBL
	|
;
DEC : TYPE LISTE_VARIABLES ';'
;
TYPE: mc_integer
;
LISTE_VARIABLES: id ',' LISTE_VARIABLES
				| id
;				
%%
main()
{
	yyparse();}
	yywrap()
{}
int yyerror(char *msg)
{
	printf("Erreur syntaxique a la ligne %d",nbligne);
}