%{
#include <stdio.h>
#include "synt.tab.h"
extern YYSTYPE yylval;
extern  int nbligne;
extern  int nbmot;
%}

regex_idf [A-Z][A-Za-z0-9]*
regex_entier [0-9]+
regex_decimal [0-9]+.[0-9]+
regex_commentaire "//".*"//"
regex_aff ":="
regex_sp "||"

%%
[{},;+*/-] return yytext[0];
\[ return yytext[0];
\] return yytext[0];
[ \t]
\n {nbligne++; printf("\n\n Line %d",nbligne);}

#CALCUL return bib_calcul;
#TAB return bib_tab;
#BOUCLE return bib_boucle;

PROGRAMME return mc_pgm;
INTEGER return mc_integer;
REAL return mc_real;
CONST return mc_const;

{regex_entier} { return val_entiere; }
{regex_decimal} { return val_reelle; }
{regex_aff} { return op_aff; }
{regex_sp} { return sp_var; }
{regex_commentaire} 
{regex_idf}	{ return id; }
. printf("\nERREUR LEXICALE: caractere inconnu !\n");

%%
