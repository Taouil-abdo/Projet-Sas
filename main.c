#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

//========================= Partie AjouterEtudiants

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
	printf("Enter le Departement :[Math , info , pc , svt] \n");
	scanf("%s",et[totalEtudiants].Departement);
	printf("Enter la Note generale : \n");
	scanf("%f",&et[totalEtudiants].Notegenerale);
	
	totalEtudiants++;
	printf("Bien Ajouter ! \n");

}

//=========================Partie AfficherEtudiants


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

//=========================Partie Rechercher

//1 .Rechercher Par Nom
void RechercherParNom()
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

//2. AfficherEtudiantsParDepartement

void AfficherEtudiantsParDepartement()
{
   char RecherchDepartement[50];
   
   printf("enter le Departement d'etudiant que vous avez de recherche :\n");
   scanf("%s",RecherchDepartement);
   
      	for(i = 0 ; i < totalEtudiants ; i++)
   {
   	   if(strcmp(RecherchDepartement,et[i].Departement) == 0)
   	{
   		printf("votre id est %d\n",et[i].id);
		printf("le Nom est : %s\n",et[i].Nom);
		printf("le Prenom : %s\n",et[i].Prenom);
		printf("la Date de Naissance : %s\n",et[i].DateNaissance);
		printf("le Departement : %s\n",et[i].Departement);
		printf("la Note generale : %.2f\n\n",et[i].Notegenerale);
	   }
   }
}

void Rechercher()
{
	int choix3 ;
	
		do{
			
		printf("1.Rechercher Par Nom.\n");
		printf("2.Afficher Etudiants Par Departement.\n");
		printf("3.Quitte.\n");
        printf("que vous choisir : \n");
        scanf("%d",&choix3);
        
        switch(choix3)
        {
        case 1:
             RechercherParNom();
            break;
        case 2:
            AfficherEtudiantsParDepartement();
            break;
        case 3:
        	return;
            break;
        default:
        	break;
        }
}while(choix3 != 4);
}
//=========================Partie ModifierEtudiant

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

//=========================Partie supprimerEtudiant


void supprimer()
{
	int Recherchid;

    printf("Entrer l'id de l'etudiant que vous voulez supprimer : \n");
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
            printf("Etudiant Bien supprime \n");

			}
		}
	}		printf("Etudaint avec l'id %d non trouve. : \n");
}

//=========================Partie calculerMoyenneGenerale

void calculerMoyenneGenerale() {
	
    float somme_totale_universite = 0;
    int nombre_total_etudiants = 0;
    float somme_notes_departement = 0;
    int nombre_etudiants_departement = 0;

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

//========================= Partie Statistique

 
// 1. Afficher le nombre total d'étudiants inscrits

void afficherNombreTotalEtudiants() {
    printf("Nombre total d'étudiants inscrits : %d\n",totalEtudiants);
}

// 2. Afficher le nombre d'étudiants dans chaque département

void NomberEtudParDepartement()
{
    char departements[50][50];
    int compteurs[50]={0};
    int nombre_departements = 0;

    for (i = 0; i < totalEtudiants; i++)
    {
        int deja_ajoute = 0;
        for (j = 0; j < nombre_departements; j++)
        {
            if (strcmp(et[i].Departement, departements[j]) == 0)
            {
                compteurs[j]++;
                deja_ajoute = 1;
                break;
            }
        }

        if (!deja_ajoute)
        {
            strcpy(departements[nombre_departements], et[i].Departement);
            compteurs[nombre_departements]++;
            nombre_departements++;
        }
    }

    for (i = 0; i < nombre_departements; i++)
    {
        printf("Nombre d'étudiants dans le département %s : %d\n", departements[i], compteurs[i]);
    }
}

// 3. Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil

void EtudiantsAvecMoyenneSuperieure(float seuil)
{
    for (i = 0; i < totalEtudiants; i++)
    {
        if (et[i].Notegenerale > seuil)
        {
            printf("Nom: %s, Prenom: %s,Departement: %s, Note générale: %.2f\n", et[i].Nom, et[i].Prenom,et[i].Departement, et[i].Notegenerale);
        }
    }
}

// 4. Afficher les 3 étudiants ayant les meilleures notes
void troisMeilleuresNotes() {
    struct etudiant temp;

    for (i = 0; i < totalEtudiants - 1; i++) {
        for (j = i + 1; j < totalEtudiants; j++) {
            if (et[i].Notegenerale < et[j].Notegenerale) {
                temp = et[i];
                et[i] = et[j];
                et[j] = temp;
            }
        }
    }

    printf("Les 3 étudiants ayant les meilleures notes :\n");
    for (i = 0; i < 3 && i < totalEtudiants; i++) {
        printf("Nom: %s, Prenom: %s, Note générale: %.2f\n", et[i].Nom, et[i].Prenom, et[i].Notegenerale);
    }
}


// 5. Afficher le nombre d'étudiants ayant réussi dans chaque département

void NombreEtudiantsAyantReussi() {
    char departements[50][50];
    int compteurs[50] = {0};
    int nombre_departements = 0;

    for (i = 0; i < totalEtudiants; i++) {
        int deja_ajoute = 0;
        for (j = 0; j < nombre_departements; j++) {
            if (strcmp(et[i].Departement, departements[j]) == 0) {
                if (et[i].Notegenerale >= 10) {
                    compteurs[j]++;
                }
                deja_ajoute = 1;
                break;
            }
        }

        if (!deja_ajoute) {
            strcpy(departements[nombre_departements], et[i].Departement);
            if (et[i].Notegenerale >= 10) {
                compteurs[nombre_departements]++;
            }
            nombre_departements++;
        }
    }

    for (i = 0; i < nombre_departements; i++) {
        printf("Nombre d'étudiants ayant réussi dans le département %s : %d\n", departements[i], compteurs[i]);
    }
}

//========== Menu statistique

void statistique()
{
	int choix2 ,seuil;
	
		do{
			
		printf("1.Afficher le nombre total d'etudiants inscrits.\n");
		printf("2.Afficher le nombre d'etudiants dans chaque departement.\n");
		printf("3.Afficher les etudiants ayant une moyenne generale superieure a un certain seuil.\n");
		printf("4.Afficher les 3 etudiants ayant les meilleures notes.\n");
		printf("5.Afficher le nombre d'etudiants ayant reussi dans chaque departement.\n");
		printf("6.Quitte.\n");
        printf("que vous choisir : \n");
        scanf("%d",&choix2);
        
        switch(choix2)
        {
        case 1:
             afficherNombreTotalEtudiants();
            break;
        case 2:
            NomberEtudParDepartement();
            break;
        case 3:
        	printf("Etudiants ayant une moyenne generale superieure a %.2f :\n", seuil);
        	EtudiantsAvecMoyenneSuperieure(seuil);
            break;
        case 4:
            troisMeilleuresNotes();
            break;
        case 5:
        	NombreEtudiantsAyantReussi();
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


//================================== Partie Triage

////1. Tri alphabétique des étudiants en fonction de leur nom (de A à Z ou de Z à A).
//

void TrierparNom(int totalEtudaint) {
	
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

//2. Tri des étudiants par moyenne générale, 
//du plus élevé au plus faible ou inversement.

void TrierparNoteGenerale(int totalEtudaint) {
	
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

//3. Tri des étudiants selon leur statut de réussite 
//(ceux ayant une moyenne supérieure ou égale à 10/20).

void TrierparReussite(int totalEtudiant) {
	
	struct etudiant temp;
	
	for(i = 0 ; i < totalEtudiant-1 ;i++)
	{
		for(j = 0 ; j < totalEtudiant-i-1 ; j++)
		{
			 if ((et[j].Notegenerale < 10.0 && et[j + 1].Notegenerale >= 10.0) || 
			 (et[j].Notegenerale >= 10.0 && et[j + 1].Notegenerale >= 10.0 && et[j].Notegenerale < et[j + 1].Notegenerale) ||
                (et[j].Notegenerale < 10.0 && et[j + 1].Notegenerale < 10.0 && et[j].Notegenerale < et[j + 1].Notegenerale))
                {
                temp = et[j];
                et[j] = et[j + 1];
                et[j + 1] = temp;
				}
		}
	}
}


//============== Menu Triage
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
                TrierparNom(totalEtudiants);
                break;
            case 2:
                TrierparNoteGenerale(totalEtudiants);
                break;
            case 3:
            	TrierparReussite(totalEtudiants);
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

    printf("========== Menu : =====================\n\n\n");
    
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
            return;
            break;
        default:
            printf("Choix invalide. Veuillez entrer un numero entre 1 et 6.\n");
            break;
    }
}while(choix != 9);
    return 0;
}

