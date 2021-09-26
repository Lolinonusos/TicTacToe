#include <iostream>
#include <string>

int turn = 1; // Used to decide whose player's turn it
char mark{}; // Used for controlling which space the players want to mark
int turnCounter = 0; // For the turn counter, when it  

// Array that makes up the board
const int row = 3;
const int col = 3;
char board[row][col] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void gaming(); // Main function used for playing the game
void drawBoard(); // Draws the board when called
void checkingWin(); // Checks if any win conditions are met
int victory = 0; // Turns to 1 when a win condition is met
void whoWon(); // Is called at the end of a game when a win condition is met and checks which player won
void tie(); // Is called at the end of a game if no win conditions are met
void resetting(); // Resets the all values in the game
void clearCin(); // Clear cin

int main() {
	std::cout << "------------ Welcome to TicTacToe ------------" << std::endl << std::endl;
	std::cout << "Player 1 uses X\n" << std::endl << "Player 2 uses O\n" << std::endl;
	std::cout << "Start the game? y/n ";
	char yesNo;
	std::cin >> yesNo;
	yesNo = tolower(yesNo); 
	if (yesNo == 'y') {
		while (true) { // Put this here to finish the functions that start
			system("cls");
			gaming();
			if (victory == 1) { // Go here if a win condition is met
				whoWon();
			}
			else if (turnCounter >= 9) { // Must check for nine or greater (can check for just nine) since it receives one more at the end of the last turn played
				tie();
			}
		}
	}
	return 0;
}

void drawBoard() {  // This function draws the board and places numbers or symbols in the boxes
	std::cout << "---------------" << std::endl;
	for (int i{}; i < row; i++) {
		for (int j{}; j < col; j++) {
			std::cout <<  "| " << board[i][j] << " |";				// Once it's done placing the three slots it goes out of the inner loop
		}															// and into the outer loop which contains the std::endl at the end of each loop
		std::cout << std::endl << "---------------" << std::endl;   //
	}
}

// This is the game
void gaming() {
	std::cout << "Player 1 starts" << std::endl; // Player 1 always starts
	drawBoard();
	while (turnCounter <= 8) { // When turnCounter reaches 8 the while loop will be broken and it will reach the tie function inside main
		
		// The turn variable decides which player has the current turn and which symbol will be useed to mark a slot
		// If turn = 1 it is P1's turn and a X will be placed
		if (turn == 1) {
			std::cout << "Select the slot where you want to insert an 'X'" << std::endl;
		}
		else if (turn == 2) {
			std::cout << "Select the slot where you want to insert an 'O'" << std::endl;
		}
		int u{};
		int v{};
		mark = 0;
		std::cin >> mark; // Main variable used for playing the game
		clearCin();

		// These for loops go through the entire board array and checks what symbol are in each element
		// If what the player inputed matches what is in an element, the value that is in that element will
		// be overwritten by the players symbol
		for (int u = 0; u < row; u++) {
			for (int v = 0; v < col; v++) {
				if (mark == board[u][v]) { // Succeeds if what the player inputted matches a symbol on the board
					system("cls");
					if (mark == 'X' || mark == 'O') { // Makes it so the players can't overwrite symbols using X or O
						if (turn == 1) {
							std::cout << "Illegal move ser Player 1!\n";
						}
						else if (turn == 2) {
							std::cout << "Illegal move ser Player 2!\n";
						}
						drawBoard();
					}
					else if (turn == 1) { // Places a X on P1's turn
						board[u][v] = 'X';
						std::cout << "Player 2, it is your turn!" << std::endl;
						drawBoard();
						turn = turn + 1; // Turn becomes 2, next loop becomes P2's turn
						turnCounter++; 
						checkingWin();
					}
					else if (turn == 2) { // Places an O on P2's turn
						board[u][v] = 'O';
						std::cout << "Player 1, it is your turn!" << std::endl;
						drawBoard();
						turn = turn - 1;// Turn becomes 1, next loop becomes P1's turn
						turnCounter++;
						checkingWin();
					}
				}
			}
		}
		if (victory == 1) { // Returns to main when this is true
			break;
		}
	} 
}

void checkingWin() { // Checks if slot next to eachother in a line has the same value/symbol. If they are Win
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
		victory = 1;
	}
	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) { // Horizontals?
		victory = 1;
	}
	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
		victory = 1;
	}

	else if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
		victory = 1;
	}
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) { // Verticals
		victory = 1;
	}
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
		victory = 1;
	}

	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) { // Diagonals
		victory = 1;
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		victory = 1;
	}
}

void tie() {
	char yesNo{};
	std::cout << "It seems we have reached a tie." << std::endl;
	std::cout << "Would you like to play again? y/n ";
	std::cin >> yesNo;
	yesNo = tolower(yesNo);
	if (yesNo == 'y') {
		resetting();
	}
	else if (yesNo == 'n') {
		exit(0);
	}
}

void whoWon() { // Checks which player won, uses opposite turn numbers to check victory i.e. if turn=2 P1 won
	char yesNo{};
	if (turn == 2) { 
		std::cout << "Player 1 has won the game!\n" << std::endl;
	}
	else if (turn == 1) {
		std::cout << "Player 2 has won the game!\n" << std::endl;
	}
	std::cout << "Do you want to play again? y/n ";
	std::cin >> yesNo;
	yesNo = tolower(yesNo);
	if (yesNo == 'y') {
		resetting();
	}
	else if (yesNo == 'n') {
		exit (0);
	}
}

void resetting() { // Resets all the values to what I've decided  their default value
	char resetBoard[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
	// For loop that goes through each number in the 'resetBoard' array
	// and each time sets the main 'board' back to the first values 
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = resetBoard[i][j];
			std::cout << board[i][j];
		}
	}
	turn = 1;
	turnCounter = 0;
	victory = 0;
}

void clearCin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}