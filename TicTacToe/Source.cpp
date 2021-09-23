#include <iostream>
#include <string>

int turn = 1;
char mark{};
int turnCounter{ 0 };

// Array that makes up the board
const int row = 3;
const int col = 3;
char board[row][col] = { {'1', '2', '3'},
								{'4', '5', '6'},
							    {'7', '8', '9'}};

void drawBoard();
void playing();
void checkingWin();
void clearCin();
void whoWon();
void quit();
int victory = false;

int main() {
	std::cout << "------------ Welcome to TicTacToe ------------" << std::endl << std::endl;
	drawBoard();
	do {
		if (turn == 1) {
			playing();
			drawBoard();
			turn = turn + 1;
		}
		checkingWin();
	} while (victory == 0);
	whoWon();
}

void drawBoard() {  // This function draws the board and places numbers in the boxes
	std::cout << "---------------" << std::endl;
	for (int i{}; i < row; i++) {
		for (int j{}; j < col; j++) {
			std::cout <<  "| " << board[i][j] << " |";				// Once it's done placing the three slots it goes out of the inner loop
		}															// and into the outer loop which contains the std::endl at the end of each loop
		std::cout << std::endl << "---------------" << std::endl;   //
	}
}

// This is player 1 turn
void playing() {

	while (turnCounter < 9) {
		if (turn == 1) {
			std::cout << "Player One: Select the slot you want to insert an 'X'" << std::endl;
		}
		else if (turn == 2) {
			std::cout << "Player Two: Select the slot you want to insert an 'O'" << std::endl;
		}
		int u{};
		int v{};
		mark = 0;
		//clearCin();
		std::cin >> mark;
		for (int u = 0; u < row; u++) {
			for (int v = 0; v < col; v++) {
				if (mark == board[u][v]) {  // If the symbols you try to input match i.e numbers, they will be overwritten by X or O
					if (turn == 1) {
						if (mark != board[u][v]) {
							std::cout << "select a free slot." << std::endl;
							playing();
						}
						board[u][v] = 'X';
						drawBoard();
					}
					else if (turn == 2) {
						board[u][v] = 'O';
						drawBoard();
					}
				}

			}
		}
		turnCounter++;
	}
	//if (board[u][v] != 'X' || board[u][v] != 'O') { // This is supposed to make it impossible to place a symbol on a used slot
		//for (int i{}; i < mark; i++) {			    // This for loop finds the correct slot when you input a number
		//	if (i % 3 == 0 && i > 0) {		        // i is a variable responsible for finding the correct x-axis
		//		j++;
		//	}
		//}
		/*if (turn == 1) {
			board[j][(mark - 1) % 3] = 'X';
			turn = turn + 1;
			table();
		}
		else if (turn == 2) {
			board[j][(mark - 1) % 3] = 'O';
			turn = turn - 1;
			table();
		}*/	//}		
}





void checkingWin() { // Checks if slot next to eachother in a line has the same value/symbol. If they are Win
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
		victory = 1;
	}
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
		victory = 1;
	}
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
		victory = 1;
	}
	else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
		victory = 1;
	}
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
		victory = 1;
	}
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
		victory = 1;
	}
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		victory = 1;
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		victory = 1;
	}
}

void whoWon() {
	char yesNo{};
	if (turn == 2) { // Uses opposite turn numbers to check victory
		std::cout << "Player 1 has won the game!\n" << std::endl;
	}
	else if (turn == 1) {
		std::cout << "Player 2 has won the game!\n" << std::endl;
	}
	std::cout << "Do you want to play again? y/n";
	std::cin >> yesNo;
	if (yesNo == 'y') {
		main();
	}
	else if (yesNo == 'n') {
		exit (0);
	}
}

void quit() {
	char YN;
	std::cout << "Are you sure you want to quit? y/n";
	std::cin >> YN;
	if (YN == 'y' || YN == 'Y') {
		exit (0);
	}
}

void clearCin() {
	std::cin.ignore(32767, '\n');
	std::cin.get();
}