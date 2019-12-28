#include "MakeColorTransparentService.h"

MakeColorTransparentService::MakeColorTransparentService() {
    connect(this, SIGNAL(startPipeline(const QString&, const QColor&)), &mPipeline, SLOT(startPipeline(const QString&, const QColor&)));
    connect(&mPipeline, SIGNAL(pipelineFinished(const QImage&)), this, SLOT(onPipelineFinished(const QImage&)));

    mPipeline.moveToThread(&mThread);
    mThread.start();
}

void MakeColorTransparentService::makeTransparent(const QString& imagePath,
                                                  const QColor& targetColor,
                                                  std::function<void(const QImage& finalImage)> callback) {
    mCallbacks.append(callback);

    emit startPipeline(imagePath, targetColor);
}

void MakeColorTransparentService::onPipelineFinished(const QImage& finalImage) {
    for (int i = 0; i < mCallbacks.size(); ++i) {
        mCallbacks.at(i)(finalImage);
    }

    mCallbacks.clear();
}
