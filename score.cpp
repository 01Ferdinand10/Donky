#include "C:\Users\lferr\OneDrive\Escritorio\DMario\proj.win32\score.h"
#include "C:\Users\lferr\OneDrive\Escritorio\DMario\proj.win32\Manu.h"
#include "AudioEngine.h"
#include "Game_Data.h"

USING_NS_CC;


Scene* score::createScene() {
	return score::create();
}


bool score::init() {
	if (!Scene::init()) return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Retorno
	auto retorno = MenuItemImage::create(
		"return_unp.png",
		"return.png",
		CC_CALLBACK_1(score::menuReturnCallback, this));
	retorno->setPosition(625, 40);
	retorno->setScale(1, .75);

	// Menu
	auto menu = Menu::create(retorno, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 10);

	// Audio
	music_id = AudioEngine::play2d("sound_silence.mp3");
	AudioEngine::setFinishCallback(music_id, [this](int id, const std::string& s) {
		music_id = AudioEngine::play2d("sound_score.mp3", true);
		AudioEngine::setVolume(music_id, 0.01f);
		});

	// Fondo
	auto fondo = Sprite::create("podio.png");
	fondo->setScale(visibleSize.width / fondo->getContentSize().width, visibleSize.height / fondo->getContentSize().height);
	fondo->setPosition(0, 0);
	fondo->setAnchorPoint(Vec2(0, 0));
	this->addChild(fondo, 0);

	// DECORACION
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("d1.png", Rect(0, 0, 355, 355)), "d1.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("d2.png", Rect(0, 0, 108, 355)), "d2.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("d3.png", Rect(0, 0, 190, 360)), "d3.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("d4.png", Rect(0, 0, 100, 320)), "d4.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("d5.png", Rect(0, 0, 790, 320)), "d5.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("tro1.png", Rect(0, 0, 230, 352)), "tro1.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("tro2.png", Rect(0, 0, 230, 352)), "tro2.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("tro3.png", Rect(0, 0, 230, 352)), "tro3.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("tro4.png", Rect(0, 0, 230, 352)), "tro4.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("tro5.png", Rect(0, 0, 230, 352)), "tro5.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("tro6.png", Rect(0, 0, 230, 352)), "tro6.png");


	// CASTILLOS
	auto c1 = Sprite::createWithSpriteFrameName("d1.png");
	c1->setScale(1);
	c1->setPosition(375, 380);
	c1->setAnchorPoint(Vec2(0, 0));
	this->addChild(c1, 3);

	auto c2 = Sprite::createWithSpriteFrameName("d1.png");
	c2->setScale(1);
	c2->setPosition(15, 120);
	c2->setAnchorPoint(Vec2(0, 0));
	this->addChild(c2, 3);

	auto c3 = Sprite::createWithSpriteFrameName("d1.png");
	c3->setScale(1);
	c3->setPosition(460, 5);
	c3->setAnchorPoint(Vec2(0, 0));
	this->addChild(c3, 3);

	// NUBES
	int ini = 420;
	for (int i = 0; i < 4; i++) {
		auto nu = Sprite::createWithSpriteFrameName("d5.png");
		nu->setScale(0.25, 0.2);
		nu->setPosition(ini, 125);
		nu->setAnchorPoint(Vec2(0, 0));
		this->addChild(nu, 4);

		ini += 50;
	}

	ini = 330;
	for (int i = 0; i < 4; i++) {
		auto nu1 = Sprite::createWithSpriteFrameName("d5.png");
		nu1->setScale(0.25, 0.2);
		nu1->setPosition(ini, 495);
		nu1->setAnchorPoint(Vec2(0, 0));
		this->addChild(nu1, 4);

		ini += 55;
	}

	ini = -15;
	for (int i = 0; i < 4; i++) {
		auto nu2 = Sprite::createWithSpriteFrameName("d5.png");
		nu2->setScale(0.25, 0.2);
		nu2->setPosition(ini, 240);
		nu2->setAnchorPoint(Vec2(0, 0));
		this->addChild(nu2, 4);

		ini += 55;
	}

	// TUBOS
	auto t1 = Sprite::createWithSpriteFrameName("d3.png");
	t1->setScale(1.5, 1.5);
	t1->setPosition(290, 170);
	t1->setAnchorPoint(Vec2(0, 0));
	t1->setRotation(90);
	this->addChild(t1, 2);

	auto t2 = Sprite::createWithSpriteFrameName("d3.png");
	t2->setScale(1.4, 1.4);
	t2->setPosition(225, 535);
	t2->setAnchorPoint(Vec2(0, 0));
	t2->setRotation(90);
	this->addChild(t2, 2);

	auto t3 = Sprite::createWithSpriteFrameName("d4.png");
	if (t3) {
		t3->setScale(.75, 1.6);
		t3->setPosition(80, -240);
		t3->setAnchorPoint(Vec2(0, 0));
		this->addChild(t3, 2);
	}

	// BANDERAS
	auto b1 = Sprite::createWithSpriteFrameName("d2.png");
	if (b1) {
		b1->setScale(1, 1.5);
		b1->setPosition(40, 230);
		b1->setAnchorPoint(Vec2(0, 0));
		this->addChild(b1, 2);
	}

	auto b2 = Sprite::createWithSpriteFrameName("d2.png");
	if (b2) {
		b2->setScale(1, 1.2);
		b2->setPosition(400, 450);
		b2->setAnchorPoint(Vec2(0, 0));
		this->addChild(b2, 2);
	}

	auto b3 = Sprite::createWithSpriteFrameName("d2.png");
	if (b3) {
		b3->setScale(1, 1.5);
		b3->setPosition(580, 20);
		b3->setAnchorPoint(Vec2(0, 0));
		this->addChild(b3, 2);
	}

	// LUGARES
	int points = 0;
	int point = Game_Data::getInstance()->getFinal();
	int pon = Game_Data::getInstance()->getTotal();

	if (pon > point) {
		points += pon;
		Game_Data::getInstance()->setFinal(pon);
	}
	else {
		points += point;
	}
	
	
	
	int ghost = cocos2d::RandomHelper::random_int(1, 10000);
	int ghost2 = cocos2d::RandomHelper::random_int(1, 1000);
	cocos2d::Vec2 l1;
	cocos2d::Vec2 l2;
	cocos2d::Vec2 l3;

	if (points > ghost && points > ghost2) {
		l1 = cocos2d::Vec2(145, 300);
	}
	else if (points < ghost && points < ghost2) {
		l1 = cocos2d::Vec2(505, 550);
	}
	else {
		l1 = cocos2d::Vec2(590, 180);
	}


	if (points < ghost && ghost > ghost2) {
		l2 = cocos2d::Vec2(145, 300);
	}
	else if (points > ghost && ghost < ghost2) {
		l2 = cocos2d::Vec2(505, 550);
	}
	else {
		l2 = cocos2d::Vec2(590, 180);
	}


	if (points < ghost2 && ghost < ghost2) {
		l3 = cocos2d::Vec2(145, 300);
	}
	else if (points > ghost2 && ghost > ghost2) {
		l3 = cocos2d::Vec2(505, 550);
	}
	else {
		l3 = cocos2d::Vec2(590, 180);
	}


	// MARIO (PLAYER)
	auto sprite = Sprite::createWithSpriteFrameName("tro3.png");
	sprite->setPosition(l1);
	sprite->setScale(0.5, 0.5);
	this->addChild(sprite, 3);

	Vector<SpriteFrame*>mario;
	mario.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("tro3.png"));
	mario.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("tro4.png"));

	auto marx = Animation::createWithSpriteFrames(mario, 0.25);
	marx->setLoops(-1);
	auto rugi = Animate::create(marx);
	sprite->runAction(rugi);

	
	auto tex = Label::createWithTTF(std::to_string(points), "fonts/Marker Felt.ttf", 50); 
	tex->setPosition(l1.x -20, l1.y +100);
	tex->setScale(0.5, 0.55);
	this->addChild(tex, 5);


	// GHOST
	auto sprit = Sprite::createWithSpriteFrameName("tro1.png");
	sprit->setPosition(l2);
	sprit->setScale(0.5, 0.5);
	this->addChild(sprit, 3);

	Vector<SpriteFrame*>ara;
	ara.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("tro1.png"));
	ara.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("tro2.png"));

	auto mar = Animation::createWithSpriteFrames(ara, 0.25);
	mar->setLoops(-1);
	auto rug = Animate::create(mar);
	sprit->runAction(rug);

	auto te = Label::createWithTTF(std::to_string(ghost), "fonts/Marker Felt.ttf", 50);
	te->setPosition(l2.x - 20, l2.y + 100);
	te->setScale(0.5, 0.55);
	this->addChild(te, 5);


	// GHOST2
	auto spri = Sprite::createWithSpriteFrameName("tro5.png");
	spri->setPosition(l3);
	spri->setScale(0.5, 0.5);
	this->addChild(spri, 3);

	Vector<SpriteFrame*>ar;
	ar.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("tro5.png"));
	ar.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("tro6.png"));

	auto ma = Animation::createWithSpriteFrames(ar, 0.25);
	ma->setLoops(-1);
	auto ru = Animate::create(ma);
	spri->runAction(ru);

	auto t = Label::createWithTTF(std::to_string(ghost2), "fonts/Marker Felt.ttf", 50);
	t->setPosition(l3.x - 20, l3.y + 100);
	t->setScale(0.5, 0.55);
	this->addChild(t, 5);

	return true;
}

void score::menuReturnCallback(Ref* pSender) {
	AudioEngine::stop(music_id);
	int soundID = AudioEngine::play2d("sound_press.mp3");
	AudioEngine::setFinishCallback(music_id, [this](int id, const std::string& s) {
		music_id = AudioEngine::play2d("sound_silence.mp3");
		});

	auto regre = Manu::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, regre));
}