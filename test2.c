#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *next;
};
int main()
{
    struct node *head,*p,*head1,*head2;
    head=NULL;
    for(int i=0;i<10;i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->num=13*(i+1);
        p->next=head;
        head=p;
    }
    head1=head;
    for(;p;p=p->next) printf("%-5d",p->num);
    printf("\n");
    head=NULL;
    for(int i=0;i<10;i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->num=15*(i+1);
        p->next=head;
        head=p;
    }
    head2=head;
    for(;p;p=p->next) printf("%-5d",p->num);
    printf("\n");
    struct node *p1,*p2;
    if(head1->num > head2->num) head=head1;
    else head=head2;
    for(p1=head1,p2=head2;(p1!=NULL)&&(p2!=NULL);)
    {
        printf("%-5d%-5d\n",p1->num,p2->num);
        if(p1->num > p2->num)
        {
            if(p1->next==NULL)
            {
                p1->next=p2;
                break;
            }
            else if(p1->next && p1->next->num > p2->num)
                p1=p1->next;
            else
            {
                p=p1->next;
                p1->next=p2;
                p1=p;
            }
        }
        else
        {
            if(p2->next==NULL)
            {
                p2->next=p1;
                break;
            }
            else if(p2->next && p2->next->num > p1->num)
                p2=p2->next;
            else
            {
                p=p2->next;
                p2->next=p1;
                p2=p;
            }
        }
    }
    for(p=head;p!=NULL;p=p->next)
        printf("%-5d",p->num);
    printf("\n");
    getchar();
    return 0;
}