#include "C:\Users\lferr\OneDrive\Escritorio\DMario\proj.win32\level_2.h"
#include "C:\Users\lferr\OneDrive\Escritorio\DMario\proj.win32\level_3.h"
#include "C:\Users\lferr\OneDrive\Escritorio\DMario\proj.win32\Manu.h"
#include "AudioEngine.h"
#include "cocos2d.h"
#include "Game_Data.h"

USING_NS_CC;


Scene* level_2::createScene() {
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_SHAPE);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -250));

	auto layer = level_2::create();
	scene->addChild(layer);

	return scene;
}

bool level_2::init() {
	if (!Scene::initWithPhysics()) return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Music
	music_id = AudioEngine::play2d("sound_stage_2.mp3", true);

	// Fondo
	auto fondo = Sprite::create("l1_fondo.png");
	fondo->setScale(visibleSize.width / fondo->getContentSize().width, visibleSize.height / fondo->getContentSize().height);
	fondo->setPosition(0, 0);
	fondo->setAnchorPoint(Vec2(0, 0));
	this->addChild(fondo, 0);


	// PISO 1
	Vector<Sprite*> piso1;

	int ini = 28;
	for (int i = 0; i < 1; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 15);
		s->setScale(5.1, 6);
		this->addChild(s, 1);
		pisos.pushBack(s);
		ini += 47;
	}

	ini = 75;
	for (int i = 0; i < 15; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 15);
		s->setScale(5.1, 6);

		this->addChild(s, 1);
		piso1.pushBack(s);
		pisos.pushBack(s);

		ini += 47;
	}


	// PISO 2
	Vector<Sprite*> piso2;

	ini = 28;
	for (int i = 0; i < 1; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 150);
		s->setScale(5.1, 6);
		this->addChild(s, 1);
		pisos.pushBack(s);
		ini += 47;
	}

	ini = 75;
	for (int i = 0; i < 10; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 150);
		s->setScale(5.1, 6);

		this->addChild(s, 1);
		piso2.pushBack(s);
		pisos.pushBack(s);

		ini += 47;
	}

	// PISO 3
	Vector<Sprite*> piso3;

	ini = 686;
	for (int i = 0; i < 1; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 275);
		s->setScale(5.1, 6);
		this->addChild(s, 1);
		pisos.pushBack(s);

		ini -= 47;
	}

	ini = 639;
	for (int i = 0; i < 10; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 275);
		s->setScale(5.1, 6);

		this->addChild(s, 1);
		piso3.pushBack(s);
		pisos.pushBack(s);

		ini -= 47;
	}


	// PISO 4
	Vector<Sprite*> piso4;

	ini = 28;
	for (int i = 0; i < 1; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 400);
		s->setScale(5.1, 6);
		this->addChild(s, 1);
		pisos.pushBack(s);

		ini += 47;
	}

	ini = 75;
	for (int i = 0; i < 10; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 400);
		s->setScale(5.1, 6);

		this->addChild(s, 1);
		piso4.pushBack(s);
		pisos.pushBack(s);

		ini += 47;
	}


	// PISO 5
	Vector<Sprite*> piso5;

	ini = 686;
	for (int i = 0; i < 1; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 525);
		s->setScale(5.1, 6);
		this->addChild(s, 1);
		pisos.pushBack(s);

		ini -= 47;
	}

	ini = 639;
	for (int i = 0; i < 10; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 525);
		s->setScale(5.1, 6);

		this->addChild(s, 1);
		piso5.pushBack(s);
		pisos.pushBack(s);

		ini -= 47;
	}

	// PISO 6
	Vector<Sprite*> piso6;

	ini = 28;
	for (int i = 0; i < 8; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 650);
		s->setScale(5.1, 6);
		this->addChild(s, 1);
		pisos.pushBack(s);

		ini += 47;
	}

	ini = 404;
	for (int i = 0; i < 3; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 650);
		s->setScale(5.1, 6);

		this->addChild(s, 1);
		piso6.pushBack(s);
		pisos.pushBack(s);

		ini += 47;
	}

	// PISO Princesa
	ini = 310;
	for (int i = 0; i < 3; i++) {
		auto s = Sprite::create("floor_short.png");

		s->setPosition(ini, 750);
		s->setScale(5.1, 6);
		this->addChild(s, 1);
		pisos.pushBack(s);

		ini += 47;
	}

	// FISICA PISOS
	for (auto p : pisos) {
		auto fisica = PhysicsBody::createBox(p->getContentSize(), PhysicsMaterial(0, 0, 0));
		fisica->setDynamic(false);
		fisica->setCategoryBitmask(0x01);
		fisica->setCollisionBitmask(0x01);
		fisica->setContactTestBitmask(0xFFFFFFFF);
		p->addComponent(fisica);
	}

	// PAREDES
	ini = 146;
	for (int i = 0; i < 12; i++) {
		auto s = Sprite::create("floor_short.png");
		s->setRotation(90);
		s->setPosition(-14, ini);
		s->setScale(5, 6);
		this->addChild(s, 1);
		paredes.pushBack(s);

		ini += 47;
	}

	ini = 5;
	for (int i = 0; i < 18; i++) {
		auto s = Sprite::create("floor_short.png");
		s->setRotation(90);
		s->setPosition(720, ini);
		s->setScale(5, 6);
		this->addChild(s, 1);
		paredes.pushBack(s);

		ini += 47;
	}

	for (auto p : paredes) {
		auto fisica = PhysicsBody::createBox(p->getContentSize(), PhysicsMaterial(0, 1, 0));
		fisica->setDynamic(false);
		fisica->setCategoryBitmask(0x01);
		fisica->setCollisionBitmask(0x01);
		fisica->setContactTestBitmask(0xFFFFFFFF);
		p->addComponent(fisica);
	}

	// KONG
	k1 = Sprite::create("1b.png");
	k1->setPosition(140, 710);
	k1->setScale(0.5, 0.48);
	this->addChild(k1, 4);

	auto fisic = PhysicsBody::createBox(Size(370, 320), PhysicsMaterial(0, 0, 0));
	fisic->setDynamic(false);
	fisic->setRotationEnable(false);
	fisic->setCategoryBitmask(0x01);
	fisic->setCollisionBitmask(0x01);
	fisic->setContactTestBitmask(0xFFFFFFFF);
	k1->addComponent(fisic);

	Vector<SpriteFrame*>arrojar;
	arrojar.pushBack(SpriteFrame::create("1e.png", Rect(0, 0, 400, 300)));
	arrojar.pushBack(SpriteFrame::create("1f.png", Rect(0, 0, 400, 300)));
	arrojar.pushBack(SpriteFrame::create("1g.png", Rect(0, 0, 400, 300)));
	auto arro = Animation::createWithSpriteFrames(arrojar, 1);
	arro->setLoops(-1);
	auto arro_barril = Animate::create(arro);

	// Princesa
	prin = Sprite::create("prince.png");
	prin->setPosition(360, 780);
	prin->setScale(0.35, 0.35);
	prin->setVisible(true);
	this->addChild(prin, 3);

	auto fic = PhysicsBody::createBox(Size(157, 195), PhysicsMaterial(0, 0, 0));
	fic->setPositionOffset(Vec2(0, 30));
	fic->setDynamic(false);
	fic->setRotationEnable(false);
	fic->setCategoryBitmask(0x01);
	fic->setCollisionBitmask(0x01);
	fic->setContactTestBitmask(0xFFFFFFFF);
	prin->addComponent(fic);


	// Bajar piso 6
	auto floor6 = CallFunc::create([piso6]() {
		int cant = 4;
		for (auto f : piso6) {
			f->runAction(MoveBy::create(0.1, Point(0, -cant)));
			cant += 4;
		}
		});

	// Bajar pisos
	auto floor5 = CallFunc::create([piso5]() {
		int cant = 3;
		for (auto f : piso5) {
			f->runAction(MoveBy::create(0.1, Point(0, -cant)));
			cant += 3;
		}
		});

	auto floor4 = CallFunc::create([piso4]() {
		int cant = 3;
		for (auto f : piso4) {
			f->runAction(MoveBy::create(0.1, Point(0, -cant)));
			cant += 3;
		}
		});

	auto floor3 = CallFunc::create([piso3]() {
		int cant = 3;
		for (auto f : piso3) {
			f->runAction(MoveBy::create(0.1, Point(0, -cant)));
			cant += 3;
		}
		});

	auto floor2 = CallFunc::create([piso2]() {
		int cant = 3;
		for (auto f : piso2) {
			f->runAction(MoveBy::create(0.1, Point(0, -cant)));
			cant += 3;
		}
		});

	auto floor1 = CallFunc::create([piso1]() {
		float cant = 1.5;
		for (auto f : piso1) {
			f->runAction(MoveBy::create(0.1, Point(0, cant)));
			cant += 1.5;
		}
		});

	// BARRILES
	auto barril = Sprite::create("barriles.png");
	barril->setPosition(30, 712);
	barril->setScale(5.2, 5);
	barril->setVisible(false);
	this->addChild(barril, 1);

	auto appear_barri = CallFunc::create([barril]() {
		barril->setVisible(true);
		});


	// New Escaleras
	ini = 90;
	for (int i = 0; i < 2; i++) {
		auto s = Sprite::create("stair.png");

		s->setPosition(500, ini);
		s->setScale(4.55, 4.55);
		this->addChild(s, 3);
		stair_inte.pushBack(s);

		ini += 41;
	}

	ini = 219;
	for (int i = 0; i < 2; i++) {
		auto s = Sprite::create("stair.png");

		s->setPosition(165, ini);
		s->setScale(4.55, 4.55);
		this->addChild(s, 3);
		stair_inte.pushBack(s);

		ini += 41;
	}

	ini = 463;
	for (int i = 0; i < 2; i++) {
		auto s = Sprite::create("stair.png");

		s->setPosition(200, ini);
		s->setScale(4.55, 4.55);
		this->addChild(s, 3);
		stair_inte.pushBack(s);

		ini += 41;
	}

	ini = 345;
	for (int i = 0; i < 2; i++) {
		auto s = Sprite::create("stair.png");

		s->setPosition(525, ini);
		s->setScale(4.5, 4.5);
		this->addChild(s, 3);
		stair_inte.pushBack(s);

		ini += 41;
	}

	ini = 593;
	for (int i = 0; i < 2; i++) {
		auto s = Sprite::create("stair.png");

		s->setPosition(550, ini);
		s->setScale(4.5, 4.5);
		this->addChild(s, 3);
		stair_inte.pushBack(s);

		ini += 40;
	}

	ini = 683;
	for (int i = 0; i < 7; i++) {
		auto s = Sprite::create("stair.png");

		s->setPosition(275, ini);
		s->setScale(4.5, 4.5);
		this->addChild(s, 3);
		stair_inte.pushBack(s);

		ini += 40;
	}

	ini = 683;
	for (int i = 0; i < 7; i++) {
		auto s = Sprite::create("stair.png");

		s->setPosition(202, ini);
		s->setScale(4.5, 4.5);
		this->addChild(s, 0);
		stair_inte.pushBack(s);

		ini += 40;
	}

	for (auto p : stair_inte) {
		auto fisica = PhysicsBody::createBox(p->getContentSize(), PhysicsMaterial(0, 0, 0));
		fisica->setDynamic(false);
		fisica->setCategoryBitmask(0x02);
		fisica->setCollisionBitmask(0x01);
		fisica->setContactTestBitmask(0xFFFFFFFF);
		p->addComponent(fisica);
	}

	// La princesa en apuros
	Vector<SpriteFrame*>cosorro;
	cosorro.pushBack(SpriteFrame::create("princess.png", Rect(0, 0, 300, 300)));
	cosorro.pushBack(SpriteFrame::create("rprince.png", Rect(0, 0, 300, 300)));

	auto ayu = CallFunc::create([&, cosorro]() {
		prin->setSpriteFrame(cosorro.at(0));
		});
	auto ayud = CallFunc::create([&, cosorro]() {
		prin->setSpriteFrame(cosorro.at(1));
		});

	int c = 65;
	auto stepr = Sequence::create(ayu, MoveBy::create(0.8, Point(c, 0)), nullptr);
	auto stepl = Sequence::create(ayud, MoveBy::create(0.8, Point(-c, 0)), nullptr);

	auto socorro = Sequence::create(DelayTime::create(2), stepr, DelayTime::create(2), stepl, nullptr);
	prin->runAction(RepeatForever::create(socorro));

	// Aparcion de escaleras y Animacion de Donkey Kong
	auto movi = Sequence::create(floor5, floor4, floor3, floor2, floor1, nullptr);
	k1->runAction(Sequence::create(floor6, movi, appear_barri, arro_barril, nullptr));


	for (int i = 0; i < 4; ++i) {
		key_states[i] = false;
	}

	//  ANIMACIONES MOVIMIENTO
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("bonus.png", Rect(0, 0, 700, 700)), "bonus.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("bm.png", Rect(0, 0, 380, 508)), "bm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("cm.png", Rect(0, 0, 380, 508)), "cm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("em.png", Rect(0, 0, 380, 508)), "em.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("fm.png", Rect(0, 0, 380, 508)), "fm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("am.png", Rect(0, 0, 380, 505)), "am.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("dm.png", Rect(0, 0, 380, 505)), "dm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("gm.png", Rect(0, 0, 380, 505)), "gm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("hm.png", Rect(0, 0, 380, 505)), "hm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("im.png", Rect(0, 0, 380, 505)), "im.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("barril.png", Rect(0, 0, 232, 232)), "barril.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("jm.png", Rect(0, 0, 240, 240)), "jm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("km.png", Rect(0, 0, 240, 240)), "km.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("lm.png", Rect(0, 0, 240, 240)), "lm.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("mm.png", Rect(0, 0, 380, 505)), "mm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("nm.png", Rect(0, 0, 380, 505)), "nm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("om.png", Rect(0, 0, 380, 505)), "om.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("pm.png", Rect(0, 0, 380, 505)), "pm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("qm.png", Rect(0, 0, 380, 505)), "qm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("rm.png", Rect(0, 0, 380, 508)), "rm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("sm.png", Rect(0, 0, 380, 508)), "sm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("tm.png", Rect(0, 0, 380, 508)), "tm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("um.png", Rect(0, 0, 380, 508)), "um.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("vm.png", Rect(0, 0, 380, 508)), "vm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("wm.png", Rect(0, 0, 380, 508)), "wm.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("ym.png", Rect(0, 0, 380, 508)), "ym.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("zm.png", Rect(0, 0, 380, 508)), "zm.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("1b.png", Rect(0, 0, 400, 400)), "1b.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("1c.png", Rect(0, 0, 400, 400)), "1c.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("marti.png", Rect(0, 0, 330, 360)), "marti.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("boom1.png", Rect(0, 0, 405, 353)), "boom1.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("boom2.png", Rect(0, 0, 405, 353)), "boom2.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("boom3.png", Rect(0, 0, 405, 353)), "boom3.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("boom4.png", Rect(0, 0, 405, 353)), "boom4.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("con.png", Rect(0, 0, 192, 353)), "con.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("conte.png", Rect(0, 0, 192, 353)), "conte.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("contene.png", Rect(0, 0, 192, 353)), "contene.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("contenedor.png", Rect(0, 0, 192, 353)), "contenedor.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("sombri.png", Rect(0, 0, 372, 351)), "sombri.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("telefo.png", Rect(0, 0, 352, 348)), "telefo.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("super_barril.png", Rect(0, 0, 232, 232)), "super_barril.png");

	// OBJETOS PUNTOS
	auto sombri = Sprite::createWithSpriteFrameName("sombri.png");
	if (sombri) {
		sombri->setPosition(200, 60);
		sombri->setScale(0.2, 0.2);
		sombri->setVisible(true);
		puntacos.pushBack(sombri);
		this->addChild(sombri, 1);
	}

	auto taq = PhysicsBody::createBox(Size(140, 140), PhysicsMaterial(0, 0, 0));
	taq->setPositionOffset(Vec2(-15, 15));
	taq->setDynamic(false);
	taq->setRotationEnable(false);
	taq->setCategoryBitmask(0x01);
	taq->setCollisionBitmask(0x02);
	taq->setContactTestBitmask(0xFFFFFFFF);
	taq->setGravityEnable(false);
	sombri->setPhysicsBody(taq);


	auto tel = Sprite::createWithSpriteFrameName("telefo.png");
	if (tel) {
		tel->setPosition(595, 395);
		tel->setScale(0.15, 0.15);
		tel->setVisible(true);
		puntacos.pushBack(tel);
		this->addChild(tel, 1);
	}

	auto tq = PhysicsBody::createBox(Size(130, 130), PhysicsMaterial(0, 0, 0));
	tq->setPositionOffset(Vec2(-12, 12));
	tq->setDynamic(false);
	tq->setRotationEnable(false);
	tq->setCategoryBitmask(0x01);
	tq->setCollisionBitmask(0x02);
	tq->setContactTestBitmask(0xFFFFFFFF);
	tq->setGravityEnable(false);
	tel->setPhysicsBody(tq);



	// BOTE LLAMAS
	bote = Sprite::createWithSpriteFrameName("con.png");
	if (bote) {
		bote->setPosition(100, 30);
		bote->setScale(0.48, 0.48);
		bote->setVisible(true);
		this->addChild(bote, 1);
	}
	auto tiq = PhysicsBody::createBox(Size(80, 120), PhysicsMaterial(0, 0, 0));
	tiq->setPositionOffset(Vec2(-20, 50));
	tiq->setDynamic(false);
	tiq->setRotationEnable(false);
	tiq->setCategoryBitmask(0x01);
	tiq->setCollisionBitmask(0x02);
	tiq->setContactTestBitmask(0xFFFFFFFF);
	tiq->setGravityEnable(false);
	bote->setPhysicsBody(tiq);

	Vector<SpriteFrame*>fuego;
	fuego.pushBack(SpriteFrame::create("con.png", Rect(0, 0, 400, 400)));
	fuego.pushBack(SpriteFrame::create("conte.png", Rect(0, 0, 400, 400)));
	fuego.pushBack(SpriteFrame::create("contene.png", Rect(0, 0, 400, 400)));
	fuego.pushBack(SpriteFrame::create("contenedor.png", Rect(0, 0, 400, 400)));

	auto fueg = Animation::createWithSpriteFrames(fuego, 0.25);
	fueg->setLoops(-1);
	auto fue = Animate::create(fueg);
	bote->runAction(fue);

	// MARTILLOS
	auto ha = Sprite::create("marti.png");
	if (ha) {
		ha->setPosition(80, 265);
		ha->setScale(0.2);
		ha->setVisible(true);
		martillos.pushBack(ha);
		this->addChild(ha, 5);
	}

	auto fa = PhysicsBody::createBox(Size(157, 177), PhysicsMaterial(0, 0, 0));
	fa->setPositionOffset(Vec2(-1, 1));
	fa->setDynamic(false);
	fa->setRotationEnable(false);
	fa->setCategoryBitmask(0x04);
	fa->setCollisionBitmask(0x01);
	fa->setContactTestBitmask(0xFFFFFFFF);
	ha->addComponent(fa);


	auto ham = Sprite::create("marti.png");
	if (ham) {
		ham->setPosition(650, 550);
		ham->setScale(0.2);
		ham->setVisible(true);
		martillos.pushBack(ham);
		this->addChild(ham, 5);
	}

	auto fai = PhysicsBody::createBox(Size(157, 177), PhysicsMaterial(0, 0, 0));
	fai->setPositionOffset(Vec2(-1, 1));
	fai->setDynamic(false);
	fai->setRotationEnable(false);
	fai->setCategoryBitmask(0x04);
	fai->setCollisionBitmask(0x01);
	fai->setContactTestBitmask(0xFFFFFFFF);
	ham->addComponent(fai);


	// CAIDA DE BARRILES
	retraso();

	// PUNTUACION
	tabl = Sprite::createWithSpriteFrameName("bonus.png");
	if (tabl) {
		tabl->setPosition(650, 720);
		tabl->setScale(0.45f);
		tabl->setVisible(true);
		this->addChild(tabl, 5);
	}

	int score = Game_Data::getInstance()->getPoints();
	label = Label::createWithTTF(std::to_string(score), "fonts/Marker Felt.ttf", 35);
	label->setPosition(Vec2(585, 820));
	label->setVisible(true);
	this->addChild(label);

	// Movimiento MARIO
	mario = Sprite::createWithSpriteFrameName("am.png");
	mario->setScale(0.13);
	mario->setPosition(120, 80);
	mario->setVisible(true);
	this->addChild(mario, 11);


	// FISICA MARIO
	fisica = PhysicsBody::createBox(Size(210, 270), PhysicsMaterial(0, 0, 0));
	fisica->setPositionOffset(Vec2(-7, 8));
	fisica->setDynamic(true);
	fisica->setRotationEnable(false);
	fisica->setCategoryBitmask(0x01);
	fisica->setCollisionBitmask(0x01);
	fisica->setContactTestBitmask(0xFFFFFFFF);
	mario->addComponent(fisica);

	// COLISIONES
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(level_2::onContactBegin, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(level_2::onContactSeparate, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	// TECLAS MOVIMIENTO
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(level_2::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(level_2::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->schedule([&](float delta) {
		Vec2 position = mario->getPosition();

		if (!perder) {
			if (key_states[SPACE_KEY] && suelo && !escalera) {
				suelo = false;
				position.y += 50;
				music_id = AudioEngine::play2d("sound_salto.mp3");
				direcJump();

				if (lado_salto) {
					if (hammer) {
						mario->setSpriteFrame("qm.png");
					}
					else {
						mario->setSpriteFrame("hm.png");
					}
				}
				else {
					if (hammer) {
						mario->setSpriteFrame("pm.png");
					}
					else {
						mario->setSpriteFrame("gm.png");
					}
				}
			}

			if (key_states[UP_ARROW_KEY] && escalera) {
				direcNormal();
				suelo = false;
				position.y += 2;
				if (hammer) {
					mario->setSpriteFrame("om.png");
				}
				else {
					mario->setSpriteFrame("im.png");
				}
			}

			if (key_states[DOWN_ARROW_KEY] && escalera) {
				direcNormal();
				suelo = false;
				position.y -= 2;
				if (hammer) {
					mario->setSpriteFrame("om.png");
				}
				else {
					mario->setSpriteFrame("im.png");
				}
			}

			if (key_states[LEFT_ARROW_KEY]) {
				position.x -= 2;
				lado_salto = false;
			}

			if (key_states[RIGHT_ARROW_KEY]) {
				position.x += 2;
				lado_salto = true;
			}

			auto visibleSize = Director::getInstance()->getVisibleSize();
			//if (position.x < 0) position.x = 0;
			//if (position.x > visibleSize.width) position.x = visibleSize.width;
			//if (position.y < 0) position.y = 0;
			//if (position.y > visibleSize.height) position.y = visibleSize.height;

			if (position.y < 0 || position.y > visibleSize.height) {
				muerte();
			}

		}
		mario->setPosition(position);
		}, "update_movement");

	late();

	return true;
}


void level_2::moversel() {
	mario->stopAllActions();
	if (suelo || escalera) {
		direcNormal();
	}
	else {
		direcJump();
	}

	Vector<SpriteFrame*> marin;

	if (hammer) {
		marin.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("rm.png"));
		marin.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("sm.png"));
	}
	else {
		marin.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("em.png"));
		marin.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("fm.png"));
	}
	auto left = Animation::createWithSpriteFrames(marin, 0.15f);
	auto l = Animate::create(left);
	auto le = RepeatForever::create(l);

	if (mario) {
		mario->runAction(le);
	}
}

void level_2::moverser() {
	mario->stopAllActions();
	if (suelo || escalera) {
		direcNormal();
	}
	else {
		direcJump();
	}

	Vector<SpriteFrame*> marin;
	if (hammer) {
		marin.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("tm.png"));
		marin.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("um.png"));
	}
	else {
		marin.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bm.png"));
		marin.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("cm.png"));
	}

	auto right = Animation::createWithSpriteFrames(marin, 0.15f);
	auto r = Animate::create(right);
	auto ri = RepeatForever::create(r);

	if (mario) {
		mario->runAction(ri);
	}
}

void level_2::direcJump() {

	mario->removeComponent(fisica);

	auto fisic = PhysicsBody::createBox(Size(225, 80), PhysicsMaterial(0, 0, 0));
	fisic->setPositionOffset(Vec2(-7, 0));
	fisic->setDynamic(true);
	fisic->setRotationEnable(false);
	fisic->setCategoryBitmask(0x01);
	fisic->setCollisionBitmask(0x01);
	fisic->setContactTestBitmask(0xFFFFFFFF);

	mario->addComponent(fisic);
}

void level_2::direcNormal() {

	mario->removeComponent(fisica);

	auto fisic = PhysicsBody::createBox(Size(210, 250), PhysicsMaterial(0, 0, 0));
	fisic->setPositionOffset(Vec2(-7, 8));
	fisic->setDynamic(true);
	fisic->setRotationEnable(false);
	fisic->setCategoryBitmask(0x01);
	fisic->setCollisionBitmask(0x01);
	fisic->setContactTestBitmask(0xFFFFFFFF);

	mario->addComponent(fisic);
}

void level_2::onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event) {
	if (!perder) {
		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_SPACE:
			key_states[SPACE_KEY] = true;
			break;

		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
			key_states[UP_ARROW_KEY] = true;
			break;

		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		case EventKeyboard::KeyCode::KEY_S:
			key_states[DOWN_ARROW_KEY] = true;
			break;

		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			if (!perder && !key_states[LEFT_ARROW_KEY]) {
				moversel();
				key_states[LEFT_ARROW_KEY] = true;
			}

			if (!suelo && !escalera) {
				direcJump();
			}

			break;

		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			if (!perder && !key_states[RIGHT_ARROW_KEY]) {
				moverser();
				key_states[RIGHT_ARROW_KEY] = true;
			}


			if (!suelo && !escalera) {
				direcJump();
			}
			break;
		}
	}
}

void level_2::onKeyReleased(EventKeyboard::KeyCode keyCode, Event * event) {
	if (!perder) {
		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_SPACE:
			key_states[SPACE_KEY] = false;
			break;

		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
			key_states[UP_ARROW_KEY] = false;
			break;

		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		case EventKeyboard::KeyCode::KEY_S:
			key_states[DOWN_ARROW_KEY] = false;
			break;

		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			if (!perder) {
				key_states[LEFT_ARROW_KEY] = false;

				if (!key_states[RIGHT_ARROW_KEY]) {
					mario->stopAllActions();

					if (hammer) {
						mario->setSpriteFrame("mm.png");
					}
					else {
						mario->setSpriteFrame("dm.png");
					}
				}
				else {
					moverser();
				}
			}
			break;

		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			if (!perder) {
				key_states[RIGHT_ARROW_KEY] = false;

				if (!key_states[LEFT_ARROW_KEY]) {
					mario->stopAllActions();

					if (hammer) {
						mario->setSpriteFrame("nm.png");
					}
					else {
						mario->setSpriteFrame("am.png");
					}

				}
				else {
					moversel();;
				}
			}
			break;
		}
	}
}

bool level_2::onContactBegin(PhysicsContact & contact) {
	auto bodyA = contact.getShapeA()->getBody();
	auto bodyB = contact.getShapeB()->getBody();

	// MARIO Y ESCALERAS
	if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
		for (auto s : stair_inte) {
			if (bodyA->getNode() == s || bodyB->getNode() == s) {
				auto body = mario->getPhysicsBody();
				body->setGravityEnable(false);
				touch_escalaera++;
				escalera = true;
				suelo = false;
			}
		}
	}

	// MARIO Y SUELO
	if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
		for (auto piso : pisos) {
			if (bodyA->getNode() == piso || bodyB->getNode() == piso) {
				if (!escalera) {
					suelo = true;
					if (!key_states[RIGHT_ARROW_KEY] && !key_states[LEFT_ARROW_KEY]) {
						if (lado_salto) {
							if (hammer) {
								mario->setSpriteFrame("nm.png");
							}
							else {
								mario->setSpriteFrame("am.png");
							}
						}
						else {
							if (hammer) {
								mario->setSpriteFrame("mm.png");
							}
							else {
								mario->setSpriteFrame("dm.png");
							}
						}
					}
				}
				break;
			}
		}
	}

	// BOTE Y BARRIL NORMAL
	if (bodyA->getNode() == bote || bodyB->getNode() == bote) {
		auto copia = barrixlex.begin();
		while (copia != barrixlex.end()) {
			auto barri = *copia;
			if (bodyA->getNode() == barri || bodyB->getNode() == barri) {

				barri->removeFromParentAndCleanup(true);
				copia = barrixlex.erase(copia);
			}
			else {
				copia += 1;
			}
		}
	}

	// BOTE Y BARRIL ESPECIAL
	if (bodyA->getNode() == bote || bodyB->getNode() == bote) {
		auto copia = especiales.begin();
		while (copia != especiales.end()) {
			auto barri = *copia;
			if (bodyA->getNode() == barri || bodyB->getNode() == barri) {

				barri->removeFromParentAndCleanup(true);
				copia = especiales.erase(copia);
			}
			else {
				copia += 1;
			}
		}
	}

	// MARIO Y PUNTOS
	if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
		auto copia = puntacos.begin();
		while (copia != puntacos.end()) {
			auto obj = *copia;
			if (bodyA->getNode() == obj || bodyB->getNode() == obj) {

				modificar2();

				int soundID = AudioEngine::play2d("sound_barril.mp3");
				obj->removeFromParentAndCleanup(true);
				copia = puntacos.erase(copia);
			}
			else {
				copia += 1;
			}
		}
	}

	// MARIO Y BARRIL NORMAL
	if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
		auto copia = barrixlex.begin();
		while (copia != barrixlex.end()) {
			auto barri = *copia;
			if (bodyA->getNode() == barri || bodyB->getNode() == barri) {
				auto currentVelocity = mario->getPhysicsBody()->getVelocity();
				mario->getPhysicsBody()->setVelocity(Vec2(0, 0));

				if (suelo) {
					mario->getPhysicsBody()->setGravityEnable(true);
				}

				if (hammer) {
					modificar();
					boon = barri->getPosition();
					kataplam();
					int soundID = AudioEngine::play2d("sound_barril.mp3");
					barri->removeFromParentAndCleanup(true);
					copia = barrixlex.erase(copia);
					destruir();
				}
				else {
					muerte();
					copia += 1;
				}
			}
			else {
				copia += 1;
			}
		}
	}

	// MARIO Y BARRIL ESPACIAL
	if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
		auto copia = especiales.begin();
		while (copia != especiales.end()) {
			auto barri = *copia;
			if (bodyA->getNode() == barri || bodyB->getNode() == barri) {
				auto currentVelocity = mario->getPhysicsBody()->getVelocity();
				mario->getPhysicsBody()->setVelocity(Vec2(0, 0));

				if (suelo) {
					mario->getPhysicsBody()->setGravityEnable(true);
				}

				if (hammer) {
					modificar2();
					boon = barri->getPosition();
					kataplam();
					int soundID = AudioEngine::play2d("sound_barril.mp3");
					barri->removeFromParentAndCleanup(true);
					copia = especiales.erase(copia);
					destruir();
				}
				else {
					muerte();
					copia += 1;
				}
			}
			else {
				copia += 1;
			}
		}
	}

	// MARIO Y DONKY
	if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
		if (bodyA->getNode() == k1 || bodyB->getNode() == k1) {

			muerte();

		}
	}

	// MARIO Y PEACH
	if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
		if (bodyA->getNode() == prin || bodyB->getNode() == prin) {

			siguiente();

		}
	}

	// MARIO Y B0TE
	if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
		if (bodyA->getNode() == bote || bodyB->getNode() == bote) {

			muerte();

		}
	}

	// MARIO Y HAMMER
	if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
		for (auto ha : martillos) {
			if (bodyA->getNode() == ha || bodyB->getNode() == ha) {
				int soundID = AudioEngine::play2d("sound_barril.mp3");

				if (ha) {
					ha->removeFromParentAndCleanup(true);
					ha = nullptr;
				}

				hammer = true;
				tite();
			}
		}
	}

	return true;
}

void level_2::modificar() {
	int points = Game_Data::getInstance()->getPoints();

	points += 100;

	Game_Data::getInstance()->setPoints(points);
	Game_Data::getInstance()->setTotal(points);

	label->setString(std::to_string(points));
}

void level_2::modificar2() {
	int points = Game_Data::getInstance()->getPoints();

	points += 300;

	Game_Data::getInstance()->setPoints(points);
	Game_Data::getInstance()->setTotal(points);

	label->setString(std::to_string(points));
}

void level_2::kataplam() {
	if (po) {
		po->removeFromParentAndCleanup(true);
		po = nullptr;
	}

	po = Sprite::createWithSpriteFrameName("boom2.png");
	if (po) {
		po->setPosition(boon);
		po->setScale(0.2, 0.2);
		this->addChild(po, 10);
	}

	Vector<SpriteFrame*>boo;
	boo.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("boom2.png"));
	boo.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("boom3.png"));
	boo.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("boom4.png"));
	boo.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("boom1.png"));

	auto mar = Animation::createWithSpriteFrames(boo, 0.1);
	mar->setLoops(1);
	auto kas = Animate::create(mar);

	auto borrar = CallFunc::create([&] {
		po->removeFromParentAndCleanup(true);
		po = nullptr;
		});

	auto secuencia = Sequence::create(kas, borrar, nullptr);
	po->runAction(secuencia);
}

void level_2::onContactSeparate(PhysicsContact & contact) {
	auto bodyA = contact.getShapeA()->getBody();
	auto bodyB = contact.getShapeB()->getBody();

	// MARIO Y ESCALERAS
	if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
		for (auto s : stair_inte) {
			if (bodyA->getNode() == s || bodyB->getNode() == s) {
				touch_escalaera--;
				if (touch_escalaera <= 0) {
					auto body = mario->getPhysicsBody();
					body->setGravityEnable(true);
					touch_escalaera = 0;
					escalera = false;
					if (lado_salto) {
						if (hammer) {
							mario->setSpriteFrame("qm.png");
						}
						else {
							mario->setSpriteFrame("hm.png");
						}
					}
					else {
						if (hammer) {
							mario->setSpriteFrame("pm.png");
						}
						else {
							mario->setSpriteFrame("gm.png");
						}
					}
				}
				break;
			}
		}
	}

	// MARIO Y SUELO
	if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
		for (auto piso : pisos) {
			if (bodyA->getNode() == piso || bodyB->getNode() == piso) {
				if (escalera) {
					suelo = false;
				}
				return;
			}
		}
	}

}

void level_2::destruir() {
	Vector<SpriteFrame*>ma;
	if (lado_salto) {
		ma.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("ym.png"));
		ma.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("wm.png"));
	}
	else {
		ma.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("zm.png"));
		ma.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("vm.png"));
	}

	auto mar = Animation::createWithSpriteFrames(ma, 0.1);
	mar->setLoops(1);
	auto death = Animate::create(mar);

	mario->runAction(death);
}

void level_2::actualizar_barriles(float dt) {
	float t = -900000;

	for (int i = 0; i < barrixlex.size(); i++) {
		auto barril = barrixlex.at(i);

		Vec2 vel = barril->getPhysicsBody()->getVelocity();
		if (vel.x > 0) {
			barril->getPhysicsBody()->applyTorque(t);
		}
		else if (vel.x < 0) {
			barril->getPhysicsBody()->applyTorque(-t);
		}
	}

	for (int i = 0; i < especiales.size(); i++) {
		auto barril = especiales.at(i);

		Vec2 vel = barril->getPhysicsBody()->getVelocity();
		if (vel.x > 0) {
			barril->getPhysicsBody()->applyTorque(t);
		}
		else if (vel.x < 0) {
			barril->getPhysicsBody()->applyTorque(-t);
		}
	}
}

void level_2::sin_power(float dt) {
	hammer = false;
}

void level_2::tite() {
	this->scheduleOnce(CC_SCHEDULE_SELECTOR(level_2::sin_power), 6);
}

void level_2::fall(float dt) {
	if (perder) {
		this->unschedule("cheqo");
		return;
	}

	if (suelo || escalera) {
		direcNormal();
	}
	else {
		direcJump();
	}
}

void level_2::late() {
	this->schedule([this](float deltaTime) {
		fall(deltaTime);
		}, 1, "cheqo");
}

void level_2::retraso() {
	this->scheduleOnce(CC_SCHEDULE_SELECTOR(level_2::rodando), 0);

	this->schedule([this](float deltaTime) {
		actualizar_barriles(deltaTime);
		}, 0.05f, "chequeo");
}

void level_2::rodando(float dt) {
	this->schedule(CC_SCHEDULE_SELECTOR(level_2::anadir_barril), 3);
}

void level_2::anadir_barril(float dt) {
	if (!no_more) {
		int casa = cocos2d::RandomHelper::random_int(1, 10);
		
		if (casa == 1) {
			auto pinfo = AutoPolygon::generatePolygon("super_barril.png");
			barril = Sprite::create(pinfo);
			barril->setScale(0.2);
			barril->setPosition(220, 680);
		}
		else {
			auto pinfo = AutoPolygon::generatePolygon("barril.png");
			barril = Sprite::create(pinfo);
			barril->setScale(0.2);
			barril->setPosition(220, 680);
		}

		auto fisica = PhysicsBody::createCircle(71, PhysicsMaterial(1, 0.4, 0.3));
		fisica->setDynamic(true);
		fisica->setRotationEnable(true);
		fisica->setCategoryBitmask(0x03);
		fisica->setCollisionBitmask(0x01);
		fisica->setContactTestBitmask(0xFFFFFFFF);

		barril->addComponent(fisica);
		this->addChild(barril, 7);

		Vec2 fuerza(6000000, 0);
		barril->getPhysicsBody()->applyImpulse(fuerza);
		
		if (casa == 1) {
			especiales.pushBack(barril);
		}
		else {
			barrixlex.pushBack(barril);
		}
	}
}

void level_2::muerte() {
	//DETENER TODO
	perder = true;
	mario->stopAllActions();
	mario->removeComponent(fisica);
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(mario);
	AudioEngine::stopAll();
	music_id = AudioEngine::play2d("sound_lost.mp3");

	// MARIO MUERTO
	Vector<SpriteFrame*>muerte;
	muerte.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("lm.png"));
	muerte.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("km.png"));
	muerte.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("jm.png"));

	//Ejecutar
	auto mar = Animation::createWithSpriteFrames(muerte, 0.75);
	mar->setLoops(1);
	auto death = Animate::create(mar);
	auto escala = ScaleTo::create(.25, .25);

	auto secuencia = Sequence::create(escala, death, nullptr);
	mario->runAction(secuencia);

	// CAMBIO
	auto espera = DelayTime::create(3);
	auto cambio = CallFunc::create([this]() {
		auto mySe = Manu::createScene();
		auto transition = TransitionFade::create(1.5, mySe);
		Director::getInstance()->replaceScene(transition);
		});

	this->runAction(Sequence::create(espera, cambio, nullptr));
}

void level_2::siguiente() {
	Game_Data::getInstance()->setPoints(0);
	Game_Data::getInstance()->setLevel3(true);

	// DETENER TODO
	perder = true;
	mario->stopAllActions();
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(mario);
	mario->getPhysicsBody()->setEnabled(false);
	AudioEngine::stopAll();
	music_id = AudioEngine::play2d("sound_win.mp3");

	k1->setVisible(false);
	no_more = true;

	sp = Sprite::createWithSpriteFrameName("a.png");
	if (sp) {
		sp->setPosition(270, 700);
		sp->setScale(0.5, 0.48);
		this->addChild(sp, 12);
	}

	// ANIMACION
	Vector<SpriteFrame*>subir2;
	subir2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("1b.png"));
	subir2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("1c.png"));

	auto izq2 = CallFunc::create([&, subir2]() {
		sp->setSpriteFrame(subir2.at(0));
		});
	auto der2 = CallFunc::create([&, subir2]() {
		sp->setSpriteFrame(subir2.at(1));
		});
	auto paso2 = MoveBy::create(0.25, Point(0, 21));

	auto escalar2 = Sequence::create(der2, paso2->clone(), izq2, paso2->clone(), nullptr);
	auto escala2 = Repeat::create(escalar2, 8);

	auto disappear = CallFunc::create([&] {
		prin->setVisible(false);
		});

	sp->runAction(Sequence::create(disappear, escala2, nullptr));

	// CAMBIO
	auto espera = DelayTime::create(4);
	auto cambio = CallFunc::create([this]() {
		auto mySe = level_3::createScene();
		auto transition = TransitionFade::create(1.5, mySe);
		Director::getInstance()->replaceScene(transition);
		});

	this->runAction(Sequence::create(espera, cambio, nullptr));
}


