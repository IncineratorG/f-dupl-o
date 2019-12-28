#ifndef TESTSCREENCONTROLLER_H
#define TESTSCREENCONTROLLER_H

#include "services/image-duplicates-finder/ImageDuplicatesFinderService.h"
#include "stores/image-duplicates-finder/IDFStore.h"

#include <QObject>

#include <any>

class TestScreenController : public QObject
{
    Q_OBJECT

public:
    TestScreenController();

    Q_INVOKABLE void setTestList();
    Q_INVOKABLE void addTestListItem();
    Q_INVOKABLE void removeTestListItem(const QString& id);
    Q_INVOKABLE void test();

private:
    ImageDuplicatesFinderService mService;

    std::shared_ptr<IDFStore> idfStore;
};

#endif // TESTSCREENCONTROLLER_H
