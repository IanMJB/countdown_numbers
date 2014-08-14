#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

#define INPUT_NUMBERS 6

using namespace std;

enum ARITH_OP { add, sub, mul, div, ignore };
const char *OPS[] = {"ADD", "SUB", "MUL", "DIV", "IGNORE"};

/**
 *  5 operators, +,-,/,* and ignore
 */

double calc_perm(vector<ARITH_OP> ops, vector<int> set)
{
    //if(set.size() != ops.size())
    //    throw runtime_error("ops vector and set vector differ in size");
    int s = set.size();

    double result;
    int it = 0;
    ARITH_OP c_op;
    
    /* get first non 0 result   */
    for(ARITH_OP op : ops){
        ++it;
        c_op = op;
        if(op != ARITH_OP::ignore){
            result = set[it-1];
            break;
        }
    }

    /* we now have our first non ignore operator    */
    for(;it<s;++it){
        if(ops[it] == ARITH_OP::ignore)
            continue;
        switch(c_op){
            case ARITH_OP::add:
                result += set[it];
                break;
            case ARITH_OP::sub:
                result -= set[it];
                break;
            case ARITH_OP::mul:
                result *= set[it];
                break;
            case ARITH_OP::div:
                result /= set[it];
                break;
        }
        c_op = ops[it];
    }
    return result;
}

bool try_permutation(int &target, vector<int> &set)
{
    vector<ARITH_OP> all = {add, sub, mul, ARITH_OP::div, ARITH_OP::ignore};
    vector<ARITH_OP> op_map = { add, add, add, add, add, add};
    vector<ARITH_OP> closest_op; 
    double closest = 0;
    //iterate over the set
    int s = all.size();
    for(int i=0;i<s;++i){
        for(int j=0;j<s;++j){
            for(int k=0;k<s;++k){
                for(int l=0;l<s;++l){
                    for(int m=0;m<s;++m){
                        for(int n=0;n<s;++n){
                            op_map[5] = static_cast<ARITH_OP>(n);
                            double res = calc_perm(op_map, set);
                            //cout << res ;
                            if(target == res){
                                cout << "SUCCESS!!!" << endl;
                                cout << res << endl;
                                for(int i: set){
                                    cout << i << " ";
                                }
                                cout << "\n";
                                for(ARITH_OP op: op_map){
                                    cout << OPS[static_cast<int>(op)] << " ";
                                }
                                exit(EXIT_SUCCESS);
                            }else if(((closest-target)*(closest-target)) > ((res-target)*(res-target))){
                                cout << "New closest value!" << endl;
                                cout << res << endl;
                                closest = res;
                                closest_op = op_map;
                                for(ARITH_OP i: op_map){
                                    cout << OPS[static_cast<int>(i)] << ", ";
                                }
                                cout << "\n\n";
                            }
                        }
                        op_map[4] = static_cast<ARITH_OP>(m);
                    }
                    op_map[3] = static_cast<ARITH_OP>(l);
                }
                op_map[2] = static_cast<ARITH_OP>(k);
            }
            op_map[1] = static_cast<ARITH_OP>(j);
        }
        op_map[0] = static_cast<ARITH_OP>(i);
    }
    return false;
} 

int main(int argc, char *argv[])
{
    if(argc != 8){
        cerr << "Error, countdown input_numbers target_number " << endl;
        exit(EXIT_FAILURE);
    }

    int target_number = atoi(argv[7]);
    vector<int> set;
    
    for(int i=0;i<INPUT_NUMBERS;++i)
        set.push_back(atoi(argv[i]));

    sort(set.begin(), set.end());
    
    do{
        try_permutation(target_number, set);
    }while(next_permutation(set.begin(), set.end()));
    cout << "Fin!" << endl;
    return 0;
}


