%{
#include <stdio.h>
#include "synt.tab.h"
extern YYSTYPE yylval;
extern  int nbligne;
extern  int nbmot;
%}

regex_idf [A-Z][A-Za-z0-9]*
regex_entier [0-9]+
regex_decimal [0-9]+\.[0-9]+
regex_commentaire "//".*"//"
regex_aff ":="
regex_sp "||"
regex_eg "=="
regex_diff "!="
regex_sup ">"
regex_supeg ">="
regex_inf "<"
regex_infeg "=<"

%%
[{},;+*/-] return yytext[0];
\[ return yytext[0];
\] return yytext[0];
\( return yytext[0];
\) return yytext[0];
[ \t]
\n {nbligne++; printf("\n\n Line %d",nbligne);}

#CALCUL return bib_calcul;
#TAB return bib_tab;
#BOUCLE return bib_boucle;

PROGRAMME return mc_pgm;
INTEGER return mc_integer;
REAL return mc_real;
CONST return mc_const;
EXECUTE return mc_exec;
IF return mc_if;
WHILE return mc_while;

{regex_entier} { return val_entiere; }
{regex_decimal} { return val_reelle; }
{regex_aff} { return sb_aff; }
{regex_eg} { return sb_eg; }
{regex_diff} { return sb_diff; }
{regex_sup} { return sb_sup; }
{regex_supeg} { return sb_supeg; }
{regex_inf} { return sb_inf; }
{regex_infeg} { return sb_infeg; }
{regex_sp} { return sp_var; }
{regex_commentaire} 
{regex_idf}	{ return id; }
. printf("\nERREUR LEXICALE: caractere inconnu : %s !\n",yytext);

%%
