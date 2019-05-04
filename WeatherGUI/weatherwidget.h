#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H
#include <QtDebug>
#include <QObject>
#include <QObject>
#include <QString>
#include <iostream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <sstream>
#include <QWidget>

namespace Ui {
class WeatherWidget;
}

class WeatherWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherWidget(QWidget *parent = nullptr);
    ~WeatherWidget();
    std::string get_string();
    int get_temp_int();
    std::string get_content_between(std::string bigString, std::string str1, std::string str2);
private:
    Ui::WeatherWidget *ui;
    int tempInt;
    QNetworkAccessManager *mng;
    QNetworkRequest request;
    std::string readBuffer;
private slots:
    void mng_finished(QNetworkReply *reply);
    void on_pushButton_clicked();
    void on_backButton_clicked();
signals:
    void backClicked();
};

#endif // WEATHERWIDGET_H
