#include "MakeTransparentScreenController.h"
#include "stores/Stores.h"

#include <QDebug>
#include <QImage>

MakeTransparentScreenController::MakeTransparentScreenController() {
    auto stores = Stores::getInstance();

    mStore = std::dynamic_pointer_cast<MakeColorTransparentStore>(
                stores->getStore(Stores::MakeColorTransparent));
    if (mStore == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->MAKE_COLOR_TRANSPARENT_STORE_IS_NULL";
        return;
    }
}

void MakeTransparentScreenController::setImagePath(const QString& path) {
    auto payload = std::make_shared<Payload>("imagePath", std::make_shared<QString>(path));

    auto setImagePathAction = mStore->getActionsFactory()->getAction(MakeColorTransaprentActions::SetImagePath);
    setImagePathAction->setPayload(payload);

    mStore->dispatch(setImagePathAction);
}

void MakeTransparentScreenController::changeWhiteToTransparent() {
    qDebug() << __PRETTY_FUNCTION__;

    QImage image("C:/Users/Alexander/Pictures/cart2.png");
    image = image.convertToFormat(QImage::Format_ARGB32);

    for (int x = 0; x < image.width(); ++x) {
        for (int y = 0; y < image.height(); ++y) {
            QPoint p(x, y);
            if (image.pixelColor(p) == QColor("white")) {
                image.setPixelColor(x, y, QColor(Qt::GlobalColor::transparent));
            }
        }
    }

    image.save("C:/Users/Alexander/Pictures/cart22.png");
}

void MakeTransparentScreenController::setTargetColor(const int r, const int g, const int b, const int a) {
    auto payload = std::make_shared<Payload>("targetColor", std::make_shared<QColor>(r, g, b, a));

    auto setTargetColorAction = mStore->getActionsFactory()->getAction(MakeColorTransaprentActions::SetTargetColor);
    setTargetColorAction->setPayload(payload);

    mStore->dispatch(setTargetColorAction);
}

void MakeTransparentScreenController::setTargetColorTransparent() {
    auto setTargetColorTransparentAction = mStore->getActionsFactory()->getAction(MakeColorTransaprentActions::SetTargetColorTransparent);

    mStore->dispatch(setTargetColorTransparentAction);
}
