#include "MainWidget.h"
#include "ui_MainWidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::MainWidget)
{
    m_ui->setupUi(this);
    SetupUi();
}

MainWidget::~MainWidget()
{
    delete m_ui;
}

void MainWidget::SetupUi()
{
    m_turn_order_widget = new TurnOrderWidget();
    m_npc_generator_widget = new NPCGeneratorWidget();
    connect(m_ui->buttonTurnOrderList, &QPushButton::clicked, this, &MainWidget::onTurnOrder);
    connect(m_ui->buttonNPCGenerator, &QPushButton::clicked, this, &MainWidget::onNPCGenerator);
}

void MainWidget::onTurnOrder()
{
    m_turn_order_widget->show();
    return;
}

void MainWidget::onNPCGenerator()
{
    m_npc_generator_widget->show();
    return;
}
