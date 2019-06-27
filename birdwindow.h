#pragma execution_character_set("utf-8")
#ifndef BIRDWINDOW_H
#define BIRDWINDOW_H

#include <QWidget>
#include <QSize>
#include <QLabel>
#include <QSizePolicy>
#include <QGridLayout>
#include <QPushButton>
#include <QPropertyAnimation>

class BirdWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BirdWindow(QWidget *parent = nullptr);

signals:
	void Close();

public slots:
	void AddWater();
	void AddFood();

private:
	void InitializeUi();
	void InitializeConnect();

private:
	QGridLayout *Layout;
	QPushButton *GobackButton, *FeedButton, *WaterButton, *TalkButton;
};

#endif // BIRDWINDOW_H