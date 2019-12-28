#include "MakeColorTransparentPipeline.h"

#include <QThread>
#include <QDebug>

MakeColorTransparentPipeline::MakeColorTransparentPipeline() {

}

void MakeColorTransparentPipeline::startPipeline(const QString& imagePath, const QColor& targetColor) {
//    qDebug() << __PRETTY_FUNCTION__ << "->IMAGE_PATH: " << imagePath;
//    qDebug() << __PRETTY_FUNCTION__ << "->TARGET_COLOR: " << targetColor.name();

//    QThread::sleep(2);

    QString imageFormat = imagePath.mid(imagePath.lastIndexOf("."));

    QImage image(imagePath);
    if (image.isNull()) {
        qDebug() << __PRETTY_FUNCTION__ << "->IMAGE_IS_NULL";
        emit pipelineFinished(QImage());
        return;
    }

    image = image.convertToFormat(QImage::Format_ARGB32);
    for (int x = 0; x < image.width(); ++x) {
        for (int y = 0; y < image.height(); ++y) {
            QPoint p(x, y);
            if (image.pixelColor(p) == targetColor) {
                image.setPixelColor(x, y, QColor(Qt::GlobalColor::transparent));
            }
        }
    }

    QString convertedImagePath = imagePath;
    convertedImagePath = convertedImagePath.insert(convertedImagePath.lastIndexOf(imageFormat), "converted");

    image.save(convertedImagePath);

    emit pipelineFinished(image);
}
