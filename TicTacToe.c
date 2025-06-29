#include <stdio.h>
#include <ctype.h>

//-----ADDED-----replace 1d array, implement with struct instead
typedef struct {
	char pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9;
} GameBoard;



//-----MODIFIED-----adjusted to print 1d array instead
void printGameBoard(GameBoard gameBoard)
{
	printf("%c %c %c\n", gameBoard.pos1, gameBoard.pos2, gameBoard.pos3);
	printf("%c %c %c\n", gameBoard.pos4, gameBoard.pos5, gameBoard.pos6);
	printf("%c %c %c\n", gameBoard.pos7, gameBoard.pos8, gameBoard.pos9);

}

char* getPosition(GameBoard *gameBoard, int position)
{
	switch(position){
		case 1: return &gameBoard->pos1;
		case 2: return &gameBoard->pos2;
		case 3: return &gameBoard->pos3;
		case 4: return &gameBoard->pos4;
		case 5: return &gameBoard->pos5;
		case 6: return &gameBoard->pos6;
		case 7: return &gameBoard->pos7;
		case 8: return &gameBoard->pos8;
		case 9: return &gameBoard->pos9;
		default: return NULL;
	}

}


int checkIllegalMove(int position, GameBoard *gameBoard)
{	
	//-----MODIFIED-----revised getPosition function, now implemented on a struct
	char *structPosition = getPosition(gameBoard, position); 
	

	//check if position is occupied
	return (!isdigit(*structPosition)) ? (printf("Spot is already occupied!\n"), 1) : 0;
	
}

void modifyGameBoard(char player, int position, GameBoard *gameBoard)
{
	
	//-----MODIFIED-----revised getPosition function, now implemented on a struct	
	char *structPosition = getPosition(gameBoard, position); 


	*structPosition = player;
}

//-----MODIFIED----- replace if-else chain with reference 2d array
int checkWinner(char player, GameBoard gameBoard)
{

	if(
		(gameBoard.pos1 == gameBoard.pos2 && gameBoard.pos2 == gameBoard.pos3) ||
		(gameBoard.pos4 == gameBoard.pos5 && gameBoard.pos5 == gameBoard.pos6) ||
		(gameBoard.pos7 == gameBoard.pos8 && gameBoard.pos8 == gameBoard.pos9) ||
		(gameBoard.pos1 == gameBoard.pos4 && gameBoard.pos4 == gameBoard.pos7) ||
		(gameBoard.pos2 == gameBoard.pos5 && gameBoard.pos5 == gameBoard.pos8) ||
		(gameBoard.pos3 == gameBoard.pos6 && gameBoard.pos6 == gameBoard.pos9) ||
		(gameBoard.pos1 == gameBoard.pos5 && gameBoard.pos5 == gameBoard.pos9) ||
		(gameBoard.pos7 == gameBoard.pos5 && gameBoard.pos5 == gameBoard.pos3))

		{
			printGameBoard(gameBoard);
			printf("Player %c Wins!!!\n", player);
			return 1;
		}

	//code falls through, means no winner yet
	return 0;
}




int main() {

	//declare const variables
	const int NUM_PLAYERS = 2;
	const int MAX_TURNS = 9;	

	//declare all variables
	int isPlaying = 1;
	int position;
	char player;

	//tracks number of turns, odd is X, even is O
	int turns = 1; 
	
	//create instance of a gameboard
	GameBoard gameBoard = {'1','2','3','4','5','6','7','8','9'};

	printf("TicTacToe: \n");
	
	//gameplay starts here
	while(isPlaying)
	{

		//determine who's turn it is
		(turns % NUM_PLAYERS != 0) ? (player = 'X') : (player = 'O');

		//print gameBoard
		printGameBoard(gameBoard);

		//get player's move
		do
		{
			printf("Player %c Enter Position: ", player);
			scanf("%d", &position);
			printf("\n");

		}while(checkIllegalMove(position, &gameBoard));

		//update the gameBoard
		modifyGameBoard(player, position, &gameBoard);
		
		//check if a player won
		isPlaying = !checkWinner(player, gameBoard);

		//reaching turns and no winner means a draw game
		(isPlaying && turns == MAX_TURNS) ? (printf("Draw Game!\n")), isPlaying = 0 : (void)0;

		
		//reset flags and update turn counter
		turns++;

	}

	printf("GAME OVER\n");
	return 0;













}

