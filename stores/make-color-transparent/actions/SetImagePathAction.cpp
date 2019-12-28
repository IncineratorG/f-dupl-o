#include "SetImagePathAction.h"
#include "stores/make-color-transparent/MakeColorTransaprentActions.h"

SetImagePathAction::SetImagePathAction() {
    mPayload = nullptr;
}

int SetImagePathAction::getType() const {
    return MakeColorTransaprentActions::SetImagePath;
}

std::shared_ptr<Payload> SetImagePathAction::getPayload() {
    return mPayload;
}

void SetImagePathAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
