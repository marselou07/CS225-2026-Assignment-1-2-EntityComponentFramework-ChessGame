#pragma once
#include "chess_base.hh"
class Pawn : public Piece
{
    public:
    Pawn();
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class Knight: public Piece
{
    public:
    Knight();
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};