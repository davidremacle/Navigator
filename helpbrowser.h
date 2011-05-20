#ifndef HELPBROWSER_H
#define HELPBROWSER_H

#include <QWidget>

class QPushButton;
class QTextBrowser;

class HelpBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit HelpBrowser(const QString &path, const QString &page, QWidget *parent = 0);

    static void showPage(const QString &page);

signals:

public slots:

    void updateWindowTitle();

 private:
    QTextBrowser *textBrowser;
    QPushButton *homeButton;
    QPushButton *backButton;
    QPushButton *closeButton;
};

#endif // HELPBROWSER_H
