#include"maze.h"
#include <QDebug>
#include <QTime>



mazeGenerator::mazeGenerator(int _xs,int _ys)
{
;

    _szx=_xs;
    if (_ys >0){ _szy=_ys;}else {_szy=_xs; }

    _world = new char[_szx * _szy];
    _pts   = new char[_szx * _szy];

    for (int i=0;i< _szx * _szy;i++)  _world[i]=0;

    _ptX = qrand() % _szx; _ptY = qrand() % _szy;
    _sx = qrand() % _szx; _sy = qrand() % _szy;
    _ex = qrand() % _szx; _ey = qrand() % _szy;

}

mazeGenerator::~mazeGenerator()
{
    free( _world);
    free(_pts);
}


void mazeGenerator::carve()
{
    while( true )
    {
        int d = getDirection();
        if( d < NOR ) return;

        switch( d )
        {
        case NOR:
            _world[_ptX + _szx * _ptY] |= NOR; _ptY--;
            _world[_ptX + _szx * _ptY] = SOU | SOU << 4;
            break;
        case EAS:
            _world[_ptX + _szx * _ptY] |= EAS; _ptX++;
            _world[_ptX + _szx * _ptY] = WES | WES << 4;
            break;
        case SOU:
            _world[_ptX + _szx * _ptY] |= SOU; _ptY++;
            _world[_ptX + _szx * _ptY] = NOR | NOR << 4;
            break;
        case WES:
            _world[_ptX + _szx * _ptY] |= WES; _ptX--;
            _world[_ptX + _szx * _ptY] = EAS | EAS << 4;
        }
    }
}
int mazeGenerator::getDirection()
{
    int d = 1 << qrand() % 4;
    while( true )
    {
        for( int x = 0; x < 4; x++ )
        {
            if( testDir( d ) ) return d;
            d <<= 1;
            if( d > 8 ) d = 1;
        }
        d = ( _world[_ptX + _szx * _ptY] & 0xf0 ) >> 4;
        if( !d ) return -1;
        switch( d )
        {
        case NOR: _ptY--; break;
        case EAS: _ptX++; break;
        case SOU: _ptY++; break;
        case WES: _ptX--; break;
        }
        d = 1 << qrand() % 4;
    }
}


bool mazeGenerator::testDirection( int d )
{
    if( d == _lastDir || !( _world[_sx + _szx * _sy] & d ) ) return false;
    switch( d )
    {
    case NOR:
        return _sy - 1 > -1 && !( _world[_sx + _szx * ( _sy - 1 )] & 0xf0 );
    case EAS:
        return _sx + 1 < _szx && !( _world[_sx + 1 + _szx * _sy] & 0xf0 );
    case SOU:
        return _sy + 1 < _szy && !( _world[_sx + _szx * ( _sy + 1 )] & 0xf0 );
    case WES:
        return _sx - 1 > -1 && !( _world[_sx - 1 + _szx * _sy] & 0xf0 );
    }
    return false;
}


int mazeGenerator::getDirection2()
{
    int d = 1 << rand() % 4;
    while( true )
    {
        for( int x = 0; x < 4; x++ )
        {
            if( testDirection( d ) ) return d;
            d <<= 1;
            if( d > 8 ) d = 1;
        }

        d = ( _world[_sx + _szx * _sy] & 0xf0 ) >> 4;
        if( !d ) return -1;
        _pts[_sx + _szx * _sy] = 0;
        updatePosition( d );
        _lastDir = invert( d );
        d = 1 << rand() % 4;
    }
}


bool mazeGenerator::testDir( int d )
{
    switch( d )
    {
    case NOR: return ( _ptY - 1 > -1 && !_world[_ptX + _szx * ( _ptY - 1 )] );
    case EAS: return ( _ptX + 1 < _szx && !_world[_ptX + 1 + _szx * _ptY] );
    case SOU: return ( _ptY + 1 < _szy && !_world[_ptX + _szx * ( _ptY + 1 )] );
    case WES: return ( _ptX - 1 > -1 && !_world[_ptX - 1 + _szx * _ptY] );
    }
    return false;
}

void mazeGenerator::draw(QPainter *painter){

    CELL_SIZE = 4;

    for( int y = 0; y < _szy; y++ )
    {
        int yy = y * _szx;
        for( int x = 0; x < _szx; x++ )
        {
            char b = _world[x + yy];
            int nx = x * CELL_SIZE,
                    ny = y * CELL_SIZE;

            if( !( b & NOR ) )
            {
                painter->setPen(Qt::darkCyan);
                painter->drawLine(nx,ny,nx + CELL_SIZE,ny);
            }
            if( !( b & EAS ) )
            {
                painter->setPen(Qt::red);
                painter->drawLine(nx + CELL_SIZE,ny,nx + CELL_SIZE ,ny + CELL_SIZE );
            }
            if( !( b & SOU ) )
            {
                painter->setPen(Qt::green);
                painter->drawLine(nx,ny+ CELL_SIZE ,nx + CELL_SIZE ,ny + CELL_SIZE);
            }
            if( !( b & WES ) )
            {
                painter->setPen(Qt::blue);
                painter->drawLine(nx,ny,nx,ny + CELL_SIZE);
            }
        }
    }


    for( int y = 0; y < _szy; y++ )
    {

        int yy = y * _szx;
        for( int x = 0; x < _szx; x++ )
        {
            char d = _pts[x + yy];

            if( !d ) continue;

            int nx = x * CELL_SIZE + CELL_SIZE/2,
                ny = y * CELL_SIZE + CELL_SIZE/2;

            painter->setPen(Qt::white);
            switch( d )
            {
            case NOR:

                painter->drawLine(nx,ny,nx,ny - CELL_SIZE);
                break;

            case EAS:

                painter->drawLine(nx,ny,nx+ CELL_SIZE,ny);
                break;

            case SOU:

                painter->drawLine(nx,ny,nx,ny+ CELL_SIZE);
                break;

            case WES:

                painter->drawLine(nx,ny,nx - CELL_SIZE,ny);
                break;
            }
        }
    }


}

void  mazeGenerator::solveIt(  )
{
    _lastDir = NONE;
    // _sx = sX; _sy = sY; _ex = eX; _ey = eY;

    for( int y = 0; y < _szy; y++ )
        for( int x = 0; x < _szx; x++ )
            _world[x + _szx * y] &= 0x0f;
    _world[_sx + _szx * _sy] |= NOR << 4;

    //	killPoints();


    for( int y = 0; y < _szy; y++ )
        for( int x = 0; x < _szx; x++ )
            _pts[x + _szx * y]=0;

    //ZeroMemory( _pts, _s * _s );

    findTheWay();

    //  _sx = sX; _sy = sY;

}

int  mazeGenerator::invert( int d )
{
    switch( d )
    {
    case NOR: return SOU;
    case SOU: return NOR;
    case WES: return EAS;
    case EAS: return WES;
    }
    return NONE;
}

void  mazeGenerator::updatePosition( int d )
{
    switch( d )
    {
    case NOR: _sy--; break;
    case EAS: _sx++; break;
    case SOU: _sy++; break;
    case WES: _sx--;
    }
}

void  mazeGenerator::findTheWay()
{



    while( true )
    {
        int d = getDirection2();




        if( d < NOR ) return;
        _lastDir = invert( d );
        _world[_sx + _szx * _sy] |= d;
        _pts[_sx + _szx * _sy] = d;

        updatePosition( d );

        if( _sx == _ex && _sy == _ey ) return;

        _world[_sx + _szx * _sy] |= _lastDir << 4;
    }
}


