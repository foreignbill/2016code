#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
using namespace std;
const int BIT[] = {1,2,4,5};
const int MAX = 362882;
int s[9] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000 };
int jie[9] = { 0,1,2,6,24,120,720,5040,40320 };
int vis[MAX];
int len[MAX];
int four[4];
int lu(int num){
	int result;
	result = num%s[4];
	result += ((num / s[5]) % 10)*s[4];
	result += num / s[8] * s[5];
	result += ((num / s[6]) % 10)*s[6];
	result += ((num / s[4]) % 10)*s[7];
	result += ((num / s[7]) % 10)*s[8];
	return result;
}

int ru(int num){
	int result = num / s[5] * s[5];
	result += num / s[1] % 10;
	result += num / s[4] % 10 * s[1];
	result += num / s[2] % 10 * s[2];
	result += num % 10 * s[3];
	result += num / s[3] % 10 * s[4];

	return result;
}

int ld(int num){
	int result = num / s[6] * s[6] + num % 10;
	result += num / s[2] % 10 * s[1];
	result += num / s[5] % 10 * s[2];
	result += num / s[3] % 10 * s[3];
	result += num / s[1] % 10 * s[4];
	result += num / s[4] % 10 * s[5];
	return result;
}

int rd(int num){
	int result = num % s[3] + num / s[8] * s[8];
	result += num / s[4] % 10 * s[3];
	result += num / s[7] % 10 * s[4];
	result += num / s[5] % 10 * s[5];
	result += num / s[3] % 10 * s[6];
	result += num / s[6] % 10 * s[7];
	return result;
}
int cantor(int key){
	int result, temp[9];
	for (int i = 8; i >= 0; i--){
		temp[i] = key % 10;
		key = key / 10;
	}
	result = 0;
	for (int i = 0; i<8; i++){
		int tot = 0;
		for (int j = i + 1; j<9; j++)
			if (temp[j]<temp[i])
				tot++;
		result += tot*jie[8 - i];
	}
	return result;
}
int key2[4];
int start = 123456789;
queue<int>que;
int main(){
	int temp;
	int key1;
	len[0] = 0;
	que.push(start);
	vis[0] = 1;
	while (!que.empty()){
		temp = que.front();
		que.pop();
		key1 = cantor(temp);
		four[0] = lu(temp);
		four[1] = ru(temp);
		four[2] = ld(temp);
		four[3] = rd(temp);
		for (int i = 0; i<4; i++){
			key2[i] = cantor(four[i]);
			if (!vis[key2[i]]){
				vis[key2[i]] = 1;
				que.push(four[i]);
				len[key2[i]] = len[key1] + 1;
			}
		}
	}
	int start[9];
	while (~scanf("%d",&start[0])){
		temp = start[0];
		for (int i = 1; i<9; i++){
			scanf("%d",&start[i]);
			temp=start[i]+temp*10;
		}
		printf("%d\n", len[cantor(temp)]);
	}
	return 0;
}
