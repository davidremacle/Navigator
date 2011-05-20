/*!
  * \file bookmarksdialog.cpp
  * \brief Navigateur web ecrit en C++ avec Qt
  * \author David Remacle
  * \version 0.1
  *
  * Boite de dialogue pour gerer les bookmarks de l'application.
  *
  */


#include "bookmarksdialog.h"
#include "ui_bookmarksdialog.h"

#include "FenPrincipale.h"

//! Bookmark Dialog.cpp is the definition of the bookmark dialog of ZNavigo

bookmarksDialog::bookmarksDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookmarksDialog)
{
    ui->setupUi(this);

    ui->bookmarksView->header()->hide();



    setWindowTitle(tr("Marques page"));

    bookModel = new QStandardItemModel;

    QStandardItem *item = new QStandardItem("Menu");
    bookModel->appendRow(item);
    item->appendRow(new QStandardItem("http://www.google.com/"));
    item->appendRow(new QStandardItem("htt://www.yahoo.com/"));

    QStandardItem *jeuxItem = new QStandardItem("Jeux");
    bookModel->appendRow(jeuxItem);
    jeuxItem->appendRow(new QStandardItem("http://www.popotamo.com/"));



    ui->bookmarksView->setModel(bookModel);


}

bookmarksDialog::~bookmarksDialog() //! Destructor of BookmarksDialog
{
    delete ui;
}

void bookmarksDialog::on_buttonBox_accepted() //! Ok Button of the dialog
{
    QItemSelectionModel *selection = ui->bookmarksView->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = bookModel->data(indexElementSelectionne, Qt::DisplayRole);
    QMessageBox::information(this, "Element selectionne", elementSelectionne.toString());



}
