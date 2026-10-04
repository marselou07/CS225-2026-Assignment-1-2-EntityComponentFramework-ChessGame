#pragma once
#include "chess_base.hh"
#include <stdlib.h> 
#include "stdio.h"
class Pawn : public Piece
{
    public:
    bool FirstMove = true;
    Pawn();
    Pawn(bool isWhite) ;
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class Knight: public Piece
{
    public:
    Knight();
    Knight(bool isWhite) ;
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class Bishop : public Piece
{
    public:
    Bishop();
    Bishop(bool isWhite) ;
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class Rook : public Piece
{
    public:
    Rook();
    Rook(bool isWhite) ;
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;


};
class Queen : public Piece
{
    public:
    Queen();
    Queen(bool isWhite) ;
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class King : public Piece
{
    public:
    King();
    King(bool isWhite);
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};