#ifndef RSSWIDGET_H
#define RSSWIDGET_H

#include <QtGui>


class RSSWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RSSWidget(QWidget *parent = 0);

signals:

public slots:

public:
    QTreeWidget* rssTreeWidget;

};

#endif // RSSWIDGET_H
