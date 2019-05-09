#ifndef __NAVI_IMG_HPP__
#define __NAVI_IMG_HPP__

class naviImg {

public:	    
    naviImg(naviPoint cBasePoint, double fBaseDirection, string sImgSrc, string sImgSrc);
    ~naviImg();
    void GenerateMarginImg();
    naviPoint GetAbsolutePoint(naviPoint cRelativePoint);
    naviPoint GetRelativePoint(naviPoint cAbsolutePoint);


private:    
    naviPoint c_BasePoint;
    double f_BaseDirection; 
    string s_ImgSrc;
    string s_ImgMargin;
};

#endif
