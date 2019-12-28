#ifndef SETTARGETCOLORTRANSPARENTACTION_H
#define SETTARGETCOLORTRANSPARENTACTION_H

#include "common/redux/Action.h"

class SetTargetColorTransparentAction : public Action
{
public:
    SetTargetColorTransparentAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // SETTARGETCOLORTRANSPARENTACTION_H
