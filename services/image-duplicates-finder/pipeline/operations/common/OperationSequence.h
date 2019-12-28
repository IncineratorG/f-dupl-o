#ifndef OPERATIONSEQUENCE_H
#define OPERATIONSEQUENCE_H

#include <QPair>
#include "Operation.h"


class OperationSequence
{
public:
    OperationSequence();
    OperationSequence(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2);
    OperationSequence(const OperationSequence& other);

    std::shared_ptr<Operation> getFirstOperation() const;
    std::shared_ptr<Operation> getSecondOperation() const;

    bool operator<(const OperationSequence& other) const {
        return this->m_sequence < other.m_sequence;
    }

private:
    QPair<std::shared_ptr<Operation>, std::shared_ptr<Operation>> m_sequence;
};

#endif // OPERATIONSEQUENCE_H
