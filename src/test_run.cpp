#include <iostream>
#include <vector>
#include "cmdata.h"

int main()
{
    std::vector<double> fdt = {1, 2, 3, 4, 5, 6, 7, 8};
    Cmdata mat(4, 2, 0);
    mat.print_Cmdata();
    mat.data_fill(fdt);
    mat.print_Cmdata();
    size_t *size_arr = mat.shape();
    std::cout << "Rows: "
              << size_arr[0]
              << " Cols: "
              << size_arr[1]
              << std::endl;
    std::cout
        << "0, 0 element: "
        << mat.get_element(0, 0)
        << std::endl;
    std::cout << "1, 1 element: "
              << mat.get_element(1, 1)
              << std::endl;

    mat.set_element(0, 0, 9.0);
    mat.print_Cmdata();
    mat.transpose();
    mat.print_Cmdata();
    return 0;
}
