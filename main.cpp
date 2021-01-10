#include <iostream>
#include <iomanip>
#include <array>
#include "tictactoe.h"
using namespace std;

int main(int argc, char* argv[])
{
	int MAX_TURNS = 9;
	int PLAYER_X = 1;
	int PLAYER_O = -1;
	int currentPlayer = 1;
	string currentPlayerString = "X's";
	int row, col;
	array< array<char, 3>, 3> board = { 0 };
	PrintBoard(board);
	for(int i = 0; i < MAX_TURNS + 1; i++)
	{
		// If Method Returns 1
		if (CheckWinner(board) == '1')
		{
			cout << "X Wins." << endl;
			break;
		}
		// If Method Returns -1
		else if (CheckWinner(board) == PLAYER_O)
		{
			cout << "O Wins." << endl;
			break;
		}
		// If Method returns 0 with max turns played 
		else if (CheckWinner(board) == '0' && i == MAX_TURNS)
		{
			cout << "Draw." << endl;
			break;
		}
		cout << currentPlayerString << " Turn: ";
		// Get User Inputs
		GetMove(row, col);
		// If Move is not Valid
		while (MoveIsValid(board, row, col) == false)
		{
			cout << currentPlayerString << " Turn: ";
			GetMove(row, col);
		}
		board[row][col] = currentPlayer;
		if (currentPlayer == PLAYER_X)
		{
			// O Turn
			currentPlayer = PLAYER_O;
			currentPlayerString = "O's";
		}
		else if (currentPlayer == PLAYER_O)
		{
			// X Turn
			currentPlayer = PLAYER_X;
			currentPlayerString = "X's";
		}
		PrintBoard(board);
	}

}