#include <iostream>
#include <string>

int turn = 1; // Used to decide whose player's turn it
char mark{}; // Used for controlling which space the players want to mark
int turnCounter = 0; // For the turn counter

// Array that makes up the board
const int row = 3;
const int col = 3;
char board[row][col] = { {'1', '2', '3'},
				         {'4', '5', '6'},
						 {'7', '8', '9'} };

void drawBoard();
void gaming();
void checkingWin();
void tie();
void whoWon();
void quit();
void resetting();
void clearCin();

int main() {
	std::cout << "------------ Welcome to TicTacToe ------------" << std::endl << std::endl;
	drawBoard();
	gaming();

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
void gaming() {
	drawBoard();
	while (turnCounter <= 9) {
		if (turn == 1) {
			std::cout << "Player One: Select the slot you want to insert an 'X'" << std::endl;
		}
		else if (turn == 2) {
			std::cout << "Player Two: Select the slot you want to insert an 'O'" << std::endl;
		}
		int u{};
		int v{};
		mark = 0;
		std::cin >> mark;
		clearCin();
		for (int u = 0; u < row; u++) {
			for (int v = 0; v < col; v++) {
				if (mark == board[u][v]) {  // If the symbols you try to input match i.e numbers, they will be overwritten by X or O
					if (turn == 1) {
						if (board[u][v] == 'X' || board[u][v] == 'O') {
							std::cout << "select a free slot." << std::endl;
							gaming();
						}
						board[u][v] = 'X';
						drawBoard();
						turn = turn + 1;
					}
					else if (turn == 2) {
						if (board[u][v] == 'X' || board[u][v] == 'O') {
							std::cout << "select a free slot." << std::endl;
							gaming();
						}
						board[u][v] = 'O';
						drawBoard();
						turn = turn - 1;
					}
				}

			}
		}
		checkingWin();
		turnCounter++;
	} // When turnCounter reaches 9 the while loop will be broken and it will reach the tie function
	tie();
}

void checkingWin() { // Checks if slot next to eachother in a line has the same value/symbol. If they are Win
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
		whoWon();
	}
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
		whoWon();
	}
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
		whoWon();
	}
	else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
		whoWon();
	}
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
		whoWon();
	}
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
		whoWon();
	}
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		whoWon();
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		whoWon();
	}
}

void tie() {
	char yesNo{};
	std::cout << "It seems we have reached a tie." << std::endl;
	std::cout << "Would you like to play again? y/n";
	std::cin >> yesNo;
	yesNo = tolower(yesNo);
	if (yesNo == 'y') {
		resetting();
	}
	else if (yesNo == 'n') {
		exit(0);
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
		resetting();
	}
	else if (yesNo == 'n') {
		exit (0);
	}
}

void resetting() {
	char resetBoard[3][3] = { {'1','2','3'},
							  {'4','5','6'},
						      {'7','8','9'} };
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = resetBoard[i][j];
			std::cout << board[i][j];
		}
	}
	turn = 1;
	turnCounter = 0;


	gaming();
}

void clearCin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}