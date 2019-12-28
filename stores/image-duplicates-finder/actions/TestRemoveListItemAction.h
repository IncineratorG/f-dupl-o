#ifndef TESTREMOVELISTITEMACTION_H
#define TESTREMOVELISTITEMACTION_H

#include "common/redux/Action.h"

class TestRemoveListItemAction : public Action
{
public:
    TestRemoveListItemAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // TESTREMOVELISTITEMACTION_H
