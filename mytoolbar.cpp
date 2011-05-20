#include "mytoolbar.h"

myToolBar::myToolBar(QWidget * parent  ):QComboBox(parent)
{
    setStyleSheet("QPushButton {text-align:center;color:blue;text-decoration:underline;font-family:arial; background-color:#d4d0c8; }");
    setEditable(true);
    setFrame(false);
    resize(300,size().height());

    te_ = new myQListWidget(this);
    setView(te_);
    setModel(te_->model());
    te_->viewport()->setBackgroundRole(backgroundRole()); //! change the background color of popup list


    bt_ = new QPushButton("clear hisroty",view());
    bt_->setFlat(true);
    bt_->setVisible(false);

    connect(bt_,SIGNAL(clicked(bool)),this,SLOT(clear()));

}

void myToolBar::showPopup ()
{
   QComboBox::showPopup ();
   bt_->setVisible(true);
   QRect qRect(view()->geometry()); //! move button to right-down corner
   int iXpos=qRect.width()-bt_->width();
   int iYpos=qRect.height()-bt_->height();
   bt_->move(iXpos,iYpos);

}
void myToolBar::hidePopup ()
{
   QComboBox::hidePopup ();
    bt_->setVisible(false);
}
