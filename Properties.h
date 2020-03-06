#pragma once

#include "Property.h"
#include <QList>

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Properties
            {
                QList<Property> mLstProperties;
            protected:

            public:
                Properties();
            };
        }
    }
}
