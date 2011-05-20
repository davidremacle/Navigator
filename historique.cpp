#include "historique.h"
#include "ui_historique.h"

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
