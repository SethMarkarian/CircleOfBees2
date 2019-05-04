#include "welcomescreen.h"
#include "ui_welcomescreen.h"

WelcomeScreen::WelcomeScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeScreen)
{
    ui->setupUi(this);
    ui->label_2->setText("This interface was made for Circle of Bees, a company which makes a product called hiveChimes. HiveChimes tracks movement of bees in and out of the hive. We have catered to hive owners and artists. Once logged in, a user can receive alerts about when their bees swarmed out of their hive, or were robbed by another colony. The user can also listen to a musical interpretation of the bees moving in and out of the hive.\nSources:\nMusic: University of Iow Electronic Music Studios\n:Weather: Dark Sky API");
}

WelcomeScreen::~WelcomeScreen()
{
    delete ui;
}
