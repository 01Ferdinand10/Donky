#include "C:\Users\lferr\OneDrive\Escritorio\DMario\proj.win32\info.h"
#include "C:\Users\lferr\OneDrive\Escritorio\DMario\proj.win32\Manu.h"
#include "AudioEngine.h"

USING_NS_CC;


Scene* info::createScene() {
	return info::create();
}


bool info::init() {
	if (!Scene::init()) return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Audio
	music_id = AudioEngine::play2d("sound_silence.mp3");
	AudioEngine::setFinishCallback(music_id, [this](int id, const std::string& s) {
		music_id = AudioEngine::play2d("sound_info.mp3", true);
		AudioEngine::setVolume(music_id, 0.01f);
		});

	// Fondo
	auto fondo = Sprite::create("walle.png");
	fondo->setScale(visibleSize.width / fondo->getContentSize().width, visibleSize.height / fondo->getContentSize().height);
	fondo->setPosition(0, 0);
	fondo->setAnchorPoint(Vec2(0, 0));
	this->addChild(fondo, 0);

	// Retorno
	auto retorno = MenuItemImage::create(
		"return_unp.png",
		"return.png",
		CC_CALLBACK_1(info::menuReturnCallback, this));
	retorno->setPosition(625, 40);
	retorno->setScale(1, .75);

	// Menu
	auto menu = Menu::create(retorno, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	// Titulo
	auto tite = Sprite::create("detail.png");
	tite->setScale(1.2, .95);
	tite->setPosition(Director::getInstance()->getVisibleSize().width / 2, 835);
	this->addChild(tite, 1);

	// Marcos
	auto mark = Sprite::create("marco.png");
	mark->setPosition(64, 715);
	mark->setScale(0.5, 0.5);
	this->addChild(mark, 2);

	auto mark0 = Sprite::create("marco.png");
	mark0->setPosition(500, 715);
	mark0->setScale(0.5, 0.5);
	this->addChild(mark0, 2);

	auto mark2 = Sprite::create("marco.png");
	mark2->setPosition(64, 560);
	mark2->setScale(0.5, 0.5);
	this->addChild(mark2, 2);

	auto mark3 = Sprite::create("marco.png");
	mark3->setPosition(64, 405);
	mark3->setScale(0.5, 0.5);
	this->addChild(mark3, 2);

	auto mark30 = Sprite::create("marco.png");
	mark30->setPosition(500, 405);
	mark30->setScale(0.5, 0.5);
	this->addChild(mark30, 2);

	auto mark4 = Sprite::create("marco.png");
	mark4->setPosition(64, 235);
	mark4->setScale(0.5, 0.5);
	this->addChild(mark4, 2);

	auto mark5 = Sprite::create("marco.png");
	mark5->setPosition(64, 80);
	mark5->setScale(0.5, 0.5);
	this->addChild(mark5, 2);



	// -------------------------------Mario Bros
	auto sprite = Sprite::create("am.png");
	sprite->setPosition(78, 695);
	sprite->setScale(0.3, 0.3);
	this->addChild(sprite, 1);

	// Frames Mario
	Vector<SpriteFrame*>mario;
	mario.pushBack(SpriteFrame::create("bm.png", Rect(0, 0, 400, 400)));
	mario.pushBack(SpriteFrame::create("cm.png", Rect(0, 0, 400, 400)));

	//Ejecutar
	auto marx = Animation::createWithSpriteFrames(mario, 0.25);
	marx->setLoops(-1);
	auto rugi = Animate::create(marx);
	sprite->runAction(rugi);

	// Tag
	auto tex = Sprite::create("info_matio.png");
	tex->setPosition(290, 715);
	tex->setScale(0.5, 0.55);
	this->addChild(tex, 1);

	// -------------------------------Princesa Peach
	auto sprite1 = Sprite::create("prince.png");
	sprite1->setPosition(125, 510);
	sprite1->setScale(0.5, 0.45);
	this->addChild(sprite1, 1);

	// Frames Peach
	Vector<SpriteFrame*>princesa;
	princesa.pushBack(SpriteFrame::create("prince.png", Rect(0, 0, 400, 400)));
	princesa.pushBack(SpriteFrame::create("princess.png", Rect(0, 0, 400, 400)));

	//Ejecutar
	auto prin = Animation::createWithSpriteFrames(princesa, 0.25);
	prin->setLoops(-1);
	auto pri = Animate::create(prin);
	sprite1->runAction(pri);

	// Tag
	auto tex1 = Sprite::create("info_peach.png");
	tex1->setPosition(280, 545);
	tex1->setScale(0.5, 0.49);
	this->addChild(tex1, 1);


	// -------------------------------King Kong
	auto sprite2 = Sprite::create("c.png");
	sprite2->setPosition(72, 370);
	sprite2->setScale(0.22, 0.31);
	this->addChild(sprite2, 1);

	// Frames Kong
	Vector<SpriteFrame*>kong;
	kong.pushBack(SpriteFrame::create("d.png", Rect(0, 0, 400, 400)));
	kong.pushBack(SpriteFrame::create("e.png", Rect(0, 0, 400, 400)));

	//Ejecutar
	auto kon = Animation::createWithSpriteFrames(kong, 0.25);
	kon->setLoops(-1);
	auto ko = Animate::create(kon);
	sprite2->runAction(ko);

	// Tag
	auto tex2 = Sprite::create("info_donkey.png");
	tex2->setPosition(280, 400);
	tex2->setScale(0.5, 0.49);
	this->addChild(tex2, 1);


	// -------------------------------Fuegos
	auto sprite3 = Sprite::create("es.png");
	sprite3->setPosition(549, 670);
	sprite3->setScale(0.45, 0.45);
	this->addChild(sprite3, 1);

	// Frames Fireballs
	Vector<SpriteFrame*>fire;
	fire.pushBack(SpriteFrame::create("es.png", Rect(0, 0, 400, 400)));
	fire.pushBack(SpriteFrame::create("esp.png", Rect(0, 0, 400, 400)));
	fire.pushBack(SpriteFrame::create("espi.png", Rect(0, 0, 400, 400)));
	fire.pushBack(SpriteFrame::create("espiri.png", Rect(0, 0, 400, 400)));

	//Ejecutar
	auto fir = Animation::createWithSpriteFrames(fire, 0.25);
	fir->setLoops(-1);
	auto fi = Animate::create(fir);
	sprite3->runAction(fi);

	// Tag
	auto tex3 = Sprite::create("info_flama.png");
	tex3->setPosition(540, 608);
	tex3->setScale(0.36, 0.3);
	this->addChild(tex3, 1);



	// -------------------------------Bote llamas
	auto sprite4 = Sprite::create("con.png");
	sprite4->setPosition(575, 363);
	sprite4->setScale(0.52, 0.48);
	this->addChild(sprite4, 1);

	// Frames Fireballs
	Vector<SpriteFrame*>flames;
	flames.pushBack(SpriteFrame::create("con.png", Rect(0, 0, 400, 400)));
	flames.pushBack(SpriteFrame::create("conte.png", Rect(0, 0, 400, 400)));
	flames.pushBack(SpriteFrame::create("contene.png", Rect(0, 0, 400, 400)));
	flames.pushBack(SpriteFrame::create("contenedor.png", Rect(0, 0, 400, 400)));

	//Ejecutar
	auto bote = Animation::createWithSpriteFrames(flames, 0.25);
	bote->setLoops(-1);
	auto bo = Animate::create(bote);
	sprite4->runAction(bo);

	// Tag
	auto tex4 = Sprite::create("info_bote.png");
	tex4->setPosition(540, 300);
	tex4->setScale(0.4, 0.38);
	this->addChild(tex4, 1);



	// -------------------------------Puntos
	auto sprite5 = Sprite::create("sombri.png");
	sprite5->setPosition(65, 233);
	sprite5->setScale(0.38, 0.38);
	this->addChild(sprite5, 1);

	// Tag
	auto tex5 = Sprite::create("info_puntos.png");
	tex5->setPosition(270, 250);
	tex5->setScale(0.45, 0.45);
	this->addChild(tex5, 1);


	// -------------------------------Martillo
	auto sprite6 = Sprite::create("marti.png");
	sprite6->setPosition(65, 77);
	sprite6->setScale(0.38, 0.38);
	this->addChild(sprite6, 1);

	// Tag
	auto tex6 = Sprite::create("info_martillo.png");
	tex6->setPosition(340, 90);
	tex6->setScale(0.71, 0.71);
	this->addChild(tex6, 1);


	return true;
}

void info::menuReturnCallback(Ref* pSender) {
	AudioEngine::stop(music_id);
	int soundID = AudioEngine::play2d("sound_press.mp3");
	AudioEngine::setFinishCallback(music_id, [this](int id, const std::string& s) {
		music_id = AudioEngine::play2d("sound_silence.mp3");
	});

	auto regre = Manu::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, regre));
}