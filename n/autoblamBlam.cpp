#include "list.h"

cautoblamBlam *pautoblamBlam = new cautoblamBlam();

cautoblamBlam::cautoblamBlam()
{

}

cautoblamBlam::~cautoblamBlam()
{

}

void cautoblamBlam::Shoot()
{
	Mem->Write<int>(ptheid->mySide + ForceAttack, 5);
	Sleep(50);
	Mem->Write<int>(ptheid->mySide + ForceAttack, 4);
}