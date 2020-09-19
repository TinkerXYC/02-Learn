#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class mywidget;
}

class mywidget : public QWidget
{
    Q_OBJECT

public:
    explicit mywidget(QWidget *parent = 0);
    ~mywidget();

private:
    Ui::mywidget *ui;
};

#endif // MYWIDGET_H
