#ifndef __GAME_DATA_H__
#define __GAME_DATA_H__

#include "cocos2d.h"

class Game_Data {
private:
    static Game_Data* instance; 
    int puntos;
    int total;
    int final;
    bool level1;
    bool level2;
    bool level3;

    Game_Data();

public:
    static Game_Data* getInstance();

    int getFinal();
    void setFinal(int a);

    int getTotal();
    void setTotal(int a);

    int getPoints();
    void setPoints(int a);

    bool getLevel1();
    void setLevel1(bool a);

    bool getLevel2();
    void setLevel2(bool a);

    bool getLevel3();
    void setLevel3(bool a);
};

#endif
