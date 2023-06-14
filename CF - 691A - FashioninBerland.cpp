#include<stdio.h>
int main()
{
    int n,num,count,var;
    scanf("%d",&n);
    count=0,var=n;
    while(n--)
    {
        scanf("%d",&num);
        if(num==0)
        count++;
    }
    if(var==1&&num==0) printf("NO\n");
    else if(count==1||(var==1&&num==1))
    printf("YES\n");
    else
    printf("NO\n");
    return 0;
}
