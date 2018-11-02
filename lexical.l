%{
#include <stdio.h>
#include "synt.tab.h"
extern  int nbligne;
%}
idf [A-Z][A-Za-z]*
%%
PROGRAMME return mc_pgm;
INTEGER return mc_integer;
#CALCUL return bib_calcul;
#TAB return bib_tab;
#BOUCLE return bib_boucle;
{idf}	{ if( yyleng <12) {return id; 
           }
          else {printf("Erreur lexicale idf >12");
         }
       }
:= return aff;
[{},;+*/-] return yytext[0];
[ \t]
\n {nbligne++;}
. printf("Erreur lexicale");

%%