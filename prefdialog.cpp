#include <QMessageBox>


#include "prefdialog.h"
#include "ui_prefdialog.h"

//! Construction of PrefDialog, this dialog write settingns in file


PrefDialog::PrefDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrefDialog)
{
    ui->setupUi(this);

    settings = new QSettings("ZNavigo", "ZNavigo");
    ui->lineEdit->setText(settings->value("home").toString());
    ui->MotRechCombo->setCurrentIndex(settings->value("Moteur_de_recherche_index").toInt());

    setWindowTitle(tr("Preferences"));

}

PrefDialog::~PrefDialog() //! Destructeur prefDialog
{
    delete ui;
}

//! on_buttonBox_accepted(), write userpreferences in settings files.
//! >Moteur_de_Recherche, string of combo "MotRechCombo"
//! >Moteur_de_recherche_index, integer of combo "MotRechCombo"

void PrefDialog::on_buttonBox_accepted()
{
    QString homeString(ui->lineEdit->text());

    settings->setValue("home", homeString);
    settings->setValue("Moteur_de_recherche", ui->MotRechCombo->currentText());
    settings->setValue("Moteur_de_recherche_index", ui->MotRechCombo->currentIndex());


}

void PrefDialog::on_buttonBox_rejected()
{

}
