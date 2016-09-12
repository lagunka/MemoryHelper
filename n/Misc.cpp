#include "list.h"

cMisc *pMisc = new cMisc();

cMisc::cMisc()
{

}

cMisc::~cMisc()
{

}

int cMisc::readCfg() {
	char *cfgs = new char[256];
	if (preadCfg->getvar(cfgs)) {
		json cfgdata = json::parse(cfgs);
		stringstream *ss = new stringstream;
		*ss << hex << cfgdata["Configs"]["Tkey"];
		*ss >> Tkey;
		*ss << hex << cfgdata["Configs"]["SK"];
		*ss >> SK;
		*ss << hex << cfgdata["Configs"]["TT"];
		*ss >> TT;
		*ss << hex << cfgdata["Configs"]["GT"];
		*ss >> GT;
		*ss << hex << cfgdata["Configs"]["BT"];
		*ss >> BT;
		MFA = cfgdata["Configs"]["MFA"];
		delete ss; delete cfgs;
		return 1;
	}
	else { delete cfgs; return 0; }
	
}

void cMisc::setmySide()
{
	ptheid->mySide = ptheid->getmySide();
}

void cMisc::setyourSide()
{
	ptheid->yourSide = ptheid->getyourSide();
}

void cMisc::forceJump()
{
	Mem->Write<int>(ptheid->mySide + ForceJump, 1);
	Sleep(30);
	Mem->Write<int>(ptheid->mySide + ForceJump, 0);
}

bool cMisc::isFocused()
{
	int * tempA = new int[33];
	tempA[0] = 92; tempA[1] = 180; tempA[2] = 192; tempA[3] = 178; tempA[4] = 190; tempA[5] = 160; tempA[6] = 186; tempA[7] = 48; tempA[8] = 124; tempA[9] = 190;
	tempA[10] = 186; tempA[11] = 168; tempA[12] = 172; tempA[13] = 160; tempA[14] = 74; tempA[15] = 22; tempA[16] = 100; tempA[17] = 174; tempA[18] = 180; tempA[19] = 154;
	tempA[20] = 152; tempA[21] = 174; tempA[22] = 22; tempA[23] = 116; tempA[24] = 162; tempA[25] = 162; tempA[26] = 160; tempA[27] = 178; tempA[28] = 188; tempA[29] = 168;
	tempA[30] = 194; tempA[31] = 160; tempA[32] = '\0';
	for (int i = 0; i < 32; ++i)
		tempA[i] = (tempA[i] / 2) + 21;
	char * tempB = new char[33];
	for (int i = 0; i < 33; ++i)
		tempB[i] = tempA[i];
	HWND tWnd = FindWindowA(0, XOR(tempB));
	delete tempA; delete tempB;
	if (GetForegroundWindow() == tWnd)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void cMisc::springEnabled()
{
	if (GetAsyncKeyState(BT) & 1)
	{
		spring = !spring;
		Beep(750, 250);
	}
}

void cMisc::thirdeyeEnabled()
{
	if (GetAsyncKeyState(GT) & 1)
	{
		thirdeye = !thirdeye;
		Beep(750, 250);
	}
}

void cMisc::switchThrowEnabled()
{
	if (GetAsyncKeyState(TT) & 1)
	{
		switchThrow = !switchThrow;
		Beep(750, 250);
	}

}

bool cMisc::isTool()
{
	if (ptheid->getToolID() != Tool_knife && ptheid->getToolID() != Tool_c4 && ptheid->getToolID() != Tool_molotov && ptheid->getToolID() != Tool_hegrenade
		&& ptheid->getToolID() != Tool_flashbang && ptheid->getToolID() != Tool_smokegrenade && ptheid->getToolID() != Tool_incgrenade && ptheid->getToolID() != Tool_decoy
		&& ptheid->getToolID() != Tool_taser)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cMisc::isshortTool()
{
	if (ptheid->getToolID() == Tool_glock || ptheid->getToolID() == Tool_usp || ptheid->getToolID() == Tool_deagle || ptheid->getToolID() == Tool_p250
		|| ptheid->getToolID() == Tool_tec9 || ptheid->getToolID() == Tool_hkp2000 || ptheid->getToolID() == Tool_elite || ptheid->getToolID() == Tool_fiveseven)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void cMisc::forceUpdate()
{
	Mem->Write<int>(ptheid->getEnginePointer() + 0x16C, -1);
}

