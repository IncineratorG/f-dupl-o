#include "MakeColorTransaprentActions.h"
#include "actions/SetImagePathAction.h"
#include "actions/SetTargetColorAction.h"
#include "actions/SetTargetColorTransparentAction.h"
#include "actions/SetBusyAction.h"

#include <QDebug>

MakeColorTransaprentActions::MakeColorTransaprentActions() {

}

std::shared_ptr<Action> MakeColorTransaprentActions::getAction(int type) const {
    switch (type) {
        case SetImagePath: {
            return std::make_shared<SetImagePathAction>();
        }

        case SetTargetColor: {
            return std::make_shared<SetTargetColorAction>();
        }

        case SetTargetColorTransparent : {
            return std::make_shared<SetTargetColorTransparentAction>();
        }

        case SetBusy: {
            return std::make_shared<SetBusyAction>();
        }

        default: {
            qDebug() << __PRETTY_FUNCTION__ << "->UNKNOWN_ACTION_TYPE: " << type;
        }
    }

    return nullptr;
}
