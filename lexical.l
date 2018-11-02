// Importing external dependencies
%{
#include <stdio.h>
#include "synt.tab.h"
extern YYSTYPE yylval;
extern  int nbligne;
extern  int nbmot;
%}

// Setting regular expressions
regex_idf [A-Z][A-Za-z0-9]*
regex_decimal [0-9]*.[0-9]*
regex_entier [0-9]*
regex_commentaire "//".*"//"

%%
// Catching libraries names
#CALCUL return bib_calcul;
#TAB return bib_tab;
#BOUCLE return bib_boucle;

// Catching key words
PROGRAMME return mc_pgm;
INTEGER return mc_integer;
REAL return mc_real;
CONST return mc_const;

// Catching variables and constants
{regex_idf}	{ if( yyleng <12) {return id; 
           }
          else {printf("Erreur Lexicale: Taille idf > 12 \n");
         }
       }
{regex_entier} { if ( yyleng>0){ return taille_tab;}
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
