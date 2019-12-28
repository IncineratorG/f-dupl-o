#ifndef MAKECOLORTRANSPARENTSTORE_H
#define MAKECOLORTRANSPARENTSTORE_H

#include "common/redux/Store.h"
#include "services/make-color-transparent/MakeColorTransparentService.h"
#include "MakeColorTransparentState.h"
#include "MakeColorTransaprentActions.h"

class MakeColorTransparentStore : public Store
{
public:
    MakeColorTransparentStore();

    std::shared_ptr<State> getState() const;
    std::shared_ptr<ActionsFactory> getActionsFactory() const;

protected:
    void reduce(std::shared_ptr<Action> action);
    void effect(std::shared_ptr<Action> action);

private:
    std::shared_ptr<MakeColorTransparentState> mState;
    std::shared_ptr<MakeColorTransaprentActions> mActionsFactory;

    const QString mQmlFilePrefix;

    MakeColorTransparentService mService;

    void setImagePathReduce(std::shared_ptr<Action> action);
    void setTargetColorReduce(std::shared_ptr<Action> action);
//    void setTargetColorTransparentReduce(std::shared_ptr<Action> action);
    void setBusyReduce(std::shared_ptr<Action> action);

    void setTargetColorTransparentEffect(std::shared_ptr<Action> action);
};

#endif // MAKECOLORTRANSPARENTSTORE_H
