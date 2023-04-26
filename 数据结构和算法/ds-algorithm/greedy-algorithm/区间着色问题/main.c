#include<stdio.h>

typedef struct Node{
	int value;
	struct Node* next;
}Node,*PNode;

/**
 * startTime: 表示每个活动开始时间的数组
 * endTime: 表示每个活动结束时间的数组
 * length: 活动个数；
 * classroom:每个教室的活动表
 * clength: 教室表的长度
 * 返回值：所用教室的个数 ， -1 返回异常,大于clength：教室不够
 * 
*/
int solve(int* startTime, int* endTime, int length, Node** classroom, int clength) {



}

int main(int argc,char* argv[]){
	int count; // 测试数据组数
	int M; // 每组数据的个数
	int classNum; // 每组数据用的教室个数
	int i,j,k; // 循环变量
	
	FILE* pSourceFile = fopen("source.txt", "r");//相对路径
	if (pSourceFile == NULL)
	{
		printf("source.txt not open");
		return 1;
	}
	FILE* pTargetFile = fopen("target.txt", "r"); //结果数据
	if(pTargetFile ==NULL){
		printf("target.txt not open");
	}
	
	fscanf(pSourceFile,"%d\n",&count);
	for(i =0;i<count;i++){
		fscanf(pSourceFile,"%d\n",&M);
		int* startTime =(int*)malloc(sizeof(int)*M); // 每组活动的开始时间
		int* endTime =(int*)malloc(sizeof(int)*M);
		Node** classRoom = (Node**)malloc(sizeof(Node*)*M); // 每组活动的结束时间
		for(j=0;j<M;j++){
			fscanf(pSourceFile,"$d\n",(startTime+j));
		}
		for(j=0;j<M;j++){
			fscanf(pSourceFile,"$d\n",(startTime+j));
		}
		
		for(j=0;j<M;j++){
			*(classRoom+j)=NULL;
		}
		solve(kaishi ,jieshu ,geshu ,jieguoji ,changdu ,deng )	
		free(startTime);
		free(endTime);
		free(classRoom);
		
	}

	fclose(pSourceFile);
	fclose(pTargetFile);
	
	return 0;
}