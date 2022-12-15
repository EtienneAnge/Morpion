#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


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
	}
	return ' ';
}

//affiche la grille
void grille(char tab[3][3]){
	for(int i = 0; i<3; i++){
		printf("\n%c|%c|%c", tab[i][0],tab[i][1], tab[i][2]);
	}
}

	
	
	
int main(int argc, char **argv) {
	srand(time(NULL));
	
	//mets '_' dans le tableau tab
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
	
	printf("[0] 1 vs 1\n[1] 1 vs IA\n");

	int mode;
	scanf("%d", &mode);
	
	while(mode!=0 && mode!=1){
		system("clear"); 
		printf("saisit incorrect\n[0] 1 vs 1\n[1] 1 vs IA\n");
		}
	
	
	//boucle de la partie du jeu
	do{
		system("clear"); 
		grille(tab);

		//vérifie a qui le tour
		if(turn%2==0){
			player = 'X';
		}else{
			player = 'O';
		}

		
		//fait jouer le joueur
		do{
			if(mode==0 || turn%2==0){
				printf("\nAu %c de jouer\nligne: ", player);
				scanf("%d", &i);
				printf("colonne: ");
				scanf("%d", &j);
				i = i-1;
				j = j-1;
			}else{
				 do{
					i = rand() % 3;
					j = rand() % 3;

				}while(tab[i][j]!=' ');
				
				printf("\nCalcul en cours...");
				sleep(1);
			}
			
			if(tab[i][j] != ' '){
				system("clear"); 
				grille(tab);
				printf("\ncase incorrecte !");
			}
		}while(tab[i][j] != ' ');
		
		tab[i][j] = player;
		
		turn = turn + 1;
		whowin = end(tab);
	}while(whowin==' ');
	system("clear");
	grille(tab);
	
	//dit qui a gagné
	if(whowin=='X'){
		printf("\nX à gagné\n");
	}else{
		printf("\nO à gagné\n");
	}
	
	
	return (0);
	}
