#include <iostream>
#include "SegmentTree.h"

using namespace std;

int cmp(int a, int b)
{
    return a+b;
}


int main()
{
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
        cin>>arr[i];
    SegmentTree<int> segTree(arr, cmp, 0, num-1);
    int s,e;
    cin>>s>>e;
    cout<<segTree.query(s-1,e-1);
    return 0;
}