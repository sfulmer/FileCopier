#pragma once

#include <fstream>
#include <iostream>
#include <QList>
#include <QString>

using namespace std;

namespace net
{
    namespace draconia
    {
        namespace io
        {
            class PropertyFileIO
            {
                fstream mFileProperties;
                QList<Property> mLstProperties;
                QString msFilename;
            protected:
                fstream &getPropertiesFile();
                QList<Property> &getPropertyListInternal() const;
            public:
                PropertyFileIO();
                PropertyFileIO(const QString &sFilename);
                PropertyFileIO(const PropertyFileIO &refCopy);
                PropertyFileIO(PropertyFileIO &refToMove);
                ~PropertyFileIO();

                PropertyFileIO &operator=(const PropertyFileIO &refCopy);
                PropertyFileIO &operator=(PropertyFileIO &refToMoveAssign);

                PropertyFileIO &addProperty(const QString sKey, const QString &sValue);
                PropertyFileIO &addProperty(const Property &refProperty);
                PropertyFileIO &addProperty(Property &refProperty);
                QString &getFilename() const;
                const QList<Property> &getPropertyList() const;
                QList<Property> &load();
                QList<Property> &load(const QString &sFilename);
                void save();
                void save(const QString &sFilename);
                void save(const QList<Property> &lstProperties);
                void save(const QList<Property> &lstProperties, const QString &sFilename);
                void setFilename(const QString &sFilename);
            };
        }
    }
}
