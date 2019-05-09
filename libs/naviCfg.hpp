#ifndef __NAVI_CFG_HPP__
#define __NAVI_CFG_HPP__

#include <string>
#include <map>


using namespace std;

class naviCfg {

public:	    
    naviCfg(string configFile);
    ~naviCfg();
    void InitConfig();
    string GetVarInfo(string name, string attr = string("Value"));


private:    
    string s_ConfigFile;
    map<string, map<string, string> > m_Vars;
};

#endif
