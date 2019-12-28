#ifndef MAKECOLORTRANSAPRENTACTIONS_H
#define MAKECOLORTRANSAPRENTACTIONS_H

#include "common/redux/ActionsFactory.h"

class MakeColorTransaprentActions : public ActionsFactory
{
public:
    static const int SetImagePath = 1;
    static const int SetTargetColor = 2;
    static const int SetTargetColorTransparent = 3;
    static const int SetBusy = 4;

    MakeColorTransaprentActions();

    std::shared_ptr<Action> getAction(int type) const;
};

#endif // MAKECOLORTRANSAPRENTACTIONS_H
