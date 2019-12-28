#ifndef MAKECOLORTRANSPARENTSTATE_H
#define MAKECOLORTRANSPARENTSTATE_H

#include "common/redux/State.h"
#include "common/reactive/ObservableProperty.h"

#include <QColor>

class MakeColorTransparentState : public State
{
public:
    std::shared_ptr<ObservableProperty<QString>> imagePath;
    std::shared_ptr<ObservableProperty<QColor>> targetColor;
    std::shared_ptr<ObservableProperty<bool>> isBusy;

    MakeColorTransparentState();
};

#endif // MAKECOLORTRANSPARENTSTATE_H
