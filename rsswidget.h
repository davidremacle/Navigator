#ifndef RSSWIDGET_H
#define RSSWIDGET_H

#include <QtGui>


class RSSWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RSSWidget(QWidget *parent = 0);

signals:

private slots:
    void getrss();

public slots:

public:
    QTreeWidget* rssTreeWidget;
    QLineEdit *rssAdress;
private:


};

#endif // RSSWIDGET_H
