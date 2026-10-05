#include "chess_base.hh"
#include "chess_pieces.hh"
Piece::Piece(bool isWhite)
{
    is_color_white = isWhite;
}
Piece::Piece(bool isWhite, int x, int y, char letter)
{
    is_color_white = isWhite;
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
    for(int i= 0; i!=BOARD_SIZE;i++)
    {
        for(int e = 0; e!= BOARD_SIZE; e++)
        {
            board[i][e]= nullptr;
        }
    }
    //Create the pawns
    for(int i = 0 ; i!= BOARD_SIZE; i++)
    {
        board[1][i]= new Pawn(true,i,1,'p');
        board[6][i]= new Pawn(false,i,6,'P');
    }
    //Set knights
    board[0][1]= new Knight(true,1,0,'k');
    board[7][1]= new Knight(false,1,7,'K');
    board[0][6]= new Knight(true,6,0,'k');
    board[7][6]= new Knight(false,6,7,'K');
    //Set bishops
    board[0][2]= new Bishop(true,2,0,'b');
    board[7][2]= new Bishop(false,2,7,'B');
    board[0][5]= new Bishop(true,5,0,'b');
    board[7][5]= new Bishop(false,5,7,'B');
}

Piece *ChessBoard::getPieceAt(int x, int y)
{
    return this->board[y][x];
}

void ChessBoard::setPieceAt(Piece *piece, int x, int y)
{


    board[y][x] = piece;
    
   
    
}

ChessBoard::~ChessBoard()
{

}
