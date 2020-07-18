#include <QPainter>

//--------------------------------------------------------------------------------------------------
enum directions { NONE, NOR = 1, EAS = 2, SOU = 4, WES = 8 };

class mazeGenerator
{
public:
    mazeGenerator(int _xs,int _ys = 0);
    ~mazeGenerator();
    void carve();

    int getDirection();
    bool testDirection( int );
    int getDirection2();
    bool testDir( int d );
    void draw(QPainter *painter);

    int CELL_SIZE;

    char** world;
    char*    _world;
    int      _szx,_szy, _ptX, _ptY;

    char*   _pts;
    int      _sx, _sy, _ex, _ey, _lastDir;

    void  solveIt(  );
    void findTheWay();
    void updatePosition( int  );

    int  invert( int  );
};
