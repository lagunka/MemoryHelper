#pragma once

class creadCfg
{
public:
	creadCfg();
	~creadCfg();
	int readData(char*);
	int creadCfg::newCfg();
	int getvar(char*);
	bool is_empty(std::ifstream& pFile);
};

extern creadCfg* preadCfg;