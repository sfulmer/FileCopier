#include "FileCopierController.h"
#include "Persistable.h"
#include "SettingsPersistenceObserver.h"
#include "SetupModel.h"

using net::draconia::FileCopier::FileCopierController;
using net::draconia::FileCopier::model::SetupModel;
using namespace net::draconia::FileCopier::observers;
using net::draconia::util::Persistable;

PropertyFileIO &SettingsPersistenceObserver::getPropertyFileIO() const
{
    return(const_cast<PropertyFileIO &>(mRefPropertyFileIO));
}

SettingsPersistenceObserver::SettingsPersistenceObserver(PropertyFileIO &refPropertyFileIO)
    :   Observer()
    ,   mRefPropertyFileIO(refPropertyFileIO)
{ }

void SettingsPersistenceObserver::update(const Observable &refObservable, const QString &sProperty)
{
    Q_UNUSED(sProperty);

    SetupModel &refSetupModel = static_cast<SetupModel &>(const_cast<Observable &>(refObservable));

    getPropertyFileIO().save(refSetupModel.pullSettingsToProperties(), "Config.properties");
}
