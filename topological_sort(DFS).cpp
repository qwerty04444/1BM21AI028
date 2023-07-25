#include<iostream>
using namespace std;

struct edge
{
    int deg;
    int ver[10];
};

int node_available(int nodes[],int n)
{
    for (int i = 0; i < n; i++)
    {
        if (nodes[i]!= -1)
            return i;
    }
    return 0;
}


bool node_not_in_vn(int vn[],int cn,int n)
{ 
    for(int i=0;i<n;i++)
    {
        if (cn==vn[i])
            return 0;
    }
    return 1;
}

int main()
{
    int n,m,n1,n2,i,j,k,l;
    cout<<"enter number of vertices : ";
    cin>>n;

    struct edge e[n];

    cout<<"enter number of edges : ";
    cin>>m;

    int nodes[n];

    for(int i=0;i<n;i++)
    {
        cout<<"enter the number of indegree vertices for vertex "<<i<<" : ";
        cin>>n1;
        e[i].deg=n1;
        nodes[i]=i;

        for(int j=0;j<n1;j++)
        {
            cout<<"enter the vertex : ";
            cin>>e[i].ver[j];
        }
    }

    int s[n];
    int top=-1;
    int vn[n];
    int vnlen=0;
    int vnc=0;

    


    while (vnlen<n)
    {
        if (top==-1)
        {
            
            k=node_available(nodes,n);
            s[++top]=k;
            nodes[k]=-1;

        }
        int cn=s[top];

        if (e[cn].deg==0 && vnlen<n)
        {
            vn[vnc++]=cn;
            top--;
            cout<<cn;
        }
        
        else
        {
            int n1=sizeof(e[cn].ver)/sizeof(e[cn].ver[0]);
            int flag=0;
            for (i = 0; i < n1; i++)
            {
                l = e[cn].ver[i];
                if (l >= 0 && l < n && node_not_in_vn(vn, l, n))
                {
                    s[++top] = l;
                    nodes[l] = -1;
                    flag = 1;
                    break;
                }
            }


            if(flag==0 && vnlen<n)
            {
                vn[vnc++]=cn;
                top--;
                cout<<cn;
            }
        }
        vnlen=vnc;
        
    }


}
