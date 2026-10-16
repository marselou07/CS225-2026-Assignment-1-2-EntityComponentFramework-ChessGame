#include "chess_base.hh"
#include "chess_pieces.hh"
/******************************************************************************
filename    chess_base.cpp
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  2
due date    06/10/2026

Brief Description: This program will set all the information for the board
and the base class piece.
******************************************************************************/
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @return nothing
 */
Piece::Piece(bool isWhite)
{
    is_color_white = isWhite;
}
/**
 * Constructor
 * @param isWhite:bool to set the color
 * @param x = position om x
 * @param y = position on y
 * @param letter: the symbol the piece has
 * @return nothing
 */
Piece::Piece(bool isWhite, int x, int y, char letter)
{
    is_color_white = isWhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}
/**
 * isWhite
 * @return the value of is_color_white
 */
bool Piece::isWhite()
{
    return is_color_white;
}
/**
 * getPosition
 * @return the position component pointer
 */
PositionComponent *Piece::getPosition()
{
    Component* comp = getComponent("Position");
    PositionComponent* pos = static_cast<PositionComponent*>(comp);
    return pos;
}
/**
 * getPosition
 * @return the visual component pointer
 */
VisualComponent *Piece::getVisual()
{
    Component* comp = getComponent("Visual");
    VisualComponent* visual = static_cast<VisualComponent*>(comp);
    return visual;
}
/**
 * Destructor
 * @return nothing
 */
Piece::~Piece()
{
    //Crear all the elements on the vector
    for(std::vector<Component*>::iterator it = components.begin(); it != components.end(); it++)
        delete *(it);        

    components.clear();
}
/**
 * initializeBoard
 * @return nothing
 */
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
        board[1][i]= new Pawn(true,i,1,'P');
        board[6][i]= new Pawn(false,i,6,'p');
    }
    //Set knights
    board[0][1] = new Knight(true,1,0,'K');
    board[7][1] = new Knight(false,1,7,'k');
    board[0][6] = new Knight(true,6,0,'K');
    board[7][6] = new Knight(false,6,7,'k');
    //Set bishops
    board[0][2] = new Bishop(true,2,0,'B');
    board[7][2] = new Bishop(false,2,7,'b');
    board[0][5] = new Bishop(true,5,0,'B');
    board[7][5] = new Bishop(false,5,7,'b');
    //Set rooks
    board[0][0] = new Rook(true,0,0,'R');
    board[7][0] = new Rook(false,0,7,'r');
    board[0][7] = new Rook(true,7,0,'R');
    board[7][7] = new Rook(false,7,7,'r');
    //Ser queen
    board[0][3] = new Queen(true,3,0,'Q');
    board[7][3] = new Queen(false,3,7,'q');
    //Set king
    board[0][4] = new King(true,4,0,'K');
    board[7][4] = new King(false,4,7,'k');

}
/**
 * getPieceAt
 * @param x: position on x
 * @param y: position on y
 * @return a pointer to the piece in that position
 */
Piece *ChessBoard::getPieceAt(int x, int y)
{
    return this->board[y][x];
}
/**
 * setPieceAt
 * @param: piece: a pointer to the piece that will be set
 * @param x: position on x
 * @param y: position on y
 * @return nothing
 */
void ChessBoard::setPieceAt(Piece *piece, int x, int y)
{
    board[y][x] = piece;
}
/**
 * desturctor
 * @return nothing
 */
ChessBoard::~ChessBoard()
{
    //Clear the board entiererly 
    for(int i=0; i!= BOARD_SIZE; i++)
    {
        for(int e = 0;e!= BOARD_SIZE; e++)
        {
            Piece * p = board[i][e];
            if(p != nullptr)
            {
                delete p;
            }
            board[i][e] = nullptr;
        }
    }
}
