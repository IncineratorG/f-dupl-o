#include "TestAddListItemAction.h"

#include "stores/image-duplicates-finder/IDFActions.h"

TestAddListItemAction::TestAddListItemAction() {
    mPayload = nullptr;
}

int TestAddListItemAction::getType() const {
    return IDFActions::TestAddListItem;
}

std::shared_ptr<Payload> TestAddListItemAction::getPayload() {
    return mPayload;
}

void TestAddListItemAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
