#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QGraphicsScene *scene; // 场景对象
    QLabel *labViewCord; // 用于在状态栏上显示坐标信息
    QLabel *labSceneCord;
    QLabel *labItemCord;
    void iniGraphicsSystem(); // 图形/视图结构初始化
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
private slots:
    void do_mouseMovePoint(QPoint point); // 鼠标移动时处理
    void do_mouseClicked(QPoint point); // 点击鼠标时处理
};
#endif // MAINWINDOW_H
