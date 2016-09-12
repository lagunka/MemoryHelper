#pragma once

class theid
{

public:
	theid();
	~theid();

	DWORD mySide;
	DWORD yourSide;

	DWORD getmySide();
	DWORD gettheid();
	DWORD getHandleWeap();
	DWORD getToolEntity();
	DWORD getCurrentTool();
	DWORD getyourSide();
	DWORD getOtherSideSite();
	DWORD getthirdeyePointer();
	DWORD getLocalEntity();
	DWORD getEnginePointer();
	DWORD getShotsFired();

	DWORD player;

	int getthirdeyeCurrentPlayer(int);
	int getToolID();
	int getLocalSide();
	int getCenterID();
	int getOtherSideVit();
	int getOtherSide();
	int getFlags();
	int getSide();
	int getVit();

	float getFlashMaxAlpha();

	float getSensitivity();

	void setSensitivity(float x);
	void getPlayer(int i);

	bool inAir();
	bool isDormant();


};

extern theid* ptheid;
