#include "list.h"

cgoggles *pgoggles = new cgoggles();

cgoggles::cgoggles()
{

}

cgoggles::~cgoggles()
{

}

void cgoggles::goggles(float MFA)
{
	Mem->Write<float>(ptheid->gettheid() + FlashMaxAlpha, MFA);
}

