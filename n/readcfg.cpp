#include "List.h"

creadCfg *preadCfg = new creadCfg();

creadCfg::creadCfg() {

}
creadCfg::~creadCfg() {

}

bool creadCfg::is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

int creadCfg::readData(char *jtmp) {
	ifstream rcfgfile;
	rcfgfile.open("config.json");
	if (rcfgfile.is_open()) {
		char *c = new char;
		int *count = new int; *count = 1;
		while (rcfgfile.get(*c)) {
			++*count;
		}
		char *jdata = new char[*count];
		rcfgfile.clear();
		rcfgfile.seekg(0, ios::beg);
		*count = 0;
		while (rcfgfile.get(*c)) {
			jdata[*count] = *c;
			++*count;
		}
		jdata[*count] = '\0';
		rcfgfile.clear();
		rcfgfile.seekg(0, ios::beg);
		++*count;
		strcpy_s(jtmp, *count, jdata);
		delete c; delete jdata; delete count;
		rcfgfile.close();
		return 1;
	}
	else { cout << "0xDEADBEEF" << endl; return 0; }
}

int creadCfg::newCfg() {
	ofstream wcfgfile;
	wcfgfile.open("config.json");
	if (wcfgfile.is_open()) {
		wcfgfile.write("{\n", 2);
		wcfgfile.write("	\"Configs\": {\n", 14);
		wcfgfile.write("		\"Tkey\" : \"0x6\",\n", 18);
		wcfgfile.write("		\"BT\" : \"0x67\",\n", 17);
		wcfgfile.write("		\"TT\" : \"0x68\"\,\n", 17);
		wcfgfile.write("		\"GT\" : \"0x69\",\n", 17);
		wcfgfile.write("		\"MFA\" : 20.0,\n", 16);
		wcfgfile.write("		\"SK\" : \"0x20\"\n", 16);
		wcfgfile.write("	}\n", 3);
		wcfgfile.write("}", 1);
		wcfgfile.close();
		cout << "New Config Created." << endl;
		return 1;
	}
	else { cout << "0xDEADBEEF" << endl; return 0; }
}

int creadCfg::getvar(char *jtmp) {
	ifstream cfgfile;
	cfgfile.open("config.json");
	if (cfgfile.is_open()) {
		if (creadCfg::is_empty(cfgfile)) {
			cfgfile.close();
			if (creadCfg::newCfg()) {
				Sleep(2000);
				if (creadCfg::readData(jtmp)) {
					return 1;
				}
			}
		}
		else {
			if (creadCfg::readData(jtmp)) {
				return 1;
			}
		}
	}
	else {
		cout << "No Config Found." << endl;
		if (creadCfg::newCfg()) {
			Sleep(2000);
			if (creadCfg::readData(jtmp)) {
				return 1;
			}
		}
	}
	return 0;
}