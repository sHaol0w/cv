#include <iostream>
#include <cstdlib>
class node//binary
{
    public:
    node *Lchild,*Rchild,*parent;
    int value;
    void link(node *c,bool LR)
    {
        node*p = this;
        if(LR ==0)
        {
            p->Lchild = c;
            c->parent = p;
        }
        else
        {
            p->Rchild = c;
            c->parent = p;
        }
    }
};
class tree
{
    public:
    node *root;
   //0 is left
    void rotate(node *x,bool LR)
    {
        if(LR ==0)
        {
            node *y;
            y = x->Rchild;
            if(x->parent->Lchild == x)
            { 
                x->parent->Lchild = y;
            }
            else
            {
                x->parent->Rchild = y;
            }
            y->parent = x->parent;
            x->parent = y;
            x->Rchild = y->Lchild;
            y->Lchild = x;
            x->Rchild->parent = x;
            y->Lchild->parent = y; 
        }
        
    }
};
int main()
{
    tree T;
    node n0,n1,n2,n3,n4,n5;
    n1.value = 1;
     n2.value = 2;
     n3.value = 3;
     n4.value = 4;
     n5.value = 5;
    n0.value  =0;
    T.root = &n0;
    n1.Lchild = &n2;
    n1.Rchild = &n3;
    n3.Lchild = &n4;
    n3.Rchild = &n5;
    n0.Lchild = &n1;
    n1.parent = &n0;
    n2.parent = &n1;
    n3.parent = &n1;
    n4.parent = &n3;
    //n5.parent = &n3;
    n3.link(&n5,1);
    T.rotate(&n1,0);
    std::cout<<n3.Rchild->value;
    //std::cout <<T.root->Lchild->Rchild->Rchild->parent->value  << std::endl;
    return 0;
}
