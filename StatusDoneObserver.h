#pragma once

#include "Observer.h"

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace observers
            {
                class StatusDoneObserver : public Observer
                {
                public:
                    virtual void update(const Observable &refObservable, const QString &sProperty);
                };
            }
        }
    }
}
