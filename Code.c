
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef int bool;
#define TRUE 1
#define FALSE 0


typedef struct element
{
struct element *svt;
int info;
struct element *prec;
}liste;
liste *tete = NULL;
liste *creer_ldc(liste *);
liste *creer_ldc_LIFO(liste *);
liste *Afficher(liste *);
liste *insert_deb(liste *);
liste *insert_fin(liste *);
liste *insert_avant(liste *);
liste *insert_apres(liste *);
liste *supp_deb(liste *);
liste *supp_fin(liste *);
liste *supp_avant(liste *);
liste *supp_apres(liste *);
liste *supp_liste(liste *);
bool Rechercher(liste *tete);

int main()
{
int option;
clrscr();
do
{
printf("\n\n *****MENU PRINCIPALE *****");
printf("\n 1: Creer la liste FIFO");
printf("\n 2: Afficher la liste");
printf("\n 3: Ajouter un noeud au début de la liste");
printf("\n 4: Ajouter un noeud à la fin de la liste");
printf("\n 5: Ajouter un noeud avant un noeud donnée");
printf("\n 6: Ajouter un noeud après un noeud donnée");
printf("\n 7: Supprimer un noeud au début de la liste");
printf("\n 8: Supprimer un noeud à la fin de la liste");
printf("\n 9: Supprimer un noeud avant un noeud donnée");
printf("\n 10: Supprimer un noeud après un noeud donnée");
printf("\n 11: Supprimer le liste entière");
printf("\n 12: Creer la liste LIFO");
printf("\n 13: Recherche une valeur");
printf("\n 14: Sortir");
printf("\n\n Entez votre choix : ");
scanf("%d", &option);
switch(option)
{
case 1: tete = creer_ldc(tete);
printf("\n DOUBLY LINKED LIST CREATED");
break;
case 2: tete = Afficher(tete);
break;
case 3: tete = insert_deb(tete);
break;
case 4: tete = insert_fin(tete);
break;
case 5: tete = insert_avant(tete);
break;
case 6: tete = insert_apres(tete);
break;
case 7: tete = supp_deb(tete);
break;
case 8: tete = supp_fin(tete);
break;
case 9: tete = supp_avant(tete);
break;
case 10: tete = supp_apres(tete);
break;
case 11: tete = supp_liste(tete);
printf("\n Liste doublement chainée supprimer");
break;

case 12: tete = creer_ldc_LIFO(tete);
break;
case 13: if (Rechercher(tete)==TRUE) printf("\nLa valeur existe"); else printf("\nLa valeur n'existe pas");
break;
}
}while(option != 14);
getch();
return 0;
}
liste *creer_ldc(liste *tete)
{
liste *new_node, *ptr;
int num;
printf("\n Entrez -1 pour finir la création");
printf("\n Entez une donnée : ");
scanf("%d", &num);
while(num!=-1)
{
if(tete == NULL)
{
new_node = (liste*)malloc(sizeof(liste));
new_node -> prec = NULL;
new_node -> info = num;
new_node -> svt = NULL;
tete = new_node;
}
else
{
ptr=tete;
new_node = (liste*)malloc(sizeof(liste));
new_node->info=num;
while(ptr->svt!=NULL)
ptr=ptr->svt;
ptr->svt=new_node;
new_node->prec=ptr;
new_node->svt=NULL;
}
printf("\n Entez une donnée : ");
scanf("%d", &num);
}
return tete;
}

liste *creer_ldc_LIFO(liste *tete)
{
liste *new_node, *ptr;
int num;
printf("\n Entrez -1 pour finir la création");
printf("\n Entez une donnée : ");
scanf("%d", &num);
while(num!=-1)
{
if(tete == NULL)
{
new_node = (liste*)malloc(sizeof(liste));
new_node -> prec = NULL;
new_node -> info = num;
new_node -> svt = NULL;
tete = new_node;
}
else
{
//ptr=tete;
new_node = (liste*)malloc(sizeof(liste));
new_node -> prec = NULL;
new_node -> info = num;
new_node -> svt = tete;
tete->prec=new_node;
tete = new_node;
}
printf("\n Entez une donnée : ");
scanf("%d", &num);
}
return tete;
}


bool Rechercher(liste *tete)
{
    int val;
   liste *ptr;
   
   printf ("\n donnez la va Rechercher");
   scanf ("%d",&val);
   
   ptr=tete;
  while(ptr!=NULL)
  {if (ptr->info==val) return (TRUE);
   ptr = ptr->svt;}
    return (FALSE);
}



liste *Afficher(liste *tete)
{
liste *ptr;
ptr=tete;
while(ptr!=NULL)
{
printf("\t %d", ptr -> info);
ptr = ptr -> svt;
}
return tete;
}
liste *insert_deb(liste *tete)
{
liste *new_node;
int num;
printf("\n Entez une donnée: ");
scanf("%d", &num);
new_node = (liste *)malloc(sizeof(liste));
new_node -> info = num;
tete -> prec = new_node;
new_node -> svt = tete;
new_node -> prec = NULL;
tete = new_node;
return tete;
}
liste *insert_fin(liste *tete)
{
liste *ptr, *new_node;
int num;
printf("\n Entez une donnée: ");
scanf("%d", &num);
new_node = (liste *)malloc(sizeof(liste));
new_node -> info = num;
ptr=tete;
while(ptr -> svt != NULL)
ptr = ptr -> svt;
ptr -> svt = new_node;
new_node -> prec = ptr;
new_node -> svt = NULL;
return tete;
}
liste *insert_avant(liste *tete)
{
liste *new_node, *ptr;
int num, val;
printf("\n Entez une donnée : ");
scanf("%d", &num);
printf("\n Entez la valeur dont la donnée dois étre inserer avant : ");
scanf("%d", &val);
new_node = (liste *)malloc(sizeof(liste));
new_node -> info = num;
ptr = tete;
while(ptr -> info != val) ptr = ptr -> svt;
if (ptr == tete) {
                     tete -> prec = new_node;
                     new_node -> svt = tete;
                     new_node -> prec = NULL;
                     tete = new_node;
                    }
                    else { new_node -> svt = ptr;
                           new_node -> prec = ptr-> prec;
                           ptr -> prec -> svt = new_node;
                           ptr -> prec = new_node;
                    }
return tete;
}
liste *insert_apres(liste *tete)
{
liste *new_node, *ptr;
int num, val;
printf("\n Enter the info : ");
scanf("%d", &num);
printf("\n Entez la valeur dont la donnée dois étre inserer aprés : ");
scanf("%d", &val);
new_node = (liste *)malloc(sizeof(liste));
new_node -> info = num;
ptr = tete;
while(ptr -> info != val)
ptr = ptr -> svt;
if (ptr->svt == NULL) {
                         ptr -> svt = new_node;
                         new_node -> prec = ptr;
                         new_node -> svt = NULL;
                        }
                        else {new_node -> prec = ptr;
                              new_node -> svt = ptr -> svt;
                              ptr -> svt -> prec = new_node;
                              ptr -> svt = new_node;}
return tete;
}
liste *supp_deb(liste *tete)
{
liste *ptr;
ptr = tete;
tete = tete -> svt;
if (tete !=NULL) {tete -> prec = NULL;}
free(ptr);
return tete;
}
liste *supp_fin(liste *tete)
{
liste *ptr;
ptr = tete;
while(ptr -> svt != NULL)
ptr = ptr -> svt;
ptr -> prec -> svt = NULL;
free(ptr);
return tete;
}
liste *supp_apres(liste *tete)
{
liste *ptr, *temp;
int val;
printf("\n Entez la valeur dont la donnée dois étre supprimer aprés: ");
scanf("%d", &val);
ptr = tete;
while(ptr -> info != val)
ptr = ptr -> svt;
if (ptr->svt != NULL) {if (ptr->svt->svt ==NULL) {ptr=ptr->svt;
                                                  ptr -> prec -> svt = NULL;
                                                  free(ptr);}
                                                  else {temp = ptr -> svt;
                                                        ptr -> svt = temp -> svt;
                                                        temp -> svt -> prec = ptr;
                                                        free(temp);}
                       }
return tete;
}
liste *supp_avant(liste *tete)
{
liste *ptr, *temp;
int val;
printf("\n Entez la valeur dont la donnée dois étre supprimer avant: ");
scanf("%d", &val);
ptr = tete;
while(ptr -> info != val)
ptr = ptr -> svt;
temp = ptr -> prec;
if(temp == tete)
{tete = supp_deb(tete);}
else
{
ptr -> prec = temp -> prec;
temp -> prec -> svt = ptr;
free(temp);
}

return tete;
}
liste *supp_liste(liste *tete)
{
while(tete != NULL)
{tete = supp_deb(tete);}

return tete;
}
