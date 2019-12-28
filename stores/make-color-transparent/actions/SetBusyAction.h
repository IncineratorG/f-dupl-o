#ifndef SETBUSYACTION_H
#define SETBUSYACTION_H

#include "common/redux/Action.h"

class SetBusyAction : public Action
{
public:
    SetBusyAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // SETBUSYACTION_H
