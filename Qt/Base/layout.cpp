/*QHBoxLayout  Horizontal
  QVBoxLayout  Ve
  QGridLayout  网格
*/
#include <QPushButton>
#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window=new QWidget;
    window->setWindowTitle("Enter Your Age");

    QSpinBox *spinbox=new QSpinBox;
    QSlider *slider=new QSlider(Qt::Horizontal);
    spinbox->setRange(0,130);
    slider->setRange(0,130);
    QPushButton *button=new QPushButton("AlwaysCoding!");


    QObject::connect(spinbox,SIGNAL(valueChanged(int)),
                     slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)),
                     spinbox,SLOT(setValue(int)));
    QObject::connect(button,SIGNAL(clicked()),
                     &app,SLOT(quit()));

    spinbox->setValue(35);

    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(spinbox);
    layout->addWidget(slider);
    layout->addWidget(button);
    window->setLayout(layout);

    window->show();

    return app.exec();
}
