%{ 
char type_actu[20];
char type_old[20];
char list_dec_old[10][20];
char list_dec_actu[10][20];
int list_taille_actu[10];
int list_taille_old[10];
int cpt_dec_actu=0;
int cpt_dec_old=0;
int fin_dec=0;
int first_dec=1;
int i=0;

void insererListe () { 
	if ( first_dec == 0 ) {
		for (i=0; i<cpt_dec_old;i++)  {
			insererType(list_dec_old[i],type_old);
			insererTaille(list_dec_old[i],list_taille_old[i]);
		}
		for (i=0; i<10;i++)  {
			strcpy(list_dec_old[i],"");
		}
		cpt_dec_old=0;
	}
	// tjrs faire
		for (i=0; i<cpt_dec_actu;i++)  {
			strcpy(list_dec_old[i],list_dec_actu[i]);
			list_taille_old[i]=list_taille_actu[i];
		}
		for (i=0; i<10;i++)  {
			strcpy(list_dec_actu[i],"");
			list_taille_actu[i]=0;
		}
		cpt_dec_old=cpt_dec_actu;
		cpt_dec_actu=0;
	first_dec=0;
}
%}

%token  <chaine>idf 
	mc_algo mc_debut mc_fin mc_var <chaine>mc_entier <chaine>mc_reel <chaine>mc_chaine mc_pour mc_jusque mc_si mc_faire mc_fait
	sb_pvg sb_dp sb_bar sb_crochet_o sb_crochet_f sb_fleche sb_par_o sb_par_f sb_moins sb_plus sb_fois sb_div sb_eg sb_diff sb_sup sb_inf sb_supeg sb_infeg
	<entier>cst_int <reel>cst_float <chaine>cst_string 


%union {
	int entier;
	float reel;
	char* chaine;
}

%%

PROJET: BLOCK_ENTETE BLOCK_DEC BLOCK_CORPS  
{ printf("\n\nPAS D'ERREUR SYNTAXIQUE!\n"); }
;

BLOCK_ENTETE: mc_algo idf
;

BLOCK_DEC: mc_var DEC { fin_dec=1; strcpy(type_old,type_actu); insererListe();  printf("\n\nFin block declaration!");}
	 | { fin_dec=1; printf("\nATTENTION:Block declaration vide!");} 
;

BLOCK_CORPS: mc_debut INST mc_fin  { printf("\n\nFin block instructions!"); }
;

DEC: LISTEIDF sb_dp TYPE sb_pvg DEC 
     | 
;

LISTEIDF: VARS sb_bar LISTEIDF 
	| VARS 
;

VARS: idf INDEX { 
	if ( fin_dec==0)  { 
		strcpy(list_dec_actu[cpt_dec_actu],$1);
		cpt_dec_actu++;
	}
	else if ( strcmp((char*)get_type($1),"") == 0 ) {
		err_position();
		printf("ERREUR SEMANTIQUE: variable non declaree \"%s\"",$1);
	}
}
;

INDEX: sb_crochet_o OPERATION sb_crochet_f
    | 
;

TYPE: mc_entier { strcpy(type_old,type_actu);strcpy(type_actu,$1); insererListe(); }
    | mc_reel { strcpy(type_old,type_actu);strcpy(type_actu,$1); insererListe(); }
    | mc_chaine { strcpy(type_old,type_actu);strcpy(type_actu,$1); insererListe(); }
;

INST: AFFECTATION INST
    | BOUCLE INST
    | CONDITION INST
    | 
;

AFFECTATION: VARS sb_fleche OPERATION sb_pvg;
;

OPERATION: OPERATION OPAR TERM
	 | SIGN TERM
;

SIGN: sb_plus
    | sb_moins
    | 
;

TERM: VARS
    | CST
    | sb_par_o OPERATION sb_par_f
;

CST: cst_int {
	if ( fin_dec==0)  { 
		if($1>0) list_taille_actu[cpt_dec_actu]=$1;
		else { err_position(); printf("ERREUR SEMANTIQUE: \"%d\" taille impossible pour un tableau ",$1);
		}
	}
}
   | cst_float {
	if ( fin_dec==0)  { 
		err_position();
		printf("ERREUR SEMANTIQUE: mauvais type pour la taille du tableau ");
	}
}

   | cst_string {
	if ( fin_dec==0)  { 
		err_position();
		printf("\n\nERREUR SEMANTIQUE: mauvais type pour la taille du tableau \"%s\"",list_dec_actu[cpt_dec_actu]);
	}
}
;

OPAR: sb_plus 
    | sb_moins
    | sb_fois
    | sb_div
;

BOUCLE: mc_pour idf sb_fleche OPERATION mc_jusque OPERATION mc_faire INST mc_fait

;

CONDITION: mc_faire INST mc_si sb_par_o PREDICAT sb_par_f

;

PREDICAT: OPERATION OPC OPERATION
	
;

OPC: sb_eg
   | sb_diff
   | sb_sup
   | sb_inf
   | sb_supeg
   | sb_infeg
;

%%

main()
{ yyparse(); afficher(); }
yywrap()
{}
