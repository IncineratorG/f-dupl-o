#ifndef TESTSCREENLISTMODEL_H
#define TESTSCREENLISTMODEL_H

#include "stores/image-duplicates-finder/IDFState.h"

#include <QAbstractListModel>
#include <QString>

class TestScreenListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum TestScreenListModelRoles {
        Id = Qt::UserRole + 1,
        ItemName
    };

    TestScreenListModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

private:
    QList<QString> mModelData;

    std::shared_ptr<IDFState> mState;
};

#endif // TESTSCREENLISTMODEL_H
