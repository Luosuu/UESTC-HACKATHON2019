#pragma execution_character_set("utf-8")

#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QSizePolicy>
#include <QPushButton>
#include <QLabel>
#include "farmwindow.h"
#include "birdwindow.h"
#include "fishingwindow.h"
#include "housewindow.h"

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = 0);
    ~StartWindow();

private:
	void InitializeUi();
	void InitializeConnect();

private:
	QPushButton *FarmButton, *BirdButton, *FishingButton, *HouseButton;
	QLabel *NpcLabel;

	FarmWindow *_FarmWindow;
	BirdWindow *_BirdWindow;
	FishingWindow *_FishingWindow;
	HouseWindow *_HouseWindow;
};

#endif // STARTWINDOW_H
