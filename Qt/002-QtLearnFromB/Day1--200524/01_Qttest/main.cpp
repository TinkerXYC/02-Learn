#include "widget.h"

//QApplication应用程序类
//Qt头文件没有.h
//头文件和类名一样
#include <QApplication>

int main(int argc, char *argv[])
{
    //有且仅有一个应用程序类的对象
    QApplication a(argc, argv);
    Widget w;
    w.show();
    //让程序一直执行，等待用户操作。等待事件发生
    return a.exec();
}
