#ifndef IDFSTORE_H
#define IDFSTORE_H

#include "common/redux/Store.h"
#include "IDFState.h"
#include "IDFActions.h"

class IDFStore : public Store
{
public:
    IDFStore();

    std::shared_ptr<State> getState() const;
    std::shared_ptr<ActionsFactory> getActionsFactory() const;

protected:
    void reduce(std::shared_ptr<Action> action);
    void effect(std::shared_ptr<Action> action);

private:
    std::shared_ptr<IDFState> mIdfState;
    std::shared_ptr<IDFActions> mIdfActionsFactory;
};

#endif // IDFSTORE_H
