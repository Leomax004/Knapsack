//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  Created by Parvesh singh on 07/12/16.
//  Copyright © 2016 Parvesh singh. All rights reserved.
//

#include <stdio.h>

void result( int weight[4] , int value[4] , int Knapsack_Table[4][8],int row,int col)
{
    int lastValue = Knapsack_Table[row][col];
    
    int array[20];
    int arrayCounter = 0;
    
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if((i == row) && (j == col))
            {
                if( Knapsack_Table[i-1][j] == lastValue )
                {
                    row = i - 1;
                    col = j;
                    result(weight, value, Knapsack_Table, row, col);
                }
                else
                {
                   // printf("\nRow is %d\n",row);
                    printf("Weight %d : value %d\n",weight[row],value[row]);
                    array[arrayCounter++] = row;

                   // printf("\nWeight is %d\n",weight[row]);
                  // printf("\nCol is %d\n",col-weight[row]);
                    if(col-weight[row] != 0)
                    {
                        result(weight, value, Knapsack_Table, row, col-weight[row]);
                    }
                    
                    
                    
                }
            }
        }
    }
    
    
    
}

int max(int value , int weight , int previous_value )
{
    int value_one =  value + weight;
    int value_second = previous_value;
    
    if( value_one > value_second)
    {
        return value_one;
    }
    else
    {
        return value_second;
    }
    
}

void Knapsack_Table( int weight[4], int value[4] ,int Bag_size)
{
    /*Table row should be equal to the number of elements in weight array
     Column should be equal to the bag size */
    int Table[4][8];
    
    /* In the for loop i tends to the row and bagsize tends to j*/
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            
            if( i == 0 )
            {
                if( weight[i] <= j )
                {
                    Table[i][j] = value[i];
                }
            }
            else
            {
                if( j < weight[i] )
                {
                    Table[i][j] = Table[i-1][j];
                }
                else
                {
                    //Max function call
                    Table[i][j] = max( value[i] ,Table[i-1][j-weight[i]] , Table[i-1][j] );
                }
            }
            
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            printf("%d\t",Table[i][j]);
        }
        printf("\n");
    }
    
        result( weight , value , Table, 3 , 7 );
    
}


int main(){
    int Bag_size = 7;
    //    int weight[4] = {1,3,4,5};
    //  int value[4] = {1,4,5,7};
    int weight[4] = {2,3,4,5};
    int value[4] = {4,5,6,7};
    Knapsack_Table(weight,value,Bag_size);
    
    
    
    return 0;
}

