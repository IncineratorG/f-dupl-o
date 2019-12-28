#include "ImageDuplicatesFinderPipeline.h"

#include <QDebug>
#include <QThread>

ImageDuplicatesFinderPipeline::ImageDuplicatesFinderPipeline() {

}

void ImageDuplicatesFinderPipeline::startPipeline() {
    qDebug() << __PRETTY_FUNCTION__;

    for (int i = 0; i < 3; ++i) {
        qDebug() << __PRETTY_FUNCTION__ << i;
        QThread::sleep(1);
    }

    qDebug() << __PRETTY_FUNCTION__ << "->END";

    emit pipelineFinished();
}
