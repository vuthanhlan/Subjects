#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "md5.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int a = 1, b, n;

int EuclidMR(int t, int ri){
    int ri1 = 1;
    while(1){
        if(((ri * ri1) - 1) % t == 0)
            return ri1;
        else
            ri1++;
    }
}

int bpvn(int x, int n, int m){
    int p = 1;
    std::stack<int> st;
    while(n != 0){
        st.push(n % 2);
        n = (n - (n % 2)) / 2;
    }
    while(!st.empty()){
        int i = st.top();
        p = p * p;
        p = p % m;
        if(i == 1){
            p = p * x;
            p = p % m;
        }
        st.pop();
    }
    return p;
}

//------------------------------------
//tab1
bool isPrime(int num) {
    // Kiểm tra các trường hợp đặc biệt
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    // Kiểm tra số lẻ
    if (num % 2 == 0) {
        return false;
    }
    // Kiểm tra các số lẻ khác
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void MainWindow::on_NhapP_returnPressed()
{
    QLineEdit *lineEdit = new QLineEdit(this);
    connect(lineEdit, SIGNAL(returnPressed()), this, SLOT(onReturnPressed()));
    int P = ui->NhapP->text().toInt();
    if(isPrime(P)){
        ui->NhapP->setStyleSheet("border: 2px solid green; background-color: white;");
        ui->thongBaoLoiP->setStyleSheet("color: green");
        ui->thongBaoLoiP->setText("Nhập đúng");
    } else {
        ui->NhapP->setStyleSheet("border: 2px solid red; background-color: white;");
        ui->thongBaoLoiP->setStyleSheet("color: red");
        ui->thongBaoLoiP->setText("Nhập sai");
    }
}

void MainWindow::on_NhapQ_returnPressed()
{
    QLineEdit *lineEdit = new QLineEdit(this);
    connect(lineEdit, SIGNAL(returnPressed()), this, SLOT(onReturnPressed()));
    int Q = ui->NhapQ->text().toInt();
    if(isPrime(Q)){
        ui->NhapQ->setStyleSheet("border: 2px solid green; background-color: white;");
        ui->thongBaoLoiQ->setStyleSheet("color: green");
        ui->thongBaoLoiQ->setText("Nhập đúng");
    } else {
        ui->NhapQ->setStyleSheet("border: 2px solid red; background-color: white;");
        ui->thongBaoLoiQ->setStyleSheet("color: red");
        ui->thongBaoLoiQ->setText("Nhập sai");
    }
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int findFiN(int p, int q)
{
    return (p - 1) * (q - 1);
}

int findB(int fiN)
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist1(2, fiN/2), dist2(dist1(rng), fiN - 1);
    int random_number1 = dist1(rng), random_number2 = dist2(rng);
    bool ok = false;
    for (int i = random_number1; i < random_number2; i++)
    {
        if (gcd(i, fiN) == 1)
        {
            ok = true;
            return i;
        }
    }
    if(!ok)
        return findB(fiN);
    return 1;
}

int findA(int fiN)
{
    return EuclidMR(fiN, b);
}


void MainWindow::on_buttonTaoKhoa_clicked()
{
    int P = ui->NhapP->text().toInt(),
        Q = ui->NhapQ->text().toInt(),
        fiN = findFiN(P, Q);

    b = findB(fiN);
    a = findA(fiN);

    n = P * Q;
    ui->showE->setText(QString::number(b));
    ui->showN->setText(QString::number(n));
    ui->showD->setText(QString::number(a));
    ui->showN_2->setText(QString::number(n));
}

void MainWindow::on_buttonExit_clicked()
{
    QApplication::quit();
}

//------------------------------------
//tab2
void MainWindow::on_buttonExit_2_clicked()
{
    QApplication::quit();
}

void MainWindow::on_taiVB_2_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("All files (*.*);; Text File(*.txt);; Word File(*.docx);; Word File(*.doc)")).replace("/", "\\");
    QString text;
    if(!filePath.isEmpty()){
        if(filePath.endsWith(".txt")){
            QFile file(filePath);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
            QTextStream in(&file);
            text = in.readAll();
            file.close();
        } else {
            QAxObject *word = new QAxObject("Word.Application");
            QAxObject *documents = word->querySubObject("Documents");
            QAxObject *document = documents->querySubObject("Open(const QString&)", filePath);
            QAxObject *content = document->querySubObject("Content");

            text = content->dynamicCall("Text()").toString();
            document->dynamicCall("Close()");
            delete content;
            delete document;
            delete documents;
            delete word;
        }
        ui->VBCanKy->setText(text);
    }
}

void MainWindow::on_Ky_clicked()
{
    QString text = ui->VBCanKy->toPlainText();
    std::string textCode = md5::Getmd5String(text.toStdString());
    qDebug() << textCode;
    //Tao chu ky
    QString chuKy = "", result = "";
    for (char ch : textCode)
    {
        int hexCode = std::stoi(std::string(1, ch), nullptr, 16);
        if(hexCode == 0){
            result = "0";
        } else if(a < 0){
            int result_1 = bpvn(hexCode, (-a), n);
            if(result_1 == 0){
                result = "0";
            } else {
                result = QString::number(EuclidMR(n, result_1));
            }
        } else if(a > 0){
            result = QString::number(bpvn(hexCode, a, n));
        } else if (a == 0){
            result = "1";
        }
        chuKy.insert(chuKy.size(), result + " ");
    }
    ui->chuKy->setText(chuKy);
}

void MainWindow::on_luuChuKy_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save File", QDir::homePath(), "Text files (*.txt)");
    if (!fileName.isNull())
    {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream << ui->chuKy->toPlainText();
            file.close();
        }
    }
}

//------------------------------------
//tab3
void MainWindow::on_taiVB_3_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("All files (*.*)")).replace("/", "\\");
    QString text;
    if(!filePath.isEmpty()){
        if(filePath.endsWith(".txt")){
            QFile file(filePath);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
            QTextStream in(&file);
            text = in.readAll();
            file.close();
        } else {
            QAxObject *word = new QAxObject("Word.Application");
            QAxObject *documents = word->querySubObject("Documents");
            QAxObject *document = documents->querySubObject("Open(const QString&)", filePath);
            QAxObject *content = document->querySubObject("Content");
            text = content->dynamicCall("Text()").toString();
            document->dynamicCall("Close()");
            delete content;
            delete document;
            delete documents;
            delete word;
        }
        ui->VBCanXacNhan->setText(text);
    }
}

void MainWindow::on_taiChuKy_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, tr("Open File"), "", tr("All files (*.*)")).replace("/", "\\");
    QString text;
    if(!filePath.isEmpty()){
        if(filePath.endsWith(".txt")){
            QFile file(filePath);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
            QTextStream in(&file);
            text = in.readAll();
            file.close();
        } else {
            QAxObject *word = new QAxObject("Word.Application");
            QAxObject *documents = word->querySubObject("Documents");
            QAxObject *document = documents->querySubObject("Open(const QString&)", filePath);
            QAxObject *content = document->querySubObject("Content");
            text = content->dynamicCall("Text()").toString();
            delete content;
            delete document;
            delete documents;
            delete word;
        }
        ui->XacNhanChuKy->setText(text);
    }
}

void MainWindow::on_xacNhan_clicked()
{
    QString temp_1 = ui->VBCanXacNhan->toPlainText(),
            temp_2 = ui->XacNhanChuKy->toPlainText();
    std::string VBCanXacNhan = temp_1.toStdString(),
                chuKyCanXacNhan = temp_2.toStdString();
    //Kiem tra chu ky
    std::vector<int> numbers;
    std::stringstream ss(chuKyCanXacNhan);
    std::string token;

    while (getline(ss, token, ' ')) {
        int number = std::stoi(token);
        numbers.push_back(number);
    }
    QString hash_1 = "", result = "";
    for (int num : numbers)
    {
        while(num < 0){
            num += n;
        }
        if(b < 0){
            int result_1 = bpvn(num, (-b), n);
            if(result_1 == 0){
                result = "0";
            } else {
                result = QString::number(EuclidMR(n, result_1));
            }
        } else if(b > 0){
            result = QString::number(bpvn(num, b, n));
        } else if (b == 0){
            result = "1";
        }
        std::stringstream stream;
        stream << std::hex << result.toInt();
        std::string hexString = stream.str();
        QString result = QString::fromStdString(hexString);

        hash_1.insert(hash_1.size(), result);
    }
    std::string textCode = md5::Getmd5String(temp_1.toStdString());
    QString hash_2 = QString::fromStdString(textCode);
    qDebug() << hash_1;
    qDebug() << hash_2;
    if(hash_1 == hash_2)
        QMessageBox::information(nullptr, "Thông báo", "Chữ ký chính xác");
    else
        QMessageBox::critical(nullptr, "Thông báo", "Chữ ký không chính xác");

}

void MainWindow::on_Chuyen_clicked()
{
    ui->VBCanXacNhan->setText(ui->VBCanKy->toPlainText());
    ui->XacNhanChuKy->setText(ui->chuKy->toPlainText());
}

