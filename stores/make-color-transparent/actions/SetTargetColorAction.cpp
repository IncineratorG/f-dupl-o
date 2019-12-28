#include "SetTargetColorAction.h"
#include "stores/make-color-transparent/MakeColorTransaprentActions.h"

SetTargetColorAction::SetTargetColorAction() {
    mPayload = nullptr;
}

int SetTargetColorAction::getType() const {
    return MakeColorTransaprentActions::SetTargetColor;
}

std::shared_ptr<Payload> SetTargetColorAction::getPayload() {
    return mPayload;
}

void SetTargetColorAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
