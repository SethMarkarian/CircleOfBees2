#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include <QtDebug>
#include <QObject>
#include <QObject>
#include <QString>
#include <iostream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <sstream>
#include <ctime>
#include <chrono>

class WeatherData
{
public:
    WeatherData();
    std::string get_string();
    int get_temp_int();
    std::string get_content_between(std::string bigString, std::string str1, std::string str2);
private:
    int tempInt;
    QNetworkAccessManager *mng;
    QNetworkRequest request;
    std::string readBuffer;
private slots:
    void mng_finished(QNetworkReply *reply);
};

#endif // WEATHERDATA_H
