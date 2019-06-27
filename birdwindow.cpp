#include "birdwindow.h"

BirdWindow::BirdWindow(QWidget *parent) : QWidget(parent)
{
	InitializeUi();
	InitializeConnect();
}

void BirdWindow::InitializeUi()
{
	setWindowTitle("养鸟");
	setFixedSize(QSize(1200, 900));


	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), QPixmap(R"(:/bird.jpg)").scaled(size()));
	setPalette(Pal);

	GobackButton = new QPushButton;
	FeedButton = new QPushButton;
	WaterButton = new QPushButton;
	TalkButton = new QPushButton;

	Layout = new QGridLayout(this);
	Layout->addWidget(GobackButton, 0, 0);
	Layout->addWidget(FeedButton, 1, 0);
	Layout->addWidget(WaterButton, 0, 2);
	Layout->addWidget(TalkButton, 1, 2);

	Layout->setColumnStretch(0, 1);
	Layout->setColumnStretch(1, 3);
	Layout->setColumnStretch(2, 1);

	GobackButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	FeedButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	WaterButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	TalkButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	GobackButton->setFlat(true);
	FeedButton->setFlat(true);
	WaterButton->setFlat(true);
	TalkButton->setFlat(true);

	setLayout(Layout);
}

void BirdWindow::InitializeConnect()
{
	connect(GobackButton, &QPushButton::clicked, [this]()
	{
		emit Close();
	});

	connect(WaterButton, &QPushButton::clicked, this, &BirdWindow::AddWater);
	connect(FeedButton, &QPushButton::clicked, this, &BirdWindow::AddFood);
}

void BirdWindow::AddFood()
{
	auto *Food = new QLabel(this);
	Food->setPixmap(QPixmap(R"(:/add_food.png)").scaled(QSize(100, 110)));
	Food->setFixedSize(QSize(100, 110));
	Food->show();

	auto FoodAnimation = new QPropertyAnimation(Food, "pos");
	FoodAnimation->setDuration(1000);
	FoodAnimation->setStartValue(QPoint(700, 300));
	FoodAnimation->setEndValue(QPoint(700, 100));
	FoodAnimation->start(QAbstractAnimation::DeleteWhenStopped);

	connect(FoodAnimation, &QPropertyAnimation::finished, Food, &QLabel::close);
}

void BirdWindow::AddWater()
{
	auto *Water = new QLabel(this);
	Water->setPixmap(QPixmap(R"(:/add_water.png)").scaled(QSize(100, 110)));
	Water->setFixedSize(QSize(100, 110));
	Water->show();

	auto WaterAnimation = new QPropertyAnimation(Water, "pos");
	WaterAnimation->setDuration(1000);
	WaterAnimation->setStartValue(QPoint(700, 300));
	WaterAnimation->setEndValue(QPoint(700, 100));
	WaterAnimation->start(QAbstractAnimation::DeleteWhenStopped);

	connect(WaterAnimation, &QPropertyAnimation::finished, Water, &QLabel::close);
}
