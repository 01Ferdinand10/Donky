#ifndef __level_3_SCENE_H__
#define __level_3_SCENE_H__

#include "cocos2d.h"

#define SPACE_KEY 0
#define DOWN_ARROW_KEY 1
#define LEFT_ARROW_KEY 2
#define RIGHT_ARROW_KEY 3
#define UP_ARROW_KEY 4
#define DOWN_ARROW_KEY 5

class level_3 : public cocos2d::Scene {
private:
    int music_id, touch_escalaera = 0;
    bool key_states[6], suelo = true, lado_salto = true, escalera = false, perder = false, no_more = false, moverse = false;
    bool hammer = false;

    cocos2d::Sprite* po;
    cocos2d::Vec2 boon;

    cocos2d::Label* label;
    cocos2d::Sprite* bote;
    cocos2d::Sprite* mario;
    cocos2d::Sprite* barril;
    cocos2d::Sprite* tabl;
    cocos2d::Sprite* k1;
    cocos2d::Sprite* prin;
    cocos2d::Sprite* sp;

    cocos2d::Vector<cocos2d::Sprite*> caida;
    cocos2d::Vector<cocos2d::Sprite*> desaparecer;
    cocos2d::Vector<cocos2d::Sprite*> puntacos;
    cocos2d::Vector<cocos2d::Sprite*> martillos;
    cocos2d::Vector<cocos2d::Sprite*> paredes;
    cocos2d::Vector<cocos2d::Sprite*> pisos;
    cocos2d::Vector<cocos2d::Sprite*> stair_inte;
    cocos2d::Vector<cocos2d::Sprite*> barrixlex;

    cocos2d::PhysicsBody* fisica;

public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);

    bool onContactBegin(cocos2d::PhysicsContact& contact);
    void onContactSeparate(cocos2d::PhysicsContact& contact);

    void rodando(float dt);
    void anadir_barril(float dt);
    void retraso();
    void actualizar_barriles(float dt);

    void fall(float dt);
    void late();

    void modificar();

    void sin_power(float dt);
    void tite();

    void finito();
    void sad(float dt);

    void muerte();
    void siguiente();

    void moverser();
    void moversel();

    void destruir();

    void direcNormal();
    void direcJump();

    void kataplam();


    CREATE_FUNC(level_3);

};

#endif // __level_3_SCENE_H__