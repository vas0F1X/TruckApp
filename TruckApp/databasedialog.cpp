#include "databasedialog.h"
#include <QFormLayout>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

DatabaseDialog::DatabaseDialog(QWidget *parent) :
    QDialog(parent)
{
    QFormLayout *formLayout = new QFormLayout(this);

    fuelTypeComboBox = new QComboBox(this);
    formLayout->addRow(tr("Тип топлива"), fuelTypeComboBox);

    okButton = new QPushButton(tr("ОК"), this);
    cancelButton = new QPushButton(tr("Отмена"), this);
    formLayout->addRow(okButton, cancelButton);

    connect(okButton, &QPushButton::clicked, this, &DatabaseDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &DatabaseDialog::reject);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("trucks.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    populateFuelTypes();
}

DatabaseDialog::~DatabaseDialog() {
    db.close();
}

void DatabaseDialog::populateFuelTypes() {
    QSqlQuery query("SELECT id, name FROM fuel", db);
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        fuelTypeComboBox->addItem(name, id);
    }
}

void DatabaseDialog::accept() {
    // Ваш код для обработки данных
    QDialog::accept();
}
