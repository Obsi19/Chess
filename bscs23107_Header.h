#pragma once


struct Position {
    int posx;
    int posy;
};


enum COLOR { Black, White };


void gotoRowCol(unsigned char rpos, unsigned char cpos);
void getRowColbyLeftClick(int& rpos, int& cpos);