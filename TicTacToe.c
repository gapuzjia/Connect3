#include <stdio.h>

//-----MODIFIED-----adjusted to print 1d array instead
void printGameBoard(char gameBoard[9])
{
	for(int i = 0; i < 9; i++)
	{
		printf("%c ", gameBoard[i]);
		printf("%s", (i + 1) % 3 == 0 ? "\n" : "");

	}
}


int checkIllegalMove(int position, char gameBoard[9])
{	
	//-----MODIFIED----- no longer need get position function
	position = position - 1;


	//check if position is occupied
	return (gameBoard[position] > 57) ? (printf("Spot is already occupied!\n"), 1) : 0;


	
}

void modifyGameBoard(char player, int position, char gameBoard[9])
{

	//-----MODIFIED----- no longer need get position function
	position = position - 1;
	gameBoard[position] = player;
}

//-----MODIFIED----- replace if-else chain with reference 2d array
int checkWinner(char player, char gameBoard[9])
{
	int a, b, c;
	
	int winningCombos[24] ={

		0, 1, 2, 3, 4, 5, 6, 7, 8,
		0, 3, 6, 1, 4, 7, 2, 5, 8,
		6, 4, 2, 0, 4, 8
	};
	
	//winning combos are grouped into 3's
	//skip count and check by groups of 3
	for(int i = 0; i < 24; i+=3)
	{
		a = winningCombos[i];
		b = winningCombos[i + 1];
		c = winningCombos[i + 2];

		if(gameBoard[a] == gameBoard[b] && gameBoard[b] == gameBoard[c])
		{
			
			printGameBoard(gameBoard);
			printf("Player %c Wins!!!\n", player);
		  	return 1;	
		}
	}

	//fall through means return 0 (no winner)
	return 0;
}




int main() {
	
	//declare all variables
	int isPlaying = 1;
	int position;
	char player;

	//tracks number of turns, odd is X, even is O
	int turns = 1; 
	
	//-----MODIFIED----- scratch the 2d array, implement with 1d array instead
	char gameBoard[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};




	printf("TicTacToe: \n");
	
	//gameplay starts here
	while(isPlaying)
	{

		//determine who's turn it is
		(turns % 2 != 0) ? (player = 'X') : (player = 'O');

		//print gameBoard
		printGameBoard(gameBoard);

		//get player's move
		do
		{
			printf("Player %c Enter Position: ", player);
			scanf("%d", &position);
			printf("\n");

		}while(checkIllegalMove(position, gameBoard));

		//update the gameBoard
		modifyGameBoard(player, position, gameBoard);
		
		//check if a player won
		isPlaying = !checkWinner(player, gameBoard);

		//9 turns and no winner means a draw game
		if(isPlaying && turns == 9)
		{
			printf("Draw Game!\n");
			isPlaying = 0;		
		}
		
		//reset flags and update turn counter
		turns++;

	}

	printf("GAME OVER\n");
	return 0;













}

