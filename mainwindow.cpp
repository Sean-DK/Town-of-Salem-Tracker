#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QVector"
#include "QString"

QVector<QString> roles = {"Investigator", "Lookout", "Psychic", "Sheriff", "Spy", "Tracker",
                          "Jailor", "Vampire Hunter", "Veteran", "Vigilante", "Bodyguard",
                          "Doctor", "Crusader", "Trapper", "Escort", "Mayor", "Medium",
                          "Retributionist", "Transporter", "Disguiser", "Forger", "Framer",
                          "Hypnotist", "Janitor", "Ambusher", "Godfather", "Mafioso", "Blackmailer",
                          "Consigliere", "Consort", "Executioner", "Jester", "Witch", "Arsonist",
                          "Serial Killer", "Werewolf"};

QVector<QString> lowerRoles = {"investigator", "lookout", "psychic", "sheriff", "spy", "tracker",
                               "jailor", "vampire hunter", "veteran", "vigilante", "bodyguard",
                               "doctor", "crusader", "trapper", "escort", "mayor", "medium",
                               "retributionist", "transporter", "disguiser", "forger", "framer",
                               "hypnotist", "janitor", "ambusher", "godfather", "mafioso", "blackmailer",
                               "consigliere", "consort", "executioner", "jester", "witch", "arsonist",
                               "serial killer", "werewolf"};

QVector<QString> unusedRoles = {"Jailor", "Town Investigative", "Town Investigative", "Town Protective",
                                  "Town Killing", "Town Supportive", "Random Town", "Random Town", "Random Town",
                                  "Godfather", "Mafioso", "Random Mafia", "Random Mafia", "Neutral Evil", "Neutral Killing"};

QVector<QString> usedRoles = {};

QVector<QString> roleCall = {"FILLER", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadList()
{
    ui->listWidget->clear();
    for (int i = 0; i < unusedRoles.size(); i++)
    {
        ui->listWidget->addItem(unusedRoles[i]);
    }
    ui->listWidget->sortItems(Qt::SortOrder::DescendingOrder);
}

void MainWindow::matchString(const QString str, int line, int pos)
{
    for (int i = 0; i < roles.size(); i++)
    {
        if (lowerRoles[i].indexOf(str) == 0 && str != "")
        {
            switch (line)
            {
            case 1:
                ui->lineEdit_1->setText(roles[i]);
                ui->lineEdit_1->setSelection(pos, 99);
                break;
            case 2:
                ui->lineEdit_2->setText(roles[i]);
                ui->lineEdit_2->setSelection(pos, 99);
                break;
            case 3:
                ui->lineEdit_3->setText(roles[i]);
                ui->lineEdit_3->setSelection(pos, 99);
                break;
            case 4:
                ui->lineEdit_4->setText(roles[i]);
                ui->lineEdit_4->setSelection(pos, 99);
                break;
            case 5:
                ui->lineEdit_5->setText(roles[i]);
                ui->lineEdit_5->setSelection(pos, 99);
                break;
            case 6:
                ui->lineEdit_6->setText(roles[i]);
                ui->lineEdit_6->setSelection(pos, 99);
                break;
            case 7:
                ui->lineEdit_7->setText(roles[i]);
                ui->lineEdit_7->setSelection(pos, 99);
                break;
            case 8:
                ui->lineEdit_8->setText(roles[i]);
                ui->lineEdit_8->setSelection(pos, 99);
                break;
            case 9:
                ui->lineEdit_9->setText(roles[i]);
                ui->lineEdit_9->setSelection(pos, 99);
                break;
            case 10:
                ui->lineEdit_10->setText(roles[i]);
                ui->lineEdit_10->setSelection(pos, 99);
                break;
            case 11:
                ui->lineEdit_11->setText(roles[i]);
                ui->lineEdit_11->setSelection(pos, 99);
                break;
            case 12:
                ui->lineEdit_12->setText(roles[i]);
                ui->lineEdit_12->setSelection(pos, 99);
                break;
            case 13:
                ui->lineEdit_13->setText(roles[i]);
                ui->lineEdit_13->setSelection(pos, 99);
                break;
            case 14:
                ui->lineEdit_14->setText(roles[i]);
                ui->lineEdit_14->setSelection(pos, 99);
                break;
            case 15:
                ui->lineEdit_15->setText(roles[i]);
                ui->lineEdit_15->setSelection(pos, 99);
                break;
            }


        }
    }
}

void MainWindow::changeRole(int n, QString str)
{
    if (roleCall[n] == "" && str != "")
    {
        unusedRoles.remove(unusedRoles.indexOf(str));
        usedRoles.push_back(str);
        roleCall[n] = str;
        loadList();
    }
    else if (roleCall[n] != "" && str != "")
    {
        //take current role from used and place in unused
        unusedRoles.push_back(roleCall[n]);
        usedRoles.remove(usedRoles.indexOf(roleCall[n]));
        //take new role from unused and place in used
        usedRoles.push_back(str);
        unusedRoles.remove(unusedRoles.indexOf(str));
        //give new role
        roleCall[n] = str;
        //load list
        loadList();
    }
    else if (roleCall[n] == "" && str == "") {}
    else
    {
        //take current role from used and place in unused
        unusedRoles.push_back(roleCall[n]);
        usedRoles.remove(usedRoles.indexOf(roleCall[n]));
        //give empty role
        roleCall[n] = str;
        //load list
        loadList();
    }
}

void MainWindow::on_lineEdit_1_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_1->cursorPosition();
    matchString(str, 1, pos);
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_2->cursorPosition();
    matchString(str, 2, pos);
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_3->cursorPosition();
    matchString(str, 3, pos);
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_4->cursorPosition();
    matchString(str, 4, pos);
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_5->cursorPosition();
    matchString(str, 5, pos);
}

void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_6->cursorPosition();
    matchString(str, 6, pos);
}

void MainWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_7->cursorPosition();
    matchString(str, 7, pos);
}

void MainWindow::on_lineEdit_8_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_8->cursorPosition();
    matchString(str, 8, pos);
}

void MainWindow::on_lineEdit_9_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_9->cursorPosition();
    matchString(str, 9, pos);
}

void MainWindow::on_lineEdit_10_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_10->cursorPosition();
    matchString(str, 10, pos);
}

void MainWindow::on_lineEdit_11_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_11->cursorPosition();
    matchString(str, 11, pos);
}

void MainWindow::on_lineEdit_12_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_12->cursorPosition();
    matchString(str, 12, pos);
}

void MainWindow::on_lineEdit_13_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_13->cursorPosition();
    matchString(str, 13, pos);
}

void MainWindow::on_lineEdit_14_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_14->cursorPosition();
    matchString(str, 14, pos);
}

void MainWindow::on_lineEdit_15_textChanged(const QString &arg1)
{
    QString str = arg1;
    str = str.toLower();
    int pos = ui->lineEdit_15->cursorPosition();
    matchString(str, 15, pos);
}


void MainWindow::on_lineEdit_1_editingFinished()
{
    QString str = ui->lineEdit_1->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(1, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(1, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(1, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(1, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(1, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(1, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(1, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(1, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(1, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(1, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(1, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(1, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(1, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(1, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(1, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(1, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(1, "");
    }
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    QString str = ui->lineEdit_2->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(2, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(2, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(2, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(2, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(2, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(2, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(2, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(2, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(2, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(2, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(2, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(2, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(2, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(2, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(2, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(2, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(2, "");
    }
}

void MainWindow::on_lineEdit_3_editingFinished()
{
    QString str = ui->lineEdit_3->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(3, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(3, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(3, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(3, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(3, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(3, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(3, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(3, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(3, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(3, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(3, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(3, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(3, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(3, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(3, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(3, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(3, "");
    }
}

void MainWindow::on_lineEdit_4_editingFinished()
{
    QString str = ui->lineEdit_4->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(4, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(4, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(4, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(4, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(4, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(4, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(4, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(4, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(4, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(4, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(4, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(4, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(4, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(4, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(4, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(4, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(4, "");
    }
}

void MainWindow::on_lineEdit_5_editingFinished()
{
    QString str = ui->lineEdit_5->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(5, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(5, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(5, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(5, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(5, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(5, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(5, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(5, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(5, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(5, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(5, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(5, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(5, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(5, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(5, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(5, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(5, "");
    }
}

void MainWindow::on_lineEdit_6_editingFinished()
{
    QString str = ui->lineEdit_6->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(6, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(6, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(6, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(6, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(6, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(6, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(6, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(6, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(6, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(6, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(6, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(6, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(6, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(6, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(6, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(6, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(6, "");
    }
}

void MainWindow::on_lineEdit_7_editingFinished()
{
    QString str = ui->lineEdit_7->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(7, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(7, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(7, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(7, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(7, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(7, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(7, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(7, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(7, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(7, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(7, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(7, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(7, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(7, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(7, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(7, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(7, "");
    }
}

void MainWindow::on_lineEdit_8_editingFinished()
{
    QString str = ui->lineEdit_8->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(8, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(8, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(8, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(8, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(8, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(8, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(8, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(8, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(8, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(8, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(8, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(8, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(8, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(8, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(8, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(8, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(8, "");
    }
}

void MainWindow::on_lineEdit_9_editingFinished()
{
    QString str = ui->lineEdit_9->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(9, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(9, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(9, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(9, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(9, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(9, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(9, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(9, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(9, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(9, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(9, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(9, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(9, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(9, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(9, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(9, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(9, "");
    }
}

void MainWindow::on_lineEdit_10_editingFinished()
{
    QString str = ui->lineEdit_10->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(10, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(10, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(10, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(10, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(10, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(10, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(10, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(10, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(10, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(10, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(10, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(10, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(10, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(10, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(10, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(10, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(10, "");
    }
}

void MainWindow::on_lineEdit_11_editingFinished()
{
    QString str = ui->lineEdit_11->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(11, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(11, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(11, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(11, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(11, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(11, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(11, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(11, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(11, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(11, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(11, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(11, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(11, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(11, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(11, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(11, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(11, "");
    }
}

void MainWindow::on_lineEdit_12_editingFinished()
{
    QString str = ui->lineEdit_12->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(12, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(12, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(12, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(12, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(12, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(12, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(12, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(12, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(12, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(12, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(12, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(12, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(12, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(12, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(12, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(12, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(12, "");
    }
}

void MainWindow::on_lineEdit_13_editingFinished()
{
    QString str = ui->lineEdit_13->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(13, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(13, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(13, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(13, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(13, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(13, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(13, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(13, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(13, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(13, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(13, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(13, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(13, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(13, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(13, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(13, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(13, "");
    }
}

void MainWindow::on_lineEdit_14_editingFinished()
{
    QString str = ui->lineEdit_14->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(14, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(14, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(14, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(14, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(14, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(14, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(14, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(14, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(14, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(14, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(14, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(14, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(14, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(14, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(14, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(14, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(14, "");
    }
}

void MainWindow::on_lineEdit_15_editingFinished()
{
    QString str = ui->lineEdit_15->text().toLower();
    if (str == "investigator" || str == "lookout" || str == "psychic" || str == "sheriff" || str == "spy" || str == "tracker")
    {
        if (unusedRoles.indexOf("Town Investigative") != -1)
        {
            changeRole(15, "Town Investigative");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(15, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Investigative.");
        }
    }
    else if (str == "jailor")
    {
        if (unusedRoles.indexOf("Jailor") != -1)
        {
            changeRole(15, "Jailor");
        }
        else if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(15, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(15, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "vampire hunter" || str == "veteran" || str == "vigilante")
    {
        if (unusedRoles.indexOf("Town Killing") != -1)
        {
            changeRole(15, "Town Killing");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(15, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Killing.");
        }
    }
    else if (str == "bodyguard" || str == "doctor" || str == "crusader" || str == "trapper")
    {
        if (unusedRoles.indexOf("Town Protective") != -1)
        {
            changeRole(15, "Town Protective");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(15, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Protective.");
        }
    }
    else if (str == "escort" || str == "mayor" || str == "medium" || str == "retributionist" || str == "transporter")
    {
        if (unusedRoles.indexOf("Town Supportive") != -1)
        {
            changeRole(15, "Town Supportive");
        }
        else if (unusedRoles.indexOf("Random Town") != -1)
        {
            changeRole(15, "Random Town");
        }
        else
        {
            ui->errorText->setText("Too many Town Supportive.");
        }
    }
    else if (str == "disguiser" || str == "forger" || str == "framer" || str == "hypnotist" || str == "janitor" || str == "blackmailer" ||
             str == "consigliere" || str == "consort")
    {
        if (unusedRoles.indexOf("Random Mafia") != -1)
        {
            changeRole(15, "Random Mafia");
        }
        else
        {
            ui->errorText->setText("Too many Random Mafia.");
        }
    }
    else if (str == "godfather")
    {
        if (unusedRoles.indexOf("Godfather") != -1)
        {
            changeRole(15, "Godfather");
        }
        else
        {
            ui->errorText->setText("Too many Godfather.");
        }
    }
    else if (str == "mafioso")
    {
        if (unusedRoles.indexOf("Mafioso") != -1)
        {
            changeRole(15, "Mafioso");
        }
        else
        {
            ui->errorText->setText("Too many Mafioso.");
        }
    }
    else if (str == "arsonist" || str == "serial killer" || str == "werewolf")
    {
        if (unusedRoles.indexOf("Neutral Killing") != -1)
        {
            changeRole(15, "Neutral Killing");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Killing.");
        }
    }
    else if (str == "executioner" || str == "jester" || str == "witch")
    {
        if (unusedRoles.indexOf("Neutral Evil") != -1)
        {
            changeRole(15, "Neutral Evil");
        }
        else
        {
            ui->errorText->setText("Too many Neutral Evil.");
        }
    }
    else
    {
        changeRole(15, "");
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->errorText->clear();
}
