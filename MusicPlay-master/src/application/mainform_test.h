#ifndef MAINFORM_TEST_H
#define MAINFORM_TEST_H

#include <QMainWindow>
#include <QLabel>
class Mainform_test : public QMainWindow
{
    Q_OBJECT
public:
    explicit Mainform_test(QWidget* parent = 0);
signals:

public slots:
private:
    QLabel *tipLbl;
};

#endif // MAINFORM_TEST_H
