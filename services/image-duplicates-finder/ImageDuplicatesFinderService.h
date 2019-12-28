#ifndef IMAGEDUPLICATESFINDERSERVICE_H
#define IMAGEDUPLICATESFINDERSERVICE_H

#include "common/service/Service.h"
#include "pipeline/ImageDuplicatesFinderPipeline.h"

#include <QThread>

class ImageDuplicatesFinderService : public QObject, public Service
{
    Q_OBJECT

public:
    ImageDuplicatesFinderService();

    void findDuplicates();

    void stop();
    void pause();

signals:
    void startPipeline();

private slots:
    void onPipelineFinished();

private:
    QThread mThread;
    ImageDuplicatesFinderPipeline mPipeline;
};

#endif // IMAGEDUPLICATESFINDERSERVICE_H
