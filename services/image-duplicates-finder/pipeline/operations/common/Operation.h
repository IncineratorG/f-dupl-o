#ifndef OPERATION_H
#define OPERATION_H

#include <QThread>
#include <memory>
#include "services/image-duplicates-finder/pipeline/operations/data/OperationProgress.h"


class Operation : public QThread
{
    Q_OBJECT

public:
    Operation();
    virtual ~Operation() = 0;

    virtual void setNextOperation(std::shared_ptr<Operation> op);
    virtual std::shared_ptr<Operation> getNextOperation();

signals:
    void publishProgress(OperationProgress value);

private:
    std::shared_ptr<Operation> m_nextOperation;
};

#endif // OPERATION_H
