#include "historique.h"
#include "FenPrincipale.h"
#include "ui_historique.h"

#include <QWebHistory>
#include <QWebHistoryItem>

Historique::Historique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Historique)
{
    ui->setupUi(this);

    setWindowTitle(tr("Historique"));

    FenPrincipale fenacc;

    QString historItem;

    historItem = fenacc.monHistorique->currentItem().url().toString();


}

Historique::~Historique()
{
    delete ui;
}
