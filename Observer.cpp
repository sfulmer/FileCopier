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

const vector<Observer *> &Observable::getObservers() const
{
    return(mLstObservers);
}

bool Observable::isChanged() const
{
    return(mbChanged);
}
