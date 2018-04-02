#pragma once


struct Width
{
public:
    explicit Width(int w) : _w(w) {}
    operator int() {return _w;}

private:
    int _w;
};


struct Height
{
public:
    explicit Height(int h) : _h(h) {}
    operator int() {return _h;}

private:
    int _h;
};

struct Grid
{
    Width xSize;
    Height ySize;
};
