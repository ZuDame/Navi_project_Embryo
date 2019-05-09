#ifndef __NAVI_POINT_HPP__
#define __NAVI_POINT_HPP__

class naviPoint {

public:	    
    naviPoint(int nCoordX, int nCoordY);
    ~naviPoint();
    int GetCoordX();
    int GetCoordY();

private:    
    int n_CoordX;
    int n_CoordY;
};

#endif
