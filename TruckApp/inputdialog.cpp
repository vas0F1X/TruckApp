#include "inputdialog.h"
#include <QFormLayout>
#include <QMessageBox>

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent)
{
    QFormLayout *formLayout = new QFormLayout(this);

    truckCapacityLineEdit = new QLineEdit(this);
    wasteTruckConsumptionLineEdit = new QLineEdit(this);
    idleFuelLineEdit = new QLineEdit(this);
    warmUpTimeLineEdit = new QLineEdit(this);
    fuelTypeComboBox = new QComboBox(this);
    populationLineEdit = new QLineEdit(this);
    accumulationNormLineEdit = new QLineEdit(this);
    settlementTypeComboBox = new QComboBox(this);

    formLayout->addRow(tr("Грузоподъемность"), truckCapacityLineEdit);
    formLayout->addRow(tr("Расход топлива"), wasteTruckConsumptionLineEdit);
    formLayout->addRow(tr("Расход на холостом ходу"), idleFuelLineEdit);
    formLayout->addRow(tr("Время прогрева"), warmUpTimeLineEdit);
    formLayout->addRow(tr("Тип топлива"), fuelTypeComboBox);
    formLayout->addRow(tr("Число жителей"), populationLineEdit);
    formLayout->addRow(tr("Норма накопления"), accumulationNormLineEdit);
    formLayout->addRow(tr("Тип поселения"), settlementTypeComboBox);

    fuelTypeComboBox->addItem(tr("Бензин"));
    fuelTypeComboBox->addItem(tr("Дизель"));

    settlementTypeComboBox->addItem(tr("Город"));
    settlementTypeComboBox->addItem(tr("Село"));

    okButton = new QPushButton(tr("ОК"), this);
    cancelButton = new QPushButton(tr("Отмена"), this);
    formLayout->addRow(okButton, cancelButton);

    connect(okButton, &QPushButton::clicked, this, &InputDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &InputDialog::reject);
}

InputDialog::~InputDialog() {
}

void InputDialog::accept() {
    // Ваш код для обработки данных
    // Пример:
    bool ok;
    int truckCapacity = truckCapacityLineEdit->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка ввода", "Некорректное значение для грузоподъемности");
        return;
    }

    // Другие проверки и операции

    QDialog::accept();
}
