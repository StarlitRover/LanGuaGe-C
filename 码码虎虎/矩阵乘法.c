int main()
{
    int ra,ca,rb,cb;
    scanf("%d%d",&ra,&ca);
    int ma[ra][ca];
    for(int i=0;i<ra;++i)
        for(int j=0;j<ca;++j)
            scanf("%d",&ma[i][j]);
    scanf("%d%d",&rb,&cb);
    if(ca!=rb)
        printf("Error: %d != %d",ca,rb);
    else
    {
        int mb[rb][cb];
        for(int i=0;i<rb;++i)
            for(int j=0;j<cb;++j)
                scanf("%d",&mb[i][j]);
        int m[ra][cb];
        for(int i=0;i<ra;++i)
            for(int j=0;j<cb;++j)
            {
                m[i][j]=0;
                for(int k=0;k<ca;++k)
                    m[i][j]+=ma[i][k]*mb[k][j];
            }
        printf("%d %d\n",ra,cb);
        for(int i=0;i<ra;++i)
        {
            for(int j=0;j<cb;++j)
            {
                if(j) printf(" ");
                printf("%d",m[i][j]);
            }
            printf("\n");
        }
    }
}