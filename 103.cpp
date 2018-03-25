#include<bits/stdc++.h>
using namespace std;
int getFitValue(int box1[], int box2[] ,int dimensions)
{
    int returnValue;
    vector<int> permute;
    for ( int i = 0; i < dimensions; i ++ )
    {
        permute.push_back(i);
    } 
    int cn = 0;
    while(next_permutation(permute.begin(),permute.end()))
    {
        cn = 0;
        for ( int i = 0; i < dimensions; i ++ )
        {
            if( box1[permute[i]] >= box2[i])
            {
                cn = 1;
            }
        }
        if ( cn == 1)
        {
            continue;
        }
        return 1;
    }
    return -1;
}re
int main()
{
    int numberOfBoxes,i,j;
    scanf("%d",&numberOfBoxes);
    int fits[numberOfBoxes][numberOfBoxes];
    int dimensions;
    scanf("%d",&dimensions);
    int boxes[numberOfBoxes][dimensions];
    int len[numberOfBoxes][numberOfBoxes];
    for ( i = 0; i < numberOfBoxes; i ++ )
    {
        len[i][0] = 0;
        len[i][1] = i;
    }

    
    //input boxes;
    for ( i= 0 ; i < numberOfBoxes; i ++ )
    {
        for ( j = 0; j < dimensions; j ++ )
        {
            scanf("%d",&boxes[i][j]);
        }
    }
    

    
    //fill Table
    for ( i = 0; i < numberOfBoxes; i ++ )
    {
        for (j = 0; j < numberOfBoxes; j ++ )
        {
            fits[i][j] = getFitValue(boxes[i],boxes[j],dimensions);
            cout << fits[i][j];
        }
        cout << endl;
        
    }
    
    //fill Table with max values
    for ( i = 0 ; i< numberOfBoxes - 1; i ++ )
    {
        for ( j = 0 ; j < numberOfBoxes ;j ++ )
        {
            if ( fits[i][j] == 1 && len[j][0] < len[i][0] +1 )
            {
                len[j][0] = len[i][0] + 1;
                
            }
        }
    }    
    int max = 0;
    int max_i;
    for ( i = 0; i < numberOfBoxes; i ++ )
    {
            if (len[i][0] > max)
                max = len[i][0];
                
    

    }
    cout << max << max_i << endl;
    int next_i;
    next_i  = max_i;
    //cout << len[next_i][1];
    while(next_i != len[next_i][1])
    {
        cout << next_i;
        next_i= len[next_i][1];
    }
    cout << next_i;
    
    return 0;
}
