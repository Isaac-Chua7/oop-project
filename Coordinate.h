#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate{
    public:
    int row;
    int col;    
    int getRow();
    void setRow(int r);
    int getCol();
    void setCol(int c);
};

#endif