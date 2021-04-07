#include<iostream>
#include<algorithm>
using namespace std;

/********************************�����㷨***********************************/

//��������--����--O(n^2) --ǰ��Ķ�������ģ������Ԫ�����β���ǰ����Ӧ��λ��
void test_insertsort(int a[], int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])//��Ҫ����λ��
        {
            temp = a[i];
            int j = i - 1;
            //��С��Ԫ�ز��뵽��Ӧ��λ�� 5,4,2,1,2
            while (j >= 0 && temp < a[j])
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;//��ֵ���ǣ���ʱ��j�п���ȡ-1��
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
//ϣ������--O(n^(1.3��2))--���飨�տ�ʼһ��ѡ���ȵ�һ�룩��ֱ����������Ϊ1ʱ��ÿ��ѡ���������--��Ϊ���������ڶԼ����Ѿ��ź�������ݲ���ʱ��Ч�ʸߣ������Դﵽ���������Ч�ʡ���
//һ���ڼ�¼�������������£�ϣ�����������Ч�ʽ�ֱ�Ӳ�������ߡ�
void test_shellsort(int a[], int n)
{
    int i, j, inc, key;//inc--���鳤��
    //��ʼ����n/2,ÿһ��/2
    for (int inc = n / 2; inc > 0; inc /= 2)
    {
        //ÿһ��ѡ���������
        for (i = inc; i < n; i++)//���ﲻ����дint����һ���ֲ�ȫ��j������Сǰ���j�����÷�Χ
        {
            key = a[i];
            for (j = i; j >= inc && key < a[j - inc]; j -= inc) //����Ϊ1ʱ�÷���
                a[j] = a[j - inc];
            a[j] = key;
        }
    }
}

//ð������--O(n^2) --����--����Ķ�������ģ�ȥǰ����ʣ�µ���ֵ����i-1��λ�á�
void test_bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)//ѭ��ÿһ��λ��,n-1--��һ��Ԫ�ز��ñȽ�
    {
        //ÿ�����ݴ��±�Ϊ 0 ��ʼ���� n-i ����(����i��Ԫ���Ѿ��������) j+1--a[j] > a[j + 1]��������һ��Ԫ�ز��ñȽ�
        for (int j = 0; j + 1 < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                //����
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
//ѡ������--O(n^2)--��ð�������෴��ǰ���������ģ�Ȼ��Ժ���������Ԫ���ҳ���ֵ��
void test_selectionsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)//n ��Ԫ�ص������Ҫ���� n-1 ��
    {
        int index = i;
        for (int j = i; j < n; j++) 
        {
            if (a[j] < a[index])//���������Ԫ�ض���index�Ƚϣ�����ֵ������¼��ֵ�±�
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
//��������--O(nlogn)-������ʱ�临�Ӷ���ͬ�����򷽷���������õ������㷨��
// ��ͷ��β����ָ�룬ѡȡһ��ֵ��Ϊ֧�㣬��ķ��ұߣ�С�ķ���ߣ�ֱ������ָ���غϣ����ߵļ���ֱ����ָ���غ�-������˼�룩
void test_qsort(int a[], int start, int end)
{
    if (start >= end)//�ٽ�����
    {
        return;
    }
    int baseval = a[start];
    int i = start, j = end;
    while (i < j)
    {
        while (i < j && a[j] >= baseval)//�ж��ұߵ�����ֱ���ҵ�С�ڵ���֧��ֵ����������
        {
            j--;
        }
        if (i < j)//���ұ�С�����ŵ����
        {
            a[i] = a[j];
        }
        while (i < j && a[i] < baseval)//�ж���ߵ�����ֱ���ҵ�����֧��ֵ����������
        {
            i++;
        }
        if (i < j)//����ߴ�����ŵ��ұ�
        {
            a[j] = a[i];
        }
    }
    a[i] = baseval;
    //֧���������ߵ�Ԫ�ؼ������沽��
    test_qsort(a, start, i - 1);
    test_qsort(a, i + 1, end);

    for (int i = 0; i < 7; i++)
        cout << a[i] << " ";
    cout << endl;
}

//�鲢����--O(nlogn)---�Ƚ�����Ԫ�ط��Σ�������˼�룬��Ϊһ��Ԫ��Ϊֹ����Ȼ�������ϲ�����
//�ŵ㣺�ڼ�¼���м�¼ a �ڼ�¼ b ��ǰ�棨��¼ a �� b �Ĺؼ��ֵ�ֵ��ȣ���ʹ�ù鲢����֮��
//      ��¼ a ���ڼ�¼ b ��ǰ�档������ֳ��˸������㷨���ȶ��ԡ���������Ϳ��������ǲ��ȶ��ġ�

void merge(int a[], int start, int mid, int end)//����aΪ����������������ɣ�midΪ�ֽ��
{
    //(����Ϊ��������������) eg: 0,2,3,0,1,99  mid=3
    int left_size = mid - start;  //�������������飬�洢�����������������
    int right_size = end - mid + 1;
    //int left_arr[left_size];  //����(�ֲ��������ܿ������С)����̬�����ڴ���
    int* left_arr = new int[left_size];
    int* right_arr = new int[right_size];
    //�ֱ������д��뿪�ٵ�������
    for (int i = start; i < mid; i++)
    {
        left_arr[i - start] = a[i];
    }
    for (int i = mid; i <= end; i++)
    {
        right_arr[i - mid] = a[i];
    }
    int i = 0, j = 0, k = start;//i j �ֱ�ָ������left_arr��right_arr��kָ��a(a���ڴ�ŵ����ĺ����Ԫ��):ע��k��ʼֵ=start,����0��
    //�������-i j��û�е���߽����ij��һ������߽�
    //i j��û�е���߽�
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
    //ij��һ������߽�
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
    //����+�ϲ�
    int mid = (start + end) / 2;;  //���ű����
    test_mergesort(a, start, mid);
    test_mergesort(a, mid + 1, end);
    merge(a, start, mid + 1, end);
}
//������--O(nlogn)-����󶥶ѣ�ÿһ�����ڵ㶼�Ⱥ��ӽڵ�󣩣�ȡ�����ڵ㣬ѭ���β��� ȱ��--���λ�ò��ȶ�
//1��ʹ������洢�ѣ����ڵ�-a[0],�ѱ����ȴ洢���������Һ��ӡ���ˣ����ڵ�i�� i_left_chiled=i*2+1��i_right_child=i*2+2;

/*ά���ѵ�����
* i--���ڵ�
* n--Ҫά���ѽڵ�Ԫ�س���
*/
void heapify(int a[], int i, int n)
{
    int max = i;  //���ڵ���±궨Ϊi
    int i_left_child = i * 2 + 1;
    int i_right_child = i * 2 + 2;
    //��¼���Һ����Ƿ�ȸ��ڵ��
    if (i_left_child < n && a[max] < a[i_left_child])//��ֹ�����ź����Ԫ��
        max = i_left_child;
    if (i_right_child < n && a[max] < a[i_right_child])
        max = i_right_child;
    if (i != max)
    {
        int temp;
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        //������Ϊ�����˺��ӽӽڵ㣬�����ƻ��˴󶥶ѵ����ʣ����Ի���Ҫ����һ��
        heapify(a, max, n);
    }
}
void test_heapsort(int a[], int n)
{
    //1.����,�����һ�����ڵ㿪ʼ�жϴ󶥶ѵ�����
    //n/2-1Ϊ���һ����Ҷ�ӽڵ�����
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, i, n);
    }
    //2.����
    //�������ڵ�����һ��Ҷ�ӽڵ��λ��
    for (int i = n - 1; i >= 0; i--)
    {
        int temp;
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heapify(a, 0, i);//û������Ľڵ����Ϊi
    }
}

/********************************�����㷨***********************************/

//˳�����--O(n)--��������\����
int test_sequential_search(int a[], int n, int keyval)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == keyval)
            return i;  //�����±�
    }
    return -1;
}
//���ֲ���--O(log2n)--˫ָ�루���е�-mid��
int test_binary_search(int a[], int n, int keyval)
{
    if (n < 0) return -1;
    //����˫ָ��
    int left = 0;
    int right = n - 1; //�õ��±�
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
//������ң�������������-��̬����--[O(log2n),(n)]֮��--���������롢ɾ��������
/*
*�����������У����������������������ô�����������н���ֵ��С�ڸ�����ֵ��
*�����������У����������������������ô�����������н���ֵ����С������ֵ��
*��������������������ҲҪ���Ƕ�����������
*/

typedef struct BinarySearchTree
{
    int data;
    struct BinarySearchTree* left_child, * right_child;
}binary_search_tree;

//����(����)
void bst_insert(binary_search_tree*& p, int data)//�ı�ָ���ֵ��Ҫ����ָ��
{
    if (p == NULL)//����ڵ�Ϊ��
    {
        if ((p = new binary_search_tree) == NULL)
            cout << "Memory error." << endl;
        p->data = data;
        p->left_child = p->right_child = NULL;
    }

    else if (p->data >= data) //���ݶ������������ص����ӱȸ��ڵ�С���Һ��ӱȸ��ڵ�����
        bst_insert(*(&(p->left_child)), data);//��ȡ��ַ��ȡֵ
    else if (p->data < data)
        bst_insert(*(&(p->right_child)), data);
}
//����
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
//ɾ��
void delete_bst(binary_search_tree*& p, int del_val)//ͬ���޸�ֵ��ĵ�ַ
{
    if (p == NULL)
        return;
    else if (p->data == del_val)
    {
        if (p->left_child == NULL)//����Ϊ��
        {
            binary_search_tree* temp = p;
            p = p->right_child;
            delete temp;
        }
        else//���Ӳ�Ϊ��ʱ
        {
            binary_search_tree* head = p, * next = p->left_child;
            //��������������Ҷ�ӽڵ㣬���û�о͸��ڵ����ڵ�p,(Ϊ��������Ԫ��֮������λ�ò��䣬
            //�ɰ������������������е������ȽϺõ������ǣ��ҵ�*p��ֱ��ǰ������ֱ�Ӻ�̣�*next��
            //��*next���滻���*p��Ȼ����ɾ�����*next)
            while (next->right_child)                    //  eg1:        7      |  eg2:      7
            {                                            //           2     8   |         2     8
                head = next;                             //          1(null)    |       1   4
                next = next->right_child;                //                     |          3 (null)
            }
            p->data = next->data;   //��*next���滻���*p, eg2: head->data=2;next->data=4
            if (p == head)           //eg1��ʾ����2���7��Ȼ��ɾ��2;(��*nextû����Ҷ�ӽڵ�)
                p->left_child = next->left_child;
            else                    //eg2��ʾ����4���7��Ȼ��ɾ��4��(��*next����Ҷ�ӽڵ�)
            {
                head->right_child = next->left_child;
            }
            delete next;//ɾ��ֱ��ǰ��
        }
    }
    else if (p->data > del_val)
        delete_bst(*(&(p->left_child)), del_val);
    else if (p->data < del_val)
        delete_bst(*(&(p->right_child)), del_val);

}
//����������
void printbst(binary_search_tree* p)
{
    if (p)
    {
        printbst(p->left_child);
        cout << p->data << ' ';
        printbst(p->right_child);
    }
}

//�������
void test_bst_search(int a[], int n)
{
    //�������
    binary_search_tree* head = NULL;
    for (int i = 0; i < n; i++)
    {
        bst_insert(head, a[i]);
    }
    printbst(head);
    cout << endl;

    //�������
   /* binary_search_tree* temp = bst_search(head, 23);
    if(temp!=NULL)
    cout << "Find results:"<<temp->data << endl;
    else
    cout << "Not find. " << endl;*/

    //ɾ�����
    delete_bst(head, 7);
    printbst(head);
    cout << endl;
}
/*********************************************AVL*********************************************************/
//ƽ�������(AVL)--O(logn)--�����ڶ���������(BST)�Ļ����ϣ�����ڵ�������ӽ����������1��
//���ԣ�ÿһ�β������ɾ��Ԫ�غ�Ҫ�ж��Ƿ�ƽ�⣨��ƽ���Ҫ��ת��

typedef struct AVL_tree {
    int data;
    struct AVL_tree* leftchild, * rightchild;
    int hight; //��¼ÿ���ڵ�����
}avl_node, * avl_tree_t;

//ͳ�ƽڵ�߶�
int node_high(const avl_tree_t& root)
{
    if (root == NULL)
        return 0;
    return root->hight;
}
//��ת
avl_tree_t right_rotate(avl_tree_t& head)//����+���¸߶�
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
avl_tree_t left_rotate(avl_tree_t& head)//����+���¸߶�
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
avl_tree_t left_right_rotate(avl_tree_t& head)//������
{
    head->leftchild = left_rotate(head->leftchild);
    return right_rotate(head);
}
avl_tree_t right_left_rotate(avl_tree_t head)//������
{
    head->rightchild = right_rotate(head->rightchild);
    return left_rotate(head);
}

avl_tree_t avl_banlance(avl_tree_t head)
{
    //�ж�ƽ��
   /**************************************************
   *eg1: 3         4     eg2:4             4
   *   2        2              5              6
   * 1  a        3            a  6           5
   * ���1      ���2          ���3         ���4
   ***************************************************/
   //����̫��
    if (node_high(head->leftchild) - node_high(head->rightchild) >= 2)//  eg1
    {
        if (node_high(head->leftchild->leftchild) > node_high(head->leftchild->rightchild))  //�ж������1,����Ҫ��head(3)����(����ƽ��)
        //if(head->leftchild->data >insertval)
        {

            head = right_rotate(head);
        }
        else //eg1�����2���Ƚ�2�������ٽ�4���������Ҳ�ƽ�⣩
        {
            head = left_right_rotate(head);
        }
    }
    //�Һ���̫��
    else if (node_high(head->rightchild) - node_high(head->leftchild) >= 2)  //eg2
    {
        if (node_high(head->rightchild->rightchild) > node_high(head->rightchild->leftchild))  //�ж������3,4-����(���Ҳ�ƽ��)
        //if(head->rightchild->data < insertval)
        {
            head = left_rotate(head);
        }
        else //eg1�����4���Ƚ�6�������ٽ�4����������ƽ�⣩
        {
            head = right_left_rotate(head);
        }
    }
    return head;
}


//���루��BST��ͬ�����Ҫ�ж��Ƿ�ƽ�⣩
void avl_insert(avl_tree_t& head, int insertval)
{
    //����
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
    //�ж�ƽ��
    head = avl_banlance(head);
    //�������
    head->hight = max(node_high(head->leftchild), node_high(head->rightchild)) + 1;
}

//ɾ��
avl_tree_t avl_remove(avl_tree_t head, int remove_val)
{
    //ɾ��Ԫ��ͬBST
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
            return head;  //��ʱ���أ���Ϊ����Ǹ���ͷ������
        }
        else
        {
            //�������
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

    //ɾ��Ԫ�غ��ƻ���ƽ�⣬Ҫ�����ж�ƽ�⣨��ת��������ȣ�
    head = avl_banlance(head);
    //�������
    head->hight = max(node_high(head->leftchild), node_high(head->rightchild)) + 1;
    return head;
}


//����������
void print_avl(const avl_tree_t head)
{
    if (head)
    {
        cout << head->data << ' ';
        print_avl(head->leftchild);

        print_avl(head->rightchild);
    }
}
//AVL�������
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
//�����--O(lgn)--������ʺ�Ƶ���Ĳ����ɾ��������AVL���ʺ϶���ҵ����
/* ������ʣ�
*���е�ÿ�������ɫ���Ǻ�ģ����Ǻڵģ�
*��������ɫ�Ǻڵģ����ڱ���
*����Ϊ nil ��Ҷ�ӽ�����ɫ�Ǻڵģ���ע�⣺Ҷ�ӽ��˵��ֻ��Ϊ�գ�nil �� NULL����Ҷ�ӽ�㣡��
*����˽���Ǻ�ģ���ô�����������ӽ��ȫ�����Ǻڵģ�������ڵ��ʱ���Ǵ�����
*����ÿ����㣬�Ӹý�㵽���ý������������������·���ϰ�������ͬ��Ŀ�ĺڽ�㣻��ɾ���ڵ�ʱ���Ǵ�����ɾ�������ֵܽڵ㣩
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
//����   flag--0:��ʱΪ����ڵ㣻flag--1:��ʱΪɾ���ڵ㣻
void rbt_left_rotate(rbt_root* T, rbt_tree x, int flag)  //ע��˫������
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
//����
void rbt_right_rotate(rbt_root* T, rbt_tree x, int flag)  //ע��˫������
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
//�������(��Ҫ��������ڵ�)
void rbt_insert_adjustment(rbt_root* T, rbt_tree x)
{
    while (x->parent->color == red) //
    {
        if (x->parent == x->parent->parent->leftchild)
        {
            rbt_tree y = x->parent->parent->rightchild;
            if (y->color == red)  //���1:
            {
                x->parent->color = black;
                y->color = black;
                y->parent->color = red;
                x = x->parent->parent;  //�ص�while
            }
            else {  //����ڵ�Ϊ��ɫ //���2�����ڵ����������ɫ��Ȼ������
                if (x == x->parent->leftchild)
                {
                    x->parent->color = black;
                    x->parent->parent->color = red;
                    rbt_right_rotate(T, x->parent->parent, 0);
                }
                else {//���3�� ������Ϊ���2
                    x = x->parent;
                    rbt_left_rotate(T, x, 0);
                }
            }
        }
        else { //�ұ�ͬ�����Ҽ���
            rbt_tree y = x->parent->parent->leftchild;
            if (y->color == red)
            {
                x->parent->color = black;
                y->color = black;
                x->parent->parent->color = red;
                x = x->parent->parent;  //�ص�while
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
        //1.ɾ���ڵ����ֵܽڵ�����
        if (x->parent->leftchild == x)
        {
            rbt_tree y = x->parent->rightchild;  //�ֵܽڵ�
            //���1���ֵܽڵ�Ϊ��ɫ--��y�ĸ��ڵ��y���ӽڵ�ض�Ϊ��ɫ������4��
            if (y->color == red) //--�����ڵ���ֵܽڵ㻻��ɫ��Ȼ������--ת��Ϊ���2��3��4
            {
                y->color = black;
                y->parent->color = red;
                rbt_left_rotate(T, x->parent, 1);
                y = x->parent->rightchild; //�µ��ֵܽڵ㣬����while�ٴ��ж�
            }
            else if (y->color == black)//�ֵܽڵ�Ϊ��ɫ
            {   //���2���ֵܽڵ�Ϊ��ɫ����������ɫ���ӽڵ�
                if (y->leftchild->color == black && y->rightchild->color == black)
                {
                    y->color = red;
                    x = x->parent;
                }
                //���3���ֵܽڵ�Ϊ��ɫ������Ϊ��ɫ�����Һ���Ϊ��ɫ--ת��Ϊ���4
                else if (y->leftchild->color == red && y->rightchild->color == black)
                {
                    y->leftchild->color = black;
                    y->color = red;
                    rbt_right_rotate(T, y, 1);
                    y = x->parent->rightchild; //�µ��ֵܽڵ�
                }
                //���4���ֵܽڵ�Ϊ��ɫ������Ϊ��ɫ���Һ���Ϊ��ɫ
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
        //2.ɾ���ڵ���
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
    x->color = black;//���ս���������ɫ��Ϊ��ɫ
}
//������������С�ڵ�
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

//�ڵ����
void rbt_transplant(rbt_root* T, rbt_tree& x1, rbt_tree& x2)//x2����x1
{
    if (x1->parent == T->nil)
        T->root = x2;
    else if (x1->parent->leftchild == x1)
        x1->parent->leftchild = x2;
    else if (x1->parent->rightchild == x1)
        x1->parent->rightchild = x2;
    x2->parent = x1->parent;
}

//ɾ���ڵ�
void rbt_delete(rbt_root*& T, int delete_val)
{
    rbt_tree delete_node = T->root;
    rbt_tree x = T->nil;
    //�ҵ�Ҫɾ���Ľڵ�
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
    //�жϱ�ɾ���ڵ���ӽڵ����
        //1.�����ӽڵ�����
    if (delete_node->leftchild != T->nil && delete_node->rightchild != T->nil)//������������СԪ�����--ת��Ϊ2��3
    {
        rbt_tree alternative_node = find_min_node(T, delete_node);
        delete_val = delete_node->data = alternative_node->data;
        delete_node = alternative_node;
    }
    //2.һ���ӽڵ�����(������)
    //3.û���ӽڵ�����Ҳ������
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
    //�ж�ɾ���Ľڵ��Ƿ�Ϊ��ɫ����ɫ���ô���
    if (delete_node->color == black)
    {
        rbt_delete_adjustment(T, x);
    }
    delete delete_node;
}
void rbt_insert(rbt_root*& T, int insert_val)
{
    rbt_node* x = T->root;
    rbt_node* temp = x; //����ͷ�ڵ�
    //�ҵ�Ҫ�����λ��
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

    //�����븸�ڵ�Ĺ�ϵ(�ж�x�Ǹ��ڵ�����ӻ����Һ��ӽڵ�)
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
    //����ڵ�֮�󣬾�Ҫά��RBT����������ʲ���Υ��
    rbt_insert_adjustment(T, x);
}
//��ʼ��
void rbt_init(rbt_root*& root)
{
    root = new rbt_root;
    //��ʼ���ڱ��ڵ�
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
//RBT�������
void test_RBT_search(int a[], int n)
{
    rbt_root* T;
    //��ʼ���ڵ�
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

//HashTable--���롢ɾ��--O(1)

#define HASH_NULL -1
int HASH_SIZE = 7;
typedef struct HashTable {
    int* arry; //һ�㶯̬�����ڴ�
    int num;  //Ԫ�ظ���  
}hashtable;

//��ʼ��
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
//hash����--ȡ����
int hash_function(int key)
{
    return key % HASH_SIZE;
}

//��չ
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

//����Ԫ��
void hash_insert(hashtable*& hash_table, int insert_val)
{
    //�ж�hashtable�Ƿ���Ҫ��չ
    //װ������=��ϣ�������ݵĸ���/��ϣ��ĳ��ȣ�װ������>70%ʱ����չһ���µ�hashtable,����hash��ͻ��
    if ((double)hash_table->num / (double)HASH_SIZE > 0.75)
    {
        hashtable* new_hash_table = new hashtable;
        hashtable* hash_table_temp = hash_table;
        hash_table = hash_extend(hash_table, new_hash_table);
        delete hash_table_temp;
    }
    //Ŀ���ַ
    int index = hash_function(insert_val);
    while (hash_table->arry[index] != HASH_NULL)
    {
        //����hash��ͻ---ѡ�񿪷ŵ�ַ��
        index = hash_function(++index);  //����̽�ⷨ--����ȡ1 
    }
    hash_table->arry[index] = insert_val;
    hash_table->num++;
}
//����Ԫ�� 
int hash_table_search(const hashtable& hash_table, int search_val)
{
    if (hash_table.num == 0)
    {
        return -1;
    }
    int val = hash_function(search_val);
    while (hash_table.arry[val] == HASH_NULL || hash_table.arry[val] != search_val)
    {
        //����hash��ͻ---ѡ�񿪷ŵ�ַ��
        val = hash_function(++val);  //����̽�ⷨ--����ȡ1 
        if (val == hash_function(search_val))//ѭ��һȦ
        {
            return -1;
        }
    }
    return val;
}
//ɾ��Ԫ��
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

//HashTable�������
void test_hashtable(int a[], int n)
{
    hashtable* H = NULL;
    hash_init(H);
    for (int i = 0; i < n; i++)
    {
        hash_insert(H, a[i]);
    }

    hash_table_delete(H, 7);

    int ret = hash_table_search(*H, 7);//����-1-�����ڣ�����-��������
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
    //��̬�����㷨
    //ans = test_sequential_search(a, length, key);
    //ans = test_binary_search(a, length,key);
    //cout << "find results:" << ans << endl;

     //����Ϊ��̬�����㷨
     test_bst_search(a,length);  //�������������ķ���ʵ��
     //test_avl_search(a, length);
     //test_RBT_search(a, length);
    //test_hashtable(a, length);

    return 0;
}