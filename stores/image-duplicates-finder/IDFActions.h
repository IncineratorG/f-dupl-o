#ifndef IDFACTIONS_H
#define IDFACTIONS_H

#include "common/redux/ActionsFactory.h"

class IDFActions : public ActionsFactory
{
public:
    static const int Test = 1;
    static const int TestSetList = 2;
    static const int TestAddListItem = 3;
    static const int TestRemoveListItem = 4;

    IDFActions();

    std::shared_ptr<Action> getAction(int type) const;
};

#endif // IDFACTIONS_H
