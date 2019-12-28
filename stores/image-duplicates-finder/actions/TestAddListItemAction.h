#ifndef TESTADDLISTITEMACTION_H
#define TESTADDLISTITEMACTION_H

#include "common/redux/Action.h"

class TestAddListItemAction : public Action
{
public:
    TestAddListItemAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // TESTADDLISTITEMACTION_H
