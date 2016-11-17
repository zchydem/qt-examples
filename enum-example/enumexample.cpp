#include "enumexample.h"

A::A(QObject * parent)
    : QObject(parent)
{

}

B::B(QObject *parent)
    : A(parent)
    , m_type(NoValue)
{

}

void B::setType(Type type)
{
    if (m_type != type) {
        m_type = type;
        emit typeChanged();
    }
}

B::Type B::type() const
{
    return m_type;
}
