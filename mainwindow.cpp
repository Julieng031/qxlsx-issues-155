#include "mainwindow.h"
#include "QXlsx/header/xlsxconditionalformatting.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QXlsx::Document doc;
    writeDoc(doc);
    doc.saveAs("test.xlsx");
}

MainWindow::~MainWindow()
{
}

void MainWindow::writeDoc(QXlsx::Document &doc) {

    doc.addSheet("test");

    QXlsx::ConditionalFormatting cf1;
    QXlsx::Format fmt1;
    fmt1.setFontColor(Qt::green);
    fmt1.setBorderStyle(QXlsx::Format::BorderDashed);
    cf1.addHighlightCellsRule(QXlsx::ConditionalFormatting::Highlight_LessThan, "40", fmt1);
    cf1.addRange("A1");
    doc.addConditionalFormatting(cf1);

    doc.write("A1", 4);
}
