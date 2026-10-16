#include "chess_pieces.hh"
/******************************************************************************
filename    chess_pieces.cpp
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  2
due date    06/10/2026

Brief Description: This program set the logic for all the pieces in the game.
******************************************************************************/
//----------------------------
//Pawn
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @param x = position om x
 * @param y = position on y
 * @param letter: the symbol the piece has
 * @return nothing
 */
Pawn::Pawn(bool isWhite, int x, int y, char letter) : Piece(isWhite,x,y,letter)
{
    
}
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @return nothing
 */
Pawn::Pawn(bool isWhite)
{
    this->is_color_white = isWhite;
}
/**
 * canMoveTo
 * @param x = position om x
 * @param y = position on y
 * @return true if position is valid
 */
bool Pawn::canMoveTo(int x, int y)
{
    //Get the position and the color for movement
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int distance = (this->isWhite() ? 1 : -1);
    //If the pawn move 1 in the direction
    if(posX == x && posY  + distance== y)
    {
        FirstMove= false;
        return true;
    }
    //If is the first move of the pawn it can move 2 squares
    else if(FirstMove == true && posX == x && posY  + 2* distance== y)
    {
        FirstMove= false;
        return true;
    }
    //Validate take other pieces
    else if((posX + 1 == x || posX -1 == x)&&posY  + distance== y)
    {
        FirstMove= false;
        return true;
    }
    return false;
}
/**
 * getType
 * @param nothing
 * @return the type of the piece
 */
PieceType Pawn::getType()
{

    return PAWN;
}
//-------------------------------------
//Knigh
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @param x = position om x
 * @param y = position on y
 * @param letter: the symbol the piece has
 * @return nothing
 */
Knight::Knight(bool isWhite, int x, int y, char letter): Piece(isWhite,x,y,letter)
{
}
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @return nothing
 */
Knight::Knight(bool isWhite)
{
    this->is_color_white = isWhite;
}
/**
 * canMoveTo
 * @param x = position om x
 * @param y = position on y
 * @return true if position is valid
 */
bool Knight::canMoveTo(int x, int y)
{
    //Get the position and the distance between the origin and ç
    //destiny
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int dx = abs(x-posX);
    int dy = abs(y - posY);
    //If is moving 2 on x and 1 in y or opposite it can move
    if(dx == 1 && dy == 2 || dx == 2 && dy == 1)
    {
        return true;
    }
    return false;
}
/**
 * getType
 * @param nothing
 * @return the type of the piece
 */
PieceType Knight::getType()
{
    return KNIGHT;
}
//----------------------------------------
//Bishop
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @param x = position om x
 * @param y = position on y
 * @param letter: the symbol the piece has
 * @return nothing
 */
Bishop::Bishop(bool isWhite, int x, int y, char letter): Piece(isWhite,x,y,letter)
{
}
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @return nothing
 */
Bishop::Bishop(bool isWhite)
{
    is_color_white = isWhite;
}
/**
 * canMoveTo
 * @param x = position om x
 * @param y = position on y
 * @return true if position is valid
 */
bool Bishop::canMoveTo(int x, int y)
{
    //Get the distance between the points
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int distanceX = std::abs(x- posX);
    int distanceY = std::abs(y -posY);
    //If the movement in x and y are equal is true
    if(abs(distanceX) == abs(distanceY))
    {
        return true;
    }
    return false;
}
/**
 * getType
 * @param nothing
 * @return the type of the piece
 */
PieceType Bishop::getType()
{
    return BISHOP;
}
//-----------------------------
//Rook
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @param x = position om x
 * @param y = position on y
 * @param letter: the symbol the piece has
 * @return nothing
 */
Rook::Rook(bool isWhite, int x, int y, char letter): Piece(isWhite,x,y,letter)
{
}
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @return nothing
 */
Rook::Rook(bool isWhite)
{
    is_color_white = isWhite;

}
/**
 * canMoveTo
 * @param x = position om x
 * @param y = position on y
 * @return true if position is valid
 */
bool Rook::canMoveTo(int x, int y)
{
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    //If the has move in on y but not on x
    if(posX == x && posY != y)
    {
        return true;
    }
    //If the has move in on x but not on y
    else if(posX != x && posY == y)
    {
        return true;
    }
    return false;
}
/**
 * getType
 * @param nothing
 * @return the type of the piece
 */
PieceType Rook::getType()
{
    return ROOK;
}
//----------------------------
//Queen
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @param x = position om x
 * @param y = position on y
 * @param letter: the symbol the piece has
 * @return nothing
 */
Queen::Queen(bool isWhite, int x, int y, char letter): Piece(isWhite,x,y,letter)
{
}
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @return nothing
 */
Queen::Queen(bool isWhite)
{
    is_color_white = isWhite;
}
/**
 * canMoveTo
 * @param x = position om x
 * @param y = position on y
 * @return true if position is valid
 */
bool Queen::canMoveTo(int x, int y)
{
    //Get the distance and mix rook and bishop logic
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int distanceX = std::abs(x- posX);
    int distanceY = std::abs(y -posY);
    if(abs(distanceX) == abs(distanceY))
    {
        return true;
    }
    else if(posX == x && posY != y)
    {
        return true;
    }
    else if(posX != x && posY == y)
    {
        return true;
    }
    return false;
}
/**
 * getType
 * @param nothing
 * @return the type of the piece
 */
PieceType Queen::getType()
{
    return QUEEN;
}
//--------------------------------------------
//King
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @param x = position om x
 * @param y = position on y
 * @param letter: the symbol the piece has
 * @return nothing
 */
King::King(bool isWhite, int x, int y, char letter): Piece(isWhite,x,y,letter)
{
}
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @return nothing
 */
King::King(bool isWhite)
{
    is_color_white = isWhite;
}
/**
 * canMoveTo
 * @param x = position om x
 * @param y = position on y
 * @return true if position is valid
 */
bool King::canMoveTo(int x, int y)
{
    //If the king moves 1 in any direction go
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int distanceX = std::abs(x- posX);
    int distanceY = std::abs(y -posY);
    if(distanceX <= 1 && distanceY <= 1)
    {
        return true;
    }
    return false;
}
/**
 * getType
 * @param nothing
 * @return the type of the piece
 */
PieceType King::getType()
{
    return KING;
}
