#include "list.h"

cthirdeye *pthirdeye = new cthirdeye();

cthirdeye::cthirdeye()
{

}

cthirdeye::~cthirdeye()
{

}

void cthirdeye::thirdeyeEsp()
{

	for (int i = 0; i < 64; i++)
	{
		bool thirdeye_currentPlayerDormant = Mem->Read<bool>(ptheid->getthirdeyeCurrentPlayer(i) + Dormant);
		int thirdeye_currentPlayerthirdeyeIndex = Mem->Read<int>(ptheid->getthirdeyeCurrentPlayer(i) + thirdeyeIndex);
		int EntityBaseTeamID = Mem->Read<int>(ptheid->getthirdeyeCurrentPlayer(i) + teamOffset);

		if (thirdeye_currentPlayerDormant == true || EntityBaseTeamID == false)
			continue;
		else
			if (ptheid->getLocalSide() != EntityBaseTeamID || thirdeyeTeamCheck == false)
				switch (EntityBaseTeamID)
				{
				case 2:
					Mem->Write<float>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0x4)), thirdeyeBananaRed);
					Mem->Write<float>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0x8)), thirdeyeBananaGreen);
					Mem->Write<float>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0xC)), thirdeyeBananaBlue);
					Mem->Write<float>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0x10)), thirdeyeBananaAlpha);
					Mem->Write<BOOL>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0x24)), true);
					Mem->Write<BOOL>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0x25)), false);
					break;
				case 3:
					Mem->Write<float>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0x4)), thirdeyeAppleRed);
					Mem->Write<float>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0x8)), thirdeyeAppleGreen);
					Mem->Write<float>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0xC)), thirdeyeAppleBlue);
					Mem->Write<float>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0x10)), thirdeyeAppleAlpha);
					Mem->Write<BOOL>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0x24)), true);
					Mem->Write<BOOL>((ptheid->getthirdeyePointer() + ((thirdeye_currentPlayerthirdeyeIndex * 0x38) + 0x25)), false);
					break;
				}
	}

}


