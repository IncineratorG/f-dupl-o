#ifndef IMAGEHELPER_H
#define IMAGEHELPER_H

#include <QString>

class ImageHelper
{
public:
    ImageHelper();

    static bool isImage(const QString& imagePath);
};

#endif // IMAGEHELPER_H
