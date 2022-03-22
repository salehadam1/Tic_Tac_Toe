#include<stdio.h>
#include "stdlib.h"
#include <time.h>

//name : Saleh adam
//ID   : G00374853

//function ask_player to ask the player to enter the X in the grid
void ask_player(char Player_Enter[10],int num1[10],char name1[10]);
//function ask_coumpter (program) choose random grid to replace with O
void ask_coumpter(char Computer_Enter[10],int num1[10]);
//function display the grid with any change hapend after the player and program enter they X/O
void display(char display[10]);
//function Find_The_winer looking for the winer or the game draw
int Find_The_winer(char winer[10]);
//function diplay_winer print out who is the winer
int diplay_winer(int i,char name[10]);
//function re_start_game restore the array been used in the game for new roll of game
void re_start_game(char ch[10], int num[10]);

int main()
{
	printf("********** Tic-tac-toe **********\n");
	printf("************** Game *************\n");
	//declare variable
	//array Game to story the game enter X/O and show what grid is not used
	char Game[10] = { '1','2','3','4','5','6','7','8','9','\0' };
	//array check is to check that the grid it not be use more than one time
	int check[10] = { 1,2,3,4,5,6,7,8,9,'\0'};
	//char for player name
	char play_name[10];
	//int option to start the game
	int start;
	//let the user choose who will start first
	int start_first;
	//to declare the winer or draw
	int winers;

	//get the player name
	printf("Please Enter you name\n");
	scanf("%s", play_name);
	
	//asking the player to start the game or just exit
	printf("Please Enter\n");
	printf("1 -- To Start the Game\n");
	printf("0 -- To Exit the game\n");
	scanf("%d", &start);
	//while loop to force the player to choose one of the option been give
	while (start != 1 && start != 0)
	{
		printf("! Please Enter\n");
		printf("1 -- To Start the Game\n");
		printf("0 -- To Exit the game\n");
		scanf("%d", &start);
	}

	//while loop to start the game or Exit
	while (start != 0)
	{
		//asking who will start first
		printf("Please Enter\n");
		printf("1 -- To Start the Game First\n");
		printf("2 -- The Computer start the game first\n");
		scanf("%d", &start_first);
		//while loop to force the player to choose one of the option been give
		while (start_first != 1 && start_first != 2)
		{
			printf("! Please Enter\n");
			printf("1 -- To Start the Game First\n");
			printf("2 -- The Computer start the game first\n");
			scanf("%d", &start_first);
		}
		//calling the function to diplay the grid
		display(Game);
		//the player strat first
		if (start_first == 1)
		{
			//for loop to run the game 3 time each time have 2 enter for the grid
			for (int l = 0; l < 3; l++)
			{
				//calling function to let the player choose there enter
				ask_player(Game,check, play_name);
				//function to let the coumpter enter the random choice in the grid
				ask_coumpter(Game,check);
			}//for End
			//we have 6 enter in the grid now check is there is winer
			//calling function find the winer
			winers = Find_The_winer(Game);
			//what ever come from the find the winwe pass to function diplay the winer
			winers = diplay_winer(winers, play_name);
			//if function diplay_winer retuen 0 that mean theres no winer
			if (winers == 0)
			{
				//ask the player and the coumpter one more time by calling the function so going be 8 enter in the grid
				ask_player(Game, check, play_name);
				ask_coumpter(Game, check);
				//calling function find the winer
				winers = Find_The_winer(Game);
				//what ever come from the find the winwe pass to function diplay the winer
				winers = diplay_winer(winers, play_name);
			}
			//if function diplay_winer retuen 0 that mean theres no winer
			if (winers == 0)
			{
				//ask the player to enter the last empty grid 
				ask_player(Game, check, play_name);
				//calling function find the winer
				winers = Find_The_winer(Game);
				//what ever come from the find the winwe pass to function diplay the winer
				winers = diplay_winer(winers, play_name);
			}
			//if function diplay_winer retuen 0 that mean the game is Draw
			if (winers == 0)
			{
				printf("\n*************\n");
				printf("Game is draw\n");
				printf("\n*************\n");
			}
			
		}
		//else the coumpter start first
		else
		{
			//for loop to run the game 3 time each time have 2 enter for the grid
			for (int l = 0; l < 3; l++)
			{
				//function to let the coumpter enter the random choice in the grid
				ask_coumpter(Game, check);
				//calling function to let the player choose there enter
				ask_player(Game, check, play_name);
			}//for End
			//we have 6 enter in the grid now check is there is winer
			//calling function find the winer
			winers = Find_The_winer(Game);
			//what ever come from the find the winwe pass to function diplay the winer
			winers = diplay_winer(winers, play_name);
			//if function diplay_winer retuen 0 that mean theres no winer
			if (winers == 0)
			{
				//ask the player and the coumpter one more time by calling the function so going be 8 enter in the grid
				ask_coumpter(Game, check);
				ask_player(Game, check, play_name);
				//calling function find the winer
				winers = Find_The_winer(Game);
				//what ever come from the find the winwe pass to function diplay the winer
				winers = diplay_winer(winers, play_name);
			}
			//if function diplay_winer retuen 0 that mean theres no winer
			if (winers == 0)
			{
				//let the coumpter enter the last empty grid 
				ask_coumpter(Game, check);
				//calling function find the winer
				winers = Find_The_winer(Game);
				//what ever come from the find the winwe pass to function diplay the winer
				winers = diplay_winer(winers, play_name);
			}
			//if function diplay_winer retuen 0 that mean the game is Draw
			if (winers == 0)
			{
				printf("\n*************\n");
				printf("Game is draw\n");
				printf("\n*************\n");
			}

		}

		//asking the player wann paly aging or just exit the game
		printf("Please Enter\n");
		printf("1 To Play the Game again\n");
		printf("0 To Exit the game\n");
		scanf("%d", &start);
		while (start != 1 && start != 0)
		{
			printf("! Please Enter\n");
			printf("1 To Play the Game again\n");
			printf("0 To Exit the game\n");
			scanf("%d", &start);
		}
		//calling function to set up the 2 array for the new game
		re_start_game(Game, check);
	}
}

//function ask_player
void ask_player(char Player_Enter[10], int num1[10], char name1[10])
{
	//ask to let the player choose the grid 
	int ask;
	//asking the player to enter the grid number
	printf("%s Chois one of the grid to replace with X\n", name1);
	scanf("%d", &ask);
	//while loop to force the player to chosse an empty grid
	while((ask > 9 || ask < 1) || num1[ask-1] == 0)
	{
		printf("! Wrong enter\n");
		printf("%s Plase chois one of the grid to replace it with X\n",name1);
		scanf("%d", &ask);
	}
	//print out the grid number been choose and replace it with X
	printf("\n*****%s select postion %d for X *****\n\n", name1,ask);
	//replace the grid number with X is by passig the array poistion = the grid postion to X
	Player_Enter[ask-1] = 'X';
	//pass the grid postion to the chech array to 0 
	num1[ask - 1] = 0;
	//calling the function to diplay the new grid
	display(Player_Enter);
	
}
//function ask_coumpter
void ask_coumpter(char Computer_Enter[10],int num1[10])
{
	//int num to get the random number for 0 to 10
	int num = rand() % 10 + 1;
	//n = random(10);
	//while loop to force the coumpter to select an empty grid
	while (num1[num - 1] == 0)
	{
		num = rand() % 10;
	}
	//pass the grid postion to the chech array to 0 
	num1[num - 1] = 0;
	//replace the random number in the grid with O is by passig the array poistion = the grid postion to O
	Computer_Enter[num - 1] = 'O';
	//print out the graid number that coumpter select it
	printf("***** Computer select postion %d for O *****\n\n",num);
	//calling the function to diplay the new grid
	display(Computer_Enter);
}
//function to diplay the grid
void display(char display[10])
{
	//print out the grid and for each grid print the value in the array display
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n", display[0], display[1], display[2]);
	printf("|_____|_____|_____|\n");		
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n", display[3], display[4], display[5]);
	printf("|_____|_____|_____|\n");			
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n", display[6], display[7], display[8]);
	printf("|_____|_____|_____|\n\n");
}
//function to get the winer
int Find_The_winer(char winer[10])
{
	int return1 = 0;
	if (winer[0] == 'O' && winer[1] == 'O' && winer[2] == 'O')
	{
		return1 = 1;
	}
	else if (winer[3] == 'O' && winer[4] == 'O' && winer[5] == 'O')
	{
		return1 = 1;
	}
	else if (winer[6] == 'O' && winer[7] == 'O' && winer[8] == 'O')
	{
		return1 = 1;
	}
	else if (winer[0] == 'O' && winer[3] == 'O' && winer[6] == 'O')
	{
		return1 = 1;
	}
	else if (winer[1] == 'O' && winer[4] == 'O' && winer[7] == 'O')
	{
		return1 = 1;
	}
	else if (winer[2] == 'O' && winer[5] == 'O' && winer[8] == 'O')
	{
		return1 = 1;
	}
	else if (winer[0] == 'O' && winer[4] == 'O' && winer[8] == 'O')
	{
		return1 = 1;
	}
	else if (winer[2] == 'O' && winer[4] == 'O' && winer[6] == 'O')
	{
		return1 = 1;
	}

	if (winer[0] == 'X' && winer[1] == 'X' && winer[2] == 'X')
	{
		return1 = 2;
	}
	else if (winer[3] == 'X' && winer[4] == 'X' && winer[5] == 'X')
	{
		return1 = 2;
	}
	else if (winer[6] == 'X' && winer[7] == 'X' && winer[8] == 'X')
	{
		return1 = 2;
	}
	else if (winer[0] == 'X' && winer[3] == 'X' && winer[6] == 'X')
	{
		return1 = 2;
	}
	else if (winer[1] == 'X' && winer[4] == 'X' && winer[7] == 'X')
	{
		return1 = 2;
	}
	else if (winer[2] == 'X' && winer[5] == 'X' && winer[8] == 'X')
	{
		return1 = 2;
	}
	else if (winer[0] == 'X' && winer[4] == 'X' && winer[8] == 'X')
	{
		return1 = 2;
	}
	else if (winer[2] == 'X' && winer[4] == 'X' && winer[6] == 'X')
	{
		return1 = 2;
	}
	return return1;
}
int diplay_winer(int i, char name[10])
{
	int num = 0;
	if (i == 1)
	{
		printf("\n*************\n");
		printf("Computer win\n");
		printf("*************\n\n");
		num = 1;
	}
	else if (i == 2)
	{
		printf("\n*************\n");
		printf("player %s win\n",name);
		printf("*************\n\n");
		num = i;
	}
	return num;
}
void re_start_game(char ch[10], int num[10])
{
	for (int i = 0; i < 9; i++)
	{
		num[i] = i + 1;
	}
	ch[0] = '1';
	ch[1] = '2';
	ch[2] = '3';
	ch[3] = '4';
	ch[4] = '5';
	ch[5] = '6';
	ch[6] = '7';
	ch[7] = '8';
	ch[8] = '9';
	ch[9] = '\0';
}
	 
