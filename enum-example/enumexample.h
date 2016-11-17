#ifndef ENUMEXAMPLE_H
#define ENUMEXAMPLE_H

#include <QObject>
#include <QtDebug>

class A : public QObject
{
    Q_OBJECT
public:
    enum Type {
        NoValue    = 0,
        TypeValue1 = 100,
        TypeValue2 = 200,
        TypeValue3 = 300
    };
    Q_ENUMS(Type)

    A(QObject * parent = 0);
    virtual ~A() {}

};

// Class B is an example how to expose enum as a part of class B to the
// QML engine by inherting the enum from the superclass.
class B : public A
{
    Q_OBJECT
    Q_PROPERTY(Type type READ type WRITE setType NOTIFY typeChanged)
    Q_ENUM(A::Type)
public:

    B(QObject * parent = 0);
    ~B() {}

    void setType(Type type);
    Type type() const;

signals:
    void typeChanged();

private:
    Type m_type;
};

// Class C is an example class how to expose enums to QML engine without QObject
class C
{
    Q_GADGET
public:

    enum Type {
        NoValue    = 0,
        TypeValue1 = 1000,
        TypeValue2 = 2000,
        TypeValue3 = 3000
    };

    Q_ENUM(Type)
};


#endif // ENUMEXAMPLE_H
