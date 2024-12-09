#ifndef __MMENU_SCENE_H__
#define __MMENU_SCENE_H__

#include "cocos2d.h"

class Manu : public cocos2d::Scene{
private:
    int music_id;
    cocos2d::Menu* menu;

public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuPlayCallback(cocos2d::Ref* pSender);
    void menuInfoCallback(cocos2d::Ref* pSender);
    void menuScoreCallback(cocos2d::Ref* pSender);

    void menuPlay2Callback(cocos2d::Ref* pSender);

    CREATE_FUNC(Manu);
};

#endif