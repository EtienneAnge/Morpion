#include <stdio.h>



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
	int turn = 0;
	int i, j;
	int whowin;
	char player;

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
		do{
			printf("\nAu %c de jouer\nligne: ", player);
			scanf("%d", &i);
			printf("colonne: ");
			scanf("%d", &j);

			if(tab[i-1][j-1] != '_'){
				printf("case incorrecte !");
			}
		}while(tab[i-1][j-1] != '_');
		tab[i-1][j-1] = player;
		
		
		whowin = end(tab);
		turn = turn + 1;
	}while(whowin=='_');

	//dit qui a gagné
	if(whowin=='X'){
		printf("\nX à gagné");
	}else{
		printf("\nO à gagné");
	}
	
	
	return (0);
	}
