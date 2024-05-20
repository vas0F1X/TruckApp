#ifndef DATABASEDIALOG_H
#define DATABASEDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QComboBox>
#include <QPushButton>

class DatabaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseDialog(QWidget *parent = nullptr);
    ~DatabaseDialog();

private slots:
    void accept() override;

private:
    QSqlDatabase db;
    QComboBox *fuelTypeComboBox;
    QPushButton *okButton;
    QPushButton *cancelButton;
    void populateFuelTypes();
};

#endif // DATABASEDIALOG_H
