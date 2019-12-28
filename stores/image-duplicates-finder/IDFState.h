#ifndef IDFSTATE_H
#define IDFSTATE_H

#include "common/redux/State.h"
#include "common/reactive/ObservableProperty.h"

#include <QString>
#include <QList>

class IDFState : public State
{
public:
    std::shared_ptr<ObservableProperty<QString>> mTestStatus;
    std::shared_ptr<ObservableProperty<QList<QString>>> mList;

    IDFState();
};

#endif // IDFSTATE_H
