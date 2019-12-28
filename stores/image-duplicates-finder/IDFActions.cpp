#include "IDFActions.h"
#include "actions/TestAction.h"
#include "actions/TestSetListAction.h"
#include "actions/TestAddListItemAction.h"
#include "actions/TestRemoveListItemAction.h"

#include <QDebug>

IDFActions::IDFActions() {

}

std::shared_ptr<Action> IDFActions::getAction(int type) const {
    switch (type) {
        case Test: {
            return std::make_shared<TestAction>();
        }

        case TestSetList: {
            return std::make_shared<TestSetListAction>();
        }

        case TestAddListItem: {
            return std::make_shared<TestAddListItemAction>();
        }

        case TestRemoveListItem: {
            return std::make_shared<TestRemoveListItemAction>();
        }

        default: {
            qDebug() << __PRETTY_FUNCTION__ << "->UNKNOWN_ACTION_TYPE: " << type;
        }
    }

    return nullptr;
}
