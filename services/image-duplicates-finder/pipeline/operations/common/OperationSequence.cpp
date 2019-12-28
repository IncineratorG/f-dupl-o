#include "OperationSequence.h"

OperationSequence::OperationSequence()
    : m_sequence(nullptr, nullptr)
{

}

OperationSequence::OperationSequence(std::shared_ptr<Operation> op1, std::shared_ptr<Operation> op2)
    : m_sequence(op1, op2)
{

}

OperationSequence::OperationSequence(const OperationSequence& other)
    : m_sequence(other.m_sequence)
{

}

std::shared_ptr<Operation> OperationSequence::getFirstOperation() const {
    return m_sequence.first;
}

std::shared_ptr<Operation> OperationSequence::getSecondOperation() const {
    return m_sequence.second;
}
