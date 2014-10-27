#include "catch.hpp"
#include "Board.hpp"
#include "Position.hpp"
#include "Bishop.hpp"
#include "Piece.hpp"

TEST_CASE( "Bishop possible moves ", "[bishop]" )
{
	SECTION("Bishop blocked by ennemies pieces")
	{
		Board board("8/3k4/8/8/8/8/1R4K1/b7 w - - 0 1");
		Position position(0,0);
		PiecePtr bishopPtr = board.getPiecePtr(position);

	    int size = bishopPtr->getPseudoLegalMoves(board).size();
	    REQUIRE(size == 1);
	}

	SECTION("Bishop blocked by allied and ennemies pieces")
	{
		Board board("2K3k1/8/3r1R2/4b3/3r1R2/8/8/8 w - - 0 1");
		Position position(4,4);
		PiecePtr bishopPtr = board.getPiecePtr(position);

	    int size = bishopPtr->getPseudoLegalMoves(board).size();
	    REQUIRE(size == 2);
	}

	SECTION("Bishop free")
	{
		Board board("8/3k4/8/3b4/8/7K/2R5/8 w - - 0 1");
		Position position(3,4);
		PiecePtr bishopPtr = board.getPiecePtr(position);

	    int size = bishopPtr->getPseudoLegalMoves(board).size();
	    REQUIRE(size == 13);
	}

	SECTION("Bishop random test")
	{
		Board board("8/3k4/5R2/8/2bBb3/2R1b3/8/3K4 w - - 0 1");
		Position position(3,3);
		PiecePtr bishopPtr = board.getPiecePtr(position);

	    int size = bishopPtr->getPseudoLegalMoves(board).size();
	    REQUIRE(size == 5);
	}
}