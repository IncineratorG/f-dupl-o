#include "TestScreenController.h"
#include "common/reactive/Observable.h"
#include "common/reactive/ObservableProperty.h"
#include "stores/Stores.h"

#include <QDebug>
#include <QString>
#include <QList>
#include <QMap>

TestScreenController::TestScreenController() {
    auto stores = Stores::getInstance();
    idfStore = std::dynamic_pointer_cast<IDFStore>(
                stores->getStore(Stores::ImageDuplciatedFinder));
    if (idfStore == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->IDF_STORE_PTR_IS_NULL";
        return;
    }
}

void TestScreenController::setTestList() {
    qDebug() << __PRETTY_FUNCTION__;

    auto setInitialListAction = idfStore->getActionsFactory()->getAction(IDFActions::TestSetList);

    idfStore->dispatch(setInitialListAction);
}

void TestScreenController::addTestListItem() {
    qDebug() << __PRETTY_FUNCTION__;

    auto newListItem = std::make_shared<QString>("New Item");

    auto payload = std::make_shared<Payload>("newItem", newListItem);

    auto addListItemAction = idfStore->getActionsFactory()->getAction(IDFActions::TestAddListItem);
    addListItemAction->setPayload(payload);

    idfStore->dispatch(addListItemAction);
}

void TestScreenController::removeTestListItem(const QString& id) {
    qDebug() << __PRETTY_FUNCTION__ << "->ID: " << id;

    auto listItemId = std::make_shared<QString>(id);

    auto payload = std::make_shared<Payload>("itemId", listItemId);

    auto removeListItemAction = idfStore->getActionsFactory()->getAction(IDFActions::TestRemoveListItem);
    removeListItemAction->setPayload(payload);

    idfStore->dispatch(removeListItemAction);
}

void TestScreenController::test() {
    qDebug() << __PRETTY_FUNCTION__;

    auto stores = Stores::getInstance();

    auto idfStore = std::dynamic_pointer_cast<IDFStore>(
                stores->getStore(Stores::ImageDuplciatedFinder));
    if (idfStore == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->IDF_STORE_PTR_IS_NULL";
        return;
    }

    auto idfState = std::dynamic_pointer_cast<IDFState>(idfStore->getState());
    if (idfState == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->IDF_STATE_PTR_IS_NULL";
        return;
    }

    auto initialStringList = std::make_shared<QList<QString>>();
    for (int i = 0; i < 3; ++i) {
        initialStringList->append("String: " + QString::number(i));
    }

    auto payload = std::make_shared<Payload>("stringList", initialStringList);

    auto setTestListAction = idfStore->getActionsFactory()->getAction(IDFActions::TestSetList);
    setTestListAction->setPayload(payload);

    idfStore->dispatch(setTestListAction);



//    auto payload = std::make_shared<Payload>("string", std::make_shared<QString>("PAYLOAD_STRING"));

//    auto testAction = idfStore->getActionsFactory()->getAction(IDFActions::Test);
//    testAction->setPayload(payload);

//    idfStore->dispatch(testAction);

    qDebug() << __PRETTY_FUNCTION__ << "->END";
}

//void TestScreenController::test() {
//    qDebug() << __PRETTY_FUNCTION__;

//    std::any n;
//    qDebug() << __PRETTY_FUNCTION__ << n.has_value();


////    auto string = std::make_any<QString>("ANY_STRING");


////    try {
////        qDebug() << __PRETTY_FUNCTION__ << std::any_cast<QString>(string);
////    } catch(const std::bad_any_cast& e) {
////        qDebug() << __PRETTY_FUNCTION__ << "->EXCEPTION: " << e.what();
////    }



////    std::any first = returnFunction(0);
////    try {
////        auto string = std::any_cast<std::shared_ptr<QString>>(first);
////        qDebug() << __PRETTY_FUNCTION__ << *string;

//////        auto list = std::any_cast<std::shared_ptr<QList<int>>>(first);
//////        for (int i = 0; i < list->length(); ++i) {
//////            qDebug() << __PRETTY_FUNCTION__ << list->at(i);
//////        }
////    } catch(const std::bad_any_cast& e) {
////        qDebug() << __PRETTY_FUNCTION__ << "->EXCEPTION: " << e.what();
////    }


//    qDebug() << __PRETTY_FUNCTION__ << "->END";
//}

//void TestScreenController::test() {
//    qDebug() << __PRETTY_FUNCTION__;

//    auto stores = Stores::getInstance();

//    auto idfStore = std::dynamic_pointer_cast<IDFStore>(
//                stores->getStore(Stores::ImageDuplciatedFinderStore));
//    if (idfStore == nullptr) {
//        qDebug() << __PRETTY_FUNCTION__ << "->IDF_STORE_PTR_IS_NULL";
//        return;
//    }

//    auto idfState = std::dynamic_pointer_cast<IDFState>(idfStore->getState());
//    if (idfState == nullptr) {
//        qDebug() << __PRETTY_FUNCTION__ << "->IDF_STATE_PTR_IS_NULL";
//        return;
//    }

//    auto subscription = idfState->mTestStatus->subscribe(
//                std::shared_ptr<Executable>(
//                    new Executable([testStatusPtr = std::weak_ptr<ObservableProperty<QString>>(idfState->mTestStatus)] () {
//        if (testStatusPtr.lock() == nullptr) {
//            qDebug() << __PRETTY_FUNCTION__ << "->TEST_STATUS_PTR_IS_NULL";
//        } else {
//            qDebug() << __PRETTY_FUNCTION__ << "->TEST_STATUS: " << *testStatusPtr.lock()->getPtr();
//        }
//    })));

//    auto payload = std::make_shared<Payload>("string", std::make_shared<QString>("PAYLOAD_STRING"));

//    auto testAction = idfStore->getActionsFactory()->getAction(IDFActions::Test);
//    testAction->setPayload(payload);

//    idfStore->dispatch(testAction);

//    idfState->mTestStatus->unsubscribe(subscription);

//    qDebug() << __PRETTY_FUNCTION__ << "->END";
//}

//void TestScreenController::test() {
//    qDebug() << __PRETTY_FUNCTION__;

////    ImageDuplicatesFinderService service;
//    mService.findDuplicates();

//    qDebug() << __PRETTY_FUNCTION__ << "->END";
//}

//void TestScreenController::test() {
//    qDebug() << __PRETTY_FUNCTION__;

//    auto stores = Stores::getInstance();

//    auto idfStore = std::dynamic_pointer_cast<IDFStore>(
//                stores->getStore(Stores::ImageDuplciatedFinderStore));

////        qDebug() << __PRETTY_FUNCTION__ << "->IDF_STORE_IS_NULL: " << (idfStore == nullptr);

//    auto testAction = idfStore->getActionsFactory()->getAction(IDFActions::Test);

////        qDebug() << __PRETTY_FUNCTION__ << "->TEST_ACTION_IS_NULL: " << (testAction == nullptr);

//    idfStore->dispatch(testAction);

//    qDebug() << __PRETTY_FUNCTION__ << "->END";
//}




//void TestScreenController::test() {
//    qDebug() << __PRETTY_FUNCTION__;


//    std::shared_ptr<ObservableProperty<int>> op(new ObservableProperty<int>());

//    auto subscription_1 = op->subscribe(std::shared_ptr<Executable>(new Executable([weakObj = std::weak_ptr<ObservableProperty<int>>(op)] () {
//        if (weakObj.lock() == nullptr) {
//            qDebug() << __PRETTY_FUNCTION__ << "WEAK_OBJ_IS_NULL";
//        } else {
//            qDebug() << "CHANGED_1" << *weakObj.lock()->getPtr();
//        }
//    })));
//    auto subscription_2 = op->subscribe(std::shared_ptr<Executable>(new Executable([weakObj = std::weak_ptr<ObservableProperty<int>>(op)] () {
//        qDebug() << "CHANGED_2" << *weakObj.lock()->getPtr();
//    })));

//    op->setPtr(std::make_shared<int>(3));
//    op->unsubscribe(subscription_1);
//    op->setPtr(std::make_shared<int>(4));
//    op->unsubscribe(subscription_1);




////    for (int i = 0; i < 100000; ++i) {
////        std::shared_ptr<ObservableProperty<int>> op(new ObservableProperty<int>());

////        auto subscription_1 = op->subscribe(std::shared_ptr<Executable>(new Executable([weakObj = std::weak_ptr<ObservableProperty<int>>(op)] () {
//////            qDebug() << "CHANGED_1" << *op->getPtr();
////        })));
//////        auto subscription_2 = op->subscribe(std::shared_ptr<Executable>(new Executable([op] () {
////////            qDebug() << "CHANGED_1" << *op->getPtr();
//////        })));

//////        op->setPtr(std::make_shared<int>(3));
//////        op->unsubscribe(subscription_1);
//////        op->setPtr(std::make_shared<int>(4));
//////        op->unsubscribe(subscription_1);
////    }


////    for (int i = 0; i < 10000; ++i) {
////        QList<QString>* list = new QList<QString>();
////        for (int j = 0; j < 100; ++j) {
////            list->append("aksjflkasjdf;kajsdfkjas;dgljskj");
////        }
////    }




////    std::shared_ptr<ObservableProperty<int>> op;
////    auto subscription_1 = op->subscribe(std::shared_ptr<Executable>(new Executable([] () {
////        qDebug() << "CHANGED_1";
////    })));
////    auto subscription_2 = op->subscribe(std::shared_ptr<Executable>(new Executable([] () {
////        qDebug() << "CHANGED_1";
////    })));
////    auto subscription_3 = op->subscribe(std::shared_ptr<Executable>(new Executable([] () {
////        qDebug() << "CHANGED_1";
////    })));



////    Observable* o = new Observable();
////    std::shared_ptr<Observable> sp(o);

////    auto subscription_1 = o->subscribe(std::shared_ptr<Executable>(new Executable([] () {
////        qDebug() << "CHANGED_1";
////    })));
////    auto subscription_2 = o->subscribe(std::shared_ptr<Executable>(new Executable([] () {
////        qDebug() << "CHANGED_1";
////    })));
////    auto subscription_3 = o->subscribe(std::shared_ptr<Executable>(new Executable([] () {
////        qDebug() << "CHANGED_1";
////    })));

////    o->unsubscribe(subscription_1);
////    o->unsubscribe(subscription_1);
////    o->unsubscribe(subscription_1);

////    delete o;


////    std::shared_ptr<Observable> o;
////    o->subscribe(std::shared_ptr<Executable>(new Executable([] () {
////        qDebug() << "CHANGED_1";
////    })));


////    Observable o;
////    o.subscribe(std::shared_ptr<Executable>(new Executable([] () {
////        qDebug() << "CHANGED_1";
////    })));
////    o.subscribe(std::shared_ptr<Executable>(new Executable([] () {
////        qDebug() << "CHANGED_1";
////    })));







////    ObservableProperty<int> op;

////    auto subscription_1 = op.subscribe(std::shared_ptr<Executable>(new Executable([op] () {
////        qDebug() << "CHANGED_1" << op.get();
////    })));
////    auto subscription_2 = op.subscribe(std::shared_ptr<Executable>(new Executable([op] () {
////        qDebug() << "CHANGED_2" << op.get();
////    })));
////    auto subscription_3 = op.subscribe(std::shared_ptr<Executable>(new Executable([op] () {
////        qDebug() << "CHANGED_3" << op.get();
////    })));

////    op.set(2);
////    qDebug() << "";

////    op.unsubscribe(subscription_1);
////    op->unsibscribe(subscription_2);

////    op.set(3);
////    qDebug() << "";

////    op->unsibscribe(subscription_2);

////    op.set(4);
////    qDebug() << "";

////    op.unsibscribe(subscription_1);



////    ObservableProperty<int>* op = new ObservableProperty<int>();

////    auto subscription_1 = op->subscribe(std::shared_ptr<Executable>(new Executable([op] () {
////        qDebug() << "CHANGED_1" << op->get();
////    })));
////    auto subscription_2 = op->subscribe(std::shared_ptr<Executable>(new Executable([op] () {
////        qDebug() << "CHANGED_2" << op->get();
////    })));
////    auto subscription_3 = op->subscribe(std::shared_ptr<Executable>(new Executable([op] () {
////        qDebug() << "CHANGED_3" << op->get();
////    })));

////    op->set(2);
////    qDebug() << "";

////    op->unsibscribe(subscription_1);
//////    op->unsibscribe(subscription_2);

////    op->set(3);
////    qDebug() << "";

//////    op->unsibscribe(subscription_2);

////    op->set(4);
////    qDebug() << "";

////    op->unsibscribe(subscription_1);


//    qDebug() << __PRETTY_FUNCTION__ << "END";
//}
