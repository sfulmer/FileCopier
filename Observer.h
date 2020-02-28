#pragma once

#include <QString>
#include <vector>

using namespace std;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class Observable;

            class Observer
            {
            public:
                virtual void update(const Observable &refObservable, const QString &sProperty) = 0;
            };

            class Observable
            {
                bool mbChanged;
                vector<Observer *> mLstObservers;
            protected:
                void notifyObservers(const QString &sProperty);
                void setChanged(const bool bChanged = true);
            public:
                Observable();

                const vector<Observer *> &getObservers() const;
                bool isChanged() const;
            };
        }
    }
}





































