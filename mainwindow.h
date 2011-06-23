#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <string>
#include "bio_cst.h"
#include "addspeciesdialog.h"
#include "inhdialog.h"
#include "complexdialog.h"
#include "synthdialog.h"
#include "systemdialog.h"

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QDialog *dia;

private slots:
    void on_commandLinkButton_clicked();
    void on_remove_reactions_clicked();
    void on_add_reactions_clicked();
    void on_modify_species_clicked();
    void on_add_species_clicked();
    void on_remove_species_clicked();
    void requestFromAddSpeciesDia(string name, bool initial_value);
    void requestFromInhDia(QString name, QString inhibited, QString inhibitor);
    void requestFromCplxDia(QString name, QStringList species_to_complex, QString result);
    void requestFromSynthDia(QString name, QStringList activators, QString result, QStringList repressors);
    void requestFromSystemDia(QString name, QStringList reactions);

public slots:
    void speciesAddingResult(bool res, string name, bool ini_val);
    void speciesRemovingResult(bool res,string name);
    void speciesModifiingResult(bool res,string name, bool initial_value);
    void reactionAddingResult(bool res, QString name, int type, QStringList speciesin, QString speciesout = QString(), QStringList speciesoptional = QStringList());
    void reactionRemovingResult(bool res, string name);
    void systemCreationResult(bool res, QString name);

signals:
    void addSpeciesRequestFromUi(string name, bool initial_value);
    void removeSpeciesRequestFromUi(string name);
    void modifySpeciesRequestFromUi(string modif_name,bool initial_value);
    void addReactionRequestFromUi(QString name, int type, QStringList speciesin, QString speciesout = QString(), QStringList speciesoptional = QStringList());
    void removeReactionRequestFromUi(string name);
    void createSystemRequestFromUi(QString name, QStringList sreactions);
};

#endif // MAINWINDOW_H
