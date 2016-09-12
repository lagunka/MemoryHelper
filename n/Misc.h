#pragma once

class cMisc
{
public:
	cMisc();
	~cMisc();
	
	int readCfg();
	bool isTool();
	bool isshortTool();

	bool thirdeyeToggleKeyPressed = true;
	bool springToggleKeyPressed = true;
	bool switchThrowToggleKeyPressed = true;

	bool switchThrow = true;
	bool thirdeye = true;
	bool spring = true;

	float fClosest;
	bool isFocused();

	void springEnabled();
	void thirdeyeEnabled();
	void switchThrowEnabled();
	
	void forceJump();
	void forceUpdate();
	
	void setmySide();
	void setyourSide();
	float MFA = 20.0F;
	int Tkey = 0x6;
	int SK = 0x20;
	int BT = 0x67;
	int TT = 0x68;
	int GT = 0x69;

};

extern cMisc* pMisc;