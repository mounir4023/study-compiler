#include<stdio.h>
#include<stdlib.h>
typedef struct TS
{
	char nom[8];
	int type;
	int constOUvar;
	int taille;
	struct TS *svt;
}TS;


int Rechercher(TS**t,char* var)
{
	TS *p;
	for(p= *t;p !=NULL;p=p->svt)
	{
		if(!strcmp(p->nom,var))	
			return 1;
	}
	return 0;
}


int inserer(TS** t,char* nomVariable,int type,int ConstVar, int taille)
{
	TS *p;
	if(Rechercher(t,nomVariable))
		return -1;
	if(*t == NULL)
	  { *t=(TS*)malloc(sizeof(TS));
	    (*t)->svt=NULL;
	  }
	else
	 {
		for(p= *t;p->svt !=NULL;p=p->svt);
			p=(TS*)malloc(sizeof(TS));
			p->svt=*t;
			*t=p;
	}
	strcpy((*t)->nom,nomVariable);
	(*t)->type=type;
	(*t)->constOUvar=ConstVar;
	(*t)->taille = taille;
	return 0;
}
