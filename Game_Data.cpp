#include "Game_Data.h"

Game_Data* Game_Data::instance = nullptr;
Game_Data::Game_Data() : puntos(0), total(0), final(0), level1(false), level2(false), level3(false) {}

Game_Data* Game_Data::getInstance() {
    if (instance == nullptr) {
        instance = new Game_Data();
    }
    return instance;
}


int Game_Data::getFinal() {
    return final;
}

void Game_Data::setFinal(int a) {
    final = a;
}


int Game_Data::getTotal() {
    return total;
}

void Game_Data::setTotal(int a) {
    total = a;
}


int Game_Data::getPoints() {
    return puntos;
}

void Game_Data::setPoints(int a) {
    puntos = a;
}



bool Game_Data::getLevel1() {
    return level1;
}

void Game_Data::setLevel1(bool a) {
    level1 = a;
}



bool Game_Data::getLevel2() {
    return level2;
}

void Game_Data::setLevel2(bool a) {
    level2 = a;
}



bool Game_Data::getLevel3() {
    return level3;
}

void Game_Data::setLevel3(bool a) {
    level3 = a;
}