#include "chess_pieces.hh"
//----------------------------
//Pawn
Pawn::Pawn()
{
}

Pawn::Pawn(bool isWhite)
{
    this->is_color_white = isWhite;
}

Pawn::Pawn(bool iswhite, int x, int y, char letter)
{
    is_color_white = iswhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

bool Pawn::canMoveTo(int x, int y)
{
    bool bounds = x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
    if(bounds == false)
    {
        return bounds;
    }
    if(this->is_color_white == true)
    {
    if((this->getPosition())->getX() == x &&(this->getPosition())->getY() +1  == y)
    {
        this->FirstMove = false;
        return true;
    }
    else if(((this->getPosition())->getX() == x &&(this->getPosition())->getY()+ 2  == y )&& this->FirstMove == true)
    {
        this->FirstMove = false;
        return true;
    }        
    }
    else
    {
    if((this->getPosition())->getX() == x &&(this->getPosition())->getY() -1  == y)
    {
        this->FirstMove = false;
        return true;
    }
    else if(((this->getPosition())->getX() == x &&(this->getPosition())->getY() - 2  == y )&& this->FirstMove == true)
    {
        this->FirstMove = false;
        return true;
    }
    }

    return false;
}

PieceType Pawn::getType()
{

    return PAWN;
}
//-------------------------------------
//Knigh

Knight::Knight()
{
}

Knight::Knight(bool isWhite)
{
    this->is_color_white = isWhite;
}

Knight::Knight(bool iswhite, int x, int y, char letter)
{
    is_color_white = iswhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

bool Knight::canMoveTo(int x, int y)
{
    bool bounds = x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    if(bounds == false)
    {
        return bounds;
    }
    if((posX + 1== x && posY + 2  == y) || (posX + 1== x && posY - 2  == y))
    {
        return true;
    }
    else if((posX + 2== x && posY + 1  == y) || (posX + 2== x && posY - 1  == y))
    {
        return true;
    }
    else if((posX - 1== x && posY + 2  == y) || (posX - 1== x && posY - 2  == y))
    {
        return false;
    }
    else if((posX - 2== x && posY + 1  == y) || (posX - 2== x && posY - 1  == y))
    {
        return true;
    }
    return false;
}

PieceType Knight::getType()
{
    return KNIGHT;
}
//----------------------------------------
//Bishop

Bishop::Bishop()
{
}

Bishop::Bishop(bool isWhite)
{
    is_color_white = isWhite;
}

Bishop::Bishop(bool iswhite, int x, int y, char letter)
{    
    is_color_white = iswhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

bool Bishop::canMoveTo(int x, int y)
{
    bool bounds = x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int distanceX = std::abs(x- posX);
    int distanceY = std::abs(y -posY);
    if(distanceX != distanceY)
    {
        return false;
    }
    else if(bounds == false)
    {
        return bounds;
    }
    else if(posX + distanceX == x && posY+ distanceY== y || posX - distanceX == x && posY - distanceY== y)
    {
        return true;
    }
    else if(posX - distanceX == x && posY + distanceY== y || posX + distanceX == x && posY - distanceY== y)
    {
        return true;
    }
    return false;
}

PieceType Bishop::getType()
{
    return BISHOP;
}
//-----------------------------
//Rook

Rook::Rook()
{
}

Rook::Rook(bool isWhite)
{
    is_color_white = isWhite;

}

Rook::Rook(bool iswhite, int x, int y, char letter)
{
    is_color_white = iswhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

bool Rook::canMoveTo(int x, int y)
{
    bool bounds = x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int distanceX = std::abs(x- posX);
    int distanceY = std::abs(y -posY);
    if(bounds == false)
    {
        return bounds;
    }
    if((posX + distanceX) == x && posY == y ||
     posX == x && posY + distanceY == y)
    {
        return true;
    }
    else if((posX - distanceX) == x && posY == y ||
     posX == x && posY - distanceY == y)
    {
        return true;
    }
    return false;
}

PieceType Rook::getType()
{
    return ROOK;
}
//----------------------------
//Queen

Queen::Queen()
{
}

Queen::Queen(bool isWhite)
{
    is_color_white = isWhite;
}

Queen::Queen(bool iswhite, int x, int y, char letter)
{
    is_color_white = iswhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

bool Queen::canMoveTo(int x, int y)
{
    bool bounds = x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int distanceX = std::abs(x- posX);
    int distanceY = std::abs(y -posY);
    if(bounds == false)
    {
        return bounds;
    }
    if((posX + distanceX) == x && posY == y ||
     posX == x && posY + distanceY == y)
    {
        return true;
    }
    else if((posX - distanceX) == x && posY == y ||
     posX == x && posY - distanceY == y)
    {
        return true;
    }
    else if(posX + distanceX == x && posY+ distanceY== y || posX - distanceX == x && posY - distanceY== y)
    {
        return true;
    }
    else if(posX - distanceX == x && posY + distanceY== y || posX + distanceX == x && posY - distanceY== y)
    {
        return true;
    }
    return false;
}

PieceType Queen::getType()
{
    return QUEEN;
}
//--------------------------------------------
//King

King::King()
{
}

King::King(bool isWhite)
{
    is_color_white = isWhite;
}

King::King(bool iswhite, int x, int y, char letter)
{
    is_color_white = iswhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

bool King::canMoveTo(int x, int y)
{
    bool bounds = x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    if(bounds == false)
    {
        return bounds;
    }
    if(posX +1 == x && posY == y || posX -1 == x && posY == y
    ||posX == x && posY + 1 == y || posX == x && posY - 1 == y) 
    {
        return true;
    }
    else if(posX +1 == x && posY + 1 == y || posX - 1 == x && posY == y +1
    ||posX + 1 == x && posY - 1 == y || posX -1 == x && posY - 1 == y) 
    {
        return true;
    }
    return false;
}

PieceType King::getType()
{
    return KING;
}
