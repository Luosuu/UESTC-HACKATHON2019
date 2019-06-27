#include "flowershopwindow.h"

FlowershopWindow::FlowershopWindow(QWidget *parent) : QWidget(parent)
{
	InitializeUi();
	InitializeConnect();
}

void FlowershopWindow::InitializeUi()
{
	setWindowTitle("ил╣Й");
	setFixedSize(QSize(800, 600));

	Layout = new QGridLayout(this);
	setLayout(Layout);

	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), QPixmap(R"(:/shop.jpg)").scaled(size()));
	setPalette(Pal);

	FlowerLabel = new QLabel;
	FlowerLabel->setPixmap(QPixmap(R"(:/flower1.jpg)"));
	Layout->addWidget(FlowerLabel);
}

void FlowershopWindow::InitializeConnect()
{
}
