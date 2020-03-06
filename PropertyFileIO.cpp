#include "PropertyFileIO.h"

using namespace net::draconia::io;



fstream &PropertyFileIO::getPropertiesFile()
{
    return(mFileProperties);
}

QList<Property> &PropertyFileIO::getPropertyListInternal() const
{
    return(const_cast<QList<Property> &>(mLstProperties));
}

PropertyFileIO::PropertyFileIO()
{ }

PropertyFileIO::PropertyFileIO(const QString &sFilename)
    :   msFilename(sFilename)
{ }

PropertyFileIO::PropertyFileIO(const PropertyFileIO &refCopy)
    :   mLstProperties(refCopy.getPropertyList())
    ,   msFilename(refCopy.getFilename())
{ }

PropertyFileIO::PropertyFileIO(PropertyFileIO &refToMove)
    :   mLstProperties(refToMove.getPropertyList())
    ,   msFilename(refToMove.getFilename())
{ }

PropertyFileIO::~PropertyFileIO()
{
    if(getPropertiesFile().is_open())
        getPropertiesFile().close();
}

PropertyFileIO &PropertyFileIO::operator=(const PropertyFileIO &refToMoveAssign)
{
    setFilename(refToMoveAssign.getFilename());

    for(Property objProperty : refToMoveAssign.getPropertyList())
        getPropertyListInternal().append(objProperty);

    return(*this);
}

PropertyFileIO &PropertyFileIO::operator=(PropertyFileIO &refToMoveAssign)
{
    setFilename(refToMoveAssign.getFilename());

    for(Property objProperty : refToMoveAssign.getPropertyList())
        getPropertyListInternal().append(objProperty);

    return(*this);
}

PropertyFileIO &PropertyFileIO::addProperty(const QString sKey, const QString &sValue)
{
    return(addProperty(Property(sKey, sValue)));
}

PropertyFileIO &PropertyFileIO::addProperty(const Property &refProperty)
{
    getPropertyListInternal().append(refProperty);

    return(*this);
}

PropertyFileIO &PropertyFileIO::addProperty(Property &refProperty)
{
    getPropertyListInternal().append(refProperty);

    return(*this);
}

QString &PropertyFileIO::getFilename() const
{
    return(const_cast<QString &>(msFilename));
}

const QList<Property> &PropertyFileIO::getPropertyList() const
{
    return(getPropertyListInternal());
}

QList<Property> &PropertyFileIO::load()
{
    return(load(getFilename()));
}

QList<Property> &PropertyFileIO::load(const QString &sFilename)
{
    if(getPropertiesFile().is_open())
        getPropertiesFile().close();

    if(sFilename.isEmpty())
        getPropertiesFile().open(getFilename().toStdString(), fstream::in);
    else
        getPropertiesFile().open(sFilename.toStdString(), fstream::in);

    while(!getPropertiesFile().eof())
        {
        char sProperty[120];

        getPropertiesFile().getline(sProperty, 120);

        getPropertyListInternal().append(Property::parse(sProperty));
        }

    getPropertiesFile().close();

    return(getPropertyListInternal());
}

void PropertyFileIO::save()
{
    save(getPropertyListInternal());
}

void PropertyFileIO::save(const QString &sFilename)
{
    save(getPropertyListInternal(), sFilename);
}

void PropertyFileIO::save(const QList<Property> &lstProperties)
{
    save(lstProperties, getFilename());
}

void PropertyFileIO::save(const QList<Property> &lstProperties, const QString &sFilename)
{
    if(getPropertiesFile().is_open())
        getPropertiesFile().close();

    if(sFilename.isEmpty())
        getPropertiesFile().open(getFilename().toStdString(), fstream::out);
    else
        getPropertiesFile().open(sFilename.toStdString(), fstream::out);

    for(Property objProperty : lstProperties)
        {
        QString sProperty = objProperty.toString();

        getPropertiesFile().write(sProperty.toStdString().c_str(), sProperty.size());
        }

    getPropertiesFile().close();
}

void PropertyFileIO::setFilename(const QString &sFilename)
{
    msFilename = sFilename;

    if(getPropertiesFile().is_open())
        getPropertiesFile().close();
}
