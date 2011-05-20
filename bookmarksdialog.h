#ifndef BOOKMARKSDIALOG_H
#define BOOKMARKSDIALOG_H

/*!
  * \file bookmarksdialog.h
  * \brief Navigateur web ecrit en C++ avec Qt
  * \author David Remacle
  * \version 0.1
  *
  * Cette classe definit l'interface graphique pour la boite
  * de dialogue pour gerer les bookmarks de notre navigateur web
  *
  */


#include <QtGui/QDialog>

#include <QStandardItemModel>
#include <QMessageBox>

namespace Ui {
    class bookmarksDialog;
}

//! Class for the bookmarks dialog

class bookmarksDialog : public QDialog
{
    Q_OBJECT

public:
    explicit bookmarksDialog(QWidget *parent = 0);
    ~bookmarksDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::bookmarksDialog *ui; //! ui

    QStandardItemModel *bookModel; //! Model for Bookmarks
};

#endif // BOOKMARKSDIALOG_H
