#ifndef MAKETRANSPARENTSCREENCONTROLLER_H
#define MAKETRANSPARENTSCREENCONTROLLER_H

#include "stores/make-color-transparent/MakeColorTransparentStore.h"

#include <QObject>
#include <QString>

class MakeTransparentScreenController : public QObject
{
    Q_OBJECT

public:
    MakeTransparentScreenController();

    Q_INVOKABLE void setImagePath(const QString& path);
    Q_INVOKABLE void changeWhiteToTransparent();
    Q_INVOKABLE void setTargetColor(const int r, const int g, const int b, const int a);
    Q_INVOKABLE void setTargetColorTransparent();

private:
    std::shared_ptr<MakeColorTransparentStore> mStore;
};

#endif // MAKETRANSPARENTSCREENCONTROLLER_H
