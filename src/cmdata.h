/*
 Creating a matrix of contigous arrays
*/
#include <vector>

#ifndef CMDATA_HEADER
#define CMDATA_HEADER

class Cmdata
{
public:
    Cmdata(int rows, int cols, double init_value);
    int *shape();
    void print_Cmdata();
    double get_element(int i, int j);
    void data_fill(std::vector<double> vd);

private:
    std::vector<double> data;
    int rs;
    int cs;
    int str1;
    int str2;
};

#endif // MCDATA_HEADER
