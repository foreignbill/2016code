#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{
    int key;//size
    Node *l,*r,*f;//left,right,father
};
class SplayTree{
public:
    void Init(){rt=NULL;}
    void Zag(Node *x){//left rotate
        Node *y=x->f;//y is the father of x
        y->r = x->l;
        if (x->l)x->l->f = y;//if x has left child
        x->f =y->f;
        if (y->f){//y is not root
            if (y==y->f->l)y->f->l=x;//y if left child
            else y->f->r=x;//y is right child
        }
        y->f=x; x->l=y;
    }
    void Zig(Node *x){//right rotate
        Node *y=x->f;//y is the father of x
        y->l = x->r;
        if (x->r)x->r->f=y;
        x->f = y->f;
        if (y->f){
            if (y==y->f->l)y->f->l=x;
            else y->f->r=x;
        }
        y->f=x;
        x->r=y;
    }
    
    void Splay(Node *x){
        while (x->f){
            Node *p=x->f;
            if (!p->f){
                if (x==p->l)Zig(x);
                else Zag(x);
            }else if (x==p->l){
                if (p==p->f->l){Zig(p);Zig(x);}
                else {Zig(x);Zag(x);}
            }else {//x==p->r
                if (p==p->f->r){Zag(p);Zag(x);}
                else {Zag(x);Zig(x);}
            }
        }
        rt=x;
    }
    Node *Find(int x){
        Node *T=rt;
        while (T){
            if (T->key==x){Splay(T);return T;}
            else if (x<T->key)T=T->l;
            else T=T->r;
        }
        return T;
    }
    void Insert(int x){
        Node *T=rt,*fa=NULL;
        while (T){
            fa=T;
            if (x<T->key)T=T->l;
            else if(x>T->key)T=T->r;
            else return ;//two the same keys
        }
        T=(Node*)malloc(sizeof(Node));
        T->key=x;
        T->l=T->r=NULL;
        T->f=fa;
        if (fa){
            if (fa->key>x)fa->l=T;
            else fa->r=T;
        }
        Splay(T);
    }
    void Delete(int x){
        Node *T=Find(x);
        if (NULL==T)return ;//error
        rt=Join(T->l,T->r);
    }
    Node *Maxnum(Node *t){
        Node *T=t;
        while (T->r)T=T->r;
        Splay(T);
        return T;
    }
    Node *Minnum(Node *t){
        Node *T=t;
        while (T->l)T=T->l;
        Splay(T);
        return T;
    }
    Node *Last(int x){
        Node *T=Find(x);
        T=T->l;
        return (Maxnum(T));
    }
    Node *Next(int x){
        Node *T=Find(x);
        T=T->r;
        return (Minnum(T));
    }
    Node *Join(Node *t1,Node *t2){
        if (NULL==t1)return t2;
        if (NULL==t2)return t1;
        Node *T=Maxnum(t1);
        T->l=t2;
        return T;
    }
    void Split(int x,Node *&t1,Node *&t2){
        Node *T=Find(x);
        t1=T->l; t2=T->r;
    }
    void Inorder(Node *T){
        if (NULL==T)return ;
        Inorder(T->l);
        printf("%d->",T->key);
        Inorder(T->r);
    }
    void _Delete(){Delete(rt);}
    void Delete(Node *T){
        if (NULL==T)return ;
        Delete(T->l);
        Delete(T->r);
        free(T);
    }
private:
    Node *rt;//root
};
int main(){
	int xxx[111]={-1},yyy[111]={1,2,3,4,5};
	*xxx=*yyy;
	memcpy	
	
	return 0;
}
