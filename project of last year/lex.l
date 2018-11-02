%{
#include "synt.tab.h"
#include <string.h>
extern YYSTYPE yylval;

int nbligne=1;
int nbmot=1;

void sautDeLigne( char *s ) {
	int i,j=0;
	for ( i=0 ; i< strlen(s) ; i++ ) {
		j+=(s[i]=='\n');	
	} 
	nbligne+=j;
}

typedef struct {
	char entite[20];
	char code[20];
	char type[20];
	int taille;
} tupleTS; 

tupleTS TS[1000];
int cptTS=0;

int rechercher(char* entite) {
	int i=0;
	while ( i<cptTS ) {
		if(strcmp(entite,TS[i].entite)==0) return i;
		i++;
	}
	return -1;
}

char* get_type( char * entite ) {
	return TS[rechercher(entite)].type;
}

void inserer(char *entite , char *code) {
	if ( rechercher(entite) == -1 ) {
		//printf("\n %s %s %s\n",entite,code,type);
		strcpy(TS[cptTS].entite,entite);
		strcpy(TS[cptTS].code,code);
		cptTS++;
	}
}

void err_position () {
	printf("\n\n[L %d - C %d] ",nbligne,nbmot);
}

void insererType(char *entite , char *type ) {
	//printf("\n %d %s %s",rechercher(entite),entite,type);
        int i=rechercher(entite);
	if (  i != -1 &&  strcmp(TS[i].type,"") ==0 ) {
		strcpy(TS[rechercher(entite)].type,type);
	}
	else if ( i != -1 && strcmp(TS[i].type,"")!=0 ) {
		err_position();
		printf("ERREUR SEMANTIQUE: Double declaration de \"%s\"",entite);
	}
}

void insererTaille( char * entite , int taille ) {
	int i=rechercher(entite);
	if ( i != -1 && TS[i].taille == 0 ) {
		TS[i].taille=taille;
	}
}

void afficher ()
{
printf("\n/***************    Table des symboles    ******************/\n");
printf("___________________________________________________________   \n");
printf("\t NomEntite |  CodeEntite  |     Type   | taille \n");
printf("___________________________________________________________   \n");
int i=0;
  while(i<cptTS)
  {
    printf("\t%10s |%12s  |%10s  |%5d\n",TS[i].entite,TS[i].code,TS[i].type,TS[i].taille);
     i++;
  }
    printf("\n\n");
}

int doubleDeclaration ( char *variable ) {
//if ( rechercher(variable) == -1 ) return 0;
if ( rechercher(variable) != -1 && TS[rechercher(variable)].type != NULL )return 1;
return ( TS[rechercher(variable)].type != NULL );
}


%}

regex_idf [a-zA-Z][a-zA-Z0-9_]*
regex_int [0-9]+
regex_float [0-9]+[.][0-9]+
regex_string \".*\"
regex_fleche "<--"
regex_com \/\*(.*|\n*)*\*\/
regex_com_l "//".*"\n"
regex_diff "!="
regex_supeg ">="
regex_infeg "<="

%%

entier { yylval.chaine=strdup(yytext); return mc_entier; }
reel { yylval.chaine=strdup(yytext); return mc_reel; }
chaine { yylval.chaine=strdup(yytext); return mc_chaine; }
Debut return mc_debut;
Fin return mc_fin;
Var return mc_var;
ALGORITHME return mc_algo;
pour return mc_pour;
jusque return mc_jusque;
si return mc_si;
faire return mc_faire;
fait return mc_fait;

\| return sb_bar;
\[ return sb_crochet_o;
\] return sb_crochet_f;
\( return sb_par_o;
\) return sb_par_f;
\+ return sb_plus;
\- return sb_moins;
\* return sb_fois;
\/ return sb_div;
: return sb_dp;
; return sb_pvg;
{regex_fleche} return sb_fleche; 
{regex_supeg} return sb_supeg;
{regex_infeg} return sb_infeg;
{regex_diff} return sb_diff;
\= return sb_eg;
\> return sb_sup;
\< return sb_inf;

{regex_int}  { yylval.entier=atoi(yytext); return cst_int; }
{regex_float} { yylval.reel=atof(yytext); return cst_float; }
{regex_string} { yylval.chaine=strdup(yytext); return cst_string; } 

{regex_idf} {
    if ( yyleng <= 12 ) {
	yylval.chaine=strdup(yytext);
	inserer(yytext,"idf");
	return idf; 
    }
    else { 
	err_position();
        printf("ERREUR LEXICALE: \"%s\" est identificateur trop long.",yytext);
    }
}

{regex_com_l} { nbligne++;}
{regex_com}   {
	sautDeLigne(yytext); 
}
[ \t]  
\n {
	nbligne++;
	nbmot=1;
}
. {
	err_position();
	printf("ERREUR LEXICALE: \"%s\" est une entite lexicale invalide.",yytext);
}

%%

int yyerror ( char * msg ) {
	err_position();
	printf ("ERREUR SYNTAXIQUE:%s",msg );
}

