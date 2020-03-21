#pragma once

#include "Properties.h"

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Setable
            {
            public:
                virtual ~Setable();

                virtual void setUp(const Properties &refProperties) = 0;
            };
        }
    }
}
