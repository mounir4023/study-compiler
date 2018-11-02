%{
#include <stdio.h>
#include "synt.tab.h"
extern  int nbligne;
%}
idf [A-Z][A-Za-z0-9]*
taille [1-9][0-9]*
%%
PROGRAMME return mc_pgm;
INTEGER return mc_integer;
REAL return mc_real;
#CALCUL return bib_calcul;
#TAB return bib_tab;
#BOUCLE return bib_boucle;
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
:= return aff;
[{},;+*/-] return yytext[0];
[ \t]
\n {nbligne++;}
. printf("Erreur lexicale");

%%