#include "chess_pieces.hh"
//----------------------------
//Pawn
Pawn::Pawn(bool isWhite, int x, int y, char letter)
{
    is_color_white = isWhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

Pawn::Pawn(bool isWhite)
{
    this->is_color_white = isWhite;
}



bool Pawn::canMoveTo(int x, int y)
{
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int distance = (isWhite ? 1 : -1);
    if(posX == x && posY  + distance== y)
    {
        return true;
    }
    else if(FirstMove == true && posX == x && posY  + 2* distance== y)
    {
        return true;
    }
    else if((posX + 1 == x || posX -1 == x)&&posY  + distance== y)
    {
        return true;
    }
    return false;
}

PieceType Pawn::getType()
{

    return PAWN;
}
//-------------------------------------
//Knigh

Knight::Knight(bool isWhite, int x, int y, char letter)
{
    is_color_white = isWhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

Knight::Knight(bool isWhite)
{
    this->is_color_white = isWhite;
}

bool Knight::canMoveTo(int x, int y)
{
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int dx = abs(x-posX);
    int dy = abs(y - posY);
    if(dx == 1 && dy == 2 || dx == 2 && dy == 1)
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

Bishop::Bishop(bool isWhite, int x, int y, char letter)
{
    is_color_white = isWhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

Bishop::Bishop(bool isWhite)
{
    is_color_white = isWhite;
}
bool Bishop::canMoveTo(int x, int y)
{
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int distanceX = std::abs(x- posX);
    int distanceY = std::abs(y -posY);
    if(abs(distanceX) == abs(distanceY))
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

Rook::Rook(bool isWhite, int x, int y, char letter)
{
    is_color_white = isWhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

Rook::Rook(bool isWhite)
{
    is_color_white = isWhite;

}
bool Rook::canMoveTo(int x, int y)
{
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();

    if(posX == x && posY != y)
    {
        return true;
    }
    else if(posX != x && posY == y)
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

Queen::Queen(bool isWhite, int x, int y, char letter)
{
    is_color_white = isWhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

Queen::Queen(bool isWhite)
{
    is_color_white = isWhite;
}
bool Queen::canMoveTo(int x, int y)
{
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

PieceType Queen::getType()
{
    return QUEEN;
}
//--------------------------------------------
//King

King::King(bool isWhite, int x, int y, char letter)
{
    is_color_white = isWhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

King::King(bool isWhite)
{
    is_color_white = isWhite;
}
bool King::canMoveTo(int x, int y)
{
    int posX = (this->getPosition())->getX();
    int posY = (this->getPosition())->getY();
    int distanceX = std::abs(x- posX);
    int distanceY = std::abs(y -posY);
    if(distanceX <= 1 && distanceY <= 1 && distanceX + distanceY != 0)
    {
        return true;
    }
    return false;
}

PieceType King::getType()
{
    return KING;
}
