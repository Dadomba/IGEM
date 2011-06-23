#ifndef SYNTHDIALOG_H
#define SYNTHDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class synthDialog;
}

class synthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit synthDialog(QWidget *parent = 0);
    synthDialog(QStringList species_names, QWidget *parent = 0);
    ~synthDialog();

private:
    Ui::synthDialog *ui;

private slots:
    void on_button_cancel_clicked();
    void on_button_add_reaction_clicked();
    void on_button_removeRepressors_clicked();
    void on_button_addRepressors_clicked();
    void on_button_removeActivators_clicked();
    void on_button_addActivators_clicked();

signals:
    void addSynthRequestFromDia(QString name, QStringList activators, QString result, QStringList repressors);
};

#endif // SYNTHDIALOG_H
