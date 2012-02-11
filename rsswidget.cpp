#include "rsswidget.h"

RSSWidget::RSSWidget(QWidget *parent) :
    QWidget(parent)
{
    rssTreeWidget = new QTreeWidget;




    QVBoxLayout *layoutContenuDock = new QVBoxLayout;
    QHBoxLayout *layoutaddRSS = new QHBoxLayout;

    rssAdress = new QLineEdit;
    rssAdress->setText("Inserez ici lien rss");
    QPushButton *ajouterRSS = new QPushButton("Ajouter RSS");

    layoutaddRSS->addWidget(rssAdress);
    layoutaddRSS->addWidget(ajouterRSS);

    layoutContenuDock->addLayout(layoutaddRSS);
    layoutContenuDock->addWidget(rssTreeWidget);

    connect(ajouterRSS, SIGNAL(clicked()), this, SLOT(getrss()));



    setLayout(layoutContenuDock);
}
void RSSWidget::getrss()
{
    QString url = rssAdress->text();

    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, url);
    rssTreeWidget->insertTopLevelItem(0, item);
}
