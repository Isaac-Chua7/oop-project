#ifndef DEFENDER2_H
#define DEFENDER2_H
#include "Defender.h"

using namespace std;

class Defender2 : public Defender {
    private:
        int income;
    public:
        Defender2();

    virtual ~Defender2() = default;

    void update() override;

    void increaseMoney(); //Increases money for player each round.

};
#endif