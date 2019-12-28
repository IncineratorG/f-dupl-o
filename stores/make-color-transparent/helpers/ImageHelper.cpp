#include "ImageHelper.h"

ImageHelper::ImageHelper() {

}

bool ImageHelper::isImage(const QString& imagePath) {
    if (imagePath.endsWith(".jpg", Qt::CaseInsensitive) ||
        imagePath.endsWith(".jpeg", Qt::CaseInsensitive) ||
        imagePath.endsWith(".png", Qt::CaseInsensitive))
    {
        return true;
    } else {
        return false;
    }
}
