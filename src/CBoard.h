/*
 * @author Hong Son Ngo <ngohongs@fit.cvut.cz>
 * @date 14/05/2020.
 */

#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <memory>
#include <sstream>
#include <random>
#include "CPiece.h"
#include "EColor.h"
#include "CPieces/CKing.h"
#include "CPieces/CQueen.h"
#include "CPieces/CBishop.h"
#include "CPieces/CKnight.h"
#include "CPieces/CRook.h"
#include "CPieces/CPawn.h"
#include "CPieces/CEmpty.h"
#include "ETile.h"
#include "EConst.h"
#include "FENTest.h"

class CPiece;

class CBoard {
private:
    using TBoard = std::vector<std::unique_ptr<CPiece>>;
    TBoard m_Board;
    unsigned int m_Castling = 0xF;
    int m_Plies = 0;
    int m_Turns = 1;
    int m_EnPassant = EMPTY;
    int m_WhiteTurn = true;

    std::map<char,std::vector<uint64_t>> m_PieceKeys;
    uint64_t m_CastlingKeys[16];
    uint64_t m_EnPassantKey;
    uint64_t m_WhiteTurnKey;

    void GenerateHashKeys();
    uint64_t GenerateUint64() const;
public:
    CBoard();

    std::ostream & Print(std::ostream & os) const;

    bool ReadFEN(const std::string & fen);

    std::string CreateFEN() const;

    void PrintState() const;
};



