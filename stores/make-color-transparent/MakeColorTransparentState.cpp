#include "MakeColorTransparentState.h"

MakeColorTransparentState::MakeColorTransparentState() {
    imagePath = std::make_shared<ObservableProperty<QString>>(std::make_shared<QString>(""));
    targetColor = std::make_shared<ObservableProperty<QColor>>(std::make_shared<QColor>(255, 255, 255, 255));
    isBusy = std::make_shared<ObservableProperty<bool>>(std::make_shared<bool>(false));
}
