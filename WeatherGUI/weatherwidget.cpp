#include "weatherwidget.h"
#include "ui_weatherwidget.h"

WeatherWidget::WeatherWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherWidget)
{
    ui->setupUi(this);
    mng = new QNetworkAccessManager(this);
        connect(mng, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(mng_finished(QNetworkReply*)));

    request.setUrl(QUrl("https://api.darksky.net/forecast/8e01431507d1197c7bc333122a591b4f/40.6884,-75.2207"));
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");
    mng->get(request);
}

WeatherWidget::~WeatherWidget(){
    delete ui;
}

std::string WeatherWidget::get_content_between(std::string bigString, std::string str1, std::string str2)
{
    std::size_t pos1 = bigString.find(str1) + str1.size();
    std::size_t pos2 = bigString.find(str2) - pos1;
    return bigString.substr(pos1, pos2);
}

int WeatherWidget::get_temp_int()
{
    return tempInt;
}

void WeatherWidget::mng_finished(QNetworkReply *reply)
{
    if(reply->error()){
        qDebug() << reply->errorString(); //if it can't find get a response, display the reason
        return;
    }

    QString myData = reply->readAll(); //read all the data from the page
    std::string data = myData.toStdString();

    std::string time = get_content_between(data, "\"currently\":{\"time\":", ",\"summary");
    std::string summary = get_content_between(data, "summary\":" , ",\"icon"); //add all content between to one string to display
    std::string temp = get_content_between(data, "temperature\":" , ",\"apparentTemperature");
    tempInt = std::stoi(temp);
    std::string rain = get_content_between(data, "precipProbability\":" , ",\"temperature");
    std::string humid = get_content_between(data, "humidity\":" , ",\"pressure");
    std::string wind = get_content_between(data, "windSpeed\":" , ",\"windGust");
    data = "Time (in seconds since January 1, 1970, because that's incredibly useful): " + time + "\nSummary: " + summary + "\nTemperature: " + temp + "\nRain: " + rain + "\nHumidity: " + humid + "\nWind: " + wind;
    //std::cout << data << std::endl;
    QString display = QString::fromStdString(data);
    ui->weatherDisplay->setText(display); //set the data to the text of the textbrowser
}

void WeatherWidget::on_pushButton_clicked() //refreshes the weather data when clicked
{
    //request.setUrl(QUrl("https://weather.com"));
    mng->get(request);
    //rerequests the webpage

}

void WeatherWidget::on_backButton_clicked() //exits the weather gui when clicked
{
    emit backClicked();
    close();
}
