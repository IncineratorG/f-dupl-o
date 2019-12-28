#include "TestSetListAction.h"

#include "stores/image-duplicates-finder/IDFActions.h"

TestSetListAction::TestSetListAction() {
    mPayload = nullptr;
}

int TestSetListAction::getType() const {
    return IDFActions::TestSetList;
}

std::shared_ptr<Payload> TestSetListAction::getPayload() {
    return mPayload;
}

void TestSetListAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
