#include<cstdio>
#include<cstring>
int g[5][5];
int hang1[10],hang2[10],lie1[10],lie2[10],zheng1[10],zheng2[10],fan1[10],fan2[10];

int main(){
	freopen("input.txt","r",stdin);
	int T;
	char ch;
	scanf("%d\n",&T);
	while (T--){
		memset(hang1,0,sizeof(hang1));
		memset(hang2,0,sizeof(hang2));
		memset(lie1,0,sizeof(lie1));
		memset(lie2,0,sizeof(lie2));
		memset(zheng1,0,sizeof(zheng1));
		memset(zheng2,0,sizeof(zheng2));
		memset(fan1,0,sizeof(fan1));
		memset(fan2,0,sizeof(fan2));
		memset(g,0,sizeof(g));
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				ch=getchar();
				if(ch=='.') g[i][j]=0;
				if(ch=='o '){
					g[i][j]=1;
					hang1[i]++;
					lie1[j]++;
					zheng1[i+j]++;
					fan1[3-i+j]++;
				}
				if(ch=='x'){
					g[i][j]=2;
					hang2[i]++;
					lie2[j]++;
					zheng2[i+j]++;
					fan2[3-i+j]++;
				}
				getchar();
			}
			//getchar();
		}
		ch=getchar();
		if(ch=='o'){
			bool flag=0;
			for(int i=1;i<=9;i++){
				if(zheng1[i]==2&&zheng2[i]==0)flag=1;
				if(fan1[i]==2&&fan2[i]==0)flag=1;
				if(hang1[i]==2&&hang2[i]==0)flag=1;
				if(lie1[i]==2&&lie2[i]==0)flag=1;
			}
			if(hang1[2]==2&&hang2[2]==1&&(hang2[1]==0&&hang2[3]==0)) flag=1;
			if(lie1[2]==2&&lie2[2]==1&&(lie2[1]==0&&lie2[3]==0)) flag=1;
			puts(flag?"o win!":"tie!");
		}
		else{
			bool flag=0;
			for(int i=1;i<=9;i++){
				if(hang2[i]==2&&hang1[i]==0)flag=1;
				if(lie2[i]==2&&lie1[i]==0)flag=1;
				if(zheng2[i]==2&&zheng1[i]==0)flag=1;
				if(fan2[i]==2&&fan1[i]==0)flag=1;
			}
			if(hang2[2]==2&&hang1[2]==1&&(hang1[1]==0||hang1[3]==0)) flag=1;
			if(lie2[2]==2&&lie1[2]==1&&(lie1[1]==0||lie1[3]==0)) flag=1;
			puts(flag?"x win!":"tie!");
		}
	}
	return 0;
}
