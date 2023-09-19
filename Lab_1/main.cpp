    #include "widget.h"
    #include <QApplication>
    #include <QHBoxLayout>
    #include <QLabel>
    #include <QLineEdit>
    #include <QPushButton>

    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
        Widget w;
        w.resize(320, 240); // Змiна розмiру головного вiджету
        w.setWindowTitle("Main window"); // Додавання заголовку iз текстом

        QLabel label("Fill me:"); // Створення QLabel
        QPushButton button("Save"); // Створення QPushButton
        QLineEdit textedit; // Створення QLineEdit

        QHBoxLayout layout(&w); //Створення горизонтального розташування
        layout.addWidget(&label);
        layout.addWidget(&textedit);
        layout.addWidget(&button);
        w.show();

        QPushButton *anotherButton  = new QPushButton("Ok", &w);
        anotherButton ->move(110, 160);
        anotherButton ->show();

        return a.exec();
    }
