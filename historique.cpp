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


}

Historique::~Historique()
{
    delete ui;
}
