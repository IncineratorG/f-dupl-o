#include "TestScreenListModel.h"
#include "stores/Stores.h"

TestScreenListModel::TestScreenListModel() {
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

    std::weak_ptr<ObservableProperty<QList<QString>>> listPtr = idfState->mList;
    idfState->mList->subscribe(
                std::shared_ptr<Executable>(
                    new Executable([listPtr, this] () {
        qDebug() << __PRETTY_FUNCTION__ << "->LIST_CHANGED";

        auto list = listPtr.lock();
        if (list == nullptr) {
            qDebug() << __PRETTY_FUNCTION__ << "->LIST_IS_NULL";
            return;
        }

        beginResetModel();
        mModelData.clear();
        for (int i = 0; i < list->getPtr()->size(); ++i) {
            qDebug() << __PRETTY_FUNCTION__ << "->VALUE: " << list->getPtr()->at(i);

            mModelData.append(list->getPtr()->at(i));
        }
        endResetModel();
    })));



//    for (int i = 0; i < 10; ++i) {
//        mModelData.append(QString::number(i));
//    }
}

int TestScreenListModel::rowCount(const QModelIndex& parent) const {
    return mModelData.size();
}

QVariant TestScreenListModel::data(const QModelIndex& index, int role) const {
    if (index.row() < 0 || index.row() >= mModelData.size()) {
        return QVariant();
    }

    switch (role) {
        case Id: {
            return mModelData.at(index.row());
        }

        case ItemName: {
            return mModelData.at(index.row());
        }
    }

    return QVariant();
}

QHash<int, QByteArray> TestScreenListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[Id] = "id";
    roles[ItemName] = "itemName";

    return roles;
}
