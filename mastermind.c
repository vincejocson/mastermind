/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.
<Jocson, Vince Miguel S.> - <12336149> - <S12>
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/****************************************
Description : This function displays the title for the game.
@param : 
@return : 
 *****************************************/
void displayLogo(){
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("%39s", "- - - - - M A S T E R M I N D - - - - -");
	printf("\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
}

/****************************************
Description : This function displays the title screen and main menu for the game. 
Allows the player to select the number of games and difficulty. Also shows the number of
available pegs and attempts per difficulty. Stores their numbers in their respective addresses.
@param : *nGames, *nDiff, *nPegs, *maxAttempt
@return : 
 *****************************************/
void displayTitleScreen(int *nGames, int *nDiff, int *nPegs, int *maxAttempt){
	int pInput;
	displayLogo();
	printf("\n\n");
	printf("SELECT NUMBER OF GAMES:\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("[1] - 2 GAMES\n");
	printf("[2] - 4 GAMES\n");
	printf("[3] - 6 GAMES\n");
	printf("[4] - 8 GAMES\n");
	printf("[5] - 10 GAMES\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n");
	do{
		printf("[INPUT]: ");
		scanf("%d", &pInput);
		switch(pInput){
			case 1: *nGames = 2; printf("[NUMBER OF GAMES]: 2\n"); break;
			case 2: *nGames = 4; printf("[NUMBER OF GAMES]: 4\n"); break;
			case 3: *nGames = 6; printf("[NUMBER OF GAMES]: 6\n"); break;
			case 4: *nGames = 8; printf("[NUMBER OF GAMES]: 8\n"); break;
			case 5: *nGames = 10; printf("[NUMBER OF GAMES]: 10\n"); break;
			default: printf("[SYSTEM MESSAGE]: INVALID INPUT!\n\n");
		}
	} while (pInput > 5 || pInput < 1);
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	
	printf("SELECT DIFFICULTY:\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("[1] - EASY\n");
	printf("[2] - AVERAGE\n");
	printf("[3] - DIFFICULT\n");
	printf("[4] - EXTREME\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n");
	do{
		printf("[INPUT]: ");
		scanf("%d", &pInput);
		switch(pInput){
			case 1: 
				*nDiff = 1; *nPegs = 6; *maxAttempt = 10; 
				printf("[DIFFICULTY]: EASY\n"); 
				printf("[NUMBER OF ATTEMPTS]: 10\n"); 
				printf("[NUMBER OF CODE PEGS]: 6\n"); 
				break;
			case 2: 
				*nDiff = 2; *nPegs = 8; *maxAttempt = 12; 
				printf("[DIFFICULTY]: AVERAGE\n"); 
				printf("[NUMBER OF ATTEMPTS]: 12\n"); 
				printf("[NUMBER OF CODE PEGS]: 8\n"); 
				break;
			case 3: 
				*nDiff = 3; *nPegs = 10; *maxAttempt = 16; 
				printf("[DIFFICULTY]: DIFFICULT\n"); 
				printf("[NUMBER OF ATTEMPTS]: 16\n"); 
				printf("[NUMBER OF CODE PEGS]: 10\n"); 
				break;
			case 4: 
				*nDiff = 4; *nPegs = 16; *maxAttempt = 20; 
				printf("[DIFFICULTY]: EXTREME\n"); 
				printf("[NUMBER OF ATTEMPTS]: 20\n"); 
				printf("[NUMBER OF CODE PEGS]: 16\n"); 
				break;
			default: printf("[SYSTEM MESSAGE]: INVALID INPUT!\n\n");
		}
	} while (pInput > 4 || pInput < 1);
}

/****************************************
Description : This function displays the pre-game screen when player is the codebreaker.
Shows the number of available pegs to be used. 
@param : nPegs
@return : 
 *****************************************/
void displayPlayerCodebreaker(int nPegs){
	int i;
	char peg = 'A';
	
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("COMPUTER HAS GENERATED CODE\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("PLAYER'S TURN TO ATTEMPT: \n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("ENTER 4 LETTER CODE FROM THE PEGS:\n");
	printf("[");
	for (i = 1; i <= nPegs; i++){
		printf("%c, ", peg);
		if (i == 13)
			printf("\n ");
		peg += 1;
	}
	printf("\b\b]");
	printf("\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	
}

/****************************************
Description : This function prints the part of the screen that indicates what game or round it currently is
@param : game
@return : 
 *****************************************/
void displayGameCount(int game){
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("GAME %d:\n", game);
}

/****************************************
Description : This function generates random numbers from the range of available pegs
and stores them in 4 variables that represent the pegs to be used for codemaking or codebreaking.
@param : *p1, *p2, *p3, *p4, nPegs
@return : 
 *****************************************/
void generatePeg(int *p1, int *p2, int *p3, int *p4, int nPegs){
	*p1 = (rand() % (nPegs - 1 + 1)) + 1;
	do{
		*p2 = (rand() % (nPegs - 1 + 1)) + 1;
	} while(*p2 == *p1);
	
	do{
		*p3 = (rand() % (nPegs - 1 + 1)) + 1;	
	} while(*p3 == *p1 || *p3 == *p2);
	do{
		*p4 = (rand() % (nPegs - 1 + 1)) + 1;
	} while(*p4 == *p1 || *p4 == *p2 || *p4 == *p3);
}

/****************************************
Description : This function converts the character of the peg into an integer by utilizing ASCII 
and storing it in an address
@param : c, *n
@return : 
 *****************************************/
void convertToNum(char c, int *n){
	if (c < 81)
		*n = c - 64;
	else
		*n = c - 96;
}

/****************************************
Description : This function converts the number value of the peg into a character by utilizing ASCII 
and returning it
@param : n
@return : 
 *****************************************/
char convertToChar(int n){
	return '@' + n; 
}

/****************************************
Description : This function calls convertToNum for all 4 characters in the code
and storing it in respective addresses
@param : c1, c2, c3, c4, *n1, *n2, *n3, *n4
@return : 
 *****************************************/
void convertToNumCode(char c1, char c2, char c3, char c4, int *n1, int *n2, int *n3, int *n4){
	convertToNum(c1, n1);
	convertToNum(c2, n2);
	convertToNum(c3, n3);
	convertToNum(c4, n4);
}

/****************************************
Description : This function calls convertToChar for all 4 digits in the code and prints them
@param : p1, p2, p3, p4
@return : 
 *****************************************/
void convertToCharCode(int p1, int p2, int p3, int p4){
	printf("%c ", convertToChar(p1));
	printf("%c ", convertToChar(p2));
	printf("%c ", convertToChar(p3));
	printf("%c", convertToChar(p4));
}

/****************************************
Description : This function returns 1 if the number value of a character in a code attempt is equal to
the number value of its parallel in the secret code. Returns 0 otherwise.
@param : n, p
@return : int; 1 for true, 0 for false
 *****************************************/
int checkBlack(int n, int p){
	if (n == p)
		return 1;
	else
		return 0;
}

/****************************************
Description : This function returns 1 if the number value of a character in a code attempt is equal to
the number value of the characters in the secret code except for its parallel. Returns 0 otherwise.
@param : n, x, y, z
@return : int; 1 for true, 0 for false
 *****************************************/
int checkWhite(int n, int x, int y, int z){
	if (n == x || n == y || n == z)
		return 1;
	else
		return 0;
}

/****************************************
Description : This function returns 1 if the player or computer wins the round by checking if there are 4 black pegs. 
This is done by calling checkBlack for all code pegs. 
@param : n1, n2, n3, n4, p1, p2, p3, p4
@return : int; 1 for true, 0 for false
 *****************************************/
int checkWin(int n1, int n2, int n3, int n4, int p1, int p2, int p3, int p4){
	if (checkBlack(n1, p1) == 1 && checkBlack(n2, p2) == 1 && checkBlack(n3, p3) == 1 && checkBlack(n4, p4) == 1)
		return 1;
	else
		return 0;
}

/****************************************
Description : This function prints the white and/or black pegs yielded by the guess attempt. This is done by calling
checkBlack and checkWhite for all code pegs. Stores the number of white and black pegs in their respective addresses.
@param : n1, n2, n3, n4, p1, p2, p3, p4, *white, *black
@return : 
 *****************************************/
void displayResult(int n1, int n2, int n3, int n4, int p1, int p2, int p3, int p4, int *white, int *black){
	printf("[RESULTS]: ");
	if (checkBlack(n1, p1) == 1){
		printf("B ");
		*black += 1;
	}
	if (checkBlack(n2, p2) == 1){
		printf("B ");
		*black += 1;
	}
	if (checkBlack(n3, p3) == 1){
		printf("B ");
		*black += 1;
	}		
	if (checkBlack(n4, p4) == 1){
		printf("B ");
		*black += 1;
	}
	if (checkWin(n1, n2, n3, n4, p1, p2, p3, p4) == 1)
		printf("WIN");
	
	else{
		if (checkWhite(n1, p2, p3, p4) == 1){
			printf("W ");
			*white += 1;
		}
		if (checkWhite(n2, p1 ,p3, p4) == 1){
			printf("W ");
			*white += 1;
		}
		if (checkWhite(n3, p1 ,p2, p4) == 1){
			printf("W ");
			*white += 1;
		}	
		if (checkWhite(n4, p1 ,p2, p3) == 1){
			printf("W ");
			*white += 1;
		}
	}
}

/****************************************
Description : This function prints the screen after a successful guess or if the max attempt is reached.
checkWin is called to determine if there was a win.
@param : n1, n2, n3, n4, p1, p2, p3, p4
@return : 
 *****************************************/
void displayGameEnd(int n1, int n2, int n3, int n4, int p1, int p2, int p3, int p4){
	if (checkWin(n1, n2, n3, n4, p1, p2, p3, p4) == 1)
		printf("[SYSTEM]: SUCCESSFUL ATTEMPT!");
	else
		printf("[SYSTEM]: MAX ATTEMPTS REACHED");
	printf("\n");
	printf("[SYSTEM]: THE CODE WAS [");
	convertToCharCode(p1, p2, p3, p4);
	printf("]\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
}

/****************************************
Description : This function computes the score after the round and stores it in its address.
@param : nAttempt, *score, win
@return : 
 *****************************************/
void computeScore(int nAttempt, int *score, int win){
	if (win == 1)
		*score += nAttempt;
	else
		*score += nAttempt + 1;
}

/****************************************
Description : This function prints out the scoreboard for the player and computer
@param : playerScore, comScore
@return : 
 *****************************************/
void displayScoreBoard(int playerScore, int comScore){
	printf("PLAYER: %d ", playerScore);
	printf("%26s %d", "COMPUTER:", comScore);
	printf("\n");
}

/****************************************
Description : This function prints out the screen for when the player becomes the codemaker. Shows the available pegs
to be used.
@param : nPegs
@return : 
 *****************************************/
void displayPlayerCodemaker(int nPegs){
	int i;
	char peg = 'A';
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("SWITCHING SIDES . . . . . . . . . . . .\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("PLAYER'S TURN TO GENERATE CODE: \n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("ENTER 4 LETTER CODE FROM THE PEGS:\n");
	printf("(NO REPETITIONS ALLOWED)\n");
	printf("[");
	for (i = 1; i <= nPegs; i++){
		printf("%c, ", peg);
		if (i == 13)
			printf("\n ");
		peg += 1;
	}
	printf("\b\b]");
	printf("\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
}

/****************************************
Description : This function prints the message when computer becomes the codebreaker
@param :
@return : 
 *****************************************/
void displayComputerCodebreaker(){
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("COMPUTER'S TURN TO ATTEMPT . . . . . . . \n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
}

/****************************************
Description : This function runs the pseudo-AI guessing of the computer as the codebreaker. Generates an initial guess
by calling generatePeg and has the ability to store correct code pegs. Randomizes the code peg if it is not the correct one.
@return : 
 *****************************************/
void computerGuess(int *n1, int *n2, int *n3, int *n4, int p1, int p2, int p3, int p4, int nPegs, int nAttempt){
	int m1 = *n1;
	int m2 = *n2;
	int m3 = *n3;
	int m4 = *n4;
	if (nAttempt == 1)
		generatePeg(n1, n2, n3, n4, nPegs);
	else{
		if (checkBlack(*n1, p1) == 0)
			do{
				*n1 = (rand() % (nPegs - 1 + 1)) + 1;
			} while (*n1 == m1 || *n1 == *n2 || *n1 == *n3 || *n1 == *n4);
		if (checkBlack(*n2, p2) != 1)
			do{
				*n2 = (rand() % (nPegs - 1 + 1)) + 1;
			} while (*n2 == m2 || *n2 == *n1 || *n2 == *n3 || *n2 == *n4);
		if (checkBlack(*n3, p3) != 1)
			do{
				*n3 = (rand() % (nPegs - 1 + 1)) + 1;
			} while (*n3 == m3 || *n3 == *n1 || *n3 == *n2 || *n3 == *n4);			
		if (checkBlack(*n4, p4) != 1)
			do{
				*n4 = (rand() % (nPegs - 1 + 1)) + 1;
			} while (*n4 == m4 || *n4 == *n1 || *n4 == *n2 || *n4 == *n3);			
	}
}

/****************************************
Description : This function prints the final screen when all the games or rounds have been finished and shows
who the winner is.
@param : playerScore, comScore
@return : 
 *****************************************/
void displayGameOver(int playerScore, int comScore){
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	if (playerScore > comScore)
		printf("%26s", "PLAYER WINS!");
	else if (playerScore < comScore)
		printf("%27s", "COMPUTER WINS!");
	else 
		printf("%25s", "GAME DRAW!");
	printf("\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
	printf("-------------- GAME OVER ---------------\n");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("__________");
	printf("\n\n");
}

/****************************************
Description : Validates the code inputted by the player. Makes sure it has no duplicates and is within the
available code pegs given. Returns 1 if the code is valid.
@param : n1, n2, n3, n4, nPegs
@return : int; 1 for true, 0 for false
 *****************************************/
int validateCode(int n1, int n2, int n3, int n4, int nPegs){
	if (n1 == n2 || n1 == n2 || n1 == n3 || n1 == n4 || n2 == n3 || n2 == n4 || n3 == n4)
		return 0;
	if (n1 > nPegs || n2 > nPegs || n3 > nPegs || n4 > nPegs)
		return 0;
	else
		return 1;
}


int main(){
	int nGames, nDiff, nPegs, maxAttempt;
	int p1, p2, p3, p4;
	char c1, c2, c3, c4;
	int n1, n2, n3, n4;
	int nWhite = 0;
	int nBlack = 0;
	int nAttempt = 0;
	int attemptend = 0; //Determines if the round is ended by max attempts reached.
	int win = 0;		//Determines if the round is ended by a successful guess.
	int playerScore = 0;
	int comScore = 0;
	int gamecount;	//Serves as an index for the game counting in the for loop.
	
	srand(time(0));
	displayTitleScreen(&nGames, &nDiff, &nPegs, &maxAttempt);
	
	for (gamecount = 1; gamecount <= nGames; gamecount++){	//The main for loop that will loop the code for the amount of games
		//Games start with player as the codebreaker
		displayGameCount(gamecount);
		generatePeg(&p1, &p2, &p3, &p4, nPegs);
		displayPlayerCodebreaker(nPegs);
		do{	//This starts the loop for the entire attempting sequence
			nAttempt++;
			do{	//This loop is responsible for code validation
				printf("[ATTEMPT %d]: ", nAttempt);
				scanf(" %c %c %c %c", &c1, &c2, &c3, &c4);
				convertToNumCode(c1, c2, c3, c4, &n1, &n2, &n3, &n4);
				if (validateCode(n1, n2, n3, n4, nPegs) == 0)
					printf("[SYSTEM]: INVALID CODE!\n\n");
			} while (validateCode(n1, n2, n3, n4, nPegs) == 0);
			displayResult(n1, n2, n3, n4, p1, p2, p3, p4, &nWhite, &nBlack);
			printf("\n\n");
			if (checkWin(n1, n2, n3, n4, p1, p2, p3, p4) == 1)
				win = 1;	
			else if (nAttempt == maxAttempt)
				attemptend = 1;
			nBlack = 0;	//Black and white pegs are reset before the next attempt
			nWhite = 0;
		} while (attemptend != 1 && win != 1);
		displayGameEnd(n1, n2, n3, n4, p1, p2, p3, p4);
		computeScore(nAttempt, &comScore, win);
		displayScoreBoard(playerScore, comScore);
		
		// Switching sides: Player will now be the codemaker
		// Values are reset before the next game/round
		nAttempt = 0;
		win = 0;
		attemptend = 0;	
		
		gamecount++; //game count increments
		displayGameCount(gamecount);
		displayPlayerCodemaker(nPegs);
		do{	//This loop is responsible for code validation
			printf("[ENTER CODE]: ");
			scanf(" %c %c %c %c", &c1, &c2, &c3, &c4);
			convertToNumCode(c1, c2, c3, c4, &p1, &p2, &p3, &p4);
			if (validateCode(p1, p2, p3, p4, nPegs) == 0)
				printf("[SYSTEM]: INVALID CODE!\n\n");
		} while (validateCode(p1, p2, p3, p4, nPegs) == 0);
		displayComputerCodebreaker();
		do{	//This starts the loop for the entire guessing sequence by the computer codebreaker
			nAttempt++;
			computerGuess(&n1, &n2, &n3, &n4, p1, p2, p3, p4, nPegs, nAttempt);
				//printf("%d%d%d%d", n1, n2, n3, n4);	//show num values for dev
			printf("[ATTEMPT %d]: ", nAttempt);
			convertToCharCode(n1, n2, n3, n4);
			printf("\n");
			displayResult(n1, n2, n3, n4, p1, p2, p3, p4, &nWhite, &nBlack);
				//printf("%d %d", nBlack, nWhite);	//show nblack and nwhite for dev
			printf("\n\n");
			if (checkWin(n1, n2, n3, n4, p1, p2, p3, p4) == 1)
				win = 1;	
			else if (nAttempt == maxAttempt)
				attemptend = 1;
			nBlack = 0;
			nWhite = 0;
		} while (attemptend != 1 && win != 1);
		displayGameEnd(n1, n2, n3, n4, p1, p2, p3, p4);
		computeScore(nAttempt, &playerScore, win);
		displayScoreBoard(playerScore, comScore);
		
		//Values are reset again before the next pair of rounds start again.
		nAttempt = 0;
		win = 0;
		attemptend = 0;
	}
	
	//All games end at the end of the for loop and displays the final screen
	displayGameOver(playerScore, comScore);
	
	return 0;
}