#include "TestRemoveListItemAction.h"

#include "stores/image-duplicates-finder/IDFActions.h"

TestRemoveListItemAction::TestRemoveListItemAction() {
    mPayload = nullptr;
}

int TestRemoveListItemAction::getType() const {
    return IDFActions::TestRemoveListItem;
}

std::shared_ptr<Payload> TestRemoveListItemAction::getPayload() {
    return mPayload;
}

void TestRemoveListItemAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
