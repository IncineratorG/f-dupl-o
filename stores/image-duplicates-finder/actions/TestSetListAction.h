#ifndef TESTSETLISTACTION_H
#define TESTSETLISTACTION_H

#include "common/redux/Action.h"

class TestSetListAction : public Action
{
public:
    TestSetListAction();

    int getType() const;

    std::shared_ptr<Payload> getPayload();
    void setPayload(std::shared_ptr<Payload> p);

private:
    std::shared_ptr<Payload> mPayload;
};

#endif // TESTSETLISTACTION_H
