#include "MakeTransparentScreenModel.h"
#include "stores/Stores.h"

#include <QDebug>

MakeTransparentScreenModel::MakeTransparentScreenModel()
    : mNoImagePathString("Click here to select image")
{
    auto stores = Stores::getInstance();

    auto makeColorTransparentStore = std::dynamic_pointer_cast<MakeColorTransparentStore>(
                stores->getStore(Stores::MakeColorTransparent));
    if (makeColorTransparentStore == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->MAKE_COLOR_TRANSPARENT_STORE_IS_NULL";
        return;
    }

    mState = std::dynamic_pointer_cast<MakeColorTransparentState>(makeColorTransparentStore->getState());
    if (mState == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->MAKE_COLOR_TRANSPARENT_STATE_IS_NULL";
        return;
    }

    std::weak_ptr<ObservableProperty<QString>> imagePathPtr = mState->imagePath;
    mImagePathSubscription = mState->imagePath->subscribe(
                std::shared_ptr<Executable>(
                    new Executable([imagePathPtr, this] () {
        auto imagePath = imagePathPtr.lock();
        if (imagePath == nullptr) {
            qDebug() << __PRETTY_FUNCTION__ << "->IMAGE_PATH_PTR_IS_NULL";
            return;
        }

        setImagePath(*imagePath->getPtr());
    })));

    std::weak_ptr<ObservableProperty<QColor>> targetColorPtr = mState->targetColor;
    mTargetColorSubscription = mState->targetColor->subscribe(
                std::shared_ptr<Executable>(
                    new Executable([targetColorPtr, this] () {
        auto targetColor = targetColorPtr.lock();
        if (targetColor == nullptr) {
            qDebug() << __PRETTY_FUNCTION__ << "->TARGET_COLOR_PTR_IS_NULL";
            return;
        }

        setTargetColor(*targetColor->getPtr());
    })));

    std::weak_ptr<ObservableProperty<bool>> busyPtr = mState->isBusy;
    mBusySubscription = mState->isBusy->subscribe(
                std::shared_ptr<Executable>(
                    new Executable([busyPtr, this] () {
        auto busy = busyPtr.lock();
        if (busy == nullptr) {
            qDebug() << __PRETTY_FUNCTION__ << "->BUSY_PTR_IS_NULL";
            return;
        }

        setBusy(*busy->getPtr());
    })));

    setImagePath(getNoImagePathString());
    setTargetColor(*mState->targetColor->getPtr());
    setPixelCoordinatesMode(false);
    setBusy(*mState->isBusy->getPtr());
}

QString MakeTransparentScreenModel::getImagePath() const {
    return mImagePath;
}

QString MakeTransparentScreenModel::getNoImagePathString() const {
    return mNoImagePathString;
}

bool MakeTransparentScreenModel::getPixelCoordinatesMode() const {
    return mPixelCoordinatesMode;
}

QColor MakeTransparentScreenModel::getTargetColor() const {
    return mTargetColor;
}

QString MakeTransparentScreenModel::getTargetColorHex() const {
    return mTargetColor.name();
}

bool MakeTransparentScreenModel::getBusy() const {
    return mBusy;
}

void MakeTransparentScreenModel::setPixelCoordinatesMode(bool value) {
    mPixelCoordinatesMode = value;
    emit pixelCoordinatesModeChanged(getPixelCoordinatesMode());
}

void MakeTransparentScreenModel::setImagePath(const QString& value) {
    mImagePath = value;
    emit imagePathChanged(mImagePath);
}

void MakeTransparentScreenModel::setTargetColor(const QColor& value) {
    mTargetColor = value;
    emit targetColorChanged(getTargetColor());
    emit targetColorHexChanged(getTargetColorHex());
}

void MakeTransparentScreenModel::setBusy(const bool value) {
    mBusy = value;
    emit busyChanged(getBusy());
}
