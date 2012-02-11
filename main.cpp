#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QWebSettings>
#include "FenPrincipale.h"
#include "historique.h"



int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

     QApplication::setDesktopSettingsAware(false);


    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);


    //! Traduction des chaines predefinies par Qt dans notre langue
    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);



    //! Ouverture de la fenetre principale du navigateur
    FenPrincipale principale;
    principale.show();


    return app.exec();
}
