#ifndef __NAVI_MARGIN_HPP__
#define __NAVI_MARGIN_HPP__

#include <string>
#include <map>


using namespace std;

class naviMargin {

public:	    
    naviMargin(string sImg1, string sImg2);
    ~naviMargin();


private:    
    naviImg c_Img1;
    naviImg c_Img2;
    void GetMarginCoords(list<cPoint>& lcMarginPoints);
};

#endif
