#include "MakeColorTransparentStore.h"
#include "helpers/ImageHelper.h"

#include <QDebug>
#include <QColor>
#include <QImage>

MakeColorTransparentStore::MakeColorTransparentStore()
    : mQmlFilePrefix("file:///")
{
    mState = std::make_shared<MakeColorTransparentState>();
    mActionsFactory = std::make_shared<MakeColorTransaprentActions>();
}

std::shared_ptr<State> MakeColorTransparentStore::getState() const {
    return mState;
}

std::shared_ptr<ActionsFactory> MakeColorTransparentStore::getActionsFactory() const {
    return mActionsFactory;
}

void MakeColorTransparentStore::reduce(std::shared_ptr<Action> action) {
    switch (action->getType()) {
        case MakeColorTransaprentActions::SetImagePath: {
            setImagePathReduce(action);
            break;
        }

        case MakeColorTransaprentActions::SetTargetColor: {
            setTargetColorReduce(action);
            break;
        }

        case MakeColorTransaprentActions::SetBusy: {
            setBusyReduce(action);
            break;
        }

        default: {

        }
    }
}

void MakeColorTransparentStore::effect(std::shared_ptr<Action> action) {
    switch (action->getType()) {
        case MakeColorTransaprentActions::SetTargetColorTransparent: {
            setTargetColorTransparentEffect(action);
            break;
        }

        default: {

        }
    }
}

void MakeColorTransparentStore::setImagePathReduce(std::shared_ptr<Action> action) {
    auto payload = action->getPayload();
    if (payload == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->PAYLOAD_IS_NULL";
        return;
    }

    try {
        auto imagePath = std::any_cast<std::shared_ptr<QString>>(payload->get("imagePath"));
        if (!ImageHelper::isImage(*imagePath)) {
            return;
        }
//        if (imagePath->contains(mQmlFilePrefix)) {
//            imagePath->remove(0, mQmlFilePrefix.length());
//        }

        mState->imagePath->setPtr(std::make_shared<QString>(*imagePath));
    } catch(const std::bad_any_cast& e) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_ANY_CAST";
        return;
    }
}

void MakeColorTransparentStore::setTargetColorReduce(std::shared_ptr<Action> action) {
    auto payload = action->getPayload();
    if (payload == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->PAYLOAD_IS_NULL";
        return;
    }

    try {
        auto targetColor = std::any_cast<std::shared_ptr<QColor>>(payload->get("targetColor"));

        mState->targetColor->setPtr(std::make_shared<QColor>(*targetColor));
    } catch(const std::bad_any_cast& e) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_ANY_CAST";
        return;
    }
}

void MakeColorTransparentStore::setBusyReduce(std::shared_ptr<Action> action) {
    auto payload = action->getPayload();
    if (payload == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->PAYLOAD_IS_NULL";
        return;
    }

    try {
        auto busy = std::any_cast<std::shared_ptr<bool>>(payload->get("busy"));

        mState->isBusy->setPtr(std::make_shared<bool>(*busy));
    } catch(const std::bad_any_cast& e) {
        qDebug() << __PRETTY_FUNCTION__ << "->BAD_ANY_CAST";
        return;
    }
}

//void MakeColorTransparentStore::setTargetColorTransparentReduce(std::shared_ptr<Action> action) {
//    if (mState->imagePath->getPtr()->isEmpty()) {
//        qDebug() << __PRETTY_FUNCTION__ << "->NO_IMAGE_SET";
//        return;
//    }

//    QString imagePath(*mState->imagePath->getPtr());
//    if (imagePath.contains(mQmlFilePrefix)) {
//        imagePath.remove(0, mQmlFilePrefix.length());
//    }

//    QString imageFormat = imagePath.mid(imagePath.lastIndexOf("."));
//    qDebug() << __PRETTY_FUNCTION__ << imageFormat;

//    QImage image(imagePath);
//    if (image.isNull()) {
//        qDebug() << __PRETTY_FUNCTION__ << "->IMAGE_IS_NULL";
//        return;
//    }

//    image = image.convertToFormat(QImage::Format_ARGB32);

//    QColor targetColor(*mState->targetColor->getPtr());

//    for (int x = 0; x < image.width(); ++x) {
//        for (int y = 0; y < image.height(); ++y) {
//            QPoint p(x, y);
//            if (image.pixelColor(p) == targetColor) {
//                image.setPixelColor(x, y, QColor(Qt::GlobalColor::transparent));
//            }
//        }
//    }

//    QString convertedImagePath = imagePath;
//    convertedImagePath = convertedImagePath.insert(convertedImagePath.lastIndexOf(imageFormat), "converted");

//   image.save(convertedImagePath);
//}

void MakeColorTransparentStore::setTargetColorTransparentEffect(std::shared_ptr<Action> action) {
    if (mState->imagePath->getPtr()->isEmpty()) {
        qDebug() << __PRETTY_FUNCTION__ << "->NO_IMAGE_SET";
        return;
    }

    QString imagePath(*mState->imagePath->getPtr());
    if (imagePath.contains(mQmlFilePrefix)) {
        imagePath.remove(0, mQmlFilePrefix.length());
    }

    QColor targetColor(*mState->targetColor->getPtr());

    auto payload = std::make_shared<Payload>("busy", std::make_shared<bool>(true));

    auto setBusyAction = getActionsFactory()->getAction(MakeColorTransaprentActions::SetBusy);
    setBusyAction->setPayload(payload);

    dispatch(setBusyAction);

    mService.makeTransparent(imagePath, targetColor, [this] (const QImage& finalImage) {
        auto payload = std::make_shared<Payload>("busy", std::make_shared<bool>(false));

        auto setBusyAction = getActionsFactory()->getAction(MakeColorTransaprentActions::SetBusy);
        setBusyAction->setPayload(payload);

        dispatch(setBusyAction);
    });
}
