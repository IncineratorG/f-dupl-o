#include "TestAction.h"

#include "stores/image-duplicates-finder/IDFActions.h"

TestAction::TestAction() {
    mPayload = nullptr;
}

int TestAction::getType() const {
    return IDFActions::Test;
}

std::shared_ptr<Payload> TestAction::getPayload() {
    return mPayload;
}

void TestAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
