#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


//vérifie si un des deux joueur a gagné
//renvoie ' ' si aucun n'a gagné, 'X' si les croix ont gagné et 'O' si les ronds on gagné
char end(char tab[3][3], char symb){

	//colone et ligne
	for(int i=0; i<3; i++){
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
	
	return ' ';
}


//affiche la grille
void grille(char tab[3][3]){
	system("clear");
	char symb;
	printf("\n");
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			for(int k=0; k<3; k++){
				
				symb = tab[i][k];
				if(symb == 'X'){
					if(j == 0){
						printf("%s", "  \\ /  ");
					}
					if(j == 1){
						printf("%s", "   X   ");
					}
					if(j == 2){
						printf("%s", "  / \\  ");
					}
				}

				if(symb == 'O'){
					if(j == 0){
						printf("%s", "  / \\  ");
					}
					if(j == 1){
						printf("%s", " |   | ");
					}
					if(j == 2){
						printf("%s", "  \\ /  ");
					}
				}
				if(symb == ' '){
					printf("%s", "       ");
				}

				if(k!=2){
					printf("|");
				}
			}
			if(j!=2){
				printf("\n");
			}
		}
		if(i!=2){
			printf("\n-----------------------\n");
		}
	}
}

	
	
	
int main(int argc, char **argv) {

	srand(time(NULL));
	
	//mets ' ' dans le tableau tab
	char tab[3][3];
	for(int m=0; m<3; m++){
		for(int n=0; n<3; n++){
			tab[m][n] = ' ';
		}
	}

	int turn = 0;
	int i;
	int j;
	int whowin;
	char player;

	system("clear");
	printf("[0] 1 vs 1\n[1] 1 vs IA\n");

	int mode;
	scanf("%d", &mode);
	
	while(mode!=0 && mode!=1){
		system("clear"); 
		printf("saisit incorrect\n[0] 1 vs 1\n[1] 1 vs IA\n");
		}
	
	
	//boucle de la partie du jeu
	do{
		grille(tab);

		//vérifie a qui le tour
		if(turn%2==0){
			player = 'X';
		}else{
			player = 'O';
		}

		
		//fait jouer le joueur
		if(mode==0 || turn%2==0){
			do{
			
				printf("\nAu %c de jouer\nligne: ", player);
				scanf("%d", &i);
				printf("colonne: ");
				scanf("%d", &j);
				i = i-1;
				j = j-1;
			
				if(tab[i][j] != ' ' || i<0 || i>2 || j<0 || j>2){ 
					grille(tab);
					printf("\nSaisie incorrecte !");
				}
			}while(tab[i][j] != ' ' || i<0 || i>2 || j<0 || j>2);
		}
		else{
				 do{
					i = rand() % 3;
					j = rand() % 3;

				}while(tab[i][j]!=' ');
				
			}
		
		tab[i][j] = player;
		
		turn = turn + 1;
		whowin = end(tab, player);
	}while(whowin==' ');

	grille(tab);
	
	//dit qui a gagné
	if(whowin=='X'){
		printf("\nX à gagné\n");
	}else{
		printf("\nO à gagné\n");
	}
	
	
	return (0);
	}
