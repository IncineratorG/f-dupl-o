#include "Stores.h"

#include <QDebug>

Stores* Stores::mInstance = nullptr;

Stores::Stores() {
    mIDFStore = std::make_shared<IDFStore>();
    mMakeColorTransparentStore = std::make_shared<MakeColorTransparentStore>();
}

Stores* Stores::getInstance() {
    if (!mInstance) {
        mInstance = new Stores();
    }

    return mInstance;
}

std::shared_ptr<Store> Stores::getStore(int type) const {
    switch (type) {
        case ImageDuplciatedFinder: {
            return mIDFStore;
        }

        case MakeColorTransparent: {
            return mMakeColorTransparentStore;
        }
    }

    qDebug() << __PRETTY_FUNCTION__ << "->UNKNOWN_STORE_TYPE: " << type;

    return nullptr;
}
