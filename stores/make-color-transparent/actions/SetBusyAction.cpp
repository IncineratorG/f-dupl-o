#include "SetBusyAction.h"
#include "stores/make-color-transparent/MakeColorTransaprentActions.h"

SetBusyAction::SetBusyAction() {
    mPayload = nullptr;
}

int SetBusyAction::getType() const {
    return MakeColorTransaprentActions::SetBusy;
}

std::shared_ptr<Payload> SetBusyAction::getPayload() {
    return mPayload;
}

void SetBusyAction::setPayload(std::shared_ptr<Payload> p) {
    mPayload = p;
}
