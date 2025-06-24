#include <stdio.h>

void printGameBoard(char gameBoard[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++){
			printf("%c ", gameBoard[i][j]);
		}

		printf("\n");
	}

}


int main() {
	
	//declare all variables
	int isPlaying = 1;
	int isIllegal = 0;
	int position;
	char player;

	//tracks number of turns, odd is X, even is O
	int turns = 1; 

	char gameBoard [3][3] = {
		{'1' ,'2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};

	printf("Connect 3: \n");
	
	//gameplay starts here
	while(isPlaying)
	{

		//determine who's turn it is
		
		if(turns % 2 != 0)
			player = 'X';
		else
			player = 'O';


		//print gameBoard
		printGameBoard(gameBoard);













	}













}

