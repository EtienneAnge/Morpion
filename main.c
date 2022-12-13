#include <stdio.h>

 typedef struct{
	int jour;
	int mois;
	int annee;
	int symb;
	} date;
	
typedef struct {
		char firstName[30];
		date age;
		char symb;
	} joueur;


date creerAge(){
	date age;
	printf("âge:\nJour: ");
	scanf("%d", &age.jour);

	
	printf("Mois: ");
	scanf("%d", &age.mois);
	
	printf("Année: ");
	scanf("%d", &age.annee);
	
	return age;
	}	

//si le premier age est plus grand que le soncond alors renvois 1 si non 0
int plusVieux(date age1, date age2){
	if(age1.annee < age2.annee){
		return 1;
		}
	if(age1.annee > age2.annee){
		return 0;
		}
	if(age1.mois < age2.mois){
		return 1;
		}
	if(age1.mois > age2.mois){
		return 0;
		}
	if(age1.jour < age2.jour){
		return 1;
		}
	if(age1.jour > age2.jour){
		return 0;
		}
		return 0;
		}

//vérifie si un des deux joueur a gagné
//renvoie 0 si aucun n'a gagné, 1 si les croix ont gagné et 2 si les ronds on gagné
char end(char tab[3][3]){
	char symb;
	for(int a = 1; a<=2; a++){
		if(a==1){
			symb = 'X';
		}else{
			symb = 'O';
		}

		//colone et ligne
		for(int i=0; 0<3; i++){
			if(tab[i][0]==symb && tab[i][1]==symb && tab[i][2]==symb){
				return symb;
			}
			if(tab[0][i]==symb && tab[1][i]==symb && tab[2][i]==symb){
				return symb;
			}
		}

		//diagonale
		if(tab[1][1]==symb){
			if(tab[0][0]==symb && tab[2][2]==symb){
				return symb;
			}
			if(tab[2][0]==symb && tab[0][2]==symb){
				return symb;
			}
		}
	}
	return '_';
}

//affiche la grille
void grille(char tab[3][3]){
	for(int i = 0; i<=2; i++){
		printf("\n%c|%c|%c", tab[i][0],tab[i][1], tab[i][2]);
	}
}

	
int main(int argc, char **argv) {
	//mets '_' dans le tableau tab
	char tab[3][3];
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			tab[i][j] = '_';
		}
	}
	int turn;

	//demande les infos des joueurs
	joueur j1;
	printf("joueur 1:\nPrénom: ");
	scanf("%s", j1.firstName);
	j1.age = creerAge();
	
	joueur j2;
	printf("joueur 2:\nPrénom: ");
	scanf("%s", j2.firstName);
	j2.age = creerAge();

	//vérifie qui commence
	if(plusVieux(j1.age, j2.age)==1){
		j1.symb = 'X';
		j2.symb = 'O';
		turn = 0;

	}else{
		j1.symb = 'O';
		j2.symb = 'X';
		turn = 1;
	}
	int i, j;
	int whowin;
	joueur player;

	//boucle de la partie du jeu
	do{
		grille(tab);

		//vérifie a qui le tour
		if(turn%2==0){
			player = j1;
		}else{
			player = j2;
		}

		
		//fait jouer le joueur
		do{
			printf("\n%s, Où voulez-vous jouer ?\nligne: ", player.firstName);
			scanf("%d", &i);
			printf("colonne: ");
			scanf("%d", &j);

			if(tab[i-1][j-1] != '_'){
				printf("case incorrecte !");
			}
		}while(tab[i-1][j-1] != '_');
		tab[i-1][j-1] = player.symb;
		
		
		whowin = end(tab);
		turn = turn + 1;
	}while(whowin=='_');

	//dit qui a gagné
	if(whowin==j1.symb){
		printf("\n%s à gagné", j1.firstName);
	}else{
		printf("\n%s à gagné", j2.firstName);
	}
	
	
	return (0);
	}
