#include "list.h"
#define EXPORTING_DLL
HANDLE threadLoop;

DWORD WINAPI Loop(PVOID pThreadParameter)
{
	int *tempA = new int[9];
	tempA[0] = 140; tempA[1] = 172; tempA[2] = 148; tempA[3] = 164; tempA[4] = 34; tempA[5] = 144; tempA[6] = 182; tempA[7] = 144; tempA[8] = '\0';
	for (int i = 0; i < 8; ++i) 
		tempA[i] = (tempA[i] / 2) + 29;
	char *tempB = new char[9];
	for (int i = 0; i < 9; ++i)
		tempB[i] = tempA[i];
	Mem->Process(XOR(tempB));
	delete tempA; delete tempB;
	pMisc->setmySide();
	pMisc->setyourSide();
	pMisc->readCfg();
	while (threadLoop)
	{
		assert(threadLoop);

		if (pMisc->isFocused())
		{
			pMisc->switchThrowEnabled();
			pMisc->thirdeyeEnabled();
			pMisc->springEnabled();

			if (pMisc->isshortTool() && GetAsyncKeyState(0x01) & 0x8000)
			{
				pautoblamBlam->Shoot();
			}
			if (pMisc->thirdeye)
			{
				pthirdeye->thirdeyeEsp();
			}
			if (pMisc->switchThrow && GetAsyncKeyState(pMisc->Tkey) & 0x8000 && pMisc->isTool())
			{
				pswitchThrow->switchThrow();
			}
			if (pMisc->spring && GetAsyncKeyState(pMisc->SK) & 0x8000)
			{
				pspring->spring();
			}
			if (ptheid->getFlashMaxAlpha() > pMisc->MFA)
			{
				pgoggles->goggles(pMisc->MFA);
			}
		}
		Sleep(5);
	}
	return 0;
}



BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		threadLoop = CreateThread(0, 0, Loop, 0, 0, NULL);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		if (threadLoop)
			CloseHandle(threadLoop);
		break;
	}
	return TRUE;
}
