#include <vector>
#include <iostream>
#include "cmdata.h"

Cmdata::Cmdata(int rows, int cols, double init_value = 0)
{
    int elem_len = rows * cols;
    rs = rows;
    cs = cols;
    str1 = 1;
    str2 = cols;
    std::vector<double> data_init(elem_len);
    data = data_init;
}

int *Cmdata::shape()
{
    static int sz_arr[2]{cs, rs};
    return sz_arr;
}

double Cmdata::get_element(int i, int j)
{
    int idx;
    idx = str2 * i;
    idx = idx + (j * str1);
    return data[idx];
}

void Cmdata::print_Cmdata()
{
    for (int i = 0; i < rs; ++i)
    {
        for (int j = 0; j < cs; ++j)
        {
            std::cout << get_element(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

void Cmdata::data_fill(std::vector<double> vd)
{
    if (vd.size() != data.size())
    {
        NULL;
        //throw input_data_wrong_size("vd.size() != data.size()")
    }
    data = vd;
}
