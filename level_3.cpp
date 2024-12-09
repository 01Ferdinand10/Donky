#include "C:\Users\lferr\OneDrive\Escritorio\DMario\proj.win32\level_3.h"
#include "C:\Users\lferr\OneDrive\Escritorio\DMario\proj.win32\score.h"
#include "C:\Users\lferr\OneDrive\Escritorio\DMario\proj.win32\Manu.h"
#include "AudioEngine.h"
#include "cocos2d.h"
#include "Game_Data.h"

USING_NS_CC;


Scene* level_3::createScene() {
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_SHAPE);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -250));

	auto layer = level_3::create();
	scene->addChild(layer);

	return scene;
}

bool level_3::init() {
	if (!Scene::initWithPhysics()) return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Music
	music_id = AudioEngine::play2d("sound_stage_3.mp3", true);

	// Fondo
	auto fondo = Sprite::create("l1_fondo.png");
	fondo->setScale(visibleSize.width / fondo->getContentSize().width, visibleSize.height / fondo->getContentSize().height);
	fondo->setPosition(0, 0);
	fondo->setAnchorPoint(Vec2(0, 0));
	this->addChild(fondo, 0);

	// PISO 1
	int ini = 104;
	for (int i = 0; i < 3; i++) {
		auto s1 = Sprite::create("nfloor.png");
		s1->setPosition(ini, 40);
		s1->setScale(.265, .265);
		pisos.pushBack(s1);
		this->addChild(s1, 1);

		ini += 243;
	}

	// PISO MEDIO
	ini = 200;
	for (int i = 0; i < 3; i++) {
		auto s1 = Sprite::create("nfloor.png");
		s1->setPosition(347, ini);
		s1->setScale(.265, .265);
		pisos.pushBack(s1);
		caida.pushBack(s1);
		this->addChild(s1, 1);

		ini += 160;
	}

	// PISO LADO IZQ
	auto s1 = Sprite::create("nfloor.png");
	s1->setPosition(115, 200);
	s1->setScale(.235, .265);
	pisos.pushBack(s1);
	this->addChild(s1, 1);

	auto s2 = Sprite::create("nfloor.png");
	s2->setPosition(122, 360);
	s2->setScale(.22, .265);
	pisos.pushBack(s2);
	this->addChild(s2, 1);

	auto s3 = Sprite::create("nfloor.png");
	s3->setPosition(128, 520);
	s3->setScale(.205, .265);
	pisos.pushBack(s3);
	this->addChild(s3, 1);

	// PISO LADO DER
	auto s4 = Sprite::create("nfloor.png");
	s4->setPosition(580, 200);
	s4->setScale(.235, .265);
	pisos.pushBack(s4);
	this->addChild(s4, 1);

	auto s5 = Sprite::create("nfloor.png");
	s5->setPosition(574, 360);
	s5->setScale(.22, .265);
	pisos.pushBack(s5);
	this->addChild(s5, 1);

	auto s6 = Sprite::create("nfloor.png");
	s6->setPosition(564, 520);
	s6->setScale(.205, .265);
	pisos.pushBack(s6);
	this->addChild(s6, 1);

	// PISO Princesa
	auto s = Sprite::create("nfloor.png");
	s->setPosition(347, 680);
	s->setScale(.265, .265);
	this->addChild(s, 1);
	pisos.pushBack(s);

	// TRAMPAS
	int b = 39;
	for (int i = 0; i < 4; i++) {
		auto tr1 = Sprite::create("trampa.png");
		tr1->setPosition(226, b);
		tr1->setScale(.26, .10);
		this->addChild(tr1, 2);
		pisos.pushBack(tr1);
		desaparecer.pushBack(tr1);

		b += 160;
	}

	b = 39;
	for (int i = 0; i < 4; i++) {
		auto tr1 = Sprite::create("trampa.png");
		tr1->setPosition(470, b);
		tr1->setScale(.26, .10);
		this->addChild(tr1, 2);
		pisos.pushBack(tr1);
		desaparecer.pushBack(tr1);

		b += 160;
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

	// KONG
	k1 = Sprite::create("c.png");
	k1->setPosition(365, 570);
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
	arrojar.pushBack(SpriteFrame::create("d.png", Rect(0, 0, 400, 300)));
	arrojar.pushBack(SpriteFrame::create("e.png", Rect(0, 0, 400, 300)));
	auto arro = Animation::createWithSpriteFrames(arrojar, 0.6);
	arro->setLoops(-1);
	auto enojo = Animate::create(arro);

	// Princesa
	prin = Sprite::create("prince.png");
	prin->setPosition(310, 705);
	prin->setScale(0.35, 0.35);
	prin->setVisible(true);
	this->addChild(prin, 3);

	// New Escaleras
	auto st = Sprite::create("nstair.png");
	st->setPosition(80, 120);
	st->setScale(0.5, 0.7);
	this->addChild(st, 3);
	stair_inte.pushBack(st);

	auto stai = Sprite::create("nstair.png");
	stai->setPosition(600, 280);
	stai->setScale(0.5, 0.7);
	this->addChild(stai, 3);
	stair_inte.pushBack(stai);

	auto stair = Sprite::create("nstair.png");
	stair->setPosition(530, 440);
	stair->setScale(0.5, 0.7);
	this->addChild(stair, 3);
	stair_inte.pushBack(stair);

	auto sta = Sprite::create("nstair.png");
	sta->setPosition(150, 440);
	sta->setScale(0.5, 0.7);
	this->addChild(sta, 3);
	stair_inte.pushBack(sta);

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

	int c = 150;
	auto stepr = Sequence::create(ayu, MoveBy::create(0.8, Point(c, 0)), nullptr);
	auto stepl = Sequence::create(ayud, MoveBy::create(0.8, Point(-c, 0)), nullptr);

	auto socorro = Sequence::create(DelayTime::create(2), stepr, DelayTime::create(2), stepl, nullptr);
	prin->runAction(RepeatForever::create(socorro));
	k1->runAction(Sequence::create(enojo, nullptr));


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

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("marti.png", Rect(0, 0, 330, 360)), "marti.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("boom1.png", Rect(0, 0, 405, 353)), "boom1.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("boom2.png", Rect(0, 0, 405, 353)), "boom2.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("boom3.png", Rect(0, 0, 405, 353)), "boom3.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("boom4.png", Rect(0, 0, 405, 353)), "boom4.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("espiri.png", Rect(0, 0, 335, 353)), "espiri.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("espi.png", Rect(0, 0, 335, 353)), "espi.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("esp.png", Rect(0, 0, 335, 353)), "esp.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("es.png", Rect(0, 0, 335, 353)), "es.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("sombri.png", Rect(0, 0, 372, 351)), "sombri.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("telefo.png", Rect(0, 0, 352, 348)), "telefo.png");

	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("1i.png", Rect(0, 0, 435, 350)), "1i.png");
	SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("1j.png", Rect(0, 0, 435, 350)), "1j.png");

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
	taq->setCategoryBitmask(0x02);
	taq->setCollisionBitmask(0x01);
	taq->setContactTestBitmask(0xFFFFFFFF);
	taq->setGravityEnable(false);
	sombri->setPhysicsBody(taq);


	auto tel = Sprite::createWithSpriteFrameName("telefo.png");
	if (tel) {
		tel->setPosition(595, 370);
		tel->setScale(0.15, 0.15);
		tel->setVisible(true);
		puntacos.pushBack(tel);
		this->addChild(tel, 1);
	}

	auto tq = PhysicsBody::createBox(Size(130, 130), PhysicsMaterial(0, 0, 0));
	tq->setPositionOffset(Vec2(-12, 12));
	tq->setDynamic(false);
	tq->setRotationEnable(false);
	tq->setCategoryBitmask(0x02);
	tq->setCollisionBitmask(0x01);
	tq->setContactTestBitmask(0xFFFFFFFF);
	tq->setGravityEnable(false);
	tel->setPhysicsBody(tq);

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
	contactListener->onContactBegin = CC_CALLBACK_1(level_3::onContactBegin, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(level_3::onContactSeparate, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	// TECLAS MOVIMIENTO
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(level_3::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(level_3::onKeyReleased, this);

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
			if (position.y < 0 || position.y > visibleSize.height) {
				muerte();
			}

		}
		mario->setPosition(position);
		}, "update_movement");

	late();
	finito();

	return true;
}


	void level_3::moversel() {
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

	void level_3::moverser() {
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

	void level_3::direcJump() {

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

	void level_3::direcNormal() {

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

	void level_3::onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event) {
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

	void level_3::onKeyReleased(EventKeyboard::KeyCode keyCode, Event * event) {
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

	bool level_3::onContactBegin(PhysicsContact & contact) {
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

		// MARIO Y BARRIL
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

		// MARIO Y SUELO ESPECIAL
		if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
			auto copia = desaparecer.begin();
			while (copia != desaparecer.end()) {
				auto barri = *copia;
				if (bodyA->getNode() == barri || bodyB->getNode() == barri) {

						modificar();
						boon = barri->getPosition();
						kataplam();
						int soundID = AudioEngine::play2d("sound_barril.mp3");
						barri->removeFromParentAndCleanup(true);
						copia = desaparecer.erase(copia);
			
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

		// MARIO Y PUNTOS
		if (bodyA->getNode() == mario || bodyB->getNode() == mario) {
			auto copia = puntacos.begin();
			while (copia != puntacos.end()) {
				auto obj = *copia;
				if (bodyA->getNode() == obj || bodyB->getNode() == obj) {

					int points = Game_Data::getInstance()->getPoints();

					points += 200;
					Game_Data::getInstance()->setPoints(points);
					Game_Data::getInstance()->setTotal(points);
					label->setString(std::to_string(points));

					int soundID = AudioEngine::play2d("sound_barril.mp3");
					obj->removeFromParentAndCleanup(true);
					copia = puntacos.erase(copia);
				}
				else {
					copia += 1;
				}
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

	void level_3::modificar() {
		int points = Game_Data::getInstance()->getPoints();

		points += 100;

		Game_Data::getInstance()->setPoints(points);
		Game_Data::getInstance()->setTotal(points);

		label->setString(std::to_string(points));
	}

	void level_3::kataplam() {
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

	void level_3::onContactSeparate(PhysicsContact & contact) {
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

	void level_3::destruir() {
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

	void level_3::sin_power(float dt) {
		hammer = false;
	}

	void level_3::tite() {
		this->scheduleOnce(CC_SCHEDULE_SELECTOR(level_3::sin_power), 8);
	}

	void level_3::fall(float dt) {
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

	void level_3::late() {
		this->schedule([this](float deltaTime) {
			fall(deltaTime);
			}, 1, "cheqo");
	}

	void level_3::retraso() {
		this->scheduleOnce(CC_SCHEDULE_SELECTOR(level_3::rodando), 0);

		this->schedule([this](float deltaTime) {
			actualizar_barriles(deltaTime);
			}, 0.1f, "chequeo");
	}

	void level_3::rodando(float dt) {
		this->schedule(CC_SCHEDULE_SELECTOR(level_3::anadir_barril), 3.5);
	}

	void level_3::actualizar_barriles(float dt) {

		for (int i = barrixlex.size() - 1; i >= 0; i--) {
			auto barril = barrixlex.at(i);

			auto visibleSize = Director::getInstance()->getVisibleSize();
			cocos2d::Vec2 boon = barril->getPosition();

			if (boon.x < 0 || boon.x > visibleSize.width || boon.y < 0 || boon.y > visibleSize.height) {
				barril->removeFromParentAndCleanup(true);
				barrixlex.erase(i);
			}
		}
	}

	void level_3::anadir_barril(float dt) {
		if (!no_more) {
			auto pinfo = AutoPolygon::generatePolygon("es.png");
			barril = Sprite::create(pinfo);
			barril->setScale(0.2);

			std::vector<int> lugares = {80, 240, 400};
			int indi = cocos2d::RandomHelper::random_int(0, static_cast<int>(lugares.size() - 1));
			int posy = lugares[indi];
			int posx = cocos2d::RandomHelper::random_int(10, 700);
			barril->setPosition(posx, posy);

			auto fisica = PhysicsBody::createBox(Size(130, 145), PhysicsMaterial(0, 0, 0));
			fisica->setPositionOffset(Vec2(-6, -6));
			fisica->setDynamic(false);
			fisica->setGravityEnable(false);
			fisica->setRotationEnable(false);
			fisica->setCategoryBitmask(0x03);
			fisica->setCollisionBitmask(0x01);
			fisica->setContactTestBitmask(0xFFFFFFFF);
			
			Vector<SpriteFrame*>lado;
			
			int direccion = cocos2d::RandomHelper::random_int(1, 2);
			int val = 0;
			if (direccion == 1) {
				val = -20;
				lado.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("es.png"));
				lado.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("esp.png"));
			}
			else {
				val = 20;
				lado.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("espi.png"));
				lado.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("espiri.png"));
			}

			auto marx = Animation::createWithSpriteFrames(lado, 0.25);
			marx->setLoops(-1);
			auto rugi = Animate::create(marx);
			

			auto salto = JumpBy::create(1, Vec2(val, 0), 20, 1);
			auto secuencia = RepeatForever::create(salto);

			barril->runAction(rugi);
			barril->runAction(secuencia);
			

			barril->addComponent(fisica);
			this->addChild(barril, 7);

			barrixlex.pushBack(barril);
		}
	}

	void level_3::muerte() {
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

	void level_3::siguiente() {
		Game_Data::getInstance()->setPoints(0);

		// DETENER TODO
		perder = true;
		mario->setVisible(false);
		prin->setVisible(false);
		mario->stopAllActions();
		Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(mario);
		mario->getPhysicsBody()->setEnabled(false);
		AudioEngine::stopAll();
		music_id = AudioEngine::play2d("sound_win.mp3");

		auto kone = CallFunc::create([&]() {
			k1->setVisible(false);
			sp->setVisible(true);
			});

		no_more = true;

		sp = Sprite::createWithSpriteFrameName("1i.png");
		if (sp) {
			sp->setPosition(300, 550);
			sp->setScale(0.5, 0.48);
			sp->setRotation(180);
			sp->setVisible(false);
			this->addChild(sp, 12);
		}

		for (auto p : caida) {
			p->setOpacity(0);
		}

		for (auto a : barrixlex) {
			a->setOpacity(0);
		}

		// ANIMACION
		Vector<SpriteFrame*>subir2;
		subir2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("1i.png"));
		subir2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("1j.png"));

		auto izq2 = CallFunc::create([&, subir2]() {
			sp->setSpriteFrame(subir2.at(0));
			});
		auto der2 = CallFunc::create([&, subir2]() {
			sp->setSpriteFrame(subir2.at(1));
			});
		auto paso2 = MoveBy::create(0.2, Point(0, -18.65));

		auto escalar2 = Sequence::create(der2, paso2->clone(), izq2, paso2->clone(), nullptr);
		auto caida = Repeat::create(escalar2, 11);

		sp->runAction(Sequence::create(DelayTime::create(3), kone, caida, nullptr));

		// CAMBIO
		auto cambio = CallFunc::create([this]() {
			auto mySe = score::createScene();
			auto transition = TransitionFade::create(1.5, mySe);
			Director::getInstance()->replaceScene(transition);
			});

		this->runAction(Sequence::create(DelayTime::create(10), cambio, nullptr));
	}

	void level_3::finito() {
			this->schedule([this](float deltaTime) {
				sad(deltaTime);
				}, 4, "co");
		}

	void level_3::sad(float dt) {
		if (no_more) {
			this->unschedule("co");
			return;
		}

		if (desaparecer.empty()) {
			siguiente();
		}
	}