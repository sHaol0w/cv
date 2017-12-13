
#include <iostream>
#include <cstdlib>
void printa(int*a,int n)
{
    int i=0;
    while(i<n)
    {
        std::cout<<a[i]<<',';
        i++;
    }
    std::cout<<std::endl;
}

class QuickSort
{
    public:
    int partition(int *a,int p,int r)//p,r is array index
    {
        
        int i = p,j = p;
        int tmp;
        for(;j<=r-1;j++)
        {
            if(a[j]<=a[r])
            {
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
                i++;
            }
        }
        tmp = a[i];
        a[i] = a[r];
        a[r] = tmp;
        return i;
    }
    void quicksort(int *a,int fi,int li)//li is last index;fi first
    {
        if(fi<li)
        { 
            int i;
            i = partition(a,fi,li);
            quicksort(a,fi,i-1);
            quicksort(a,i+1,li);
        }
    }
};


class heap
{
    public:
   void heapify(int a[],int i,int n)
   {
       int l,r;
       l = 2*i;
       r = 2*i+1;
       int largest = i;
       if(l<=n&&a[l]>a[largest])
           largest = l;
       if(r<=n&&a[r]>a[largest])
           largest = r;
       if(largest != i)
       {
            int tmp = a[i];
            a[i] = a[largest];
            a[largest] = tmp;
            heapify(a,largest,n);
       }
   }
   void buildheap(int*a,int n)
   {
       for(int i = n/2;i>=1;i--)
           heapify(&a[0],i,10);
   }
   void heapsort(int*a,int n)
   {
       for(int i = n;i>=2;i--)
       {
           int tmp= a[i];
           a[i] = a[1];
           a[1] = tmp;
           printa(&a[1],10);
           heapify(&a[0],1,i-1);
           printa(&a[1],10);
       }
   }
};

int main()
{
   /* heap H;
    int a[11] = {10,4,1,3,2,16,9,10,14,8,7};//first element is the size
    printa(&a[1],10);
    H.heapify(a,2,10);
           
    printa(&a[1],10);
    H.buildheap(&a[0],10);
    printa(&a[1],10);
    
    H.heapsort(&a[0],10);
    
    printa(&a[1],10);
    return 0;*/
    
    int a[11] = {10,4,1,3,2,16,9,10,14,8,7};
    QuickSort q;
    printa(&a[0],11);
    q.quicksort(a,0,10);
    printa(&a[0],11);
    return 0;
}

