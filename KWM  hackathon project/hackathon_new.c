#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void approval (int legal, int financial, int technical);
int legal_department(int legal_requirement);
int financial_department(int financial_requirement);
int technical_department(int technical_requirement);
int board(int board_requirement);

int main (int argc, char *argv[]){
    clock_t begin = clock();
    int standard, variation, less_than_five_k;
    int legal, financial, technical;
    printf("Is this a standard contract? ");
    scanf("%d",&standard);
    if (standard){
        printf("Are there any variations? ");
        scanf("%d",&variation);
        if (!variation){
            printf("The contract requires to be approved by the lowest level of authority.");
        }else{
            printf("Are there financial concerns? ");
            scanf("%d", &financial);
            printf("Are there legal concerns? ");
            scanf("%d", &legal);
            printf("Are there technical concerns? ");
            scanf("%d", &technical);
            approval(legal,financial,technical);
        }
    }else{
        printf("Is the amount involved less than 5000 dollars? ");
        scanf("%d", &less_than_five_k);
        if (less_than_five_k){
            printf("The contract requires to be approved by the lowest level of authority.");
        }else{
            printf("Are there legal concerns? ");
            scanf("%d", &legal);
            printf("Are there financial concerns? ");
            scanf("%d", &financial);
            printf("Are there technical concerns? ");
            scanf("%d", &technical);
            approval(legal,financial,technical);
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe CPU processing took %.2lf seconds including decision making time!", time_spent);
    return 0;
}


void approval (int legal, int financial, int technical){
    int legal_requirement, financial_requirement, technical_requirement, board_requirement;
    int legal_authorization = 1, financial_authorization = 1, technical_authorization = 1, board_authorization = 1;
    int board_approval_required;
    if (legal){
        printf("Has the legal requirement been reviewed and met: ");
        scanf("%d", &legal_requirement);
        legal_authorization = legal_department(legal_requirement);
    }
    if (financial){
        printf("Has the financial requirement been reviewed and met: ");
        scanf("%d", &financial_requirement);
        financial_authorization = financial_department(financial_requirement);
    }
    if (technical){
        printf("Has the technical requirement been reviewed and met: ");
        scanf("%d", &technical_requirement);
        technical_authorization = technical_department(technical_requirement);
    }
    if (legal_authorization&&financial_authorization&&technical_authorization){
        printf("Does the contract requires to be approved by the board? ");
        scanf("%d", &board_approval_required);
        if (board_approval_required){
            printf("Enter your board review requirement: ");
            scanf("%d", &board_requirement);
            board_authorization = board(board_requirement);
            if (!board_authorization){
                printf("There has been a disagreement, stop and resolve the issue.");
            }
        }else{
            printf("The contract does not need to be approved by the board, contract approved!");
        }
    }else if ((!legal_authorization)||(!financial_authorization)||(!technical_authorization)){
        printf("There has been a disagreement, stop and resolve the issue.");
    }
}


int legal_department (int legal_requirement){
    if (legal_requirement){
        printf("Legal Department approves the contract!\n");
    }else{
        printf("Legal Department does not approves the contract!\n");
    }
    return legal_requirement;
}

int financial_department (int financial_requirement){
    if (financial_requirement){
        printf("Financial Department approves the contract!\n");
    }else{
        printf("Financial Department does not approves the contract!\n");
    }
    return financial_requirement;
}

int technical_department (int technical_requirement){
    if (technical_requirement){
        printf("Technical Department approves the contract!\n");
    }else{
        printf("Technical Department does not approves the contract!\n");
    }
    return technical_requirement;
}

int board(int board_requirement){
    if (board_requirement){
        printf("The board approves the contract!\nThe contract is approved!");
    }else{
        printf("The board does not approves the contract!\n");
    }
    return board_requirement;
}
