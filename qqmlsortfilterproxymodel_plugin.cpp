#include "qqmlsortfilterproxymodel_plugin.h"

#include <qqml.h>

namespace qqsfpm
{

void registerQQmlSortFilterProxyModelTypes();
void registerFiltersTypes();
void registerSorterTypes();
void registerProxyRoleTypes();

}

void QQmlSortFilterProxyModelPlugin::registerTypes(const char *uri)
{
    Q_UNUSED(uri)

    qqsfpm::registerQQmlSortFilterProxyModelTypes();
    qqsfpm::registerSorterTypes();
    qqsfpm::registerProxyRoleTypes();
    qqsfpm::registerFiltersTypes();
}

