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
    Component* comp = getComponent("position");
    PositionComponent* pos = static_cast<PositionComponent*>(comp);
    return pos;
}

VisualComponent *Piece::getVisual()
{
    Component* comp = getComponent("visual");
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


    Pawn* pawn = new Pawn();
    setPieceAt(pawn,0,0);
    //board[0][0] = pawn;

}

Piece *ChessBoard::getPieceAt(int x, int y)
{
    
    return nullptr;
}

void ChessBoard::setPieceAt(Piece *piece, int x, int y)
{

}

ChessBoard::~ChessBoard()
{

}
