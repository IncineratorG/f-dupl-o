#ifndef STORES_H
#define STORES_H

#include "image-duplicates-finder/IDFStore.h"
#include "make-color-transparent/MakeColorTransparentStore.h"

class Stores
{
public:
    static const int ImageDuplciatedFinder = 1;
    static const int MakeColorTransparent = 2;

    Stores();

    static Stores* getInstance();

    std::shared_ptr<Store> getStore(int type) const;

private:
    static Stores* mInstance;

    std::shared_ptr<IDFStore> mIDFStore;
    std::shared_ptr<MakeColorTransparentStore> mMakeColorTransparentStore;
};

#endif // STORES_H
