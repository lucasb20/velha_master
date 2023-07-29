#include "lib/minimax.hpp"
#include "lib/TicTacToe.hpp"

//define DEBUG

char _max(std::vector <char> pos, position *ref){
    std::vector<position> copias;

    char rand_num;

    static bool first_move = true;

    if(first_move){
        rand_num = rand()%9;
        ref->val = 0;
        copy_and_move(pos,ref->array,rand_num,1);
        first_move = false;
        return rand_num;
    }

    #ifdef DEBUG
    printf("\nref->val alocado.\n");
    #endif
    ref->val=0;

    #ifdef DEBUG
    printf("\nPosição recebida (max) -> %hhd.\n",check_winner(pos));
    display(pos);
    #endif

    if(check_winner(pos)!=0){
        if(check_winner(pos)==-2){
            printf("O que aconteceu? (max)\n");
            exit(1);
        }
        ref->val = aval_pos(pos);
        #ifdef DEBUG
        printf("\nPosição calculada (max) -> %hhd.\n",ref->val);
        display(ref->array);
        #endif  
        copy_match(pos,ref->array);
        return -1;
    }
    
    #ifdef DEBUG
    printf("\nCalculando jogada seguinte (max).\n");
    #endif

    std::vector<position> results;

    int k=0;
    for(int i = 0; i < 9; i++){
        if(pos[i]==0){
            copias.push_back(*ref);
            results.push_back(*ref);
            copy_and_move(pos,copias[k].array,i,1);
            copy_and_move(pos,results[k].array,i,1);
            k++;
        }
    }
    
    for(int i = 0; i < copias.size(); i++){
        if(check_winner(copias[i].array)==1){
            ref->val=1;
            copy_match(copias[i].array,ref->array);
            return check_diff(pos,copias[i].array);
        }
    }

    for(int i = 0; i < copias.size() ; i++){
        _min(copias[i].array,&(copias[i]));
    }

    char max_val = search_max(copias);
    char max_diff = check_diff(copias[max_val].array,results[max_val].array);
    ref->val=copias[max_val].val;
    undo_move(copias[max_val].array,max_diff);
    copy_match(copias[max_val].array,ref->array);

    #ifdef DEBUG
    printf("\nPosição resultado: [%hhd]\n",ref->val);
    display(ref->array);
    #endif

    return max_diff;
}

char _min(std::vector <char> pos,position *ref){
    std::vector<position> copias;
    
    #ifdef DEBUG
    printf("\nref->val alocado.\n");
    #endif
    ref->val=0;   

    #ifdef DEBUG
    printf("\nPosição recebida (min) -> %hhd.\n",check_winner(pos));
    display(pos);
    #endif

    if(check_winner(pos)!=0){
        if(check_winner(pos)==-2){
            printf("O que aconteceu? (min)\n");
            exit(1);
        }
        ref->val = aval_pos(pos);
        copy_match(pos,ref->array); 
        #ifdef DEBUG
        printf("\nPosição calculada (min) -> %hhd.\n",ref->val);
        display(ref->array);
        #endif
        return -1;
    }

    #ifdef DEBUG
    printf("\nCalculando jogada seguinte (min).\n");
    #endif

    std::vector<position> results;

    int k=0;
    for(int i = 0; i < 9; i++){
        if(pos[i]==0){
            copias.push_back(*ref);
            results.push_back(*ref);
            copy_and_move(pos,copias[k].array,i,2);
            copy_and_move(pos,results[k].array,i,2);
            k++;
        }
    }

    for(int i = 0; i < copias.size(); i++){
        if(check_winner(copias[i].array)==2){
            ref->val=-1;
            copy_match(copias[i].array,ref->array);
            return check_diff(pos,copias[i].array);
        }
    }

    for(int i = 0; i < copias.size() ; i++){
        _max(copias[i].array,&(copias[i]));
    }

    char min_val = search_min(copias);
    char min_diff = check_diff(copias[min_val].array,results[min_val].array);

    ref->val=copias[min_val].val;
    undo_move(copias[min_val].array,min_diff);
    copy_match(copias[min_val].array,ref->array);

    return min_diff;
}

void copy_match(std::vector <char> pos,std::vector<char> &ref){
    ref.assign(9,0);
    for(int i=0;i<9;i++){
        ref[i] = pos[i];
    }
}

void copy_and_move(std::vector<char> pos,std::vector<char>&ref,char move,char turn){
    for(int i=0;i<9;i++){
        ref[i] = pos[i];
    }

    ref[move] = turn;
    #ifdef DEBUG
    printf("Movimento a considerar [%hhd].\n",move);
    display(ref);
    #endif
}

int search_max(std::vector<position> &copias){
    int maior = copias[0].val;
    int pos = 0;
    for(int i=1; i<copias.size();i++){
        if(copias[i].val>maior){
            #ifdef DEBUG
            printf("\nMelhor posição: (max)\n");
            display(copias[i].array);
            #endif
            maior = copias[i].val;
            pos = i;
        }
    }
    return pos;
}

int search_min(std::vector<position> &copias){
    int menor = copias[0].val;
    int pos = 0;
    for(int i=1; i<copias.size();i++){
        if(copias[i].val<menor){
            #ifdef DEBUG
            printf("\nMelhor posição: (min)\n");
            display(copias[i].array);
            #endif
            menor = copias[i].val;
            pos = i;
        }
    }
    return pos;
}

char do_machine_move(std::vector<char> pos){
    position *aux = new position;
    aux->array.assign(9,0);
    char res = -3;

    char option = calc_turn(pos)-1;

    if(!option){
        _max(pos,aux);
    }
    else{
        _min(pos,aux);
    }

    res = check_diff(aux->array,pos);
    delete aux;
    return res;
}

void display(std::vector<char> pos){
    char casa=-1;
    for(int i = 0; i < 9; i++){
        switch(pos[i]){
            case 0:
            casa = '-';
            break;
            case 1:
            casa = 'X';
            break;
            case 2:
            casa = 'O';
            break;
            default:
            casa = '?';
            break;
        }
        printf("%c",casa);
        if(i%3==2)std::cout << '\n';
    }
}

void play_vs_engine(TicTacToe *partida, int option){
    int turn;
    int move;

    if(option == 1){
        while(true){
            turn = partida->getTurn();
            printf("Vez do %c (Formato -> posição da casa) \n",turn);
            do{
                scanf("%d",&move);
            }while(!(partida->do_move(move)));
            partida->display_match();
            if(check_winner(partida->match) != 0)break;
            move = do_machine_move(partida->match);
            if(move != -3)partida->do_move(move);
            partida->display_match();
            if(check_winner(partida->match) != 0)break;
        }
    }
    else if(option == 2){
        while(true){
            move = do_machine_move(partida->match);
            if(move != -3)partida->do_move(move);
            partida->display_match();
            if(check_winner(partida->match) != 0)break;
            turn = partida->getTurn();
            printf("Vez do %c (Formato -> posição da casa)\n",turn);
            do{
                scanf("%d",&move);
            }while(!(partida->do_move(move)));
            partida->display_match();
            if(check_winner(partida->match) != 0)break;
        }
    }
    else{
        while(true){
            move = do_machine_move(partida->match);
            if(move != -3)partida->do_move(move);
            printf("Vez do X:\n");
            partida->display_match();
            if(check_winner(partida->match) != 0)break;
            move = do_machine_move(partida->match);
            if(move != -3)partida->do_move(move);
            printf("Vez do O:\n");
            partida->display_match();
            if(check_winner(partida->match) != 0)break;
        }
    }

    switch(check_winner(partida->match)){
        case -1:
        std::cout << "Draw.\n";
        break;
        default:
        printf("O vencedor foi %c.\n",(check_winner(partida->match)%2)?'X':'O');
    }
}

char aval_pos(std::vector<char> pos){
    char res;
    res = check_winner(pos);
    switch(res){
        case 1:
        res = 1;
        break;
        case 2:
        res = -1;
        break;
        default:
        res = 0;
        break;
    }
    return res;
}

char check_diff(std::vector<char> pos1,std::vector<char> pos2){
    int res=-3;
    for(int i = 0; i < 9; i++){
        if(pos1[i]!=pos2[i])res=i;
    }
    return res;
}

void undo_move(std::vector<char> &pos, char move){
    if(move >= 0 && move < 9)pos[move] = 0;
}

char calc_turn(std::vector<char> pos){
    char num_1=0;
    char num_2=0;
    for(char &i : pos){
        if(i==1)num_1++;
        if(i==2)num_2++;
    }
    return ((num_1+num_2)%2)?2:1;
}