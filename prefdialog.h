#ifndef PREFDIALOG_H
#define PREFDIALOG_H

#include <QtGui/QDialog>
#include <QSettings>

namespace Ui {
    class PrefDialog;
}

class PrefDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrefDialog(QWidget *parent = 0);
    ~PrefDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PrefDialog *ui;

    QSettings *settings;

};

#endif // PREFDIALOG_H
