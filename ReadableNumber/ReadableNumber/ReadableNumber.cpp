#include "ReadableNumber.h"

#include <QString>
#include <QStringList>

#include <stdexcept>

QString ReadableNumber::_nan = QString("NOT A NUMBER");

ReadableNumber::ReadableNumber()
{
}

char const *ReadableNumber::getTerminal(int n) const
{
    char const *s = 0;

    switch(n)
    {
    case 0: s = "ZERO"; break;
    case 1: s = "ONE"; break;
    case 2: s = "TWO"; break;
    case 3: s = "THREE"; break;
    case 4: s = "FOUR"; break;
    case 5: s = "FIVE"; break;
    case 6: s = "SIX"; break;
    case 7: s = "SEVEN"; break;
    case 8: s = "EIGHT"; break;
    case 9: s = "NINE"; break;
    case 10: s = "TEN"; break;
    case 11: s = "ELEVEN"; break;
    case 12: s = "TWELVE"; break;
    case 13: s = "THIRTEEN"; break;
    case 14: s = "FOURTEEN"; break;
    case 15: s = "FIFTEEN"; break;
    case 16: s = "SIXTEEN"; break;
    case 17: s = "SEVENTEEN"; break;
    case 18: s = "EIGHTEEN"; break;
    case 19: s = "NINETEEN"; break;
    case 20: s = "TWENTY"; break;
    case 30: s = "THIRTY"; break;
    case 40: s = "FOURTY"; break;
    case 50: s = "FIFTY"; break;
    case 60: s = "SIXTY"; break;
    case 70: s = "SEVENTY"; break;
    case 80: s = "EIGHTY"; break;
    case 90: s = "NINETY"; break;
    }

    return s;
}

QString ReadableNumber::makeReadable(long n) const
{
    QString qs;

    if (n < 0)
    {
        qs += "MINUS ";
        n = -n;
    }

    auto s = getTerminal(n);
    if (s)
    {
        qs += s;
    }
    else if (n < 100)
    {
        auto ones = getTerminal(n % 10);
        auto tens = getTerminal(n - (n % 10));

        qs += QString(tens) + " " + QString(ones);
    }
    else if (n < 1000)
    {
        qs += makeReadable(n / 100) + " HUNDRED";

        auto remainder = n % 100;
        if (0 != remainder)
        {
            qs += " AND " + makeReadable(remainder);
        }
    }
    else if (n < 1000000)
    {
        qs += makeReadable(n / 1000) + " THOUSAND";

        auto remainder = n % 1000;
        if (0 != remainder)
        {
            qs += " ";

            auto hundreds = remainder / 100;
            if (0 == hundreds)
            {
                qs += "AND ";
            }

            qs += makeReadable(remainder);
        }
    }
    else if (n < 1000000000000)
    {
        qs += makeReadable(n / 1000000) + " MILLION";

        auto remainder = n % 1000000;
        if (0 != remainder)
        {
            qs += " ";

            qs += makeReadable(remainder);
        }
    }
    else if (1000000000000 == n)
    {
        qs += "ONE BILLION";
    }
    else
    {
        throw std::runtime_error("Number is absolutely too large");
    }

    return qs;
}

QString ReadableNumber::makeReadable(double d, int decimals) const
{
    long integer_part = static_cast<long>(d);

    QString qs;

    qs += makeReadable(integer_part);

    double fractional_part = (d > 0 ? 1 : -1) * (d - integer_part);

    qs += " POINT";

    for (int i = 0; i < decimals; ++i)
    {
        fractional_part *= 10;
        long digit = static_cast<long>(fractional_part) % 10;

        qs += " " + makeReadable(digit);
    }

    return qs;
}

QString ReadableNumber::makeReadable(const char *s) const
{
    QString qs;
    bool ok;

    auto parts = QString(s).split('.');
    auto integer_part = parts[0].toLong(&ok);
    if (!ok) return NaN();

    qs += makeReadable(integer_part);

    if (1 == parts.size()) return qs;

    QString fractional_part = parts[1];
    if (0 == fractional_part.size()) return qs;

    qs += " POINT";

    foreach(auto c, fractional_part)
    {
        auto digit = (long)c.digitValue();
        if (-1 == digit) return NaN();

        qs += " " + makeReadable((long)digit);
    }

    return qs;
}
