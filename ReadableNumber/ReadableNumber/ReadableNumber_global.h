#pragma once

#include <QtCore/qglobal.h>

#if defined(READABLENUMBER_LIBRARY)
#  define READABLENUMBERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define READABLENUMBERSHARED_EXPORT Q_DECL_IMPORT
#endif

