#ifndef MAKECOLORTRANSPARENTSERVICE_H
#define MAKECOLORTRANSPARENTSERVICE_H

#include "common/service/Service.h"
#include "pipeline/MakeColorTransparentPipeline.h"

#include <QThread>
#include <QString>
#include <QColor>
#include <QImage>
#include <QList>

#include <functional>

class MakeColorTransparentService : public QObject, public Service
{
    Q_OBJECT

public:
    MakeColorTransparentService();

    void makeTransparent(const QString& imagePath,
                         const QColor& targetColor,
                         std::function<void(const QImage& finalImage)> callback);

signals:
    void startPipeline(const QString& imagePath, const QColor& targetColor);

private slots:
    void onPipelineFinished(const QImage& finalImage);

private:
    QThread mThread;
    QList<std::function<void(const QImage& finalImage)>> mCallbacks;
    MakeColorTransparentPipeline mPipeline;
};

#endif // MAKECOLORTRANSPARENTSERVICE_H
