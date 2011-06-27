#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

/*!
  * \file FenPrincipale.h
  * \brief En-tete de la classe pour la fenetre principale
  * \author Mateo21, David Remacle
  * \version 0.1
  *
  * \brief Fichier d'en-tete pour la gestion de la fenetre principale.
  *
  *
  *
  */


#include <QtGui>
#include <QtWebKit>
#include <QSystemTrayIcon>
#include <QWebHistory>
#include <QWebHistoryItem>

#include "rsswidget.h"

#include "mytoolbar.h"

#include "bookmarksdialog.h"
#include "CookieJar.h"

//! Mainwindow of the App

class FenPrincipale : public QMainWindow
{
    /*! \class FenPrincipale
      * \brief Ceci est la classe de la fenetre principale de l'application
      *
      * C'est dans cette classe qu'est definie l'interface de l'application.
      *
      */

    Q_OBJECT

    public:
        FenPrincipale();

    public slots:
        void aurevoir();


    private:
        void creerActions();
        void creerMenus();
        void creerBarresOutils();
        void creerBarreEtat();
        void creerDockRSSWidget();
        QWidget *creerOngletPageWeb(QString url = "");
        QWebView *pageActuelle();

    private slots:
        void precedente();
        void suivante();
        void accueil();
        void stop();
        void actualiser();

        void aPropos();
        void nouvelOnglet();
        void fermerOnglet();
        void chargerPage();
        void changementOnglet(int index);

        void changementTitre(const QString & titreComplet);
        void changementUrl(const QUrl & url);
        void chargementDebut();
        void chargementEnCours(int pourcentage);
        void chargementTermine(bool ok);

        void lancerPreference();

        void montrerHistorique();

        void rechercherGoogle();

        void montrerMarquePage();

        void showHelp();
        void plusGrandSlot();
        void plusPetitSlot();







    private:
        QTabWidget *onglets;

        QSettings *settings;

        QAction *actionNouvelOnglet; /*! <Action pour un nouveau tab dans la fenetre */
        QAction *actionFermerOnglet; /*! <Action pour fermer le tab */
        QAction *actionQuitter; /*! <action pour quitter l'application */
        QAction *actionAPropos; /*! <action pour afficher la fenetre d'infos de l'application */
        QAction *actionAProposQt; /*! <action pour montrer la version de Qt lors de la compilation */
        QAction *actionPrecedente; /*! <action pour acceder a la page precedente de l'historique */
        QAction *actionSuivante; /*! <action pour acceder a la page suivante dans l'historique */
        QAction *actionStop; /*! <action pour arreter le telechargement si trop long */
        QAction *actionActualiser; /*! <action actualiser la page */
        QAction *actionAccueil; /*! <action pour afficher la page d'acceuil predefinie dans les preferences. */
        QAction *actionGo; /*! <action pour acceder a l'url desire */
        QAction *actionPrefWindow; /*! <action pour afficher la boite de dialogue des prerefences utilisateur */
        QAction *actionShowHistorique; /*! <action pour affichier la boite de dialogue de l'historique de navigation */
        QAction *showBookmarks; /*! <action pour montrer les signets */
        QAction *afficherRSS; /*! <afficher les abonnement fils RSS. */
        QAction *montrerAide; /*! <afficher l'aide de l'application */
        QAction *actionPlusGrand;
        QAction *actionPlusPetit;
        QAction *showSource;

        QMenu *MenuHistorique;

        QDockWidget *rssWidget; /*! <Dock Widget for RSSWidget */
        RSSWidget *monRSSWidget; /*! <RSS Widget */



        QLineEdit *champAdresse; /*! <champ ou l'utilisateur indique le site a acceder */
        QProgressBar *progression ; /*! <barre de progression pour le telechargement du site */



        //myToolBar *mybarr;

        QLineEdit *champGoogle;
};



#endif
