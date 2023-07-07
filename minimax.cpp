#include "lib/minimax.hpp"
#include "lib/TicTacToe.hpp"

//define DEBUG

/* 
#ifdef DEBUG
printf("teste.\n");
#endif
 */

char _max(char *pos, position *ref){
    acts copias;
    copias.qtd = 0;

    char rand_num;
    char *rand_array = (char*) calloc(9,sizeof(char));
    if(first_move(pos)){
        rand_num = rand()%9;
        ref->val = 0;
        copy_and_move(pos,&(ref->array),rand_num,1);
        return rand_num;
    }
    free(rand_array);
    
    if(ref->array==nullptr){
        #ifdef DEBUG
        printf("\nref->val alocado.\n");
        #endif
        ref->val=0;
    }

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
        copy_match(pos,&(ref->array));
        return -1;
    }
    
    #ifdef DEBUG
    printf("\nCalculando jogada seguinte (max).\n");
    #endif

    acts results;

    for(int i = 0; i < 9; i++)if(pos[i]==0)copias.qtd++;

    copias.acoes = (position*) calloc(copias.qtd,sizeof(position));
    results.acoes = (position*) calloc(copias.qtd,sizeof(position));    
    
    int k=0;
    for(int i = 0; i < 9; i++){
        if(pos[i]==0){
            copy_and_move(pos,&(copias.acoes[k].array),i,1);
            copy_and_move(pos,&(results.acoes[k].array),i,1);
            k++;
        }
    }
    
    for(int i = 0; i < copias.qtd; i++){
        if(check_winner(copias.acoes[i].array)==1){
            ref->val=1;
            copy_match(copias.acoes[i].array,&(ref->array));
            return check_diff(pos,copias.acoes[i].array);
        }
    }

    for(int i = 0; i < copias.qtd ; i++){
        _min(copias.acoes[i].array,&(copias.acoes[i]));
    }

    char max_val = search_max(&copias);
    char max_diff = check_diff(copias.acoes[max_val].array,results.acoes[max_val].array);
    ref->val=copias.acoes[max_val].val;
    undo_move(&(copias.acoes[max_val].array),max_diff);
    copy_match(copias.acoes[max_val].array,&(ref->array));

    #ifdef DEBUG
    printf("\nPosição resultado: [%hhd]\n",ref->val);
    display(ref->array);
    #endif

    return max_diff;
}

char _min(char *pos,position *ref){
    acts copias;
    copias.qtd = 0;
    
    if(ref->array==nullptr){
        #ifdef DEBUG
        printf("\nref->val alocado.\n");
        #endif
        ref->val=0;
    }

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
        copy_match(pos,&(ref->array)); 
        #ifdef DEBUG
        printf("\nPosição calculada (min) -> %hhd.\n",ref->val);
        display(ref->array);
        #endif
        return -1;
    }

    #ifdef DEBUG
    printf("\nCalculando jogada seguinte (min).\n");
    #endif

    acts results;

    for(int i = 0; i < 9; i++)if(pos[i]==0)copias.qtd++;

    copias.acoes = (position*) calloc(copias.qtd,sizeof(position));
    results.acoes = (position*) calloc(copias.qtd,sizeof(position));

    int k=0;
    for(int i = 0; i < 9; i++){
        if(pos[i]==0){
            copy_and_move(pos,&(copias.acoes[k].array),i,2);
            copy_and_move(pos,&(results.acoes[k].array),i,2);
            k++;
        }
    }

    for(int i = 0; i < copias.qtd; i++){
        if(check_winner(copias.acoes[i].array)==2){
            ref->val=-1;
            copy_match(copias.acoes[i].array,&(ref->array));
            return check_diff(pos,copias.acoes[i].array);
        }
    }

    for(int i = 0; i < copias.qtd ; i++){
        _max(copias.acoes[i].array,&(copias.acoes[i]));
    }

    char min_val = search_min(&copias);
    char min_diff = check_diff(copias.acoes[min_val].array,results.acoes[min_val].array);

    ref->val=copias.acoes[min_val].val;
    undo_move(&(copias.acoes[min_val].array),min_diff);
    copy_match(copias.acoes[min_val].array,&(ref->array));

    return min_diff;
}

void copy_match(char*pos,char**ref){
    if(*ref==nullptr){
        *ref = (char*) calloc(9,sizeof(char));
    }
    
    for(int i=0;i<9;i++){
        (*ref)[i] = pos[i];
    }
}

void copy_and_move(char *pos,char**ref,char move,char turn){
    if(*ref==nullptr)*ref = (char*) calloc(9,sizeof(char));
    for(int i=0;i<9;i++){
        (*ref)[i] = pos[i];
    }
    (*ref)[move] = turn;
    #ifdef DEBUG
    printf("Movimento a considerar [%hhd].\n",move);
    display(*ref);
    #endif
}

int search_max(acts *copias){
    int maior = copias->acoes[0].val;
    int pos = 0;
    for(int i=1; i<copias->qtd;i++){
        if(copias->acoes[i].val>maior){
            #ifdef DEBUG
            printf("\nMelhor posição: (max)\n");
            display(copias->acoes[i].array);
            #endif
            maior = copias->acoes[i].val;
            pos = i;
        }
    }
    return pos;
}

int search_min(acts *copias){
    int menor = copias->acoes[0].val;
    int pos = 0;
    for(int i=1; i<copias->qtd;i++){
        if(copias->acoes[i].val<menor){
            #ifdef DEBUG
            printf("\nMelhor posição: (min)\n");
            display(copias->acoes[i].array);
            #endif
            menor = copias->acoes[i].val;
            pos = i;
        }
    }
    return pos;
}

char do_machine_move(char *pos){
    position *aux = (position*) calloc(1,sizeof(position));
    char res = -3;

    char option = calc_turn(pos)-1;

    if(!option){
        _max(pos,aux);
    }
    else{
        _min(pos,aux);
    }

    res = check_diff(aux->array,pos);
    return res;
}

void display(char*pos){
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

/*     for(int i = 0; i < 9; i++){
        printf("%d ",pos[i]);
    }
    printf("\n"); */
}

void play_vs_engine(TicTacToe *partida, int option){
    char turn;
    char move;
    
    if(option == 1){
        while(true){
            turn = partida->getTurn();
            printf("Vez do %c\n",turn);
            do{
                scanf("%hhd",&move);
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
            printf("Vez do %c\n",turn);
            do{
                scanf("%hhd",&move);
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

char aval_pos(char*pos){
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

char check_diff(char*pos1,char*pos2){
    int res=-3;
    for(int i = 0; i < 9; i++){
        if(pos1[i]!=pos2[i])res=i;
    }
    return res;
}

void undo_move(char **pos, char move){
    if(move >= 0 && move < 9)(*pos)[move] = 0;
}

bool first_move(char*pos){
    bool teste=true;
    for(int i = 0; i < 9; i++){
        if(pos[i]!=0)teste=false;
    }
    return teste;
}

char calc_turn(char*pos){
    char num_1=0;
    char num_2=0;
    for(int i=0; i<9; i++){
        if(pos[i]==1)num_1++;
        if(pos[i]==2)num_2++;
    }
    return ((num_1+num_2)%2)?2:1;
}