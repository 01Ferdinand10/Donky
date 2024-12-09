#ifndef __score_SCENE_H__
#define __score_SCENE_H__

#include "cocos2d.h"


class score : public cocos2d::Scene {
private:
    int music_id;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuReturnCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(score);

};

#endif // __score_SCENE_H__