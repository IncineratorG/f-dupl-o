#include "IDFState.h"

IDFState::IDFState() {
    mTestStatus = std::make_shared<ObservableProperty<QString>>(std::make_shared<QString>("INITIAL_TEST_STATUS"));
    mList = std::make_shared<ObservableProperty<QList<QString>>>(std::make_shared<QList<QString>>());
}
