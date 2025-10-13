#ifndef DEFENDER3_H
#define DEFENDER3_H
#include "Defender.h"

class Defender3 : public Defender {
    public:
        Defender3();
    
    virtual ~Defender3() = default;

    void update() override;

};
#endif