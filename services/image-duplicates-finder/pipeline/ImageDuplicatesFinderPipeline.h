#ifndef IMAGEDUPLICATESFINDERPIPELINE_H
#define IMAGEDUPLICATESFINDERPIPELINE_H

#include <QObject>

class ImageDuplicatesFinderPipeline : public QObject
{
    Q_OBJECT

public:
    ImageDuplicatesFinderPipeline();

public slots:
    void startPipeline();

signals:
    void pipelineFinished();
};

#endif // IMAGEDUPLICATESFINDERPIPELINE_H
