#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc,argv);

    QWidget w;
    w.setWindowTitle("放过我先杀ADC");


    QPushButton b;
    b.setText("同意");
    //b.show();
    b.setParent(&w);
    b.move(100,100);
    w.show();

    app.exec();
    return 0;
}
