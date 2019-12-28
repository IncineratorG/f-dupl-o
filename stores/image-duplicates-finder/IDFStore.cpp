#include "IDFStore.h"

#include <QDebug>

IDFStore::IDFStore() {
    mIdfState = std::make_shared<IDFState>();
    mIdfActionsFactory = std::make_shared<IDFActions>();
}

std::shared_ptr<State> IDFStore::getState() const {
    return mIdfState;
}

std::shared_ptr<ActionsFactory> IDFStore::getActionsFactory() const {
    return mIdfActionsFactory;
}

void IDFStore::reduce(std::shared_ptr<Action> action) {
//    qDebug() << __PRETTY_FUNCTION__ << "->ACTION_TYPE: " << action->getType();

    switch (action->getType()) {
        case IDFActions::TestSetList: {
            auto initialStringList = std::make_shared<QList<QString>>();
            for (int i = 0; i < 7; ++i) {
                initialStringList->append("String: " + QString::number(i + 1));
            }

            mIdfState->mList->setPtr(initialStringList);

            break;
        }

    case IDFActions::TestAddListItem: {
        auto payload = action->getPayload();
        if (payload == nullptr) {
            qDebug() << __PRETTY_FUNCTION__ << "->TEST_ADD_LIST_ITEM->PAYLOAD_IS_NULL";
            break;
        }

        try {
            auto newListItem = std::any_cast<std::shared_ptr<QString>>(payload->get("newItem"));

            auto oldList = mIdfState->mList->getPtr();

            auto newList = std::make_shared<QList<QString>>(*oldList);
            newList->append(*newListItem);

            mIdfState->mList->setPtr(newList);
        } catch(const std::bad_any_cast& e) {
            qDebug() << __PRETTY_FUNCTION__ << "->TEST_ADD_LIST_ITEM->BAD_ANY_CAST";
            break;
        }

        break;
    }

    case IDFActions::TestRemoveListItem: {
        auto payload = action->getPayload();
        if (payload == nullptr) {
            qDebug() << __PRETTY_FUNCTION__ << "->TEST_REMOVE_LIST_ITEM->PAYLOAD_IS_NULL";
            break;
        }

        try {
            auto itemToRemoveId = std::any_cast<std::shared_ptr<QString>>(payload->get("itemId"));

            auto oldList = mIdfState->mList->getPtr();
            auto newList = std::make_shared<QList<QString>>();
            for (int i = 0; i < oldList->size(); ++i) {
                if (oldList->at(i) == *itemToRemoveId) {
                    continue;
                }

                newList->append(oldList->at(i));
            }

            mIdfState->mList->setPtr(newList);
        } catch(const std::bad_any_cast& e) {
            qDebug() << __PRETTY_FUNCTION__ << "->TEST_REMOVE_LIST_ITEM->BAD_ANY_CAST";
            break;
        }

        break;
    }


//        case IDFActions::TestSetList: {
//            auto payload = action->getPayload();
//            if (payload == nullptr) {
//                qDebug() << __PRETTY_FUNCTION__ << "->TEST_SET_LIST->PAYLOAD_IS_NULL";
//                break;
//            }

//            try {
//                auto stringList = std::any_cast<std::shared_ptr<QList<QString>>>(payload->get("stringList"));

//                mIdfState->mList->setPtr(stringList);
//            } catch(const std::bad_any_cast& e) {
//                qDebug() << __PRETTY_FUNCTION__ << "->TEST_SET_LIST->BAD_ANY_CAST";
//                break;
//            }

//            break;
//        }


//        case IDFActions::Test: {
//            auto payload = action->getPayload();
//            if (payload == nullptr) {
//                qDebug() << __PRETTY_FUNCTION__ << "->PAYLOAD_IS_NULL";
//                break;
//            }

//            try {
//                auto string = std::any_cast<std::shared_ptr<QString>>(payload->get("string"));

//                auto stringList = std::make_shared<QList<QString>>(*mIdfState->mList->getPtr());
//                stringList->append(*string);

//                mIdfState->mList->setPtr(stringList);
//            } catch(const std::bad_any_cast& e) {
//                qDebug() << __PRETTY_FUNCTION__ << "->BAD_ANY_CAST";
//                break;
//            }

//            break;
//        }

//        case IDFActions::Test: {
//            auto payload = action->getPayload();
//            if (payload == nullptr) {
//                qDebug() << __PRETTY_FUNCTION__ << "->PAYLOAD_IS_NULL";
//                break;
//            }

//            try {
//                auto string = std::any_cast<std::shared_ptr<QString>>(payload->get("string"));

//                auto oldTestString = *mIdfState->mTestStatus->getPtr();
//                auto newTestString = std::make_shared<QString>(oldTestString + "n" + *string);

//                mIdfState->mTestStatus->setPtr(newTestString);
//            } catch(const std::bad_any_cast& e) {
//                qDebug() << __PRETTY_FUNCTION__ << "->BAD_ANY_CAST";
//                break;
//            }

//            break;
//        }
    }
}

void IDFStore::effect(std::shared_ptr<Action> action) {
//    qDebug() << __PRETTY_FUNCTION__ << "->ACTION_TYPE: " << action->getType();
}
