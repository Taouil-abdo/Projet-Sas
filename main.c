#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct etudiant
{
	int id;
    char Nom[50];
    char Prenom[50];
    char DateNaissance[50];
    char Departement[50];
    float Notegenerale;
};

struct etudiant et[50];
int totalEtudiants = 0;
int i ,j,k;


void Ajouter()
{
	
	printf("================ Menu =================\n");
	
	printf("votre id est %d\n",et[totalEtudiants].id = totalEtudiants+1);
	printf("Enter le Nom : \n");
	scanf("%s",et[totalEtudiants].Nom);
	printf("Enter le Prenom : \n");
	scanf("%s",et[totalEtudiants].Prenom);
	printf("Enter la Date de naissance : \n");
	scanf("%s",et[totalEtudiants].DateNaissance);
	printf("Enter le Departement : \n");
	scanf("%s",et[totalEtudiants].Departement);
	printf("Enter la Note generale : \n");
	scanf("%f",&et[totalEtudiants].Notegenerale);
	
	totalEtudiants++;
	printf("Bien Ajouter ! \n");

}


void Afficher()
{
	for(i = 0; i < totalEtudiants ; i++)
	{
		printf("=============================\n");
		printf("votre id est %d\n",et[i].id);
		printf("le Nom est : %s\n",et[i].Nom);
		printf("le Prenom : %s\n",et[i].Prenom);
		printf("la Date de Naissance : %s\n",et[i].DateNaissance);
		printf("le Departement : %s\n",et[i].Departement);
		printf("la Note generale : %.2f\n",et[i].Notegenerale);
	}
}

void Rechercher()
{
   char RecherchNom[50];
   int found = 0;
   
   printf("enter le Nom d'etudiant que vous avez de recherche :\n");
   scanf("%s",RecherchNom);
   
      	for(i = 0 ; i < totalEtudiants ; i++)
   {
   	   if(strcmp(RecherchNom,et[i].Nom) == 0)

   	{
   		printf("votre id est %d\n",et[i].id);
		printf("le Nom est : %s\n",et[i].Nom);
		printf("le Prenom : %s\n",et[i].Prenom);
		printf("la Date de Naissance : %s\n",et[i].DateNaissance);
		printf("le Departement : %s\n",et[i].Departement);
		printf("la Note generale : %.2f\n",et[i].Notegenerale);
	   }
    
   }

}


void Modifier()
{
    int Recherchid;
    int found = 0;

    printf("Entrer l'id de l'etudiant que vous voulez modifier : \n");
    scanf("%d", &Recherchid);

    for (i = 0; i < totalEtudiants; i++)
    {
        if (Recherchid == et[i].id)  
        {
            printf("Entrez le nouveau Nom : \n");
            scanf("%s", et[i].Nom);
            printf("Entrez le nouveau Prenom : \n");
            scanf("%s", et[i].Prenom);
            printf("Entrez la nouvelle Date de Naissance : \n");
            scanf("%s", et[i].DateNaissance);
            printf("Entrez le nouveau Departement : \n");
            scanf("%s", et[i].Departement);
            printf("Entrez la nouvelle Note generale : \n");
            scanf("%f", &et[i].Notegenerale);

            printf("Les informations ont ete modifiees avec succes.\n");
            found = 1;  
            break; 
        }
    }

    if (!found)
    {
        printf("Etudiant avec l'id %d non trouve \n", Recherchid);
    }
}


void supprimer()
{
	int Recherchid;

    printf("Entrer l'id de l'etudiant que vous voulez modifier : \n");
    scanf("%d", &Recherchid);
    
    for(i = 0 ; i < totalEtudiants ; i++)
    {
    	if(Recherchid == et[i].id)
    	{
    		
    		while(i < totalEtudiants)
    		{
    			 et[i].id = et[i+1].id ;
    			strcpy(et[i].Nom, et[i+1].Nom);
    			strcpy(et[i].Prenom, et[i+1].Prenom);
    			strcpy(et[i].Departement, et[i+1].Departement);
    			strcpy(et[i].DateNaissance, et[i+1].DateNaissance);
    			et[i].Notegenerale = et[i+1].Notegenerale;
    			
            totalEtudiants--;
            i++;
            printf("Étudiant Bien supprimé \n");

			}
		}
		printf("Etudaint avec l'id %d non trouve. : \n");
	}
	
}


void calculerMoyenneGenerale() {
	
    float somme_totale_universite = 0;
    int nombre_total_etudiants = 0;

    for (i = 0; i < totalEtudiants; i++) {
        char departementCourant[50];
        strcpy(departementCourant, et[i].Departement); 
        
        int deja_calculer = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(et[j].Departement, departementCourant) == 0) {
                deja_calculer = 1;
                break;
            }
        }
        
        if (!deja_calculer) {
            float somme_notes_departement = 0;
            int nombre_etudiants_departement = 0;
            
            for (k = 0; k < totalEtudiants; k++) {
                if (strcmp(et[k].Departement, departementCourant) == 0) {
                    somme_notes_departement += et[k].Notegenerale;
                    nombre_etudiants_departement++;
                }
            }
            
            if (nombre_etudiants_departement > 0) {
                float moyenne_departement = somme_notes_departement / nombre_etudiants_departement;
                printf("Moyenne generale du departement %s : %.2f\n", departementCourant, moyenne_departement);
            }
        }
        
        somme_totale_universite += et[i].Notegenerale;
        nombre_total_etudiants++;
    }
    
    if (nombre_total_etudiants > 0) {
        float moyenne_generale_universite = somme_totale_universite / nombre_total_etudiants;
        printf("Moyenne generale de l'universite : %.2f\n", moyenne_generale_universite);
    } else {
        printf("Aucun etudiant n'est inscrit.\n");
    }
}


// 1. Afficher le nombre total d'étudiants inscrits

void afficherNombreTotalEtudiants() {
    printf("Nombre total d'étudiants inscrits : %d\n",totalEtudiants);
}

// 2. Afficher le nombre d'étudiants dans chaque département

void NomberEtudParDepartement()
{	
	
	
}

// 3. Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil

void NomberEtudParDepartement(int seuil)
{
	
}

// 4. Afficher les 3 étudiants ayant les meilleures notes

// Fonction pour afficher les statistiques

void statistique()
{
	int choix2;
	
		do{
			
		printf("1.Afficher le nombre total d'etudiants inscrits.\n");
		printf("2.Afficher le nombre d'etudiants dans chaque departement.\n");
		printf("3.Afficher les etudiants ayant une moyenne generale superieure a un certain seuil.\n");
		printf("4.Afficher les 3 etudiants ayant les meilleures notes.\n");
		printf("5.Afficher le nombre d'etudiants ayant reussi dans chaque departement.\n");
        printf("que vous choisir : \n");
        scanf("%d",&choix2);
        
        switch(choix2)
        {
        case 1:
             afficherNombreTotalEtudiants();
            break;
        case 2:
            
            break;
        case 3:
        	
            break;
        case 4:
            
            break;
        case 5:
        	
            break;
        case 6:
        	    return;
            break;
        default:
            printf("Choix invalide. Veuillez entrer un numero entre 1 et 6.\n");
            break;
		}
		
	}while(choix2 != 7);
}


//Tri alphabétique des étudiants en fonction de leur nom (de A à Z ou de Z à A).

void TrierparNom(struct etudiant *et, int totalEtudaint) {
	
    struct etudiant temp;
    
    for (i = 0; i < totalEtudaint-1 ; i++) {
        for (j = 0; j < totalEtudaint-i-1 ; j++) {
            if (strcmp(et[j].Nom, et[j + 1].Nom) > 0) {
                temp = et[j];
                et[j] = et[j + 1];
                et[j + 1] = temp;
            }
        }
    }
}

//Tri des étudiants par moyenne générale, 
//du plus élevé au plus faible ou inversement.

void TrierparNoteGenerale(struct etudiant *et, int totalEtudaint) {
	
    struct etudiant temp;
    
    for (i = 0; i < totalEtudaint-1 ; i++) {
        for (j = 0; j < totalEtudaint-i-1 ; j++) {
            if (et[j].Notegenerale - et[j + 1].Notegenerale < 0) {
                temp = et[j];
                et[j] = et[j + 1];
                et[j + 1] = temp;
            }
        }
    }
}

//Tri des étudiants selon leur statut de réussite 
//(ceux ayant une moyenne supérieure ou égale à 10/20).

//void TrierparRéussite(struct etudiant *et, int totalEtudaint) {

//}


void trie()
{
	int choixtrie;
	
	 do {
        printf("1. Trier par nom\n");
        printf("2. Trier par moyenne\n");
        printf("3. Trier par statut de réussite\n");
        printf("4. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choixtrie);
        
        switch (choixtrie) {
            case 1:
                TrierparNom(et,totalEtudiants);
                break;
            case 2:
                TrierparNoteGenerale(et,totalEtudiants);
                break;
            case 3:
            	TrierparNom(et,totalEtudiants);
                break;
            case 4:
                printf("Au revoir !\n");
                 return ;
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
		
	}while(choixtrie != 5);
}


//// ================================ Menu 

int main() {
    int choix;

do{

    printf("========== Menu de gestion des livres: =====================\n\n\n");
    
    printf("1.Ajouter un etudiant \n");
    printf("2.Afficher les details d'un etudiant \n");
    printf("3.Rechercher un etudiant\n");
    printf("4.Modifier un etudiant \n");
    printf("5.supprimer un etudiant \n");
    printf("6.Calculer la moyenne generale \n");
    printf("7.Statistiques \n");
    printf("8.Trier un etudiant par \n");
    printf("9.Quitte \n ");

    printf("Veuillez entrer le numero de votre choix : \n");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
             Ajouter();
            break;
        case 2:
            Afficher();
            break;
        case 3:
        	Rechercher();
            break;
        case 4:
            Modifier();
            break;
        case 5:
        	supprimer();
            break;
        case 6:
        	calculerMoyenneGenerale();
            break;
        case 7:
        	statistique();
            break;
        case 8:
        	trie();
            break;
        case 9:
        
            break;
        default:
            printf("Choix invalide. Veuillez entrer un numero entre 1 et 6.\n");
            break;
    }
}while(choix != 9);
    return 0;
}
