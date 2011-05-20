#include "cookiejar.h"
#include <QtCore>



//! constructeur de cookie Jar
CookieJar::CookieJar(QObject *parent)
    :QNetworkCookieJar(parent)
{
    QFile cookieFile("cookies.txt");
    if (cookieFile.exists() && cookieFile.open(QIODevice::ReadOnly) )
    {
        QList<QNetworkCookie> list;
        QByteArray line;
        while(!(line = cookieFile.readLine()).isNull())
        {
            list.append(QNetworkCookie::parseCookies(line));
        }
        setAllCookies(list);
    }
}

//! Destructeur, sauve les cookies
CookieJar::~CookieJar()
{
    QFile cookieFile("cookies.txt");
    if (cookieFile.open(QIODevice::WriteOnly) )
    {
        QTextStream out(&cookieFile);
        foreach(const QNetworkCookie & cookie, allCookies())
        {
            if (!cookie.isSessionCookie())
                out << cookie.toRawForm() << endl;
        }
    }
}




QList<QNetworkCookie> CookieJar::cookiesForUrl ( const QUrl & url ) const
{
    qDebug() << "Getting cookie for" << url;
    return QNetworkCookieJar::cookiesForUrl(url);
}

bool CookieJar::setCookiesFromUrl ( const QList<QNetworkCookie> & cookieList, const QUrl & url )
{
    qDebug() << "Setting cookie for" << url;
    return QNetworkCookieJar::setCookiesFromUrl(cookieList, url);
}
