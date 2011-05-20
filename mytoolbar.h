//mytoolbar.h
#ifndef MYTOOLBAR_
#include <QComboBox>
#include <QPushButton>
#include <QListWidget>

class myQListWidget:public QListWidget
{
public:
    myQListWidget(QWidget * parent = 0 ):QListWidget(parent)
    {
        setViewportMargins(0,0,0,30); //! we'll put "clear history" button in the bottom margin
    }
};
class myToolBar:public QComboBox
{
public:
    myToolBar(QWidget * parent = 0);
    void showPopup ();
    void hidePopup ();
private:
    QPushButton *bt_;
    myQListWidget *te_;

};

#endif
