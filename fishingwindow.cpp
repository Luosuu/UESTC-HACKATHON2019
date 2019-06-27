#include "fishingwindow.h"

FishingWindow::FishingWindow(QWidget *parent) : QWidget(parent)
{
	InitializeUi();
	InitializeConnect();
}

void FishingWindow::InitializeUi()
{
	setWindowTitle("钓鱼");
	setFixedSize(QSize(1200, 900));

	GobackButton = new QPushButton(this);
	GobackButton->move(width() - 360, height() - 270);
	GobackButton->setFixedSize(QSize(360, 270));
	GobackButton->setFlat(true);

	FishingButton = new QPushButton(this);
	FishingButton->move(width() / 2 + 45, height() / 3 - 50);
	FishingButton->setFixedSize(QSize(390, 240));
	FishingButton->setFlat(true);

	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), QPixmap(R"(:/fishing_pool.jpg)").scaled(size()));
	setPalette(Pal);
}

void FishingWindow::InitializeConnect()
{
	connect(GobackButton, &QPushButton::clicked, [this]()
	{
		emit Close();
	});

	connect(FishingButton, &QPushButton::clicked, this, &FishingWindow::PlayFishAnimation);
}

void FishingWindow::PlayFishAnimation()
{
	auto *FishLabel = new QLabel(this);
	FishLabel->setPixmap(QPixmap(R"(:/fish.png)"));
	FishLabel->show();

	auto *FishingAnimation = new QPropertyAnimation(FishLabel, "pos");
	FishingAnimation->setDuration(1000);
	FishingAnimation->setStartValue(QPoint(width() / 3, height() / 3 + 150));
	FishingAnimation->setEndValue(QPoint(width() / 3, height() / 3 - 200));
	FishingAnimation->start(QAbstractAnimation::DeleteWhenStopped);

	connect(FishingAnimation, &QPropertyAnimation::finished, FishLabel, &QLabel::deleteLater);
}
