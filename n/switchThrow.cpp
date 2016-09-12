#include "list.h"

cswitchThrow *pswitchThrow = new cswitchThrow();

cswitchThrow::cswitchThrow()
{

}

cswitchThrow::~cswitchThrow()
{

}


void cswitchThrow::switchThrow()
{
	if (ptheid->getLocalSide() != ptheid->getOtherSide() && ptheid->getCenterID() > 0 && ptheid->getOtherSideVit() > 0)
	{
		pautoblamBlam->Shoot();
	}
}
