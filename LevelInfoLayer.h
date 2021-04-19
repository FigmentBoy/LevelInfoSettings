#pragma once
#include <cocos2d.h>
#include "MinHook.h"
using namespace cocos2d;

namespace LevelInfoLayer {
	int __fastcall hkInit(CCLayer* self, void*, void* lvl);
	inline int(__thiscall* init)(CCLayer* self, void* lvl);

	void mem_init();
}

class OptionsLayer : public CCLayerColor {
protected:
	char pad[0x1E0u];

public:
	static OptionsLayer* create() {
		size_t base = (size_t)GetModuleHandle(0);

		auto pRet = new OptionsLayer;
		if (pRet) {
			reinterpret_cast<int(__thiscall*)(OptionsLayer*)>(base + 0x1DCF40)(pRet); // VTable

			float time = 220.f;
			__asm {
				movss xmm2, time
			}
			if (reinterpret_cast<bool(__thiscall*)(void*, char const*)>(base + 0x113530)(pRet, "Settings")) { // Init
				pRet->autorelease();
				return pRet;
			}
			else {
				CC_SAFE_DELETE(pRet);
				return 0;
			}
		}
	}
};

class Callbacks : public CCObject {
public:
	void showOptionsLayer(CCObject* pTarget);
};