#include <stdio.h>
//#define MAXN 1000005          /* 按题目操作数上界给，够用即可 */
//
//int heap[MAXN];
//int sz = 0;                   /* 当前堆大小；下标从 1 开始 */
//
///* 插入：末尾上浮 */
//void push(int x) {
//    int i = ++sz;
//    heap[i] = x;
//    while (i > 1 && heap[i] < heap[i / 2]) {
//        int t = heap[i]; heap[i] = heap[i / 2]; heap[i / 2] = t;
//        i /= 2;
//    }
//}
//
///* 删除堆顶（最小）：末元素搬到根，再下沉 */
//void pop(void) {
//    if (sz == 0) return;
//    heap[1] = heap[sz--];     /* ⚠️ 先赋值再减 sz，顺序不能反 */
//    int i = 1;
//    while (1) {
//        int l = i * 2, r = i * 2 + 1, s = i;
//        if (l <= sz && heap[l] < heap[s]) s = l;
//        if (r <= sz && heap[r] < heap[s]) s = r;
//        if (s == i) break;                  /* 已满足堆性质 */
//        int t = heap[i]; heap[i] = heap[s]; heap[s] = t;
//        i = s;
//    }
//}
//
//int top(void) { return heap[1]; }
//noob106
//int main(void) {
//    int n, i, op, x;
//    if (scanf("%d", &n) != 1) return 0;
//    for (i = 0; i < n; i++) {
//        scanf("%d", &op);
//        if (op == 1) {
//            scanf("%d", &x);
//            push(x);
//        }
//        else if (op == 2) {
//            if (sz > 0) printf("%d\n", top());
//        }
//        else if (op == 3) {
//            pop();
//        }
//    }
//    return 0;
//}
//noob109
#define MAXN 200005

int mnv[MAXN], mni[MAXN], mn_sz = 0;   /* 小根堆：值 + id */
int mxv[MAXN], mxi[MAXN], mx_sz = 0;   /* 大根堆：值 + id */
char alive[MAXN];
int idc = 0;

void mn_push(int v, int id) {
    int i = ++mn_sz; mnv[i] = v; mni[i] = id;
    while (i > 1) {
        int p = i / 2;
        if (mnv[i] < mnv[p]) {
            int t = mnv[i]; mnv[i] = mnv[p]; mnv[p] = t;
            t = mni[i]; mni[i] = mni[p]; mni[p] = t;
            i = p;
        }
        else break;
    }
}
void mn_pop(void) {
    mnv[1] = mnv[mn_sz]; mni[1] = mni[mn_sz]; mn_sz--;
    int i = 1;
    while (1) {
        int l = i * 2, r = i * 2 + 1, s = i;
        if (l <= mn_sz && mnv[l] < mnv[s]) s = l;
        if (r <= mn_sz && mnv[r] < mnv[s]) s = r;
        if (s == i) break;
        int t = mnv[i]; mnv[i] = mnv[s]; mnv[s] = t;
        t = mni[i]; mni[i] = mni[s]; mni[s] = t;
        i = s;
    }
}
void mx_push(int v, int id) {
    int i = ++mx_sz; mxv[i] = v; mxi[i] = id;
    while (i > 1) {
        int p = i / 2;
        if (mxv[i] > mxv[p]) {
            int t = mxv[i]; mxv[i] = mxv[p]; mxv[p] = t;
            t = mxi[i]; mxi[i] = mxi[p]; mxi[p] = t;
            i = p;
        }
        else break;
    }
}
void mx_pop(void) {
    mxv[1] = mxv[mx_sz]; mxi[1] = mxi[mx_sz]; mx_sz--;
    int i = 1;
    while (1) {
        int l = i * 2, r = i * 2 + 1, s = i;
        if (l <= mx_sz && mxv[l] > mxv[s]) s = l;
        if (r <= mx_sz && mxv[r] > mxv[s]) s = r;
        if (s == i) break;
        int t = mxv[i]; mxv[i] = mxv[s]; mxv[s] = t;
        t = mxi[i]; mxi[i] = mxi[s]; mxi[s] = t;
        i = s;
    }
}

int main(void) {
    int n, op, x;
    if (scanf("%d", &n) != 1) return 0;
    while (n--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            alive[++idc] = 1;
            mn_push(x, idc);
            mx_push(x, idc);
        }
        else if (op == 2 || op == 4) {
            while (mn_sz > 0 && !alive[mni[1]]) mn_pop();
            if (mn_sz > 0) {
                if (op == 2) printf("%d\n", mnv[1]);
                else { alive[mni[1]] = 0; mn_pop(); }
            }
        }
        else {
            while (mx_sz > 0 && !alive[mxi[1]]) mx_pop();
            if (mx_sz > 0) {
                if (op == 3) printf("%d\n", mxv[1]);
                else { alive[mxi[1]] = 0; mx_pop(); }
            }
        }
    }
    return 0;
}