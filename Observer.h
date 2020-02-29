#pragma once

#include <QList>
#include <QString>

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
                QList<Observer *> mLstObservers;
            protected:
                void notifyObservers(const QString &sProperty);
                void setChanged(const bool bChanged = true);
            public:
                Observable();

                void addObserver(const Observer *objObserver);
                const QList<Observer *> &getObservers() const;
                bool isChanged() const;
            };
        }
    }
}





































