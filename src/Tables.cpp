#include "Tables.hpp"

/* List of tables declarations*/
U64 Tables::FRONT_SPANS[2][64];
U64 Tables::PAWN_ATTACK_SPANS[2][64];
U64 Tables::PASSED_PAWN_MASK[2][64];
U64 Tables::ATTACK_TABLE[Piece::PIECE_TYPE_NB][64];

/* Methods */
void Tables::init()
{
    for (unsigned int square=0; square<64; ++square)
    {
        FRONT_SPANS[WHITE][square] = frontBB(square,WHITE);
        FRONT_SPANS[BLACK][square] = frontBB(square,BLACK);
        PAWN_ATTACK_SPANS[WHITE][square] = sidesBB(square,WHITE);
        PAWN_ATTACK_SPANS[BLACK][square] = sidesBB(square,BLACK);
        PASSED_PAWN_MASK[WHITE][square] = FRONT_SPANS[WHITE][square] | PAWN_ATTACK_SPANS[WHITE][square];
        PASSED_PAWN_MASK[BLACK][square] = FRONT_SPANS[BLACK][square] | PAWN_ATTACK_SPANS[BLACK][square];
    }
}

U64 Tables::frontBB(const unsigned int pos,Color color)
{
    U64 shift = 0xffffffffffffffff << (pos+1); // pos+1 for WHITE, take the complement for BLACk
    if (color == BLACK){shift = (~shift) >> 1;}
    return  shift & MASK_FILE[Utils::getFile(pos)];
}


U64 Tables::sidesBB(const unsigned int pos,Color color)
{
    unsigned int file = Utils::getFile(pos);
    U64 leftSide(0);
    U64 rightSide(0);
    if (file > 0){leftSide=frontBB(pos-1,color);}
    if (file < 7){rightSide=frontBB(pos+1,color);}
    return leftSide | rightSide;
}


U64 Tables::getKingAttacks(const unsigned int pos) const
{

}

U64 Tables::getQueenAttacks(const unsigned int pos) const
{

}

U64 Tables::getRookAttacks(const unsigned int pos) const
{

}

U64 Tables::getBishopAttacks(const unsigned int pos) const
{

}

U64 Tables::getKnightAttacks(const unsigned int pos) const
{

}
