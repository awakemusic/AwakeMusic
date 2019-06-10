#include "text.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

MainWindow* text::tet()
{

    Ui_MainWindow *s = new Ui::MainWindow();
    MainWindow *m = new MainWindow(nullptr);
    s->setupUi(m);

    s->label->setText("wajia");
    s->label_2->setText("xulu");
    return m;
}
