#pragma once

class cswitchThrow
{
public:
	cswitchThrow();
	~cswitchThrow();
	void switchThrow();
private:
	DWORD switchThrowKey = 0x05;
};

extern cswitchThrow *pswitchThrow;

