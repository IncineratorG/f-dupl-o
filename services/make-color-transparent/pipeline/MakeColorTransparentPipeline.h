#ifndef MAKECOLORTRANSPARENTPIPELINE_H
#define MAKECOLORTRANSPARENTPIPELINE_H

#include <QObject>
#include <QString>
#include <QColor>
#include <QImage>

class MakeColorTransparentPipeline : public QObject
{
    Q_OBJECT

public:
    MakeColorTransparentPipeline();

public slots:
    void startPipeline(const QString& imagePath, const QColor& targetColor);

signals:
    void pipelineFinished(const QImage& finalImage);
};

#endif // MAKECOLORTRANSPARENTPIPELINE_H
