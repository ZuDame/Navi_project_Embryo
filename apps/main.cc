#include <libxml/parser.h>
#include <libxml/tree.h>
#include <iostream>
#include <cstring>
#include "../libs/naviCfg.hpp"


naviCfg cNaviCfg("NaviCfg.xml");


int main(void) {
  string sName, sAttr1, sAttr2;
  sName = "Speed";
  sAttr1 = "Descr";
  sAttr2 = "Value";
  cNaviCfg.ReadConfigFile();

  cout << "The " << sAttr1 << " of " << sName << " is " << cNaviCfg.GetVarInfo(sName,sAttr1) << endl;
  cout << "The " << sAttr2 << " of " << sName << " is " << cNaviCfg.GetVarInfo(sName,sAttr2) << endl;
  return 0;

}

