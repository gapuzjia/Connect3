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
int getLocation(int position)
    {
        int i, j;

        //determine subscripts for row
        if(position > 6)
            i = 2;
        else if (position > 3)
            i = 1;
        else
            i = 0;

        //determine subscripts for column
        if(i == 0)
            j = position - 1;
        else if(i == 1)
            j = position - 4;
        else
            j = position - 7;

        i = i * 10;
        return i + j;
    }



int checkIllegalMove(int position, char gameBoard[3][3])
{
	int subscripts = getLocation(position);
        int i = subscripts / 10;
        int j = subscripts % 10;	
	
	//check if position is occupied
	if(gameBoard[i][j] > 57) //using ASCII
	{
		printf("Spot is already occupied!\n");
		return 1;
	}

}

void modifyGameBoard(char player, int position, char gameBoard[3][3])
{
	int subscripts = getLocation(position);
	int i = subscripts / 10;
	int j = subscripts % 10;

	gameBoard[i][j] = player;
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

		//get player's move
		do
		{
			printf("Player %c Enter Position: ", player);
			scanf("%d", &position);
			printf("\n");

		}while(checkIllegalMove(position, gameBoard));

		//update the gameBoard
		modifyGameBoard(player, position, gameBoard);
		










	}













}

