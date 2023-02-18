#include <iostream>
#include <cmath>

int matrix[512][512];
int cntr = 1;

void fill_rec(int x1, int y1, int side, int x_, int y_){
    side = side / 2;
    bool x_f = (x_ - x1) < side;
    bool y_f = (y_ - y1) < side;
    if (x_f && y_f){
        if (side != 1){
            fill_rec(x1, y1,side,x_,y_);
            fill_rec(x1 , y1 + side,side,x1 + side - 1,y1 + side);
            fill_rec(x1 + side , y1,side,x1 + side,y1 + side - 1);
            fill_rec(x1 + side , y1 + side,side,x1 + side,y1 + side);
        }
        matrix[x1 + side][y1 + side - 1] = cntr;
        matrix[x1 + side][y1 + side] = cntr;
        matrix[x1 + side - 1][y1 + side] = cntr;
    } else if (x_f && !y_f){
        if (side != 1)
        {
            fill_rec(x1, y1,side,x1 + side - 1,y1 + side - 1);
            fill_rec(x1 , y1 + side,side,x_,y_);
            fill_rec(x1 + side , y1,side,x1 + side,y1 + side - 1);
            fill_rec(x1 + side , y1 + side,side,x1 + side,y1 + side);
        }
        matrix[x1 + side - 1][y1 + side - 1] = cntr;
        matrix[x1 + side][y1 + side] = cntr;
        matrix[x1 + side][y1 + side-1] = cntr;
    } else if (!x_f && y_f){
        if (side != 1)
        {
            fill_rec(x1, y1,side,x1 + side - 1,y1 + side - 1);
            fill_rec(x1 , y1 + side,side,x1 + side - 1,y1 + side);
            fill_rec(x1 + side , y1,side,x_,y_);
            fill_rec(x1 + side , y1 + side,side,x1 + side,y1 + side);
        } 
        matrix[x1 + side -1][y1 + side - 1] = cntr;
        matrix[x1 + side -1][y1 + side] = cntr;
        matrix[x1 + side][y1 + side] = cntr;
    } else {
        if (side != 1)
        {
            fill_rec(x1, y1,side,x1 + side - 1,y1 + side - 1);
            fill_rec(x1 , y1 + side,side,x1 + side - 1,y1 + side);
            fill_rec(x1 + side , y1,side,x1 + side,y1 + side - 1);
            fill_rec(x1 + side , y1 + side,side,x_,y_);
        } 
        matrix[x1 + side -1][y1 + side - 1] = cntr;
        matrix[x1 + side -1][y1 + side] = cntr;
        matrix[x1 + side][y1 + side - 1] = cntr;
    }

    cntr++;
}

int main(){
    int n,X,Y,sd;
    std::cin >> n >> X >> Y;
    sd = (int)std::pow(2,n);
    fill_rec(0,0,sd,X-1,Y-1);
    for (size_t i = 0; i < sd; i++)
    {
        for (size_t j = 0; j < sd; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
    
}           