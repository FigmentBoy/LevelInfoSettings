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
public:
	static OptionsLayer* create() {
		size_t base = (size_t)GetModuleHandle(0);
		return reinterpret_cast<OptionsLayer * (__stdcall*)()>(
			base + 0x1DD310
			)();
	}
};

class Callbacks : public CCObject {
public:
	void showOptionsLayer(CCObject* pTarget);
};
