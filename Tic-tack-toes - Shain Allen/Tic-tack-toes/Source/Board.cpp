//------------------------------------------------------------------------------
//
// File Name:	Board.cpp
// Author(s):	Shain Allen
// Project:		Tic Tac Toe
// Course:		CS170
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "Board.h"
#include <iostream>




namespace CS170
{
	struct Board
	{
		TileState** data; // The 2D game board represented as an array.
	};

	const int boardwidth = 3;
	const int boardhight = 3;

	// Allocate memory for a tic-tac-toe board.
		// Returns:
		//   A pointer to the created board struct.
	Board* BoardCreate()
	{
		//allocate board struct
		Board* board = new Board;

		//allocate array inside of the board
		board->data = new TileState *[boardwidth];

		//allocate the actual board
		for (int r = 0; r < boardwidth; ++r)
		{
			board->data[r] = new TileState[boardhight];
		}

		//set all the spots on the board to emtpy 
		for (int r = 0; r < boardwidth; r++)
		{
			for (int c = 0; c < boardhight; c++)
			{
				board->data[r][c] = tsEMPTY;
			}
		}

		//return board struct
		return board;
	}

	// Free memory for the tic-tac-toe board.
	// Params:
	//   theBoard = A reference to the pointer to the board.
	void BoardFree(Board*& theBoard)
	{
		for (int r = 0; r < boardwidth; r++)
		{
			delete[] theBoard->data[r];
			theBoard->data[r] = nullptr;
		}

		delete[] theBoard->data;
		delete theBoard;
		theBoard = nullptr;
	}

	// Display the contents of the board using the standard output stream.
	// Params:
	//   theBoard = A reference to the game board.
	void BoardDisplay(const Board& board)
	{
		using std::cout;
		using std::endl;

		cout << "-------------" << endl;
		for (int w = 0; w < boardwidth; w++)
		{
			for (int h = 0; h < boardhight; h++)
			{
				if (board.data[w][h] == tsEMPTY)
				{
					cout << "| " << "  ";
				}
				else if (board.data[w][h] == tsPLAYER_ONE)
				{
					cout << "| " << "X ";
				}
				else if (board.data[w][h] == tsPLAYER_TWO)
				{
					cout << "| " << "O ";
				}
			}
			cout << "|" << endl << "-------------" << endl;
		}

	}

	// Place a token on the board at a specific position.
	// Params:
	//   theBoard = A reference to the game board.
	//   row = The row of the board on which to place the token.
	//   column = The column of the board on which to place the token.
	//   value = The value to place in the specified tile.
	// Returns:
	//   Whether the token was able to be placed.
	PlaceResult BoardPlaceToken(Board& board, unsigned row, unsigned column, TileState value)
	{
		if (row == boardwidth && column == boardhight)
		{
			if (board.data[row][column] == tsEMPTY)
			{
				if (value == tsPLAYER_ONE)
				{
					board.data[row][column] = tsPLAYER_ONE;
					return prACCEPTED;
				}
				else
				{
					board.data[row][column] = tsPLAYER_TWO;
					return prACCEPTED;
				}
			}
			else if (board.data[row][column] == tsPLAYER_ONE || board.data[row][column] == tsPLAYER_TWO)
			{
				using std::cout;
				return prREJECTED_OCCUPIED;
			}
		}
		else
		{
			return prREJECTED_OUTOFBOUNDS;
		}
	}

	// Reset the board to an empty state.
	// Params:
	//   theBoard = A reference to the game board.
	/*void BoardReset(Board& board)
	{

	}

	// Get the current state of the board. (Is the game over?)
	// Params:
	//   theBoard = A reference to the game board.
	// Returns:
	//   The current state of the game - win, tie, or open (still going).
	/*BoardState BoardGetState(const Board& board)
	{

	}*/
}