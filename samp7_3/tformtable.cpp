#include "tformtable.h"
#include "ui_tformtable.h"

#include <TDialogSize.h>

TFormTable::TFormTable(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TFormTable)
{
    ui->setupUi(this);
    m_model = new QStandardItemModel(12, 6, this); // 数据模型
    m_selection = new QItemSelectionModel(m_model, this); // 选择模型
    ui->tableView->setModel(m_model); // 设置数据模型
    ui->tableView->setSelectionModel(m_selection); // 设置选择模型
}

TFormTable::~TFormTable()
{
    delete ui;
}

void TFormTable::on_actSize_triggered()
{
    // “定义表格大小”按钮
    TDialogSize *dlgTableSize = new TDialogSize(this);
    dlgTableSize->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    dlgTableSize->setRowColumn(m_model->rowCount(), m_model->columnCount());
    int ret = dlgTableSize->exec(); // 以模态方式显示对话框
    if (ret == QDialog::Accepted)
    {
        int cols = dlgTableSize->columnCount();
        m_model->setColumnCount(cols);
        int rows = dlgTableSize->rowCount();
        m_model->setRowCount(rows);
    }
    delete dlgTableSize; // 删除对话框
}


void TFormTable::on_actSetHeader_triggered()
{
    // “设置表头”按钮
    if (dlgSetHeaders == nullptr)
        dlgSetHeaders = new TDialogHeaders(this);
    if (dlgSetHeaders->headerList().count() != m_model->columnCount())
    {
        QStringList strList;
        for (int i = 0; i < m_model->columnCount(); i++) // 获取现有的表头标题
            strList.append(m_model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
        dlgSetHeaders->setHeaderList(strList); // 用于对话框初始化显示
    }

    int ret = dlgSetHeaders->exec(); // 以模态方式显示对话框
    if (ret == QDialog::Accepted)
    {
        QStringList strList = dlgSetHeaders->headerList();
        m_model->setHorizontalHeaderLabels(strList);
    }
}

