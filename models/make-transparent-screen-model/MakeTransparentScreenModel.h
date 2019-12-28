#ifndef MAKETRANSPARENTSCREENMODEL_H
#define MAKETRANSPARENTSCREENMODEL_H

#include "stores/make-color-transparent/MakeColorTransparentState.h"

#include <QObject>
#include <QString>
#include <QColor>

class MakeTransparentScreenModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString imagePath         READ getImagePath                                          NOTIFY imagePathChanged)
    Q_PROPERTY(QString noImagePathString READ getNoImagePathString                                  NOTIFY noImagePathStringChanged)
    Q_PROPERTY(bool pixelCoordinatesMode READ getPixelCoordinatesMode WRITE setPixelCoordinatesMode NOTIFY pixelCoordinatesModeChanged)
    Q_PROPERTY(QColor targetColor        READ getTargetColor                                        NOTIFY targetColorChanged)
    Q_PROPERTY(QString targetColorHex    READ getTargetColorHex                                     NOTIFY targetColorHexChanged)
    Q_PROPERTY(bool busy                 READ getBusy                                               NOTIFY busyChanged)

public:
    MakeTransparentScreenModel();

    QString getImagePath() const;
    QString getNoImagePathString() const;
    bool getPixelCoordinatesMode() const;
    QColor getTargetColor() const;
    QString getTargetColorHex() const;
    bool getBusy() const;

    void setPixelCoordinatesMode(bool value);

signals:
    void imagePathChanged(QString value);
    void noImagePathStringChanged(QString value);
    void pixelCoordinatesModeChanged(bool value);
    void targetColorChanged(QColor value);
    void targetColorHexChanged(QString value);
    void busyChanged(bool value);

private:
    QString mImagePath;
    QString mNoImagePathString;
    bool mPixelCoordinatesMode;
    QColor mTargetColor;
    bool mBusy;

    std::shared_ptr<MakeColorTransparentState> mState;
    std::shared_ptr<Subscription> mImagePathSubscription;
    std::shared_ptr<Subscription> mTargetColorSubscription;
    std::shared_ptr<Subscription> mBusySubscription;

    void setImagePath(const QString& value);
    void setTargetColor(const QColor& value);
    void setBusy(const bool value);
};

#endif // MAKETRANSPARENTSCREENMODEL_H
