//
// Created by Ranya STITOU on 26/11/2023.
//

#include <stdio.h>

int main(){
    Graphe * g;
    int sommet_initial;
    char nom_fichier[50];

    printf("Entrer le nom du fichier du labyrinthe:");
    gets(nom_fichier);

    g = lire_graphe(nom_fichier);

    ///saisie du numéro du sommet initial pour lancer un BFS puis un DSF
    printf("Saisir le numero du sommet initial : ");

    scanf("%d",&sommet_initial);

    /// afficher le graphe
    graphe_afficher(g);


    ///Allocation dynamique des sommets: la variable marque correspond aux sommets du graphe qui ont été visités
    int * marque= (int *) malloc(sizeof(int)*g->ordre);
    for(int i=0;i<g->ordre;i++)
        marque[i]=0;

    printf("\n====> DFS <====\n");
    DFS(g, sommet_initial,marque);

    for(int i=0;i<g->ordre;i++)
        marque[i]=0;

    printf("\n====> BFS <====\n");

    BFS(g, sommet_initial,marque);

    return 0;
}


/* affichage des successeurs du sommet num*/
void afficher_successeurs(pSommet * sommet, int num){
    printf(" sommet %d :\n",num);

    pArc arc=sommet[num]->arc;

    while(arc!=NULL){
        printf("%d ",arc->sommet);
        arc=arc->arc_suivant;
    }
}

// Ajouter l'arête entre les sommets s1 et s2 du graphe
pSommet* CreerArete(pSommet* sommet,int s1,int s2){
    if(sommet[s1]->arc==NULL){
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;
        sommet[s1]->arc=Newarc;
        return sommet;
    }

    else{
        pArc temp=sommet[s1]->arc;
        while( !(temp->arc_suivant==NULL)){
            temp=temp->arc_suivant;
        }
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;

        if(temp->sommet>s2){
            Newarc->arc_suivant=temp->arc_suivant;
            Newarc->sommet=temp->sommet;
            temp->sommet=s2;
            temp->arc_suivant=Newarc;
            return sommet;
        }

        temp->arc_suivant=Newarc;
        return sommet;
    }
}

// créer le graphe
Graphe* CreerGraphe(int ordre){
    Graphe * Newgraphe=(Graphe*)malloc(sizeof(Graphe));
    Newgraphe->pSommet = (pSommet*)malloc(ordre*sizeof(pSommet));

    for(int i=0; i<ordre; i++){
        Newgraphe->pSommet[i]=(pSommet)malloc(sizeof(struct Sommet));
        Newgraphe->pSommet[i]->valeur=i;
        Newgraphe->pSommet[i]->arc=NULL;
    }
    return Newgraphe;
}


/* La construction du réseau peut se faire à partir d'un fichier dont le nom est passé en paramètre
Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs */
Graphe * lire_graphe(char * nomFichier){
    Graphe* graphe;
    FILE * ifs = fopen(nomFichier,"r");
    int taille, orientation, ordre, s1, s2;

    if (!ifs){
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&ordre);

    graphe=CreerGraphe(ordre); // créer le graphe d'ordre sommets

    fscanf(ifs,"%d",&taille);
    fscanf(ifs,"%d",&orientation);

    graphe->orientation=orientation;
    graphe->ordre=ordre;

    // créer les arêtes du graphe
    for (int i=0; i<taille; ++i){
        fscanf(ifs,"%d%d",&s1,&s2);
        graphe->pSommet=CreerArete(graphe->pSommet, s1, s2);

        if(!orientation)
            graphe->pSommet=CreerArete(graphe->pSommet, s2, s1);
    }

    return graphe;
}

/*affichage du graphe avec les successeurs de chaque sommet */
void graphe_afficher(Graphe* graphe){
    printf("graphe:\n\n");

    if(graphe->orientation)
        printf("1.oriente\n");
    else
        printf("1.non oriente\n");

    printf("2.ordre = %d\n",graphe->ordre);

    printf("3.listes d'adjacence :\n");

    for (int i=0; i<graphe->ordre; i++){
        afficher_successeurs(graphe->pSommet, i);
        printf("\n");
    }

}

void BFS(Graphe * G, int depart, int * marque){
    int Q[G->ordre];
    int iQ=1,jQ=0;

    Q[jQ]=depart;
    marque[jQ]=1;

    while(iQ!=jQ){
        if(G->pSommet[Q[jQ]]->arc!=NULL){
            pArc arc = G->pSommet[Q[jQ]]->arc;
            while(arc!=NULL ){
                if(marque[arc->sommet]==0){
                    Q[iQ]=arc->sommet;
                    marque[Q[iQ]]=1;
                    iQ++;
                }
                arc=arc->arc_suivant;
            }
        }
        printf("-->%d",jQ);
        jQ++;
    }
    printf("\n ===>FIN BFS<===\n");
}

void DFS(Graphe * G, int depart, int * marque){
    marque[depart] =1;
    printf("->%d",depart);

    if(G->pSommet[depart]->arc!=NULL){
        pArc arc = G->pSommet[depart]->arc;
        while(arc!=NULL )        {
            if(marque[arc->sommet]==0)
                DFS(G, arc->sommet,marque);
            arc=arc->arc_suivant;
        }
    }
    printf("\nLe noeud %d ne possede plus de noeud adjacents non visite !\n\n",depart);
}

