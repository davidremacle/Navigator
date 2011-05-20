#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QtGui/QDialog>
#include <QFileSystemModel>

namespace Ui {
    class Historique;
}

class Historique : public QDialog
{
    Q_OBJECT

public:
    explicit Historique(QWidget *parent = 0);
    ~Historique();

private:
    Ui::Historique *ui;
};

#endif // HISTORIQUE_H
