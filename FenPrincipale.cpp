/*!
  * \file FenPrincipale.cpp
  * \brief Navigateur web ecrit en C++ avec Qt
  * \author Mateo21, David Remacle
  * \version 0.1
  *
  * FenPrincipale is the main window of the app.
  *
  *
  *
  */

#include "FenPrincipale.h"
#include "prefdialog.h"
#include "historique.h"
#include "apropos.h"
#include "CookieJar.h"
#include "helpbrowser.h"

/*! to do : bug fixe with CookieJar.
 *          if CookieJar.h is enabled, the app would not compile
 */



FenPrincipale::FenPrincipale()
{

#ifdef Q_WS_MAC
    setUnifiedTitleAndToolBarOnMac(true); //! Mac Apperance of tool bar
#endif

    //! Lecture des preferences
    settings = new QSettings("ZNavigo", "ZNavigo");

    QString stringPref = settings->value("home").toString();


    setAnimated(false);

    creerActions();
    creerMenus();
    creerBarresOutils();
    creerBarreEtat();
    creerDockRSSWidget();


    onglets = new QTabWidget;
    onglets->addTab(creerOngletPageWeb(stringPref), tr("(Nouvelle page)"));
    connect(onglets, SIGNAL(currentChanged(int)), this, SLOT(changementOnglet(int)));
    setCentralWidget(onglets);

   onglets->setDocumentMode(true);


    setMinimumSize(500, 350);
    setWindowIcon(QIcon(":/images/znavigo.png"));
    setWindowTitle(tr("zNavigo"));



    int numMotCherch = settings->value("Moteur_de_recherche_index").toInt();
    switch(numMotCherch)
    {
    case 0:
        champGoogle->setText(tr("Tapez ici vos recherches avec Google."));
        break;
    case 1:
        champGoogle->setText(tr("Tapez ici vos recherches avec Yahoo."));
        break;
    case 2:
        champGoogle->setText(tr("Tapez ici vos recherches avec Bing."));
        break;
    case 3:
        champGoogle->setText(tr("Tapez ici vos recherche avec altavista..."));
        break;
    default:
        champGoogle->setText(tr("Vous n'avez pas defini de moteur de recherche"));
        break;
    }




}

/*!
* \fn creerAction ()
* \brief Fonction de creation des actions qui seront utilisee par les menu et bouton personnalises.
*
* \param aucun.
* \return de type void
*/



void FenPrincipale::creerActions()
{
    actionNouvelOnglet = new QAction(tr("&New Tab"), this);
    actionNouvelOnglet->setShortcut(tr("Ctrl+T"));
    connect(actionNouvelOnglet, SIGNAL(triggered()), this, SLOT(nouvelOnglet()));
    actionFermerOnglet = new QAction(tr("&Close Tab"), this);
    actionFermerOnglet->setShortcut(tr("Ctrl+W"));
    connect(actionFermerOnglet, SIGNAL(triggered()), this, SLOT(fermerOnglet()));
    actionQuitter = new QAction(tr("&Quit"), this);
    actionQuitter->setShortcut(tr("Ctrl+Q"));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    actionPrecedente = new QAction(QIcon(":/images/precedente.png"), tr("&Precedente"), this);
    actionPrecedente->setShortcut(QKeySequence::Back);


    connect(actionPrecedente, SIGNAL(triggered()), this, SLOT(precedente()));
    actionSuivante = new QAction(QIcon(":/images/suivante.png"), tr("&Suivante"), this);
    actionSuivante->setShortcut(QKeySequence::Forward);
    connect(actionSuivante, SIGNAL(triggered()), this, SLOT(suivante()));
    actionStop = new QAction(QIcon(":/images/stop.png"), tr("S&top"), this);
    connect(actionStop, SIGNAL(triggered()), this, SLOT(stop()));
    actionActualiser = new QAction(QIcon(":/images/actualiser.png"), tr("&Actualiser"), this);
    actionActualiser->setShortcut(QKeySequence::Refresh);
    connect(actionActualiser, SIGNAL(triggered()), this, SLOT(actualiser()));
    actionAccueil = new QAction(QIcon(":/images/accueil.png"), tr("A&ccueil"), this);
    connect(actionAccueil, SIGNAL(triggered()), this, SLOT(accueil()));
    actionGo = new QAction(QIcon(":/images/go.png"), tr("A&ller a"), this);
    connect(actionGo, SIGNAL(triggered()), this, SLOT(chargerPage()));

    actionAPropos = new QAction(tr("&About"), this);
    connect(actionAPropos, SIGNAL(triggered()), this, SLOT(aPropos()));
    //actionAPropos->setShortcut(QKeySequence::HelpContents);
    actionAProposQt = new QAction(tr("About &Qt"), this);
    connect(actionAProposQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    montrerAide = new QAction(tr("&Help"), this);
    montrerAide->setShortcut(QKeySequence::HelpContents);
    connect(montrerAide, SIGNAL(triggered()), this, SLOT(showHelp()));

    actionPrefWindow = new QAction(tr("Preferences"), this);
    actionPrefWindow->setShortcut(tr("Ctrl+,"));
    connect(actionPrefWindow, SIGNAL(triggered()), this, SLOT(lancerPreference()));

    actionPlusGrand = new QAction(QIcon(":/images/Zoom-In-icon.png"), tr("Zoom avant"), this);
    connect(actionPlusGrand, SIGNAL(triggered()), this, SLOT(plusGrandSlot()));
    actionPlusGrand->setShortcut(tr("Ctrl++"));
    actionPlusPetit = new QAction(QIcon(":/images/Zoom-Out-icon.png"), tr("Zoom arrière"), this);
    connect(actionPlusPetit, SIGNAL(triggered()), this, SLOT(plusPetitSlot()));
    actionPlusPetit->setShortcut(tr("Ctrl+-"));

    actionShowHistorique = new QAction(tr("Show History"), this);
    actionShowHistorique->setShortcut(tr("Ctrl+"));
    connect(actionShowHistorique, SIGNAL(triggered()), this, SLOT(montrerHistorique()));

    showBookmarks = new QAction(tr("Show Bookmaks"), this);
    connect(showBookmarks, SIGNAL(triggered()), this, SLOT(montrerMarquePage()));

    afficherRSS = new QAction(tr("Show RSS"), this);
    //connect(afficherRSS, SIGNAL(triggered()), RSSWidget, SLOT(visibilityChanged()));

    //connect(qApp, SIGNAL(aboutToQuit()), SLOT(aurevoir()));



}

/*! \brief aurevoir est le slot pour afficher l'information que l'application quitte.
  */

void FenPrincipale::aurevoir()
{
    QMessageBox::information(this, "Ciao", "On Ferme");
}

void FenPrincipale::creerMenus()
{
    QMenu *menuFichier = menuBar()->addMenu(tr("&File"));

    menuFichier->addAction(actionNouvelOnglet);
    menuFichier->addAction(actionFermerOnglet);
    menuFichier->addSeparator();
    menuFichier->addAction(actionQuitter);

    QMenu *menuNavigation = menuBar()->addMenu(tr("&Présentation"));

    menuNavigation->addAction(actionPrecedente);
    menuNavigation->addAction(actionSuivante);
    menuNavigation->addAction(actionStop);
    menuNavigation->addAction(actionActualiser);
    menuNavigation->addAction(actionAccueil);
    menuNavigation->addSeparator();
    menuNavigation->addAction(actionPlusGrand);
    menuNavigation->addAction(actionPlusPetit);

    QMenu *menuBookmark = menuBar()->addMenu(tr("&Bookmarks"));
    menuBookmark->addAction(showBookmarks);


    MenuHistorique = menuBar()->addMenu(tr("H&istory"));
    MenuHistorique->addAction(actionShowHistorique);


    QMenu *menuAide = menuBar()->addMenu(tr("&Help"));

    menuAide->addAction(montrerAide);
    menuAide->addAction(actionAPropos);
    menuAide->addAction(actionAProposQt);
    menuAide->addSeparator();
    menuAide->addAction(actionPrefWindow);



}

void FenPrincipale::creerBarresOutils()
{
    champAdresse = new QLineEdit;
    connect(champAdresse, SIGNAL(returnPressed()), this, SLOT(chargerPage()));

    champGoogle = new QLineEdit;
    connect(champGoogle, SIGNAL(returnPressed()), this, SLOT(rechercherGoogle()));
    champGoogle->setToolTip(tr("Champ de recherche."));

    actionPrecedente->setToolTip(tr("page precedente\naffiche la page precedente"));

    //mybarr = new myToolBar;

    QToolBar *toolBarNavigation = addToolBar(tr("Navigation"));

    toolBarNavigation->addAction(actionPrecedente);
    toolBarNavigation->addAction(actionSuivante);
    toolBarNavigation->addAction(actionStop);
    toolBarNavigation->addAction(actionActualiser);
    toolBarNavigation->addAction(actionAccueil);
    toolBarNavigation->addWidget(champAdresse);
    toolBarNavigation->addAction(actionGo);
    toolBarNavigation->addSeparator();
    toolBarNavigation->addWidget(champGoogle);

    //toolBarNavigation->addWidget(mybarr);
}

/*!
* \brief creerBarreEtat()
*
* cree la barre d'etat de la fenetre principale
*
* \param aucuns
*/

void FenPrincipale::creerBarreEtat()
{



    progression = new QProgressBar(this);
    progression->setVisible(false);
    progression->setMaximumHeight(14);
    statusBar()->addPermanentWidget(progression);
}

void FenPrincipale::creerDockRSSWidget()
{
    /*rssWidget = new QDockWidget("RSS", this, Qt::Sheet);
    monRSSWidget = new RSSWidget;

    rssWidget->setWidget(monRSSWidget);

    rssWidget->setFeatures(QDockWidget::DockWidgetClosable);
    rssWidget->setFeatures(QDockWidget::DockWidgetMovable);
    rssWidget->setFeatures(QDockWidget::DockWidgetVerticalTitleBar);

    addDockWidget(Qt::LeftDockWidgetArea, rssWidget);

    rssWidget->show(); */
}



/*! Slots
  */

void FenPrincipale::precedente() //! Back website in history of webview
{
    pageActuelle()->back();
}

void FenPrincipale::suivante() //! Next website in history of webview
{
    pageActuelle()->forward();
}

void FenPrincipale::accueil() //! Load home page of users preferences
{
    pageActuelle()->load(QUrl(settings->value("home").toString()));
}

void FenPrincipale::stop() //! stop the loading of webpages
{
    pageActuelle()->stop();
}

void FenPrincipale::actualiser() //! reload the actual page in webview
{
    pageActuelle()->reload();
}

void FenPrincipale::montrerMarquePage() //! show bookmarks window.
{
    bookmarksDialog book;
    book.exec();
}


void FenPrincipale::aPropos() //! show the about box of the app
{
    Apropos *aproposWind = new Apropos;
    aproposWind->show();

    //QMessageBox::information(this, tr("A propos..."), tr("Base sur zNavigo du site du zero..<br />Les images de ce programme ont ete creees par <a href=\"http://www.everaldo.com\">Everaldo Coelho</a>"));
}

void FenPrincipale::nouvelOnglet() //! new tab in window
{
    int indexNouvelOnglet = onglets->addTab(creerOngletPageWeb(), tr("(Nouvelle page)"));
    onglets->setCurrentIndex(indexNouvelOnglet);
    pageActuelle()->setContextMenuPolicy(Qt::CustomContextMenu);

    champAdresse->setText("");
    champAdresse->setFocus(Qt::OtherFocusReason);
}

void FenPrincipale::fermerOnglet() //!close tab in window
{
    //! On ne doit pas fermer le dernier onglet, sinon le QTabWidget ne marche plus
    if (onglets->count() > 1)
    {
        onglets->removeTab(onglets->currentIndex());
    }
    else
    {
       QMessageBox::critical(this, tr("Erreur"), tr("Il faut au moins un onglet !"));
    }
}

void FenPrincipale::chargerPage() //! load page
{
    QString url = champAdresse->text();

    //! On rajoute le "http://" s'il n'est pas deja dans l'adresse
    if (url.left(7) != "http://" && url.left(8) != "https://")
    {
        url = "http://" + url;
        champAdresse->setText(url);
    }


    pageActuelle()->load(QUrl(url));


}

void FenPrincipale::changementOnglet(int index) //! change tab
{
    changementTitre(pageActuelle()->title());
    changementUrl(pageActuelle()->url());
}


void FenPrincipale::changementTitre(const QString & titreComplet) //! change tab title with title of webview
{
    QString titreCourt = titreComplet;

    //! On tronque le titre pour eviter des onglets trop larges
    if (titreComplet.size() > 40)
    {
        titreCourt = titreComplet.left(40) + "...";
    }

    setWindowTitle(titreCourt + " - " + tr("zNavigator"));
    onglets->setTabText(onglets->currentIndex(), titreCourt);
}

void FenPrincipale::changementUrl(const QUrl & url) //! load urls of url Field.
{
    if (url.toString() != tr("html/page_blanche.html"))
    {
        champAdresse->setText(url.toString());
    }

}

void FenPrincipale::chargementDebut() //! set the progress bar visible at start of downlaod webpage in webview.
{
    progression->setVisible(true);
}

void FenPrincipale::chargementEnCours(int pourcentage) //! the download progress.
{
    progression->setValue(pourcentage);
}

void FenPrincipale::chargementTermine(bool ok) //! hide the progress bar at the end of download of webpage.
{
    progression->setVisible(false);
    statusBar()->showMessage(tr("Ready"), 2000);

}



//! Autres methodes


QWidget *FenPrincipale::creerOngletPageWeb(QString url) //! Create widget whith empy page
{


    QWidget *pageOnglet = new QWidget;
    QWebView *pageWeb = new QWebView;

    webSettings = pageWeb->settings();
    webSettings->setAttribute(QWebSettings::PluginsEnabled, true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(pageWeb);
    pageOnglet->setLayout(layout);

    if (url.isEmpty())
    {
        pageWeb->load(QUrl(tr(":html/page_blanche.html")));
    }
    else
    {
        if (url.left(7) != "http://")
        {
            url = "http://" + url;
        }
       // pageWeb()->page()->networkAccessManager()->setCookieJar(new CookieJar(this));
        pageWeb->load(QUrl(url));
    }





    //! Gestion des signaux envoyes par la page web
    connect(pageWeb, SIGNAL(titleChanged(QString)), this, SLOT(changementTitre(QString)));
    connect(pageWeb, SIGNAL(urlChanged(QUrl)), this, SLOT(changementUrl(QUrl)));
    connect(pageWeb, SIGNAL(loadStarted()), this, SLOT(chargementDebut()));
    connect(pageWeb, SIGNAL(loadProgress(int)), this, SLOT(chargementEnCours(int)));
    connect(pageWeb, SIGNAL(loadFinished(bool)), this, SLOT(chargementTermine(bool)));

    return pageOnglet;
}

//! Ouverture de la boite de dialogue de preferences

void FenPrincipale::lancerPreference()
{
    PrefDialog myPrefWindow;
    myPrefWindow.exec();
}

//! fonction pour le champ de recherche dans la barre d'outils.

void FenPrincipale::rechercherGoogle()
{
    QString rechGoog = champGoogle->text();

    int motRech = settings->value("Moteur_de_recherche_index").toInt();

    switch(motRech)
    {
    case 0:
        pageActuelle()->load(QUrl("http://www.google.com/search?q=" + rechGoog));
        break;
    case 1:
        pageActuelle()->load(QUrl("http://fr.search.yahoo.com/search?p=" + rechGoog));
        break;
    case 2:
        pageActuelle()->load(QUrl("http://www.bing.com/search?q=" + rechGoog));
        break;
    case 3:
        pageActuelle()->load(QUrl("http://www.altavista/search?q=" + rechGoog));
    }
}


void FenPrincipale::showHelp()
{
    HelpBrowser::showPage("index.html");
}

void FenPrincipale::plusGrandSlot()
{
    pageActuelle()->setZoomFactor(+1.5);
}

void FenPrincipale::plusPetitSlot()
{
    pageActuelle()->setZoomFactor(+1);
}


//! ouverture de la boite de dialogue de l'historique

void FenPrincipale::montrerHistorique()
{
    Historique histor;



    histor.exec();
}

QWebView *FenPrincipale::pageActuelle()
{


    return onglets->currentWidget()->findChild<QWebView *>();
}


