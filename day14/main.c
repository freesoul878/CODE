#include<stdio.h>
#include<stdbool.h>
//BGN2田忌赛马，深度优先搜素
 int qiwei[3];
int tianji[3];
int best_score = -100;
int best_plan[3];
bool used[3] = {false};
int path[3];
int calc_score(int *plan)
{
    int score = 0;
    for(int i = 0;i<3;i++)
    {
        if(plan[i] > qiwei[i])
        {
            score +=2;

        }
    }
    return score;
}
void dfs(int depth)
{
    
    if(depth == 3)
    {
       int s = calc_score(path);
        if(s > best_score)
        {
            best_score = s;
            for(int i = 0;i<3;i++)
            best_plan[i] = path[i];
        }
        return;
    }
    for(int i = 0;i<3;i++)
    {
        if(!used[i])
        {
            used[i] =true;
            path[depth] = tianji[i];
            dfs(depth+1);
            used[i] = false;
        }
    }
}
int main() {
   
    int i = 0;
    for(i = 0;i<3;i++)
    scanf("%d",&qiwei[i]);
    for(i = 0;i<3;i++)
    scanf("%d",&tianji[i]);
    dfs(0);
    if(calc_score(best_plan)>=2)
    {
        printf("Yes\n");
    }
    else
    printf("No\n");
    return 0;
}