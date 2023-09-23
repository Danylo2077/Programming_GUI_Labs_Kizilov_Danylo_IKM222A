#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // Головний вертикальний контейнер для розміщення груп радіокнопок
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Встановлення назви головного вікна
    setWindowTitle("Currency Converter");

    // Налаштування розмірів вікна
    setFixedSize(450, 400);


    // Створення віджетів
    labelResult = new QLabel("Result:", this);
    lineEditAmount = new QLineEdit(this);
    buttonConvert = new QPushButton("Convert", this);
    buttonClear = new QPushButton("Clear", this);
    comboBoxFrom = new QComboBox(this);
    comboBoxTo = new QComboBox(this);
    doubleSpinBoxRate = new QDoubleSpinBox(this);
    checkBoxInvert = new QCheckBox("Invert Colors", this);

    //Позиція для QCheckBox
    int checkBoxInvertY = 50;
    checkBoxInvert->move(20, checkBoxInvertY);

    //Позиція для QLineEdit
    int lineEditAmountY = 150;
    lineEditAmount->move(20, lineEditAmountY);

    //Позиція для QComboBoxFrom
    int comboBoxFromY = 150;
    comboBoxFrom->move(121, comboBoxFromY);

    //Позиція для QComboBoxTo
    int comboBoxToY = 150;
    comboBoxTo->move(330, comboBoxToY);

     //Позиція для QDoubleSpinBox
    int doubleSpinBoxRateY = 100;
    doubleSpinBoxRate->move(20, doubleSpinBoxRateY);

   //Позиція для QLabel
    int labelResultY = 150;
    labelResult->move(230, labelResultY);

    // Встановлення рамки для QLabel
    labelResult->setFrameShape(QFrame::Box);
    labelResult->setFrameShadow(QFrame::Sunken);

    // Видалення рамки фону
    labelResult->setAutoFillBackground(false);


    // Позиція для кнопки Convert
    int convertButtonY = 250;
    buttonConvert->move(20, convertButtonY);

    // Позиція для кнопки Clear
    int clearButtonY = 250;
    buttonClear->move(120, clearButtonY);


    // Група для RadioButton колір тексту
    QGroupBox *textColorGroup = new QGroupBox("Text Color", this);
    QRadioButton *textOption1 = new QRadioButton("Red", textColorGroup);
    QRadioButton *textOption2 = new QRadioButton("White", textColorGroup);
    QRadioButton *textOption3 = new QRadioButton("Pink", textColorGroup);

    // Група для RadioButton колір фону
    QGroupBox *backgroundColorGroup = new QGroupBox("Background Color", this);
    QRadioButton *backgroundOption1 = new QRadioButton("Black", backgroundColorGroup);
    QRadioButton *backgroundOption2 = new QRadioButton("Grey", backgroundColorGroup);
    QRadioButton *backgroundOption3 = new QRadioButton("Blue", backgroundColorGroup);


     // Створення та заповнення вертикальної групи textColor
    QVBoxLayout *textColorLayout = new QVBoxLayout;
    textColorLayout->addWidget(textOption1);
    textColorLayout->addWidget(textOption2);
    textColorLayout->addWidget(textOption3);

    // Додавання радіокнопок до групи textColor
    textColorGroup->setLayout(new QVBoxLayout);
    textColorGroup->layout()->addWidget(textOption1);
    textColorGroup->layout()->addWidget(textOption2);
    textColorGroup->layout()->addWidget(textOption3);

    // Додавання груп до головного контейнера
    mainLayout->addWidget(textColorGroup);

    // Створення та заповнення вертикальної групи backgroundColor
    QVBoxLayout *backgroundColorLayout = new QVBoxLayout;
    backgroundColorLayout->addWidget(backgroundOption1);
    backgroundColorLayout->addWidget(backgroundOption2);
    backgroundColorLayout->addWidget(backgroundOption3);

    // Додавання радіокнопок до групи backgroundColor
    backgroundColorGroup->setLayout(new QVBoxLayout);
    backgroundColorGroup->layout()->addWidget(backgroundOption1);
    backgroundColorGroup->layout()->addWidget(backgroundOption2);
    backgroundColorGroup->layout()->addWidget(backgroundOption3);

    // Додавання груп до головного контейнера
    mainLayout->addWidget(backgroundColorGroup);

    // Створення горизонтального контейнера для груп радіокнопок
    QHBoxLayout *groupsLayout = new QHBoxLayout;

    // Визначення розміру і положення груп
    textColorGroup->setFixedSize(200, 100);  // Встановлюємо ширину і висоту для групи колір тексту
    backgroundColorGroup->setFixedSize(200, 100);  // Встановлюємо ширину і висоту для групи колір фону

    // Додавання груп до горизонтального контейнера груп
    groupsLayout->addWidget(textColorGroup);
    groupsLayout->addWidget(backgroundColorGroup);

    // Вирівнюємо горизонтальний контейнер груп вліво і внизу вікна
    groupsLayout->setAlignment(Qt::AlignLeft | Qt::AlignBottom);

    // Встановлюємо відступи для контейнера groupsLayout
    groupsLayout->setContentsMargins(10, 0, 0, 0); // Лівий відступ 10 пікселів

    // Додаємо горизонтальний контейнер груп до головного горизонтального контейнера
    mainLayout->addLayout(groupsLayout);


    // Підключення сигналів і слотів для кнопок Convert і Clear
    connect(buttonConvert, &QPushButton::clicked, this, &Widget::convertCurrency);
    connect(buttonClear, &QPushButton::clicked, this, &Widget::clearFields);


    // Встановлення початкових значень для QDoubleSpinBox і QComboBox
    doubleSpinBoxRate->setValue(0.00); // Початковий курс
    comboBoxFrom->addItem("UAH");
    comboBoxTo->addItem("USD");
    comboBoxFrom->addItem("USD");
    comboBoxTo->addItem("UAH");     // Додаємо валюти
    comboBoxFrom->addItem("UAH");
    comboBoxTo->addItem("EUR");
    comboBoxFrom->addItem("EUR");
    comboBoxTo->addItem("UAH");

    // Налаштування QDoubleSpinBox
    doubleSpinBoxRate->setDecimals(3); // Встановлюємо кількість десяткових розрядів на 3
    doubleSpinBoxRate->setSingleStep(0.01); // Встановлюємо крок зміни значення на 0.01


    connect(checkBoxInvert, &QCheckBox::stateChanged, [=](int state) {
        if (state == Qt::Checked) {
            // Якщо QCheckBox активований, встановлюємо колір тексту з вибраної радіокнопки
            if (textOption1->isChecked()) {
                currentTextColor = Qt::red;
            } else if (textOption2->isChecked()) {
                currentTextColor = Qt::white;
            } else if (textOption3->isChecked()) {
                currentTextColor = Qt::magenta;
            }

            // Встановлюємо колір фону з вибраної радіокнопки
            if (backgroundOption1->isChecked()) {
                currentBackgroundColor = Qt::black;
            } else if (backgroundOption2->isChecked()) {
                currentBackgroundColor = Qt::gray;
            } else if (backgroundOption3->isChecked()) {
                currentBackgroundColor = Qt::blue;
            }
        } else {
            // Якщо QCheckBox не активований, повертаємо початкові кольори
            currentTextColor = Qt::black;
            currentBackgroundColor = Qt::white;
        }

        // Встановлюємо поточний колір тексту і фону для всіх віджетів
        lineEditAmount->setStyleSheet("color: " + currentTextColor.name() + "; background-color: " + currentBackgroundColor.name() + ";");
        labelResult->setStyleSheet("color: " + currentTextColor.name() + "; background-color: " + currentBackgroundColor.name() + ";");
        doubleSpinBoxRate->setStyleSheet("color: " + currentTextColor.name() + "; background-color: " + currentBackgroundColor.name() + ";");
    });


}

// Реалізація слотів
void Widget::convertCurrency()
{
    // Отримуємо значення введеної суми і встановленого курсу
    double amount = lineEditAmount->text().toDouble();
    double rate = doubleSpinBoxRate->value();

    // Отримуємо вибрані валюти
    QString fromCurrency = comboBoxFrom->currentText();
    QString toCurrency = comboBoxTo->currentText();

    // Виконується конвертація і встановлюється результат у QLabel
    double convertedAmount = amount * rate;
    // Встановлюємо результат у QLabel разом із словом "Result:"
    labelResult->setText(QString("Result: %1").arg(QString::number(convertedAmount)));
}

void Widget::clearFields()
{
    lineEditAmount->clear();
    doubleSpinBoxRate->setValue(0.0);
    comboBoxFrom->setCurrentIndex(0);
    comboBoxTo->setCurrentIndex(0);
    labelResult->clear();
}

Widget::~Widget()
{

}


