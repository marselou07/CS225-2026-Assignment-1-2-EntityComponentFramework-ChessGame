#pragma once
#include "chess_base.hh"
#include <stdlib.h> 
#include "stdio.h"
class Pawn : public Piece
{ 
    public:
    bool FirstMove = true;
    Pawn(bool isWhite, int x, int y, char letter);
    Pawn(bool isWhite);
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class Knight: public Piece
{
    public:
    Knight(bool isWhite, int x, int y, char letter);
    Knight(bool isWhite) ;
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class Bishop : public Piece
{
    public:
    Bishop(bool isWhite, int x, int y, char letter);
    Bishop(bool isWhite) ;
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class Rook : public Piece
{
    public:
    Rook(bool isWhite, int x, int y, char letter);
    Rook(bool isWhite) ;
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;


};
class Queen : public Piece
{
    public:
    Queen(bool isWhite, int x, int y, char letter);
    Queen(bool isWhite) ;
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class King : public Piece
{
    public:
    King(bool isWhite, int x, int y, char letter);
    King(bool isWhite);
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};