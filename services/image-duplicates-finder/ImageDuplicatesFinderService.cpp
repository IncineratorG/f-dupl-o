#include "ImageDuplicatesFinderService.h"

#include <QDebug>

ImageDuplicatesFinderService::ImageDuplicatesFinderService() {
    connect(this, SIGNAL(startPipeline()), &mPipeline, SLOT(startPipeline()));
    connect(&mPipeline, SIGNAL(pipelineFinished()), this, SLOT(onPipelineFinished()));

    mPipeline.moveToThread(&mThread);
    mThread.start();
}

void ImageDuplicatesFinderService::findDuplicates() {
    qDebug() << __PRETTY_FUNCTION__;
    emit startPipeline();
}

void ImageDuplicatesFinderService::stop() {
    qDebug() << __PRETTY_FUNCTION__;
}

void ImageDuplicatesFinderService::pause() {
    qDebug() << __PRETTY_FUNCTION__;
}

void ImageDuplicatesFinderService::onPipelineFinished() {
    qDebug() << __PRETTY_FUNCTION__;
}
