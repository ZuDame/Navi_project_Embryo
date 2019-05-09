#include <libxml/parser.h>
#include <libxml/tree.h>
#include <iostream>
#include "naviCfg.hpp"
#include "naviMacro.hpp"
#include <map>


naviCfg::naviCfg(string configFile) {
   s_ConfigFile = configFile;
}

naviCfg::~naviCfg() {
    /* lilh - the task left but still need to do 
     *	destroy the memory occupied by m_Vars and its values.
     */
}

void naviCfg::InitConfig() {
    char sName[_NAVI_LINE_MAX_CHARS_];
    xmlDocPtr xDoc;
    xmlNodePtr xNode, xNodeChild;

    xmlKeepBlanksDefault(0);
    xDoc = xmlParseFile(s_ConfigFile.c_str());
    if(!xDoc) {
        fprintf(stderr, "Document not Load successfully. \n");
        return;
    }
    xNode = xmlDocGetRootElement(xDoc);
    if(!xNode) {
        fprintf(stderr, "No XML contents exist. \n");
        xmlFreeDoc(xDoc);
        return;
    } 
    xNode = xNode->xmlChildrenNode;
    while (xNode) {
	char sVarInfoKey[_NAVI_LINE_MAX_CHARS_];
	char sVarInfoVal[_NAVI_LINE_MAX_CHARS_];
	map<string, string> sVarInfo;
	sprintf(sName, "%s", xNode->name);
	xNodeChild = xNode->xmlChildrenNode;
	while (xNodeChild) {
	    sprintf(sVarInfoKey,"%s",xNodeChild->name);
	    sprintf(sVarInfoVal,"%s",xmlNodeGetContent(xNodeChild));

	    sVarInfo.insert(sVarInfo.end(),pair<string, string>(string(sVarInfoKey),string(sVarInfoVal)));
	    xNodeChild = xNodeChild->next;
	}
      
	m_Vars.insert(m_Vars.end(),pair<string, map<string, string> >(string(sName), sVarInfo));
	xNode = xNode->next;
    }
    xmlFreeDoc(xDoc);
    return ;
}

string naviCfg::GetVarInfo(string name, string attr) {
    map<string, map<string, string> >::iterator iter1;
    map<string, string>::iterator iter2;
    map<string, string> mVar;
    iter1 = m_Vars.find(name);
  
    if (iter1 == m_Vars.end()) {
	// the variable name is not defined 
	return "";
    } 
    mVar = iter1->second;
    iter2 = mVar.find(attr);
    if (iter2 == mVar.end()) {
	// the attr is not defined for name 
	return "";
    }
    return iter2->second;
    mVar.clear();
    m_Vars.clear();
}

