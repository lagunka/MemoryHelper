#include "list.h"

theid *ptheid = new theid();

theid::theid()
{

}

theid::~theid()
{

}

DWORD theid::getmySide()
{
	int * tempA = new int[11];
	tempA[0] = 152; tempA[1] = 170; tempA[2] = 164; tempA[3] = 156; tempA[4] = 174; tempA[5] = 186; tempA[6] = 46; tempA[7] = 154; tempA[8] = 170; tempA[9] = 170; tempA[10] = '\0';
	for (int i = 0; i < 10; ++i)
		tempA[i] = (tempA[i] / 2) + 23;
	char * tempB = new char[11];
	for (int i = 0; i < 11; ++i)
		tempB[i] = tempA[i];
	DWORD result = Mem->Module(XOR(tempB));
	delete tempA; delete tempB;
	return result;
}

DWORD theid::getyourSide()
{
	int * tempA = new int[11];
	tempA[0] = 148; tempA[1] = 166; tempA[2] = 152; tempA[3] = 156; tempA[4] = 166; tempA[5] = 148; tempA[6] = 38; tempA[7] = 146; tempA[8] = 162; tempA[9] = 162; tempA[10] = '\0';
	for (int i = 0; i < 10; ++i)
		tempA[i] = (tempA[i] / 2) + 27;
	char * tempB = new char[11];
	for (int i = 0; i < 11; ++i)
		tempB[i] = tempA[i];
	DWORD result = Mem->Module(XOR(tempB));
	delete tempA; delete tempB;
	return result;
}

DWORD theid::getShotsFired()
{
	return Mem->Read<DWORD>(gettheid() + m_iShotsFired);
}

DWORD theid::gettheid()
{
	return Mem->Read<DWORD>(mySide + playerBase);
}

DWORD theid::getHandleWeap()
{
	return Mem->Read<DWORD>(gettheid() + ActiveTool);
}

DWORD theid::getToolEntity()
{
	return getHandleWeap() & 0xFFF;
}

DWORD theid::getCurrentTool()
{
	return Mem->Read<DWORD>(mySide + entityBase + (getToolEntity() - 1) * 0x10);
}

int theid::getToolID()
{
	return Mem->Read<int>(getCurrentTool() + iToolID);
}

int theid::getLocalSide()
{
	return Mem->Read<int>(gettheid() + teamOffset);
}

int theid::getCenterID()
{
	return Mem->Read<int>(gettheid() + crosshairOffset);
}

DWORD theid::getOtherSideSite()
{
	return Mem->Read<DWORD>(mySide + entityBase + ((getCenterID() - 1) * EntLoopDist));
}

int theid::getOtherSideVit()
{
	return Mem->Read<int>(getOtherSideSite() + healthOffset);
}

int theid::getOtherSide()
{
	return Mem->Read<int>(getOtherSideSite() + teamOffset);
}

int theid::getSide()
{
	return Mem->Read<int>(player + teamOffset);
}

int theid::getVit()
{
	return Mem->Read<int>(player + healthOffset);
}


int theid::getFlags()
{
	return Mem->Read<int>(gettheid() + Flags);
}

DWORD theid::getthirdeyePointer()
{
	return Mem->Read<DWORD>(mySide + thirdeyeObject);
}

int theid::getthirdeyeCurrentPlayer(int index)
{
	return Mem->Read<int>(mySide + entityBase + index * 0x10);
}

float theid::getFlashMaxAlpha()
{
	return Mem->Read<float>(gettheid() + FlashMaxAlpha);
}

DWORD theid::getLocalEntity()
{
	return Mem->Read<DWORD>(mySide + gettheid());
}

DWORD theid::getEnginePointer()
{
	return Mem->Read<DWORD>(yourSide + clientState);
}

bool theid::inAir()
{
	return getFlags() == 256 || getFlags() == 258 || getFlags() == 260 || getFlags() == 262;
}

void theid::getPlayer(int i)
{
	player = Mem->Read<DWORD>(mySide + entityBase + (i * 0x10));
}	

bool theid::isDormant()
{
	return Mem->Read<bool>(player + Dormant);
}

float theid::getSensitivity()
{
	DWORD thisPtr = (int)(mySide + dwSensitivityPtr);
	DWORD sensitivity = Mem->Read<DWORD>(mySide + dwSensitivity);

	sensitivity ^= thisPtr;

	float sens = *reinterpret_cast<float*>(&sensitivity);
	
	return sens;
}

void theid::setSensitivity(float x)
{
	DWORD thisPtr = (int)(mySide + dwSensitivityPtr);
	DWORD xored = *(DWORD*)&x ^ thisPtr;

	Mem->Write<DWORD>(mySide + dwSensitivity, xored);
}
