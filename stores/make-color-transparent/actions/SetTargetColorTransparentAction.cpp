#include "SetTargetColorTransparentAction.h"
#include "stores/make-color-transparent/MakeColorTransaprentActions.h"

SetTargetColorTransparentAction::SetTargetColorTransparentAction() {
    mPayload = nullptr;
}

int SetTargetColorTransparentAction::getType() const {
    return MakeColorTransaprentActions::SetTargetColorTransparent;
}

std::shared_ptr<Payload> SetTargetColorTransparentAction::getPayload() {
    return mPayload;
}

void SetTargetColorTransparentAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
