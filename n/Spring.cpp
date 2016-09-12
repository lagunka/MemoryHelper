#include "list.h"

cspring *pspring = new cspring();

cspring::cspring()
{

}

cspring::~cspring()
{

}


void cspring::spring()
{

	if (!ptheid->inAir())
	{
		Mem->Write<int>(ptheid->mySide + ForceJump, 5);
	}
	else if (ptheid->inAir())
	{
		Mem->Write<int>(ptheid->mySide + ForceJump, 4);
		Mem->Write<int>(ptheid->mySide + ForceJump, 5);
		Mem->Write<int>(ptheid->mySide + ForceJump, 4);
	}
	else
	{
		Mem->Write<int>(ptheid->mySide + ForceJump, 4);
	}
}
