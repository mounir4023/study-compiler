%{
#include <stdio.h>
#include "synt.tab.h"
extern YYSTYPE yylval;
extern  int nbligne;
int nbcolonne=1;
extern  int nbmot;
extern YYSTYPE yylval;
%}

regex_idf [A-Z][A-Za-z0-9]*
regex_entier [0-9]+
regex_decimal [0-9]+\.[0-9]+
regex_commentaire "//"(.*|[\r\n])*"//"
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
\n {nbligne++; nbcolonne=1; }

#CALCUL 	{ nbcolonne=nbcolonne+yyleng; return bib_calcul;}
#TAB 		{ nbcolonne=nbcolonne+yyleng; return bib_tab;}
#BOUCLE 	{ nbcolonne=nbcolonne+yyleng; return bib_boucle;}

PROGRAMME 	{ nbcolonne=nbcolonne+yyleng; return mc_pgm;}
INTEGER 	{ nbcolonne=nbcolonne+yyleng; return mc_integer;}
REAL 		{ nbcolonne=nbcolonne+yyleng; return mc_real;}
CONST 		{ nbcolonne=nbcolonne+yyleng; return mc_const;}
EXECUTE 	{ nbcolonne=nbcolonne+yyleng; return mc_exec;}
IF 			{ nbcolonne=nbcolonne+yyleng; return mc_if;}
WHILE 		{ nbcolonne=nbcolonne+yyleng; return mc_while;}

{regex_entier} 	{ nbcolonne=nbcolonne+yyleng; yylval.entier=atoi(yytext); return val_entiere; }
{regex_decimal} { nbcolonne=nbcolonne+yyleng; yylval.real=atof(yytext); return val_reelle; }
{regex_aff} 	{ nbcolonne=nbcolonne+yyleng; return sb_aff; }
{regex_eg} 		{ nbcolonne=nbcolonne+yyleng; return sb_eg; }
{regex_diff} 	{ nbcolonne=nbcolonne+yyleng; return sb_diff; }
{regex_sup} 	{ nbcolonne=nbcolonne+yyleng; return sb_sup; }
{regex_supeg} 	{ nbcolonne=nbcolonne+yyleng; return sb_supeg; }
{regex_inf} 	{ nbcolonne=nbcolonne+yyleng; return sb_inf; }
{regex_infeg} 	{ nbcolonne=nbcolonne+yyleng; return sb_infeg; }
{regex_sp} 		{ nbcolonne=nbcolonne+yyleng; return sp_var; }
{regex_commentaire} 	{nbcolonne=nbcolonne+yyleng;}
{regex_idf}		{ nbcolonne=nbcolonne+yyleng; yylval.chaine=strdup(yytext); return id; }
. printf("\nERREUR LEXICALE: caractere inconnu : %s ! LIGNE : %d COLONNE : %d\n",yytext,nbligne,nbcolonne);

%%
