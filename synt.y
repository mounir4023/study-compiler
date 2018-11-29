%{
#include <stdio.h>
#include "Tab_Symbole.h"
#include "Quadruplet.h"

int Bib_Calcule=0,Bib_Boucle=0,Bib_Tab=0;
int Ind_Operand=0,Ind_Declaration=0;
int sauv_BR;
int yylex();
int yyerror(char *s);
%}

%union{
char*  chaine;
int entier;
float real;
struct Str{char *val;char* type;}Str;
struct Str2{char* op;char* res;}Str2;
}

%token mc_pgm mc_integer mc_real mc_const mc_if mc_while mc_exec
       bib_calcul bib_tab bib_boucle
       sb_eg sb_diff sb_inf sb_infeg sb_sup sb_supeg
       sb_aff sp_var
       <chaine>id <entier>val_entiere <real>val_reelle
       '{' '}' ',' ';' '+' '*' '/' '-' '[' ']' '(' ')'

%type <Str> EXP1
%type <Str> EXP2
%type <Str> EXP3        
%type <Str> VAR
%type <Str> CST
%type <Str> COMPARATEUR

%%

//////////////////////////////////// Structure general ////////////////////////////////////
S : BIBL mc_pgm id '{' DEC INST '}' { printf("\n\nLe programme est syntaxiquement correct !\n"); }
;

BIBL : CALCUL BIBL     
     | TAB BIBL        
     | BOUCLE BIBL 
     | 
;

//////////////////////////////// Règles bibliothèques  ///////////////////////////////////////

CALCUL : bib_calcul 
    { 
        if (Bib_Calcule==0) { 
            Inserer("CALCUL","mc","/",0);
            Bib_Calcule=1; 
        } else {
            printf("\nBibliotheque CALCUL deja declaree");
        } 
    }
;

TAB : bib_tab 
    { 
        if (Bib_Tab==0) {
            Inserer("TAB","mc","/",0);
            Bib_Tab=1;
        } else { 
            printf("\nBibliotheque TAB deja déclaée");
        }
    }
;

BOUCLE : bib_boucle 
    { 
        if (Bib_Boucle==0) { 
            Inserer("BOUCLE","mc","/",0);
            Bib_Boucle=1;
        } else {
            printf("\nBibliotheque BOUCLE deja declare");
        }
    }
;

//////////////////////////////////// Declaration part ////////////////////////////////////
DEC : TYPE CONST NVAR ';' MOREDEC 
;

CONST: mc_const { type_const=1;  }
     | { type_const=0; }
;

MOREDEC : DEC 
        |  { fin_dec=1; }
;

NVAR : VAR MOREVAR 
;

MOREVAR : sp_var NVAR 
        |  { Vider_LD(); }
;

VAR : id INDEX  
    { 
        if( fin_dec == 0 ) { // partie declaration
            Inserer_LD($1,index_val);
        } else { // partie instructions
            if ( Rechercher($1) == NULL ) {
                printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Variable %s non declaree !",nbligne,nbcolonne,$1);	
                Ind_Declaration=1; //faut sortir sinon yrouh ychercher 3la null donc lazem n7absso
            }
            if (index_val ==-1 && get_taille($1) > 1) {
                printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Acces a un tableau sans preciser d indice !",nbligne,nbcolonne);
            } else if (index_val>get_taille($1)) {
                printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Depassement de la taille de tableau !",nbligne,nbcolonne);
            } else if (get_taille($1)==1 && index_val != -1 ) {
                printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Variable simple utilisee comme un tableau !",nbligne,nbcolonne);
            }
            if ( Rechercher($1)!=NULL)
            {
                $$.val=strdup($1);
                $$.type=getType($1);
            }
            //printf("wach kayen %s\n",$$.type);
        }
    }
;

INDEX : '[' val_entiere ']' 
    { 
        if(!Bib_Tab) printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Utilisation de tableau sans import de la biblioteque !",nbligne,nbcolonne);
        if (!fin_dec) {
            if($2==0) printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Declaration de tableau de taille egale a zero  !",nbligne,nbcolonne);
            if($2==1) printf("\nL%2d C%2d | AVERTISSEMENT: Le tableau de taille 1 a ete transforme en variable simple  !",nbligne,nbcolonne);
        }
        index_val = $2;
    }
      | { index_val = -1; }
;

TYPE : mc_integer   { type_courant = strdup("INTEGER"); } 
     | mc_real	    { type_courant = strdup("REAL"); } 
;

CST : val_entiere   {$$.type=strdup("INTEGER");  char t[10]; sprintf(t,"%d",$1); $$.val=strdup(t);}
    | val_reelle    {$$.type=strdup("REAL");     char t[10]; sprintf(t,"%f",$1); $$.val=strdup(t);}
;

//////////////////////////////////// Instruction part ////////////////////////////////////

INST : INST_AFF MOREINST 
     | INST_IF MOREINST 
     | INST_WHL MOREINST 
;

MOREINST : INST 
	 | 
;

INST_AFF: VAR {
                    if ( getNature($1.val)==1){ 
                    printf ("\nL%2d C%2d | ERREUR SEMANTIQUE: %s est une constante",nbligne,nbcolonne,$1.val);
                    }
                }

          sb_aff EXP1 ';' 
                {
                    if ( ! Bib_Calcule ) {
                        printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Utilisation d'operations arithmetiques sans import de biblioteque !",nbligne,nbcolonne); 
                    }
                    if ( Ind_Declaration==0 && Ind_Operand == 0)
                    {
                        if ( strcmp($1.type,$4.type)!=0){
                        printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité, affectation de %s à %s !",nbligne,nbcolonne,$4.type,$1.type);
                        }
                    }

                    if ( Ind_Declaration==0 && Ind_Operand ==1)
                        {
                            printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité, affectation non permise!",nbligne,nbcolonne);
                            Ind_Operand=0;
                            }

                    if ( Ind_Declaration==1 && Ind_Operand ==0)
                        {
                            printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité, affectation de %s à %s NON DECLARER!",nbligne,nbcolonne,$4.type,$1.val);
                            Ind_Declaration=0;
                        }

                    if ( Ind_Declaration==1 && Ind_Operand ==1)
                        {
                            printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité, affectation à %s NON DECLARER!",nbligne,nbcolonne,$1.val);
                            printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité, affectation non permise!",nbligne,nbcolonne);
                            Ind_Operand=0;
                            Ind_Declaration=0;
                            }
                    Ajouter_Quad("=",$1.val,$4.val,"");
                    
                }
;

EXP1 : EXP2 '+' EXP1 
        {
            if ( strcmp($1.type,$3.type)!=0){ printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité de types entre opérands addition %s avec %s !",nbligne,nbcolonne,$1.type,$3.type);
            Ind_Operand=1;
            }
            else{
                    $$.type=$1.type; 
                    char t[10]; sprintf(t,"T%d",Cpt_temp); 
                    Cpt_temp++;
                    Ajouter_Quad("+",$1.val,$3.val,t);
                    $$.val=strdup(t);
            }
        }
     | EXP2 '-' EXP1 
        {
            if ( strcmp($1.type,$3.type)!=0){ printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité de types entre opérands différence %s avec %s !",nbligne,nbcolonne,$1.type,$3.type);
            Ind_Operand=1;
            }
            else{
                    $$.type=$1.type; 
                    char t[10]; sprintf(t,"T%d",Cpt_temp); 
                    Cpt_temp++;
                    Ajouter_Quad("-",$1.val,$3.val,t);
                    $$.val=strdup(t);
            }
        }
     | EXP2 {$$.val=$1.val; $$.type=$1.type;}
;

EXP2 : EXP3 '*' EXP2 
        {
            if ( strcmp($1.type,$3.type)!=0){ printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité de types entre opérands multiplucation %s avec %s !",nbligne,nbcolonne,$1.type,$3.type);
            Ind_Operand=1;
            }
            else{
                    $$.type=$1.type; 
                    char t[10]; sprintf(t,"T%d",Cpt_temp); 
                    Cpt_temp++;
                    Ajouter_Quad("*",$1.val,$3.val,t);
                    $$.val=strdup(t);
            }
        }
     | EXP3 '/' EXP2 
        {
            if ( strcmp($1.type,$3.type)!=0){ printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité de types entre opérands division %s avec %s !",nbligne,nbcolonne,$1.type,$3.type);
            Ind_Operand=1;
            //return 0;
            }
            else{
                    $$.type=$1.type; 
                    char t[10]; sprintf(t,"T%d",Cpt_temp); 
                    Cpt_temp++;
                    Ajouter_Quad("/",$1.val,$3.val,t);
                    $$.val=strdup(t);
            }
        }
     | EXP3 {$$.val=$1.val; $$.type=$1.type;}
;

EXP3 : VAR  {$$.val=$1.val; $$.type=$1.type;}
     | CST  {$$.val=$1.val; $$.type=$1.type;} 
;

INST_IF : mc_exec {printf("s1\n");empiler_if(Num_Qc);printf("1: %d\n",Num_Qc);} 
          INST {        
                            printf("hii\n");
                            empiler_if(Num_Qc);
                            printf("7: %d\n",Num_Qc);
            Ajouter_Quad("BR","","","");

                            printf("hisi\n");
          }
          mc_if 
          '(' 
          COND {
            printf("rani fel cond");
                sauv_BR=depiler_if();
                int Deb_Inst=depiler_if();
                printf("%d\n",Deb_Inst);
                int id=Num_Qc-1;
                MAJ_quad_if(id,Deb_Inst);
                printf("%d\n",id);
                id++;
                printf("%d\n",sauv_BR);
                MAJ_quad_if(sauv_BR,id);
          } 
          ')' 
;

INST_WHL : mc_while '(' COND ')' '{' INST '}'
    {
        if(!Bib_Boucle)  printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Utilisation de boucle sans import de la biblioteque !",nbligne,nbcolonne);
    }
;

COND : EXP1 COMPARATEUR EXP1 
        {
            if ( strcmp($1.type,$3.type)!=0){
                printf("\nL%2d C%2d | ERREUR SEMANTIQUE: Incompatibilité de types entre opérands lors de la comparaison %s avec %s !",nbligne,nbcolonne,$1.val,$3.val);
            }
            else{
                    
                    printf("16s\n");
                    char t[10]; sprintf(t,"T%d",Cpt_temp);
                    Cpt_temp++;
                    Ajouter_Quad("-",$1.val,$3.val,t);
                    //ZIIID T LES AUTRES NOUBLE PAS W MACHI F LE CHMPS RES XD
                    if ( strcmp($2.val,"==")==0){
                        Ajouter_Quad("BE","","",t);
                    }
                    if ( strcmp($2.val,"!=")==0){
                        Ajouter_Quad("BNE","","",t);
                    }
                    if ( strcmp($2.val,"<")==0){
                        Ajouter_Quad("BL","","",t);
                    }
                    if ( strcmp($2.val,"<=")==0){
                        Ajouter_Quad("BLE","","",t);
                    }
                    if ( strcmp($2.val,">")==0){
                        Ajouter_Quad("BG","","",t);
                    }
                    if ( strcmp($2.val,">=")==0){
                        Ajouter_Quad("BGE","","",t);
                    }
            }
        }
;

COMPARATEUR : sb_eg    {$$.val=strdup("==");}
	    | sb_diff      {$$.val=strdup("!=");}   
	    | sb_inf       {$$.val=strdup("<");}
	    | sb_infeg     {$$.val=strdup("<=");}
	    | sb_sup       {$$.val=strdup(">");}
	    | sb_supeg     {$$.val=strdup(">=");}
;
      
%%
int main()
{yyparse(); 
 AfficherTS(TS);
 Affichage_Quad();
}

int yywrap()
{return 1;}

int yyerror(char *msg) 
{printf("\nL%2d C%2d | ERREUR SYNTAXIQUE",nbligne,nbcolonne);	return 1;}
