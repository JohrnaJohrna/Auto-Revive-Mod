#pragma once

#include "Memory_S.h"

class CHR_DBG
{
private:
	uintptr_t CHR_DBG_BASE;
	uintptr_t CHR_DBG_FLAGS;

	struct DEBUG_FLAGS {

	};

	struct DEBUG_DISP_FLAGS {

	};

	struct TAE {

	};

	struct WEAPON_SFX {
		int _DrawEnchantSfxOccurencePos = 0xC1;
		int _EnchantSfxOccurenceInterval = 0xC8;
		int _WhipEnchantSfxOccurenceInterval = 0xCC;
		int _WhipStandbyEnchantSfxOccurenceInterval = 0xD0;
	};

	struct HIT_STOP {

	};

protected:

public:
	CHR_DBG();
	CHR_DBG(const CHR_DBG& chr_dbg);
	~CHR_DBG();
	CHR_DBG& operator=(const CHR_DBG& chr_dbg);

	float* GetHitStopVal();
};