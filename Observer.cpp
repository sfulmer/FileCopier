#include "Observer.h"

using namespace net::draconia::util;

void Observable::notifyObservers(const void *objArg)
{
    for(Observer &objObserver : mLstObservers)
        objObserver.update(*this, objArg);

    setChanged(false);
}

void Observable::setChanged(const bool bChanged)
{
    mbChanged = bChanged;
}

Observable::Observable()
    :   mbChanged(false)
{ }

Observable::~Observable()
{ }

const vector<Observer> &Observable::getObservers() const
{
    return(mLstObservers);
}

bool Observable::isChanged() const
{
    return(mbChanged);
}
