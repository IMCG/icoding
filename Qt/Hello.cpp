//Linux First Qt code
#include <QApplication>
#include <QLabel>

int main(int argc,char *argv[]){
    QApplication app(argc,argv);
    QLabel *label=new QLabel("Hello xuesen!");
    label->show();
    return app.exec();
}
