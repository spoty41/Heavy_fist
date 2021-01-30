
#include "main.hpp"

void threadMain()
{
	bool currentState = false;
	while (true)
	{
		if (GetAsyncKeyState(VK_F4))
		{
			currentState = !currentState;
		
			unsigned long* cPlayerPed = FindPlayerPed(-1);
			if (cPlayerPed)
			{
				Beep(100, 100);
				char weaponSkill = GetWeaponSkill(cPlayerPed, 0);
				CWeaponInfo* weaponInfo = GetWeaponInfo(0, weaponSkill);
				if (currentState)
					weaponInfo->m_nFlags.bHeavy = 1;
				else
					weaponInfo->m_nFlags.bHeavy = 0;
			}
		}
		Sleep(100);
	}
}

class cEntry
{
public:
	cEntry()
	{
		CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(threadMain), 0, 0, 0);
	}
} _entry;
