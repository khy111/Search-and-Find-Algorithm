#include<iostream>
#include<algorithm>
using namespace std;

/********************************排序算法***********************************/

//插入排序--升序--O(n^2) --前面的都是有序的，后面的元素依次插入前面相应的位置
void test_insertsort(int a[], int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])//需要调换位置
        {
            temp = a[i];
            int j = i - 1;
            //将小的元素插入到相应的位置 5,4,2,1,2
            while (j >= 0 && temp < a[j])
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;//极值考虑，此时的j有可能取-1；
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
//希尔排序--O(n^(1.3—2))--分组（刚开始一般选长度的一半）（直到分组因子为1时，每次选择插入排序--因为插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率。）
//一般在记录的数量多的情况下，希尔排序的排序效率较直接插入排序高。
void test_shellsort(int a[], int n)
{
    int i, j, inc, key;//inc--分组长度
    //初始增量n/2,每一次/2
    for (int inc = n / 2; inc > 0; inc /= 2)
    {
        //每一趟选择插入排序
        for (i = inc; i < n; i++)//这里不能再写int定义一个局部全量j，会缩小前面的j的作用范围
        {
            key = a[i];
            for (j = i; j >= inc && key < a[j - inc]; j -= inc) //步长为1时好分析
                a[j] = a[j - inc];
            a[j] = key;
        }
    }
}

//冒泡排序--O(n^2) --升序--后面的都是有序的，去前面找剩下的最值加入i-1的位置。
void test_bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)//循环每一个位置,n-1--第一个元素不用比较
    {
        //每次起泡从下标为 0 开始，到 n-i 结束(后面i个元素已经是有序的) j+1--a[j] > a[j + 1]无序的最后一个元素不用比较
        for (int j = 0; j + 1 < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                //交换
                int temp = 0;
                temp = a[j];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
//选择排序--O(n^2)--与冒泡排序相反，前面的是有序的，然后对后面的无序的元素找出最值。
void test_selectionsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)//n 个元素的无序表要遍历 n-1 次
    {
        int index = i;
        for (int j = i; j < n; j++) 
        {
            if (a[j] < a[index])//后面的无序元素都与index比较，找最值，并记录最值下标
            {
                index = j;
            }
        }
        if (index != i)
        {
            int temp;
            temp = a[index];
            a[index] = a[i];
            a[i] = temp;
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
//快速排序--O(nlogn)-是所有时间复杂度相同的排序方法中性能最好的排序算法。
// 开头结尾两个指针，选取一个值作为支点，大的放右边，小的放左边，直到两个指针重合（两边的继续直到两指针重合-迭代的思想）
void test_qsort(int a[], int start, int end)
{
    if (start >= end)//临界条件
    {
        return;
    }
    int baseval = a[start];
    int i = start, j = end;
    while (i < j)
    {
        while (i < j && a[j] >= baseval)//判断右边的数，直到找到小于等于支点值的数才跳出
        {
            j--;
        }
        if (i < j)//将右边小的数放到左边
        {
            a[i] = a[j];
        }
        while (i < j && a[i] < baseval)//判断左边的数，直到找到大于支点值的数才跳出
        {
            i++;
        }
        if (i < j)//将左边大的数放到右边
        {
            a[j] = a[i];
        }
    }
    a[i] = baseval;
    //支点左右两边的元素继续上面步骤
    test_qsort(a, start, i - 1);
    test_qsort(a, i + 1, end);

    for (int i = 0; i < 7; i++)
        cout << a[i] << " ";
    cout << endl;
}

//归并排序--O(nlogn)---先将无序元素分治（迭代的思想，分为一个元素为止），然后两两合并排序
//优点：在记录表中记录 a 在记录 b 的前面（记录 a 和 b 的关键字的值相等），使用归并排序之后
//      记录 a 还在记录 b 的前面。这就体现出了该排序算法的稳定性。而堆排序和快速排序都是不稳定的。

void merge(int a[], int start, int mid, int end)//数组a为两个有序子序列组成，mid为分界点
{
    //(必须为两个有序子序列) eg: 0,2,3,0,1,99  mid=3
    int left_size = mid - start;  //开辟两个新数组，存储数组的有序列子数组
    int right_size = end - mid + 1;
    //int left_arr[left_size];  //报错(局部变量不能开数组大小)，动态分配内存解决
    int* left_arr = new int[left_size];
    int* right_arr = new int[right_size];
    //分别将子序列存入开辟的数组里
    for (int i = start; i < mid; i++)
    {
        left_arr[i - start] = a[i];
    }
    for (int i = mid; i <= end; i++)
    {
        right_arr[i - mid] = a[i];
    }
    int i = 0, j = 0, k = start;//i j 分别指向数组left_arr和right_arr，k指向a(a现在存放的是拍好序的元素):注意k初始值=start,不是0；
    //两种情况-i j都没有到达边界或者ij有一个到达边界
    //i j都没有到达边界
    while (i < left_size && j < right_size)
    {
        if (left_arr[i] > right_arr[j])
        {
            a[k] = right_arr[j];
            j++;
            k++;
        }
        else
        {
            a[k] = left_arr[i];
            i++;
            k++;
        }
    }
    //ij有一个到达边界
    while (i < left_size)
    {
        a[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < right_size)
    {
        a[k] = right_arr[j];
        j++;
        k++;
    }
}
void test_mergesort(int a[], int start, int end)
{
    if (start == end)
        return;
    //分治+合并
    int mid = (start + end) / 2;;  //括号必须加
    test_mergesort(a, start, mid);
    test_mergesort(a, mid + 1, end);
    merge(a, start, mid + 1, end);
}
//堆排序--O(nlogn)-构造大顶堆（每一个父节点都比孩子节点大），取出根节点，循环次步骤 缺点--相对位置不稳定
//1、使用数组存储堆，根节点-a[0],堆必须先存储左孩子再有右孩子。因此：父节点i： i_left_chiled=i*2+1；i_right_child=i*2+2;

/*维护堆的性质
* i--父节点
* n--要维护堆节点元素长度
*/
void heapify(int a[], int i, int n)
{
    int max = i;  //最大节点的下标定为i
    int i_left_child = i * 2 + 1;
    int i_right_child = i * 2 + 2;
    //记录左右孩子是否比父节点大
    if (i_left_child < n && a[max] < a[i_left_child])//防止干扰排好序的元素
        max = i_left_child;
    if (i_right_child < n && a[max] < a[i_right_child])
        max = i_right_child;
    if (i != max)
    {
        int temp;
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        //这里因为交换了孩子接节点，可能破坏了大顶堆的性质，所以还需要迭代一次
        heapify(a, max, n);
    }
}
void test_heapsort(int a[], int n)
{
    //1.建堆,从最后一个父节点开始判断大顶堆的性子
    //n/2-1为最后一个非叶子节点的序号
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, i, n);
    }
    //2.排序
    //交换根节点和最后一个叶子节点的位置
    for (int i = n - 1; i >= 0; i--)
    {
        int temp;
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heapify(a, 0, i);//没有排序的节点个数为i
    }
}

/********************************查找算法***********************************/

//顺序查找--O(n)--遍历数组\链表
int test_sequential_search(int a[], int n, int keyval)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == keyval)
            return i;  //返回下标
    }
    return -1;
}
//二分查找--O(log2n)--双指针（找中点-mid）
int test_binary_search(int a[], int n, int keyval)
{
    if (n < 0) return -1;
    //定义双指针
    int left = 0;
    int right = n - 1; //用的下标
    int mid = ((right - left) >> 1) + left;
    while (left <= right)
    {
        if (keyval == a[mid])
        {
            return mid;
        }
        else if (a[mid] < keyval)
        {
            left = mid + 1;
        }
        else if (a[mid] > keyval)
        {
            right = mid - 1;
        }
    }
}
/*********************************************BST*********************************************************/
//二叉查找（排序、搜索）树-动态过程--[O(log2n),(n)]之间--创建、插入、删除、查找
/*
*二叉排序树中，如果其根结点有左子树，那么左子树上所有结点的值都小于根结点的值；
*二叉排序树中，如果其根结点有右子树，那么右子树上所有结点的值都大小根结点的值；
*二叉排序树的左右子树也要求都是二叉排序树；
*/

typedef struct BinarySearchTree
{
    int data;
    struct BinarySearchTree* left_child, * right_child;
}binary_search_tree;

//插入(创建)
void bst_insert(binary_search_tree*& p, int data)//改变指针的值需要二级指针
{
    if (p == NULL)//插入节点为空
    {
        if ((p = new binary_search_tree) == NULL)
            cout << "Memory error." << endl;
        p->data = data;
        p->left_child = p->right_child = NULL;
    }

    else if (p->data >= data) //根据二叉搜索树的特点左孩子比父节点小，右孩子比父节点大插入
        bst_insert(*(&(p->left_child)), data);//先取地址再取值
    else if (p->data < data)
        bst_insert(*(&(p->right_child)), data);
}
//查找
binary_search_tree* bst_search(binary_search_tree* p, int keyval)
{
    if (p == NULL)
        return NULL;
    if (p->data == keyval)
        return p;
    else if (p->data > keyval)
        bst_search(*(&(p->left_child)), keyval);
    else if (p->data < keyval)
        bst_search(*(&(p->right_child)), keyval);
}
//删除
void delete_bst(binary_search_tree*& p, int del_val)//同理修改值针的地址
{
    if (p == NULL)
        return;
    else if (p->data == del_val)
    {
        if (p->left_child == NULL)//左孩子为空
        {
            binary_search_tree* temp = p;
            p = p->right_child;
            delete temp;
        }
        else//左孩子不为空时
        {
            binary_search_tree* head = p, * next = p->left_child;
            //找左子树的右子叶子节点，如果没有就父节点代替节点p,(为保持其它元素之间的相对位置不变，
            //可按中序遍历保持有序进行调整。比较好的做法是，找到*p的直接前驱（或直接后继）*next，
            //用*next来替换结点*p，然后再删除结点*next)
            while (next->right_child)                    //  eg1:        7      |  eg2:      7
            {                                            //           2     8   |         2     8
                head = next;                             //          1(null)    |       1   4
                next = next->right_child;                //                     |          3 (null)
            }
            p->data = next->data;   //用*next来替换结点*p, eg2: head->data=2;next->data=4
            if (p == head)           //eg1所示：用2替代7，然后删除2;(即*next没有右叶子节点)
                p->left_child = next->left_child;
            else                    //eg2所示：用4替代7，然后删除4；(即*next有右叶子节点)
            {
                head->right_child = next->left_child;
            }
            delete next;//删掉直接前驱
        }
    }
    else if (p->data > del_val)
        delete_bst(*(&(p->left_child)), del_val);
    else if (p->data < del_val)
        delete_bst(*(&(p->right_child)), del_val);

}
//中序遍历输出
void printbst(binary_search_tree* p)
{
    if (p)
    {
        printbst(p->left_child);
        cout << p->data << ' ';
        printbst(p->right_child);
    }
}

//程序入口
void test_bst_search(int a[], int n)
{
    //插入入口
    binary_search_tree* head = NULL;
    for (int i = 0; i < n; i++)
    {
        bst_insert(head, a[i]);
    }
    printbst(head);
    cout << endl;

    //查找入口
   /* binary_search_tree* temp = bst_search(head, 23);
    if(temp!=NULL)
    cout << "Find results:"<<temp->data << endl;
    else
    cout << "Not find. " << endl;*/

    //删除入口
    delete_bst(head, 7);
    printbst(head);
    cout << endl;
}
/*********************************************AVL*********************************************************/
//平衡二叉树(AVL)--O(logn)--就是在二叉排序树(BST)的基础上，任意节点的左右子结点个数差不超过1；
//所以：每一次插入或者删除元素后都要判断是否平衡（不平衡就要旋转）

typedef struct AVL_tree {
    int data;
    struct AVL_tree* leftchild, * rightchild;
    int hight; //记录每个节点的深度
}avl_node, * avl_tree_t;

//统计节点高度
int node_high(const avl_tree_t& root)
{
    if (root == NULL)
        return 0;
    return root->hight;
}
//旋转
avl_tree_t right_rotate(avl_tree_t& head)//右旋+更新高度
{
    if (head == NULL)
        return NULL;
    avl_tree_t temp = head->leftchild;
    head->leftchild = temp->rightchild;
    temp->rightchild = head;

    head->hight = max(node_high(head->leftchild), node_high(head->rightchild)) + 1;
    temp->hight = max(node_high(temp->leftchild), node_high(temp->rightchild)) + 1;
    return temp;
}
avl_tree_t left_rotate(avl_tree_t& head)//左旋+更新高度
{
    if (head == NULL)
        return NULL;
    avl_tree_t temp = head->rightchild;
    head->rightchild = temp->leftchild;
    temp->leftchild = head;

    head->hight = max(node_high(head->leftchild), node_high(head->rightchild)) + 1;
    temp->hight = max(node_high(temp->leftchild), node_high(temp->rightchild)) + 1;
    return temp;
}
avl_tree_t left_right_rotate(avl_tree_t& head)//左右旋
{
    head->leftchild = left_rotate(head->leftchild);
    return right_rotate(head);
}
avl_tree_t right_left_rotate(avl_tree_t head)//右左旋
{
    head->rightchild = right_rotate(head->rightchild);
    return left_rotate(head);
}

avl_tree_t avl_banlance(avl_tree_t head)
{
    //判断平衡
   /**************************************************
   *eg1: 3         4     eg2:4             4
   *   2        2              5              6
   * 1  a        3            a  6           5
   * 情况1      情况2          情况3         情况4
   ***************************************************/
   //左孩子太高
    if (node_high(head->leftchild) - node_high(head->rightchild) >= 2)//  eg1
    {
        if (node_high(head->leftchild->leftchild) > node_high(head->leftchild->rightchild))  //判断是情况1,则需要将head(3)右旋(左左不平衡)
        //if(head->leftchild->data >insertval)
        {

            head = right_rotate(head);
        }
        else //eg1的情况2，先将2左旋，再将4右旋（左右不平衡）
        {
            head = left_right_rotate(head);
        }
    }
    //右孩子太高
    else if (node_high(head->rightchild) - node_high(head->leftchild) >= 2)  //eg2
    {
        if (node_high(head->rightchild->rightchild) > node_high(head->rightchild->leftchild))  //判断是情况3,4-左旋(右右不平衡)
        //if(head->rightchild->data < insertval)
        {
            head = left_rotate(head);
        }
        else //eg1的情况4，先将6右旋，再将4左旋（右左不平衡）
        {
            head = right_left_rotate(head);
        }
    }
    return head;
}


//插入（与BST不同点就是要判断是否平衡）
void avl_insert(avl_tree_t& head, int insertval)
{
    //插入
    if (head == NULL)
    {
        head = new avl_node;
        head->data = insertval;
        head->leftchild = head->rightchild = NULL;
    }
    else if (head->data > insertval)
        avl_insert(head->leftchild, insertval);
    else if (head->data <= insertval)
        avl_insert(head->rightchild, insertval);
    //判断平衡
    head = avl_banlance(head);
    //更新深度
    head->hight = max(node_high(head->leftchild), node_high(head->rightchild)) + 1;
}

//删除
avl_tree_t avl_remove(avl_tree_t head, int remove_val)
{
    //删除元素同BST
    if (head == NULL)
        return NULL;
    if (head->data == remove_val)
    {
        if (head->leftchild == NULL)
        {
            avl_tree_t temp = head;
            head = head->rightchild;
            delete temp;
            temp = NULL;
            return head;  //及时返回，因为深度是根据头结点算的
        }
        else
        {
            //两种情况
            avl_node* s = head, * t = head->leftchild;
            while (t->rightchild)
            {
                s = t;
                t = t->rightchild;
            }
            head->data = t->data;
            if (s = t)
                head->leftchild = t->leftchild;
            else
                s->rightchild = t->leftchild;
            delete t;
        }
    }
    else if (head->data > remove_val)
        head->leftchild = avl_remove(head->leftchild, remove_val);
    else if (head->data < remove_val)
        head->rightchild = avl_remove(head->rightchild, remove_val);

    //删除元素后破坏了平衡，要重新判断平衡（旋转，更新深度）
    head = avl_banlance(head);
    //更新深度
    head->hight = max(node_high(head->leftchild), node_high(head->rightchild)) + 1;
    return head;
}


//中序遍历输出
void print_avl(const avl_tree_t head)
{
    if (head)
    {
        cout << head->data << ' ';
        print_avl(head->leftchild);

        print_avl(head->rightchild);
    }
}
//AVL程序入口
void test_avl_search(int a[], int n)
{
    avl_tree_t p = NULL;
    for (int i = 0; i < n; i++)
    {
        avl_insert(p, a[i]);
    }
    p = avl_remove(p, 7);
    print_avl(p);
}

/*********************************************RBT*********************************************************/
//红黑树--O(lgn)--红黑树适合频繁的插入和删除操作，AVL树适合多查找的情况
/* 五大性质：
*树中的每个结点颜色不是红的，就是黑的；
*根结点的颜色是黑的；（哨兵）
*所有为 nil 的叶子结点的颜色是黑的；（注意：叶子结点说的只是为空（nil 或 NULL）的叶子结点！）
*如果此结点是红的，那么它的两个孩子结点全部都是黑的；（插入节点的时候考虑此条）
*对于每个结点，从该结点到到该结点的所有子孙结点的所有路径上包含有相同数目的黑结点；（删除节点时考虑此条，删除考虑兄弟节点）
*/
typedef enum Node_color { red, black }node_color;
typedef struct Rbt_tree {
    int data;
    struct Rbt_tree* leftchild, * rightchild, * parent;
    enum Node_color color;
}rbt_node, * rbt_tree;

typedef struct RBT_Root {
    rbt_tree root;
    rbt_tree nil;
}rbt_root;
//左旋   flag--0:此时为插入节点；flag--1:此时为删除节点；
void rbt_left_rotate(rbt_root* T, rbt_tree x, int flag)  //注意双向链表
{
    rbt_node* y = x->rightchild;
    x->rightchild = y->leftchild;
    if (x->rightchild != T->nil)
    {
        x->rightchild->parent = x;
    }
    y->parent = x->parent;
    if (y->parent == T->nil)
    {
        T->root = y;
    }
    if (flag == 0)
    {
        if (y->parent->data > y->data)
        {
            y->parent->leftchild = y;
        }
        else if (y->parent->data <= y->data)
        {
            y->parent->rightchild = y;
        }
    }
    else if (flag == 1)
    {
        if (x->parent->leftchild == x)
            y->parent->leftchild = y;
        else if (x->parent->rightchild == x)
            y->parent->rightchild = y;
    }
    y->leftchild = x;
    x->parent = y;
}
//右旋
void rbt_right_rotate(rbt_root* T, rbt_tree x, int flag)  //注意双向链表
{
    rbt_node* y = x->leftchild;
    x->leftchild = y->rightchild;
    if (x->leftchild != T->nil)
    {
        x->leftchild->parent = x;
    }
    y->parent = x->parent;
    if (y->parent == T->nil)
    {
        T->root = y;
    }
    if (flag == 0)
    {
        if (y->parent->data > y->data)
        {
            y->parent->leftchild = y;
        }
        else
        {
            y->parent->rightchild = y;
        }
    }
    else if (flag == 1)
    {
        if (x->parent->leftchild == x)
            y->parent->leftchild = y;
        else if (x->parent->rightchild == x)
            y->parent->rightchild = y;
    }
    y->rightchild = x;
    x->parent = y;
}
//四种情况(都要考虑叔叔节点)
void rbt_insert_adjustment(rbt_root* T, rbt_tree x)
{
    while (x->parent->color == red) //
    {
        if (x->parent == x->parent->parent->leftchild)
        {
            rbt_tree y = x->parent->parent->rightchild;
            if (y->color == red)  //情况1:
            {
                x->parent->color = black;
                y->color = black;
                y->parent->color = red;
                x = x->parent->parent;  //回到while
            }
            else {  //叔叔节点为黑色 //情况2：父节点和主父结点变色，然后右旋
                if (x == x->parent->leftchild)
                {
                    x->parent->color = black;
                    x->parent->parent->color = red;
                    rbt_right_rotate(T, x->parent->parent, 0);
                }
                else {//情况3： 左旋变为情况2
                    x = x->parent;
                    rbt_left_rotate(T, x, 0);
                }
            }
        }
        else { //右边同理，左换右即可
            rbt_tree y = x->parent->parent->leftchild;
            if (y->color == red)
            {
                x->parent->color = black;
                y->color = black;
                x->parent->parent->color = red;
                x = x->parent->parent;  //回到while
            }
            else {
                if (x == x->parent->rightchild)
                {
                    x->parent->color = black;
                    x->parent->parent->color = red;
                    rbt_left_rotate(T, x->parent->parent, 0);
                }
                else {
                    x = x->parent;
                    rbt_right_rotate(T, x, 0);
                }
            }
        }
    }
    T->root->color = black;
}

void rbt_delete_adjustment(rbt_root*& T, rbt_tree x)
{
    while (x != T->root && x->color == black)
    {
        //1.删除节点左，兄弟节点在右
        if (x->parent->leftchild == x)
        {
            rbt_tree y = x->parent->rightchild;  //兄弟节点
            //情况1：兄弟节点为红色--则y的父节点和y的子节点必定为黑色（性质4）
            if (y->color == red) //--将父节点和兄弟节点换颜色，然后左旋--转换为情况2、3、4
            {
                y->color = black;
                y->parent->color = red;
                rbt_left_rotate(T, x->parent, 1);
                y = x->parent->rightchild; //新的兄弟节点，进入while再次判断
            }
            else if (y->color == black)//兄弟节点为黑色
            {   //情况2：兄弟节点为黑色且有两个黑色的子节点
                if (y->leftchild->color == black && y->rightchild->color == black)
                {
                    y->color = red;
                    x = x->parent;
                }
                //情况3：兄弟节点为黑色且左孩子为红色，且右孩子为黑色--转换为情况4
                else if (y->leftchild->color == red && y->rightchild->color == black)
                {
                    y->leftchild->color = black;
                    y->color = red;
                    rbt_right_rotate(T, y, 1);
                    y = x->parent->rightchild; //新的兄弟节点
                }
                //情况4：兄弟节点为黑色且左孩子为黑色且右孩子为红色
                else if (y->rightchild->color == red)
                {
                    y->color = x->parent->color;
                    x->parent->color = black;
                    y->rightchild->color = black;
                    rbt_left_rotate(T, x->parent, 1);
                    x = T->root;
                }
            }
        }
        //2.删除节点右
        else {
            if (x->parent->rightchild == x)
            {
                rbt_tree y = x->parent->leftchild;
                if (y->color == red)
                {
                    y->color = black;
                    x->parent->color = red;
                    rbt_right_rotate(T, x->parent, 1);
                    y = x->parent->leftchild;
                }
                else if (y->color == black)
                {
                    if (y->rightchild->color == black && y->leftchild->color == black)
                    {
                        y->color = red;
                        x = x->parent;
                    }
                    else if (y->rightchild->color == red && y->leftchild->color == black)
                    {
                        y->rightchild->color = black;
                        y->color = red;
                        y = x->parent->leftchild;
                    }
                    else if (y->leftchild->color == red)
                    {
                        y->color = y->parent->color;
                        x->parent->color = black;
                        y->leftchild->color = black;
                        rbt_right_rotate(T, x->parent, 1);
                        x = T->root;
                    }
                }
            }
        }
    }
    x->color = black;//最终将根结点的颜色设为黑色
}
//找右子树的最小节点
rbt_tree find_min_node(rbt_root* T, rbt_tree x)
{
    rbt_tree temp = x->rightchild;
    if (T->root == T->nil)
        return T->nil;
    while (temp->leftchild != T->nil)
    {
        temp = temp->leftchild;
    }
    return temp;
}

//节点代替
void rbt_transplant(rbt_root* T, rbt_tree& x1, rbt_tree& x2)//x2代替x1
{
    if (x1->parent == T->nil)
        T->root = x2;
    else if (x1->parent->leftchild == x1)
        x1->parent->leftchild = x2;
    else if (x1->parent->rightchild == x1)
        x1->parent->rightchild = x2;
    x2->parent = x1->parent;
}

//删除节点
void rbt_delete(rbt_root*& T, int delete_val)
{
    rbt_tree delete_node = T->root;
    rbt_tree x = T->nil;
    //找到要删除的节点
    if (T->root == T->nil)
        return;
    while (delete_node != T->nil && delete_node->data != delete_val)
    {
        if (delete_node->data > delete_val)
            delete_node = delete_node->leftchild;
        else if (delete_node->data <= delete_val)
            delete_node = delete_node->rightchild;
    }
    if (delete_node == T->nil)
    {
        cout << "Not find :" << delete_val << endl;
        return;
    }
    //判断被删除节点的子节点个数
        //1.两个子节点的情况
    if (delete_node->leftchild != T->nil && delete_node->rightchild != T->nil)//找右子树的最小元素替代--转换为2、3
    {
        rbt_tree alternative_node = find_min_node(T, delete_node);
        delete_val = delete_node->data = alternative_node->data;
        delete_node = alternative_node;
    }
    //2.一个子节点的情况(分左右)
    //3.没有子节点的情况也走这里
    if (delete_node->rightchild == T->nil)
    {
        x = delete_node->leftchild;
        rbt_transplant(T, delete_node, delete_node->leftchild);
    }
    else  if (delete_node->leftchild == T->nil)
    {
        x = delete_node->rightchild;
        rbt_transplant(T, delete_node, delete_node->rightchild);
    }
    //判断删除的节点是否为黑色（红色不用处理）
    if (delete_node->color == black)
    {
        rbt_delete_adjustment(T, x);
    }
    delete delete_node;
}
void rbt_insert(rbt_root*& T, int insert_val)
{
    rbt_node* x = T->root;
    rbt_node* temp = x; //保存头节点
    //找到要插入的位置
    while (x != T->nil)
    {
        temp = x;
        if (x->data > insert_val)
        {
            x = x->leftchild;
        }
        else if (x->data <= insert_val)
        {
            x = x->rightchild;
        }
    }
    x = new rbt_node;
    x->data = insert_val;
    x->leftchild = x->rightchild = T->nil;
    x->color = red;
    x->parent = temp;

    //建立与父节点的关系(判断x是父节点的左孩子还是右孩子节点)
    if (T->root == T->nil)
        T->root = x;
    else if (temp->data > insert_val)
    {
        temp->leftchild = x;
    }
    else if (temp->data <= insert_val)
    {
        temp->rightchild = x;
    }
    //插入节点之后，就要维护RBT树的五大性质不被违反
    rbt_insert_adjustment(T, x);
}
//初始化
void rbt_init(rbt_root*& root)
{
    root = new rbt_root;
    //初始化哨兵节点
    root->nil = new rbt_node;
    root->nil->color = black;
    root->nil->data = -1;
    root->nil->leftchild = root->nil->rightchild = root->nil->parent = NULL;
    root->root = root->nil;
}
void pre_printBRT(rbt_root* T, rbt_tree x)
{
    if (x != T->nil)
    {
        pre_printBRT(T, x->leftchild);
        cout << x->data << " ";
        pre_printBRT(T, x->rightchild);
    }
}
//RBT程序入口
void test_RBT_search(int a[], int n)
{
    rbt_root* T;
    //初始化节点
    rbt_init(T);
    for (int i = 0; i < n; i++)
    {
        rbt_insert(T, a[i]);
    }
    rbt_tree x = T->root;
    pre_printBRT(T, x);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        rbt_delete(T, a[i]);
        rbt_tree x = T->root;
        pre_printBRT(T, x);
        cout << endl;
    }
}

//HashTable--插入、删除--O(1)

#define HASH_NULL -1
int HASH_SIZE = 7;
typedef struct HashTable {
    int* arry; //一般动态分配内存
    int num;  //元素个数  
}hashtable;

//初始化
void hash_init(hashtable*& hash_table)
{
    hash_table = new hashtable;
    hash_table->arry = new int[HASH_SIZE];
    hash_table->num = 0;
    for (int i = 0; i < HASH_SIZE; i++)
    {
        hash_table->arry[i] = HASH_NULL;
    }
}
//hash函数--取余数
int hash_function(int key)
{
    return key % HASH_SIZE;
}

//扩展
hashtable* hash_extend(hashtable*& hash_table, hashtable* new_hash_table)
{
    if ((double)hash_table->num / (double)HASH_SIZE > 0.75)
    {
        HASH_SIZE = HASH_SIZE * 2;
        new_hash_table->arry = new int[HASH_SIZE];
        hash_init(new_hash_table);

        int i = 0;
        while (hash_table->num > 0)
        {
            if (hash_table->arry[i] == HASH_NULL)
            {
                i++;
                continue;
            }
            int temp = hash_table->arry[i];
            int ret = hash_function(temp);
            while (new_hash_table->arry[ret] != HASH_NULL)
            {
                ret++;
                ret = hash_function(ret);
            }
            new_hash_table->arry[ret] = temp;
            new_hash_table->num++;
            hash_table->num--;
            i++;
        }
        delete[] hash_table->arry;
    }
    return new_hash_table;
}

//插入元素
void hash_insert(hashtable*& hash_table, int insert_val)
{
    //判断hashtable是否需要扩展
    //装填因子=哈希表中数据的个数/哈希表的长度（装填因子>70%时，扩展一个新的hashtable,减少hash冲突）
    if ((double)hash_table->num / (double)HASH_SIZE > 0.75)
    {
        hashtable* new_hash_table = new hashtable;
        hashtable* hash_table_temp = hash_table;
        hash_table = hash_extend(hash_table, new_hash_table);
        delete hash_table_temp;
    }
    //目标地址
    int index = hash_function(insert_val);
    while (hash_table->arry[index] != HASH_NULL)
    {
        //处理hash冲突---选择开放地址法
        index = hash_function(++index);  //线性探测法--增量取1 
    }
    hash_table->arry[index] = insert_val;
    hash_table->num++;
}
//查找元素 
int hash_table_search(const hashtable& hash_table, int search_val)
{
    if (hash_table.num == 0)
    {
        return -1;
    }
    int val = hash_function(search_val);
    while (hash_table.arry[val] == HASH_NULL || hash_table.arry[val] != search_val)
    {
        //处理hash冲突---选择开放地址法
        val = hash_function(++val);  //线性探测法--增量取1 
        if (val == hash_function(search_val))//循环一圈
        {
            return -1;
        }
    }
    return val;
}
//删除元素
void hash_table_delete(hashtable*& hash_table, int delete_val)
{
    int return_search_val = hash_table_search(*hash_table, delete_val);
    if (return_search_val == -1)
    {
        cout << "Delete faided." << endl;
    }
    else
    {
        hash_table->arry[return_search_val] = HASH_NULL;
        hash_table->num--;
    }
}

//HashTable程序入口
void test_hashtable(int a[], int n)
{
    hashtable* H = NULL;
    hash_init(H);
    for (int i = 0; i < n; i++)
    {
        hash_insert(H, a[i]);
    }

    hash_table_delete(H, 7);

    int ret = hash_table_search(*H, 7);//返回-1-不存在；存在-返回索引
    if (ret == -1)
        cout << "not found." << endl;
    else
        cout << "find value: " << H->arry[ret] << endl;
}



int main(int argc, char* argv[])
{
    int a[] = { 5,3,6,2,4,7 };
    int length = sizeof(a) / sizeof(a[0]);
    //test_insertsort(a,length);
    //test_bubblesort(a, length);
    //test_selectionsort(a, length);
    //test_qsort(a, 0,length-1);
    //merge(a, 0, 3, 5);
    //test_mergesort(a, 0, length - 1);
    //test_heapsort(a, length);
    //test_shellsort(a, length);
    int ans;
    int key = a[3];
    //静态查找算法
    //ans = test_sequential_search(a, length, key);
    //ans = test_binary_search(a, length,key);
    //cout << "find results:" << ans << endl;

     //下面为动态查找算法
     test_bst_search(a,length);  //可以用面向对象的方法实现
     //test_avl_search(a, length);
     //test_RBT_search(a, length);
    //test_hashtable(a, length);

    return 0;
}