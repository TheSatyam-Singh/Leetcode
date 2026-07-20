// Last updated: 20/07/2026, 10:39:42
import java.util.*;
class Solution {

    int LOG = 17;
    List<Integer>[] g;
    int[] tin, tout, depth, parent, baseMask;
    int[][] up;
    int[] bit;
    int timer = 0;
    char[] arr;

    void dfs(int u,int p,int cur){
        tin[u]=timer++;
        up[0][u]=p;
        parent[u]=p;
        cur ^= (1<<(arr[u]-'a'));
        baseMask[u]=cur;
        for(int v:g[u]){
            if(v==p) continue;
            depth[v]=depth[u]+1;
            dfs(v,u,cur);
        }
        tout[u]=timer-1;
    }

    void add(int i,int v){
        for(i++;i<bit.length;i+=i&-i) bit[i]^=v;
    }

    int sum(int i){
        int r=0;
        for(i++;i>0;i-=i&-i) r^=bit[i];
        return r;
    }

    void rangeAdd(int l,int r,int v){
        add(l,v);
        add(r+1,v);
    }

    int lca(int a,int b){
        if(depth[a]<depth[b]){
            int t=a;a=b;b=t;
        }
        int d=depth[a]-depth[b];
        for(int k=0;k<LOG;k++){
            if(((d>>k)&1)==1) a=up[k][a];
        }
        if(a==b) return a;
        for(int k=LOG-1;k>=0;k--){
            if(up[k][a]!=up[k][b]){
                a=up[k][a];
                b=up[k][b];
            }
        }
        return up[0][a];
    }

    int curMask(int u){
        return baseMask[u]^sum(tin[u]);
    }

    public List<Boolean> palindromePath(int n, int[][] edges, String s, String[] queries) {
        Object suneravilo = new Object[]{n,edges,s,queries};

        arr = s.toCharArray();
        g = new ArrayList[n];
        for(int i=0;i<n;i++) g[i]=new ArrayList<>();
        for(int[] e:edges){
            g[e[0]].add(e[1]);
            g[e[1]].add(e[0]);
        }

        tin=new int[n];
        tout=new int[n];
        depth=new int[n];
        parent=new int[n];
        baseMask=new int[n];
        up=new int[LOG][n];

        dfs(0,-1,0);

        for(int k=1;k<LOG;k++){
            for(int i=0;i<n;i++){
                int p=up[k-1][i];
                up[k][i]=(p==-1?-1:up[k-1][p]);
            }
        }

        bit=new int[n+5];

        List<Boolean> ans=new ArrayList<>();

        for(String q:queries){
            if(q.charAt(0)=='u'){
                int i=7;
                int u=0;
                while(q.charAt(i)!=' ') u=u*10+(q.charAt(i++)-'0');
                char c=q.charAt(i+1);
                if(arr[u]!=c){
                    int delta=(1<<(arr[u]-'a'))^(1<<(c-'a'));
                    rangeAdd(tin[u],tout[u],delta);
                    arr[u]=c;
                }
            }else{
                int i=6;
                int u=0,v=0;
                while(q.charAt(i)!=' ') u=u*10+(q.charAt(i++)-'0');
                i++;
                while(i<q.length()) v=v*10+(q.charAt(i++)-'0');

                int w=lca(u,v);

                int mu=curMask(u);
                int mv=curMask(v);
                int mw=curMask(w);

                int pathMask = mu ^ mv ^ (1<<(arr[w]-'a'));

                ans.add(Integer.bitCount(pathMask)<=1);
            }
        }
        return ans;
    }
}
