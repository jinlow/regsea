#include "cmdata.h"

Cmdata::Cmdata(size_t rows, size_t cols, double init_value)
{
    int elem_len = rows * cols;
    rs = rows;
    cs = cols;
    str1 = 1;
    str2 = cols;
    data.assign(elem_len, init_value);
}

Cmdata::Cmdata(std::vector<double> &init_vector, size_t rows, size_t cols)
{
    int elem_len = rows * cols;
    rs = rows;
    cs = cols;
    str1 = 1;
    str2 = cols;
    data.swap(init_vector);
}

// TODO
// This function is static... So right
// now it returns the same shape regadless
// of the matrix
size_t *Cmdata::shape()
{
    static size_t sz_arr[2]{cs, rs};
    return sz_arr;
}

void Cmdata::print_data_ref()
{
    std::cout << data.data() << std::endl;
}

double &Cmdata::get_element(size_t i, size_t j)
{
    return data[get_idx(i, j)];
}

void Cmdata::set_element(size_t i, size_t j, double set_value)
{
    data.at(get_idx(i, j)) = set_value;
}

void Cmdata::print_Cmdata(bool info)
{
    if (info)
    {
        std::cout << "Matrix: " << rs << " x " << cs << std::endl;
    }
    for (int i = 0; i < rs; ++i)
    {
        for (int j = 0; j < cs; ++j)
        {
            std::cout << get_element(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

void Cmdata::data_fill(std::vector<double> &vd)
{
    assert(vd.size() == data.size());
    data.swap(vd);
}

void Cmdata::transpose()
{
    int temp_str = str1;
    size_t temp_rs = rs;
    str1 = str2;
    rs = cs;
    str2 = temp_str;
    cs = temp_rs;
}

Cmdata Cmdata::mat_slice(size_t f_row, size_t l_row,
                         size_t f_col, size_t l_col)
{
    size_t n_rows = (l_row - f_row) + 1;
    size_t n_cols = (l_col - f_col) + 1;
    std::vector<double> vals;
    vals.reserve((n_rows * n_cols));
    for (auto i = f_row; i <= l_row; ++i)
    {
        for (auto j = f_col; j <= l_col; ++j)
        {
            vals.push_back(data[get_idx(i, j)]);
        }
    }
    return Cmdata(vals, n_rows, n_cols);
}

// Mathmatical Operators
Cmdata Cmdata::operator-()
{
    Cmdata n_mdata(data, rs, cs);
    for (int i = 0; i < n_mdata.data.size(); ++i)
    {
        n_mdata.data[i] *= -1;
    }
    return n_mdata;
}

// Private Functions
size_t Cmdata::get_idx(size_t i, size_t j)
{
    if (i >= rs || j >= cs)
    {
        throw std::range_error("Index out of bounds");
    }
    size_t idx;
    idx = str2 * i;
    idx = idx + (j * str1);
    return idx;
}
