#include "Manu.h"
#include "level_1.h"
#include "level_2.h"
#include "level_3.h"
#include "info.h"
#include "score.h"
#include "AudioEngine.h"
#include "Game_Data.h"

USING_NS_CC;

Scene* Manu::createScene()
{
    return Manu::create();
}

bool Manu::init() {
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Boton salida del juego
    auto cont = MenuItemImage::create(
        "continue.png",
        "continue_press.png",
        CC_CALLBACK_1(Manu::menuPlay2Callback, this));
    cont->setPosition(visibleSize.width / 2, 2 * visibleSize.height / 4);
    cont->setScale(visibleSize.width / 800, visibleSize.height / 1200);
    cont->setVisible(false);

    bool caso = Game_Data::getInstance()->getLevel2();
    if (caso) {
        cont->setVisible(true);
    }

    // Boton salida del juego
    auto close = MenuItemImage::create(
        "exit.png",
        "exit2.png",
        CC_CALLBACK_1(Manu::menuCloseCallback, this));
    close->setPosition(visibleSize.width / 8, 2 * visibleSize.height / 18);
    close->setScale(visibleSize.width / 1150, visibleSize.height / 1200);

    // Boton info del juego
    auto info = MenuItemImage::create(
        "i.png",
        "info.png",
        CC_CALLBACK_1(Manu::menuInfoCallback, this));
    info->setPosition(600, 2 * visibleSize.height / 18);
    info->setScale(visibleSize.width / 1500, visibleSize.height / 1800);

    // Boton score del juego
    auto score = MenuItemImage::create(
        "score_unpres.png",
        "score_pres.png",
        CC_CALLBACK_1(Manu::menuScoreCallback, this));
    score->setPosition(607,2 * visibleSize.height / 7.25);
    score->setScale(visibleSize.width / 900, visibleSize.height / 1300);

    // Boton Start del juego
    auto start = MenuItemImage::create(
        "donkey-Kong.png",
        "donkey-sec.png",
        CC_CALLBACK_1(Manu::menuPlayCallback, this));
    start->setPosition(visibleSize.width / 2, 5 * visibleSize.height / 6.5);
    start->setScale(visibleSize.width/ 625, visibleSize.height/ 700);

    // Menu
    menu = Menu::create(close, start, info, score, cont, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    // Fondo
    auto fondo = Sprite::create("fondo2.png");
    fondo->setScale(visibleSize.width / fondo->getContentSize().width, visibleSize.height / fondo->getContentSize().height);
    fondo->setPosition(0, 0);
    fondo->setAnchorPoint(Vec2(0, 0));
    this->addChild(fondo, 0);  

    if (AudioEngine::getPlayingAudioCount() == 0) {
        AudioEngine::preload("sound_start.mp3");
        AudioEngine::preload("sound_manu.mp3");
        AudioEngine::preload("sound_exit.mp3");
        AudioEngine::preload("sound_play.mp3");
        AudioEngine::preload("sound_press.mp3");
        AudioEngine::preload("sound_correr.mp3");

        AudioEngine::preload("sound_info.mp3");

        AudioEngine::preload("sound_lost.mp3");
        AudioEngine::preload("sound_salto.mp3");

        AudioEngine::preload("sound_beginning_1.mp3");
        AudioEngine::preload("sound_stage_1.mp3");

        AudioEngine::preload("sound_win.mp3");
        AudioEngine::preload("sound_stage_2.mp3");

        AudioEngine::preload("sound_stage_3.mp3");

        AudioEngine::preload("sound_barril.mp3");
        AudioEngine::preload("sound_score.mp3");

        AudioEngine::setMaxAudioInstance(30);
    }

    music_id = AudioEngine::play2d("sound_start.mp3");
    AudioEngine::setFinishCallback(music_id, [this](int id, const std::string& s) {
        music_id = AudioEngine::play2d("sound_manu.mp3", true);
    });

    return true;
}

void Manu::menuScoreCallback(Ref* pSender) {
    menu->setEnabled(false);
    AudioEngine::stop(music_id);

    int soundID = AudioEngine::play2d("sound_press.mp3");

    auto espera = DelayTime::create(0.5);
    auto cambio = CallFunc::create([this]() {
        auto mySe = score::createScene();
        auto transition = TransitionFade::create(2, mySe);
        menu->setEnabled(true);
        Director::getInstance()->replaceScene(transition);

    });

    this->runAction(Sequence::create(espera, cambio, nullptr));
}


void Manu::menuInfoCallback(Ref* pSender) {
    menu->setEnabled(false);
    AudioEngine::stop(music_id);

    int soundID = AudioEngine::play2d("sound_press.mp3");

    auto espera = DelayTime::create(0.5);
    auto cambio = CallFunc::create([this](){
        auto mySe = info::createScene();
        auto transition = TransitionFade::create(2, mySe);
        menu->setEnabled(true);
        Director::getInstance()->replaceScene(transition);
    });

    this->runAction(Sequence::create(espera, cambio, nullptr));
}

void Manu::menuPlay2Callback(Ref* pSender) {
    menu->setEnabled(false);
    AudioEngine::stop(music_id);
    int soundID = AudioEngine::play2d("sound_press.mp3");
    Game_Data::getInstance()->setPoints(0);

    auto espera = DelayTime::create(0.5);
    auto cambio = CallFunc::create([this]() {

        bool pon = Game_Data::getInstance()->getLevel3();
        bool pin = Game_Data::getInstance()->getLevel2();
        if (pon) {
            auto mySe = level_3::createScene();
            auto transition = TransitionFade::create(2, mySe);
            menu->setEnabled(true);
            Director::getInstance()->replaceScene(transition);
        }
        else if (pin) {
            auto mySe = level_2::createScene();
            auto transition = TransitionFade::create(2, mySe);
            menu->setEnabled(true);
            Director::getInstance()->replaceScene(transition);
        }
        else {
            auto mySe = level_1::createScene();
            auto transition = TransitionFade::create(2, mySe);
            menu->setEnabled(true);
            Director::getInstance()->replaceScene(transition);
        }  
    });

    this->runAction(Sequence::create(espera, cambio, nullptr));
}

void Manu::menuPlayCallback(Ref* pSender) {
    AudioEngine::stop(music_id);
    menu->setEnabled(false);

    Game_Data::getInstance()->setPoints(0);
    Game_Data::getInstance()->setTotal(0);

    // Mario Izq
    auto sprite = Sprite::create("am.png");
    sprite->setPosition(20, (Director::getInstance()->getVisibleSize().height / 2) - 50);
    sprite->setScale(0.6, 0.6);
    this->addChild(sprite, 2);

    // Frames Mario
    Vector<SpriteFrame*>correr;
    correr.pushBack(SpriteFrame::create("bm.png", Rect(0, 0, 400, 400)));
    correr.pushBack(SpriteFrame::create("cm.png", Rect(0, 0, 400, 400)));

    // Juntar
    auto izq = CallFunc::create([sprite, correr]() {
        sprite->setSpriteFrame(correr.at(0));
        });
    auto der = CallFunc::create([sprite, correr]() {
        sprite->setSpriteFrame(correr.at(1));
        });
    auto paso = MoveBy::create(0.25, Point(30, 0));

    // Ejecutar
    auto escalar = Sequence::create(izq, paso->clone(), der, paso->clone(), nullptr);
    sprite-> runAction(Repeat::create(escalar, 15));

    // Audios
    int soundID = AudioEngine::play2d("sound_press.mp3");
    AudioEngine::setFinishCallback(soundID, [this](int id, const std::string& filePath) {
        int sID = AudioEngine::play2d("sound_correr.mp3");
    });

    auto espera = DelayTime::create(6.5);
    auto cambio = CallFunc::create([this]() {
        auto mySe = level_1::createScene();
        auto transition = TransitionFade::create(2, mySe);
        menu->setEnabled(true);
        Director::getInstance()->replaceScene(mySe);
    });

    this->runAction(Sequence::create(espera, cambio, nullptr));
}


void Manu::menuCloseCallback(Ref* pSender) {
    AudioEngine::stop(music_id);
    menu->setEnabled(false);

    // Kong Abajo
    auto sprite = Sprite::create("a.png");
    sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, 50);
    sprite->setScale(0.7, 0.7);
    this->addChild(sprite, 2);

    // Frames Kong
    Vector<SpriteFrame*>subir;
    subir.pushBack(SpriteFrame::create("b.png", Rect(0, 0, 400, 400)));
    subir.pushBack(SpriteFrame::create("a.png", Rect(0, 0, 400, 400)));

    Vector<SpriteFrame*>rugir;
    rugir.pushBack(SpriteFrame::create("d.png", Rect(0, 0, 400, 400)));
    rugir.pushBack(SpriteFrame::create("e.png", Rect(0, 0, 400, 400)));

    // Juntar
    auto izq = CallFunc::create([sprite, subir]() {
        sprite->setSpriteFrame(subir.at(0));
        });
    auto der = CallFunc::create([sprite, subir]() {
        sprite->setSpriteFrame(subir.at(1));
        });
    auto paso = MoveBy::create(0.25, Point(0, 25));

    // Escalar Kong
    auto escalar = Sequence::create(izq, paso->clone(), der, paso->clone(), nullptr);
    auto escala = Repeat::create(escalar, 2);

    // Salto de Kong
    auto saltito = MoveBy::create(0.25, Point(0, 150));

    // Accioenes rugir
    auto rugido = Animation::createWithSpriteFrames(rugir, 0.25);
    rugido->setLoops(6);
    auto rugi = Animate::create(rugido);

    //Orden
    sprite->runAction(Sequence::create(escala, saltito, rugi, nullptr));


    int soundID = AudioEngine::play2d("sound_exit.mp3");

    AudioEngine::setFinishCallback(soundID, [this](int id, const std::string& filePath) {
        menu->setEnabled(true);
        Director::getInstance()->end();
    });
}