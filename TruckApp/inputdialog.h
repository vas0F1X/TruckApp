#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr);
    ~InputDialog();

private slots:
    void accept() override;

private:
    QLineEdit *truckCapacityLineEdit;
    QLineEdit *wasteTruckConsumptionLineEdit;
    QLineEdit *idleFuelLineEdit;
    QLineEdit *warmUpTimeLineEdit;
    QComboBox *fuelTypeComboBox;
    QLineEdit *populationLineEdit;
    QLineEdit *accumulationNormLineEdit;
    QComboBox *settlementTypeComboBox;
    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif // INPUTDIALOG_H
