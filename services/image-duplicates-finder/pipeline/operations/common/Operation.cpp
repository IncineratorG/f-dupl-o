#include "Operation.h"


Operation::Operation() {
    m_nextOperation = nullptr;
}

Operation::~Operation() {

}

void Operation::setNextOperation(std::shared_ptr<Operation> op) {
    m_nextOperation = op;
}

std::shared_ptr<Operation> Operation::getNextOperation() {
    return m_nextOperation;
}
