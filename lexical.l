// Importing external dependencies
%{
#include <stdio.h>
#include "synt.tab.h"
extern YYSTYPE yylval;
extern  int nbligne;
extern  int nbmot;
%}

// Setting regular expressions
idf [A-Z][A-Za-z0-9]*
taille [1-9][0-9]*

%%
// Catching libraries names
#CALCUL return bib_calcul;
#TAB return bib_tab;
#BOUCLE return bib_boucle;

// Catching key words
PROGRAMME return mc_pgm;
INTEGER return mc_integer;
REAL return mc_real;

// Catching variables and constants
{idf}	{ if( yyleng <12) {return id; 
           }
          else {printf("Erreur Lexicale: Taille idf > 12 \n");
         }
       }
{taille} { if ( yyleng>0){ return taille_tab;}
			else{
					printf("Erreur Lexicale: Taille de tableau doit être positive");
				}
			}       

// Catching symboles and operators
:= return op_aff;
[{},;+*/-] return yytext[0];
[ \t]
\n {nbligne++;}
. printf("Erreur lexicale");

%%
