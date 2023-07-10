typedef double w_type;
#define qtd_neu 16
#define qtd_in 9
#define qtd_out 9

double sigmoid (double);
char nnue_algorithm(char*);
void fill_random(w_type***,size_t,size_t);
void fill_random(w_type**,size_t);
void impress_w(w_type**,size_t,size_t);
void impress_w(w_type*,size_t);

int mul_matrix(w_type***,char**,w_type**,size_t,size_t,size_t,size_t);
int mul_matrix(w_type***,w_type**,w_type**,size_t,size_t,size_t,size_t);
int sum_matrix(w_type**,w_type**,w_type**,size_t);
void apply_sigmoid(w_type**,size_t);