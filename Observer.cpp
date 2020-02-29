#include "Observer.h"

using namespace net::draconia::util;

void Observable::notifyObservers(const QString &sProperty)
{
    for(Observer *ptrObserver : mLstObservers)
        ptrObserver->update(*this, sProperty);

    setChanged(false);
}

void Observable::setChanged(const bool bChanged)
{
    mbChanged = bChanged;
}

Observable::Observable()
    :   mbChanged(false)
{ }

void Observable::addObserver(const Observer *objObserver)
{
    mLstObservers.append(const_cast<Observer *>(objObserver));
}

const QList<Observer *> &Observable::getObservers() const
{
    return(mLstObservers);
}

bool Observable::isChanged() const
{
    return(mbChanged);
}
