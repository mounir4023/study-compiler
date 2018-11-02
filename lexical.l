%{
#include <stdio.h>
#include "synt.tab.h"
extern YYSTYPE yylval;
extern  int nbligne;
extern  int nbmot;
%}

regex_idf [A-Z][A-Za-z0-9]*
regex_decimal [0-9]*.[0-9]*
regex_entier [0-9]*
regex_commentaire "//".*"//"

%%
#CALCUL return bib_calcul;
#TAB return bib_tab;
#BOUCLE return bib_boucle;

PROGRAMME return mc_pgm;
INTEGER return mc_integer;
REAL return mc_real;
CONST return mc_const;

{regex_entier} { return val_entiere; }
{regex_decimal} { return val_reelle; }
{regex_commentaire} 
{regex_idf}	{ 
	if ( yyleng <12 ) return id;
	else printf("ERREUR LEXICALE: identificateur trop long !\n");
}

":=" return op_aff;
"||" return sp_var;
[{},;+*/-] return yytext[0];
[ \t]
\n {nbligne++;}
. printf("ERREUR LEXICALE: caractere inconnu !\n");

%%
