#include "chess_base.hh"
#include "chess_pieces.hh"
Piece::Piece(bool isWhite)
{
    is_color_white = isWhite;
}
Piece::Piece(bool iswhite, int x, int y, char letter)
{
    is_color_white = iswhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}

bool Piece::isWhite()
{
    return is_color_white;
}

PositionComponent *Piece::getPosition()
{
    Component* comp = getComponent("Position");
    PositionComponent* pos = static_cast<PositionComponent*>(comp);
    return pos;
}

VisualComponent *Piece::getVisual()
{
    Component* comp = getComponent("Visual");
    VisualComponent* visual = static_cast<VisualComponent*>(comp);
    return visual;
}

Piece::~Piece()
{
    for(std::vector<Component*>::iterator it = components.begin(); it != components.end(); it++)
        delete *(it);        

    components.clear();
}

void ChessBoard::initializeBoard()
{
    //initialize de board set everithing to  null


    Piece* pawn = new Pawn(true, 0,0, 'p');
    Piece* pawnblack = new Pawn(false, 0,0, 'P');

    board[1][0] = pawn;
    board[1][1] = pawn;
    board[1][3] = pawnblack;
}

Piece *ChessBoard::getPieceAt(int x, int y)
{
    return this->board[y][x];
}

void ChessBoard::setPieceAt(Piece *piece, int x, int y)
{
    if(piece->canMoveTo(x,y))
    {
        board[y][x] = piece;
    }
    return;
}

ChessBoard::~ChessBoard()
{

}
