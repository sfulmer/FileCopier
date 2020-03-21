#pragma once

#include "Properties.h"
#include "PropertyFileIO.h"

using net::draconia::util::Properties;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Persistable
            {
            protected:
                virtual Properties prefixWithDividerKey(const Properties &refProperties) = 0;
            public:
                virtual ~Persistable();

                virtual Properties pullSettingsToProperties() = 0;
            };
        }
    }
}
