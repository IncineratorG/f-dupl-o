QT += quick
CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    services/image-duplicates-finder/ImageDuplicatesFinderService.cpp \
    services/image-duplicates-finder/pipeline/ImageDuplicatesFinderPipeline.cpp \
    services/image-duplicates-finder/pipeline/operations/common/Operation.cpp \
    services/image-duplicates-finder/pipeline/operations/data/OperationProgress.cpp \
    services/image-duplicates-finder/pipeline/operations/common/OperationSequence.cpp \
    screen-native-controllers/test-screen-controller/TestScreenController.cpp \
    common/reactive/Executable.cpp \
    common/reactive/Subscription.cpp \
    common/reactive/Subscriber.cpp \
    common/reactive/Subscribers.cpp \
    common/reactive/Observable.cpp \
    common/reactive/ObservableProperty.cpp \
    common/reactive/ObservableLike.cpp \
    common/service/Service.cpp \
    common/redux/State.cpp \
    common/redux/Action.cpp \
    common/redux/Payload.cpp \
    common/redux/ActionsFactory.cpp \
    common/redux/Store.cpp \
    stores/image-duplicates-finder/IDFStore.cpp \
    stores/image-duplicates-finder/IDFState.cpp \
    stores/image-duplicates-finder/IDFActions.cpp \
    stores/Stores.cpp \
    stores/image-duplicates-finder/actions/TestAction.cpp \
    models/test-screen-models/TestScreenListModel.cpp \
    stores/image-duplicates-finder/actions/TestSetListAction.cpp \
    stores/image-duplicates-finder/actions/TestAddListItemAction.cpp \
    stores/image-duplicates-finder/actions/TestRemoveListItemAction.cpp \
    screen-native-controllers/make-transparent-screen-controller/MakeTransparentScreenController.cpp \
    stores/make-color-transparent/MakeColorTransparentStore.cpp \
    stores/make-color-transparent/MakeColorTransparentState.cpp \
    stores/make-color-transparent/MakeColorTransaprentActions.cpp \
    stores/make-color-transparent/actions/SetImagePathAction.cpp \
    models/make-transparent-screen-model/MakeTransparentScreenModel.cpp \
    stores/make-color-transparent/helpers/ImageHelper.cpp \
    stores/make-color-transparent/actions/SetTargetColorAction.cpp \
    stores/make-color-transparent/actions/SetTargetColorTransparentAction.cpp \
    services/make-color-transparent/MakeColorTransparentService.cpp \
    services/make-color-transparent/pipeline/MakeColorTransparentPipeline.cpp \
    stores/make-color-transparent/actions/SetBusyAction.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    services/image-duplicates-finder/ImageDuplicatesFinderService.h \
    services/image-duplicates-finder/pipeline/ImageDuplicatesFinderPipeline.h \
    services/image-duplicates-finder/pipeline/operations/common/Operation.h \
    services/image-duplicates-finder/pipeline/operations/data/OperationProgress.h \
    services/image-duplicates-finder/pipeline/operations/common/OperationSequence.h \
    screen-native-controllers/test-screen-controller/TestScreenController.h \
    common/reactive/Executable.h \
    common/reactive/Subscription.h \
    common/reactive/Subscriber.h \
    common/reactive/Subscribers.h \
    common/reactive/Observable.h \
    common/reactive/ObservableProperty.h \
    common/reactive/ObservableLike.h \
    common/service/Service.h \
    common/redux/State.h \
    common/redux/Action.h \
    common/redux/Payload.h \
    common/redux/ActionsFactory.h \
    common/redux/Store.h \
    stores/image-duplicates-finder/IDFStore.h \
    stores/image-duplicates-finder/IDFState.h \
    stores/image-duplicates-finder/IDFActions.h \
    stores/Stores.h \
    stores/image-duplicates-finder/actions/TestAction.h \
    models/test-screen-models/TestScreenListModel.h \
    stores/image-duplicates-finder/actions/TestSetListAction.h \
    stores/image-duplicates-finder/actions/TestAddListItemAction.h \
    stores/image-duplicates-finder/actions/TestRemoveListItemAction.h \
    screen-native-controllers/make-transparent-screen-controller/MakeTransparentScreenController.h \
    stores/make-color-transparent/MakeColorTransparentStore.h \
    stores/make-color-transparent/MakeColorTransparentState.h \
    stores/make-color-transparent/MakeColorTransaprentActions.h \
    stores/make-color-transparent/actions/SetImagePathAction.h \
    models/make-transparent-screen-model/MakeTransparentScreenModel.h \
    stores/make-color-transparent/helpers/ImageHelper.h \
    stores/make-color-transparent/actions/SetTargetColorAction.h \
    stores/make-color-transparent/actions/SetTargetColorTransparentAction.h \
    services/make-color-transparent/MakeColorTransparentService.h \
    services/make-color-transparent/pipeline/MakeColorTransparentPipeline.h \
    stores/make-color-transparent/actions/SetBusyAction.h
