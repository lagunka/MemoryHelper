#pragma once

class cthirdeye
{
public:
	cthirdeye();
	~cthirdeye();
	void thirdeyeEsp();
	
	float thirdeyeBananaRed = 1.f;
	float thirdeyeBananaGreen = 0.f;
	float thirdeyeBananaBlue = 0.f;
	float thirdeyeBananaAlpha = 1.f;

	float thirdeyeAppleRed = 0.f;
	float thirdeyeAppleGreen = 0.f;
	float thirdeyeAppleBlue = 1.f;
	float thirdeyeAppleAlpha = 1.f;

	bool thirdeyeActive = true;
	bool thirdeyeTeamCheck = true;
};

extern cthirdeye *pthirdeye;


