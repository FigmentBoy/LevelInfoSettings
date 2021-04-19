#include "LevelInfoLayer.h"
//#include "button.h"
void Callbacks::showOptionsLayer(CCObject* pTarget) {
	size_t base = (size_t)GetModuleHandle(0);

	auto scene = CCDirector::sharedDirector()->getRunningScene();

	auto layer = OptionsLayer::create();

	CCLayer* ddl = (CCLayer*)layer->getChildren()->objectAtIndex(0);
	ddl->removeChild((CCNode*)ddl->getChildren()->objectAtIndex(9));

	layer->setZOrder(9999);
	scene->addChild(layer);

	reinterpret_cast<CCAction * (__thiscall*)(CCLayerColor*, bool)>(base + 0x1139C0)(layer, false);
}

int __fastcall LevelInfoLayer::hkInit(CCLayer* self, void*, void* lvl) {
	auto menu = CCMenu::create();

	float height = CCDirector::sharedDirector()->getWinSize().height;
	menu->setPosition(70, height-23.5);

	/*auto img = new CCImage();
	img->initWithImageData(&data, sizeof(data), CCImage::kFmtPng);
	
	auto texture = new CCTexture2D();
	texture->initWithImage(img);

	auto sprite = CCSprite::createWithTexture(texture);*/

	auto sprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
	sprite->setScale(0.75);

	size_t base = (size_t)GetModuleHandle(0);
	auto btn = reinterpret_cast<CCMenuItemSprite * (__thiscall*)(CCNode*, CCObject*, SEL_MenuHandler)>(base + 0x18EE0)(sprite, self, menu_selector(Callbacks::showOptionsLayer));

	menu->addChild(btn);
	self->addChild(menu);

	return init(self, lvl);
}


void LevelInfoLayer::mem_init() {
	size_t base = (size_t)GetModuleHandle(0);

	MH_CreateHook(
		(PVOID)(base + 0x175DF0),
		LevelInfoLayer::hkInit,
		(LPVOID*)&LevelInfoLayer::init
	);
}