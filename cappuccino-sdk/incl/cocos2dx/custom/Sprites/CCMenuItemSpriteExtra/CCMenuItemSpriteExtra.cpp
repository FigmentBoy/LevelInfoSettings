#include "CCMenuItemSpriteExtra.h"

void CCMenuItemSpriteExtra::selected(){
	CCMenuItemSprite::selected();
	auto resize = cocos2d::CCMoveTo::create(0.3, { this->getPositionX(), -8.f });
	auto bounce = cocos2d::CCEaseInOut::create(resize, 3);
	this->runAction(bounce);
}

void CCMenuItemSpriteExtra::unselected(){
	CCMenuItemSprite::unselected();
	auto resize = cocos2d::CCMoveTo::create(0.3, { this->getPositionX(), 0.f });
	auto bounce = cocos2d::CCEaseInOut::create(resize, 3);
	this->runAction(bounce);
}

void CCMenuItemSpriteExtra::activate() {
	CCMenuItemSprite::activate();
	this->stopAllActions();
	auto resize = cocos2d::CCMoveTo::create(0.3, { this->getPositionX(), 0.f });
	auto bounce = cocos2d::CCEaseInOut::create(resize, 3);
	this->runAction(bounce);
}

void CCMenuItemSpriteExtra::setScale(float scale) {
	CCMenuItemSprite::setScale(scale);	
	m_origScale = scale;
}

CCMenuItemSpriteExtra* CCMenuItemSpriteExtra::create(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, cocos2d::SEL_MenuHandler selector){
	auto spriteItem = new CCMenuItemSpriteExtra;
	if (spriteItem && spriteItem->initWithNormalSprite(normalSprite, selectedSprite, nullptr, target, selector)) 
		spriteItem->autorelease();
	else {
		delete spriteItem;
		spriteItem = nullptr;
	}
	return spriteItem;

}
