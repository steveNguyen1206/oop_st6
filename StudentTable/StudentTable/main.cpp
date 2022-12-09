#include "Table.h"
#include "Student.h"
#include "IValueConverter.h"
#include "StudentToRowConverter.h"
#include "Object.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>

int main()
{
    std::vector<std::shared_ptr<Object>> data = {
        std::make_shared<Student>("Tran Huu Long", "0909888712", "227 Nguyen Van Cu P4 Q5"),
        std::make_shared<Student>("Cao Duc Tuan", "0773256712", "177 Nguyen Dinh Chieu Q3"),
        std::make_shared<Student>("Le Mai Loan", "0869327617", "17 Tran Phu Q2"),
        std::make_shared<Student>("Dinh Thi Ly", "0999876432", "35 Vo Thi Sau Q1"),
        std::make_shared<Student>("Nguyen Duc Vinh", "0999882725", "15 Vo Van Tan P11 Binh Thanh"),
    };
    std::vector<std::string> headers = {
        "Ho va ten", "SDT", "Dia chi"
    };
    std::vector<int> widths = {
        15, 11, 28
    };
    std::shared_ptr<IValueConverter> converter = std::make_shared<StudentToRowConverter>(widths);
    Table table(headers, widths, data, converter);
    table.display();

}