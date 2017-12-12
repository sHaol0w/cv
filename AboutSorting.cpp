
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
    heap H;
    int a[11] = {10,4,1,3,2,16,9,10,14,8,7};//first element is the size
    printa(&a[1],10);
    H.heapify(a,2,10);
           
    printa(&a[1],10);
    H.buildheap(&a[0],10);
    printa(&a[1],10);
    
    H.heapsort(&a[0],10);
    
    printa(&a[1],10);
    return 0;
}

