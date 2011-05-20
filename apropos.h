#ifndef APROPOS_H
#define APROPOS_H

#include <QtGui>

//! Class Aprops, this window show programmers and other contributers of this program.

class Apropos : public QWidget
{
    Q_OBJECT
public:
    explicit Apropos(QWidget *parent = 0);

signals:

public slots:

private:

    QPushButton *aideButton;
    QPushButton *closeButton;
    QLabel *txte1;
    QLabel *gplLabel;

};

#endif // APROPOS_H
