typedef double w_type;
#define qtd_neu 16
#define qtd_in 9
#define qtd_out 9

#include <vector>

double sigmoid (double);
char nnue_algorithm(char*);
void fill_random(std::vector<std::vector<w_type>>&);
void fill_random(std::vector<w_type> &);
void impress_w(std::vector<std::vector<w_type>>);
void impress_w(std::vector<w_type>);

int mul_matrix(std::vector<std::vector<w_type>>&,char**,std::vector<w_type>&);
int mul_matrix(std::vector<std::vector<w_type>>&,std::vector<w_type>&,std::vector<w_type>&);
int sum_matrix(std::vector<w_type>&,std::vector<w_type>&,std::vector<w_type>&);
void apply_sigmoid(std::vector<w_type>&);