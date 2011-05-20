#include "rsswidget.h"

RSSWidget::RSSWidget(QWidget *parent) :
    QWidget(parent)
{
    rssTreeWidget = new QTreeWidget;


    QVBoxLayout *layoutContenuDock = new QVBoxLayout;
    QHBoxLayout *layoutaddRSS = new QHBoxLayout;

    QLineEdit *rssAdress = new QLineEdit;
    rssAdress->setText("Inserez ici lien rss");
    QPushButton *ajouterRSS = new QPushButton("Ajouter RSS");

    layoutaddRSS->addWidget(rssAdress);
    layoutaddRSS->addWidget(ajouterRSS);

    layoutContenuDock->addLayout(layoutaddRSS);
    layoutContenuDock->addWidget(rssTreeWidget);

    setLayout(layoutContenuDock);
}
