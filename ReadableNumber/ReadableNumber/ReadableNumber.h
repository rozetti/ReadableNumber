#pragma once

#include "ReadableNumber_global.h"

#include <QString>

class READABLENUMBERSHARED_EXPORT ReadableNumber
{
public:
    ReadableNumber();

    QString makeReadable(long n) const;
    QString makeReadable(double d, int decimals = 5) const;
    QString makeReadable(char const *) const;

    static QString const NaN() { return _nan; }
    static void setNaN(QString s) { _nan = s; }

private:
    const char *getTerminal(int n) const;

    static QString _nan;
};

