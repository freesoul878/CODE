#include <stdbool.h> // 引入 bool、true 和 false，供队列状态与操作结果使用。
#include <stdio.h> // 引入 printf，供下面的演示程序输出结果。

#define PQ_CAPACITY 1000 // 定义优先队列最多可以保存的整数个数。

typedef struct { // 定义整数优先队列的数据结构。
    int data[PQ_CAPACITY]; // 用数组保存堆中的整数。
    int size; // 记录当前队列中实际保存的元素个数。
} PriorityQueue; // 将这个结构体类型命名为 PriorityQueue。

void priority_queue_init(PriorityQueue *queue) { // 初始化队列，使其成为空队列。
    queue->size = 0; // 空队列中元素个数为零。
} // 结束初始化函数。

bool priority_queue_is_empty(const PriorityQueue *queue) { // 判断队列是否为空。
    return queue->size == 0; // 元素个数为零时返回 true，否则返回 false。
} // 结束判空函数。

bool priority_queue_push(PriorityQueue *queue, int value) { // 将一个整数放入最大优先队列。
    if (queue->size >= PQ_CAPACITY) { // 如果数组已满，就不能再插入元素。
        return false; // 返回 false，表示插入失败。
    } // 结束容量检查。
    int index = queue->size; // 新元素先放到数组末尾。
    queue->data[index] = value; // 将待插入的整数写入末尾位置。
    queue->size++; // 更新队列中的元素个数。
    while (index > 0) { // 只要当前元素不是根节点，就检查它的父节点。
        int parent = (index - 1) / 2; // 根据完全二叉树的数组规则计算父节点下标。
        if (queue->data[parent] >= queue->data[index]) { // 父节点不小于当前节点时，堆性质已满足。
            break; // 停止向上调整。
        } // 结束父子大小比较。
        int temporary = queue->data[parent]; // 暂存父节点的值，准备交换。
        queue->data[parent] = queue->data[index]; // 将较大的当前值移到父节点。
        queue->data[index] = temporary; // 将原父节点的值移到当前节点。
        index = parent; // 继续从父节点位置向上检查。
    } // 结束向上调整循环。
    return true; // 返回 true，表示插入成功。
} // 结束入队函数。

bool priority_queue_peek(const PriorityQueue *queue, int *value) { // 读取队首元素但不移除它。
    if (priority_queue_is_empty(queue)) { // 空队列没有可读取的队首元素。
        return false; // 返回 false，表示读取失败。
    } // 结束空队列检查。
    *value = queue->data[0]; // 最大堆的根节点就是当前优先级最高的整数。
    return true; // 返回 true，表示读取成功。
} // 结束查看队首函数。

bool priority_queue_pop(PriorityQueue *queue, int *value) { // 移除并取出当前优先级最高的整数。
    if (priority_queue_is_empty(queue)) { // 空队列没有可移除的元素。
        return false; // 返回 false，表示出队失败。
    } // 结束空队列检查。
    *value = queue->data[0]; // 先把根节点保存到调用者提供的位置。
    queue->size--; // 移除根节点后，队列元素个数减一。
    if (queue->size == 0) { // 如果移除后队列为空，就不需要再调整堆。
        return true; // 返回 true，表示出队成功。
    } // 结束空堆处理。
    queue->data[0] = queue->data[queue->size]; // 将最后一个元素移到根节点位置。
    int index = 0; // 从根节点开始向下恢复最大堆性质。
    while (true) { // 持续向下调整，直到父节点不小于两个子节点。
        int left = index * 2 + 1; // 计算左子节点的数组下标。
        int right = index * 2 + 2; // 计算右子节点的数组下标。
        int largest = index; // 先假设当前节点是三者中最大的。
        if (left < queue->size && queue->data[left] > queue->data[largest]) { // 左子节点存在且更大时。
            largest = left; // 记录左子节点为当前最大节点。
        } // 结束左子节点比较。
        if (right < queue->size && queue->data[right] > queue->data[largest]) { // 右子节点存在且更大时。
            largest = right; // 记录右子节点为当前最大节点。
        } // 结束右子节点比较。
        if (largest == index) { // 当前节点已经不小于两个子节点。
            break; // 堆性质恢复完成，结束调整。
        } // 结束调整完成检查。
        int temporary = queue->data[index]; // 暂存当前节点的值，准备交换。
        queue->data[index] = queue->data[largest]; // 将较大的子节点移到父节点位置。
        queue->data[largest] = temporary; // 将原父节点的值移到子节点位置。
        index = largest; // 继续从交换后的子节点位置向下检查。
    } // 结束向下调整循环。
    return true; // 返回 true，表示出队成功。
} // 结束出队函数。

int main(void) { // 程序入口，同时演示优先队列的基本用法。
    PriorityQueue queue; // 创建一个整数优先队列变量。
    priority_queue_init(&queue); // 初始化队列后才能进行其他操作。
    priority_queue_push(&queue, 12); // 插入整数 12。
    priority_queue_push(&queue, 3); // 插入整数 3。
    priority_queue_push(&queue, 25); // 插入整数 25。
    priority_queue_push(&queue, 8); // 插入整数 8。
    int value; // 声明一个变量，用来接收查看或取出的整数。
    if (priority_queue_peek(&queue, &value)) { // 查看队首，成功时进入分支。
        printf("当前最高优先级：%d\n", value); // 输出最大堆当前的队首值。
    } // 结束查看队首示例。
    while (priority_queue_pop(&queue, &value)) { // 只要出队成功，就继续处理下一个元素。
        printf("出队：%d\n", value); // 输出出队元素，顺序应从大到小。
    } // 结束出队演示，队列此时为空。
    return 0; // 返回零，表示程序正常结束。
} // 结束 main 函数。