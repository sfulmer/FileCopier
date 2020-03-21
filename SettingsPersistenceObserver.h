#pragma once

#include "Observer.h"
#include "PropertyFileIO.h"

using net::draconia::io::PropertyFileIO;
using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace observers
            {
                class SettingsPersistenceObserver : public Observer
                {
                    PropertyFileIO mRefPropertyFileIO;
                protected:
                    PropertyFileIO &getPropertyFileIO() const;
                public:
                    SettingsPersistenceObserver(PropertyFileIO &refPropertyFileIO);

                    virtual void update(const Observable &refObservable, const QString &sProperty);
                };
            }
        }
    }
}
