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
    Pawn(bool iswhite, int x, int y, char letter);
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class Knight: public Piece
{
    public:
    Knight();
    Knight(bool isWhite) ;
    Knight(bool iswhite, int x, int y, char letter);
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class Bishop : public Piece
{
    public:
    Bishop();
    Bishop(bool isWhite) ;
    Bishop(bool iswhite, int x, int y, char letter);    
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class Rook : public Piece
{
    public:
    Rook();
    Rook(bool isWhite) ;
    Rook(bool iswhite, int x, int y, char letter);    
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;


};
class Queen : public Piece
{
    public:
    Queen();
    Queen(bool isWhite) ;
    Queen(bool iswhite, int x, int y, char letter);
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};
class King : public Piece
{
    public:
    King();
    King(bool isWhite);
    King(bool iswhite, int x, int y, char letter);
    bool canMoveTo(int x,int y) override;
    PieceType getType() override;
};