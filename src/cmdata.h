// Creating a matrix of contigous data
// currently using c++ vector template.

#include <vector>

#ifndef CMDATA_HEADER
#define CMDATA_HEADER
/* Cmdata
 * Two dimensional tabular data matrix class.
 */
class Cmdata
{
public:
    Cmdata(size_t rows, size_t cols, double init_value);
    Cmdata(std::vector<double> &init_vector, size_t rows, size_t cols);
    size_t *shape();
    void print_Cmdata();
    double &get_element(size_t i, size_t j);
    void set_element(size_t i, size_t j, double set_value);
    void data_fill(std::vector<double> &vd);
    void transpose();

private:
    std::vector<double> data;
    size_t rs;
    size_t cs;
    int str1;
    int str2;
    size_t get_idx(size_t i, size_t j);
};

#endif // CMDATA_HEADER
