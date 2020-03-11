#include <iostream>
#include <vector>
#include "cmdata.h"

int main()
{
    std::vector<double> fdt = {1.1, 2.2, 3, 4, 5, 6, 7, 8};
    std::cout << fdt.data() << std::endl;
    Cmdata mat(4, 2, 0.0);
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

    // mat.set_element(0, 0, 9.0);
    mat.get_element(0, 0) = 10;
    mat.print_Cmdata();
    mat.transpose();
    mat.print_Cmdata();

    std::cout << "\n\n";
    std::cout << "Trying Other Constructor" << std::endl;
    std::vector<double> fdt2 = {8, 7, 6, 5, 4, 3, 2, 1};
    Cmdata mat2(fdt2, 4, 2);
    mat2.print_Cmdata();
    mat2 = -mat2;
    mat2.print_Cmdata();

    std::cout << "Trying the slice" << std::endl;
    Cmdata dat_slice = mat2.mat_slice(0, 1, 0, 1);

    mat2.print_data_ref();
    dat_slice.print_Cmdata();
    dat_slice.print_data_ref();

    return 0;
}
