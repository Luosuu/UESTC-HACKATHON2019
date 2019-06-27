#pragma execution_character_set("utf-8")
#ifndef FISHINGWINDOW_H
#define FISHINGWINDOW_H

#include <QWidget>
#include <QPoint>
#include <QLabel>
#include <QSize>
#include <QPushButton>
#include <QPixmap>
#include <QPropertyAnimation>

class FishingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit FishingWindow(QWidget *parent = nullptr);

signals:
	void Close();

public slots:
	void PlayFishAnimation();

private:
	void InitializeUi();
	void InitializeConnect();

private:
	QPushButton *GobackButton, *FishingButton;
};

#endif // FISHINGWINDOW_H