#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QColor>



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLabel *labelResult;
    QLineEdit *lineEditAmount;
    QPushButton *buttonConvert;
    QPushButton *buttonClear;
    QComboBox *comboBoxFrom;
    QComboBox *comboBoxTo;

    QGroupBox *radioGroup;  // Група для RadioButton
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QRadioButton *radioButton4;
    QRadioButton *radioButton5;
    QRadioButton *radioButton6;

    QCheckBox *checkBoxInvert;
    QDoubleSpinBox *doubleSpinBoxRate;


   void convertCurrency();// оголошення слотів
   void clearFields();



   QColor currentTextColor; // змінна, яка зберігає поточний колір тексту
   QColor currentBackgroundColor; //змінна, яка зберігає поточний колір фону

};
#endif // WIDGET_H
